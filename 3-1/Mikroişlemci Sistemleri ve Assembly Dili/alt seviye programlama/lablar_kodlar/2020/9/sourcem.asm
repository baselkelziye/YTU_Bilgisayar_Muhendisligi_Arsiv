;;;;WORKING ONE CODEUM;;;;;;;;;
CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
	
DATA    SEGMENT PARA 'DATA'
;WRITE YOUR VARIABLES HERE
freq_var db 60,30,20,15,12
sine db 0,4,8,13,17,22,26,31,35,39,44,48,53,57,61,65,70,74,78,83,87,91,95,99,103,107,111,115,119,123,127,131,135
	db 138,142,146,149,153,156,160,163,167,170,173,177,180,183,186,189,192,195,198,200,203,206,208,211,213,216,218,220,223,225
	db 227,229,231,232,234,236,238,239,241,242,243,245,246,247,248,249,250,251,251,252,253,253,254,254,254,254,254,255
	db 254,254,254,254,254,253,253,252,251,251,250,249,248,247,246,245,243,242,241,239,238,236,234,232,231,229,227,225,223,220,218,216,213,211
	db 208,206,203,200,198,195,192,189,186,183,180,177,173,170,167,163,160,156,153,149,146,142,138,135,131,127,123,119,115,111,107,103,99,95,91,87,83
	db 78,74,70,65,61,57,53,48,44,39,35,31,26,22,17,13,8,4,0
genlik_var db 51,102,153,204,255
DATA    ENDS

STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

START PROC
        MOV AX, DATA
	MOV DS, AX
		
; USE NEAR PROCEDURES FOR REPEATING JOBS LIKE CHECKING 8253 OUT STATUS
; USE SINGLE 7SEG, VALUES AFTER F (15) IS NOT IMPORTANT
; YOU CAN STORE BINARY EQUALIVENT OF VALUES 0-F IN ARRAY FOR 7SEG 

; WRITE INTERRUPT SERVICE ROUTINES HERE
;
;
;;;;;;;;;;;;;;;;;
		xor ax,ax
		mov es,ax
		xor bx,bx
		mov al,80h;tus1 80h
		mov bl,4
		mul bl
		mov bx, ax
		lea ax,  rand_wave
		mov es:[bx], ax
		mov ax,cs
		mov es:[bx+2],ax
		;--------
		add bx,4
		lea ax, si_changer;tus2 81h
		mov es:[bx], ax
		mov ax,cs
		mov es:[bx+2],ax
		
		;-------------
		add bx,4
		lea ax, di_changer
		mov es:[bx], ax ;tus3 82h
		mov ax,cs
		mov es:[bx+2],ax
		
;;;;;;;;;;;;;;;;;;;;;


; WRITE INITIALIZATION INSTRUCTIONS HERE

;-----------------------
;8253 initialization
		mov dx, 0406h
		mov al,	00010110b;mode 3 square wave control word
		out dx,al
		mov dx, 0400h
		mov al, freq_var[si]
		out dx, al
;----------------------
;8259 initialization
mov dx,0200h
mov al, 13h;icw1= edge trigger single ic4 needed
out dx,al

mov al , 80h;icw2=ir0 vector type 
add dx, 2
out dx, al

mov al,1fh ;icw4 = aeoi equals 1
out dx,al

sti
;-------------------------
xor dx,dx; dac 0000h adresinde yer almakta

xor ax,ax
;out dx,al

;;;;
PRIMARY_DATA_LOOP:
JMP PRIMARY_DATA_LOOP
;;;;
	
RET
START ENDP
	
;;;;;;;;;;;;;;;
delay proc near
push cx
xor cx,cx

again:
inc cx
cmp cx,255
jb again
pop cx

ret 
delay endp
;;;;;;;;;;;;;;;;;;;

;**********************************
rand_wave proc far
	
	push ax
	push bx
	push cx
	mov cx, 4
	

	again:
		xor ax,ax
		up_tri:
			out dx ,al
			inc al
			cmp al,genlik_var[di]
			jb up_tri
		
		down_tri:
			out dx, al
			dec al
			cmp al,0
			ja down_tri
			
		saw_teeth:
			out dx,al
			inc al
			cmp al,genlik_var[di]
			jb  saw_teeth
		xor ax, ax
		
		xor bx,bx
		
		square_zero:
		inc bx
		out dx ,al
		cmp bl, genlik_var[di]
		jb square_zero
		
		mov al,genlik_var[di]
		square_one:
		out dx, al
		dec bx
		cmp bx, 0
		ja square_one
		
		
		xor bx,bx	
		sinner:
			mov al,sine[bx]
			inc bx
			out dx,al
			cmp bx,180 
			jb sinner
			
		
						
	loop again
	pop cx
	pop bx 
	pop ax

	iret
rand_wave endp

;************************

;=============================
si_changer proc far
		; frequency changer
	cmp si,4
	jb sonx
	xor si,si
	jmp cikis	
	sonx:
	inc si
	push dx
	cikis:
	;_______________________
	;8253 initialization
		mov dx, 0406h
		mov al,	00010110b	;mode 3 square wave control word
		out dx,al
		mov dx, 0400h
		mov al, freq_var[si]
		out dx, al
	;_______________________
	pop dx
	iret
si_changer endp
;======================================

;--------------------------
di_changer proc far
		;genlik changer
	cmp di,4
	jb sony
	xor di,di
	jmp cikisdi	
	sony:
	inc di
	cikisdi:
		
	iret
di_changer endp

;-------------------------

CODE    ENDS
        END START
;;;;;;;;;;;;;;;;WORKING ONE CODEUM END;;;;;;;;





























;**********************************************
;8253 initialization
;8253 1hzlik output uretsin
;out cisi 8259 un 3 ucuna baglansin

