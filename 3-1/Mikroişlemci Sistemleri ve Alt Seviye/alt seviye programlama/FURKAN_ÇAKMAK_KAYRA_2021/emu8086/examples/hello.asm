; "hello, world!" step-by-step char-by-char way...
; this is very similar to what int 21h/9h does behind your eyes.
; instead of $, the string in this example is zero terminated
; (the Microsoft Corporation has selected dollar to terminate the strings for MS-DOS operating system)
 
name "hello"

org     100h   ; compiler directive to make tiny com file.

; execution starts here, jump over the data string:
jmp     start

; data string:
msg db 'Hello, world!', 0

start:

; set the index register:
        mov     si, 0

next_char:

; get current character:
        mov     al, msg[si]
; is it zero?
; if so stop printing:
        cmp     al, 0           
        je      stop

; print character in teletype mode:
        mov     ah, 0eh
        int     10h

; update index register by 1:
        inc     si

; go back to print another char:
        jmp     next_char


stop:  mov ah, 0  ; wait for any key press.
       int 16h

; exit here and return control to operating system...
        ret     

end     ; to stop compiler.

this text is not compiled and is not checked for errors,
because it is after the end directive;
however, syntax highlight still works here.

