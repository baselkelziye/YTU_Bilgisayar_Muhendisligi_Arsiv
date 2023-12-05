; a tiny example of multi segment executable file.
; data is stored in a separate segment, segment registers must be set correctly.

name "testexe"

data segment
    msg  db "hello, world!", 0dh,0ah, '$'
ends

stack segment
    db 30 dup(0)
ends

code segment
start:
 ; set segment registers:
        mov     ax, data
        mov     ds, ax
        mov     es, ax

 ; print "hello, world!":
        lea     dx, msg
        mov     ah, 09h
        int     21h

 ; wait for any key...
        mov     ah, 0
        int     16h

 ; return control to os:
        mov     ah, 4ch
        int     21h
ends
        end start  ; set entry point and stop the assembler.
        
        
