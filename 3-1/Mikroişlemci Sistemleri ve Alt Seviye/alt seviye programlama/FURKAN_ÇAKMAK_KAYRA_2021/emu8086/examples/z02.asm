; output: exe



.stack 64h

.data

    msg db "Hello, World", 24h

.code

    mov ax, @data
    mov ds, ax
    
    mov dx, offset msg
    mov ah, 9
    int 21h

.exit




