#include <cstdint>
#include <sstream>

#include "Headers/getters.h"
#include "Headers/opcodes.h"
#include "Headers/search.h"
#include "Headers/errors.h"

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

uint8_t get_opcode_as_int(std::string opcode) { 

    std::vector<uint8_t>    valid_opcodes_as_int_v {
        ADD, ADDI, ADDIU, ADDU, AND, ANDI, BEQ, BGTZ, BLEZ, 
        BNE, DIV, DIVU, J, JAL, JALR, JR, LB, LBU, LH, 
        LHI, LHU, LLO, LW, MFHI, MFLO, MTHI, MTLO, MULT, 
        MULTU, NOR, OR, ORI, SB, SH, SLL, SLT, SLTI, 
        SLTIU, SLTU, SLV, SRA, SRAV, SRL, SRLV, SUB, SUBU, 
        SW, TRAP, XOR, XORI 
    };

    std::vector<std::string> valid_opcode_names_v { 
        "add", "addi", "addiu", "addu", "and", "andi", "beq", "bgtz", 
        "blez", "bne", "div", "divu", "j", "jal", "jalr", "jr", "lb", 
        "lbu", "lh", "lhi", "lhu", "llo", "lw", "mfhi", "mflo", "mthi", 
        "mtlo", "mult", "multu", "nor", "or", "ori", "sb", "sh", "sll", 
        "slt", "slti", "sltiu", "sltu", "slv", "sra", "srav", "srl", 
        "srlv", "sub", "subu", "sw", "trap", "xor", "xori" 
    }; 

    int index;
    index = kgk::binary_search(valid_opcode_names_v, opcode);

    // testing
    //std::cout << valid_opcodes_as_int_v[index] << std::endl;
    //for (int i = 0; i < 10; i++) {
        //printf("%x\n", valid_opcodes_as_int_v[i]);
    //}

    if (index != -1) {
        return valid_opcodes_as_int_v[index];
    } else {
        report_error("opcodes.cpp", "opcode: '"+opcode+"' not found");
        return -1;
    }
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
        
        /* ignore registers */
        if ( line[i] == '$' ) {
            while (line[i] != ',') {
                i++;
            }
        }

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

std::vector<uint8_t> get_registers(std::string line, int type) {
    /* returns the registers used in the following format:
     * - For I type:
     *      register_s, register_t
     *
     * - For R type:
     *      register_s, register_t, register_d
     */
    /* Needs work */
    unsigned int i;
    std::string reg_num_s = "";
    uint8_t reg_num_int;
    std::vector<uint8_t> register_v;

    for (i = 0; i < line.size(); i++) {
        if (line[i] == '$') {
            while (line[i] != ',') {
                if ( (line[i] == '\n') || (line[i] == ' ') ) {
                    break;
                }
                if (is_num(line[i])) {
                    reg_num_s += line[i];
                }
            }
            /* convert reg number from string to int, append to vector */
            std::stringstream(reg_num_s) >> reg_num_int; 
            register_v.push_back(reg_num_int);
            reg_num_int = 0;
            reg_num_s = "";
        }
    } 
    return register_v;
}
