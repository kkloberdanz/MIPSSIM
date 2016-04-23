#include <iostream>
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

    /* Jump type opcode, first 6 bits are opcode, last 26 bits
     * multiplited by 4 gives the memory address to jump to.
     */ 
    uint32_t returnValue = opcode_as_int << 26;
    if (type == J) { 
        std::cout << "J type instructions are not yet supported, exiting"
            << std::endl;
        std::exit(EXIT_FAILURE);
    } else if (type == I) { 
        return returnValue + get_immediate_as_int(line);
    }

}
