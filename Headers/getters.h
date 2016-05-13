#ifndef GETTERS_H
#define GETTERS_H

#include <string>
#include <vector>
#include <cstdint>

#include "opcodes.h"

enum Instruction_type_t { R_type, J_type, I_type };

std::vector<std::string> get_valid_opcodes();
std::string get_opcode(std::string);
bool is_alpha(char);
bool is_num(char);
std::string get_immediate_as_string(std::string);
int16_t get_immediate_as_int(std::string);
int8_t get_opcode_as_int(std::string);
std::vector<int8_t> get_registers(std::string, int);
Instruction_type_t get_type(std::string);
Instruction_type_t get_type(int32_t);

int8_t get_opcode_from_machinecode(int32_t);

int8_t get_register_s(int32_t);

int8_t get_register_t(int32_t);
int8_t get_register_d(int32_t);
int8_t get_shift_amount(int32_t);
int16_t get_immediate_from_machinecode(int32_t);
int8_t get_function_from_machinecode(int32_t);
int32_t get_jump_target(int32_t);
#endif
