#include <cstdint>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>

#include <stdio.h>

#include "Headers/cpu.h"
#include "Headers/registers.h"
#include "Headers/getters.h"
#include "Headers/opcodes.h"
#include "Headers/func.h"

#define MEMORY_SIZE 32000

/* initialize registers */
std::vector<int32_t> REGISTERS(32, 0x0); 

/* special registers, non-addressable */
int32_t              HI = 0;
int32_t              LO = 0;

/* 
 * Initialize memory 
 *
 * Each section of memory is 8 bits wide. 1 word is 32 bits,
 * so 4 sections of memory make up 1 word.
 */
std::vector<int8_t> MEMORY(MEMORY_SIZE, 0x0);

/* Increment by 4 after each instruction fetched */
int32_t PROGRAM_COUNTER = 0; 

void load_in_memory(int32_t machinecode) {
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
    int8_t opcode;
    int8_t register_t;
    int8_t register_s;
    int8_t register_d;
    int8_t shift_ammount;
    int8_t func;
    int16_t immediate;
    int32_t jump_target;
    int32_t machinecode = 0;
    //Instruction_type_t type;
    while (true) { 

        assert(REGISTERS[ZERO] == 0);

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
        printf("register_t:   %d\n", register_t);
        printf("register_s:    %d\n", register_s);
        printf("register_d:    %d\n", register_d);
        printf("shift_ammount: %d\n", shift_ammount); printf("immediate:     %d\n", immediate);
        printf("jump_target:   %d\n", jump_target);
        printf("func:          %d\n", func);
        puts("");
        */

        switch (opcode) {

            /* func dictates what to do, opcode is zero */
            case FUNC: 

                /* Register instructions */
                switch (func) {

                    case SYSCALL:
                        syscall();
                        break; 

                    case ADD: 
                        // add register_t, register_s, store in register_d
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] + REGISTERS[register_t];
                        break;

                    case ADDU:
                        std::cout << "Not yet implemented" << std::endl;
                        //REGISTERS[register_d] = 
                            //(uint32_t)(REGISTERS[register_s] + REGISTERS[register_t]);
                        break; 

                    case AND:
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] & REGISTERS[register_t];
                        break;
 
                    case DIV:
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] / REGISTERS[register_t];
                        break; 

                    case DIVU:
                        REGISTERS[register_d] = 
                            (uint32_t)(REGISTERS[register_s] / REGISTERS[register_t]);
                        break;

                    case MULT:
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] * REGISTERS[register_t];
                        break;

                    case MULTU:
                        REGISTERS[register_d] = 
                            (uint32_t)(REGISTERS[register_s] * REGISTERS[register_t]);
                        break;

                    case NOR:
                        REGISTERS[register_d] = 
                            ~(REGISTERS[register_s] | 
                              REGISTERS[register_t]);
                        break;

                    case OR:
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] | REGISTERS[register_t];
                        break;

                    case SLL:
                        /* Shift left logical, and NOOP (shifting zero does nothing) */
                        REGISTERS[register_d] = 
                            REGISTERS[register_t] << shift_ammount;
                        break;

                    case SRLV:
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] >> REGISTERS[register_t];
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

                    case SLV:
                        std::cout << "Not yet implemented" << std::endl;
                        break; 

                    case SUB:
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] - REGISTERS[register_t];
                        break;
                        
                    case SUBU:
                        std::cout << "Not yet implemented" << std::endl;
                        break;

                    case XOR: 
                        REGISTERS[register_d] = 
                            REGISTERS[register_s] ^ REGISTERS[register_t];
                        break; 

                    case JR:
                        std::cout << "Not yet implemented" << std::endl;
                        break; 

                    case MFHI:
                        REGISTERS[register_d] = HI;
                        break;

                    case MFLO: 
                        REGISTERS[register_d] = LO;
                        break;

                    default:
                        std::cout << "Not a valid func" << std::endl;
                        std::exit(EXIT_FAILURE);
                        break;
                } // end case FUNC
                break;

            /* Immediate instructions */
            case ADDI: 
                //printf("register_s = %d, immediate = %d, sum = %d\n", REGISTERS[register_s], immediate, immediate + REGISTERS[register_s]);
                REGISTERS[register_t]= REGISTERS[register_s] + immediate;
                break;

            case ADDIU:
                REGISTERS[register_t] = (uint32_t)(REGISTERS[register_s] + immediate);
                break; 
                       
            case ANDI:
                REGISTERS[register_t]= REGISTERS[register_s] & immediate; 
                break; 

            case ORI:
                REGISTERS[register_t]= REGISTERS[register_s] | immediate; 
                break; 

            case XORI:
                REGISTERS[register_t]= REGISTERS[register_s] ^ immediate; 
                break; 

            case LHI:
                {
                /* load immediate << 16 into reg_d */
                int32_t tmp = immediate;
                REGISTERS[register_t] &= 0x0000FFFF; // zero out first 16 bits
                REGISTERS[register_t] |= tmp << 16; // set first 16 bits to tmp
                break;
                }

            case LLO:
                REGISTERS[register_t] &= 0xFFFF0000; // zero out lower 16 bits
                REGISTERS[register_t] |= immediate;  // set lower 16 bits to tmp
                break;

            case BEQ:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case BLEZ:
                std::cout << "Not yet implemented" << std::endl;
                break; 

            case BNE:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case J:
                PROGRAM_COUNTER = jump_target << 2;
                break;

            case JAL:
                REGISTERS[RA] = PROGRAM_COUNTER;
                PROGRAM_COUNTER = jump_target << 2;
                break;

            case LB:
                std::cout << "Not yet implemented" << std::endl;
                break; 

            case LBU:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case LH:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case LHU:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case LW:
                REGISTERS[register_t]= 
                    MEMORY[REGISTERS[register_t] + immediate];
                break; 

            case SB:
                std::cout << "Not yet implemented" << std::endl;
                MEMORY[register_s + immediate] = register_t;
                break;

            case SH:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case SW:
            { 
                size_t i;
                for (i = 0; i < 4; i++) { 
                    MEMORY[register_s + immediate] = register_t / 0x1000000; 
                    register_t = register_t << 8;
                }

                break; 
            }

            case MTHI:
                std::cout << "Not yet implemented" << std::endl;
                break;

            case MTLO:
                std::cout << "Not yet implemented" << std::endl;
                break; 

            case TRAP:
                std::cout << "Not yet implemented" << std::endl;
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
            printf("%d", REGISTERS[A0]);
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
            REGISTERS[V0] = (int32_t)user_input;
            break;
        }

        default:
            printf("*** Unknown syscall, '%d' exiting ***\n", 
                    REGISTERS[V0]);
            computer_dump();
            std::exit(EXIT_FAILURE);
            break;
    }
}

void computer_dump() {
    unsigned int i;
    for (i = 0; i < REGISTERS.size(); i++) {
        printf("Register %2d: %d\n", i, REGISTERS[i]);
    } 
    puts("");

    /*
    for (i = 0; i < MEMORY.size(); i++) {
        printf("Memory %d: %x\n", i, MEMORY[i]);
    } 
    */
}
