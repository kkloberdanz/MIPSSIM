/*
 * Programmer: Kyle Kloberdanz
 * Description:
 *
 * Defines which index each register can be found in the 
 * registers vector
 *
 * Does not include floating point registers. Floating point opperations
 * may be supported in the future.
 *
 * 32 registers total
 */

/*
 * Source: 
 * https://msdn.microsoft.com/en-us/subscriptions/ms253512%28v=vs.80%29.aspx
 */

#ifndef REGISTERS_H
#define REGISTERS_H 

enum Registers {
    /* register names and their aliases */ 
    ZERO    = 0, // this register is always zero
    AT      = 1, // Assembler temporary, function result register

    V0      = 2, 
    V1      = 3,
    A0      = 4,

    A1      = 5,
    A2      = 6,
    A3      = 7,

    T0      = 8,  // temporary registers.
    T1      = 9,
    T2      = 10,
    T3      = 11,
    T4      = 12,
    T5      = 13,
    T6      = 14,
    T7      = 15,
    T8      = 24,
    T9      = 25,

    S0      = 16, // saved registers
    S1      = 17,
    S2      = 18,
    S3      = 19,
    S4      = 20,
    S5      = 21,
    S6      = 22,
    S7      = 23,
    S8      = 30,

    K0      = 26, // reserved for kernel and exception return
    K1      = 27,

    GP      = 28, // global pointer

    SP      = 29, // stack pointer

    RA      = 31, // return address
};

#endif
