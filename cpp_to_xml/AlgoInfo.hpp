#pragma once
#include "string"

// кстати оно нам по моему даже не нужно, всё цифрами писать планируется
// Представляет <arg name=... val=... />
// Представляет <param name=... type=... value=... />
struct Param {
    std::string name;
    std::string type;
    std::string value;

    Param(const std::string& n, const std::string& t, const std::string& v) : name(n), type(t), value(v) {}
};

struct Arg {
    std::string name;
    std::string val;

    Arg(const std::string& n, const std::string& v) : name(n), val(v) {}
};

// Представляет <in bsrc=... src=... />
// bsrc=bsrc[0]::bsrc[1]::bsrc[2]:: ...
// src=src[0], src[1], src[2] ...
struct InEdge {
    std::vector<std::string> bsrc;
    std::vector<std::string> src;

    InEdge(const std::vector<std::string>& b, const std::vector<std::string>& s) : bsrc(b), src(s) {}
};

// Представляет <vertex ...>...</vertex>
struct Vertex {
    std::string condition;
    std::string type;
    std::vector<InEdge> dependecies;

    Vertex(const std::string& cond, const std::string& t) : condition(cond), type(t) {}

    void addDependency(const InEdge& edge) { dependecies.push_back(edge); }
};

// Представляет <block id=... dims=...>...</block>
struct Block {
    std::string id;
    std::string dims;

    std::vector<Arg> args;
    std::vector<Vertex> vertices;
    // if any
    std::vector<Block> nestedBlocks;

    Block(const std::string& i, const std::string& d) : id(i), dims(d) {}

    void addArg(const Arg& arg) { args.push_back(arg); }
    void addVertex(const Vertex& vertex) { vertices.push_back(vertex); }
    void addNestedBlock(const Block& block) { nestedBlocks.push_back(block); }
};

// Корень всей структуры — <algo>...</algo>
class AlgoInfo {
   public:
    void addParam(const Param& param) { params.push_back(param); }
    void addBlock(const Block& block) { blocks.push_back(block); }

    const std::vector<Param>& getParams() const { return params; }
    const std::vector<Block>& getBlocks() const { return blocks; }

    // печатки
    void print(const AlgoInfo& algo);
    void printParams(const std::vector<Param>& params, int indent);
    void printBlock(const Block& block, int indent);
    void printVertex(const Vertex& vertex, int indent);
    void printArg(const Arg& arg, int indent);
    void printInEdge(const InEdge& in, int indent);
    std::string makeIndent(int indent) const;
    std::string join(const std::vector<std::string>& vec, const std::string& delim) const;

   private:
    std::vector<Param> params;
    std::vector<Block> blocks;
};

// Usage example:

// AlgoInfo algo;

// algo.addParam({"n", "int", "4"});
// algo.addParam({"m", "int", "4"});

// Block outer("0", "1");
// outer.addArg({"i", "0..n-1"});

// Block inner1("0", "1");
// inner1.addArg({"j", "0..m-1"});
// inner1.addVertex({"", "1"});

// Block inner2("1", "1");
// inner2.addArg({"j", "0..m-1"});
// Vertex v2("", "1");
// v2.addDependency({{"0", "0"}, {"i", "j"}});
// inner2.addVertex(v2);

// outer.addNestedBlock(inner1);
// outer.addNestedBlock(inner2);
// algo.addBlock(outer);

// План
// Каждый раз, когда мы входим в цикл for - появляется новый блок, в котором
// id соответствует циклу for
// а нам в src надо писать всякое типа 0::0::1 из айдишников циклов
// поэтому надо видимо делать какую то ассоциацию из таблиц и циклов id шников циклов for

// при обходе цикла for надо добавлять block
// вопрос: как узнавать его вложенность?
// вопрос: как писать его id? допустим просто сквозной id++

// при обходе цикла for надо добавлять arg (при чём в цикле для itNames)
// вопрос: name ? это буквально имя итератора (или нескольких)
// вопрос: диапазон 0..n ? это стартовое значение и последнее значение, которое принимал итератор

// при обходе переменных надо заполнять vertex
// warning: заполнение возможно уже после полного execution