name "calc-sum"

org 100h ; directive make tiny com file.

; calculate the sum of elements in vector,
; store result in m and print it in binary code.

; number of elements:
mov cx, 5

; al will store the sum:
mov al, 0

; bx is an index:
mov bx, 0

; sum elements:
next: add al, vector[bx]

; next byte:
inc bx

; loop until cx=0:
loop next


; store result in m:  
mov m, al


; print result in binary:
mov bl, m
mov cx, 8
print: mov ah, 2   ; print function.
       mov dl, '0'
       test bl, 10000000b  ; test first bit.
       jz zero
       mov dl, '1'
zero:  int 21h
       shl bl, 1
loop print
; print binary suffix:
mov dl, 'b'
int 21h



mov dl, 0ah ; new line.
int 21h
mov dl, 0dh ; carrige return.
int 21h


; print result in decimal:
mov al, m
call print_al




; wait for any key press:
mov ah, 0
int 16h



ret

; variables:
vector db 5, 4, 5, 2, 1
m db 0


print_al proc
cmp al, 0
jne print_al_r
    push ax
    mov al, '0'
    mov ah, 0eh
    int 10h
    pop ax
    ret 
print_al_r:    
    pusha
    mov ah, 0
    cmp ax, 0
    je pn_done
    mov dl, 10
    div dl    
    call print_al_r
    mov al, ah
    add al, 30h
    mov ah, 0eh
    int 10h    
    jmp pn_done
pn_done:
    popa  
    ret  
endp