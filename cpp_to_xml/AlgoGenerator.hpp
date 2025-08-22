#pragma once

#include <memory>
#include "ASTContext.hpp"
#include "AlgoInfo.hpp"
#include "IteratorNamer.hpp"
#include "Tables.hpp"

class AlgoGenerator {
   public:
    AlgoGenerator(const Observer& obs, const ASTContext& ast);

    AlgoInfo generate();

   private:
    const Observer& observer;
    const ASTContext& astContext;
    int nextBlockId = 0;
    std::unordered_map<int, std::vector<int>> tableIdToBlockPath;  // id <-> path (list of ids)
    std::vector<int> currentBlockPath;
    Block* currentLoopBlock = nullptr;
    Block* currentAssignmentBlock = nullptr;

    void markNeededTables();
    // void buildAlgoFromInstruction(const Instruction& instr, AlgoInfo& algo, IteratorNamer& namer);
    // void buildAlgoFromInstructions(const std::vector<Instruction>& instrs,
    //                                Block& currentBlock,
    //                                IteratorNamer& namer);
    void buildAlgoFromInstructions(const std::vector<Instruction>& instrs,
                                   AlgoInfo* algo,
                                   Block* parentBlock,
                                   IteratorNamer& namer,
                                   int depth);
    std::vector<Instruction> filterInstrs(const std::vector<Instruction>& instrs);
    std::vector<const LoopInfo*> computeChain(const LoopInfo& loop);

    void processRow(const TableRow& row, Block& block, IteratorNamer& namer, int type);
    // std::vector<Arg> generateArgsFromTable(const Table& table, IteratorNamer& namer);
};
