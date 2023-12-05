; The recursive function to print decimal UNsigned value of AL register.
; And simpler function to print out binary value of AL register.

name "printAL"

org 100h

mov al, 254
call print_al       ; unsigned decimal.
call print_nl       ; new line.
call print_al_bin   ; binary (8 bits).

ret




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



; procedure prints the binary value of AL
print_al_bin proc
    pusha
    ; print result in binary:
    mov cx, 8  
    mov bl, al
    p1:    mov ah, 2   ; print function.
           mov dl, '0'
           test bl, 10000000b  ; test first bit.
           jz zero
           mov dl, '1'
    zero:  int 21h
           shl bl, 1
    loop p1
    ; print binary suffix:
    mov dl, 'b'
    int 21h
    ; print carrige return and new line:
    mov dl, 0Dh
    int 21h
    mov dl, 0Ah
    int 21h
    popa
    ret  ; return to the main program.
endp



print_nl proc 
    push ax  
    push dx  
    mov ah, 2
    mov dl, 0Dh
    int 21h  
    mov dl, 0Ah
    int 21h   
    pop dx 
    pop ax      
    ret
endp         