; mouse test

name "mouse"

org 100h

print macro x, y, attrib, sdat
LOCAL   s_dcl, skip_dcl, s_dcl_end
    pusha
    mov dx, cs
    mov es, dx
    mov ah, 13h
    mov al, 1
    mov bh, 0
    mov bl, attrib
    mov cx, offset s_dcl_end - offset s_dcl
    mov dl, x
    mov dh, y
    mov bp, offset s_dcl
    int 10h
    popa
    jmp skip_dcl
    s_dcl DB sdat
    s_dcl_end DB 0
    skip_dcl:    
endm

clear_screen macro
    pusha
    mov ax, 0600h
    mov bh, 0000_1111b
    mov cx, 0
    mov dh, 24
    mov dl, 79
    int 10h
    popa
endm

print_space macro num
    pusha
    mov ah, 9
    mov al, ' '
    mov bl, 0000_1111b
    mov cx, num
    int 10h
    popa
endm


jmp start

curX dw 0
curY dw 0
curB dw 0


start:
mov ax, 1003h ; disable blinking.  
mov bx, 0        
int 10h

; hide text cursor:
mov ch, 32
mov ah, 1
int 10h


; reset mouse and get its status:
mov ax, 0
int 33h
cmp ax, 0
jne ok
print 1,1,0010_1111b, " mouse not found :-( "
jmp stop

ok:
clear_screen

print 7,7,0010_1011b," note: in the emulator you may need to press and hold mouse buttons "
print 7,8,0010_1011b," because mouse interrupts are not processed in real time.           "
print 7,9,0010_1011b," for a real test, click external->run from the menu.                "
print 10,11,0010_1111b," click/hold both buttons to exit... "

; display mouse cursor:
mov ax, 1
int 33h

check_mouse_buttons:
mov ax, 3
int 33h
cmp bx, 3  ; both buttons
je  hide
cmp cx, curX
jne print_xy
cmp dx, curY
jne print_xy
cmp bx, curB
jne print_buttons


print_xy:
print 0,0,0000_1111b,"x="
mov ax, cx
call print_ax
print_space 4
print 0,1,0000_1111b,"y="
mov ax, dx
call print_ax
print_space 4
mov curX, cx
mov curY, dx
jmp check_mouse_buttons

print_buttons:
print 0,2,0000_1111b,"btn="
mov ax, bx
call print_ax
print_space 4
mov curB, bx
jmp check_mouse_buttons



hide:
mov ax, 2  ; hide mouse cursor.
int 33h

clear_screen

print 1,1,1010_0000b," hardware must be free!      free the mice! "

stop:
; show box-shaped blinking text cursor:
mov ah, 1
mov ch, 0
mov cl, 8
int 10h

print 4,7,0000_1010b," press any key.... "
mov ah, 0
int 16h

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
