
; this is a program in 8086 assembly language that
; accepts a character string from the keyboard and
; stores it in the string array. the program then converts 
; all the lower case characters of the string to upper case. 
; if the string is empty (null), it doesn't do anything.

name "upper"

org 100h


jmp start


; first byte is buffer size,
; second byte will hold number
; of used bytes for string,
; all other bytes are for characters:
string db 20, 22 dup('?')

new_line db 0Dh,0Ah, '$'  ; new line code.

start:

; int 21h / ah=0ah - input of a string to ds:dx, 
; fist byte is buffer size, second byte is number 
; of chars actually read. does not add '$' in the
; end of string. to print using int 21h / ah=09h
; you must set dollar sign at the end of it and 
; start printing from address ds:dx + 2.

lea dx, string

mov ah, 0ah
int 21h

mov bx, dx
mov ah, 0
mov al, ds:[bx+1]
add bx, ax ; point to end of string.

mov byte ptr [bx+2], '$' ; put dollar to the end.

; int 21h / ah=09h - output of a string at ds:dx.
; string must be terminated by '$' sign.
lea dx, new_line
mov ah, 09h
int 21h


lea bx, string

mov ch, 0
mov cl, [bx+1] ; get string size.

jcxz null ; is string is empty?

add bx, 2 ; skip control chars.

upper_case:

; check if it's a lower case letter:
cmp byte ptr [bx], 'a'
jb ok
cmp byte ptr [bx], 'z'
ja ok

; convert to uppercase:

; upper case letter do not have
; third bit set, for example:
; 'a'             : 01100001b
; 'a'             : 01000001b
; upper case mask : 11011111b

; clear third bit:
and byte ptr [bx], 11011111b

ok:
inc bx ; next char.
loop upper_case


; int 21h / ah=09h - output of a string at ds:dx.
; string must be terminated by '$' sign.
lea dx, string+2
mov ah, 09h
int 21h
 
; wait for any key press....
mov ah, 0
int 16h 
 
 
null:
ret  ; return to operating system.
 
 
 
 