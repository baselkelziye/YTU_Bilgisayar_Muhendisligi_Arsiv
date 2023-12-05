; a short program to check how
; set and get pixel color works

name "pixel"

org  100h

mov ah, 0   ; set display mode function.
mov al, 13h ; mode 13h = 320x200 pixels, 256 colors.
int 10h     ; set it!

mov cx, 10  ; column
mov dx, 20  ; row
mov al, 15  ; white
mov ah, 0ch ; put pixel
int 10h

xor al, al  ; al = 0

mov cx, 10  ; column
mov dx, 20  ; row
mov ah, 0dh ; get pixel
int 10h

; pause the screen for dos compatibility:

;wait for keypress
  mov ah,00
  int 16h			

; return to text mode:
  mov ah,00 ; set display mode function.
  mov al,03 ; normal text mode 3
  int 10h   ; set it!


ret

