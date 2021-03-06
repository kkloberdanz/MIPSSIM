#include <iostream>
#include <bitset>
#include <stdio.h>
#include <cstdlib>

#include "Headers/errors.h"
#include "Headers/getters.h"
#include "Headers/opcodes.h"
#include "Headers/registers.h"
#include "Headers/func.h"

int32_t asm_to_machinecode(std::string line) {


    if (line.substr(0, 7) == "syscall") {
        return SYSCALL;
    }

    std::string opcode_as_string = get_opcode(line);
    // get machine code for the opcode
    int opcode_as_int = get_opcode_as_int(opcode_as_string);
    /*
    if (opcode_as_int == SYSCALL) {
        return (SYSCALL << 26);
    }
    */

    Instruction_type_t type = get_type(opcode_as_string);
    int32_t returnValue = opcode_as_int << 26;

    /* Jump type opcode, first 6 bits are opcode, last 26 bits
     * multiplited by 4 gives the memory address to jump to.
     */ 
    if (type == J_type) { 
        std::cout << "J type instructions are not yet supported, exiting"
            << std::endl;
        std::exit(EXIT_FAILURE);
    } else if (type == I_type) { 

        int16_t immediate;
        std::vector<int8_t> registers = get_registers(line, type);
        returnValue = returnValue + (registers[1] << 21);
        returnValue = returnValue + (registers[0] << 16);
        immediate = get_immediate_as_int(line);
        returnValue += immediate;

        /*
        int32_t register_s = registers[1];
        int32_t register_t = registers[0];

        opcode_as_int = opcode_as_int << 26;
        register_s    = register_s    << 21;
        register_t    = register_t    << 16;

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
        //std::cout << "R type instructions are not yet supported, exiting"
            //<< std::endl;
        //std::exit(EXIT_FAILURE);

        int32_t register_s;
        int32_t register_t;
        int32_t register_d;
        //int8_t  shift_ammount = 0;
        int8_t  function = get_opcode_as_int(opcode_as_string); 

        std::vector<int8_t> registers = get_registers(line, type);
        /*
        printf("registers[0] = %d\n", registers[0]);
        printf("registers[1] = %d\n", registers[1]);
        printf("registers[2] = %d\n", registers[2]);
        */

        register_d = registers[0];
        register_s = registers[1];
        register_t = registers[2];


        register_s = register_s << 21;
        register_t = register_t << 16;
        register_d = register_d << 11;

        /*
        std::cout << "opcode: " << std::endl;
        std::cout << std::bitset<32>(returnValue) << std::endl;
        std::cout << std::bitset<32>(register_s) << std::endl;
        std::cout << std::bitset<32>(register_t) << std::endl;
        std::cout << std::bitset<32>(register_d) << std::endl;
        */
        returnValue = register_s + register_d + register_t + function;
        //std::cout << std::bitset<32>(returnValue) << std::endl;
        return returnValue;
    }

}
