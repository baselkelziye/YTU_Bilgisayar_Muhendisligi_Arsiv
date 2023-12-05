; this sample shows how to use scasb instruction to find a symbol.

org 100h


jmp start


str1 db 'aaabbbxddd'
s_found db '"yes" - found!', 0Dh,0Ah, '$'
s_not   db '"no" - not found!', 0Dh,0Ah, '$'
find_what equ 'x'


start:
; set forward direction:
    cld

; set counter to string size:
    mov cx, 10

; load string address into es:di
    mov ax, cs
    mov es, ax
    lea di, str1

; we will look for the character in string:
    mov al, find_what

    repne   scasb

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

; di contains the address of searched character:
    dec di  


; wait for any key press...
    mov ah, 0
    int 16h
    
exit_here:
    ret
