;Yildiz Teknik Universitesi Bilgisayar Muhendisligi Mikroislemciler dersi kapsaminda 
;8251 ve 8255 ile eszamanli calisan hesap makinesi gerceklenmis olup, tek digitte hata kontrolleri yapilmistir.
;Hazirlayan: Orcun Celik  

MYSS SEGMENT PARA STACK 'STACK'
	 DB 256 DUP(0)
MYSS ENDS
MYDS SEGMENT PARA 'DATA'

TUSLAR  DB 10H,66H,0H,10H,10H,3H,2H,1H,10H,6H,5H,4H,10H,9H,8H,7H

TOPLAMA DB 74H, 6FH, 70H, 6CH, 61H, 6DH, 61H,20H
CIKARMA DB 63H, 69H, 6BH, 61H, 72H, 6DH, 61H, 20H
CARPMA  DB 63H, 61H, 72H, 70H, 6DH, 61H, 20H
BOLME   DB 62H, 6FH, 6CH, 6DH, 65H

HATA        DB 68H, 61H, 74H, 61H
HATATASMA   DB 64H, 69H, 67H, 69H, 74H, 20H, 74H, 61H, 73H, 6DH, 61H, 73H, 69H
HATANEGATIF DB 6EH, 65H, 67H, 61H, 74H, 69H, 66H, 20H, 69H, 73H, 61H, 72H, 65H, 74H
HATABOLUNME DB 74H, 61H, 6DH, 20H, 62H, 6FH, 6CH, 75H, 6EH, 65H, 6DH, 65H, 6DH, 65H
HATASIFIR   DB 73H, 69H, 66H, 69H, 72H, 20H, 69H, 6CH, 65H, 20H, 62H, 6FH, 6CH, 6DH, 65H
HATAKODU    DB 0H

ISLEM DB 0H
SAYI1 DB 0H
SAYI2 DB 0H

MYDS ENDS
CODE    SEGMENT PUBLIC 'CODE'
        ASSUME SS:MYSS, DS: MYDS, CS:CODE
START:
	PUSH DS
	XOR  AX,AX
	PUSH AX
	MOV  AX,MYDS
	MOV  DS,AX
;________________________________________________
;8251 INITIALIZATION
	MOV  DX, 020Ah         ;C=0 control verisi gonderilir MODE INSTUCTION
	MOV  AL, 01001101B     ;01 BAUD RATE = 1, 11 8 BÝT, 00 Parity Disable, 01 1 BÝT stop
	OUT  DX, AL            ;Control portuna atildi
	MOV  AL, 40H 	       ;0100 0000 RESET islemi yapar KONTROL YAZMACI
	OUT  DX, AL
	MOV  AL, 01001101B     ;MOD INSTRUCTION TEKRAR SOYLERIZ
	OUT  DX, AL
	MOV  AL, 00010101B     ;CONTROL YAZMACI YAZARIZ
	OUT  DX, AL
;________________________________________________
;8255 SETTINGS
	MOV  DX, 206H ;cntrl  adress
	MOV  AL, 09H  ;0000 1001 
	OUT  DX, AL
	MOV  AL, 05H  ;0000 0101
	OUT  DX, AL
	MOV  AL, 0BCH ;1011 1100
	OUT  DX, AL
;________________________________________________
ENDLESS: 
    MOV  HATAKODU,0 ;Hatakodu reset
	;7 Segment'e 0 yazmak icin handshake kontrolu
HANDSHAKE1:	 ;Handshake kontrolu
	MOV  DX,204H
	IN   AL,DX
	AND  AL,01H
	CMP  AL,00
	JE   HANDSHAKE1
	
	MOV  DX,0202H		;Port B
	XOR  AX,AX
	OUT  DX,AL		;Port B reset	
;________________________________________________	
;1. SAYIYI ALMAK
HANDSHAKE2: ;Handshake kontrolu
	MOV  DX,204H 		;Port C
	IN   AL,DX			
	AND  AL,08H 		
	CMP  AL,00 		
	JE   HANDSHAKE2   	
	
	;Hesap makinesine sayi girilmesi
	MOV  DX,200H		;Port A (Hesap makinesi)
	XOR  BX,BX
	IN   AL,DX			;Hesap makinesinden veri okunmasi	
	MOV  BL,AL		    ;Verinin gecici saklanmasi
	AND  BL,00001111b	;Lower bits masking
	CMP  BL,3H		    
	JE   ENDLESS
	CMP  TUSLAR[BX],10H   
	JGE  ENDLESS		    
	
