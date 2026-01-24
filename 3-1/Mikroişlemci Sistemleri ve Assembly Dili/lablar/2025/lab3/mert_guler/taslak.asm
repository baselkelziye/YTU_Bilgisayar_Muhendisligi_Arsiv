STK SEGMENT PARA STACK 'STACK'
        DW 100 DUP(?)
STK ENDS

DSG SEGMENT PARA 'DATA'
	IS_PRIME_FLAG DB 0
	FACTORS DW 32 dup(0) ;32 bit isaretsiz sayinin teorik olarak tekrarli en fazla 31 adet asal carpani olabilir. (2147483648) + 1 adet ekstra 
	NUMBER_LIST DD 2, 162, 13, 997, 91, 60060, 259657, 1, 0 ; Debug amacli, veriler tamamen kullanicidan okunuyor
	NUMBERS_COUNT DW 9 ; En fazla 9 adet sayi girebilirsiniz
	FACT_COUNT DW 0
	MAX_FACTOR DD 0
    CR	EQU 13 ; GETN icin gerekli
	; Ekrana yazdirmak icin hazir veriler
	MSG_SAYI DB "Sayi: $"
	MSG_ASAL DB " - Asal$"
	MSG_ASALDEGIL DB " - Asal Degil$"
	MSG_ASALCARPANLAR DB " - Carpanlar: $"
	MSG_ENBUYUKCARPAN DB "- En Buyuk Carpan: $"
DSG ENDS

; flowchart ve videoda bu yok, yeniden video cekmeye zamanim kalmadi. Ama:
; Kodu optimize etmek icin asal kontrolunde sayi cift ise erken cikmayi ekledim

; --------------------------------------------------------------
; Kullanicidan 9 boyutunda dizi girdisi almak icin kullanilir
; 32 bitlik veri okunabilir
; -------------------------------------------------------------
READ_ARRAY MACRO
	PUSH SI
	PUSH BX
	PUSH CX

	MOV SI, 0
	LEA BX, NUMBER_LIST
	MOV CX, 9

	READ_ARRAY_LOOP:
	CALL GETN
	MOV WORD PTR [BX + SI], DX
	ADD SI, 2
	MOV WORD PTR [BX + SI], AX
	ADD SI, 2
	LOOP READ_ARRAY_LOOP

	POP CX
	POP BX
	POP SI
ENDM

; --------------------------------------------------------------
; 9 Boyutlu NUMBER_LIST dizisini elemanlar arasinda bosluk birakarak ekrana yazdirir
; 32 bitlik veri yazar
; -------------------------------------------------------------
PRINT_ARRAY MACRO
	PUSH SI
	PUSH BX
	PUSH CX

	MOV SI, 0
	LEA BX, NUMBER_LIST
	MOV CX, 9

	PRINT_ARRAY_LOOP:
	MOV  DX, WORD PTR [BX + SI]
	ADD SI, 2
	MOV  AX, WORD PTR [BX + SI]
	ADD SI, 2
	CALL PUTN
	XOR AX, AX
	CALL PUTC
	LOOP PRINT_ARRAY_LOOP

	POP CX
	POP BX
	POP SI
ENDM

