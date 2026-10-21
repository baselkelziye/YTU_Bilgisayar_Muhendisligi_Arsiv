
SSEG 	SEGMENT PARA STACK 'STACK'
	DW 32 DUP (?)
SSEG 	ENDS

DSEG	SEGMENT PARA 'DATA'
SAYILAR  DW 20 DUP (?) 
N DW ?
MOD_RESULT DW ? ;stores the mod of the array
MOD_FREQ DW ? ;stores the frequency of the mod 
CR	EQU 13
LF	EQU 10
MSG1	DB 'kac sayi gireceksiniz (Maksimum 20): ',0
MSG2	DB CR, LF, 'sayiyi giriniz: ', 0
HATA	DB CR, LF, 'Dikkat !!! Sayi vermediniz yeniden girin.!!!  ', 0
SONUC_MOD	DB CR, LF, 'Mod: ', 0
SONUC_SIKLIK DB CR, LF, 'Frequency: ', 0

DSEG 	ENDS 

CSEG SEGMENT PARA 'CODE'
	ASSUME CS:CSEG, DS:DSEG, SS:SSEG

    GIRIS_DIZI MACRO
        LOCAL L1 
        PUSH BP ;preserving the value of BP

        MOV BP, SP ;setting the BP to SP to get the parameters
        MOV SI, [BP + 2] ;setting SI to the array's offset
        MOV CX, [BP + 4] ;setting CX to the size of the array
    L1:
        MOV AX, OFFSET MSG2
        CALL PUT_STR ; showing MSG2
        CALL GETN ;Get the number
        MOV [SI], AX ;loading the number in AX to array
        ADD SI, 2
        LOOP L1
        
        POP BP ;getting the value of BP before macro
    ENDM

    ANA PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DSEG 
        MOV DS, AX

        ;code
	MOV AX, OFFSET MSG1 ;loading msg1 to AX
   NOTINRANGE:
        CALL PUT_STR ;showing MSG1 by giving AX as a parameter 
        CALL GETN    ;reading N (size of the array)
        CMP AX, 20   ;if N should be in range (0, 20]
        JA NOTINRANGE
        CMP AX, 0
        JBE NOTINRANGE
        MOV N, AX ;GETN returns AX so we load the value to N

        PUSH N ;pushing N to stack to give it to the macro as parameter
        LEA BX, SAYILAR ;fetching the array's offset to BX
        PUSH BX ;pushing BX to stack to give the array offset to the macro as parameter
        GIRIS_DIZI ;using the macro GIRIS_DIZI to get the array with size N
        ADD SP, 4 ;cleaning the two variables in the stack after GIRIS_DIZI is finished 
        
        PUSH MOD_FREQ ;pushing the frequency of the mod stored in the DS to MOD_BUL as parameter 
        PUSH MOD_RESULT ;pushing the mod stored in the DS to give it to MOD_BUL as parameter
        PUSH N ;pushing N to stack to give it to MOD_BUL as parameter
        LEA BX, SAYILAR 
        PUSH BX ;pushing BX to stack to give the array offset to MOD_BUL as parameter
        CALL MOD_BUL 
        POP MOD_RESULT ;MOD_BUL cleans the first two variables and returns the last two so we load the first one to MOD_RESULT
        POP MOD_FREQ ;load the other one to mod frequency
        
        MOV AX, OFFSET SONUC_MOD
        CALL PUT_STR 
        MOV AX, MOD_RESULT 
        CALL PUTN ;showing the mod of the array
        MOV AX, OFFSET SONUC_SIKLIK
        CALL PUT_STR
        MOV AX, MOD_FREQ
        CALL PUTN ;showing the frequency of the mod 
        RETF 
    ANA ENDP

    MOD_BUL PROC NEAR ;it takes SAYILAR, N and MOD_RESULT as parameter and returns MOD_RESULT in the stack
        PUSH CX ;preserving the values of the register before the function
        PUSH AX
        PUSH BX
        PUSH SI
        PUSH DI 
        PUSH BP 

        MOV BP, SP ;setting the BP to SP to get the parameters
        MOV BX, [BP + 14] ;setting BX to the array's offset
        XOR DX, DX
        MOV CX, [BP + 16] ;setting CX to the size of the array
        DEC CX ;decrement CX to make the outer loop iterates N-1 times
        XOR SI, SI
        XOR DI, DI
        CMP CX, 0 ;if there is one element we can simply return the first element and also frequency as 1
        JE ONEELEMENT
    L1:
        PUSH CX ;preserving CX of outer loop
        MOV DX, [BX + SI] ;getting SAYILAR[SI]
        MOV DI, SI 
        ADD DI, 2 ;setting DI to look at the elements after SI
        XOR AL, AL ;this will store the frequency of SAYILAR[SI]
        INC AL ;starting the counter at 1
    L2:
        CMP DX, [BX + DI] ;if the element is equal to DX then we can increment the counter AL
        JNE PASS
        INC AL
    PASS:
        ADD DI, 2
        LOOP L2 ;inner loop iterates N - I - 1 times
        POP CX ;getting CX of the outer loop
        CMP AL, AH ;AH stores the max frequency so if AL gets bigger then it, we should update it
        JBE NOTABOVE
        MOV AH, AL ;updating AH
        MOV [BP + 18], DX ;updating the parameter for mod in the stack since DX stores the possible mod
    NOTABOVE:
        ADD SI, 2
        LOOP L1
        MOV [BP + 20], AH ;after the loops we can write the frequency of the mod to the MOD_FREQ in the DS
        JMP CONT

    ONEELEMENT: ;one element situation
        MOV DX, [BX + SI]   
        MOV [BP + 18], DX 
        MOV WORD PTR [BP + 20], 1
    CONT: 
        POP BP ;getting the values of the register before the function call
        POP DI
        POP SI
        POP BX
        POP AX
        POP CX

        RET 4 ;cleaning the two parameters in the stack and returning the last one as return
    MOD_BUL ENDP

    GETC	PROC NEAR
        ;------------------------------------------------------------------------
        ; Klavyeden basılan karakteri AL yazmacına alır ve ekranda gösterir. 
        ; işlem sonucunda sadece AL etkilenir. 
        ;------------------------------------------------------------------------
        MOV AH, 1h
        INT 21H
        RET 
GETC	ENDP 

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

PUT_STR	PROC NEAR
        ;------------------------------------------------------------------------
        ; AX de adresi verilen sonunda 0 olan dizgeyi karakter karakter yazdırır.
        ; BX dizgeye indis olarak kullanılır. Önceki değeri saklanmalıdır. 
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
        JMP PUT_LOOP			        ; yazdırmaya devam 
PUT_FIN:
	POP BX
	RET 
PUT_STR	ENDP

CSEG 	ENDS 
	END ANA
