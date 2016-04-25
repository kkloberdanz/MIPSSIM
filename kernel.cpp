#include <cstdint>
#include <vector>

#include "Headers/kernel.h"
#include "Headers/registers.h"
#include "Headers/getters.h"

/* initialize registers */
std::vector<uint32_t> REGISTERS(32, 0x0); 

/* 
 * Initialize memory 
 *
 * Each section of memory is 8 bits wide. 1 word is 32 bits,
 * so 4 sections of memory make up 1 word.
 */
std::vector<uint8_t> MEMORY(1000, 0x0);

/* Increment by 4 after each instruction fetched */
uint32_t PROGRAM_COUNTER = 0; 

void load_in_memory(uint32_t machinecode) {
    MEMORY[PROGRAM_COUNTER] = machinecode;
    PROGRAM_COUNTER++;
}

void execute() { 
    PROGRAM_COUNTER = 0;
    uint8_t opcode;
    Instruction_type_t type;
    while (true) {
        uint32_t machinecode = MEMORY[PROGRAM_COUNTER];
        //type = get_type(machinecode);
        opcode = machinecode / 0x1000000; 
    }
}

void syscall() {
}

void computer_dump() {
}
