#ifndef GLOBALS_H
#define GLOBALS_H

/* initialize registers */
extern std::vector<uint32_t> REGISTERS(32, 0x0); 

/* 
 * Initialize memory 
 *
 * Each section of memory is 8 bits wide. 1 word is 32 bits,
 * so 4 sections of memory make up 1 word.
 */
extern std::vector<uint8_t> MEMORY(1000, 0x0);

/* Increment by 4 after each instruction fetched */
extern uint32_t PROGRAM_COUNTER = 0; 



#endif