; --------------------------------------------------------------
; 9 Boyutlu NUMBER_LIST dizisi icin ISPRIME, FACTORIZE, FIND_MAX_FACTOR fonksiyonlarini calistirir
; Degerleri ekrana yazar
; -------------------------------------------------------------
CALCULATE_ALL MACRO
	PUSH BX
	PUSH CX
	PUSH SI

	MOV CX, 9
	LEA BX, NUMBER_LIST
	MOV SI, 0

	; Ana dongu
	CALCULATE_ALL_LOOP:
	; DX:AX'i diziden oku
	MOV  DX, WORD PTR [BX + SI]
	ADD SI, 2
	MOV  AX, WORD PTR [BX + SI]
	ADD SI, 2

	; Sayiyi ekrana yazdir
	CALL PRINT_MSG_SAYI
	CALL PUTN

	; Asal sayi kontrolu
	CALL ISPRIME
	CMP IS_PRIME_FLAG, 1
	JE PRINT_PRIME ; Asal degilse factorize islemlerini atla

	; Kesim uzerinden aktarin denilmis, Sayi DX:AX yazmaclari ile aktarilabilirdi. Stack ile ayni islemi yaptim fakat sacma.
	PUSH AX
	PUSH DX
	CALL FACTORIZE
	POP DX
	POP AX

	; Asal carpanlari yazdirmak icin dongu baslatilacak
	PUSH BX
	PUSH CX ; Bu kisimlar erkenden kaydedilmeli yoksa ilk dongu bozulur
	PUSH SI

	; 0 veya 1 ise erkenden bitir
	MOV CX, FACT_COUNT
	CMP CX, 0
	JE ZERO_ONE_END

	LEA BX, FACTORS ; BX kaydedildi, Simdi ise asal carpanlar icin dongude kullanilacak.
	MOV SI, 0

	CALL PRINT_MSG_ASALDEGIL
	CALL PRINT_MSG_ASALCARPANLAR

	PRINT_FACTORS_LOOP:
	MOV  AX, WORD PTR [BX + SI]
	ADD SI, 2
	XOR DX, DX ; Asal carpan 16 bit olmali o yuzden DX sifirlanacak
	CALL PUTN

	XOR AX, AX
	CALL PUTC ; Bir bosluk yazdir
	LOOP PRINT_FACTORS_LOOP ; Carpanlar bitene kadar devam et
	; Asal carpanlar dongusunden cik

	; En buyuk faktoru buldur ve ekran yaz
	PRINT_MAX_FACTOR:
	CALL FIND_MAX_FACTOR ; En buyuk carpani fonksiyon
	CALL PRINT_MSG_ENBUYUKCARPAN ; Mesaj yazmak icin fonksiyon

	; En buyuk carpani ekrana yazdir
	MOV AX, WORD PTR [MAX_FACTOR]
	XOR DX, DX
	CALL PUTN
	XOR AX, AX
	CALL PUTC
	; Sifir birler icin printe girmemek adina o kismi atliyoruz
	JMP END_PRINT_FACTORS_LOOP

	ZERO_ONE_END: ; Sifir ve bir icin ozel ekrana asal degil yazisi bastir
	CALL PRINT_MSG_ASALDEGIL

	; Asal carpanlari yazdirmayi bitir
	END_PRINT_FACTORS_LOOP:
	POP SI
	POP CX
	POP BX
	; Sonraki sayi icin ilk dongunun basina don ve asallik kontrolu ile devam et. (PRINT_PRIME kismini atlamak adina)
	JMP CALCULATE_ALL_CONTINUE

	; Sayi asal ise Factorize atlandi.  Ve asal mesaji bastirildi.
	PRINT_PRIME:
	CALL PRINT_MSG_ASAL
	XOR AX, AX
	CALL PUTC

	; Ana donguye devam et
	CALCULATE_ALL_CONTINUE:
	CALL PRINT_NEWLINE
	LOOP CALCULATE_ALL_LOOP

	POP SI
	POP CX
	POP BX
	RET
ENDM

CSG SEGMENT PARA 'CODE'
	ASSUME CS:CSG, DS:DSG, SS:STK 
	
	MAIN PROC FAR
		PUSH DS
		XOR AX, AX
		PUSH AX

		MOV AX, DSG
		MOV DS, AX

		READ_ARRAY
		PRINT_ARRAY
		CALL PRINT_NEWLINE
		CALCULATE_ALL

		RETF
	MAIN ENDP

	;-----------------------------------------------------------
