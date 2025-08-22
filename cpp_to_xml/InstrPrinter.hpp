#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>
#include "ASTContext.hpp"
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_CYAN "\033[36m"
#define COLOR_MAGENTA "\033[35m"

class InstructionsPrinter {
   public:
    static void printAST(const std::vector<Instruction>& instrs);
    static void printInstructionsScheme(const std::vector<Instruction>& instrs, int depth = 0);
    static void printInstructionList(const std::vector<Instruction>& instrs, int indent = 1);
    static void printScope(const std::unordered_map<std::string, VarInfo>& scope, int indent = 1);
    static void printAssignment(const Instruction& instr, int indent = 1);
    static void printForLoop(const Instruction& instr, int indent = 1);
    static void printIfStatement(const Instruction& instr, int indent = 1);
    static void printBlock(const Instruction& instr, int indent = 1);
    static void printTable(const Table& table);

   private:
};