#include "InstrPrinter.hpp"

void InstructionsPrinter::printAST(const std::vector<Instruction>& instrs) {
    std::cout << "AST Structure:\n";
    printInstructionList(instrs, 0);
}

void InstructionsPrinter::printInstructionsScheme(const std::vector<Instruction>& instrs, int depth) {
    std::string indent(depth * 2, ' ');

    for (const auto& instr : instrs) {
        switch (instr.type) {
            case InstructionType::FOR_LOOP:
                std::cout << indent << "FOR_LOOP\n";
                printInstructionsScheme(std::get<LoopInfo>(instr.data).body.instructions, depth + 1);
                break;
            case InstructionType::ASSIGNMENT:
                std::cout << indent << "ASSIGNMENT\n";
                break;
            case InstructionType::IF_STATEMENT: {
                std::cout << indent << "IF_STATEMENT\n";
                const auto& ifStmt = std::get<IfStatement>(instr.data);
                // заходи в then-блок
                printInstructionsScheme(ifStmt.thenBlock.instructions, depth + 1);
                // заходи в else-if’ы, если нужно
                for (const auto& elif : ifStmt.elseIfBranches) {
                    std::cout << indent << "ELSE_IF_STATEMENT\n";
                    printInstructionsScheme(elif.block.instructions, depth + 1);
                }
                // и в else-блок
                if (!ifStmt.elseBlock.instructions.empty()) {
                    std::cout << indent << "ELSE_STATEMENT\n";
                    printInstructionsScheme(ifStmt.elseBlock.instructions, depth + 1);
                }
                break;
            }
            case InstructionType::BLOCK:
                std::cout << indent << "BLOCK\n";
                printInstructionsScheme(std::get<ScopedBlock>(instr.data).instructions, depth + 1);
                break;
            case InstructionType::MAIN_FUNC:
                std::cout << indent << "MAIN_FUNC\n";
                printInstructionsScheme(std::get<ScopedBlock>(instr.data).instructions, depth + 1);
                break;
            case InstructionType::PROGRAM:
                std::cout << indent << "PROGRAM\n";
                printInstructionsScheme(std::get<ScopedBlock>(instr.data).instructions, depth + 1);
                break;
        }
    }
}

void InstructionsPrinter::printInstructionList(const std::vector<Instruction>& instrs, int indent) {
    for (const auto& instr : instrs) {
        switch (instr.type) {
            case InstructionType::ASSIGNMENT:
                printAssignment(instr, indent);
                break;
            case InstructionType::FOR_LOOP:
                printForLoop(instr, indent);
                break;
            case InstructionType::IF_STATEMENT:
                printIfStatement(instr, indent);
                break;
            case InstructionType::BLOCK:
            case InstructionType::PROGRAM:
            case InstructionType::MAIN_FUNC:
                printBlock(instr, indent);
                break;
        }
    }
}

void InstructionsPrinter::printScope(const std::unordered_map<std::string, VarInfo>& scope, int indent) {
    std::string ind(indent * 2, ' ');
    if (!scope.empty()) {
        std::cout << ind << "  [Scope variables: \n";
        for (const auto& [name, var] : scope) {
            std::cout << ind << "    " << COLOR_CYAN << name << COLOR_RESET << ": " << COLOR_GREEN << var.type
                      << COLOR_RESET;

            if (var.isArray) {
                std::cout << COLOR_YELLOW << " array[" << var.dim << "]" << COLOR_RESET;

                if (!var.dimSizes.empty()) {
                    std::cout << COLOR_MAGENTA << " sizes = [";
                    for (size_t i = 0; i < var.dimSizes.size(); ++i) {
                        std::cout << var.dimSizes[i];
                        if (i + 1 < var.dimSizes.size())
                            std::cout << ", ";
                    }
                    std::cout << "]" << COLOR_RESET;
                }
            } else {
                std::cout << " scalar";
            }

            if (var.value.has_value()) {
                std::cout << ", val = " << COLOR_BLUE << *var.value << COLOR_RESET;
            }

            if (var.numericVal.has_value()) {
                std::cout << ", numerical_val = " << COLOR_BLUE << *var.value << COLOR_RESET;
            }

            std::cout << ", visible = " << COLOR_BLUE << var.visible << COLOR_RESET;

            std::cout << "\n";
        }
        std::cout << ind << "  ]\n";
    }
}

void InstructionsPrinter::printAssignment(const Instruction& instr, int indent) {
    std::string ind(indent * 2, ' ');
    if (!std::holds_alternative<AssignmentInfo>(instr.data)) {
        std::cout << ind << COLOR_RED << "ASSIGNMENT: [ERROR: data is not AssignmentInfo!]" << COLOR_RESET
                  << "\n";
        return;
    }
    const auto& assign = std::get<AssignmentInfo>(instr.data);
    std::cout << ind << COLOR_BLUE << "ASSIGNMENT:" << COLOR_RESET << "\n";

    std::cout << ind << "  " << COLOR_GREEN << "Declared: " << COLOR_RESET << assign.declared << std::endl;

    std::cout << ind << "  " << COLOR_GREEN << "LHS: " << COLOR_RESET << assign.leftVar.name;
    if (!assign.leftVar.indices.empty()) {
        std::cout << COLOR_YELLOW << "[";
        for (size_t i = 0; i < assign.leftVar.indices.size(); ++i) {
            std::cout << assign.leftVar.indices[i];
            if (i + 1 < assign.leftVar.indices.size())
                std::cout << ", ";
        }
        std::cout << "]" << COLOR_RESET;
    } else {
        std::cout << COLOR_YELLOW << "[0]" << COLOR_RESET;
    }
    std::cout << "\n";

    std::cout << ind << "  " << COLOR_GREEN << "RHS variables:" << COLOR_RESET << "\n";
    for (const auto& var : assign.rightVars) {
        std::cout << ind << "    - " << COLOR_CYAN << var.name;
        if (!var.indices.empty()) {
            std::cout << COLOR_YELLOW << "[";
            for (size_t j = 0; j < var.indices.size(); ++j) {
                std::cout << var.indices[j];
                if (j + 1 < var.indices.size())
                    std::cout << ", ";
            }
            std::cout << "]" << COLOR_RESET;
        } else {
            std::cout << COLOR_YELLOW << "[0]" << COLOR_RESET;
        }
        std::cout << "\n";
    }
    std::cout << ind << "  " << COLOR_GREEN << "Value: " << COLOR_RESET;
    std::cout << COLOR_YELLOW << assign.value << COLOR_RESET;
    std::cout << "\n";
}

