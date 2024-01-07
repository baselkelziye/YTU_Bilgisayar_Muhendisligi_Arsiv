;timer mod 2 de ayarlanmali 
;timer ctr0 a clock girisi 10hz olmali
; out cikisi her 1 saymada 1 olmali ki  10 hz frekans olsun

;8255 port a si input olmali 
;8255 pA0 i 1 ile test edilmeli
;pA0 = 1 ise read adc olmali
;===!!!! a3 a8 bitlerini handle etmemiz gerektigi soylenmemis!!!!!=====
; cozumu hepsini 0 yazip or gateye sokmak


;--------------
;8255 settings
mov dx, 0006h
mov al, 10010000b; cw value
out dx,al
;8255 settings end
;---------------

;-------------
;8253 timer settings
mov dx, 0206h
mov al, 00010100b;cw value 
out dx, al
;8253 timer settings end
;-------------


;-------------
;adc settings
; adc has no cw
; uses 1byte space in i/o space
;adc settings end
;-------------


;---------------
;dac settings
;dac has no cw
;dac uses 1byte space in i/o space
;dac settings end
;--------------

; program flow

mov cx, 3
count3sc:

mov al,1;timer divisor
mov dx, 0200h ; ctr 0 address
out dx, al
push cx
mov cx,10
hz_10:
;read 8255 
xor dx, dx
in al, dx ;read from portA 
pA0:
test al, 01h ; test portA-0 if timer pulse
jnz pA0; read again wait for timer out_0 to be 0

;adc read opr.
mov al, 00h; mp makes nonsense write oper.
mov dx , 0200h
; read intr of adc
mov dx, 0400h
wait_intr:
in al , dx
test al , 01h
jnz wait_intr

mov samples[si], al
inc si
loop hz_10

pop cx

loop count3sc
 
 
 
 
 ;==============================================
 ;==============================================
 ;============================================== 
 ;==============================================
 CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
	samples db 30 dup(88)
DATA    ENDS


START PROC far
        MOV AX, DATA
	MOV DS, AX
	
ENDLESS:

	CALL _ADDRESSCHECK

        ;JMP ENDLESS

	


;***************************************************
;timer mod 2 de ayarlanmali 
;timer ctr0 a clock girisi 10hz olmali
; out cikisi her 1 saymada 1 olmali ki  10 hz frekans olsun

;8255 port a si input olmali 
;8255 pA0 i 1 ile test edilmeli
;pA0 = 1 ise read adc olmali
;===!!!! a3 a8 bitlerini handle etmemiz gerektigi soylenmemis!!!!!=====
; cozumu hepsini 0 yazip or gateye sokmak


;--------------
;8255 settings
mov dx, 0006h
mov al, 10010000b; cw value
out dx,al
mov dx, 0000h
in al ,dx
;8255 settings end
;---------------

;-------------
;8253 timer settings
mov dx, 0806h
mov al, 00110100b;cw value 
out dx, al
mov al,01h;timer divisor
			mov dx, 0800h ; ctr 0 address
			out dx, al
xor al, al
out dx, al
xor ah,ah
;8253 timer settings end
;-------------


;-------------
;adc settings
; adc has no cw

; uses 1byte space in i/o space
;adc settings end
;-------------


;---------------
;dac settings
;dac has no cw
;dac uses 1byte space in i/o space
;dac settings end
;--------------

; program flow
	
	mov cx, 3
	count3sc:

		
		push cx
		mov cx,10
		hz_10:
			;read 8255 
			mov dx, 0000h
			pA0:
			in al, 00h ;read from portA 
			
			test al, 01h ; test portA-0 if timer pulse
			jnz pA0; read again

			;adc read opr.
			mov al, 0fbh; mp makes nonsense write oper.
			mov dx , 0200h
			out dx, al
			; read intr of adc
			mov dx, 0400h
			wait_intr:
			in al , dx
			test al , 10h
			jnz wait_intr
			;data is ready
			mov dx, 0200h
			in al , dx

			mov samples[si], al
			inc si
			loop hz_10

		pop cx

		loop count3sc
	 

;***************************************************
	RET
START ENDP

_ADDRESSCHECK PROC NEAR 
        MOV AL,  00H
	MOV DX, 10030H
	OUT DX, AL
RET
_ADDRESSCHECK ENDP

	
CODE    ENDS
        END START
 ;==============================================
 ;==============================================
 ;==============================================
 ;==============================================
