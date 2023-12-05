; this sample prints 16x16 color map,
; it uses all possible colors.

name "colors"

org     100h   


; set video mode:
; text mode. 80x25. 16 colors. 8 pages.
mov     ax, 3
int     10h

; blinking disabled for compatibility with dos,
; emulator and windows prompt do not blink anyway.
mov     ax, 1003h
mov     bx, 0      ; disable blinking.
int     10h


               
mov     dl, 0   ; current column.
mov     dh, 0   ; current row.

mov     bl, 0   ; current attributes.

jmp     next_char

next_row:
inc     dh
cmp     dh, 16
je      stop_print
mov     dl, 0

next_char:

; set cursor position at (dl,dh):
mov     ah, 02h
int     10h

mov     al, 'a'
mov     bh, 0
mov     cx, 1
mov     ah, 09h
int     10h

inc     bl      ; next attributes.

inc     dl
cmp     dl, 16
je      next_row
jmp     next_char

stop_print:

; set cursor position at (dl,dh):
mov     dl, 10  ; column.
mov     dh, 5   ; row.
mov     ah, 02h
int     10h

; test of teletype output,
; it uses color attributes
; at current cursor position:
mov     al, 'x'
mov     ah, 0eh
int     10h


; wait for any key press:
mov ah, 0
int 16h


ret
