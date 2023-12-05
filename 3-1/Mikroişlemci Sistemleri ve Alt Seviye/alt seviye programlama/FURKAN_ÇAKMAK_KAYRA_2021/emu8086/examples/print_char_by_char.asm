
name "charchar"


org  100h


print_new_line macro
    mov dl, 13
    mov ah, 2
    int 21h   
    mov dl, 10
    mov ah, 2
    int 21h      
endm


    mov dx, offset msg1
    mov ah, 9
    int 21h
    ; input the string:
    mov dx, offset s1
    mov ah, 0ah
    int 21h
    
    ; get actual string size:
    xor cx, cx
    mov cl, s1[1]
    print_new_line
                  
    mov bx, offset s1[2]
print_char:
    mov dl, [bx]
    mov ah, 2
    int 21h      
    print_new_line   
    inc bx
    loop print_char


    ; wait for any key...
    mov ax, 0 
    int 16h
    
    ret


msg1    db  "ENTER THE STRING: $"
s1      db 100,?, 100 dup(' ') 


end
