/*
 * Programmer: Kyle Kloberdanz
 * Date Created: 21 Apr 2016
 *
 * Requirements: A version of g++ capable of gnu++11 standard
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include <stdio.h>
#include <string.h>

#include "Headers/opcodes.h"
#include "Headers/registers.h"
#include "Headers/errors.h"
#include "Headers/kernel.h"
#include "Headers/file-handler.h"

void print_help() {
    std::cout << "mips-sim:\n"
                 "Usage: ./mips-sim FILENAME.s\n"
                 "  --show "
                 "      show assembly as it is loaded into memory\n" 
                 "  --help "
                 "      show this menu\n" 
    << std::endl;
}

int main(int argc, char* argv[]) { 
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    std::cout << "Warning -- Not tested for windows!" << std::endl;
#endif

    // show the assembly being loaded into memory
    bool show = false;

    int i;
    for (i = 1; i < argc; i++) { 
        if ( strcmp(argv[i], "--help") == 0) {
            print_help();
            std::exit(EXIT_SUCCESS);

        } else if ( strcmp(argv[i], "--show") == 0) {
            show = true;
        }
    }

    if (argv[1]) {
        std::string input_file(argv[1]);
        std::cout << "*** Loading from file: '" << argv[1] << "' ***" 
            << std::endl;
        load_from_file(input_file, show);
    } else {
        print_help();
        std::exit(EXIT_SUCCESS);
    }

    std::cout << "*** Running program ***" << std::endl;
    execute(); 

    return 0;
}
