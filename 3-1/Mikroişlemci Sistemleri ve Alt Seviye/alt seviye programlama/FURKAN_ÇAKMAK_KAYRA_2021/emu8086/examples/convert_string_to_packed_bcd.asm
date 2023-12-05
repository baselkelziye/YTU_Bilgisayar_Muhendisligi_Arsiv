name "convert"

; this program uses a subroutine written in 8086 assembly language 
; that can be used for converting a string of number 
; (max of 4 ascii digit) to equivalent packed bcd digits.
; bcd is binary coded decimal.

; this program does no screen output.
; to see results click "vars".




org 100h

jmp start

string db '1234'  ; 4 ascii digits.
packed_bcd dw ?   ; two bytes (word) to store 4 digits.

start:

lea bx, string
lea di, packed_bcd
call pack_to_bcd_and_binary

ret ; return to operating system.





; subroutine written in 8086 assembly language 
; that can be used for converting a string of number 
; (max of 4 ascii digit) to equivalent packed
; bcd digits. 
; input parameters:
;    bx - address of source string (4 ascii digits).
; output:
;    di - must be set to address for packed bcd (2 bytes).


pack_to_bcd_and_binary proc near
pusha 

; point to 2 upper digits of packed bcd:
; (assumed that we have 4 digits)
add di, 1

; loop only for 2 because every time we
; read 2 digits (2 x 2 = 4 digits)
mov cx, 2

; reset packed bcd:
mov word ptr [di], 0

	; to convert a char (0..9) to digit we need
	; to subtract 48 (30h) from its ascii code,
	; or just clear the upper nibble of a byte.
	; mask:  00001111b  (0fh)
	
next_digit:	
mov ax, [bx]	; read 2 digits.

and ah, 00001111b
and al, 00001111b

; 8086 and all other Intel's microprocessors store less 
; significant byte at lower address.
 
xchg al, ah		

; move first digit to upper nibble:
shl ah, 4 

; pack bcd:
or ah, al 

; store 2 digits:
mov [di], ah

; next packed bcd:
sub di, 1
; next word (2 digits):
add bx, 2

loop next_digit

popa
ret
pack_to_bcd_and_binary endp





