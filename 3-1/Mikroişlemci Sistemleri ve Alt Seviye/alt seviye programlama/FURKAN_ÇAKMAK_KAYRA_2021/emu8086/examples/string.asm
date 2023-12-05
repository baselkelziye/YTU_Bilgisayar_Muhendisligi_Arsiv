
; this example demonstrates the input and output string functions of emu8086.inc
; this code doesnt depend on MS-DOS or any other operating system's interrupts, therefore
; it can easily be used for developing an operating system or a boot record loader.

name "string"

; this macro prints a string that is given as a parameter, example:
; print 'hello world!'
print   macro   sdat
local   next_char, s_dcl, printed, skip_dcl
push    ax      ; store registers...
push    si      ;
jmp     skip_dcl        ; skip declaration.
        s_dcl db sdat, 0
skip_dcl:
        lea     si, s_dcl
next_char:      
        mov     al, cs:[si]
        cmp     al, 0
        jz      printed
        inc     si
        mov     ah, 0eh ; teletype function.
        int     10h
        jmp     next_char
printed:
pop     si      ; re-store registers...
pop     ax      ;
print   endm


; this macro prints a string that is given as a parameter, example:
; printn 'hello world!'
; the same as print, but new line is automatically added.
printn   macro   sdat
local   next_char, s_dcl, printed, skip_dcl
push    ax      ; store registers...
push    si      ;
jmp     skip_dcl        ; skip declaration.
        s_dcl db sdat, 0Dh, 10, 0
skip_dcl:
        lea     si, s_dcl
next_char:      
        mov     al, cs:[si]
        cmp     al, 0
        jz      printed
        inc     si
        mov     ah, 0eh ; teletype function.
        int     10h
        jmp     next_char
printed:
pop     si      ; re-store registers...
pop     ax      ;
printn   endm


; this macro prints a char in al and advances
; the current cursor position:
putc    macro   char
        push    ax
        mov     al, char
        mov     ah, 0eh
        int     10h     
        pop     ax
putc    endm



org     100h

jmp start  ; skip over the declarations and data




buffer db "empty buffer --- empty buffer"
size = $ - offset buffer  ; declare constant
msg1   db "Enter a string: ", 0


start:
; print a welcome message:
lea     si, msg1
call    print_string

; get string to ds:di
lea     di, buffer      ; buffer offset.
mov     dx, size        ; buffer size.
call    get_string

putc    0Dh
putc    10 ; next line.

; print using macro:
print "You've entered: "

; print string in ds:si using procedure:
mov     si, di
call    print_string

; wait for any key...
mov     ax, 0
int     16h

ret



; get a null terminated string from keyboard,
; write it to buffer at ds:di, maximum buffer size is set in dx.
; 'enter' stops the input.
get_string      proc    near
push    ax
push    cx
push    di
push    dx

mov     cx, 0                   ; char counter.

cmp     dx, 1                   ; buffer too small?
jbe     empty_buffer            ;

dec     dx                      ; reserve space for last zero.


;============================
; eternal loop to get
; and processes key presses:

wait_for_key:

mov     ah, 0                   ; get pressed key.
int     16h

cmp     al, 0Dh                  ; 'return' pressed?
jz      exit


cmp     al, 8                   ; 'backspace' pressed?
jne     add_to_buffer
jcxz    wait_for_key            ; nothing to remove!
dec     cx
dec     di
putc    8                       ; backspace.
putc    ' '                     ; clear position.
putc    8                       ; backspace again.
jmp     wait_for_key

add_to_buffer:

        cmp     cx, dx          ; buffer is full?
        jae     wait_for_key    ; if so wait for 'backspace' or 'return'...

        mov     [di], al
        inc     di
        inc     cx
        
        ; print the key:
        mov     ah, 0eh
        int     10h

jmp     wait_for_key
;============================

exit:

; terminate by null:
mov     [di], 0

empty_buffer:

pop     dx
pop     di
pop     cx
pop     ax
ret
get_string      endp



; print null terminated string at current cursor position,
; raddress of string in ds:si
print_string proc near
push    ax      ; store registers...
push    si      ;

next_char:      
        mov     al, [si]
        cmp     al, 0
        jz      printed
        inc     si
        mov     ah, 0eh ; teletype function.
        int     10h
        jmp     next_char
printed:

pop     si      ; re-store registers...
pop     ax      ;

ret
print_string endp


