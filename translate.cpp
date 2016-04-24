#include <iostream>
#include <bitset>
#include <stdio.h>
#include <cstdlib>

#include "Headers/errors.h"
#include "Headers/getters.h"
#include "Headers/opcodes.h"
#include "Headers/registers.h"

uint32_t asm_to_machinecode(std::string line) {

    enum Instruction_type_t { R, J, I };
    Instruction_type_t type;

    std::string opcode_as_string = get_opcode(line);

    // get machine code for the opcode
    int opcode_as_int = get_opcode_as_int(opcode_as_string);

    // determine which type of instruction (R, J, I) 
    if (opcode_as_string[0] == 'j') {
        type = J; 
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

        type = I;
    } else {
        type = R;
    } 

    uint32_t returnValue = opcode_as_int << 26;

    /* Jump type opcode, first 6 bits are opcode, last 26 bits
     * multiplited by 4 gives the memory address to jump to.
     */ 
    if (type == J) { 
        std::cout << "J type instructions are not yet supported, exiting"
            << std::endl;
        std::exit(EXIT_FAILURE);
    } else if (type == I) { 

        uint16_t immediate;
        std::vector<uint8_t> registers = get_registers(line, type);
        returnValue = returnValue + (registers[1] << 21);
        returnValue = returnValue + (registers[0] << 16);
        immediate = get_immediate_as_int(line);
        returnValue += immediate;

        uint32_t register_s = registers[1];
        uint32_t register_t = registers[0];

        opcode_as_int = opcode_as_int << 26;
        register_s    = register_s    << 21;
        register_t    = register_t    << 16;

        /*
        std::cout << std::bitset<32>(opcode_as_int) << std::endl;
        std::cout << std::bitset<32>(register_s) << std::endl;
        std::cout << std::bitset<32>(register_t) << std::endl;
        std::cout << std::bitset<32>(immediate) << std::endl;
        std::cout << std::bitset<32>(returnValue) << std::endl;
        */

        //printf("Opcode: %x, register_s: %x, register_t: %x, immediate: %x, returnValue: %x\n", opcode_as_int, registers[1], registers[0], immediate, returnValue);
        return returnValue;
    } else {
        /* else, R type */ 
        std::cout << "R type instructions are not yet supported, exiting"
            << std::endl;
        std::exit(EXIT_FAILURE);
    }

}
