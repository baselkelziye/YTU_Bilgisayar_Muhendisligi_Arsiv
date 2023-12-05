; to prevent the MS-DOS window from closing immediately,
; you can have MOV AX,0 / INT 16h as the last instructions 
; in your assembly program before return to the operating system.

name "no-close"

org 100h

mov dx, offset msg
mov ah, 9
int 21h

mov ax, 0         ; wait for any key...
int 16h

ret               ; return to the operating system.


msg db "Hello Windows!   $"
