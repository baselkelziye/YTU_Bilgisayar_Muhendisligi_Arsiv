name "huge"

; this example shows how to add huge unpacked bcd numbers.

; this allows to over come the 16 bit and even 32 bit limitation.
; because 32 digit decimal value holds over 100 bits!
; with some effort the number of digits can be increased.

org     100h

; skip data:
jmp     code

; the number of digits in numbers:
; it's important to reserve 0 as most significant digit, to avoid overflow.
; so if you need to operate with 250 digit values, you need to declare len = 251
len     equ     32

; every decimal digit is stored in a separate byte.

; first number is: 423454612361234512344535179521
num1    db      0,0,4,2,3,4,5,4,6,1,2,3,6,1,2,3,4,5,1,2,3,4,4,5,3,5,1,7,9,5,2,1
; second number is: 712378847771981123513137882498
num2    db      0,0,7,1,2,3,7,8,8,4,7,7,7,1,9,8,1,1,2,3,5,1,3,1,3,7,8,8,2,4,9,8

; we will calculate this:

; sum = num1 + num2

; 423454612361234512344535179521 + 712378847771981123513137882498 =
;              = 1135833460133215635857673062019

sum     db      len dup(0) ; declare array to keep the result.

; you may check the result on paper, or click Start , then Run, then type "calc" and hit enter key.

code:   nop ; entry point (nop does nothing, it's nope).

; digit pointer:
xor     bx, bx

; setup the loop:
mov     cx, len 
mov 	bx, len-1  ; point to lest significant digit!
        
next_digit:

        ; add digits:
        mov     al, num1[bx]
        adc     al, num2[bx]
        
        ; this is a very useful instruction that
        ; adjusts the value of addition
        ; to be string compatible
        aaa
        
        ; aaa stands for ascii add adjust.
        ; --- algorithm behind aaa ---
        ; if low nibble of al > 9 or af = 1 then:
	;     al = al + 6 
	;     ah = ah + 1 
	;     af = 1 
	;     cf = 1 
	; else
	;     af = 0 
        ;     cf = 0 
        ;
        ; in both cases: clear the high nibble of al.         
        ; --- end of aaa logic ---
        
        ; store result:
        mov     sum[bx], al
        
        ; point to next digit:
        dec     bx
        
        loop    next_digit

; include carry in result (if any):
adc     sum[bx], 0


; print out the result:
mov     cx, len

; start printing from most significant digit:
mov     bx, 0

print_d:
        mov     al, sum[bx]
        ; convert to ascii char:
        or      al, 30h

        mov     ah, 0eh
        int     10h
        
        inc     bx
        
        loop    print_d

; wait for any key press:
mov ah, 0
int 16h

ret  ; stop

                                                  
                                                  
                                                  

