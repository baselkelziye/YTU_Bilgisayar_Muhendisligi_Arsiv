mydata segment para 'data'
   kenar1 dw 4
   kenar2 dw 4
   kenar3 dw 4
   sonuc dw ? 
ends

mystack segment para stack 'stack'
    dw   20  dup(?)
ends 

mycode segment para 'code'
    assume cs:mycode,ss:mystack,ds:mydata
MAIN proc far
    push ds
    xor ax,ax
    push ax
    mov ax,mydata
    mov ds,ax 
    mov ax,kenar1
    mov bx,kenar2
    cmp ax,bx
    mov bx,kenar3  
    jnz false1
    cmp ax,bx
    jnz ikizKenar
    mov ax,1
    mov sonuc,ax
    jmp bitis
false1:cmp ax,bx
    jnz cesitkenar 
    jmp ikizkenar
cesitkenar:mov ax,3
    mov sonuc,ax
    jmp bitis
ikizkenar:mov ax,2
    mov sonuc,ax
bitis: 
    retf
endp
ends
    end MAIN

    
    