#MIPSSIM

(Not yet working, still a work in progress)

Requires a version of g++ capable of gnu++11 standard


This is a simulator for a MIPS processor. 


As of now the only supported syntax is explicitly using the register number, as in 'addi $r1, $r0, 10'


TODO:

    Currently, only unsigned arithmetic is supported, need to support
    signed arithmetic

    Support register names, e.g., $v0 instead of $r2

    Implement J type instructions

