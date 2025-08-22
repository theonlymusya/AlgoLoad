#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

enum class InstructionType { ASSIGNMENT, FOR_LOOP, IF_STATEMENT, BLOCK, MAIN_FUNC, PROGRAM };

struct VarInfo {
    bool visible = false;
    bool isArray = false;
    int dim = 0;
    std::string type;
    std::vector<std::string> dimSizes;
    std::optional<std::string> value;
    std::optional<double> numericVal;
};

// Предварительное объявление
struct Instruction;

struct ScopedBlock {
    std::vector<Instruction> instructions;
    std::unordered_map<std::string, VarInfo> localScope;
};

// struct LoopItersInfo {
//     std::string startValue;
//     std::string updateValue;
// };

struct LoopInfo {
    std::unordered_map<std::string, std::string> itName_startVal;
    std::unordered_map<std::string, std::string> itName_updateVal;
    std::string condition;
    ScopedBlock body;
    mutable std::vector<int> actualNumericStartValues;
    mutable std::vector<int> actualNumericStopValues;
};

struct ElseIfStatement {
    std::string condition;
    ScopedBlock block;
};

enum class IfBranch { THEN = 0, ELIF, ELSE, NONE };

struct IfStatement {
    std::string condition;
    ScopedBlock thenBlock;
    std::vector<ElseIfStatement> elseIfBranches;
    ScopedBlock elseBlock;

    mutable IfBranch executedBranch = IfBranch::NONE;
    mutable size_t executedElifIndex = 0;
};

struct IndexedVariable {
    std::string name;
    std::vector<std::string> indices;
};

struct AssignmentInfo {
    static inline int global_counter = 0;  // статическая переменная-счётчик
    int id = global_counter++;             // id присваивается при создании объекта
    bool declared = false;
    int loopDepth = 0;
    IndexedVariable leftVar;
    std::vector<IndexedVariable> rightVars;
    std::string value;
};

struct Instruction {
    InstructionType type;
    std::variant<AssignmentInfo,  // ASSIGNMENT
                 LoopInfo,        // FOR_LOOP
                 IfStatement,     // IF
                 ScopedBlock      // BLOCK, MAIN_FUNC, PROGRAM
                 >
        data;
};
