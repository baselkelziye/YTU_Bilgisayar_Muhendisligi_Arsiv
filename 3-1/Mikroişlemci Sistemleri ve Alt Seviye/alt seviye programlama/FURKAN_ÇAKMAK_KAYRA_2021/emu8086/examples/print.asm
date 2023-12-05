; this example shows how to print string.
; the string is defined just after the call instruction.
; this example does not use emu8086.inc library.

name "print"

org    100h

; set these values to registers for no particular reason,
; we just want to check that the procedure does not destroy them.
mov si, 1234h
mov ax, 9876h

; 0Dh,0Ah - is the code
;          for standard new
;          line characters:
;   0Dh - carriage return.
;   0Ah - new line.

call printme
db 'hello', 0

; gets here after print:
mov    cx, 1    

call   printme
db ' world!', 0Dh,0Ah, 0

; gets here after print:
mov    cx, 2

call   printme
       db 'hi there!', 0Ah
       db "what's up?", 0Dh,0Ah
       db 'printing!', 0

; printme returns here:
xor    cx, cx

call   printme
       db 0xd,0xa,"press any key...", 0


; wat for any key....
mov ah, 0
int 16h


ret    ; return to os.

;*******************************
; this procedure prints a null terminated
; string at current cursor position.
; the zero terminated string should
; be defined just after
; the call. for example:
;
; call printme
; db 'hello world!', 0
;
; address of string is stored in the
; stack as return address.
; procedure updates value in the
; stack to make return
; after string definition.

printme:

mov     cs:temp1, si  ; protect si register.

pop     si            ; get return address (ip).

push    ax            ; store ax register.

next_char:      
        mov     al, cs:[si]
        inc     si            ; next byte.
        cmp     al, 0
        jz      printed        
        mov     ah, 0eh       ; teletype function.
        int     10h
        jmp     next_char     ; loop.
printed:

pop     ax            ; re-store ax register.

; si should point to next command after
; the call instruction and string definition:
push    si            ; save new return address into the stack.

mov     si, cs:temp1  ; re-store si register.

ret
; variable to store original
; value of si register.
temp1  dw  ?    
;*******************************
