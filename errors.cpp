#include <iostream>
#include <vector>
#include <map>
#include "Headers/errors.h"

void report_error(std::string filename, std::string reason) {
    std::cout << "ERROR in file " << filename << " : " << reason << std::endl;
}

void preprocess(std::string & line) {

    if (line[0] == ' ') {
        while (line[0] == ' ') {
            line = line.substr(1, line.size());
        }
    }

    if (line[0] == '\t') { 
        while (line[0] == '\t') {
            line = line.substr(1, line.size());
        }
    }
}

std::string get_opcode(std::string line) {
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

bool is_valid_assembly_code(std::string line) {
    // test
    bool set_debug = false;

    std::vector<std::string> valid_opcodes_v = get_valid_opcodes();
    

    /* do not allow blank lines */
    if (line[0] == '\n') {
        return false;
    }

    std::string opcode = get_opcode(line);

    bool is_valid_opcode = false;
    unsigned int i;
    for (i = 0; i < valid_opcodes_v.size(); i++) {
        // check if opcode matches the valid set
        if (opcode == valid_opcodes_v[i]) {
            is_valid_opcode = true;
        }
    } 

    if (set_debug) {
        std::cout << "opcode: " << opcode 
        << ((is_valid_opcode)? " VALID" : " NOT A VALID OPCODE") 
        << std::endl;
    }

    return is_valid_opcode;
}