org 100h

mov ax, 0
mov es, ax

mov ax, es:[40h]
mov word_offset, ax

mov ax, es:[40h+2]
mov word_segment, ax

mov ah,0eh ; set up parameters for int 10h
mov al, 1  ; ASCII code of a funny face.

; do same things as int does
pushf
push cs
mov bx, rr
push bx

opcode       db 0EAh   ; jmp word_segment:word_offset
word_offset  dw ?
word_segment dw ?

rr:
mov ax, 1  ; return here

ret


