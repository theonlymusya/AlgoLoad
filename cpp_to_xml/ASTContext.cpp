// ASTContext.cpp
#include "ASTContext.hpp"
#include <cstdlib>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include "CalcExpr.hpp"
#include "InstrPrinter.hpp"

void ASTContext::pushIterator(const std::string& name, int value, bool anonymous) {
    iterStack.push_back({name, value, anonymous});
}

bool ASTContext::hasIterator(const std::string& name) const {
    return std::any_of(iterStack.begin(), iterStack.end(),
                       [&](const IterFrame& f) { return !f.anonymous && f.name == name; });
}

void ASTContext::updateIterator(const std::string& name, int newValue) {
    for (auto& f : iterStack) {
        if (!f.anonymous && f.name == name) {
            f.value = newValue;
            return;
        }
    }
}

void ASTContext::popLastIterators(size_t count) {
    for (size_t i = 0; i < count && !iterStack.empty(); ++i)
        iterStack.pop_back();
}

void ASTContext::registerIteratorsFromUpdateVal(const LoopInfo& loop,
                                                const std::unordered_map<std::string, VarInfo>& visibleVars) {
    for (const auto& [itName, updateVal] : loop.itName_updateVal) {
        if (!hasIterator(itName)) {
            auto it = visibleVars.find(itName);

            if (it == visibleVars.end()) {
                throw std::runtime_error("[FATAL] Iterator variable '" + itName +
                                         "' used in updateVal but not declared.");
            }

            if (!it->second.visible) {
                throw std::runtime_error("[FATAL] Iterator variable '" + itName +
                                         "' is not visible at loop entry.");
            }

            if (!it->second.numericVal.has_value()) {
                throw std::runtime_error("[FATAL] Iterator variable '" + itName +
                                         "' has no numeric value for initialization.");
            }

            int initial = static_cast<int>(it->second.numericVal.value());
            pushIterator(itName, initial, false);
        }
    }
}

void ASTContext::setObserver(Observer* obs) {
    observer = obs;
}

ASTContext::ASTContext() {}

void ASTContext::addProgram(const ScopedBlock& block) {
    instructions.push_back({InstructionType::PROGRAM, block});
}

void ASTContext::pushScope(const std::unordered_map<std::string, VarInfo>& scope) {
    scopeStack.push_back(scope);
}

void ASTContext::popScope() {
    if (!scopeStack.empty()) {
        scopeStack.pop_back();
    } else {
        std::cerr << "[ERROR] Scope stack underflow!\n";
    }
}

std::unordered_map<std::string, VarInfo> ASTContext::getAllVisibleVars() const {
    std::unordered_map<std::string, VarInfo> result;

    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        for (const auto& [name, info] : *it) {
            if (info.visible && !result.count(name)) {
                result[name] = info;
            }
        }
    }

    return result;
}

std::unordered_map<std::string, VarInfo*> ASTContext::getAllVisibleVarsForChanges() {
    std::unordered_map<std::string, VarInfo*> result;

    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        for (auto& [name, info] : *it) {
            if (info.visible && !result.count(name)) {
                result[name] = &info;
            }
        }
    }

    return result;
}

std::unordered_map<std::string, VarInfo*> ASTContext::getLocalVarsForChanges() {
    if (scopeStack.empty()) {
        throw std::runtime_error("Scope stack is empty");
    }

    std::unordered_map<std::string, VarInfo*> result;

    auto& topScope = scopeStack.back();
    for (auto& [name, info] : topScope) {
        result[name] = &info;
    }

    return result;
}

void ASTContext::executeInstructions() {
    executeInstructionList(instructions);
}

void ASTContext::executeInstructionList(const std::vector<Instruction>& instrs) {
    for (const auto& instr : instrs) {
        switch (instr.type) {
            case InstructionType::ASSIGNMENT: {
                // заполнение таблицы
                executeAssignment(std::get<AssignmentInfo>(instr.data));
                break;
            }
            case InstructionType::FOR_LOOP: {
                executeLoop(std::get<LoopInfo>(instr.data));
                break;
            }
            case InstructionType::IF_STATEMENT: {
                executeIfStatement(std::get<IfStatement>(instr.data));
                break;
            }
            case InstructionType::MAIN_FUNC:
            case InstructionType::PROGRAM:
            case InstructionType::BLOCK: {
                const auto& scoped = std::get<ScopedBlock>(instr.data);
                pushScope(scoped.localScope);
                executeInstructionList(scoped.instructions);
                popScope();
            }
        }
    }
}

