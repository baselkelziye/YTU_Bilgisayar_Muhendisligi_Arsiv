;SORU: Virtual terminali kullanarak 8251 vasıtasyıla 
;208H Adresine 8251 yerlestirilmis ardisik cift adreslerle 20AH (ardisik cift adresi)
;C/D kontrolü için 208H 20AH (16bit) kullanilir basta belirlenecek iki adres budur.
;208H son 4 biti ...1000 --- 20AH son 4 biti ...1010H C/D = A1 bağlanacak
;208H iken Data 20AH iken Control islemi yapar
;Calisma frekansi 9600 baud rate clockun, virtual terminalinde 9600
;8bit data biti 1 bit stop bit parity yok
;Terminale girilen herhangi bir veri alınsın bir sonraki harf işlemci tarafından
;karar verilsin ekrana 8251 üzerinden transmit edilerek terminalde recieve edilerek
;ekrana yazilsin.
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
NUM  	DW 0H
ISIM          DB 4FH, 52H, 43H, 55H, 4EH
ARR	       	DB  0H, 0H, 0H, 0H, 0H, 0H, 0H, 0H	;6 bytelik yer acalim
DATA    ENDS

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
START:
    MOV AX, DATA
	MOV DS, AX
	MOV DX, 020Ah     ;C=0 control verisi gonderilir MODE INSTUCTION
	MOV AL, 01001101B ;01 BAUD RATE = 1, 11 8 BİT, 00 Parity Disable, 01 1 BİT stop
	OUT DX, AL   ;Control portuna atildi
	MOV AL, 40H ;0100 0000 RESET islemi yapar KONTROL YAZMACI
	OUT DX, AL
	MOV AL, 01001101B ;MOD INSTRUCTION TEKRAR SOYLERIZ
	OUT DX, AL
	MOV AL, 00010101B ;CONTROL YAZMACI YAZARIZ
	OUT DX, AL

ENDLESS:

;ILK KARAKTERI OKURKEN
;Okurken*****
	MOV DX, 020AH ;Kontrol islemleri yapacagiz C=1
TEKRAR:
	IN AL, DX   ;Status okuma islemi AL ye status aktarılır, durum kontrolü
	AND AL, 02H ;AL AND 0000 0010, A1 eğer 1 ise Receive Ready 
	JZ TEKRAR
;*************

;Okuma
	MOV DX, 0208H ;Data islemleri yapilir C=0 
	IN AL, DX	;AL  8251den data okur
	SHR AL,1
	AND AH, 00000000B   ;Masking the upper bits to reach lower 
	MOV BL,AL
	MOV NUM, AX  ;NUM icinde yedekleme islemi
	

;Yazarken*****
	MOV DX, 020AH  ;C=1 
TEKRAR2:
	IN AL, DX  ;Status okuma islemi
	AND AL, 01H  ;Transmit ready mi veri virtual terminale aktarilir
	JZ TEKRAR2  ;Transmit ready olana kadar
;**********
;Yazma	
	MOV DX, 0208H  ;Data islemleri yapilir
	MOV AL,BL
	OUT DX, AL	   ;Virtual terminale yazilir
	
;_______________________________________________________________

;Okurken*****

	 XOR SI,SI
	 SUB NUM,30H   ;GERCEK DEGERE ERISIM
	 MOV CX, NUM    
	 
	  ;Kontroller
	 CMP CX,5
	 JAE BOSLUK
	 CMP CX,0
	 JBE BOSLUK
	 
	 
	 
OKU1:		 
      	 MOV DX, 020AH ;Kontrol islemleri yapacagiz C=1
TKRR1:
	 IN AL, DX   ;Status okuma islemi AL ye status aktarılır, durum kontrolü
	AND AL, 02H ;AL AND 0000 0010, A1 eğer 1 ise Receive Ready 
	JZ TKRR1

        MOV DX, 0208H ;Data islemleri yapilir C=0 
	IN AL, DX	;AL  8251den data okur
	SHR AL,1
	MOV ARR[SI], AL  ;NUM icinde yedekleme islemi
	INC SI
LOOP OKU1  


;Yazarken*****
	 MOV CX,NUM   ;BURAYA ALDIGIMIZ VERI GELMELI AMA NUM DEGERINI YAZINCA PROGRAM CALISMIYOR
	 XOR SI,SI
YAZ1: 
	 MOV DX, 020AH  ;C=1 
TKRR2:
	IN AL, DX  ;Status okuma islemi
	AND AL, 01H  ;Transmit ready mi veri virtual terminale aktarilir
	JZ TKRR2  ;Transmit ready olana kadar
	
	MOV DX, 0208H  ;Data islemleri yapilir
	MOV AL,ARR[SI]
	INC SI
	OUT DX, AL	   ;Virtual terminale yazilir
LOOP YAZ1 


;Ekleme islemleri
	 XOR SI,SI
	 MOV CX, 5 	;TOTAL SIZE 
	 SUB CX,  NUM 	;Istedigim cevrim sayisi
	 MOV SI,  NUM 	;Dizi indisi
	

FINISH: 
	 MOV DX, 020AH  ;C=1 
TKRR3:
	IN AL, DX  ;Status okuma islemi
	AND AL, 01H  ;Transmit ready mi veri virtual terminale aktarilir
	JZ TKRR3  ;Transmit ready olana kadar
	
	 MOV DX, 0208H	;Data islemleri
	 MOV AL,ISIM[SI]
	 INC SI
	 OUT DX,AL
LOOP FINISH	 

BOSLUK:
;BOSLUK KARAKTERI EKLENMESI
	  MOV DX, 020AH  ;C=1 
TKRR4:
	IN AL, DX  ;Status okuma islemi
	AND AL, 01H  ;Transmit ready mi veri virtual terminale aktarilir
	JZ TKRR4
	MOV DX,0208H
	MOV AL,20H
	OUT DX,AL
	 
		
        JMP ENDLESS
CODE    ENDS
        END START