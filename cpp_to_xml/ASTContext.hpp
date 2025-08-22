#pragma once

#include <iostream>
#include <optional>
#include <stack>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include "ContextStructs.hpp"
#include "Tables.hpp"

struct IterFrame {
    std::string name;        // имя итератора, например "i"
    int value;               // текущее числовое значение
    bool anonymous = false;  // true, если это "анонимный" итератор в for(;;)
};

class ASTContext {
   public:
    using iterValType = int;
    ASTContext();

    void setObserver(Observer* obs);

    void addProgram(const ScopedBlock& block);
    void executeInstructions();
    std::vector<Instruction>& get_instr() { return instructions; }

    void pushScope(const std::unordered_map<std::string, VarInfo>& scope);
    void popScope();
    std::unordered_map<std::string, VarInfo> getAllVisibleVars() const;
    std::unordered_map<std::string, VarInfo*> getAllVisibleVarsForChanges();
    std::unordered_map<std::string, VarInfo*> getLocalVarsForChanges();
    const std::vector<Instruction>& getInstructions() const { return instructions; }

   private:
    Observer* observer = nullptr;

    std::vector<IterFrame> iterStack;  // стек активных итераторов
    void pushIterator(const std::string& name, int value, bool anonymous = false);
    void popLastIterators(size_t count);
    bool hasIterator(const std::string& name) const;
    void updateIterator(const std::string& name, int newValue);
    void registerIteratorsFromUpdateVal(const LoopInfo& loop,
                                        const std::unordered_map<std::string, VarInfo>& visibleVars);

    std::vector<Instruction> instructions;

    std::vector<std::unordered_map<std::string, VarInfo>> scopeStack;

    void executeInstructionList(const std::vector<Instruction>& instrs);
    void executeLoop(const LoopInfo& loop);
    void executeIfStatement(const IfStatement& ifStmt);
    void executeAssignment(const AssignmentInfo& info);
};
