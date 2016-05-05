#include <cstdint>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "Headers/cpu.h"
#include "Headers/registers.h"
#include "Headers/getters.h"
#include "Headers/opcodes.h"
#include "Headers/func.h"

#define MEMORY_SIZE 32000

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
        if (PROGRAM_COUNTER + i >= MEMORY_SIZE - 1) {
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
    uint8_t register_d;
    uint8_t shift_ammount;
    uint8_t func;
    uint16_t immediate;
    uint32_t jump_target;
    uint32_t machinecode = 0;
    //Instruction_type_t type;
    while (true) {
        for (i = 0; i < 4; i++) {
            machinecode += MEMORY[PROGRAM_COUNTER + i];
            if (i != 3) {
                machinecode =  machinecode << 8; 
            }

            if (PROGRAM_COUNTER >= MEMORY_SIZE - 1) {
                std::cout << "*** Out of memory, shutting down ***"
                    << std::endl;
                std::exit(EXIT_FAILURE);
            } 
        }
        //std::cout << "Execution Program Counter: " << PROGRAM_COUNTER << std::endl;
        //printf("Machine code: %x\n", MEMORY[PROGRAM_COUNTER]);
        //opcode = machinecode >> 26;
        //printf("machinecode: %x, opcode: %x, addi: %x\n", machinecode, opcode, ADDI);

        opcode        = get_opcode_from_machinecode(machinecode);
        register_t    = get_register_t(machinecode);
        register_s    = get_register_s(machinecode);
        register_d    = get_register_d(machinecode);
        shift_ammount = get_shift_amount(machinecode);
        immediate     = get_immediate_from_machinecode(machinecode);
        jump_target   = get_jump_target(machinecode);
        func          = get_function_from_machinecode(machinecode);

        /*
        printf("opcode:        %d\n", opcode);
        printf("register_t :   %d\n", register_t);
        printf("register_s:    %d\n", register_s);
        printf("shift_ammount: %d\n", shift_ammount);
        printf("immediate:     %d\n", immediate);
        printf("jump_target:   %d\n", jump_target);
        printf("func:          %d\n", func);
        puts("");
        */

        switch (opcode) {

            case SYSCALL:
                /* this actually belongs in func, but requires a near 
                 * entire re-write of translate.cpp. This will be done 
                 * at a future date */
                syscall();
                break; 

            /* func dictates what to do, opcode is zero */
            case FUNC: 
                switch (func) {

                    std::cout << "FUNC" << std::endl;
                    case ADD: 
                        // add register_t + register_s, store in register_d
                        REGISTERS[register_d] = REGISTERS[register_s] + REGISTERS[register_t];
                        break;

                    case ADDU:
                        std::cout << "Not yet implemented" << std::endl;
                        break; 

                    case AND:
                        std::cout << "Not yet implemented" << std::endl;
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

                    case SLL:
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

                    default:
                        std::cout << "Not a valid func" << std::endl;
                        std::exit(EXIT_FAILURE);
                        break;
                } // end case FUNC

            case ADDI: 
                REGISTERS[register_t]= REGISTERS[register_s] + immediate;
                break;

            case ADDIU:
                std::cout << "Not yet implemented" << std::endl;
                break; 
                       
            case ANDI:
                REGISTERS[register_t]= REGISTERS[register_s] & immediate; 
                break; 

            case ORI:
                REGISTERS[register_t]= REGISTERS[register_s] | immediate; 
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

            case XORI:
                REGISTERS[register_t]= REGISTERS[register_s] ^ immediate; 
                break; 

            case LW:
                REGISTERS[register_t]= 
                    MEMORY[REGISTERS[register_t] + immediate];
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
        case 1:
            /* print int */
            printf("%d\n", REGISTERS[A0]);
            break;

        case 2:
            /* print float */
            std::cout << 
                "*** Floating point opperations not yet supported" 
            << std::endl;
            break;

        case 3: 
            /* print double */
            std::cout << 
                "*** Floating point opperations not yet supported" 
            << std::endl;
            break;

        case 4:
            /* print string */
            std::cout << 
                "*** String opperations not yet supported" 
            << std::endl;
            break;

        case 5:
            /* read int */
            std::cin >> REGISTERS[V0];
            break;

        case 6: 
            /* print double */
            std::cout << 
                "*** Floating point opperations not yet supported" 
            << std::endl;
            break;

        case 7: 
            /* print double */
            std::cout << 
                "*** Floating point opperations not yet supported" 
            << std::endl;
            break; 

        case 8:
            /* read string */
            std::cout << 
                "*** String opperations not yet supported" 
            << std::endl; 
            break; 

        case 9:
            /* allocate memory */
            std::cout << 
                "*** Memory allocation not yet supported" 
            << std::endl; 
            break;

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

        case 12:
        {
            /* read char */
            char user_input;
            scanf("%c", &user_input);
            REGISTERS[V0] = (uint32_t)user_input;
            break;
        }

        default:
            std::cout << "*** Unknown syscall, exiting ***" << std::endl;
            std::exit(EXIT_FAILURE);
            break;
    }
}

void computer_dump() {
    unsigned int i;
    for (i = 0; i < REGISTERS.size(); i++) {
        printf("Register %d: %x\n", i, REGISTERS[i]);
    } 

    for (i = 0; i < MEMORY.size(); i++) {
        printf("Memory %d: %x\n", i, MEMORY[i]);
    } 
}
