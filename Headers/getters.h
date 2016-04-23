#ifndef GETTERS_H
#define GETTERS_H

#include <string>
#include <vector>
#include <cstdint>

std::vector<std::string> get_valid_opcodes();
std::string get_opcode(std::string);
bool is_alpha(char);
bool is_num(char);
std::string get_immediate_as_string(std::string);
uint32_t get_immediate_as_int(std::string);
uint8_t get_opcode_as_int(std::string);

#endif
