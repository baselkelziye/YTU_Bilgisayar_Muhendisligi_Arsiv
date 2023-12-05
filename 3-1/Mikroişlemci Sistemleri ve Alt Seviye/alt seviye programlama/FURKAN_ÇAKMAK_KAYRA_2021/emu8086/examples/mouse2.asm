; mouse drawing.
; press left mouse button to draw.

; for a real test click external->run from the emulator's menu.

name "mouse2"

org 100h

jmp start

oldX dw -1
oldY dw 0


start:
mov ah, 00
mov al, 13h       ; set screen to 256 colors, 320x200 pixels. 
int 10h

; reset mouse and get its status:
mov ax, 0
int 33h
cmp ax, 0
; display mouse cursor:
;mov ax, 1
;int 33h



check_mouse_button:
mov ax, 3
int 33h
shr cx, 1       ; x/2 - in this mode the value of CX is doubled.
cmp bx, 1
jne xor_cursor:
mov al, 1010b   ; pixel color
jmp draw_pixel
xor_cursor:
cmp oldX, -1
je not_required
push cx
push dx
mov cx, oldX
mov dx, oldY
mov ah, 0dh     ; get pixel.
int 10h
xor al, 1111b   ; pixel color
mov ah, 0ch     ; set pixel
int 10h
pop dx
pop cx
not_required:
mov ah, 0dh     ; get pixel.
int 10h
xor al, 1111b   ; pixel color
mov oldX, cx
mov oldY, dx
draw_pixel:
mov ah, 0ch     ; set pixel
int 10h
check_esc_key:
mov dl, 255
mov ah, 6
int 21h
cmp al, 27      ; esc?
jne check_mouse_button


stop:
;mov ax, 2  ; hide mouse cursor.
;int 33h
mov ax, 3 ; back to text mode: 80x25
int 10h
; show box-shaped blinking text cursor:
mov ah, 1
mov ch, 0
mov cl, 8
int 10h
mov dx, offset msg
mov ah, 9
int 21h
mov ah, 0
int 16h
ret

msg db " press any key....     $"

