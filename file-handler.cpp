#include <iostream>
#include <fstream>
#include <string>

#include "Headers/file-handler.h"
#include "Headers/opcodes.h"
#include "Headers/errors.h"
#include "Headers/translate.h"

void load_from_file(std::string filename) {
    std::ifstream infile(filename);

    std::string line;
    while (std::getline(infile, line)) {
        preprocess(line);
        if (is_valid_assembly_code(line)) {
            // TEST
            //std::cout << line << std::endl; 
            
            // translate to machine code, add to memory
            asm_to_machinecode(line);
        }
    }

    infile.close();
}