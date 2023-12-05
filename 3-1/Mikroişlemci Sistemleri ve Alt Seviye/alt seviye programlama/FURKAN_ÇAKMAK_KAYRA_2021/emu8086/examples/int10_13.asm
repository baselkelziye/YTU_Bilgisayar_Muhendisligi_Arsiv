; this is an example of bios function: int 10h / ah=13h.
; refer to short list of dos interrupts for more info:
; c:\emu8086\documentation\

name "int10h"

org     100h


; set es (just in case):
push    cs
pop     es

mov     bh, 0    ; page.
lea     bp, msg  ; offset.
mov     bl, 0f3h ; default attribute.
mov     cx, 12   ; char number.
mov     dl, 2    ; col.
mov     dh, 1    ; row.
mov     ah, 13h  ; function.
mov     al, 1    ; sub-function.
int     10h

; show current cursor position:
mov     al, '<'  
mov     ah, 0eh
int     10h

mov     bh, 0    ; page.
lea     bp, cmsg ; offset of string with attributes.
mov     bl, 0f3h ; default attribute (not used when al=3).
mov     cx, 12   ; char number.
mov     dl, 2    ; col.
mov     dh, 3    ; row.
mov     ah, 13h  ; function.
mov     al, 3    ; sub-function.
int     10h

; show current cursor position:
mov     al, '<'
mov     ah, 0eh
int     10h

; wait for any key press....
mov     ah, 0
int     16h

ret  ; return control to the operating system.

msg db 'hello world!'

cmsg db 'h', 0cfh, 'e', 8bh, 'l', 0f0h, 'l', 5fh, 'o', 3ch, ' ', 0e0h
     db 'w', 0b3h, 'o', 2eh, 'r', 0cah, 'l', 1ah, 'd', 0ach, '!', 2fh

