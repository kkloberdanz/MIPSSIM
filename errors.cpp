#include <iostream>
#include <vector>

#include "Headers/errors.h"
#include "Headers/getters.h"

void report_error(std::string filename, std::string reason) {
    std::cout << "ERROR in file " << filename << " : " << reason << std::endl;
}

void preprocess(std::string & line) {

    /* remove comments */
    unsigned int i;
    for (i = 0; i < line.size(); i++) {
        /* treat ';' and '#' as comments */
        if ((line[i] == ';') || (line[i] == '#')) {
            if (line.size() > 1) {
                line = line.substr(0, i);
            } else {
                line = " ";
            }
        }
    }


    if (line[0] == ' ') {
        while (line[0] == ' ') {
            line = line.substr(1, line.size());
        }
    } else if (line[0] == '\t') { 
        while (line[0] == '\t') {
            line = line.substr(1, line.size());
        }
    } 
} 

bool is_valid_assembly_code(std::string line) {
    // test
    bool set_debug = true;

    std::vector<std::string> valid_opcodes_v = get_valid_opcodes();
    

    /* do not allow blank lines */
    if (line[0] == '\n') {
        return false;
    }

    std::string opcode = get_opcode(line);

    bool is_valid_opcode = false;
    unsigned int i;
    for (i = 0; i < valid_opcodes_v.size(); i++) {
        // check if opcode matches the valid set
        if (opcode == valid_opcodes_v[i]) {
            is_valid_opcode = true;
        }
    } 

    if (set_debug) {
        std::cout << "opcode: " << opcode 
        << ((is_valid_opcode)? " VALID" : " NOT A VALID OPCODE") 
        << std::endl;
    }

    return is_valid_opcode;
}
