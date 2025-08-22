#pragma once

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

class CPreprocessor {
   public:
    explicit CPreprocessor(const std::string& input_file,
                           const std::string& output_file = "processed_c_program.c")
        : input_file(input_file), output_file(output_file) {
        std::ofstream out(output_file, std::ios::trunc);
        if (!out) {
            std::cerr << "Failed to create/clear the file: " << output_file << std::endl;
        }
    }

    void expand_compound_assignments_and_increments();

    void print_file() const;

    std::string get_output_file() const { return output_file; }

   private:
    std::string input_file;
    std::string output_file;
};