;1. SAYIYI YAZMAK 
HANDSHAKE3:   ;Handshake kontrolu
	MOV  DX,204H
	IN   AL,DX
	AND  AL,01H
	CMP  AL,00
	JE   HANDSHAKE3
	
	MOV  AL,TUSLAR[BX] 	;Sayi okunup SAYI1 degiskenine kaydedildi
	MOV  SAYI1,AL
	MOV  DX,202H		 	;SAYI1 7segmentte yazdirildi
	OUT  DX,AL
;________________________________________________
;ISLEMI ALMAK
HANDSHAKE4:
	MOV  DX,204H 	;PORT C
	IN   AL,DX
	AND  AL,08H 			
	CMP  AL,00 			   
	JE   HANDSHAKE4

	MOV  DX,200H	;Port A 
	XOR  BX,BX
	IN   AL,DX
	MOV  BL,AL
	AND  BL,00001111b
	
	CMP  BL,3H		;ON/C Tusunun adresi
	JE   ENDLESS		
	
	CMP  TUSLAR[BX],10H
	JNE  HANDSHAKE4
	
;ISLEM ALINCA 0 YAZDIRMA
HANDSHAKE5:
	MOV  DX,204H
	IN   AL,DX
	AND  AL,01H
	CMP  AL,00
	JE   HANDSHAKE5
	
	MOV  DX,202H        ;Port B
	MOV  AL,0
	OUT  DX,AL
	
	MOV  ISLEM,BL	  ;Islem kaydedilir
	
;__________________________________________________
;2. SAYIYI ALMAK
HANDSHAKE6:	;Handshaking kontrolu
	MOV  DX,204H  ;Port C
	IN   AL,DX
	AND  AL,08H 
	CMP  AL,00 
	JE   HANDSHAKE6   
 	
	MOV  DX,200H  ;Port A
	XOR  BX,BX
	IN   AL,DX
	MOV  BL,AL
	AND  BL,00001111B
	CMP  BL,3H		;ON/C ise eger basa don.
	JE   ENDLESS		
	
IKINCISAYI:
	CMP  TUSLAR[BX],10H	;10H islemdir
	JE   HANDSHAKE4		
	MOV  AL,TUSLAR[BX]
	MOV  SAYI2,AL			;Sayiyi al
	
;________________________________________________
;Islemler
	XOR  AL,AL
	MOV  AL,ISLEM
	CMP  AL,0H		;Toplama isaretinin karsiligi
	JNE  OTHER1
	XOR  AL,AL
	MOV  AL,SAYI1
	ADD  AL,SAYI2			
	CMP  AL,09H      ;09H buyuk olmasi durumunda tasma hatasi olur.
	JA   HATAOF		;Tasma hatasina atlar
	JMP  YAZ
OTHER1:
	CMP  AL,04H	   ;Cikarma isaretinin karsiligi
	JNE  OTHER2
	MOV  AL,SAYI1
	CMP  AL,SAYI2
	JA   CIKAR		;Sayi1 Sayi2'den buyuk olmasi durumunda cikarma islemi gerceklesir.
	JB   HATACIKARMA ;Kucuk olmasi durumunda hata yasanir.
CIKAR:
	SUB  AL,SAYI2			
	JMP  YAZ
OTHER2:
	CMP  AL,08H	  ;Carpma isaretinin karsiligi
	JNE  OTHER3	  ;Esit degilse 0CH olan bolme isareti yapilir
	XOR  AX,AX
    XOR  BX,BX
	MOV  AL,SAYI1
	MOV  BL,SAYI2
	MUL  BL				
	CMP  AL,09H    ;Tasma kontrolu
	JA   HATAOF    ;Hata durumu
	JMP  YAZ
OTHER3:			  
	MOV  AL,SAYI2                                                                                                         
	CMP  AL,0	 ;0 ile bolunme hatasý kontrolu
	JE   HATAZERO
	
	MOV  AL,SAYI1                                                                                                             
	MOV  BL,SAYI2
	DIV  BL				
	CMP  AH,0H	;AH 0'dan buyuk olmasi durumunda tam boluneme yasanir
	JG   HATABOLME
	JMP  YAZ
;________________________________________________
;Hata kodlarýna gore virtual terminale yazdirma islemi yapilacaktir
HATAOF:
	MOV  HATAKODU,1		;Overflow hatasi kodu
	JMP  HATAYAZDIRMA
HATACIKARMA:
	MOV  HATAKODU,2		;Cikarma hatasi kodu
	JMP  HATAYAZDIRMA
