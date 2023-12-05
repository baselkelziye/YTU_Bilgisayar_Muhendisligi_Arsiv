; 8086 subroutine to encrypt/decrypt lower case characters using xlat

name "crypt"

org 100h


jmp start

; string has '$' in the end:
string1 db 'hello world!', 0Dh,0Ah, '$'


;                       'abcdefghijklmnopqrstvuwxyz'

table1 db 97 dup (' '), 'klmnxyzabcopqrstvuwdefghij'

table2 db 97 dup (' '), 'hijtuvwxyzabcdklmnoprqsefg'


start:

; encrypt:
lea bx, table1
lea si, string1
call parse

; show result:
lea dx, string1
; output of a string at ds:dx
mov ah, 09
int 21h



; decrypt:
lea bx, table2
lea si, string1
call parse

; show result:
lea dx, string1
; output of a string at ds:dx
mov ah, 09
int 21h

; wait for any key...
mov ah, 0
int 16h


ret   ; exit to operating system.




; subroutine to encrypt/decrypt
; parameters: 
;             si - address of string to encrypt
;             bx - table to use.
parse proc near

next_char:
	cmp [si], '$'      ; end of string?
	je end_of_string
	
	mov al, [si]
	cmp al, 'a'
	jb  skip
	cmp al, 'z'
	ja  skip	
	; xlat algorithm: al = ds:[bx + unsigned al] 
	xlatb     ; encrypt using table2.  
	mov [si], al
skip:
	inc si	
	jmp next_char

end_of_string:


ret
parse endp



end
