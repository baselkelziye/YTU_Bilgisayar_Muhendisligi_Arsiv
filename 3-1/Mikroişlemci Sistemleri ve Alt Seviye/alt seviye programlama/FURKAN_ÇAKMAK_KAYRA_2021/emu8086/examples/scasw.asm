; this sample shows how to use scasw instruction to find a word (2 bytes).


org 100h

jmp start

dat1 dw 1234h, 5678h, 9075h, 3456h
find_what equ 9075h
s_found db '"yes" - found!', 0Dh,0Ah, '$'
s_not   db '"no" - not found!', 0Dh,0Ah, '$'

start:
; set forward direction:
    cld

; set counter to data size:
    mov cx, 4

; load string address into es:di
    mov ax, cs
    mov es, ax
    lea di, dat1

; we will look for the word in data string:
    mov ax, find_what

    repne   scasw

    jz  found

not_found:

; "no" - not found!
    mov dx, offset s_not
    mov ah, 9
    int 21h

    jmp exit_here
found:

; "yes" - found!
    mov dx, offset s_found
    mov ah, 9
    int 21h

; di contains the address of searched word:
    dec di  

; wait for any key press...
    mov ah, 0
    int 16h
    

exit_here:
    ret  ; return control to operating system...

