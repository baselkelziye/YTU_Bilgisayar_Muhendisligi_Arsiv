

; how to use cmpsb instruction to compare byte strings.

name "cmpsb"


org     100h

; set forward direction:
        cld     

; load source into ds:si,
; load target into es:di:
        mov     ax, cs
        mov     ds, ax
        mov     es, ax
        lea     si, str1
        lea     di, str2

; set counter to string length:
        mov     cx, size

; compare until equal:
        repe    cmpsb
        jnz     not_equal

; "yes" - equal!
        mov     al, 'y'
        mov     ah, 0eh
        int     10h

        jmp     exit_here

not_equal:

; "no" - not equal!
        mov     al, 'n'
        mov     ah, 0eh
        int     10h

exit_here:

	; wait for any key press:
	mov ah, 0
	int 16h

        ret

; strings must have equal lengths:
x1:
str1 db 'test string'
str2 db 'test string'
size = ($ - x1) / 2




