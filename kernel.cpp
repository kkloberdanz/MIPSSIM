#include <cstdint>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "Headers/kernel.h"
#include "Headers/registers.h"
#include "Headers/getters.h"
#include "Headers/opcodes.h"

#define MEMORY_SIZE 100

/* initialize registers */
std::vector<uint32_t> REGISTERS(32, 0x0); 

/* 
 * Initialize memory 
 *
 * Each section of memory is 8 bits wide. 1 word is 32 bits,
 * so 4 sections of memory make up 1 word.
 */
std::vector<uint8_t> MEMORY(MEMORY_SIZE, 0x0);

/* Increment by 4 after each instruction fetched */
uint32_t PROGRAM_COUNTER = 0; 

void load_in_memory(uint32_t machinecode) {
    //printf("LOADING: PROGRAM_COUNTER: %x\n", PROGRAM_COUNTER);
    for (int i = 0; i < 4; i++) {
        MEMORY[PROGRAM_COUNTER] = machinecode / 0x1000000;
        machinecode = machinecode << 8;
        PROGRAM_COUNTER++;
        if (PROGRAM_COUNTER > MEMORY_SIZE) {
            std::cout << "*** Out of memory, shutting down ***"
                << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

void execute() { 
    PROGRAM_COUNTER = 0;
    int i;
    uint8_t opcode;
    uint8_t register_t;
    uint8_t register_s;
    uint16_t immediate;
    uint32_t machinecode = 0;
    //Instruction_type_t type;
    while (true) {
        for (i = 0; i < 4; i++) {
            machinecode += MEMORY[PROGRAM_COUNTER + i];
            if (i != 3) {
                machinecode =  machinecode << 8; 
            }

            if (PROGRAM_COUNTER > MEMORY_SIZE) {
                std::cout << "*** Out of memory, shutting down ***"
                    << std::endl;
                std::exit(EXIT_FAILURE);
            } 
        }
        //std::cout << "Execution Program Counter: " << PROGRAM_COUNTER << std::endl;
        //printf("Machine code: %x\n", MEMORY[PROGRAM_COUNTER]);
        opcode = machinecode >> 26;
        //printf("machinecode: %x, opcode: %x, addi: %x\n", machinecode, opcode, ADDI);
        switch (opcode) {
            case ADD: 
                break;

            case ADDU:
                break;

            case ADDI:
                immediate  =  machinecode % 0x10000;
                //printf("immediate: %x\n", immediate);
                register_s = (machinecode & 0x3e00000) >> 21;
                register_t = (machinecode & 0x1f0000)  >> 16;
                REGISTERS[register_t]= REGISTERS[register_s] + immediate;
                break;

            case ADDIU:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case AND:
                std::cout << "Not yet implemented" << std::endl;
                break;
                
            case ANDI:
                immediate  =  machinecode % 0x10000;
                //printf("immediate: %x\n", immediate);
                register_s = (machinecode & 0x3e00000) >> 21;
                register_t = (machinecode & 0x1f0000)  >> 16;
                REGISTERS[register_t]= REGISTERS[register_s] & immediate; 
                break; 

            case DIV:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case DIVU:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case MULT:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case MULTU:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case NOR:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case OR:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case ORI:
                immediate  =  machinecode % 0x10000;
                //printf("immediate: %x\n", immediate);
                register_s = (machinecode & 0x3e00000) >> 21;
                register_t = (machinecode & 0x1f0000)  >> 16;
                REGISTERS[register_t]= REGISTERS[register_s] | immediate; 
                break;

            case SLL:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SLV:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SRA:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SRAV:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SRL:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SRLV:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SUB:
                std::cout << "Not yet implemented" << std::endl;
                break;
                
            case SUBU:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case XOR: 
                std::cout << "Not yet implemented" << std::endl;
                break;

            case XORI:
                immediate  =  machinecode % 0x10000;
                //printf("immediate: %x\n", immediate);
                register_s = (machinecode & 0x3e00000) >> 21;
                register_t = (machinecode & 0x1f0000)  >> 16;
                REGISTERS[register_t]= REGISTERS[register_s] ^ immediate; 
                break;


            case LW:
                immediate  =  machinecode % 0x10000;
                register_s = (machinecode & 0x3e00000) >> 21;
                register_t = (machinecode & 0x1f0000)  >> 16;
                REGISTERS[register_t]= 
                    MEMORY[REGISTERS[register_t] + immediate];
                break;

            case SYSCALL:
                syscall();
                break;
        }
        machinecode = 0;

        /* This is a temporary fix, in the future, this will be 
           implemented case by case */
        PROGRAM_COUNTER += 4;
    } // end while
}

void syscall() {
    //printf("REGISTERS[V0] = %x\n", REGISTERS[V0]);
    switch (REGISTERS[V0]) {
        case 10:
            /* exit */
            std::cout << "*** Program terminated SUCCESSFULLY ***" 
                << std::endl;
            std::exit(EXIT_SUCCESS);
            break;

        case 11:
            /* print character */
            printf("%c", REGISTERS[A0]);
            break;

        default:
            std::cout << "*** Unknown syscall, exiting ***" << std::endl;
            std::exit(EXIT_FAILURE);
            break;
    }
}

void computer_dump() {
}
