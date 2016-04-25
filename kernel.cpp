#include <cstdint>
#include <vector>

#include "Headers/globals.h"
#include "Headers/kernel.h"
#include "Headers/registers.h"
#include "Headers/getters.h"

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
