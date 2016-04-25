#ifndef GETTERS_H
#define GETTERS_H

#include <string>
#include <vector>
#include <cstdint>

enum Instruction_type_t { R_type, J_type, I_type };

std::vector<std::string> get_valid_opcodes();
std::string get_opcode(std::string);
bool is_alpha(char);
bool is_num(char);
std::string get_immediate_as_string(std::string);
uint16_t get_immediate_as_int(std::string);
uint8_t get_opcode_as_int(std::string);
std::vector<uint8_t> get_registers(std::string, int);
Instruction_type_t get_type(std::string);
Instruction_type_t get_type(uint32_t);

#endif
