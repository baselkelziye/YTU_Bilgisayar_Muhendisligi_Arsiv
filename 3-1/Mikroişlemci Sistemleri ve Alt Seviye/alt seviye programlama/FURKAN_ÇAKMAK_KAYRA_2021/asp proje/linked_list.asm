SSEG 	SEGMENT PARA STACK 'STACK'
	DW 200 DUP (?)
SSEG 	ENDS

DSEG	SEGMENT PARA 'DATA'
CR	EQU 13
LF	EQU 10
MSG1	DB CR,LF,   'N degerini giriniz',0
MSG45   DB '   100 den Kucuk :' ,0
MSG3	DB CR, LF,' ',0
MSG2	DB CR, LF, 'Elemani giriniz: ', 0
MSG5    DB CR, LF, 'Link dizisi elemanlari ', 0
MSG6    DB CR, LF, 'Dizinin giris sirasina gore elemanlari ', 0
MSG7    DB CR, LF, 'Dizinin linkli liste dizisindeki adresleri ', 0
MSG8    DB CR, LF, 'Hangisini yapmak istiyorsunuz? ', 0
MSG9    DB CR, LF, '1-) En bastan eleman girme ', 0
MSG10   DB CR, LF, '3-) Eleman ekleme ', 0
MSG11   DB CR, LF, '2-) Eleman listeleme ', 0
MSG12   DB CR, LF, '4-) Program sonlandirma ', 0
MSG25   DB CR,LF, 'EN KUCUK ELEMAN = ',0
MSG4    DB CR,LF, 'Muhammet Kayra Bulut 20011901 ', 0
HATA	DB CR, LF, 'Dikkat !!! Duzgun sayi vermediniz yeniden giris yapiniz.!!!  ', 0
MSG26   DB CR,LF, 'INDIS DEGERI = ',0
N   	DW 0
dizi	DW 100 DUP(?)
link    DW 100 DUP(?)
enkck   DW ?
DSEG 	ENDS 

CSEG 	SEGMENT PARA 'CODE'
ASSUME CS:CSEG, DS:DSEG, SS:SSEG

elemanekle PROC FAR
           PUSH DX
           MOV dizi[SI],AX
           CMP SI,0
           JNE  L1
           MOV enkck,SI
           MOV link[SI],-1
           JMP SON
L1:        MOV DI,enkck
           CMP dizi[DI],AX
           JNG L2
           MOV DX,enkck
           MOV link[SI],DX
           MOV enkck,SI
           JMP SON
L2:        MOV DI,enkck
           MOV BX,link[DI]

L4:        CMP BX,-1
           JE L3
           CMP dizi[BX],AX
           JG L3
           MOV DI,link[DI]
           MOV BX,link[DI]
           JMP L4
L3:        MOV link[SI],BX
           MOV link[DI],SI
           
SON:       ADD SI,2
           POP DX
           RETF
elemanekle ENDP
        


MENU     MACRO
        MOV AX, OFFSET MSG4
        CALL PUT_STR
         MOV AX,OFFSET MSG9
        CALL PUT_STR
        MOV AX,OFFSET MSG11
        CALL PUT_STR
        MOV AX,OFFSET MSG10
        CALL PUT_STR
         MOV AX,OFFSET MSG12
        CALL PUT_STR
        CALL GETN
ENDM


YAZDIRMA PROC FAR
        PUSH SI
        PUSH CX
        PUSH AX
        PUSH DI
        MOV AX,OFFSET MSG6
        CALL PUT_STR
        XOR SI,SI
        MOV CX,N
Label1:  MOV AX,OFFSET MSG3
        CALL PUT_STR
        MOV AX,dizi[SI]
        CALL PUTN
        ADD SI,2
        LOOP Label1
        MOV AX,OFFSET MSG5
        CALL PUT_STR
        MOV CX,N
        XOR SI,SI
Label3: MOV AX, OFFSET MSG3
        CALL PUT_STR
        MOV AX,link[SI]
        CALL PUTN
        ADD SI,2
        LOOP Label3
        MOV AX,OFFSET MSG25
        CALL PUT_STR

        MOV DI,enkck
        MOV AX,dizi[DI]
        CALL PUTN
        MOV AX,OFFSET MSG26
        CALL PUT_STR
        MOV AX,enkck
        CALL PUTN
        POP DI
        POP AX
        POP CX
        POP SI
        RETF
YAZDIRMA ENDP


ANA 	PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DSEG 
        MOV DS, AX
