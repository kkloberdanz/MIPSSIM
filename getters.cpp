#include <iostream>
#include <cstdint>
#include <sstream>

#include "Headers/getters.h"
#include "Headers/opcodes.h"
#include "Headers/search.h"
#include "Headers/errors.h"

std::vector<std::string> get_valid_opcodes() {
    std::vector<std::string> valid_opcodes_v {
    "add", "addi", "addiu", "addu", "and", "andi", "beq", "bgtz", "blez", "bne", "div", "divu", "j", "jal", "jalr", "jr", "lb", "lbu", "lh", "lhi", "lhu", "llo", "lw", "mfhi", "mflo", "mthi", "mtlo", "mult", "multu", "nor", "or", "ori", "sb", "sh", "sll", "slt", "slti", "sltiu", "sltu", "slv", "sra", "srav", "srl", "srlv", "sub", "subu", "sw", "syscall", "trap", "xor", "xori" }; 
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
           ADD, ADDI, ADDIU, ADDU, AND, ANDI, BEQ, BGTZ, BLEZ, BNE, DIV, DIVU, J, JAL, JALR, JR, LB, LBU, LH, LHI, LHU, LLO, LW, MFHI, MFLO, MTHI, MTLO, MULT, MULTU, NOR, OR, ORI, SB, SH, SLL, SLT, SLTI, SLTIU, SLTU, SLV, SRA, SRAV, SRL, SRLV, SUB, SUBU, SW, SYSCALL, TRAP, XOR, XORI 
    };

    std::vector<std::string> valid_opcode_names_v { 
           "add", "addi", "addiu", "addu", "and", "andi", "beq", "bgtz", "blez", "bne", "div", "divu", "j", "jal", "jalr", "jr", "lb", "lbu", "lh", "lhi", "lhu", "llo", "lw", "mfhi", "mflo", "mthi", "mtlo", "mult", "multu", "nor", "or", "ori", "sb", "sh", "sll", "slt", "slti", "sltiu", "sltu", "slv", "sra", "srav", "srl", "srlv", "sub", "subu", "sw", "syscall", "trap", "xor", "xori"
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

uint16_t get_immediate_as_int(std::string line) {
    uint32_t immediate_int;
    std::string immediate_str = get_immediate_as_string(line);
    std::stringstream(immediate_str) >> immediate_int;
    return immediate_int;
}

std::vector<uint8_t> get_registers(std::string line, int type) {
    /* returns the registers used in the following format:
     * - For I type:
     *      register_t, register_s
     *
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
                i++;
            }
            /* convert reg number from string to int, append to vector */
            std::stringstream(reg_num_s) >> reg_num_int; 
            reg_num_int = reg_num_int - '0';
            //std::cout << "Register: " << reg_num_int << std::endl; 
            register_v.push_back(reg_num_int);
            reg_num_int = 0;
            reg_num_s = "";
        }
    } 
    //printf("register_v[1] = %d, regitser_v[0] = %d\n",register_v[1], register_v[0] );
    return register_v;
}


Instruction_type_t get_type(std::string line) {
    // determine which type of instruction (R, J, I) 
    std::string opcode_as_string = get_opcode(line);
    if (opcode_as_string[0] == 'j') {
        return J_type; 
    } else if ( (opcode_as_string == "addi" ) || 
                (opcode_as_string == "addiu") ||
                (opcode_as_string == "andi" ) ||
                (opcode_as_string == "lhi"  ) ||
                (opcode_as_string == "mfhi" ) ||
                (opcode_as_string == "mthi" ) ||
                (opcode_as_string == "ori"  ) ||
                (opcode_as_string == "slti" ) ||
                (opcode_as_string == "sltiu") ||
                (opcode_as_string == "xori" ) ) {

        return I_type;
    } else {
        return R_type;
    } 
}

Instruction_type_t get_type(uint32_t machinecode) {
    // determine which type of instruction (R, J, I) 
    uint8_t opcode = machinecode / 1000000;
    if ( (opcode == J   ) ||
         (opcode == JAL ) ||
         (opcode == JALR) ||
         (opcode == JR) ) {
        return J_type; 

    } else if ( (opcode == ADDI ) || 
                (opcode == ADDIU) ||
                (opcode == ANDI ) ||
                (opcode == LHI  ) ||
                (opcode == MFHI ) ||
                (opcode == MTHI ) ||
                (opcode == ORI  ) ||
                (opcode == SLTI ) ||
                (opcode == SLTIU) ||
                (opcode == XORI ) ) {

        return I_type;
    } else {
        return R_type;
    } 
}
