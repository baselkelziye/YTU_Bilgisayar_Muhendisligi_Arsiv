name "far2"

; the correct use of far call for defined procedures.



org    100h

jmp start
off_print_me dw ?
seg_print_me dw ?

start:
mov off_print_me, printme
mov seg_print_me, seg printme
call far off_print_me
db 'hello', 0

mov ah, 0
int 16h

ret



;*******************************
printme proc far
mov     cs:origSI, si  ; protect SI register.
mov     cs:origDS, ds  ; protect DS register.
pop     si             ; get return address (IP).
pop     ds             ; get return segment.
push    ax             ; store ax register.
next_char:
       mov     al, ds:[si]
       inc     si            ; next byte.
       cmp     al, 0
       jz      printed
       mov     ah, 0eh       ; teletype function.
       int     10h
       jmp     next_char     ; loop.
printed:
pop     ax                   ; re-store ax register.
push    ds                   ; ds:si should point to next command after the call instruction and string definition.
mov     ds, cs:origDS        ; re-store ds register.
push    si                   ; save new return address into the stack.
mov     si, cs:origSI        ; re-store si register.
retf
; variables to store the original value of SI and DS registers:
origSI  dw  ?
origDS  dw ?
endp
;*******************************