HATABOLME:
	MOV  HATAKODU,3		;Cikarma hatasi kodu
	JMP  HATAYAZDIRMA
HATAZERO:
	MOV  HATAKODU,4		;Sýfýr ile bolunme hatasi kodu
;________________________________________________
;Hata Yazdirma ve 'h' karakterini okuma islemleri
HATAYAZDIRMA:

	XOR  SI,SI
	MOV  CX,4
YAZHATA:
	MOV  DX,020AH 
STATUS1:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	        ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS1	            ;Transmit ready olana kadar

	MOV  DX, 0208H       ;Data islemleri yapilir
	MOV  AL,HATA[SI]		
	INC  SI
	OUT  DX, AL	        ;Virtual terminale yazilir
	LOOP YAZHATA
;________________________________________________
;'h' karakterini okuma
	MOV  DX, 020AH ;C = 1 Kontrol
STATUS2:
	IN   AL,DX
	AND  AL,02H    ;Status
	JZ   STATUS2

	MOV  DX,0208H   ;C=0 Data
	IN   AL,DX	
	SHR  AL,1
	CMP  AL,68H
	JNE  SONDUR
	MOV  BL,AL 		;Gecici Saklanmasi
	
	;Bosluk karakterinin Yazilmasi
	MOV  DX,020AH  ;C=1 
STATUS3:
	IN   AL,DX          ;Status okuma islemi
	AND  AL,01H        ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS3
	
	MOV  DX,0208H   ;C=0
	MOV  AL,20H
	OUT  DX,AL
;________________________________________________
;'h' karakterini yazdirma
	MOV  DX,020AH  ;C = 1 Kontrol
STATUS4:
	IN   AL,DX  ;Status 
	AND  AL,01H  ;Transmit ready 
	JZ   STATUS4

	MOV  DX,0208H  ;C=0 Data
	MOV  AL,BL
	OUT  DX,AL	 
	
;Bosluk karakterinin Yazilmasi
	MOV  DX,020AH  ;C=1 
STATUS5:
	IN   AL,DX          ;Status okuma islemi
	AND  AL,01H       ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS5
	
	MOV  DX,0208H   ;C=0
	MOV  AL,20H
	OUT  DX,AL
;________________________________________________
;Hata Turunun Algilanip Yazilmasi
	MOV  AL,HATAKODU
	CMP  AL,1
	JE   TASMAHATASI
	CMP  AL,2
	JE   CIKARMAHATASI
	CMP  AL,3
	JE   BOLMEHATASI
	CMP  AL,4
	JE   SIFIRHATASI
	JMP  SONDUR
;________________________________________________
TASMAHATASI:

	XOR  SI,SI
	MOV  CX,13
YAZHATA1:
	MOV  DX,020AH 
STATUS6:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	        ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS6	        ;Transmit ready olana kadar

	MOV  DX,0208H       ;Data islemleri yapilir
	MOV  AL,HATATASMA[SI]		
	INC  SI
	OUT  DX,AL	        ;Virtual terminale yazilir
	LOOP YAZHATA1
	
	JMP  SONDUR
;________________________________________________
CIKARMAHATASI:

	XOR  SI,SI
	MOV  CX,14
YAZHATA2:
	MOV  DX,020AH 
STATUS7:
	IN   AL,DX 		  ;Status okuma islemi
	AND  AL,01H	      ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS7	      ;Transmit ready olana kadar

	MOV  DX,0208H     ;Data islemleri yapilir
	MOV  AL,HATANEGATIF[SI]		
	INC  SI
	OUT  DX, AL	      ;Virtual terminale yazilir
	LOOP YAZHATA2
	
	JMP  SONDUR
;________________________________________________
BOLMEHATASI:

	XOR  SI,SI
	MOV  CX,14
YAZHATA3:
	MOV  DX,020AH 
STATUS8:
	IN   AL,DX 		;Status okuma islemi
	AND  AL,01H	    ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS8	    ;Transmit ready olana kadar

	MOV  DX,0208H   ;Data islemleri yapilir
	MOV  AL,HATABOLUNME[SI]		
	INC  SI
	OUT  DX,AL	    ;Virtual terminale yazilir
	LOOP YAZHATA3
	
	JMP  SONDUR
;________________________________________________
SIFIRHATASI:

	XOR  SI,SI
	MOV  CX,15
YAZHATA4:
	MOV  DX,020AH 
STATUS9:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	    ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS9	    ;Transmit ready olana kadar

	MOV  DX,0208H    ;Data islemleri yapilir
	MOV  AL,HATASIFIR[SI]		
	INC  SI
	OUT  DX,AL	   ;Virtual terminale yazilir
	LOOP YAZHATA4
	
	JMP  SONDUR
