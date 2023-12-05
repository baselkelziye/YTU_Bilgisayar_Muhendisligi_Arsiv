name "hex-bin"

org 100h

; load binary value:
; (hex: 5h)
mov al, 00000101b

; load hex value:
mov bl, 0ah

; load octal value:
; (hex: 8h)
mov cl, 10o

; 5 + 10 = 15 (0fh)
add al, bl

; 15 - 8 = 7
sub al, cl




; print result in binary:
mov bl, al
mov cx, 8
print: mov ah, 2   ; print function.
       mov dl, '0'
       test bl, 10000000b  ; test first bit.
       jz zero
       mov dl, '1'
zero:  int 21h
       shl bl, 1
loop print
; print binary suffix:
mov dl, 'b'
int 21h


; wait for any key press:
mov ah, 0
int 16h

ret




