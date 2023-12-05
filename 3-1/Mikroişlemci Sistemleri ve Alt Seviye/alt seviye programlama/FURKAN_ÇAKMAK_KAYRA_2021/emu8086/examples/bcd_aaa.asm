; this example shows the use of aaa instruction (ascii adjust after addition).
; it is used to add huge bcd numbers.

name "bcd_aaa"

org     100h

; first number '9':
mov     ah, 09h

; second number '5':
mov     al, 05h

; al = al + ah =
;    = 09h + 05h = 0eh
add     al, ah

; clear tens byte of bcd
; result:
xor     ah, ah

; adjust result to bcd form,
; ah = 1, al = 4  ->  '14'
aaa

; print the result:

; store contents of
; ax register:
mov     dx, ax

; print first digit:
mov     ah, 0eh
; convert to ascii:
or      dh, 30h
mov     al, dh
int     10h

; print second digit:
; convert to ascii:
or      dl, 30h
mov     al, dl
int     10h

; wait for any key press:
mov ah, 0
int 16h

ret  ; return control to operating system.




