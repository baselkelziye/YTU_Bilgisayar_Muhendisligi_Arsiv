; Flat Assembler uses the Intel syntax.
; Effective for:
;      Flat assembler version 1.64
;      emu8086 integrated assembler version 4.00-Beta-20 (or above)          
           
#fasm#   ; this code is for FASM.

org 100h   

name "fasmcomp"   
   
 
; === [NOTE 1] 
; calculate the sum of 'a' and 'b'
  
jmp start
  
a dw 5
b dw 7


start:

; this is correct syntax for emu8086 integrated assembler,
; but it is wrong for fasm:
mov ax, a
mov bx, b
add ax, bx    ; AX = offset a + offset b  (AX=206)   (correct, but not what we expect)


; correct syntax for fasm:
mov ax, [a]
mov bx, [b]
add ax, bx    ; AX = 5 + 7   (AX=000C)     (correct)

 
;; to calculate sum of offsets for emu8086 integrated assembler
;; it is required to use the offset directive, for example:
;    mov ax, offset a
;    mov bx, offset b
;    add ax, bx    ; sum of offsets instead of values.             
;; the offset directive is not supported for fasm (error: extra characters on line)
      
        
; Hello, World example in fasm:        
mov dx, msg
mov ah, 9
int 21h  

; for emu8086 integrated assembler:
;    mov dx, offset msg
; or
;    lea dx, msg
; (syntax of the integrated 8086 assembler is mostly MASM/TASM compatible)


; wait for any key...
mov ah, 0
int 16h  
 
ret 

msg db "Hello, World!", 0x0D, 0x0A, "$"
   
; emu8086 compatible declaration is:
; msg: db "Hello, World!", 0x0D, 0x0A, "$"
;  (note: there is ":" after msg)
   
                                 
                                   
; === [NOTE 2]  
; fasm does not support the comment directive, for example:
; comment *
;    la lalala la...
; *      

; === [NOTE 3]     
; these precompiler directives are preparsed by the IDE:
;  NAME
;  #make...
;  #AX=...
;  etc...
          

; === [NOTE 4]  
; for fasm it's required to use "byte" and "word" prefixes
; in places where it may be required to use "byte ptr", "word ptr"
; or "b.", "w." prefixes for the integrated 8086 assembler. 
; For example:
           
           
mov byte [m1], AL           
m1 dw 1234h

;	; for the integrated 8086 assembler it should be:
;	mov b. m1, AL             
;	; or:
;	mov byte ptr m1, AL  ; (MASM compatible)
	               
               
; === [NOTE 5] 
; uninitialised variables are not added to actual binary file
; when these variables are located in the bottom of the file
; and there is no defined data after them (MASM compatible)
; 8086 assembler always initialises variables as 0 (MASM incompatibility)
; For example:

u1 dw ?   


; === [NOTE 6] 
; fasm assembler is case sensitive;
; for example, the following code would cause
; "symbol redefinition" error for MASM or 8086 integrated assembler,
; but it is completely legal for fasm:

mov [d], 9
mov [D], 12
ret
d Dw 5
D dw 7

; === [NOTE 7]   
; there may be other slight syntax incompatibilities,
; if you find any problem feel free to email.
   
