DATASEG SEGMENT PARA 'DATASG'
    SAYILAR     DW 10 DUP(0)
    N           DW 0
    SAYILAR_MOD DW 0            ; Sayilar dizisinin mod degeri
    MAX         DW 0            ; MODBUL fonksiyonunda kullanılan maksimum tekrar eden sayiyi tutan degisken
    CR	        EQU 13
    LF	        EQU 10
    MSG1	DB CR, LF, 'Dizinin eleman sayisini giriniz (1 <= N <= 10): ', 0
    MSG2	DB CR, 'Sayi giriniz: ', 0
    MSG3	DB CR, LF, 'Dizinin modu: ', 0
    HATA	DB CR, LF, 'Dikkat !!! Sayi vermediniz yeniden giris yapiniz.!!!  ', 0    
DATASEG ENDS

STACKSEG SEGMENT PARA STACK 'STACKSG'
    DW 40 DUP(?)
STACKSEG ENDS

CODESEG SEGMENT PARA 'CODESG'
    ASSUME CS:CODESEG, DS:DATASEG, SS:STACKSEG

    GIRIS_DIZI MACRO ELEMAN_SAYISI
        LOCAL BOYUT_AL, SAYI_AL
BOYUT_AL:        
        MOV AX, OFFSET MSG1
        CALL PUT_STR            ; 'Dizinin eleman sayisini giriniz: '
        CALL GETN               ; Kullanicidan eleman sayisi alinir.
        CMP AX, 1               ; Eleman sayisi 1'den kucukse tekrar alinir.
        JB BOYUT_AL             
        CMP AX, 10              ; Eleman sayisi 10'dan buyukse tekrar alinir.
        JA BOYUT_AL

        MOV ELEMAN_SAYISI, AX   ; Verilen degiskene eleman sayisi yazilir.
        MOV CX, AX
        XOR SI, SI
SAYI_AL:                        ; Eleman sayisi kadar eleman alinir.
        MOV AX, OFFSET MSG2
        CALL PUT_STR            ; 'Sayi giriniz: '
        CALL GETN               ; Kullanicidan sayi alinir.
        MOV SAYILAR[SI], AX
        ADD SI, 2
        LOOP SAYI_AL
    ENDM

    MAIN PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, DATASEG
        MOV DS, AX

        GIRIS_DIZI N            ; MACRO ile N ve SAYILAR dizisi alinir.

        PUSH N                  ; Fonksiyona parametre olarak dizi boyutu stack ile gonderilir.
        CALL MODBUL
        POP SAYILAR_MOD         ; Fonksiyondan dizinin mod degeri stack ile alinir.

        MOV AX, OFFSET MSG3     ; 'Dizinin modu: '
        CALL PUT_STR
        MOV AX, SAYILAR_MOD     ; Mod degeri ekrana bastirilir.
        CALL PUTN
        RETF
    MAIN ENDP

    MODBUL  PROC NEAR
        PUSH AX                 ; AX = modu bulanacak sayi
        PUSH BX                 ; BX = mod 
        PUSH CX                 ; CX = N
        PUSH DX                 ; DX = modun kac kez bulundugu
        PUSH SI                 ; SI = i
        PUSH DI                 ; DI = j
        PUSH BP

        MOV BP, SP              
        MOV CX, [BP + 16]       ; CX = N, Dizinin boyutu stackten alinir.
        ADD CX, CX              ; Dizinin boyutu word oldugu icin ikiyle carpilir.
        XOR BX, BX              ; BX = 0
        XOR SI, SI              ; SI = 0 (i = 0)

loop1:  MOV AX, SAYILAR[SI]     ; AX'e siradaki eleman atilir.
        XOR DX, DX              ; DX, AX'teki elemandan kac tane oldugunu tutar.
        MOV DI, SI              ; DI = SI (j = i)

loop2:  CMP AX, SAYILAR[DI]     ; AX'ten itibaren sonraki degerler AX'le karsilastirilir.
        JNE farkli
        INC DX                  ; Ayni ise DX arttirilir.
