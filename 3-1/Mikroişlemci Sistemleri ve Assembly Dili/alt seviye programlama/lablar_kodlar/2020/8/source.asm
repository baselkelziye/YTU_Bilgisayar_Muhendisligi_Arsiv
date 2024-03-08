;*************WORKING ONE*****************

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
	
DATA    SEGMENT PARA 'DATA'
;WRITE YOUR VARIABLES HERE
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
;



; WRITE INITIALIZATION INSTRUCTIONS HERE
; 
; 
; 	
;******************************
;-----------------------------
;memory uzayinin
;256. gozune interrupt 
;adresini yerlestiren
;code parcasi
;yani 40h tipinde
;interrupt ureten code parcasi

xor ax,ax
mov es,ax
mov al,4h
mov ah,40h
mul ah
mov bx, ax
lea ax, sayint
mov es:[bx],ax
mov ax,cs
mov es:[bx+2],ax

;________________________________


; 8254 ctnr initializations
; c1,c2,c3 => mod-3

mov al, 16h;cw value
mov dx, 1e06h
out dx, al 
mov al, 60;cnt value
mov dx, 1e00h
out dx , al
;c1 is set to count back from 60
;________

mov dx, 1e06h;cw address
mov al , 56h;cw calue
out dx, al
mov al, 15; count value
mov dx, 1e02h
out dx , al
;c2 is set to count back from4

;___________

mov dx, 1e06h;cw address
mov al, 96h;cw value
out dx, al
mov al, 60; count value
mov dx, 1e04h
out dx , al
;c3 is set to count back from 4
;--------------------


mov dx, 1000h

MOV AL, 13H
OUT dx, AL
MOV AL, 40H
add dx, 2
OUT dx, AL
MOV AL, 03H
OUT dx, AL
STI
XOR AX, AX
;xor bx,bx ;for validation



PRIMARY_DATA_LOOP:
;YOUR CODE SHOULD BE LOOPING HERE AFTER INITIALIZATION
JMP PRIMARY_DATA_LOOP


	
RET
START ENDP


;----------------------
;ax degerini 1 arttiran 
;interrput
sayint proc far
inc ax
;inc bx ; for validation
iret
sayint endp
 	
;------------------------
	
CODE    ENDS
        END START

;****************WORKING ONE ENDP-***********





;------------CALISMIYOR OLABILIR------------------
CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
	
DATA    SEGMENT PARA 'DATA'
;WRITE YOUR VARIABLES HERE
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

xor ax,ax
mov es,ax
mov al,4
mov ah,40
mul ah
mov bx, ax
lea ax, sayint
mov es:[bx],ax
mov ax,cs
mov es:[bx+2],ax
;
;
;
; WRITE INITIALIZATION INSTRUCTIONS HERE
; 
; 
;
;----------------------
sayint proc far
inc ax

iret
sayint endp


 	
;------------------------
; 8254 ctnr initializations
; c1,c2,c3 => mod-3

mov al, 16h
mov dx, 1e06h
out dx, al 
mov al, 60
mov dx, 1e000h
out dx , al
;c1 is set to count back from 60
;________

mov dx, 1e06h;cw address
mov al , 56h
out dx, al
mov al, 15
mov dx, 1e002h
out dx , al
;c2 is set to count back from4

;___________

mov dx, 1e06h;cw address
mov al, 96h
out dx, al

mov al, 4
mov dx, 1e004h
out dx , al

;--------------------








PRIMARY_DATA_LOOP:
;YOUR CODE SHOULD BE LOOPING HERE AFTER INITIALIZATION
JMP PRIMARY_DATA_LOOP


	
RET
START ENDP
	
CODE    ENDS
        END START
		
		
		
		
;--------------------------------
		
xor ax,ax
mov es,ax
;mov al,4h
;mov ah,40h
;mul ah
mov ax, 08h
mov bx, ax
lea ax, sayint
mov es:[bx],ax
mov ax,cs
mov es:[bx+2],ax
;;--------------


mov bx, ax
mov temp, ax
 mov al, data[bx]
out al, dx

dizim db 0ffh, 0f9h, 0a4h, 0b0h, 099h, 092h, 082h, 0f8h,080h , 090h 
 
 
 
		
		;====================================================
		;***********WORKING ONE *******************
		CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
	
DATA    SEGMENT PARA 'DATA'
;WRITE YOUR VARIABLES HERE
temp dw 0000h
dizim db 11000000b, 0f9h, 0a4h, 0b0h, 099h, 092h, 082h, 0f8h,080h , 090h,10001000b,10000011b,11000110b,10100001b,10000110b,10001110b
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
;



; WRITE INITIALIZATION INSTRUCTIONS HERE
; 



;--------------------------------
; burada  tip2 kesme adresine kodu gomuyoruz
xor ax,ax
mov es,ax
;mov al,4h
;mov ah,40h
;mul ah
mov ax, 08h
mov bx, ax
lea ax, sayint
mov es:[bx],ax
mov ax,cs
mov es:[bx+2],ax
;;--------------


; 
; 	
;******************************
;-----------------------------
;memory uzayinin
;256. gozune interrupt 
;adresini yerlestiren
;code parcasi
;yani 40h tipinde
;interrupt ureten code parcasi

xor ax,ax
mov es,ax
mov al,4h
mov ah,40h
mul ah
mov bx, ax
lea ax, sayint
mov es:[bx],ax
mov ax,cs
mov es:[bx+2],ax

;________________________________


; 8254 ctnr initializations
; c1,c2,c3 => mod-3

mov al, 16h;cw value
mov dx, 1e06h
out dx, al 
mov al, 60;cnt value
mov dx, 1e00h
out dx , al
;c1 is set to count back from 60
;________

mov dx, 1e06h;cw address
mov al , 56h;cw calue
out dx, al
mov al, 15; count value
mov dx, 1e02h
out dx , al
;c2 is set to count back from4

;___________

mov dx, 1e06h;cw address
mov al, 96h;cw value
out dx, al
mov al, 60; count value
mov dx, 1e04h
out dx , al
;c3 is set to count back from 4
;--------------------


mov dx, 1000h

mov al, 13h;icw1 =>00010011 ic4 needed  single edge trigger
OUT dx, AL
mov al, 40h;icw2 => vector address
add dx, 2
OUT dx, AL
MOV AL, 03H;icw4 =>00000011 pm=1 aeoi = 1
OUT dx, AL
STI
XOR AX, AX
xor bx,bx ;for validation
;-------------------------


;;;;;;;;;;;;;;;;;;;;
;8255 initializations

mov dx, 0006h
mov al, 80h
out DX , al
mov dx, 0000h
XOR AX,AX

BASLA:
PRIMARY_DATA_LOOP:
;YOUR CODE SHOULD BE LOOPING HERE AFTER INITIALIZATION

;mov al, 0ffh
;out 00h , al
;jmp BASLA


;cmp ax, 10
;jae mod_al

mov bx, ax
mov temp, ax
;xor ax ,ax
 mov al, dizim[bx]
out dx,al
mov ax, temp
jmp BASLA




;mod_al:
;mov cx, 10
;div cx
;mov al,ah
;ja mod_al

JMP PRIMARY_DATA_LOOP


	
RET
START ENDP


;----------------------
;ax degerini 1 arttiran 
;interrput
sayint proc far
inc ax
;mov temp,ax
;inc bx ; for validation
cmp ax, 16
jb son1
push cx
mov cl,16
div cl
mov al, ah
pop cx 

son1:
iret
sayint endp

 	
;------------------------
	
CODE    ENDS
        END START
		;________________________________