STK SEGMENT PARA STACK 'STACK'
        DW 256 DUP(?)
STK ENDS

DSG SEGMENT PARA 'DATA'
    NUMBER_LIST DW 100 DUP (0)
    NUMBER_COUNT DW 0
    KEY DW 0
    RESULT_INDEX DW -1
    IS_SORTED_FLAG DB 0
    MSG_INFO DB "Girdiginiz dizi artan (tekrarsiz), boyutu 2-100 olmalidir! Boyut Girin: $"
    MSG_GIRDI DB "Girdi: $"
    MSG_SIRALI DB "Dizi Sirali!$"
    MSG_SIRASIZ DB "Dizi Sirasiz! Cikiliyor...$"
    MSG_ARANACAK_SAYI DB "Aranacak Sayi: $"
    MSG_SONUC DB "Bulunan Index: $"
    CR	EQU 13
DSG ENDS

READ_ARRAY MACRO
	PUSH SI
	PUSH BX
	PUSH CX
    PUSH DX

	MOV SI, 0
	LEA BX, NUMBER_LIST
	MOV CX, NUMBER_COUNT

	READ_ARRAY_LOOP:
    MOV DX, OFFSET MSG_GIRDI
    CALL PRINT_MSG

	CALL GETN
	MOV WORD PTR [BX + SI], AX
	ADD SI, 2
	LOOP READ_ARRAY_LOOP

    POP DX
	POP CX
	POP BX
	POP SI
ENDM

PRINT_ARRAY MACRO
	PUSH SI
	PUSH BX
	PUSH CX

	MOV SI, 0
	MOV BX, OFFSET NUMBER_LIST
	MOV CX, NUMBER_COUNT

	PRINT_ARRAY_LOOP:
	MOV  AX, WORD PTR [BX + SI]
	ADD SI, 2
	CALL PUTN
	MOV AL, ' '
	CALL PUTC
	LOOP PRINT_ARRAY_LOOP

	POP CX
	POP BX
	POP SI
ENDM

