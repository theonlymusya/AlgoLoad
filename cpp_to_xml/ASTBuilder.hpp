#pragma once

#include <optional>
#include <stack>
#include <string>
#include <variant>
#include <vector>
#include "ASTContext.hpp"
#include "small_c_grammarBaseListener.h"
#include "small_c_grammarParser.h"

struct ElseIf {
    std::string condition;
    ScopedBlock block;
};

struct IfNode {
    std::string condition;
    ScopedBlock thenBlock;
    std::vector<ElseIf> elseIfBranches;
    ScopedBlock elseBlock;
};

class ASTBuilder : public small_c_grammarBaseListener {
   public:
    ASTBuilder();
    virtual ~ASTBuilder();

    ASTContext& getASTContext();

    void enterProgram(small_c_grammarParser::ProgramContext* ctx) override;
    void exitProgram(small_c_grammarParser::ProgramContext* ctx) override;

    void enterFunction(small_c_grammarParser::FunctionContext* ctx) override;
    void exitFunction(small_c_grammarParser::FunctionContext* ctx) override;

    void enterBlock(small_c_grammarParser::BlockContext* ctx) override;
    void exitBlock(small_c_grammarParser::BlockContext* ctx) override;

    void enterAssignmentOp(small_c_grammarParser::AssignmentOpContext* ctx) override;
    void exitAssignmentOp(small_c_grammarParser::AssignmentOpContext* ctx) override;

    void enterIfStatement(small_c_grammarParser::IfStatementContext* ctx) override;
    void exitIfStatement(small_c_grammarParser::IfStatementContext* ctx) override;

    void enterForStatement(small_c_grammarParser::ForStatementContext* ctx) override;
    void exitForStatement(small_c_grammarParser::ForStatementContext* ctx) override;

    void enterMathExpr(small_c_grammarParser::MathExprContext* ctx) override;
    void exitMathExpr(small_c_grammarParser::MathExprContext* ctx) override;

   private:
    bool disableInstructionCapture = false;

    ASTContext astContext;

    // стеки
    // для накопления инструкций текущего блока
    std::stack<std::vector<Instruction>> blockStack;
    // для накопления переменных текущего блока
    std::stack<std::unordered_map<std::string, VarInfo>> scopeStack;
    // для временного хранения if-операторов
    std::stack<IfNode> ifStack;

    std::stack<int> loopDepthStack;

    // вспомогательные функции обхода дерева и сбора информации
    void beginBlock();
    ScopedBlock endBlock();

    void addInstruction(const Instruction& instr);
    void addVariable(const std::string& name,
                     const std::string& type,
                     const std::optional<std::string>& value,
                     bool isArray,
                     int dim,
                     const std::vector<std::string>& dimSizes,
                     bool visible = false);

    void handleDeclaration(small_c_grammarParser::AssignmentOpContext* ctx);
    AssignmentInfo buildAssignmentInfo(small_c_grammarParser::AssignmentOpContext* ctx);

    void handleElifChain(small_c_grammarParser::ElifChainContext* ctx, IfNode& node);
    void handleElseBranch(small_c_grammarParser::ElseBranchContext* ctx, IfNode& node);
    void collectIndexedVariables(antlr4::tree::ParseTree* node, std::vector<IndexedVariable>& out);

    void handleForInit(small_c_grammarParser::ForStartContext* startCtx, LoopInfo& loopInfo);
    void handleForCondition(small_c_grammarParser::ForStopContext* stopCtx, LoopInfo& loopInfo);
    void handleForUpdate(small_c_grammarParser::ForStepContext* stepCtx, LoopInfo& loopInfo);
};
