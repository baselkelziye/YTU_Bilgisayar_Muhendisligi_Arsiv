name "faradv"

org  100h	; set location counter to 100h


jmp start

adr_a dw  offset a
seg_a dw  ?

adr_c dw  offset c
seg_c dw  ?

; set segments, requred because we don't know where
; the program will be loaded by the operating system
start:
mov ax, cs
mov seg_a, ax
mov seg_c, ax

call far adr_a
call b
call far adr_c

mov ax, offset d
call ax           

ret  ; return to os.

;--------------------------------------------------
a proc
	mov ax, 1
	retf      ; far return, pop ip and cs.
a endp
;--------------------------------------------------
b proc
	add ax, 2
	ret       ; return, pop ip only.
b endp
;-------------------------------------------------
c proc
	add ax, 3
	retf      ; far return, pop ip and cs.
c endp
;-------------------------------------------------
d proc
	add ax, 4
	ret       ; return, pop ip only.
d endp
;-------------------------------------------------


; note: assembler automatically replaces ret (C3) with retf (CB)
;       if proc has far label, for example:
;       c proc far
;          ....