;________________________________________________
;Eger hata yoksa 7 segmentte sonuc yazdirma islemi yapilir
YAZ:
	MOV  BL,AL
	MOV  AL,ISLEM
	
	CMP  AL,00H
	JE   TOPLAMAYAZ
	CMP  AL,04H
	JE   CIKARMAYAZ
	CMP  AL,08H
	JE   CARPMAYAZ
	CMP  AL,0CH
	JE   BOLMEYAZ
	JMP  YAZ7Seg
;___________________________________________________
;Eger hata yoksa islem turunun yazilmasi
TOPLAMAYAZ:
	XOR  SI,SI
	MOV  CX,7
YAZTOPLA:
	MOV  DX,020AH     ;C =1
STATUS10:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	    ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS10 	    ;Transmit ready olana kadar

	MOV  DX, 0208H    ;Data islemleri yapilir
	MOV  AL,TOPLAMA[SI]		
	INC  SI
	OUT  DX, AL	   ;Virtual terminale yazilir
	LOOP YAZTOPLA

	JMP  YAZ7Seg
;________________________________________________
CIKARMAYAZ:
	XOR  SI,SI
	MOV  CX,7
YAZCIKAR:
	MOV  DX,020AH 	;C = 1
STATUS11:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	    ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS11 	    ;Transmit ready olana kadar

	MOV  DX,0208H    ;Data islemleri yapilir
	MOV  AL,CIKARMA[SI]		
	INC  SI
	OUT  DX,AL	   ;Virtual terminale yazilir
	LOOP YAZCIKAR
	
	JMP  YAZ7Seg
;________________________________________________
CARPMAYAZ:
	XOR  SI,SI
	MOV  CX,6
YAZCARP:
	MOV  DX,020AH 			;C = 1
STATUS12:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	        ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS12 	    ;Transmit ready olana kadar

	MOV  DX, 0208H    ;Data islemleri yapilir
	MOV  AL,CARPMA[SI]		
	INC  SI
	OUT  DX,AL	   ;Virtual terminale yazilir
	LOOP YAZCARP	 
	
	JMP  YAZ7Seg
;________________________________________________
BOLMEYAZ:
	XOR  SI,SI
	MOV  CX,5
YAZBOL:
	MOV  DX,020AH 		;C = 1
STATUS13:
	IN   AL,DX 		    ;Status okuma islemi
	AND  AL,01H	    ;Transmit ready mi veri virtual terminale aktarilir
	JZ   STATUS13	    ;Transmit ready olana kadar

	MOV  DX,0208H    ;Data islemleri yapilir
	MOV  AL,BOLME[SI]		
	INC  SI
	OUT  DX,AL	   ;Virtual terminale yazilir
	LOOP YAZBOL
	
	JMP  YAZ7Seg
;________________________________________________
;7 Segmentte islem sonucunun yazilmasi (Sonuc olarak BL'de)
YAZ7seg:
HANDSHAKE7:
	MOV DX,204H    ;Port C
	IN  AL,DX
	AND AL,01H
	CMP AL,00
	JE  HANDSHAKE7

	MOV AL,BL
	
	MOV DX,202H   ;Port B
	OUT DX, AL
	JMP FINISH
;________________________________________________
SONDUR: ;7 Seg Sondurulur
HANDSHAKE8: 
	MOV  DX,204H		;Port C
	IN   AL,DX
	AND  AL,01H
	CMP  AL,00
	JE   HANDSHAKE8
	MOV  AL,00001111b	
	MOV  DX,202H		;Port B
	OUT  DX, AL
	
FINISH:
;BOSLUK KARAKTERI EKLENMESI
	MOV DX, 020AH  ;C=1 
STATUS14:
	IN  AL, DX      ;Status okuma islemi
	AND AL, 01H    ;Transmit ready mi veri virtual terminale aktarilir
	JZ  STATUS14
	
	MOV DX,0208H   ;C=0
	MOV AL,20H
	OUT DX,AL
;________________________________________________
	
HANDSHAKE9:	;Handshaking
	MOV DX,204H		;Port C
	IN  AL,DX
	AND AL,08H
	CMP AL,00
	JE  HANDSHAKE9
	
	MOV DX,200H		;Port B
	IN  AL,DX
	XOR BX,BX
	AND AL,00001111b
	MOV BL,AL
	CMP BL,3H
	
	JNE HANDSHAKE9
	JE  ENDLESS
 
CODE    ENDS
        END START