farkli: ADD DI, 2
        CMP DI, CX              ; DI, CX'ten kucuk oldugu surece dongu devam eder.
        JB loop2

        CMP DX, MAX             ; DX, MAX'tan buyuk ise su ana kadarki en cok tekrar eden eleman guncellenir.
        JBE kucuk
        MOV MAX, DX
        MOV BX, AX

kucuk:  ADD SI, 2
        CMP SI, CX              ; SI, CX'ten kucuk oldugu surece dongu devam eder.
        JB loop1
        MOV [BP + 16], BX 

        POP BP
        POP DI
        POP SI
        POP DX
        POP CX
        POP BX
        POP AX
        RET
    MODBUL  ENDP

    GETN 	PROC NEAR
        ;------------------------------------------------------------------------
        ; Klavyeden basılan sayiyi okur, sonucu AX yazmacı üzerinden dondurur. 
        ; DX: sayının işaretli olup/olmadığını belirler. 1 (+), -1 (-) demek 
        ; BL: hane bilgisini tutar 
        ; CX: okunan sayının islenmesi sırasındaki ara değeri tutar. 
        ; AL: klavyeden okunan karakteri tutar (ASCII)
        ; AX zaten dönüş değeri olarak değişmek durumundadır. Ancak diğer 
        ; yazmaçların önceki değerleri korunmalıdır. 
        ;------------------------------------------------------------------------
        PUSH BX
        PUSH CX
        PUSH DX
GETN_START:
        MOV DX, 1	                        ; sayının şimdilik + olduğunu varsayalım 
        XOR BX, BX 	                        ; okuma yapmadı Hane 0 olur. 
        XOR CX,CX	                        ; ara toplam değeri de 0’dır. 
NEW:
        CALL GETC	                        ; klavyeden ilk değeri AL’ye oku. 
        CMP AL,CR 
        JE FIN_READ	                        ; Enter tuşuna basilmiş ise okuma biter
        CMP  AL, '-'	                        ; AL ,'-' mi geldi ? 
        JNE  CTRL_NUM	                        ; gelen 0-9 arasında bir sayı mı?
NEGATIVE:
        MOV DX, -1	                        ; - basıldı ise sayı negatif, DX=-1 olur
        JMP NEW		                        ; yeni haneyi al
CTRL_NUM:
        CMP AL, '0'	                        ; sayının 0-9 arasında olduğunu kontrol et.
        JB error 
        CMP AL, '9'
        JA error		                ; değil ise HATA mesajı verilecek
        SUB AL,'0'	                        ; rakam alındı, haneyi toplama dâhil et 
        MOV BL, AL	                        ; BL’ye okunan haneyi koy 
        MOV AX, 10 	                        ; Haneyi eklerken *10 yapılacak 
        PUSH DX		                        ; MUL komutu DX’i bozar işaret için saklanmalı
        MUL CX		                        ; DX:AX = AX * CX
        POP DX		                        ; işareti geri al 
        MOV CX, AX	                        ; CX deki ara değer *10 yapıldı 
        ADD CX, BX 	                        ; okunan haneyi ara değere ekle 
        JMP NEW 		                ; klavyeden yeni basılan değeri al 
ERROR:
        MOV AX, OFFSET HATA 
        CALL PUT_STR	                        ; HATA mesajını göster 
        JMP GETN_START                          ; o ana kadar okunanları unut yeniden sayı almaya başla 
FIN_READ:
        MOV AX, CX	                        ; sonuç AX üzerinden dönecek 
        CMP DX, 1	                        ; İşarete göre sayıyı ayarlamak lazım 
        JE FIN_GETN
        NEG AX		                        ; AX = -AX