; biri testere biri square biri ucgen dalga olsun
; priority olsun

DATA    SEGMENT PARA 'DATA'
;WRITE YOUR VARIABLES HERE
	freq_var db 60,30,20,15,12
	genlik_var db 51,102,153,204,255
	sine db 0,4,8,13,17,22,26,31,35,39,44,48,53,57,61,65,70,74,78,83,87,91,95,99,103,107,111,115,119,123,127,131,135
	db 138,142,146,149,153,156,160,163,167,170,173,177,180,183,186,189,192,195,198,200,203,206,208,211,213,216,218,220,223,225
	db 227,229,231,232,234,236,238,239,241,242,243,245,246,247,248,249,250,251,251,252,253,253,254,254,254,254,254,255
	db 254,254,254,254,254,253,253,252,251,251,250,249,248,247,246,245,243,242,241,239,238,236,234,232,231,229,227,225,223,220,218,216,213,211
	db 208,206,203,200,198,195,192,189,186,183,180,177,173,170,167,163,160,156,153,149,146,142,138,135,131,127,123,119,115,111,107,103,99,95,91,87,83
	db 78,74,70,65,61,57,53,48,44,39,35,31,26,22,17,13,8,4,0
	
	
DATA    ENDS

STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS
CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
		
		xor es,es
		xor bx,bx
		mov al,80h
		mov ah,4
		mul ah
		mov bx, ax
		lea ax,  rand_wave
		mov es:[bx], ax
		mov es:[bx+2],cs
		;--------
		add bx,4
		lea ax, si_changer
		mov es:[bx], ax
		mov es:[bx+2],cs
		;-------------
		add bx,4
		lea ax, di_changer
		mov es:[bx], ax
		mov es:[bx+2],cs
	
	
	
;--------------------------
di_changer proc far
		;genlik changer
	cmp di,4
	jb sony
	xor di,di
	jmp cikisdi	
	sony:
	inc di
	cikisdi:
		
	iret
di_changer endp

;-------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;
;_______________________
si_changer proc far
		; frequency changer
	cmp si,4
	jb sonx
	xor si,si
	jmp cikis	
	sonx:
	inc si
	cikis:
	;_______________________
	;8253 initialization
		mov dx, 0406h
		mov al,	00010110b	;mode 3 square wave control word
		out dx,al
		mov dx, 0400h
		mov al, freq_var[si]
		out dx, al
	;_______________________			
	iret
si_changer endp
;_______________________
;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;
;**********************************
rand_wave proc far
	
	push ax
	push bx
	push cx
	mov cx, 4
	

	again:
		xor ax,ax
		up_tri:
			out dx ,al
			inc al
			cmp al,genlik_var[di]
			jb up_tri
		
		down_tri:
			out dx, al
			dec al
			cmp al,0
			ja down_tri
			
		saw_teeth:
			out dx,al
			inc al
			cmp al,genlik_var[di]
			jb  saw_teeth
		xor ax, ax
		
		saw_teeth:
			out dx,al
			inc al
			cmp al,genlik_var[di]
			jb  saw_teeth
		xor ax, ax
		
		saw_teeth:
			out dx,al
			inc al
			cmp al,genlik_var[di]
			jb  saw_teeth
		xor ax ,ax
		xor bx,bx
		
		square_zero:
		inc bx
		out dx ,al
		cmp bx, genlik_var[di]
		jb square_zero
		
		mov al,genlik_var[di]
		square_one:
		out dx, al
		dec bx
		cmp bx, 0
		ja square_one
		
		
		xor bx,bx	
		sinner:
			mov al,sine[bx]
			inc bx
			out dx,al
			cmp bx,180 
			jb sinner
			
		
						
	loop again
	pop cx
	pop bx 
	pop ax

	iret
rand_wave endp

;************************


;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	
	
	
START PROC far
        MOV AX, DATA
	MOV DS, AX
	
		xor si,si
		xor di,di
		;8253 initialization
		mov dx, 0406h
		mov al,	00010110b	;mode 3 square wave control word
		out dx,al
		mov dx, 0400h
		mov al, freq_var[si]
		out dx, al
		
		
 
START endp




CODE ends
end START
	;;;;;
	
	
	;sacma kod parcalari
	again:
		xor ax,ax
		up_tri:
			out dx ,al
			inc al
			;call delay
			cmp al,255
			jb up_tri
		
		down_tri:
			out dx, al
			dec al
			;call delay
			cmp al,0
			ja down_tri
			
		saw_teeth:
			out dx,al
			inc al
			;call delay
			cmp al,255
			jb  saw_teeth
		xor ax, ax
		
		saw_teeth2:
			out dx,al
			inc al
			;call delay
			cmp al,255
			jb  saw_teeth2
		xor ax, ax
		
		saw_teeth3:
			out dx,al
			inc al
			;call delay
			cmp al,255
			jb  saw_teeth3
		xor ax ,ax
		xor bx,bx
		
		square_zero:
		inc bx
		out dx ,al
		;call delay
		cmp bx, 255
		jb square_zero
		
		mov al,255
		square_one:
		out dx, al
		dec bx
		;call delay
		cmp bx, 0
		ja square_one



		sinner:
			mov al,sinm[bx]
			inc bx
			out dx,al
			cmp bx,180 
			jb sinner
	xor bx,bx
			;sinner2:
			;out dx,al
			;dec bx
			;mov al,sinm[bx]
			;cmp bx,0h
			;jae sinner2
		sinner2:
			mov al,sinm[bx]
			inc bx
			out dx,al
			cmp bx,180 
			jb sinner2
xor bx,bx
		sinner3:
			mov al,sinm[bx]
			inc bx
			out dx,al
			cmp bx,180 
			jb sinner3


						
	loop again
	
	
	;sacmalik ends