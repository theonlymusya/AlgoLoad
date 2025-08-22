#include "CPreprocess.hpp"

void CPreprocessor::expand_compound_assignments_and_increments() {
    std::ifstream in(input_file);
    if (!in) {
        std::cerr << "Failed to open input file: " << input_file << std::endl;
        return;
    }

    std::ofstream out(output_file);
    if (!out) {
        std::cerr << "Failed to open output file for writing: " << output_file << std::endl;
        return;
    }

    std::string line;

    // --- Compound assignment operators ---
    std::regex re_plus(R"((\S+)\s*\+=\s*)");
    std::regex re_minus(R"((\S+)\s*-=\s*)");
    std::regex re_mul(R"((\S+)\s*\*=\s*)");
    std::regex re_div(R"((\S+)\s*/=\s*)");
    std::regex re_mod(R"((\S+)\s*%=\s*)");

    std::regex re_and(R"((\S+)\s*&=\s*)");
    std::regex re_or(R"((\S+)\s*\|=\s*)");
    std::regex re_xor(R"((\S+)\s*\^=\s*)");
    std::regex re_shl(R"((\S+)\s*<<=\s*)");
    std::regex re_shr(R"((\S+)\s*>>=\s*)");

    // --- Increment/decrement operators ---
    std::regex postfix_inc(R"((\b\w+)\s*\+\+)");
    std::regex prefix_inc(R"(\+\+\s*(\b\w+))");

    std::regex postfix_dec(R"((\b\w+)\s*\-\-)");
    std::regex prefix_dec(R"(\-\-\s*(\b\w+))");

    while (std::getline(in, line)) {
        line = std::regex_replace(line, re_plus, "$1 = $1 + ");
        line = std::regex_replace(line, re_minus, "$1 = $1 - ");
        line = std::regex_replace(line, re_mul, "$1 = $1 * ");
        line = std::regex_replace(line, re_div, "$1 = $1 / ");
        line = std::regex_replace(line, re_mod, "$1 = $1 % ");

        line = std::regex_replace(line, re_and, "$1 = $1 & ");
        line = std::regex_replace(line, re_or, "$1 = $1 | ");
        line = std::regex_replace(line, re_xor, "$1 = $1 ^ ");
        line = std::regex_replace(line, re_shl, "$1 = $1 << ");
        line = std::regex_replace(line, re_shr, "$1 = $1 >> ");

        line = std::regex_replace(line, postfix_inc, "$1 = $1 + 1");
        line = std::regex_replace(line, prefix_inc, "$1 = $1 + 1");
        line = std::regex_replace(line, postfix_dec, "$1 = $1 - 1");
        line = std::regex_replace(line, prefix_dec, "$1 = $1 - 1");

        out << line << '\n';
    }

    in.close();
    out.close();
}

void CPreprocessor::print_file() const {
    std::ifstream in(output_file);
    if (!in) {
        std::cerr << "Failed to open file for reading: " << output_file << std::endl;
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << std::endl;
    }
    in.close();
}