FIN_GETN:
        POP DX
        POP CX
        POP DX
        RET 
    GETN 	ENDP 

    GETC	PROC NEAR
        ;------------------------------------------------------------------------
        ; Klavyeden basılan karakteri AL yazmacına alır ve ekranda gösterir. 
        ; işlem sonucunda sadece AL etkilenir. 
        ;------------------------------------------------------------------------
        MOV AH, 1h
        INT 21H
        RET 
    GETC	ENDP

    PUT_STR	PROC NEAR
        ;------------------------------------------------------------------------
        ; AX de adresi verilen sonunda 0 olan dizgeyi karakter karakter yazdırır.
        ; BX dizgeye indis olarak kullanılır. Önceki değeri saklanmalıdır. 
        ;------------------------------------------------------------------------
	    PUSH BX 
        MOV BX,	AX			            ; Adresi BX’e al 
        MOV AL, BYTE PTR [BX]	                ; AL’de ilk karakter var 
PUT_LOOP:   
        CMP AL,0		
        JE  PUT_FIN 			        ; 0 geldi ise dizge sona erdi demek
        CALL PUTC 			        ; AL’deki karakteri ekrana yazar
        INC BX 				        ; bir sonraki karaktere geç
        MOV AL, BYTE PTR [BX]
        JMP PUT_LOOP			        ; yazdırmaya devam 
PUT_FIN:
	    POP BX
	    RET 
    PUT_STR	ENDP

    PUTC	PROC NEAR   
        ;------------------------------------------------------------------------
        ; AL yazmacındaki değeri ekranda gösterir. DL ve AH değişiyor. AX ve DX 
        ; yazmaçlarının değerleri korumak için PUSH/POP yapılır. 
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

    PUTN 	PROC NEAR
        ;------------------------------------------------------------------------
        ; AX de bulunan sayiyi onluk tabanda hane hane yazdırır. 
        ; CX: haneleri 10’a bölerek bulacağız, CX=10 olacak
        ; DX: 32 bölmede işleme dâhil olacak. Soncu etkilemesin diye 0 olmalı 
        ;------------------------------------------------------------------------
        PUSH CX
        PUSH DX 	
        XOR DX,	DX 	                        ; DX 32 bit bölmede soncu etkilemesin diye 0 olmalı 
        PUSH DX		                        ; haneleri ASCII karakter olarak yığında saklayacağız.
                                                ; Kaç haneyi alacağımızı bilmediğimiz için yığına 0 
                                                ; değeri koyup onu alana kadar devam edelim.
        MOV CX, 10	                        ; CX = 10
        CMP AX, 0
        JGE CALC_DIGITS	
        NEG AX 		                        ; sayı negatif ise AX pozitif yapılır. 
        PUSH AX		                        ; AX sakla 
        MOV AL, '-'	                        ; işareti ekrana yazdır. 
        CALL PUTC
        POP AX		                        ; AX’i geri al 
        
CALC_DIGITS:
        DIV CX  		                ; DX:AX = AX/CX  AX = bölüm DX = kalan 
        ADD DX, '0'	                        ; kalan değerini ASCII olarak bul 
        PUSH DX		                        ; yığına sakla 
        XOR DX,DX	                        ; DX = 0
        CMP AX, 0	                        ; bölen 0 kaldı ise sayının işlenmesi bitti demek
        JNE CALC_DIGITS	                        ; işlemi tekrarla 
        
DISP_LOOP:
                                                ; yazılacak tüm haneler yığında. En anlamlı hane üstte 
                                                ; en az anlamlı hane en alta ve onu altında da 
                                                ; sona vardığımızı anlamak için konan 0 değeri var. 
        POP AX		                        ; sırayla değerleri yığından alalım
        CMP AX, 0 	                        ; AX=0 olursa sona geldik demek 
        JE END_DISP_LOOP 
        CALL PUTC 	                        ; AL deki ASCII değeri yaz
        JMP DISP_LOOP                           ; işleme devam
        
END_DISP_LOOP:
        POP DX 
        POP CX
        RET
    PUTN 	ENDP 
CODESEG ENDS
    END MAIN