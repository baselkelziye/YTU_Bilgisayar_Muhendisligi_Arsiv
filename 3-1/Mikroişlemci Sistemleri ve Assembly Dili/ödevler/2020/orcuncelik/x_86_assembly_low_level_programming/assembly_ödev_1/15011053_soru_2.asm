myds SEGMENT PARA 'data'  
CR       EQU 13
LF       EQU 10      
n        DW  ? 																;Dizi boyutu
dizi     dw  ?   															;Dizi
MSG1     DB  'Boyut girin.',0						
MSG2     DB  CR, LF, 'Sayilari girin.',0
LINE     DB  CR, LF, '->',0													;Next line ve tasarim acisindan optimizasyon '->'
SPACE    DB  ' , ',0 														;Output verirken tasarim acisindan optimizasyon
HATA0    DB  CR, LF, 'Hata!!! 0-1000 arasinda bir sayi girin.',0   
HATA1    DB  CR, LF, 'Negatif sayi giremezsiniz!!! Lutfen tekar girin.',0  
HATA2    DB  CR, LF, 'Hata!!! Lutfen rakam girin.',0 
HATA3    DB  CR, LF, 'Ucgen sarti saglanmiyor!!!',0 
SONUC    DB  CR, LF,  'Sonuc: ',0  

myds ENDS
myss SEGMENT PARA STACK 'stack'
	 DW 12 DUP(?)
myss ENDS
mycs SEGMENT PARA 'code'
	 ASSUME CS:mycs, DS:myds, SS:myss
ANA	 PROC FAR
	 PUSH DS
	 XOR AX,AX
	 PUSH AX
	 MOV AX,myds
	 MOV DS,AX
;EXE tipi programlar icin on ayar
          
     MOV AX, OFFSET MSG1  ;Boyut girin mesajı
     CALL PUT_STR	      
     MOV AX, OFFSET LINE  
     CALL PUT_STR		  ;
     CALL GETN
	 MOV n,AX			  ;Boyut 'n' de saklanır
     CMP AX,2     		  ;3 elemandan az girilirse ucgen sarti saglanmadigindan program hata mesajı verir.  
     JA devam			  ;Eger boyut 2'den buyukse program devam eder.
     MOV AX, OFFSET HATA3 ;Ucgen sarti saglanmadigi hatasinin OFFSET'i AX registerina aktarilir.
     CALL PUT_STR 		  ;Ucgen sarti saglanmadigina dair hata ekrana basılır.
     JMP Lexit 			  ;Ucgen sarti saglanmadigi icin programdan cikis yapilir.  
     
     devam:     
     XOR SI,SI
     MOV AX, OFFSET MSG2  ;Sayilari girin mesajı
     CALL PUT_STR
     ;Input alma islemi
     MOV CX,n  			  ;n dizi boyutu kadar donguye girer.
Lin: MOV AX, OFFSET LINE  
     CALL PUT_STR 		  ;'->' Tasarım için.
     CALL GETN			  ;Konsoldan girilen sayi AX'e aktarilir.
     MOV dizi[SI],AX  	  ;Dizinin elemanları AX'ten alinir.
     ADD SI,2     
     LOOP Lin
     

;____BUBBLE_SORT______________________________________________________________	     
;Bubble Sort kucukten buyuge siralama algoritması			
	MOV CX,n
    XOR BX,BX   					;i
    DEC CX      					;n-1     
    XOR SI,SI
    
;Bubble Sort kucukten buyuge siralama algoritması			
   LB1: PUSH CX						    ;n-1 stackte		
	    MOV CX,n					    ;yeni cx
     	DEC CX
	    SUB CX, BX					    ;n-i-1
	    XOR SI,SI					    ;SI index 0
		   LB2: MOV AX, dizi[SI]		;İlk eleman AX'te
				CMP AX, dizi[SI+2]		;İkinci elemanla karşılaştırıyoruz
				JB cikis			    ;Jump below ise cik buyuk ise devam
				XCHG dizi[SI+2], AX		;Dizinin 2. elemanla AX yer degistir.
			    MOV  dizi[SI], AX		;Dizinin 1. elamana AX'i ata.
				cikis:
				ADD SI,2
			LOOP LB2
		INC BX						;i
		POP CX
    LOOP LB1
;_______________________________________________________________________________  
    XOR SI,SI   ;dizi
    XOR BX,BX	;i gorevi goruyor.
    XOR DI,DI   ;sign
    MOV CX,n    ;n
    
LWHILE:	CMP BX,CX
		JA exitwhile
		    CMP DI,0     		  			;Eger en kucuk ucgen olusmadiysa 0 dir
		    JNE exitWHILE
			    MOV AX, dizi[SI]   			;a
			    ADD AX,dizi[SI+4]  			;a+c
			    CMP AX, dizi[SI+2] 			;comparing a+c, b
			    JB exitIF
			        MOV AX, dizi[SI]   		;a
			        ADD AX, dizi[SI+2] 		;a+b
			        CMP AX, dizi[SI+4] 		;comparing a+b, c
			        JB exitIF
			            MOV AX, dizi[SI+2] ;b
			            ADD AX, dizi[SI+4] ;b+c
			            CMP AX, dizi[SI]   ;comparing b+c, a
			            JB exitIF  
			                ;eger tum sartlari sagliyorsa
			                MOV BX,SI 	   ;konum icin
			                PUSH BX   	   ;en kucuk ucgenin ilk indsinin konumunu stacke attim
			                MOV DI, 1      ;sign 1 oldu,en kucuk ucgen bulundu			               
			                JMP exitIF
      exitIF:   ADD SI,2
	            DEC CX    ;While dongusunde oldugumuzdan count registerinin degerini azalttik.
	            INC BX    ;i degerini arttirdik.              
	            JMP LWHILE		
