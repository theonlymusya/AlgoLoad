#include "AlgoGenerator.hpp"
#include <sstream>
#include "InstrPrinter.hpp"

AlgoGenerator::AlgoGenerator(const Observer& obs, const ASTContext& ast) : observer(obs), astContext(ast) {}

void AlgoGenerator::markNeededTables() {
    // Сначала отмечаем таблицы, которые имеют хотя бы один source
    for (const auto& [id, tablePtr] : observer.getAllTables()) {
        if (!tablePtr)
            continue;

        for (const auto& row : tablePtr->rows) {
            if (!row.sources.empty()) {
                tablePtr->showsDepends = true;
                tablePtr->verticiesType = 1;
                break;
            }
        }
        // std::cout << "Table id:" << id << "Deps: " << tablePtr->showsDepends << std::endl;
    }

    // Теперь проходим ещё раз — отмечаем таблицы, на которые ссылаются другие
    for (const auto& [id, tablePtr] : observer.getAllTables()) {
        if (!tablePtr)
            continue;

        for (const auto& row : tablePtr->rows) {
            for (const auto& src : row.sources) {
                auto targetTablePtr = observer.getTableByAssignmentId(src.tableIdx);
                if (targetTablePtr) {
                    targetTablePtr->showsDepends = true;
                }
            }
        }
        // std::cout << "Table id:" << id << "Deps: " << tablePtr->showsDepends << std::endl;
    }
}

// to do
// 1. i j k лучше брать из минмаксных в таблице, я думаю, чтобы лишних итераций не было
// 2. починить поиск источника для скалярной переменной
// done: bsrc - найти при предварительном обходе
// done: сделать отметки таблиц, которые нужно печатать (+дать им тим вершин)
// done: warning если оператор присваивания вне цикла лежит ему нужен arg 0..0
AlgoInfo AlgoGenerator::generate() {
    AlgoInfo algo;
    markNeededTables();

    IteratorNamer namer;
    auto filtered = filterInstrs(astContext.getInstructions());
    InstructionsPrinter::printInstructionsScheme(filtered);
    buildAlgoFromInstructions(filtered, &algo, nullptr, namer, 0);

    // rootBlock.dims = std::to_string(rootBlock.args.size());
    // algo.addBlock(rootBlock);

    return algo;
}

std::vector<Instruction> AlgoGenerator::filterInstrs(const std::vector<Instruction>& instrs) {
    std::vector<Instruction> filtered_instrs;
    for (auto& instr : instrs) {
        switch (instr.type) {
            case InstructionType::ASSIGNMENT:
                filtered_instrs.push_back(instr);
                break;

            case InstructionType::FOR_LOOP: {
                // склонируем LoopInfo, но его тело тоже фильтруем
                LoopInfo L = std::get<LoopInfo>(instr.data);
                L.body.instructions = filterInstrs(L.body.instructions);
                Instruction copy;
                copy.type = InstructionType::FOR_LOOP;
                copy.data = std::move(L);
                filtered_instrs.push_back(std::move(copy));
                break;
            }

            case InstructionType::IF_STATEMENT: {
                // рекурсивно берём только ту ветку, что отработала
                IfStatement S = std::get<IfStatement>(instr.data);
                std::vector<Instruction> branch;
                switch (S.executedBranch) {
                    case IfBranch::THEN:
                        branch = filterInstrs(S.thenBlock.instructions);
                        break;
                    case IfBranch::ELIF:
                        branch = filterInstrs(S.elseIfBranches[S.executedElifIndex].block.instructions);
                        break;
                    case IfBranch::ELSE:
                        branch = filterInstrs(S.elseBlock.instructions);
                        break;
                    case IfBranch::NONE:
                        break;
                }
                // вставляем полученные инструкции на текущий уровень
                filtered_instrs.insert(filtered_instrs.end(), std::make_move_iterator(branch.begin()),
                                       std::make_move_iterator(branch.end()));
                break;
            }

            case InstructionType::BLOCK:
            case InstructionType::PROGRAM:
            case InstructionType::MAIN_FUNC: {
                // из обёрток «разворачиваем» вложенность сразу
                const auto& sc = std::get<ScopedBlock>(instr.data);
                auto nested = filterInstrs(sc.instructions);
                // вносим их прямо на уровень выше
                filtered_instrs.insert(filtered_instrs.end(), std::make_move_iterator(nested.begin()),
                                       std::make_move_iterator(nested.end()));
                break;
            }

            default:
                // IF_STATEMENT и всё остальное — игнорируем
                break;
        }
    }
    return filtered_instrs;
}

// возвращает пару: (число подряд вложенных for), указатель на самый глубокий LoopInfo
std::vector<const LoopInfo*> AlgoGenerator::computeChain(const LoopInfo& loop) {
    std::vector<const LoopInfo*> chain;
    const LoopInfo* cur = &loop;

    while (true) {
        // levels++;
        // levels += static_cast<int>(cur->actualNumericStartValues.size());
        chain.push_back(cur);
        if (cur->body.instructions.size() != 1)
            break;
        const Instruction& only = cur->body.instructions[0];
        if (only.type != InstructionType::FOR_LOOP)
            break;
        cur = &std::get<LoopInfo>(only.data);
    }
    return chain;
}

