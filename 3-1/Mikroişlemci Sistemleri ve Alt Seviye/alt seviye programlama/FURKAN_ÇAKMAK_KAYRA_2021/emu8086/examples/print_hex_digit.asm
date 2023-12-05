; this sample prints out a hex value of DL register.

name "digit"

org 100h

mov dl, 7ch

; load address of data table in bx, for xlat instruction:
lea bx, table  

; xlat does the following:
; al = ds:[bx + unsigned al]

mov al, dl
shr al, 4    ; leave high part only.
xlat         ; get hex digit. 
mov ah, 0eh  ; teletype sub-function.
int 10h


mov al, dl
and al, 0fh  ; leave low part only.
xlat         ; get hex digit.     
mov ah, 0eh  ; teletype sub-function.
int 10h

; wait for any key press:
mov ah, 0
int 16h


ret

table db '0123456789abcdef'