// struct ScopedBlock {
//     std::vector<Instruction> instructions;
//     std::unordered_map<std::string, VarInfo> localScope;
// };

// struct LoopItersInfo {
//     std::string startValue;
//     std::string updateValue;
// };

// struct LoopInfo {
//     std::unordered_map<std::string, LoopItersInfo> varNames;
//     std::string condition;
//     ScopedBlock body;
// };

void ASTContext::executeLoop(const LoopInfo& loop) {
    // std::cout << "[DEBUG] Вызов executeLoop\n";

    pushScope(loop.body.localScope);

    size_t iterStackSizeBefore = iterStack.size();

    auto localVarsWriteMod = getLocalVarsForChanges();

    for (const auto& [itName, _] : loop.itName_startVal) {
        if (localVarsWriteMod.count(itName)) {
            localVarsWriteMod[itName]->visible = true;
        }
    }

    // 1. Получаем полную текущую область (для вычислений)
    auto visibleVarsWriteMod = getAllVisibleVarsForChanges();
    auto visibleVarsReadMod = getAllVisibleVars();
    auto visibleVarsVal = expr_utils::extractValues(visibleVarsReadMod);

    for (const auto& [itName, startVal] : loop.itName_startVal) {
        double start = ExpressionCalculator::evaluateWithTinyExpr(startVal, visibleVarsVal);

        // обновляем VarInfo
        if (visibleVarsWriteMod.count(itName)) {
            auto* var = visibleVarsWriteMod[itName];
            var->value = std::to_string(static_cast<int>(start));
            var->numericVal = static_cast<int>(start);
        } else {
            std::cerr << "[WARNING] Variable " << itName << " was not found for initialization\n";
        }
        pushIterator(itName, static_cast<int>(start), false);
    }

    // Дополняем итераторами из updateVal (например, for (; i < n; i++))
    // если такие переменные ещё не в iterStack
    registerIteratorsFromUpdateVal(loop, visibleVarsReadMod);

    // сохраняем стартовые значения
    if (loop.actualNumericStartValues.empty()) {
        for (size_t i = iterStackSizeBefore; i < iterStack.size(); i++) {
            loop.actualNumericStartValues.push_back(iterStack[i].value);
        }
    }

    // Если вообще нет итераторов → считаем цикл бесконечным for(;;)
    if (iterStack.size() == iterStackSizeBefore) {
        pushIterator("?", -1, true);
    }

    for (;;) {
        // std::cout << "\n--- Новая итерация цикла ---\n";

        visibleVarsReadMod = getAllVisibleVars();
        visibleVarsVal = expr_utils::extractValues(visibleVarsReadMod);
        // InstructionsPrinter::printScope(visibleVarsReadMod);

        // std::cout << "  Условие: " << loop.condition << std::endl;
        double cond = ExpressionCalculator::evaluateWithTinyExpr(loop.condition, visibleVarsVal);
        // std::cout << "  Значение условия: " << cond << "\n";

        if (!cond)
            break;

        // std::cout << "  До: " << "\n";
        // InstructionsPrinter::printScope(visibleVarsReadMod);

        executeInstructionList(loop.body.instructions);
        // std::cout << "  После: " << "\n";

        // 4. Обновление значений итераторов
        visibleVarsReadMod = getAllVisibleVars();
        visibleVarsVal = expr_utils::extractValues(visibleVarsReadMod);
        visibleVarsWriteMod = getAllVisibleVarsForChanges();

        // InstructionsPrinter::printScope(visibleVarsReadMod);

        // проблема с обновлением значений итераторов вне заголовка цикла
        for (const auto& [itName, updateVal] : loop.itName_updateVal) {
            double updated = ExpressionCalculator::evaluateWithTinyExpr(updateVal, visibleVarsVal);

            if (visibleVarsWriteMod.count(itName)) {
                auto* var = visibleVarsWriteMod[itName];
                var->value = std::to_string(static_cast<int>(updated));
                var->numericVal = updated;
            } else {
                std::cerr << "[WARNING] Variable " << itName << " was not found for updating\n";
            }

            // Обновляем итератор в стеке
            updateIterator(itName, static_cast<int>(updated));
        }
    }
    popScope();
    // сохраняем конечные значения
    if (loop.actualNumericStopValues.empty()) {
        for (size_t i = iterStackSizeBefore; i < iterStack.size(); i++) {
            loop.actualNumericStopValues.push_back(iterStack[i].value);
        }
    }
    popLastIterators(iterStack.size() - iterStackSizeBefore);
}

