/*
 * Source: http://alumni.cs.ucr.edu/~vladimir/cs161/mips.html
 */
#ifndef OPCODES_H
#define OPCODES_H

#include <cstdint> 

enum Opcodes {

    /* Arithmetic and logical instructions */
    FUNC    = 0x00,
    ADDI    = 0x08, // 001000
    ADDIU   = 0x09, // 001001
    ANDI    = 0x0c, // 001100
    ORI     = 0x0D, // 001101
    XORI    = 0x0E, // 001110

    /* Constant-Manipulating Instructions */
    LHI     = 0x19, // 011001
    LLO     = 0x18, // 011000

    /* Branch Instructions */
    BEQ     = 0x04, // 000100 
    BGTZ    = 0x07, // 000111 
    BLEZ    = 0x06, // 000110 
    BNE     = 0x05, // 000101

    /* Jump Instructions */
    J       = 0x02, // 000010
    JAL     = 0x03, // 000011

    /* Load Instructions */
    LB      = 0x20, // 100000
    LBU     = 0x24, // 100100
    LH      = 0x21, // 100001
    LHU     = 0x25, // 100101
    LW      = 0x23, // 100011

    /* Store Instructions */
    SB      = 0x28, // 101000 
    SH      = 0x29, // 101001 
    SW      = 0x2B, // 101011

    /* Data Movement Instructions */
    MTHI    = 0x11, // 010001
    MTLO    = 0x13, // 010011

    /* Exception and Interrupt Instructions */
    TRAP    = 0x1A, // 011010 
};

#endif
