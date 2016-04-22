#include <iostream> 
#include <stdio.h> 
#include <vector> 
#include <string> 
#include <cstdint> 
#include <algorithm> 
#include "Headers/opcodes.h"
#include "search.cpp"
#include "Headers/errors.h" 

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
        report_error("opcodes.cpp", "opcode not found");
        return -1;
    }
}
