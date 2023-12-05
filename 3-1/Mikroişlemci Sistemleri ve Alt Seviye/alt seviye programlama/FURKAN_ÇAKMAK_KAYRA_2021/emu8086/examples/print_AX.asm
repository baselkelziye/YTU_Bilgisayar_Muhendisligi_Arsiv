; The recursive function to print UNsigned value of AX register.
; And simpler function to print out binary value of the AX register.

name "printAX"

org 100h

mov ax, 12345  
call print_ax     ; unsigned decimal.
call print_nl     ; new line. 
call print_ax_bin ; binary (16 bit).
    

; wait for any key...
mov ah, 1
int 21h    
    
    
ret


   
print_ax proc
cmp ax, 0
jne print_ax_r
    push ax
    mov al, '0'
    mov ah, 0eh
    int 10h
    pop ax
    ret 
print_ax_r:
    pusha
    mov dx, 0
    cmp ax, 0
    je pn_done
    mov bx, 10
    div bx    
    call print_ax_r
    mov ax, dx
    add al, 30h
    mov ah, 0eh
    int 10h    
    jmp pn_done
pn_done:
    popa  
    ret  
endp


print_ax_bin proc  
    pusha
    ; print result value in binary:
    mov cx, 16
    mov bx, ax
    print: mov ah, 2   ; print function.
           mov dl, '0'
           test bx, 1000000000000000b  ; test first bit.
           jz zero
           mov dl, '1'
    zero:  int 21h
           shl bx, 1
    loop print      
    ; print binary suffix:
    mov dl, 'b'
    int 21h  
    popa  
    ret
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