// struct IndexedVariable {
//     std::string name;
//     std::vector<std::string> indices;
// };

// struct AssignmentInfo {
//     IndexedVariable leftVar;
//     std::vector<IndexedVariable> rightVars;
//     std::string value;
// };

void ASTContext::executeAssignment(const AssignmentInfo& info) {
    std::shared_ptr<Table> tablePtr;
    if (observer) {
        if (!observer->hasTableForAssignment(info.id)) {
            tablePtr = std::make_shared<Table>(info.leftVar.name, info.id, info.loopDepth);
            observer->registerTableForVar(info.leftVar.name, tablePtr);
            std::cout << "[DEBUG] Создана таблица: ID = " << info.id << ", переменная = " << info.leftVar.name
                      << ", глубина вложенности = " << info.loopDepth << "\n";
        } else {
            tablePtr = observer->getTableByAssignmentId(info.id);
            if (!tablePtr) {
                std::cerr << "[ERROR] table wasn't created and wasn't found for " << info.leftVar.name;
                exit(1);
            }
        }
    }
    // План
    // 1. Если текущая assignment была declared - найти левую переменную в текущей
    // области видимости через getLocalVisibleVarsForChanges() и сделать её visible

    auto localVarsWriteMod = getLocalVarsForChanges();
    if (info.declared) {
        if (localVarsWriteMod.count(info.leftVar.name)) {
            localVarsWriteMod[info.leftVar.name]->visible = true;
        } else {
            std::cerr << "[WARNING] Declared variable " << info.leftVar.name
                      << " not found in local scope for visibility update\n";
        }
    }
    // 2. Для любой левой переменной попробовать вычислить её numеricalValue
    //(если не вычисляется - продолжать работу, не заполняя поле numericalValue)

    auto visibleVarsReadMod = getAllVisibleVars();
    auto visibleVarsVal = expr_utils::extractValues(visibleVarsReadMod);
    auto visibleVarsWriteMod = getAllVisibleVarsForChanges();

    if (visibleVarsWriteMod.count(info.leftVar.name)) {
        try {
            double value = ExpressionCalculator::evaluateWithTinyExpr(info.value, visibleVarsVal);
            visibleVarsWriteMod[info.leftVar.name]->value = info.value;
            visibleVarsWriteMod[info.leftVar.name]->numericVal = value;
        } catch (const std::exception& e) {
            // значение не вычислилось — оставляем как есть
            visibleVarsWriteMod[info.leftVar.name]->value = info.value;
            visibleVarsWriteMod[info.leftVar.name]->numericVal = std::nullopt;
        }
    } else {
        // std::cerr << "[WARNING] Variable " << info.leftVar.name << " not found for value assignment\n";
    }

    // 3. Вычисляем и выводим индексные значения переменной слева
    std::vector<int> lhsIndices;
    std::ostringstream lhsIndexStr;
    for (size_t i = 0; i < info.leftVar.indices.size(); i++) {
        double idxVal = ExpressionCalculator::evaluateWithTinyExpr(info.leftVar.indices[i], visibleVarsVal);
        lhsIndices.push_back((int)idxVal);
        lhsIndexStr << "[" << (int)idxVal << "]";
    }
    // если переменная скалярная
    if (lhsIndices.empty()) {
        lhsIndices.push_back(0);
    }
    // std::cout << info.leftVar.name << lhsIndexStr.str() << " = ";

    // 3. Вычисляем и выводим индексные значения всех переменных справа
    std::vector<std::vector<int>> rhsIndexValues;
    for (size_t i = 0; i < info.rightVars.size(); i++) {
        const auto& rv = info.rightVars[i];

        std::vector<int> rhsIndices;
        std::ostringstream rvIndexStr;
        for (size_t j = 0; j < rv.indices.size(); j++) {
            double idxVal = ExpressionCalculator::evaluateWithTinyExpr(rv.indices[j], visibleVarsVal);
            rhsIndices.push_back((int)idxVal);
            rvIndexStr << "[" << (int)idxVal << "]";
        }
        rhsIndexValues.push_back(std::move(rhsIndices));

        std::cout << rv.name << rvIndexStr.str();
        if (i + 1 < info.rightVars.size())
            std::cout << ", ";
    }
    std::cout << std::endl;

    if (observer) {
        TableRow row;
        row.scheduleIdx = observer->nextScheduleIndexForVar(info.leftVar.name);
        for (const auto& frame : iterStack)
            row.iters.push_back(frame.value);
        if ((int)row.iters.size() != tablePtr->dim) {
            std::cerr << "[WARNING] Несовпадение размеров итераторов и dim таблицы!\n";
        }
        // если скаляр
        if (row.iters.empty()) {
            row.iters.push_back(0);
        }
        row.LHSVarIdx = std::move(lhsIndices);

        // 3. Индексы и источники переменных справа
        for (size_t i = 0; i < info.rightVars.size(); ++i) {
            const auto& rhsVar = info.rightVars[i];
            const auto& rhsIndices = rhsIndexValues[i];

            auto src = observer->findLatestSrc(rhsVar.name, rhsIndices);
            if (src.has_value()) {
                row.RHSVarIdx.push_back(rhsIndices);
                row.sources.push_back(*src);
            } else {
                std::cerr << "[DEBUG] Не найден источник для " << rhsVar.name << " с индексами: [";
                for (int v : rhsIndices)
                    std::cerr << v << " ";
                std::cerr << "]\n";
            }
        }

        // 4. Строка добавляется В ЛЮБОМ СЛУЧАЕ
        tablePtr->addRow(std::move(row));
    }
}

