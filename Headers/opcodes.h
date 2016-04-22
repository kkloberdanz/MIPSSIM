/*
 * Source: http://alumni.cs.ucr.edu/~vladimir/cs161/mips.html
 */
#ifndef OPCODES_H
#define OPCODES_H

#include <cstdint> 

uint8_t get_opcode_as_int(std::string);

enum Opcodes {

    /* Arithmetic and logical instructions */
    ADD     = 0x20, // 100000
    ADDU    = 0x21, // 100001
    ADDI    = 0x08, // 001000
    ADDIU   = 0x09, // 001001
    AND     = 0x24, // 100100
    ANDI    = 0x0c, // 001100
    DIV     = 0x1A, // 011010
    DIVU    = 0x1B, // 011011
    MULT    = 0x18, // 011000
    MULTU   = 0x19, // 011001
    NOR     = 0x27, // 100111
    OR      = 0x25, // 100101
    ORI     = 0x0D, // 001101
    SLL     = 0x00, // 000000
    SLV     = 0x04, // 000100
    SRA     = 0x03, // 000011
    SRAV    = 0x07, // 000111
    SRL     = 0x02, // 000010
    SRLV    = 0x06, // 000110
    SUB     = 0x22, // 100010
    SUBU    = 0x23, // 100011
    XOR     = 0x26, // 100110
    XORI    = 0x0E, // 001110

    /* Constant-Manipulating Instructions */
    LHI     = 0x19, // 011001
    LLO     = 0x18, // 011000

    /* Comparison Instructions */
    SLT     = 0x2A, // 101010
    SLTU    = 0x2B, // 101011
    SLTI    = 0x0A, // 001010
    SLTIU   = 0x09, // 001001

    /* Branch Instructions */
    BEQ     = 0x04, // 000100 
    BGTZ    = 0x07, // 000111 
    BLEZ    = 0x06, // 000110 
    BNE     = 0x05, // 000101

    /* Jump Instructions */
    J       = 0x02, // 000010
    JAL     = 0x03, // 000011
    JALR    = 0x03, // 001001
    JR      = 0x08, // 001000

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
    MFHI    = 0x10, // 010000
    MFLO    = 0x12, // 010010
    MTHI    = 0x11, // 010001
    MTLO    = 0x13, // 010011

    /* Exception and Interrupt Instructions */
    TRAP    = 0x1A  // 011010 
};

#endif