menu001:MOV AX, OFFSET MSG4
        CALL PUT_STR
        XOR SI,SI
        MOV AX, OFFSET MSG1
        CALL PUT_STR; MSG1’i göster 
        MOV AX, OFFSET MSG45
        CALL PUT_STR
        CALL GETN  			        ; N’i oku 

        CMP AX,1
        JL Nkucukdegil
        CMP AX,100
        JNA  Buyukdegil
Nkucukdegil:MOV AX, OFFSET HATA
        CALL PUT_STR
        MOV AX,OFFSET MSG3
        CALL PUT_STR
        JMP menu001
Buyukdegil:MOV N, AX
        MOV CX,N
LA1:     MOV AX, OFFSET MSG2
        CALL PUT_STR; MSG2’i göster 
        CALL GETN 			            ; SAYI2’i oku 
        CALL elemanekle
        LOOP LA1
menu0:   MENU
        MOV DX,AX
        CMP DX,4
        JE SOBN
        CMP DX,1
        JNE menu1
        JMP menu001
menu1:  CMP DX,2
        JNE menu2
        CALL YAZDIRMA
asagi:  JMP menu0
menu2:  CMP DX,3
        JNE menu4
        MOV AX,OFFSET MSG2
        CALL PUT_STR
        CALL GETN
        CALL elemanekle
        INC N
        JMP menu0
menu4:  CMP DX,4
        JE SOBN
        MOV AX,OFFSET HATA
        CALL PUT_STR
        JMP menu0
        


SOBN:    RETF
ANA 	ENDP


GETC	PROC NEAR
        ;------------------------------------------------------------------------
        ; Klavyeden basýlan karakteri AL yazmacýna alýr ve ekranda gösterir. 
        ; iþlem sonucunda sadece AL etkilenir. 
        ;------------------------------------------------------------------------
        MOV AH, 1h
        INT 21H
        RET 
GETC	ENDP 

PUTC	PROC NEAR
        ;------------------------------------------------------------------------
        ; AL yazmacýndaki deðeri ekranda gösterir. DL ve AH deðiþiyor. AX ve DX 
        ; yazmaçlarýnýn deðerleri korumak için PUSH/POP yapýlýr. 
        ;------------------------------------------------------------------------
        PUSH AX
        PUSH DX
        MOV DL, AL
        MOV AH,2
        INT 21H
        POP DX
        POP AX
        RET 
PUTC 	ENDP 

GETN 	PROC NEAR
        ;------------------------------------------------------------------------
        ; Klavyeden basýlan sayiyi okur, sonucu AX yazmacý üzerinden dondurur. 
        ; DX: sayýnýn iþaretli olup/olmadýðýný belirler. 1 (+), -1 (-) demek 
        ; BL: hane bilgisini tutar 
        ; CX: okunan sayýnýn islenmesi sýrasýndaki ara deðeri tutar. 
        ; AL: klavyeden okunan karakteri tutar (ASCII)
        ; AX zaten dönüþ deðeri olarak deðiþmek durumundadýr. Ancak diðer 
        ; yazmaçlarýn önceki deðerleri korunmalýdýr. 
        ;------------------------------------------------------------------------
        PUSH BX
        PUSH CX
        PUSH DX
GETN_START:
        MOV DX, 1	                        ; sayýnýn þimdilik + olduðunu varsayalým 
        XOR BX, BX 	                        ; okuma yapmadý Hane 0 olur. 
        XOR CX,CX	                        ; ara toplam deðeri de 0’dýr. 
NEW:
        CALL GETC	                        ; klavyeden ilk deðeri AL’ye oku. 
        CMP AL,CR 
        JE FIN_READ	                        ; Enter tuþuna basilmiþ ise okuma biter
        CMP  AL, '-'	                        ; AL ,'-' mi geldi ? 
        JNE  CTRL_NUM	                        ; gelen 0-9 arasýnda bir sayý mý?
NEGATIVE:
        MOV DX, -1	                        ; - basýldý ise sayý negatif, DX=-1 olur
        JMP NEW		                        ; yeni haneyi al
CTRL_NUM:
        CMP AL, '0'	                        ; sayýnýn 0-9 arasýnda olduðunu kontrol et.
        JB error 
        CMP AL, '9'
        JA error		                ; deðil ise HATA mesajý verilecek
        SUB AL,'0'	                        ; rakam alýndý, haneyi toplama dâhil et 
        MOV BL, AL	                        ; BL’ye okunan haneyi koy 
        MOV AX, 10 	                        ; Haneyi eklerken *10 yapýlacak 
        PUSH DX		                        ; MUL komutu DX’i bozar iþaret için saklanmalý
        MUL CX		                        ; DX:AX = AX * CX
        POP DX		                        ; iþareti geri al 
        MOV CX, AX	                        ; CX deki ara deðer *10 yapýldý 
        ADD CX, BX 	                        ; okunan haneyi ara deðere ekle 
        JMP NEW 		                ; klavyeden yeni basýlan deðeri al 
