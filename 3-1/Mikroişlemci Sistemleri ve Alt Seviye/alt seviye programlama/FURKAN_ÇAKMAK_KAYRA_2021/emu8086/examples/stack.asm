; this sample shows how the stack works. 
; click 'stack' button in emulator to see the contents of the stack.

; stack is important element in computer architecture.

; this code does nothing useful, except printing "Hi" in the end.

name "stack"

org     100h   ; create tiny com file.

mov     ax, 1234h
push    ax

mov     dx, 5678h
push    dx

pop     bx
pop     cx

; function call pushes ip value of the next instruction:

call    tfunc

mov     ax, 7890h
push    ax
pop     bx

; interrupts are like funtions,
; but in addition they push code segment into the stack
mov     ax, 3
int     10h    ; set standart video mode.

; a typical use of stack is to set segment registers.
; set ds to video memory segment:
mov     ax, 0b800h
push    ax
pop     ds

; print "hi":
mov     [170h], 'H'
mov     [172h], 'i'

; color attribute for 'h'
mov     [171h], 11001110b

; color attribute for 'i'
mov     [173h], 10011110b


; wait for any key press....
mov     ah, 0
int     16h      

; here we "pop" the ip value,
; and return control to the operating system:
ret

; the test procedure:

tfunc   proc

        xor     bx, bx
        xor     cx, cx

; here we "pop" the ip value,
; and return control to the main program:
        ret
endp