// struct ElseIfStatement {
//     std::string condition;
//     ScopedBlock block;
// };

// struct IfStatement {
//     std::string condition;
//     ScopedBlock thenBlock;
//     std::vector<ElseIfStatement> elseIfBranches;
//     ScopedBlock elseBlock;
// };

void ASTContext::executeIfStatement(const IfStatement& ifStmt) {
    auto visibleVarsReadMod = getAllVisibleVars();
    auto visibleVarsVal = expr_utils::extractValues(visibleVarsReadMod);

    // std::cout << " If cond: " << ifStmt.condition;
    double ifCond = ExpressionCalculator::evaluateWithTinyExpr(ifStmt.condition, visibleVarsVal);
    // std::cout << " == " << ifCond << std::endl;
    if (ifCond) {
        ifStmt.executedBranch = IfBranch::THEN;
        pushScope(ifStmt.thenBlock.localScope);
        executeInstructionList(ifStmt.thenBlock.instructions);
        popScope();
        return;
    }

    bool matched = false;
    visibleVarsReadMod = getAllVisibleVars();
    visibleVarsVal = expr_utils::extractValues(visibleVarsReadMod);

    int idx = 0;
    for (const auto& elif : ifStmt.elseIfBranches) {
        // std::cout << " If cond: " << elif.condition;
        double elifCond = ExpressionCalculator::evaluateWithTinyExpr(elif.condition, visibleVarsVal);
        // std::cout << " == " << elifCond << std::endl;
        if (elifCond) {
            ifStmt.executedBranch = IfBranch::ELIF;
            ifStmt.executedElifIndex = idx;
            pushScope(elif.block.localScope);
            executeInstructionList(elif.block.instructions);
            popScope();
            matched = true;
            return;
        }
        idx++;
    }

    if (!matched && !ifStmt.elseBlock.instructions.empty()) {
        ifStmt.executedBranch = IfBranch::ELSE;
        pushScope(ifStmt.elseBlock.localScope);
        executeInstructionList(ifStmt.elseBlock.instructions);
        popScope();
    }
}