ERROR:
        MOV AX, OFFSET HATA 
        CALL PUT_STR	                        ; HATA mesajýný göster 
        JMP GETN_START                          ; o ana kadar okunanlarý unut yeniden sayý almaya baþla 
FIN_READ:
        MOV AX, CX	                        ; sonuç AX üzerinden dönecek 
        CMP DX, 1	                        ; Ýþarete göre sayýyý ayarlamak lazým 
        JE FIN_GETN
        NEG AX		                        ; AX = -AX
FIN_GETN:
        POP DX
        POP CX
        POP DX
        RET 
GETN 	ENDP 

PUTN 	PROC NEAR
        ;------------------------------------------------------------------------
        ; AX de bulunan sayiyi onluk tabanda hane hane yazdýrýr. 
        ; CX: haneleri 10’a bölerek bulacaðýz, CX=10 olacak
        ; DX: 32 bölmede iþleme dâhil olacak. Soncu etkilemesin diye 0 olmalý 
        ;------------------------------------------------------------------------
        PUSH CX
        PUSH DX 	
        XOR DX,	DX 	                        ; DX 32 bit bölmede soncu etkilemesin diye 0 olmalý 
        PUSH DX		                        ; haneleri ASCII karakter olarak yýðýnda saklayacaðýz.
                                                ; Kaç haneyi alacaðýmýzý bilmediðimiz için yýðýna 0 
                                                ; deðeri koyup onu alana kadar devam edelim.
        MOV CX, 10	                        ; CX = 10
        CMP AX, 0
        JGE CALC_DIGITS	
        NEG AX 		                        ; sayý negatif ise AX pozitif yapýlýr. 
        PUSH AX		                        ; AX sakla 
        MOV AL, '-'	                        ; iþareti ekrana yazdýr. 
        CALL PUTC
        POP AX		                        ; AX’i geri al 
        
CALC_DIGITS:
        DIV CX  		                ; DX:AX = AX/CX  AX = bölüm DX = kalan 
        ADD DX, '0'	                        ; kalan deðerini ASCII olarak bul 
        PUSH DX		                        ; yýðýna sakla 
        XOR DX,DX	                        ; DX = 0
        CMP AX, 0	                        ; bölen 0 kaldý ise sayýnýn iþlenmesi bitti demek
        JNE CALC_DIGITS	                        ; iþlemi tekrarla 
        
DISP_LOOP:
                                                ; yazýlacak tüm haneler yýðýnda. En anlamlý hane üstte 
                                                ; en az anlamlý hane en alta ve onu altýnda da 
                                                ; sona vardýðýmýzý anlamak için konan 0 deðeri var. 
        POP AX		                        ; sýrayla deðerleri yýðýndan alalým
        CMP AX, 0 	                        ; AX=0 olursa sona geldik demek 
        JE END_DISP_LOOP 
        CALL PUTC 	                        ; AL deki ASCII deðeri yaz
        JMP DISP_LOOP                           ; iþleme devam
        
END_DISP_LOOP:
        POP DX 
        POP CX
        RET
PUTN 	ENDP 

PUT_STR	PROC NEAR
        ;------------------------------------------------------------------------
        ; AX de adresi verilen sonunda 0 olan dizgeyi karakter karakter yazdýrýr.
        ; BX dizgeye indis olarak kullanýlýr. Önceki deðeri saklanmalýdýr. 
        ;------------------------------------------------------------------------
	PUSH BX 
        MOV BX,	AX			        ; Adresi BX’e al 
        MOV AL, BYTE PTR [BX]	                ; AL’de ilk karakter var 
PUT_LOOP:   
        CMP AL,0		
        JE  PUT_FIN 			        ; 0 geldi ise dizge sona erdi demek
        CALL PUTC 			        ; AL’deki karakteri ekrana yazar
        INC BX 				        ; bir sonraki karaktere geç
        MOV AL, BYTE PTR [BX]
        JMP PUT_LOOP			        ; yazdýrmaya devam 
PUT_FIN:
	POP BX
	RET 
PUT_STR	ENDP

CSEG 	ENDS 
	END ANA