void AlgoGenerator::buildAlgoFromInstructions(const std::vector<Instruction>& instrs,
                                              AlgoInfo* algo,
                                              Block* parentBlock,
                                              IteratorNamer& namer,
                                              int depth) {
    for (size_t idx = 0; idx < instrs.size(); idx++) {
        const auto& instr = instrs[idx];

        switch (instr.type) {
            case InstructionType::FOR_LOOP: {
                const auto& L = std::get<LoopInfo>(instr.data);

                // auto [levels, deepest] = computeLevels(L);
                auto chain = computeChain(L);

                // idx += levels - 1;
                int levels = 0;
                for (auto lp : chain) {
                    levels += static_cast<int>(lp->itName_startVal.size());
                }

                int bid = nextBlockId++;
                Block blk(std::to_string(bid), std::to_string(levels));
                currentBlockPath.push_back(bid);

                // for (int i = 0; i < levels; i++) {
                //     std::string argName = namer.nameAt(depth, i);
                //     blk.addArg(Arg(argName, "0..0"));
                // }
                int argIdx = 0;
                for (auto lp : chain) {
                    // lp->actualStartValues и actualEndValues хранят одинаковую по размеру пару векторов
                    for (size_t v = 0; v < lp->actualNumericStartValues.size(); v++) {
                        // имя аргумента по глубине и порядковому аргументу
                        std::string argName = namer.nameAt(depth, argIdx++);
                        // строим строку "start..end"
                        std::string range = std::to_string(lp->actualNumericStartValues[v]) + ".." +
                                            std::to_string(lp->actualNumericStopValues[v]);
                        blk.addArg(Arg(argName, range));
                    }
                }

                blk.dims = std::to_string(blk.args.size());

                const LoopInfo* deepest = chain.back();
                buildAlgoFromInstructions(deepest->body.instructions,
                                          /*algo=*/nullptr,
                                          /*parentBlock=*/&blk, namer, depth + 1);

                currentBlockPath.pop_back();

                if (algo)
                    algo->addBlock(std::move(blk));
                else
                    parentBlock->addNestedBlock(std::move(blk));

                break;
            }

            case InstructionType::ASSIGNMENT: {
                const auto& A = std::get<AssignmentInfo>(instr.data);
                auto tbl = observer.getTableByAssignmentId(A.id);
                // std::cout << "Ass ID " << A.id << std::endl;

                if (!tbl || !tbl->showsDepends)
                    break;
                // std::cout << "Ass ID " << A.id << std::endl;

                bool hasNeighbors = (instrs.size() > 1);

                if (hasNeighbors && parentBlock) {
                    int abid = nextBlockId++;
                    Block aBlk(std::to_string(abid), "0");

                    tableIdToBlockPath[A.id] = currentBlockPath;
                    tableIdToBlockPath[A.id].push_back(abid);

                    // std::cout << "ID: " << abid << "PATH: ";
                    // for (auto it : currentBlockPath)
                    //     std::cout << it << "::";
                    // std::cout << std::endl;

                    for (auto& row : tbl->rows)
                        processRow(row, aBlk, namer, tbl->verticiesType);

                    if (algo)
                        algo->addBlock(std::move(aBlk));
                    else
                        parentBlock->addNestedBlock(std::move(aBlk));

                } else if (parentBlock) {
                    tableIdToBlockPath[A.id] = currentBlockPath;

                    for (auto& row : tbl->rows)
                        processRow(row, *parentBlock, namer, tbl->verticiesType);

                    // на 0-вом уровне вложенности нужно делать блок размерности 1
                } else {
                    int soloId = nextBlockId++;
                    Block solo(std::to_string(soloId), "1");

                    solo.addArg(Arg("i", "0..0"));

                    tableIdToBlockPath[A.id] = currentBlockPath;
                    tableIdToBlockPath[A.id].push_back(soloId);

                    for (auto& row : tbl->rows)
                        processRow(row, solo, namer, tbl->verticiesType);

                    algo->addBlock(std::move(solo));
                }

                break;
            }
            default:
                break;
        }
    }
}

void AlgoGenerator::processRow(const TableRow& row, Block& block, IteratorNamer& namer, int type) {
    std::ostringstream condition;
    for (size_t idx = 0; idx < row.iters.size(); idx++) {
        if (idx > 0)
            condition << " and ";
        condition << namer.nameAt(0, idx) << " == " << row.iters[idx];
    }

    Vertex vertex(condition.str(), std::to_string(type));

    for (const auto& src : row.sources) {
        std::vector<std::string> bsrcVec;
        std::vector<std::string> srcVec;

        auto it = tableIdToBlockPath.find(src.tableIdx);
        if (it != tableIdToBlockPath.end()) {
            const auto& path = it->second;
            for (size_t idx = 0; idx < path.size(); ++idx) {
                bsrcVec.push_back(std::to_string(path[idx]));
            }
        } else {
            std::cerr << "[ERROR] Path for tableId=" << src.tableIdx << " not found!\n";
        }

        for (int val : src.srcTableIters) {
            srcVec.push_back(std::to_string(val));
        }

        vertex.addDependency(InEdge(bsrcVec, srcVec));
    }

    block.addVertex(vertex);
}
