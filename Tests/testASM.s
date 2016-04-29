

; This section prints "enter an int: " to the screen
addi $r2, $r0, 11  ; load 11 into $v0, print char
addi $r4, $r0, 101 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 110 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 116
syscall            ; print to screen
addi $r4, $r0, 101 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 114 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 32  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 97  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 110 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 32  ; load into $a0
syscall            ; print to screen 
addi $r4, $r0, 105 ; load into $a0
syscall            ; print to screen 
addi $r4, $r0, 110 ; load into $a0
syscall            ; print to screen 
addi $r4, $r0, 116 ; load into $a0
syscall            ; print to screen 
addi $r4, $r0, 58  ; load into $a0
syscall            ; print to screen 
addi $r4, $r0, 32  ; load into $a0
syscall            ; print to screen 

; TEST
addi $r2, $r0, 5
syscall             ; read int 
addi $r8, $r2, 0  ; move the user's input int to $t0
; TEST

; This section prints "your int: " to the screen
addi $r2, $r0, 11  ; load 11 into $v0, print char
addi $r4, $r0, 121 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 111 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 117
syscall            ; print to screen
addi $r4, $r0, 114 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 32  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 105  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 110  ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 116 ; load into $a0
syscall            ; print to screen
addi $r4, $r0, 58  ; load into $a0
syscall            ; print to screen 
addi $r4, $r0, 32 ; load into $a0
syscall            ; print to screen 

addi $r4, $r8, 0
addi $r2, $r0, 1  ; load 1 into $v0, print int
syscall 

; Print Newline
addi $r2, $r0, 11  ; load 11 into $v0, print char
addi $r4, $r0, 10  ; load newline char into $a0
syscall            ; print newline to screen 

; Halt
addi $r2, $r0, 10  ; load 10 into $v0
syscall            ; halt program



