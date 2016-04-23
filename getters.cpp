#include <cstdint>
#include <sstream>

#include "Headers/getters.h"

std::vector<std::string> get_valid_opcodes() {
    std::vector<std::string> valid_opcodes_v { 
        "add", "addu", "addi", "addiu", "and", "andi", "div", "divu",
        "mult", "multu", "nor", "or", "ori", "sll", "slv", "sra", "srav", 
        "srl", "srlv", "sub", "subu", "xor", "xori", "lhi", "llo", "slt", 
        "sltu", "slti", "sltiu", "beq", "bgtz", "blez", "bne", "j", 
        "jal", "jalr", "jr", "lb", "lbu", "lh", "lhu", "lw", "sb", 
        "sh", "sw", "mfhi", "mflo", "mthi", "mtlo", "trap" };
    return valid_opcodes_v; 
}

/*
 * This function requires preprocess to be called on line first.
 */
std::string get_opcode(std::string line) {
    /* if empty line, data line, blank line, or newline, 
     * return empty string, no opcode.  */
    if ((line[0] == ' ') || (line[0] == '.') || (line[0] == '\n')) {
        return "";
    }

    /* get opcode */
    unsigned int i;
    std::string opcode = "";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            break;
        } else {
            opcode += line[i];
        }
    }
    return opcode;
} 

bool is_alpha(char c) {
    return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}

bool is_num(char c) {
    return ((c >= '0') && (c <= '9'));
}

std::string get_immediate_as_string(std::string line) { 
    unsigned int i;
    std::string immediate_str = "";
    for (i = 0; i < line.size(); i++) {
        /* remove opcode */
        if ( is_num(line[i]) ) {
            immediate_str = immediate_str + line[i];
        }
    }
    return immediate_str;
}

uint32_t get_immediate_as_int(std::string line) {
    uint32_t immediate_int;
    std::string immediate_str = get_immediate_as_string(line);
    std::stringstream(immediate_str) >> immediate_int;
    return immediate_int;
}
