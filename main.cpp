/*
 * Programmer: Kyle Kloberdanz
 * Date Created: 21 Apr 2016
 *
 * Requirements: A version of g++ capable of gnu++14 standard
 */
#include <iostream>
#include <cstdlib>
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

void print_help() {
    std::cout << "mips-sim: Usage: ./mips-sim FILENAME.s" << std::endl;
}

int main(int argc, char* argv[]) { 

    if (argv[1]) {
        std::string input_file(argv[1]);
        load_from_file(input_file);
    } else {
        print_help();
        std::exit(EXIT_SUCCESS);
    }

    return 0;
}