; 32 bit / 16 bit bolme yapar
; Girdi : DX:AX = 32 bit bolunen sayi
;          BX     = 16 bit bolen
; Cikti : DX:AX = 32 bit bolum
;          CX     = 16 bit kalan
; BX Degismez
;-----------------------------------------------------------
	DIV32 PROC NEAR
        PUSH SI
        PUSH DI    
        PUSH BX

        XOR CX, CX  
        XOR SI, SI  
        XOR DI, DI  
        MOV BP, 32 ; 32 bit bolme yapacagimiz icin indeksimiz

    DIV32_LOOP:
        ; Bolunen ve kalan sola kaydirilacak
        SHL AX, 1   ; DX:AX sola kayar
        RCL DX, 1
        RCL CX, 1   ; en yuksek biti CX e alacagiz

        ; Bolumu (DI:SI) sola kaydiracagiz
        SHL SI, 1   
        RCL DI, 1  

		; kalan bolumden yuksek ise cikaracagiz ve bolumu bir arttiracagiz
        CMP CX, BX 
        JB NO_SUB
        SUB CX, BX
        INC SI      
    NO_SUB:
        DEC BP ; Birer birer azaltiyoruz 32 bitten itibaren s
        JNZ DIV32_LOOP
		; Sonucu aktariyoruz
        MOV AX, SI  
        MOV DX, DI  

        POP BX
        POP DI     
        POP SI
        RET
    DIV32 ENDP

	; -----------------------------------------------------
    ; 32 bitlik girdinin asal sayi olup olmadigini belirler
	; GIRDI
    ; REGISTER - DX: Sayinin ust 16 biti
    ; REGISTER - AX: Sayinin alt 16 biti 
	; CIKTI
	; DATA SEGMENT - IS_PRIME_FLAG; Asallik bayragi
    ; -----------------------------------------------------
	ISPRIME PROC NEAR
		PUSH AX
		PUSH BX
		PUSH CX
		PUSH DX

		; BX bolum olarak kullanilacak. Bayragi da bir kabul edecegiz aksi olursa erken cikacagiz
		MOV BX, 3
		MOV IS_PRIME_FLAG, 1
		
		; ILK IF: N <= 2 ise erken cikacagiz. 
		CMP DX, 0
		JA CHECK_EVEN
		CMP AX, 2
		JB NOT_PRIME
		JE IS_PRIME_END

		; Sayinin son hanesi cift ise asal degildir erken cikalim
		CHECK_EVEN:
		TEST AX, 1
		JZ NOT_PRIME

		; WHILE DONGUSU: (i <= N / i) yani bolum degeri sayinin karekokunden dusuk ve esit oldugu surece devam edecegiz 
		IS_PRIME_LOOP:
		PUSH AX ; N degerini kaydet
		PUSH DX

		; WHILE KONTROLU 
		CALL DIV32
		CMP DX, 0
		JA IS_PRIME_IF
		CMP BX, AX
		JA IS_PRIME_CLEARSTACK_AND_END ; Whiledan cik BX, N / BX den daha buyuk

		IS_PRIME_IF:
		POP DX ; N degerini geri al 
		POP AX
		PUSH AX ; N degerini kaydet
		PUSH DX
		CALL DIV32 ; N % i yap
		CMP CX, 0 ; DX:AX = BX ile bolumunden kalan
		POP DX  ; N degerini geri al 
		POP AX
		JE NOT_PRIME ; Eger sayi tam bolunduyse asal degildir erken bitir.
		INC BX ; Kalan varsa boleni bir arttir donguyu devam ettir
		JMP IS_PRIME_LOOP

		; While cikisinda pop zorunlu. 
		IS_PRIME_CLEARSTACK_AND_END:
		POP DX
		POP AX
		JMP IS_PRIME_END

		; Ilk IF'de erken bitirmek icin labelimiz
		NOT_PRIME:
		MOV IS_PRIME_FLAG, 0

		IS_PRIME_END:
		POP DX
		POP CX
		POP BX
		POP AX
		RET
	ISPRIME ENDP

    ;  -----------------------------------------------------
    ; 32 bitlik asal olmayan sayinin asal bolenlerini cikarir
	; GIRDI 
    ; STACK - DX: Sayinin ust 16 biti
    ; STACK - AX: Sayinin alt 16 biti 
	; CIKTI
	; DATA SEGMENT - FACTORS: Asal carpanlar dizisi (32 boyutlu)
	; DATA SEGMENT - FACT_COUNT: Asal carpan sayisi
    ;  -----------------------------------------------------
	FACTORIZE PROC NEAR
		PUSH BP
		MOV BP, SP 
		MOV DX, [BP+4] ; Stackten DX:AX'i okuyoruz (Yazmactan da aktarilabilirdi ancak boyle istenmis)
		MOV AX, [BP+6]
		PUSH BX
		PUSH CX
		PUSH SI

		; Ana donguyu baslat
		MOV FACT_COUNT, 0
		MOV BX, 2

		FACTORIZE_LOOP:
		; Sayi ikiden kucukse zaten asal degildir. (Asal sayilar zaten bu fonksiyona girmiyor ama yine de kontrollu)
		CMP DX, 0 
		JA FACTORIZE_CONTINUE
		CMP AX, 2
		JB FACTORIZE_END

		FACTORIZE_CONTINUE:
		PUSH AX ; N degerini kaydet
		PUSH DX

		CALL DIV32
		CMP CX, 0 ; Kalan varsa BX'i (i indeksi - bolum) bir arttir
		JNE FACTORIZE_INCREMENT

		MOV CX, BX ; BX - bolum degerini gecici olarak CX'e kaydet

		LEA BX, FACTORS 
		PUSH DX ; DX'i gecici olarak stack'e kaydet
		; Diziye yazilmasi gereken indeksi hesapla
		MOV DX, FACT_COUNT 
		SHL DX, 1 
		MOV SI, DX

		MOV WORD PTR [BX + SI], CX ; Bolum degerini (gecici olarak CX'de) diziye yaz.
		MOV BX, CX
		INC FACT_COUNT ; Asal carpan sayisini arttir.
		POP DX ; DX'i geri al

		POP CX ; Iki kez bos pop etmek zorundayiz (mecburi)
		POP CX
		; Donguyu devam ettir (IF'in TRUE kolu)
		JMP FACTORIZE_LOOP
		
		; Donguyu devam ettir (IF'in FALSE kolu)
		FACTORIZE_INCREMENT:
		POP DX ; N degerini geri al
		POP AX 
		INC BX ; Bolumu bir arttir
		JMP FACTORIZE_LOOP
		
		FACTORIZE_END:
		POP SI
		POP CX
		POP BX
		POP BP
		RET
	FACTORIZE ENDP

	; -----------------------------------------------------
    ; 32 boyuttaki asal carpanlar dizisinden en buyuk asal carpani dondurur. 
	; Asal carpan yoksa sayinin kendisini dondurur
	; GIRDI
    ; REGISTER - DX: Sayinin ust 16 biti
    ; REGISTER - AX: Sayinin alt 16 biti 
	; DATASEGMENT - FACTORS: Sayinin 32 boyuttaki asal carpanlar dizisi
	; DATASEGMENT - FACT_COUNT: Sayinin asal carpan sayisi
	; CIKTI
	; DATASEGMENT - MAX_FACTOR: En buyuk asal carpan
    ; -----------------------------------------------------
	FIND_MAX_FACTOR PROC NEAR
		PUSH BX
		PUSH CX
		PUSH SI

		CMP FACT_COUNT, 0
		JE PRIME ; Asal oldugu icin MAX_FACTOR kendisi olmali

		; Dizide okunacak adresi hesapla.
		LEA BX, FACTORS
		MOV CX, FACT_COUNT
		DEC CX
		SHL CX, 1
		MOV SI, CX

		MOV CX, WORD PTR [BX + SI] ; Diziden CX'e oku.

		MOV WORD PTR [MAX_FACTOR], CX
		MOV WORD PTR [MAX_FACTOR + 2], 0 ; En fazla 16 bit olabilir fakat sayi kendisi ise MAX_FACTOR 32 bit olmalidir
		JMP FIND_MAX_FACTOR_END

		PRIME: ; MAX_FACTOR sayinin kendisidir.
		MOV WORD PTR [MAX_FACTOR], AX
		MOV WORD PTR [MAX_FACTOR + 2], DX 

		FIND_MAX_FACTOR_END:
		POP SI
		POP CX
		POP BX
		RET
	FIND_MAX_FACTOR ENDP


	; ---------------------------- HAZIR KOD ---------------------------------
    ; Klavyeden basılan karakteri AL yazmacına alır ve ekranda gösterir. 
    ; işlem sonucunda sadece AL etkilenir. 
    ; ------------------------------------------------------------------------
	GETC PROC NEAR
        MOV AH, 1h
        INT 21H
		RET
	GETC ENDP


	; -----------------------------------------------------
    ; Kullanicidan 32 bit okuma yapilir
	; GIRDI - CIKTI AYNI
    ; REGISTER - DX: Sayinin ust 16 biti
    ; REGISTER - AX: Sayinin alt 16 biti 
    ; -----------------------------------------------------
	GETN PROC NEAR
        PUSH BX
        PUSH CX
	GETN_START:
        XOR BX, BX 	                     
        XOR CX,CX	                       
		XOR DX, DX
		XOR AX, AX
	;  Yeni deger okumak icin dongu
	NEW: 
        CALL GETC	                     
        CMP AL,CR ; Enter girildiyse sonlandir.
        JE RESTORE_AX	                   
	CTRL_NUM:
        SUB AL,'0'	 ; Al'i asciiye cevir            
        MOV BL, AL	  ; Basamagi BL ye yaz.                  

		; DX:AX 32 bit olarak 10 ile carpilip basmak hesabi yapilacak
		MOV AX, CX ; Gecici olarak kaydedilen AX'i kendi yerine yaz. (CX de gecici olarak bulunuyor - dongunun sonunda)
		MOV CX, 10 ; Carpim icin CX'e 10 yaz
		PUSH AX ; AX'i gecici olarak stackte kaydet
		MOV AX, DX ; DX ilk carpilmak zorunda. AX buradan sonra = DX
		MUL CX ; AX (DX) i 10 ile carp.
		POP DX ; AX i geri al. (Carpim sonucunu kaybetmemek icin DX e yazmak zorundayiz)
		PUSH AX ; Carpim sonucunu stack'e et
		MOV AX, DX ; AX, i tekrardan kendi yerine yaz
		MUL CX ; AX'i 10 ile carp
		POP CX ; DX'i CX olarak al
		ADD CX, DX ; DX + DX yap. CX burada eski DX.
		MOV DX, CX ; DX'i kendi yazmacina aktar

        ADD AX, BX  ; Basamak degerini AX'e ekle.
		ADC DX, 0  ; Carry varsa DX'e ekle
		MOV CX, AX ; AX'i gecici olarak CX kaydet   
        JMP NEW 	; Yeni inputu al
	RESTORE_AX:
		MOV AX, CX	; ENTER girildiyse AX'i geri al.                                         
	FIN_GETN:
        POP CX
        POP BX
		RET
	GETN ENDP

	; ---------------------------- HAZIR KOD ---------------------------------
    ; AL yazmacındaki değeri ekranda gösterir. DL ve AH değişiyor. AX ve DX 
    ; yazmaçlarının değerleri korumak için PUSH/POP yapılır. 
    ; ------------------------------------------------------------------------
	PUTC	PROC NEAR

        PUSH AX
        PUSH DX
        MOV DL, AL
        MOV AH,2
        INT 21H
        POP DX
        POP AX
		RET
	PUTC ENDP

	;------------------------------------------------------------------------
    ; DX:AX de bulunan 32 bitlik sayiyi onluk tabanda hane hane yazdırır. 
    ;------------------------------------------------------------------------
	PUTN PROC NEAR
		PUSH AX
        PUSH BX
        PUSH CX
		PUSH DX	

        XOR CX,	CX 	; Yazma dursun diye stack'e 0 atalim  
        PUSH CX		
        MOV BX, 10	; Basamak bolucu
CALC_DIGITS:
		CALL DIV32   ; 32 bit bolme yapacagiz          
        ADD CX, '0'	  ; Kalani ASCIIye ceviriyoruz                    
        PUSH CX		; Kalani Stack'e kaydedelim                   
        XOR CX,CX  ; Kalani sifirla
		; Sayi sifir degil ise devam et. 0 olana kadar devam et     
        CMP DX, 0
		JNE CALC_DIGITS
		CMP AX, 0
		JNE CALC_DIGITS                       
DISP_LOOP:
        POP AX ; Stack'e attigimiz basamaklari tek tek ekrana yazalim. push ettigimiz 0 a denk gelene kadar devam et                 
        CMP AX, 0 	                   
        JE END_DISP_LOOP 
        CALL PUTC 	                   
        JMP DISP_LOOP                      
END_DISP_LOOP:
		POP DX
        POP CX 
        POP BX
		POP AX
		RET
PUTN ENDP 

; Ekran yazdirmak icin fonksiyonlar
; Ana kodda daha az pop push olmasi icin parametre aktarimi yerine her biri icin ayri fonksiyon yazdim

PRINT_NEWLINE PROC NEAR
	PUSH AX 
	MOV AX, 0DH
	CALL PUTC 
	MOV AX, 0AH
	CALL PUTC
	POP AX
	RET
PRINT_NEWLINE ENDP

PRINT_MSG PROC NEAR
	PUSH AX
    MOV AH, 9
    INT 21h
	POP AX
	RET	
PRINT_MSG ENDP

PRINT_MSG_SAYI PROC NEAR
	PUSH DX
	LEA DX, MSG_SAYI
	CALL PRINT_MSG
	POP DX
	RET
PRINT_MSG_SAYI ENDP

PRINT_MSG_ASALCARPANLAR PROC NEAR
	PUSH DX
	LEA DX, MSG_ASALCARPANLAR 
	CALL PRINT_MSG
	POP DX
	RET
PRINT_MSG_ASALCARPANLAR ENDP

PRINT_MSG_ASAL PROC NEAR
	PUSH DX
	LEA DX, MSG_ASAL
	CALL PRINT_MSG
	POP DX
	RET
PRINT_MSG_ASAL ENDP

PRINT_MSG_ASALDEGIL PROC NEAR
	PUSH DX
	LEA DX, MSG_ASALDEGIL
	CALL PRINT_MSG
	POP DX
	RET
PRINT_MSG_ASALDEGIL ENDP

PRINT_MSG_ENBUYUKCARPAN PROC NEAR
	PUSH DX
	LEA DX, MSG_ENBUYUKCARPAN
	CALL PRINT_MSG
	POP DX
	RET
PRINT_MSG_ENBUYUKCARPAN ENDP

CSG ENDS
	END MAIN