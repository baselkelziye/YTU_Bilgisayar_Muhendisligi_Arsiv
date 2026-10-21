STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
DIZI  DB 41H, 4CH, 41H, 52H, 41H
COUNTER DB 00H
DATA    ENDS

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
	
START:

        MOV AX, DATA
	MOV DS, AX
	
	MOV DX, 020Ah
	MOV AL, 01001101B  
	;1 bit, parite yok, 8 bit, baud rate factor 1
	OUT DX, AL
	
	MOV AL, 40H ;internal reset kontrol yazmacı
	OUT DX, AL
	
	MOV AL, 01001101B ;resetten sonra yine mod belirlenir
	OUT DX, AL
	
	MOV AL, 00010101B ;hem transmitter hem de receiver enable kontrol yazmacı
	OUT DX, AL
	
ENDLESS:
	
	XOR CX, CX
	XOR SI, SI
	MOV DX, 020AH
	
RECEIVE1: 

	  IN AL, DX
	  AND AL, 02H ;RxRDY kontrolü
	  JZ RECEIVE1
	  
	  MOV DX, 0208H
	  IN AL, DX
	  SHR AL, 1 ;bunu yapmazsak karakterler yanlış görünüyor
	   
	   MOV BL, AL ;sayıyı ekrana yansıtmak için kenara aldık
	   
	   MOV CL, AL ;döngü değişkeni
	    ;rakam kontrolü
	   CMP CL, 31H 
	   JL ENDLESS
	   
	   CMP CL, 34H
	   JA ENDLESS
	   
	   ;eğer her şey yolundaysa o zaman bu değerle işlem yapabiliriz 
	   
	   AND CL, 0FH ;ascii koduyla alıyoruz burada maskeleme sebebi de o 
	   MOV COUNTER , CL;bu counter en sonda kalan döngü için kullanılacak
	   
	   MOV DX, 20AH

TRANSMIT1: ;aldığımız sayıyı ekrana yazma
	 
	  IN AL, DX
	  AND AL, 01H ;TxRDY kontrolü
	  JZ TRANSMIT1
	  
	  MOV DX, 0208H 
	  MOV AL, BL
	  OUT DX, AL
	  
DONGU1: ;döngü halinde harfleri kontrol edip eşitse ekrana yazma
	 
	 MOV DX, 20AH
	 
RECEIVE2: 

	IN AL, DX
	AND AL, 02H ;RxRDY kontrolü
	JZ RECEIVE2
	  
	MOV DX, 0208H
	IN AL, DX
	SHR AL, 1
	  
	MOV BL, AL
	MOV AH, DIZI[SI]
	
	 CMP AH, BL ;aynı değilse  tekrardan sayı girmesini istiyoruz
	 JNE ENDLESS
	   
	 INC SI ;aynıysa almaya devam edeceğiz
	 MOV DX, 020AH

TRANSMIT2:

	     IN AL, DX
	     AND AL, 01H
	     JZ TRANSMIT2
	     
	     MOV DX, 0208H
	     MOV AL, BL
	     OUT DX, AL
	      
LOOP DONGU1
	
;her şey doğru gittiyse burada kalan harfleri ekrana yazdıracağız

	 MOV BL,  5 ;kalan döngü sayısını hesaplamak için
	 SUB BL, COUNTER
	 MOV CL, BL
	
DONGU2:

        MOV BL, DIZI[SI]
        MOV DX, 020AH
	
TRANSMIT3:

	IN AL, DX
	AND AL, 01H
	JZ TRANSMIT3
	
	MOV DX, 0208H
	MOV AL, BL
	OUT DX, AL	
	  
	 INC SI
	 LOOP DONGU2
	 
	 MOV BL, 20H ;sonda boşluk yansıtma
	 MOV DX, 020AH
	 
TRANSMITSON:

	IN AL, DX
	AND AL, 01H
	JZ TRANSMITSON
	
	MOV DX, 0208H
	MOV AL, BL
	OUT DX, AL
	 
        JMP ENDLESS
	
CODE    ENDS
        END START
