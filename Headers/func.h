#ifndef FUNC_H
#define FUNC_H

/* 
 * These functions all have an opcode of 0. The function code 
 * dictates what to do
 */

enum Func { 
    /* Arithmetic and logical instructions */
    ADD     = 0x20, // 100000
    ADDU    = 0x21, // 100001
    AND     = 0x24, // 100100
    DIV     = 0x1A, // 011010
    DIVU    = 0x1B, // 011011
    MULT    = 0x18, // 011000
    MULTU   = 0x19, // 011001
    NOR     = 0x27, // 100111
    OR      = 0x25, // 100101 
    SLL     = 0x00, // 000000
    SRA     = 0x03, // 000011
    SRLV    = 0x06, // 000110
    SUB     = 0x22, // 100010
    SUBU    = 0x23, // 100011
    XOR     = 0x26, // 100110

    /* Jump Instructions */
    JR      = 0x08, // 001000 

    /* Data Movement Instructions */
    MFHI    = 0x10, // 010000
    MFLO    = 0x12, // 010010

    /* Comparison Instructions */
    SLT     = 0x2A, // 101010
    SLTU    = 0x2B, // 101011
    SLTI    = 0x0A, // 001010
    SLTIU   = 0x09, // 001001 

    // TODO: actual encoding '0000 00-- ---- ---- ---- ---- --00 1100'
    /*
     * For the future:
     *  Define opcode ZERO = 0x00
     *  in cpu.cpp, have a case ZERO
     *  Within this case, have another switch for
     *  the function codes, to specify what to do.
     *
     *  Make a file 'Headers/func.h' to contain the different function 
     *  codes.
     */
    SYSCALL = 0x0c
};

#endif
