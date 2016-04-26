;addi $r8, $r0, 100 ; load 100 into t0

addi $r2, $r0, 11  ; load 11 into $v0

; This section prints "It works!" to the screen
addi $r4, $r0, 73  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 116 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 32  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 119 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 111 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 114 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 107 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 115 ; load into $a0
syscall            ; print to screen
addi $r4, $r0,  33 ; load into $a0
syscall            ; print to screen

; Print Newline
addi $r4, $r0, 10  ; load newline char into $a0
syscall            ; print newline to screen

; Halt
addi $r2, $r0, 10  ; load 10 into $v0
syscall            ; halt program

;       add $r1, $r2, $r3

;andi $r3, $r4, 9
;ori $r5, $r6, 9

;asdf $r3, $r4, $r5