void InstructionsPrinter::printForLoop(const Instruction& instr, int indent) {
    std::string ind(indent * 2, ' ');
    const auto& loop = std::get<LoopInfo>(instr.data);

    std::cout << ind << "FOR_LOOP: ";

    // Печать инициализации
    if (!loop.itName_startVal.empty()) {
        size_t count = 0;
        for (const auto& [var, val] : loop.itName_startVal) {
            std::cout << var << " = " << val;
            if (++count < loop.itName_startVal.size())
                std::cout << ", ";
        }
    } else {
        std::cout << "(no initialization)";
    }

    // Печать условия
    std::cout << "; ";
    if (!loop.condition.empty()) {
        std::cout << loop.condition;
    } else {
        std::cout << "(no condition)";
    }

    // Печать обновлений
    std::cout << "; ";
    size_t updateCount = 0;
    bool hasUpdates = false;
    if (!loop.itName_updateVal.empty()) {
        for (const auto& [var, val] : loop.itName_updateVal) {
            std::cout << var << " = " << val;
            if (++updateCount < loop.itName_updateVal.size())
                std::cout << ", ";
            hasUpdates = true;
        }
    }
    if (!hasUpdates) {
        std::cout << "(no update)";
    }

    std::cout << "\n";

    // Печать области видимости и тела
    printScope(loop.body.localScope, indent);
    printInstructionList(loop.body.instructions, indent + 1);
}

void InstructionsPrinter::printIfStatement(const Instruction& instr, int indent) {
    std::string ind(indent * 2, ' ');
    const auto& ifStmt = std::get<IfStatement>(instr.data);
    std::cout << ind << "IF: (" << ifStmt.condition << ")\n";
    printScope(ifStmt.thenBlock.localScope, indent);
    printInstructionList(ifStmt.thenBlock.instructions, indent + 1);

    for (const auto& elif : ifStmt.elseIfBranches) {
        std::cout << ind << "ELSE IF: (" << elif.condition << ")\n";
        printScope(elif.block.localScope, indent);
        printInstructionList(elif.block.instructions, indent + 1);
    }

    if (!ifStmt.elseBlock.instructions.empty()) {
        std::cout << ind << "ELSE:\n";
        printScope(ifStmt.elseBlock.localScope, indent);
        printInstructionList(ifStmt.elseBlock.instructions, indent + 1);
    }
}

void InstructionsPrinter::printBlock(const Instruction& instr, int indent) {
    std::string ind(indent * 2, ' ');
    const auto& scoped = std::get<ScopedBlock>(instr.data);
    std::string label = instr.type == InstructionType::MAIN_FUNC ? "MAIN_FUNC"
                        : instr.type == InstructionType::BLOCK   ? "BLOCK"
                                                                 : "PROGRAM";
    std::cout << ind << label << ":\n";
    printScope(scoped.localScope, indent);
    printInstructionList(scoped.instructions, indent + 1);
}

void InstructionsPrinter::printTable(const Table& table) {
    std::cout << "schedule  iters   LHS   RHS indices           sources\n";
    std::cout << "--------  ------  ----  ---------------------  ------------------\n";

    for (const auto& row : table.rows) {
        // schedule index
        std::cout << std::setw(8) << row.scheduleIdx << " ";

        // iters (i, j, k)
        std::ostringstream itersStr;
        for (int v : row.iters)
            itersStr << v;
        std::cout << std::setw(7) << itersStr.str();

        // LHS (индексы переменной слева)
        std::ostringstream lhsStr;
        for (int idx : row.LHSVarIdx)
            lhsStr << idx;
        std::cout << "  " << std::setw(4) << lhsStr.str();

        // RHS indices
        std::ostringstream rhsStr;
        if (!row.RHSVarIdx.empty()) {
            for (const auto& rhs : row.RHSVarIdx) {
                for (int idx : rhs)
                    rhsStr << idx;
                rhsStr << " ";
            }
        }
        std::cout << "  " << std::setw(22) << rhsStr.str();

        // sources
        std::ostringstream srcStr;
        for (const auto& src : row.sources) {
            srcStr << (src.tableIdx == 0 ? "bsrc" : "src ");
            srcStr << "(" << src.tableIdx << ", ";
            for (int val : src.srcTableIters)
                srcStr << val;
            srcStr << ") ";
        }
        std::cout << "  " << srcStr.str();

        std::cout << "\n";
    }
}
