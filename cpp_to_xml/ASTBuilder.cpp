#include "ASTBuilder.hpp"
#include <cstdlib>
#include <iostream>

// вспомогательная функция для открытия блока
void ASTBuilder::beginBlock() {
    blockStack.push({});
    scopeStack.push({});
}

// вспомогательная функция для закрытия блока
ScopedBlock ASTBuilder::endBlock() {
    ScopedBlock block;

    block.instructions = blockStack.top();
    blockStack.pop();

    block.localScope = scopeStack.top();
    scopeStack.pop();

    return block;
}

// вспомогательная функция накапливания инструкций в текущем блоке
void ASTBuilder::addInstruction(const Instruction& instr) {
    if (!blockStack.empty()) {
        blockStack.top().push_back(instr);
    } else {
        std::cerr << "[WARNING] addInstruction called with empty block stack!\n";
    }
}

// struct VarInfo {
//     bool visible = false;
//     bool isArray = false;
//     int dim = 0;
//     std::string type;
//     std::vector<std::string> dimSizes;
//     std::optional<std::string> value;
//     std::optional<double> numericVal;
// };

// вспомогательная функция накапливания переменных в текущем блоке
void ASTBuilder::addVariable(const std::string& name,
                             const std::string& type,
                             const std::optional<std::string>& value,
                             bool isArray,
                             int dim,
                             const std::vector<std::string>& dimSizes,
                             bool visible) {
    VarInfo info{visible, isArray, dim, type, dimSizes, value};
    if (!scopeStack.empty()) {
        scopeStack.top()[name] = info;
    } else {
        std::cerr << "[WARNING] addVariable called with empty scope stack!\n";
    }
}

ASTBuilder::ASTBuilder() {}

ASTBuilder::~ASTBuilder() {}

ASTContext& ASTBuilder::getASTContext() {
    return astContext;
}

void ASTBuilder::enterProgram(small_c_grammarParser::ProgramContext* ctx) {
    blockStack.push({});
    scopeStack.push({});
}

void ASTBuilder::exitProgram(small_c_grammarParser::ProgramContext* ctx) {
    if (!blockStack.empty()) {
        ScopedBlock top = endBlock();
        astContext.addProgram(top);
    }
}

void ASTBuilder::enterFunction(small_c_grammarParser::FunctionContext* ctx) {
    // функция – это блок с собственной областью видимости
    beginBlock();
}

void ASTBuilder::exitFunction(small_c_grammarParser::FunctionContext* ctx) {
    ScopedBlock funcBlock = endBlock();

    Instruction funcInstr;
    funcInstr.type = InstructionType::MAIN_FUNC;
    funcInstr.data = funcBlock;

    addInstruction(funcInstr);
}

void ASTBuilder::enterBlock(small_c_grammarParser::BlockContext* ctx) {
    if (disableInstructionCapture)
        return;

    beginBlock();
}

void ASTBuilder::exitBlock(small_c_grammarParser::BlockContext* ctx) {
    if (disableInstructionCapture)
        return;

    ScopedBlock block = endBlock();

    Instruction blockInstr;
    blockInstr.type = InstructionType::BLOCK;
    blockInstr.data = block;

    addInstruction(blockInstr);
}

// assignmentOp
//     : declaration? varName ('=' mathExpr)?
//     ;

void ASTBuilder::handleDeclaration(small_c_grammarParser::AssignmentOpContext* ctx) {
    std::string varType = ctx->declaration()->getText();
    std::string varName = ctx->varName()->ID()->getText();
    std::optional<std::string> varValue = std::nullopt;

    if (ctx->mathExpr()) {
        varValue = ctx->mathExpr()->getText();
    }

    std::vector<std::string> dimSizes;
    bool isArray = ctx->varName()->arrayDecl() != nullptr;
    if (isArray) {
        auto exprs = ctx->varName()->arrayDecl()->mathExpr();
        for (auto* expr : exprs) {
            dimSizes.push_back(expr->getText());
        }
    }
    int dim = dimSizes.size();

    addVariable(varName, varType, varValue, isArray, dim, dimSizes);
}

