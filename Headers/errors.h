#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include <vector>

void preprocess(std::string&);
bool is_valid_assembly_code(std::string);
std::string get_opcode(std::string);
std::vector<std::string> get_valid_opcodes();
void report_error(std::string, std::string);

#endif
