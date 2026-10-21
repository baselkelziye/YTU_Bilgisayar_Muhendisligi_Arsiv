;0208H data olarak alınır son 4 biti 1000 oldugundan 
;020AH kontrol olarak alınır son 4 biti 1010 oldugundan
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
AD          DB 0H, 0H, 0H, 0H, 0H   ;KENDI ISMINI YAZMALISN
TMP	       DB  0H, 0H, 0H, 0H, 0H, 0H, 0H, 0H, 0H, 0H	;okuma ve yazma icin dizi
N      	DW 0H
DATA    ENDS

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
START:
;BU KISIM INITIALZITION
;Kuralı var ilk once mode insturction yapilir sonra control registerdan reset
;Sonra mod insturction ardından kontrol register islemi yapilir 
    MOV AX, DATA
	MOV DS, AX
	MOV DX, 020Ah      ;MODE INSTUCTION
	MOV AL, 01001101B ;Mode instruction tablosundan bakılmalı
	OUT DX, AL   
	MOV AL, 40H ;Kontrol registerı tablosundan bakilmali Reset islemi yapildi
	OUT DX, AL
	MOV AL, 01001101B ;Mod instruction tablosundan bakilmali
	OUT DX, AL
	MOV AL, 00010101B ;Kontrol register tablosundan bakilmali 
	OUT DX, AL

ENDLESS:

;Reading the number and writing it
	MOV DX, 020AH ;C = 1 Kontrol
TEKRAR:
	IN AL, DX
	AND AL, 02H    ;Status
	JZ TEKRAR


	MOV DX, 0208H   ;C=0 Data
	IN AL, DX	
	SHR AL,1
	XOR BX,BX ;BX'in high kısmı temizlenir
	MOV BL,AL   ;BL gecici olarak tutulur
	MOV N, BX  ;N icinde yedekleme islemi

        SUB N,30H   ;VIRTUAL TERMINALDEN ASCII DEGER ALINIR BURADA ISE ASCII DEGERI CIKARTILIP, SAYI DEGER BULUNUR

	MOV DX, 020AH  ;C = 1 Kontrol
TEKRAR2:
	IN AL, DX  ;Status 
	AND AL, 01H  ;Transmit ready 
	JZ TEKRAR2  

	MOV DX, 0208H  ;C=0 Data
	MOV AL,BL
	OUT DX, AL	   
	

  ;Reading the char array and writing it with loop
  MOV CX,N
  XOR DI,DI
OKUMA:		 
    MOV DX, 020AH  ;C = 1 Kontrol
REP1:
	IN AL, DX   ;Status
	AND AL, 02H ;Receive ready?
	JZ REP1

    MOV DX, 0208H ;C=0 Data
	IN AL, DX	
	SHR AL,1
	MOV TMP[DI], AL  
	INC DI
LOOP OKUMA  


	 MOV CX,N   
	 XOR DI,DI
YAZMA: 
	 MOV DX, 020AH   ;C = 1 Kontrol
REP2:
	IN AL, DX  ;Status okuma islemi
	AND AL, 01H  ;Transmit ready 
	JZ REP2  
	
	MOV DX, 0208H  ;C=0 Data
	MOV AL,TMP[DI]
	INC DI
	OUT DX, AL	  
LOOP YAZMA 


;Ekleme islemleri
	 MOV DI,  N 	;indis
	 MOV CX, 5 	;BURAYA ISMININ UZUNLUGUNU GIRMELISIN
	 SUB CX,  N 	;Cevrim sayisi algoritmasi LAST labelından baslar

LAST: 
	 MOV DX, 020AH ;C = 1 Kontrol
REP3:
	IN AL, DX  ;Status 
	AND AL, 01H  ;Transmit ready 
	JZ REP3 
	
	 MOV DX, 0208H	;C=0 Data
	 MOV AL,AD[DI]
	 INC DI
	 OUT DX,AL
LOOP LAST	 

;SPACE yazdırma
	MOV DX, 020AH ;C = 1 Kontrol
REP4:
	IN AL, DX  
	AND AL, 01H  
	JZ REP4
	MOV DX,0208H ;C=0 Data
	MOV AL,20H ;Bosluk karakteri
	OUT DX,AL
	 
		
        JMP ENDLESS
CODE    ENDS
        END START