CSG SEGMENT PARA 'CODE'
	ASSUME CS:CSG, DS:DSG, SS:STK 
	
	MAIN PROC FAR
		PUSH DS
		XOR AX, AX
		PUSH AX
		MOV AX, DSG
		MOV DS, AX

        ; Diziyi kullanicidan oku. 2-100 boyut ve sayilar tekrar ederse sirasiz sayilir.
        SIZE_LOOP:
        MOV DX, OFFSET MSG_INFO
        CALL PRINT_MSG
        CALL GETN
        CMP AX, 100
        JA SIZE_LOOP
        CMP AX, 2
        JB SIZE_LOOP
        MOV NUMBER_COUNT, AX
        
        READ_ARRAY
        CALL PRINT_NEWLINE
        PRINT_ARRAY
        CALL PRINT_NEWLINE

        ; Is_sorted parametreleri
        XOR AX, AX
        PUSH AX ; Geri donus degeri icin yer ayir. 
        MOV AX, OFFSET NUMBER_LIST
        PUSH AX 
        PUSH NUMBER_COUNT

        CALL IS_SORTED

        POP AX ; Geri donus degeri
        MOV IS_SORTED_FLAG, AL ; Dataya yaz ama neden istendi bilmiyorum zaten stackle aktariliyor
        CMP IS_SORTED_FLAG, 1
        JE PRINT_SIRALI 

        ; Dizi sirasiz. Print et ve cik.
        MOV DX, OFFSET MSG_SIRASIZ
        CALL PRINT_MSG
        JMP END_MAIN

        PRINT_SIRALI:
        MOV DX, OFFSET MSG_SIRALI
        CALL PRINT_MSG

        ; Binary Search
        SEARCH_LOOP:
        ; Aranacak sayi mesajini yazdir
        CALL PRINT_NEWLINE
        MOV DX, OFFSET MSG_ARANACAK_SAYI
        CALL PRINT_MSG

        CALL GETN
        CMP AX, 'q'
        JE END_MAIN

        MOV BX, OFFSET NUMBER_LIST 
        XOR CX, CX ; Low
        MOV DX, NUMBER_COUNT
        DEC DX ; High

        PUSH CX ; Geri Donus Degeri icin yer ayir
        PUSH BX ; Number list
        PUSH CX ; low
        PUSH DX ; high
        PUSH AX ; key
        CALL BINARY_SEARCH

        ; Sonucu yazdir
        MOV DX, OFFSET MSG_SONUC
        CALL PRINT_MSG
        POP AX
        MOV RESULT_INDEX, AX ; Dataya yaz ama neden istendi bilmiyorum zaten stackle aktariliyor
        CALL PUTN
        ; Devam et
        JMP SEARCH_LOOP

        END_MAIN:

		RETF
	MAIN ENDP

    ; Girdi : [SP + 2] = Dizinin Baslangic Adresi (Offset)
    ;         [SP + 4] = Dizi Eleman Sayisi (Count)
    ;
    ; Cikti : [SP + 6] = Sonuc (Word)
    ;                  1 = Dizi Sirali
    ;                  0 = Dizi Sirasiz
    ;
    ; Not : Esit elemanlar sirayi bozar (Orn: 1, 2, 2 = Artan degil)
    ;-----------------------------------------------------------
    IS_SORTED PROC NEAR
        PUSH BP
        MOV BP, SP 
        PUSH AX
        PUSH BX
        PUSH CX
        PUSH DX
        PUSH SI

		MOV CX, [BP+4] ; Number Count
		MOV BX, [BP+6] ; Number List
        DEC CX ; I <= N - 1 oldugu surece devam etmesi icin
        XOR SI, SI

        MOV AX, [BX + SI] ; Ilk degeri oku

        IS_SORTED_LOOP:
        ADD SI, 2
        MOV DX, [BX + SI] ; Ikinci degeri oku
        CMP AX, DX ; Buyuk ve esitse artan degildir.
        JAE NOT_SORTED
        MOV AX, DX ; Ikinci degeri dongunun devaminda ilk deger olarak al
        LOOP IS_SORTED_LOOP

        MOV WORD PTR [BP+8], 1 ; Geri donus degerini, Sirali: 1 yaz
        JMP END_IS_SORTED

        NOT_SORTED:
        MOV WORD PTR [BP+8], 0 ; Geri donus degerini, Sirasiz: 0 yaz

        END_IS_SORTED:
        POP SI
        POP DX
        POP CX
        POP BX
        POP AX
        POP BP
        RET 4
    IS_SORTED ENDP

    ; Girdi : [SP + 8] = Dizinin Baslangic Adresi (Offset)
    ;         [SP + 6]  = Alt Sinir Indexi (Low)
    ;         [SP + 4]  = Ust Sinir Indexi (High)
    ;         [SP + 2]  = Aranan Sayi (Key)
    ;
    ; Cikti : [SP + 10] = Bulunan Index (Word)
    ;                   0..N-1 = Sayinin bulundugu index
    ;                   -1     = Sayi bulunamadi
    ;-----------------------------------------------------------
    BINARY_SEARCH PROC NEAR
        PUSH BP
        MOV BP, SP 
        PUSH AX
        PUSH BX
        PUSH CX
        PUSH DX
        PUSH SI
        PUSH DI

		MOV CX, [BP+8] ; low
		MOV BX, [BP+6] ; high
        XOR DX, DX
        XOR SI, DX

        CMP BX, CX ; High >= Low degilse -1 dondur.
        JL RETURN_NOT_FOUND

        ; Mid hesapla
        MOV AX, BX ; High
        SUB AX, CX ; High - Low
        SHR AX, 1; (High - Low) / 2
        ADD AX, CX ; Low + (High - Low) / 2 = MID

        MOV SI, AX ; mid
        MOV DI, AX 
        SHL DI, 1 ; Mid * 2 (Word indexine donustur)
        MOV BX, [BP+10] ;  BX = Number_list'in adresi
        MOV AX, [BX+DI] ; AX = NUMBER_LIST[MID]
        MOV DX, [BP+4] ; DX = X

        CMP AX, DX 
        JE RETURN_MID ; Bulundu ise
        JA CALL_LEFT ; NUMBER_LIST[MID] > X, Dizinin sol tarafi ile binary search

        ; Dizinin sag tarafi ile binary search
        XOR DI, DI
        PUSH DI ; geri donus degeri icin bos yer ac
        PUSH BX 
        INC SI 
        PUSH SI ; Low = mid + 1
        MOV BX, [BP+6] ; High degerini stackten oku
        PUSH BX  ; High'i at
        PUSH DX ; X degeri hep DX'de
        CALL BINARY_SEARCH
        POP AX ; Geri donus degerini al
        MOV [BP+12], AX ; Geri donus degerini onceki ayirilmis geri donus degerine yaz
        JMP END_BINARY_SEARCH

        CALL_LEFT:
        XOR DI, DI
        PUSH DI  ; geri donus degeri icin bos yer ac

        PUSH BX ; Number_list'in adresini at
        PUSH CX ; Low degimedi, at
        DEC SI
        PUSH SI ; High = mid - 1
        PUSH DX ; X degismedi, at
        CALL BINARY_SEARCH
        POP AX ; Geri donus degerini al
        MOV [BP+12], AX ; Geri donus degerini onceki ayirilmis geri donus degerine yaz
        JMP END_BINARY_SEARCH

        RETURN_MID:
        MOV [BP+12], SI ; SI = MID, deger bulundu ise mid dondur
        JMP END_BINARY_SEARCH

        RETURN_NOT_FOUND:
        MOV WORD PTR [BP+12], -1 ; Deger bulunamadi ise -1 dondur

        END_BINARY_SEARCH:
        POP DI
        POP SI
        POP DX
        POP CX
        POP BX
        POP AX
        POP BP
        RET 8
    BINARY_SEARCH ENDP

	GETC PROC NEAR
        MOV AH, 1h
        INT 21H
		RET
	GETC ENDP

	GETN PROC NEAR
        PUSH BX
        PUSH CX
        PUSH DX
        
        GETN_START:
        XOR BX, BX             
        XOR CX, CX             
        NEW:
        CALL GETC               
        CMP AL, 'q'          
        JE RETURN_Q          
        CMP AL, CR              
        JE FIN_READ           
        CMP AL, '0'
        JB NEW                  
        CMP AL, '9'
        JA NEW            
        CTRL_NUM:
        SUB AL, '0'            
        MOV BL, AL             
        MOV BH, 0              
        MOV AX, 10
        MUL CX                 
        MOV CX, AX              
        ADD CX, BX          
        JMP NEW              
        FIN_READ:
        MOV AX, CX             
        JMP POP_EXIT        
        RETURN_Q:
        MOV AH, 0     
        MOV AL, 'q'          
        POP_EXIT:
        POP DX
        POP CX
        POP BX
        RET 
    GETN ENDP   

	PUTC PROC NEAR
        PUSH AX
        PUSH DX
        MOV DL, AL
        MOV AH,2
        INT 21H
        POP DX
        POP AX
		RET
	PUTC ENDP

	PUTN PROC NEAR
        PUSH CX
        PUSH DX 	
        XOR DX,	DX 	                      
        PUSH DX		                     
        MOV CX, 10	                   
        CMP AX, 0
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
        CMP AX, 0	                        
        JNE CALC_DIGITS	                       
        DISP_LOOP:
        POP AX		                        
        CMP AX, 0 	                        
        JE END_DISP_LOOP 
        CALL PUTC 	                       
        JMP DISP_LOOP                           
        END_DISP_LOOP:
        POP DX 
        POP CX
        RET
        PUTN 	ENDP 

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

CSG ENDS
	END MAIN