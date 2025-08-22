#include "CalcExpr.hpp"
#include <iostream>

// is not in use since different math operation's syntax
double ExpressionCalculator::evaluateWithExprtk(const std::string& expr,
                                                const std::unordered_map<std::string, double>& variables) {
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    symbol_table_t symbol_table;

    // локальное копирование, т.к. exprtk требует неконстантные double&
    std::unordered_map<std::string, double> variableCopies = variables;

    for (auto& [name, value] : variableCopies) {
        symbol_table.add_variable(name, value);
    }

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    if (!parser.compile(expr, expression)) {
        // Соберём подробное сообщение об ошибке
        std::ostringstream oss;
        oss << "[ExprTk ERROR] Не удалось разобрать выражение: '" << expr << "'\n";
        oss << "Причина: " << parser.error() << "\n";

        // Выведем информацию по каждой ошибке парсера (если есть)
        for (std::size_t i = 0; i < parser.error_count(); ++i) {
            exprtk::parser_error::type error = parser.get_error(i);
            oss << "  [" << i << "] " << error.diagnostic << " @ " << error.token.position << " near '"
                << error.token.value << "'\n";
        }

        // Бросим исключение с подробностями
        throw std::runtime_error(oss.str());
    }

    return expression.value();
}

double ExpressionCalculator::evaluateWithTinyExpr(const std::string& expression,
                                                  const std::unordered_map<std::string, double>& variables) {
    te_parser parser;

    for (const auto& [name, value] : variables) {
        parser.add_variable_or_function(te_variable{
            name,        // имя переменной
            value,       // значение
            TE_DEFAULT,  // тип переменной (обычная)
            nullptr      // контекст (не нужен)
        });
    }

    double result = parser.evaluate(expression);

    if (!parser.success()) {
        std::ostringstream oss;
        oss << "Expr parcing error: '" << expression << "'\n";

        if (parser.get_last_error_position() != te_parser::npos) {
            oss << "Position: " << parser.get_last_error_position() << "\n";
        }

        if (!parser.get_last_error_message().empty()) {
            oss << "Message: " << parser.get_last_error_message() << "\n";
        }

        throw std::runtime_error(oss.str());
    }

    return result;
}

// int main(int argc, char* argv[]) {
//     std::unordered_map<std::string, double> vars = {{"x", 3}, {"y", 4}};
//     std::string expr = std::string(argv[1]);
//     std::cout << expr << std::endl;
//     std::string converted = MathToTinyExprConverter::convert(expr);
//     std::cout << converted << std::endl;

//     try {
//         double result = ExpressionCalculator::evaluateWithTinyExpr(converted, vars);
//         std::cout << "Result : " << result << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Error : " << e.what() << std::endl;
//     }

//     return 0;
// }