#include <iostream>
#include <fstream>
#include <string>

#include "Headers/file-handler.h"
#include "Headers/opcodes.h"
#include "Headers/errors.h"
#include "Headers/translate.h"
#include "Headers/kernel.h"

void load_from_file(std::string filename) {
    std::ifstream infile(filename);

    std::string line;
    while (std::getline(infile, line)) {
        preprocess(line);
        if (is_valid_assembly_code(line)) {
            // TEST
            //std::cout << line << std::endl; 
            
            // translate to machine code, add to memory
            //printf("%x\n", asm_to_machinecode(line)); 
            std::cout << line << std::endl;
            load_in_memory(asm_to_machinecode(line));
        }
    }

    infile.close();
}
