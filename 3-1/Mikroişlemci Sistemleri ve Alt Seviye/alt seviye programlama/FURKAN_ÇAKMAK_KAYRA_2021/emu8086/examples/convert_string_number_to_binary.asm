name "str2bin"

; convert string number to binary!

; this program written in 8086 assembly language to
; convert string value to binary form.

; this example is copied with major modifications
; from macro "scan_num" taken from  c:\emu8086\inc\emu8086.inc
;
; the original "scan_num" not only converts the string number
; but also reads the string from the keyboard and supports
; backspace key, this example is a shorten version
; of original "scan_num" macro.

; here we assume that the string number is already given,
; and the string number does not contain non-digit chars
; and it cannot cause buffer overflow (number is in word range
; and/or has only 4 digits).

; negative values are allowed in this example.

; the original "scan_num" does not allow to enter non-digits
; and it also checks for buffer overflow.

; you can the original file with other macro definitions
;  in c:\emu8086\inc\emu8086.inc


org 100h

jmp start

; text data:
msg1 db 0Dh,0Ah, " enter any number from -32768 to 65535 inclusive, or zero to stop: $"
msg2 db 0Dh,0Ah, " binary form: $"

; buffer for int 21h/0ah
; fist byte is buffer size,
; second byte is number of chars actually read (set by int 21h/0ah).
buffer db 7,?, 5 dup (0), 0, 0

; for result:
binary dw ?

start:

; print welcome message:
mov dx, offset msg1
mov ah, 9
int 21h

; input string:
mov dx, offset buffer
mov ah, 0ah
int 21h

; make sure the string is zero terminated:
mov bx, 0
mov bl, buffer[1]
mov buffer[bx+2], 0


lea    si, buffer + 2  ; buffer starts from third byte.
call    tobin

; the number is in cx register.
; for '-1234' it's 0fb2eh

mov binary, cx

jcxz stop

; print pre-result message:
mov dx, offset msg2
mov ah, 9
int 21h

; print result in binary:
mov bx, binary
mov cx, 16
print: mov ah, 2   ; print function.
       mov dl, '0'
       test bx, 1000000000000000b  ; test first bit.
       jz zero
       mov dl, '1'
zero:  int 21h
       shl bx, 1
loop print
; print binary suffix:
mov dl, 'b'
int 21h

jmp start  ; loop

stop:

ret ; return control to the operating system.



; this procedure converts string number to
; binary number. number can have a sign ('-').
; the result is stored in cx register.
; parameters:
; si - address of string number (zero terminated).

tobin   proc    near
        push    dx
        push    ax
        push    si
   
   
jmp process
       
;==== local variables ====      
make_minus      db      ?       ; used as a flag.
ten             dw      10      ; used as multiplier.
;=========================

process:       

        ; reset the accumulator:
        mov     cx, 0

        ; reset flag:
        mov     cs:make_minus, 0

next_digit:

    ; read char to al and
    ; point to next byte:
    mov     al, [si]
    inc    si     

        ; check for end of string:
        cmp     al, 0  ; end of string?
        jne     not_end
        jmp     stop_input       
not_end:

        ; check for minus:
        cmp     al, '-'
        jne     ok_digit
        mov     cs:make_minus, 1 ; set flag!
    jmp     next_digit
   
ok_digit:

        ; multiply cx by 10 (first time the result is zero)
        push    ax
        mov     ax, cx
        mul     cs:ten                  ; dx:ax = ax*10
        mov     cx, ax
        pop     ax

    ; it is assumed that dx is zero - overflow not checked!

        ; convert from ascii code:
        sub     al, 30h

        ; add al to cx:
        mov     ah, 0
        mov     dx, cx      ; backup, in case the result will be too big.
        add     cx, ax
       
        ; add - overflow not checked!

        jmp     next_digit

stop_input:

        ; check flag, if string number had '-'
        ; make sure the result is negative:
        cmp     cs:make_minus, 0
        je      not_minus
        neg     cx
       
not_minus:

        pop     si
        pop     ax
        pop     dx
        ret
tobin        endp

