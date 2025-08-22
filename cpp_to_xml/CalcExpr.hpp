#pragma once
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include "ContextStructs.hpp"
#include "external/exprtk/exprtk.hpp"
#include "external/tinyExpr/tinyexpr.h"

class ExpressionCalculator {
   public:
    // std::unordered_map<std::string, double> vars = {{"x", 10}, {"y", 5}};
    static double evaluateWithExprtk(const std::string& expr,
                                     const std::unordered_map<std::string, double>& variables);
    static double evaluateWithTinyExpr(const std::string& expressionStr,
                                       const std::unordered_map<std::string, double>& variables);
};

class MathToTinyExprConverter {
   public:
    // usage: std::string converted = MathToTinyExprConverter::convert(expr);
    static std::string convert(const std::string& input) {
        std::string output = input;

        const std::vector<std::pair<std::regex, std::string>> replacements = {
            {std::regex(R"(([^?:()]+)\s*\?\s*([^?:()]+)\s*:\s*([^?:()]+))"), "IF($1, $2, $3)"},
            {std::regex(R"(\bacosh\s*\(([^()]+)\))"), "log($1 + sqrt($1^2 - 1))"},
            {std::regex(R"(\basinh\s*\(([^()]+)\))"), "log($1 + sqrt($1^2 + 1))"},
            {std::regex(R"(\batanh\s*\(([^()]+)\))"), "0.5 * log((1 + $1) / (1 - $1))"},
            {std::regex(R"(\bcbrt\s*\(([^()]+)\))"), "($1)^(1/3)"},
            {std::regex(R"(\bcomb\s*\(([^(),]+),([^()]+)\))"), "COMBIN($1, $2)"},
            {std::regex(R"(\bcopysign\s*\(([^(),]+),([^()]+)\))"), "SIGN($1) * abs($2)"},
            {std::regex(R"(\bdegrees\s*\(([^()]+)\))"), "($1 * 180) / pi"},
            {std::regex(R"(\bdist\s*\(([^(),]+),([^()]+),([^(),]+),([^()]+)\))"),
             "sqrt(($1 - $2)^2 + ($3 - $4)^2)"},
            {std::regex(R"(\bexpm1\s*\(([^()]+)\))"), "EXP($1) - 1"},
            {std::regex(R"(\bfabs\s*\(([^()]+)\))"), "ABS($1)"},
            {std::regex(R"(\bfactorial\s*\(([^()]+)\))"), "FAC($1)"},
            {std::regex(R"(\bfmod\s*\(([^(),]+),([^()]+)\))"), "MOD($1, $2)"},
            {std::regex(R"(\bfsum\s*\(([^()]+)\))"), "SUM($1)"},
            {std::regex(R"(\bgamma\s*\(([^()]+)\))"), "TGAMMA($1)"},
            {std::regex(R"(\bhypot\s*\(([^(),]+),([^()]+)\))"), "sqrt($1^2 + $2^2)"},
            {std::regex(R"(\bisclose\s*\(([^(),]+),([^()]+)\))"), "ABS($1 - $2) < eps"},
            {std::regex(R"(\bisqrt\s*\(([^()]+)\))"), "INT(SQRT($1))"},
            {std::regex(R"(\bldexp\s*\(([^(),]+),([^()]+)\))"), "$1 * 2^$2"},
            {std::regex(R"(\blgamma\s*\(([^()]+)\))"), "LOG(TGAMMA($1))"},
            {std::regex(R"(\blog1p\s*\(([^()]+)\))"), "LN(1 + $1)"},
            {std::regex(R"(\blog2\s*\(([^()]+)\))"), "LN($1) / LN(2)"},
            {std::regex(R"(\bmodf\s*\(([^()]+)\))"), "TRUNC($1), $1 - TRUNC($1)"},
            {std::regex(R"(\bperm\s*\(([^(),]+),([^()]+)\))"), "NPR($1, $2)"},
            {std::regex(R"(\bradians\s*\(([^()]+)\))"), "($1 * pi) / 180"},
            {std::regex(R"(\bremainder\s*\(([^(),]+),([^()]+)\))"), "MOD($1, $2)"},
            {std::regex(R"(\bisqrt\s*\(\s*([^\(\)]+?)\s*\))"), "TRUNC(SQRT($1))"},
            {std::regex(R"(\btanh\s*\(\s*([^\(\)]+?)\s*\))"), "SINH($1) / COSH($1)"}};

        for (const auto& [pattern, replacement] : replacements) {
            output = std::regex_replace(output, pattern, replacement);
        }

        return output;
    }
};

namespace expr_utils {

// {name : VarInfo} -> {name : num_value}
// skips variable if it doesn't have numerical value
inline std::unordered_map<std::string, double> extractValues(
    const std::unordered_map<std::string, VarInfo>& vars) {
    std::unordered_map<std::string, double> result;

    for (const auto& [name, info] : vars) {
        if (info.numericVal.has_value()) {
            result[name] = *info.numericVal;
        }
    }

    return result;
}

}  // namespace expr_utils
