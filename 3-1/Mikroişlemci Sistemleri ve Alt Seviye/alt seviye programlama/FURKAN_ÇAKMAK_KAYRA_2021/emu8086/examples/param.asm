; this sample prints out the command line parameters.
; in dos you simply add this line after the executable,
; for example:

; param p1 p2 p3

; in emulator it is possible to set parameters
; by selecting "set command line paramters" from the "file" menu.


name "param"


org     100h

jmp start

buffer db 30 dup (' ')
msg db 'no command line parameters!', 0Dh,0Ah, '$'


start:
mov     si, 80h       ; cmd parameters offset.


; copy command line to our buffer:
xor     cx, cx          ; zero cx register.
mov     cl, [si]        ; get command line size.

lea     di, buffer      ; load buffer address to di.

cmp     cx, 0           ; cx = 0 ?
jz      no_param        ; then skip the copy.

inc     si              ; copy from second byte.
next_char:
mov     al, [si]
mov     [di], al
inc     si
inc     di
loop    next_char

; set '$' sign in the end of the buffer:
mov     byte ptr [di], '$'

; print out the buffer:
lea     dx, buffer
mov     ah, 09h
int     21h

jmp     exit    ; skip error message.

no_param:
; print out the error message:
lea     dx, msg
mov     ah, 09h
int     21h



exit:
; wait for any key....
mov     ah, 0
int     16h

ret ; return control to the operating system.


