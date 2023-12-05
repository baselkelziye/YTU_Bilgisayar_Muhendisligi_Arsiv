; Count number of key presses. the result is in bx register.
;
; You must type into the emulator's screen,
; if it closes, press screen button to re-open it.

name "keycount"

org  100h 

; print welcome message:
mov dx, offset msg
mov ah, 9
int 21h

xor bx, bx ; zero bx register.   

wait:  mov ah, 0   ; wait for any key....
       int 16h

       cmp al, 27  ; if key is 'esc' then exit.
       je stop

       mov ah, 0eh ; print it.
       int 10h

       inc bx ; increase bx on every key press.

       jmp wait


; print result message:
stop:  mov dx, offset msg2
       mov ah, 9
       int 21h

mov ax, bx
call print_ax

; wait for any key press:
mov ah, 0
int 16h

ret ; exit to operating system.

msg db "I'll count all your keypresses. press 'Esc' to stop...", 0Dh,0Ah, "$"
msg2 db 0Dh,0Ah, "recorded keypresses: $" 




   
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

