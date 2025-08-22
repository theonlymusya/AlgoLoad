#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "ASTBuilder.hpp"
#include "ASTContext.hpp"
#include "AlgoGenerator.hpp"
#include "CPreprocess.hpp"
#include "InstrPrinter.hpp"
#include "Tables.hpp"
#include "antlr4-runtime.h"
#include "small_c_grammarLexer.h"
#include "small_c_grammarParser.h"

using namespace antlr4;
#include <iostream>
#include <variant>

int main(int argc, const char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_filename> <output_filename>" << std::endl;
        return 1;
    }

    std::string input_filename = std::string(argv[1]);

    CPreprocessor preprocessor(input_filename);
    preprocessor.expand_compound_assignments_and_increments();
    preprocessor.print_file();

    std::string file = preprocessor.get_output_file();
    std::ifstream stream(file);
    if (!stream) {
        std::cerr << "Error opening file: " << file << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << stream.rdbuf();
    ANTLRInputStream input(buffer.str());

    small_c_grammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    small_c_grammarParser parser(&tokens);
    tree::ParseTree* tree = parser.program();

    // ASTPrinter printer;
    // printer.visit(tree);

    std::cout << "\n=== AST, сгенерированное ANTLR4 ===\n";
    std::cout << tree->toStringTree(&parser) << std::endl;
    ASTBuilder builder;
    tree::ParseTreeWalker::DEFAULT.walk(&builder, tree);
    ASTContext context = builder.getASTContext();
    Observer observer;
    context.setObserver(&observer);

    // std::cout << "\n=== Развернутое выполнение кода ===\n";
    // InstructionsPrinter printer;
    // printer.printAST(context.get_instr());

    context.executeInstructions();
    InstructionsPrinter::printInstructionsScheme(context.getInstructions());
    for (const auto& [id, table] : observer.getAllTables()) {
        std::cout << "\n=== Таблица для переменной " << table->targetVar << " (id=" << id << ") ===\n";
        InstructionsPrinter::printTable(*table);
    }

    AlgoGenerator generator(observer, context);
    AlgoInfo algo = generator.generate();
    algo.print(algo);
    // после твоих строк:
    std::ofstream out(argv[2], std::ios::trunc);
    auto old_buf = std::cout.rdbuf(out.rdbuf());
    algo.print(algo);          // уедет в файл
    std::cout.rdbuf(old_buf);  // вернуть обратно консоль

    return 0;
}
