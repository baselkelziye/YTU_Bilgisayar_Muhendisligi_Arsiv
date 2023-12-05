name "callfar"

; examples shows how to call int 10h without using int instruction.

org 100h

; set es:bx to point to int 10h vector in interrupt vector table
mov bx, 0h  
mov es, bx
mov bx, 40h
mov ah, 0eh ; set up int 10h params
mov al, '*' 
pushf
call far es:[bx] ; do a far cal to int10h vector


; wait for any key....
mov ah, 0
int 16h


ret