exitWHILE:
        CMP DI,0   			 ;ucgen sarti saglanmissa DI 1 dir.
        JNE ucgen  			 ;DI 0'a esit degilse ucgen sarti saglanmis demektir.
        MOV AX, OFFSET HATA3 ;Ucgen sarti saglanamadigina dair hata mesajı
        CALL PUT_STR 
        JMP Lexit 			 ;Ucgen sarti saglanmadigi icin programdan cikis yapilir.          
ucgen:  ;Eger sonuc olustuysa ekrana yazdirma islemi.    
        MOV AX, OFFSET SONUC
        CALL PUT_STR
        POP BX
        MOV CX,3         
        print: ;Sonucun ekranda yazdirilmasi
            MOV AX,dizi[BX] 
            CALL PUTN
            MOV AX, OFFSET SPACE
            CALL PUT_STR
            ADD BX,2
        LOOP print                
Lexit: ;Programdan cikis labelimiz.
	 RETF
ANA  ENDP    
;___________________________________________________________________________________
;Kullanicidan veri girisi alabilmemiz icin gerekli yordamlar

GETC PROC NEAR ;Klavyeden alinan karakteri alir ve AL yazmacina alip, ekranda gosterir
	 MOV AH, 1h
	 INT 21H
	 RET
GETC ENDP
;---------------
PUTC PROC NEAR ;AL yazmacindaki degeri ekranda gosterir
	 PUSH AX
	 PUSH DX
	 MOV DL, AL
	 MOV AH,2
	 INT 21H
	 POP DX
	 POP AX
	 RET
PUTC ENDP       
;-----------------
GETN PROC NEAR ;Klavyeden girilen degeri degeri AX registirina atar.
     PUSH BX
     PUSH CX
     PUSH DX
     PUSH DI     ;Basamak sayisini tutar.(3 haneyi gecmesin diye)
GETN_START:
;    MOV DX,1
     XOR BX,BX
     XOR CX,CX
     XOR DI,DI
NEW: CMP DI,3     ;Sayimiz 4 basamakli olamaz, bunun icin basamak kontrolü.
     JA  ERROR0   ;
     CALL GETC
     CMP AL,CR
     JE FIN_READ  ;Enter tusuna basildiysa okuma biter
     CMP AL, '-'  ;AL - mi geldi mi?
     JNE CTRL_NUM ;Gelen sayi 0-9 arasında mi
NEGATIVE:
     JMP ERROR1   ;Negatif hata mesajı
CTRL_NUM:
     CMP AL, '0'  ;Sayi 0 ile 9 arasinda mi kontrolu
     JB ERROR2
     CMP AL, '9'
     JA ERROR2
     SUB AL,'0'
     MOV BL,AL
     MOV AX,10
;    PUSH DX
     MUL CX
;    POP DX
     MOV CX,AX
     ADD CX,BX
     INC DI;    ;Basamak arttirdik
     JMP NEW    ;Klavyeden yeni basilan degeri al      
ERROR0:
     MOV AX, OFFSET HATA0
     CALL PUT_STR   ;Hata!!! 0-1000 arasinda bir sayi girin:'
     MOV AX, OFFSET LINE
     CALL PUT_STR
     JMP GETN_START
ERROR1:
     MOV AX, OFFSET HATA1
     CALL PUT_STR   ;Negatif sayi giremezsiniz!!!
      MOV AX, OFFSET LINE
     CALL PUT_STR 
     JMP GETN_START      
ERROR2:
     MOV AX, OFFSET HATA2
     CALL PUT_STR   ;Hata!!! Lutfen rakam girin
     MOV AX, OFFSET LINE
     CALL PUT_STR
     JMP GETN_START  

     
FIN_READ: 
     MOV AX, CX
FIN_GETN:
     POP DI
     POP DX
     POP CX
     POP DX
     RET
GETN ENDP
;-----------------------     
PUTN PROC NEAR ;AX de bulunan sayiyi onluk tabanda hane han yazdırır
	 PUSH CX
	 PUSH DX
	 XOR DX,DX
	 PUSH DX
	 MOV CX,10
	 CMP AX,0
	 JGE CALC_DIGITS
	 NEG AX
	 PUSH AX
	 MOV AL, '-'
	 CALL PUTC
	 POP AX
CALC_DIGITS:
	 DIV CX
	 ADD DX, '0'
	 PUSH DX
	 XOR DX,DX
	 CMP AX,0
	 JNE CALC_DIGITS
DISP_LOOP:
	 POP AX
	 CMP AX,0
	 JE END_DISP_LOOP
	 CALL PUTC
	 JMP DISP_LOOP
END_DISP_LOOP:
	 POP DX
	 POP CX
	 RET
PUTN ENDP   
;---------------------
PUT_STR PROC NEAR;AX de adresi verilen sonunda 0 olan stringi karakter karakter yazdırır. BX stringe indis olarak kullanılır
     PUSH BX
     MOV BX, AX
     MOV AL, BYTE PTR[BX]
PUT_LOOP:
     CMP AL,0
     JE PUT_FIN
     CALL PUTC
     INC BX
     MOV AL, BYTE PTR[BX]
     JMP PUT_LOOP
PUT_FIN:
     POP BX
     RET
PUT_STR ENDP   

mycs ENDS  
    END ANA























