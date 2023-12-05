
; how to use cmpsw instruction to compare word strings.

name "cmpsw"

org     100h

; set forward direction:
        cld     

; load source into ds:si,
; load target into es:di:
        mov     ax, cs
        mov     ds, ax
        mov     es, ax
        lea     si, dat1
        lea     di, dat2

; set counter to data length in words:
        mov     cx, size

; compare until equal:
        repe    cmpsw
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

; data vectors must have equal lengths:
x1:
dat1 dw 1234h, 5678h, 9012h, 3456h
dat2 dw 1234h, 5678h, 9012h, 3456h
size = ($ - x1) / 4


