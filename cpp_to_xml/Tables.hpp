#pragma once
#include <map>
#include <string>
#include <vector>

struct Src {
    int tableIdx;
    std::vector<int> srcTableIters;
};

struct TableRow {
    int scheduleIdx;
    std::vector<int> iters;                   // значения i, j, k, ... (типа строка)
    std::vector<int> LHSVarIdx;               // типа столбец
    std::vector<std::vector<int>> RHSVarIdx;  // индексные выражения переменных справа (типа элементы)
    std::vector<Src> sources;                 // источники значений справа от "="
};

class Table {
   public:
    // каждая таблица соответствует оператору присваивания
    // каждая таблица ассоциирована с переменной
    std::string targetVar;
    int tableId;
    int dim;
    int verticiesType = 0;
    bool showsDepends = false;

    std::vector<TableRow> rows;
    // std::vector<std::pair<int, int>> iterMinsMaxs;

    Table(std::string _var, int _id, int _dim) : targetVar(std::move(_var)), tableId(_id), dim(_dim) {}

    const TableRow* getRowByScheduleIndex(int scheduleIdx) const {
        for (const auto& row : rows) {
            if (row.scheduleIdx == scheduleIdx)
                return &row;
        }
        return nullptr;
    }
    void addRow(const TableRow& row);
};

class Schedule {
   public:
    std::vector<std::shared_ptr<Table>> tables;

    void addTable(const std::shared_ptr<Table>& table) { tables.push_back(table); }
};

struct MetaNode {
    enum class NodeType { ForLoop, Assignment };

    NodeType type;
    int id;
    std::vector<std::shared_ptr<MetaNode>> children;

    MetaNode(NodeType t, int identifier) : type(t), id(identifier) {}
};

struct LoopMetaInfo {
    int loopId;        // уникальный id цикла for
    int parentLoopId;  // id родителя (0 если нет)
    // std::vector<std::string> iteratorNames;  // имена итераторов (i, j, k)
    std::vector<int> tablesInside;  // id таблиц присваиваний внутри этого for
    std::vector<int> nestedLoops;   // id вложенных for внутри этого for
};

class Observer {
   public:
    // желательно сделать приватной
    std::unordered_map<std::string, Schedule> LHVars_Schedule;

    bool hasTableForAssignment(int id) const;
    std::shared_ptr<Table> getTableByAssignmentId(int assignmentId) const;

    const std::map<int, std::shared_ptr<Table>>& getAllTables() const;

    void registerTableForVar(const std::string& var_name, std::shared_ptr<Table> table);

    int nextScheduleIndexForVar(const std::string& varName) { return ++scheduleCounters[varName]; }

    std::optional<Src> findLatestSrc(const std::string& varName, const std::vector<int>& rhsIndices) const;

   private:
    // каждая таблица соответствует оператору присваивания
    std::map<int, std::shared_ptr<Table>> AssignmentId_Table;
    std::unordered_map<std::string, int> scheduleCounters;  // varName → lastScheduleIdx
};
