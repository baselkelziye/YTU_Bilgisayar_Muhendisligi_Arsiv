; this program inputs a decimal number
; and prints out its binary equivalent.

; convertion is done by convert_to_bin procedure,
; all other stuff is just for input/output.


name "ToBin"

org 100h

; skipt data area:
jmp start

; ascii buffer holds 16 bits of binary equivalent:
result db 16 dup('x'), 'b'
msg1 db "supported values from -32768 to 65535", 0Dh,0Ah
     db "enter the number: $"

msg2 db 0Dh,0Ah, "converted to binary: $"



start:
; print the message1:
mov dx, offset msg1
mov ah, 9
int 21h


call scan_num ; get the number to cx.

mov bx, cx

call convert_to_bin ; convert number in bx to result.

; print the message2:
mov dx, offset msg2
mov ah, 9
int 21h


; print the result string backwards:
mov si, offset result  ; set buffer's address to si.
mov ah, 0eh            ; teletype function of bios.
mov cx, 17             ; print 16 bits + suffix 'b'.
print_me:
	mov al, [si]
	int 10h ; print in teletype mode.
	inc si
loop print_me



; wait for any key....
mov ah, 0
int 16h


ret ; return to operating system.





; procedure to convert number in bx to its binary equivalent.
; result is stored in ascii buffer string.
convert_to_bin    proc     near
pusha

lea di, result

; print result in binary:
mov cx, 16
print: mov ah, 2   ; print function.
       mov [di], '0'
       test bx, 1000_0000_0000_0000b  ; test first bit.
       jz zero
       mov [di], '1'
zero:  shl bx, 1
       inc di
loop print

popa
ret
convert_to_bin   endp




; this macro prints a char in al and advances the current cursor position:
putc    macro   char
        push    ax
        mov     al, char
        mov     ah, 0eh
        int     10h     
        pop     ax
endm

; this procedure gets the multi-digit signed number from the keyboard,
; and stores the result in cx register:
scan_num        proc    near
        push    dx
        push    ax
        push    si
        
        mov     cx, 0

        ; reset flag:
        mov     cs:make_minus, 0

next_digit:

        ; get char from keyboard
        ; into al:
        mov     ah, 00h
        int     16h
        ; and print it:
        mov     ah, 0eh
        int     10h

        ; check for minus:
        cmp     al, '-'
        je      set_minus

        ; check for enter key:
        cmp     al, 13  ; carriage return?
        jne     not_cr
        jmp     stop_input
not_cr:


        cmp     al, 8                   ; 'backspace' pressed?
        jne     backspace_checked
        mov     dx, 0                   ; remove last digit by
        mov     ax, cx                  ; division:
        div     cs:ten                  ; ax = dx:ax / 10 (dx-rem).
        mov     cx, ax
        putc    ' '                     ; clear position.
        putc    8                       ; backspace again.
        jmp     next_digit
backspace_checked:


        ; allow only digits:
        cmp     al, '0'
        jae     ok_ae_0
        jmp     remove_not_digit
ok_ae_0:        
        cmp     al, '9'
        jbe     ok_digit
remove_not_digit:       
        putc    8       ; backspace.
        putc    ' '     ; clear last entered not digit.
        putc    8       ; backspace again.        
        jmp     next_digit ; wait for next input.       
ok_digit:


        ; multiply cx by 10 (first time the result is zero)
        push    ax
        mov     ax, cx
        mul     cs:ten                  ; dx:ax = ax*10
        mov     cx, ax
        pop     ax

        ; check if the number is too big
        ; (result should be 16 bits)
        cmp     dx, 0
        jne     too_big

        ; convert from ascii code:
        sub     al, 30h

        ; add al to cx:
        mov     ah, 0
        mov     dx, cx      ; backup, in case the result will be too big.
        add     cx, ax
        jc      too_big2    ; jump if the number is too big.

        jmp     next_digit

set_minus:
        mov     cs:make_minus, 1
        jmp     next_digit

too_big2:
        mov     cx, dx      ; restore the backuped value before add.
        mov     dx, 0       ; dx was zero before backup!
too_big:
        mov     ax, cx
        div     cs:ten  ; reverse last dx:ax = ax*10, make ax = dx:ax / 10
        mov     cx, ax
        putc    8       ; backspace.
        putc    ' '     ; clear last entered digit.
        putc    8       ; backspace again.        
        jmp     next_digit ; wait for enter/backspace.
        
        
stop_input:
        ; check flag:
        cmp     cs:make_minus, 0
        je      not_minus
        neg     cx
not_minus:

        pop     si
        pop     ax
        pop     dx
        ret
make_minus      db      ?       ; used as a flag.
ten             dw      10      ; used as multiplier.
scan_num        endp

