; this is an example of aas instruction, 
; it is used to subtract huge bcd numbers (binary coded decimals).

name "bcd_aas"

org	100h

; make 5 - 8
; al = 0fdh (not in binary coded decimal form)
mov	al, 05h
mov	bl, 08h
sub	al, bl


; convert to binary coded decimal,
; al = 7
; and 1 is borrowed from ah, like calculating 15 - 8:
aas

; convert to printable symbol:
or	al, 30h

; print char in al using bios teletype function:
mov	ah, 0eh
int	10h


; wait for any key press:
mov ah, 0
int 16h


ret  ; return control to operating system.

