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
    SLV     = 0x04, // 000100
    SRAV    = 0x07, // 000111
    SRL     = 0x02, // 000010
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
    SLT     = 0x2A,
    SLTU    = 0x2B,

    SYSCALL = 0x0C
};

#endif
