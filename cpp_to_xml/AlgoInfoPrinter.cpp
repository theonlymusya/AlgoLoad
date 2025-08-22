#include <iostream>
#include "AlgoInfo.hpp"

std::string AlgoInfo::makeIndent(int indent) const {
    return std::string(indent * 2, ' ');
}

std::string AlgoInfo::join(const std::vector<std::string>& vec, const std::string& delim) const {
    std::string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i + 1 < vec.size())
            result += delim;
    }
    return result;
}

void AlgoInfo::print(const AlgoInfo& algo) {
    std::cout << "<algo>\n";

    // printParams(algo.getParams(), 1);
    for (const auto& block : algo.getBlocks()) {
        printBlock(block, 1);
    }

    std::cout << "</algo>\n";
}

void AlgoInfo::printParams(const std::vector<Param>& params, int indent) {
    std::string ind = makeIndent(indent);
    std::cout << ind << "<params>\n";
    for (const auto& p : params) {
        std::cout << ind << "  <param name = \"" << p.name << "\" type = \"" << p.type << "\" value = \""
                  << p.value << "\"></param>\n";
    }
    std::cout << ind << "</params>\n";
}

void AlgoInfo::printBlock(const Block& block, int indent) {
    std::string ind = makeIndent(indent);
    std::cout << ind << "<block id = \"" << block.id << "\" dims = \"" << block.dims << "\">\n";

    for (const auto& arg : block.args)
        printArg(arg, indent + 1);

    for (const auto& b : block.nestedBlocks)
        printBlock(b, indent + 1);

    for (const auto& v : block.vertices)
        printVertex(v, indent + 1);

    std::cout << ind << "</block>\n";
}

void AlgoInfo::printArg(const Arg& arg, int indent) {
    std::string ind = makeIndent(indent);
    std::cout << ind << "<arg name = \"" << arg.name << "\" val = \"" << arg.val << "\"></arg>\n";
}

void AlgoInfo::printVertex(const Vertex& vertex, int indent) {
    std::string ind = makeIndent(indent);
    if (vertex.dependecies.empty()) {
        std::cout << ind << "<vertex condition = \"" << vertex.condition << "\" type = \"" << vertex.type
                  << "\"></vertex>\n";
    } else {
        std::cout << ind << "<vertex condition = \"" << vertex.condition << "\" type = \"" << vertex.type
                  << "\">\n";
        for (const auto& input : vertex.dependecies) {
            printInEdge(input, indent + 1);
        }
        std::cout << ind << "</vertex>\n";
    }
}

void AlgoInfo::printInEdge(const InEdge& in, int indent) {
    std::string ind = makeIndent(indent);
    std::cout << ind << "<in bsrc = \"" << join(in.bsrc, "::") << "\" src = \"" << join(in.src, ", ")
              << "\"></in>\n";
}