void ASTBuilder::collectIndexedVariables(antlr4::tree::ParseTree* node, std::vector<IndexedVariable>& out) {
    if (!node)
        return;

    auto* var = dynamic_cast<small_c_grammarParser::VarNameContext*>(node);
    if (var) {
        IndexedVariable iv;
        iv.name = var->ID()->getText();
        // std::cout << iv.name << " ";

        if (auto* arr = var->arrayDecl()) {
            for (auto* expr : arr->mathExpr()) {
                // std::cout << expr->getText() << " ";
                iv.indices.push_back(expr->getText());
            }
        } else {
            iv.indices.push_back("0");
        }
        // std::cout << std::endl;

        out.push_back(iv);
        return;
    }

    for (int i = 0; i < node->children.size(); ++i) {
        collectIndexedVariables(node->children[i], out);
    }
}

AssignmentInfo ASTBuilder::buildAssignmentInfo(small_c_grammarParser::AssignmentOpContext* ctx) {
    AssignmentInfo info;

    if (ctx->declaration()) {
        info.declared = true;
    }

    auto* leftVar = ctx->varName();
    info.leftVar.name = leftVar->ID()->getText();

    if (leftVar->arrayDecl()) {
        for (auto* idxExpr : leftVar->arrayDecl()->mathExpr()) {
            info.leftVar.indices.push_back(idxExpr->getText());
        }
    }
    if (ctx->mathExpr()) {
        // std::cout << "\n=== mathExpr AST ===\n";
        // std::cout << ctx->mathExpr()->toStringTree() << "\n";
        collectIndexedVariables(ctx->mathExpr(), info.rightVars);
        info.value = ctx->mathExpr()->getText();
    }

    info.loopDepth = loopDepthStack.empty() ? 0 : loopDepthStack.top();

    return info;
}

void ASTBuilder::enterAssignmentOp(small_c_grammarParser::AssignmentOpContext* ctx) {
    if (disableInstructionCapture)
        return;

    antlr4::ParserRuleContext* parent = dynamic_cast<antlr4::ParserRuleContext*>(ctx->parent);
    antlr4::ParserRuleContext* grandparent =
        parent ? dynamic_cast<antlr4::ParserRuleContext*>(parent->parent) : nullptr;

    if ((parent && dynamic_cast<small_c_grammarParser::ForStartExprContext*>(parent)) ||
        (parent && dynamic_cast<small_c_grammarParser::ForStepExprContext*>(parent)) ||
        (grandparent && dynamic_cast<small_c_grammarParser::ForStartContext*>(grandparent))) {
        return;  // пропускаем добавление AssignmentInfo для заголовка цикла for
    }

    if (ctx->declaration()) {
        handleDeclaration(ctx);
    }

    AssignmentInfo assign = buildAssignmentInfo(ctx);
    addInstruction({InstructionType::ASSIGNMENT, assign});
}

void ASTBuilder::exitAssignmentOp(small_c_grammarParser::AssignmentOpContext* ctx) {
    // ничего не требуется
}

void ASTBuilder::enterIfStatement(small_c_grammarParser::IfStatementContext* ctx) {
    disableInstructionCapture = true;

    IfNode newIf;
    newIf.condition = ctx->cond->getText();

    ifStack.push(newIf);
}

void ASTBuilder::handleElifChain(small_c_grammarParser::ElifChainContext* ctx, IfNode& node) {
    for (size_t i = 0; i < ctx->elifCond.size(); ++i) {
        std::string cond = ctx->elifCond[i]->getText();

        beginBlock();

        antlr4::tree::ParseTreeWalker::DEFAULT.walk(this, ctx->statement(i));

        auto block = endBlock();

        node.elseIfBranches.push_back(ElseIf{cond, block});
    }
}

void ASTBuilder::handleElseBranch(small_c_grammarParser::ElseBranchContext* ctx, IfNode& node) {
    beginBlock();

    antlr4::tree::ParseTreeWalker::DEFAULT.walk(this, ctx->statement());

    node.elseBlock = endBlock();
}

