/*
 * Programmer: Kyle Kloberdanz
 * Date Created: 21 Apr 2016
 *
 * Requirements: A version of g++ capable of gnu++14 standard
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Headers/opcodes.h"
#include "Headers/registers.h"
#include "Headers/errors.h"
#include "Headers/file-handler.h"

/*
 * TODO:
 * (1) translate.cpp 
 *     - assembly to machine code
 *     - Use format type
 *
 * (2) errors.cpp
 *     - decide if valid registers
 */

int main(int argc, char* argv[]) { 

    /* initialize registers */
    std::vector<uint32_t> registers(32, 0x0); 

    /* 
     * Initialize memory 
     *
     * Each section of memory is 8 bits wide. 1 word is 32 bits,
     * so 4 sections of memory make up 1 word.
     */
    std::vector<uint8_t> memory(1000, 0x0);

    /* Increment by 4 after each instruction fetched */
    uint64_t program_counter = 0;

    if (argv[1]) {
        std::string input_file(argv[1]);
        load_from_file(input_file);
    } 

    return 0;
}
