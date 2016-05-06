addiu $r8, $r0, 21
addiu $r9, $r0, -54

add  $r4, $r8, $r9

; print integer
addi $r2, $r0, 1  ; load 1 into $v0, print int
syscall 

; Print Newline
addi $r2, $r0, 11  ; load 11 into $v0, print char
addi $r4, $r0, 10  ; load newline char into $a0
syscall            ; print newline to screen 

addi $r8, $r0, -100
addi $r9, $r0, 54

sub  $r4, $r8, $r9

; print integer
addi $r2, $r0, 1  ; load 1 into $v0, print int
syscall 

; Print Newline
addi $r2, $r0, 11  ; load 11 into $v0, print char
addi $r4, $r0, 10  ; load newline char into $a0
syscall            ; print newline to screen 


; Halt
addi $r2, $r0, 10  ; load 10 into $v0
syscall            ; halt program