void ASTBuilder::exitIfStatement(small_c_grammarParser::IfStatementContext* ctx) {
    auto currentIf = ifStack.top();
    ifStack.pop();

    beginBlock();
    disableInstructionCapture = false;
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(this, ctx->statement());
    currentIf.thenBlock = endBlock();

    if (ctx->elifChain()) {
        handleElifChain(ctx->elifChain(), currentIf);
    }

    if (ctx->elseBranch()) {
        handleElseBranch(ctx->elseBranch(), currentIf);
    }

    Instruction ifInstr;
    ifInstr.type = InstructionType::IF_STATEMENT;

    IfStatement finalIf;
    finalIf.condition = currentIf.condition;
    finalIf.thenBlock = currentIf.thenBlock;
    for (const auto& elif : currentIf.elseIfBranches) {
        finalIf.elseIfBranches.push_back(ElseIfStatement{elif.condition, elif.block});
    }
    finalIf.elseBlock = currentIf.elseBlock;

    ifInstr.data = finalIf;
    addInstruction(ifInstr);
}

void ASTBuilder::enterForStatement(small_c_grammarParser::ForStatementContext* ctx) {
    if (disableInstructionCapture)
        return;
    int depth = loopDepthStack.empty() ? 1 : loopDepthStack.top() + 1;
    loopDepthStack.push(depth);
    beginBlock();
}

void ASTBuilder::handleForInit(small_c_grammarParser::ForStartContext* startCtx, LoopInfo& loopInfo) {
    // if init field is empty - do nothing
    if (!startCtx)
        return;

    for (auto* startExpr : startCtx->forStartExpr()) {
        auto* assign = startExpr->assignmentOp();

        std::string varName = assign->varName()->getText();
        std::string varStartValue;

        if (assign->mathExpr()) {
            varStartValue = assign->mathExpr()->getText();
        } else {
            // error handler
            std::cerr << "Missing initialization value in for-loop header.\n";
            exit(1);
        }

        if (assign->declaration()) {
            std::string type = assign->declaration()->getText();
            std::vector<std::string> dimSizes;
            bool isArray = false;

            if (assign->varName()->arrayDecl()) {
                isArray = true;
                for (auto* dimExpr : assign->varName()->arrayDecl()->mathExpr()) {
                    dimSizes.push_back(dimExpr->getText());
                }
            }
            addVariable(varName, type, varStartValue, isArray, dimSizes.size(), dimSizes);
        }

        loopInfo.itName_startVal[varName] = varStartValue;
    }
}

void ASTBuilder::handleForCondition(small_c_grammarParser::ForStopContext* stopCtx, LoopInfo& loopInfo) {
    // if cond field is empty it's always true
    if (!stopCtx)
        loopInfo.condition = "1";
    loopInfo.condition = stopCtx->getText();
}

void ASTBuilder::handleForUpdate(small_c_grammarParser::ForStepContext* stepCtx, LoopInfo& loopInfo) {
    if (!stepCtx)
        return;

    for (auto* stepExpr : stepCtx->forStepExpr()) {
        std::string varName = stepExpr->varName()->getText();
        std::string updateExpr = stepExpr->mathExpr()->getText();

        loopInfo.itName_updateVal[varName] = updateExpr;
    }
}

void ASTBuilder::exitForStatement(small_c_grammarParser::ForStatementContext* ctx) {
    if (disableInstructionCapture)
        return;

    LoopInfo loopInfo;

    handleForInit(ctx->forStart(), loopInfo);
    handleForCondition(ctx->forStop(), loopInfo);
    handleForUpdate(ctx->forStep(), loopInfo);

    ScopedBlock loopBody = endBlock();
    loopInfo.body = loopBody;

    Instruction loopInstr;
    loopInstr.type = InstructionType::FOR_LOOP;
    loopInstr.data = loopInfo;
    addInstruction(loopInstr);

    loopDepthStack.pop();
}

void ASTBuilder::enterMathExpr(small_c_grammarParser::MathExprContext* ctx) {
    // math exptessions are handling inside other AST nodes' handler functions
}

void ASTBuilder::exitMathExpr(small_c_grammarParser::MathExprContext* ctx) {}
