STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS

DTSG SEGMENT PARA 'DTSG' 
    SAYILAR db 10 DUP (?)
    n db ? 
    MaxCount db ?              ; max tekrarlanmayi tutan degisken
    Mode db ?                  ; en cok tekrar eden degeri yani mod'u tutan degisken
    CR	EQU 13
    LF	EQU 10
    MSG1	DB 'dizinin boyutunu giriniz: ',0
    MSG2	DB CR, LF, 'eleman giriniz: ', 0
    HATA	DB CR, LF, 'Sayi vermediniz yeniden giris yapiniz!  ', 0
    SONUC	DB CR, LF, 'Mod:  ', 0
    
DTSG ENDS

CDSG SEGMENT PARA 'CDSGM'
	ASSUME CS: CDSG, DS: DTSG, SS: STSG
GIRIS_DIZI macro
    PUSH BP
    MOV BP, SP
    
    MOV AX, OFFSET MSG1
    CALL PUT_STR
    CALL GETN
    mov cx, ax
    mov n, al
    
    PUSH CX            ; array'e kaç tane eleman yazilacagini stack'e pushla
    
    xor si, si
giris:
    PUSH CX            ; counter'i pushla
    MOV AX, OFFSET MSG2
    CALL PUT_STR
    CALL GETN
    mov [SAYILAR + si], al
    inc si
    POP CX             ; counter'i popla
    loop giris
    
    POP CX
    POP BP
    endm

ANA PROC FAR
    PUSH DS
    XOR AX, AX
    PUSH AX

    MOV AX, DTSG
    MOV DS, AX
    
    GIRIS_DIZI         ; makroyu cagirip diziyi al
    
    
    mov al, n
    cbw
    PUSH AX            ; eleman sayisini pushla
    LEA AX, SAYILAR    ; array'in efektif adresini al
    PUSH AX            ; aldigimiz degeri pushla
    CALL SORT_ARRAY    ; siralama alt yordamini cagir
    
    
    mov al, n
    cbw
    PUSH AX            ; eleman sayisini pushla
    LEA AX, SAYILAR    ; array'in efektif adresini al
    PUSH AX            ; aldigimiz degeri pushla
    CALL MYMOD         ; mod alma alt yordamini cagir
    
    ; sonuclari goster
    cbw
    CALL PUTN 
    MOV AX, OFFSET SONUC 
    CALL PUT_STR
    RETF
ANA ENDP

; sorting kismi
SORT_ARRAY PROC NEAR
    PUSH BP
    MOV BP, SP
    
    ; [BP+4] = array adresi
    ; [BP+6] = array boyutu
    
    MOV CX, [BP+6]     ; ARRAY SİZE'I AL
    DEC CX             ; loop icin 1 azalt
    XOR SI, SI         ; SI = 0
    
sort_loop:
    MOV DI, SI
    INC SI
    MOV BX, [BP+4]     ; array adresi al
    MOV AL, [BX+SI]    ; 
    
compare:
    MOV AH, [BX+DI]
    CMP AH, AL
    JL swap_skip
    XCHG [BX+DI+1], AH
    DEC DI
    CMP DI, 0
    JAE compare
    
swap_skip:
    MOV BX, [BP+4]
    MOV [BX+DI+1], AL
    LOOP sort_loop
    
    POP BP
    RET 4
SORT_ARRAY ENDP

; 
MYMOD PROC NEAR
    PUSH BP
    MOV BP, SP
    
    ; [BP+4] = array address
    ; [BP+6] = array size
    
    XOR SI, SI                  ; dis dongu indexi
    MOV CX, [BP+6]             ; array size
    MOV MaxCount, 0            
    MOV Mode, 0               
    
outer_loop:
    CMP SI, CX                 ; bitti mi diye bakıyoruz
    JAE find_done             
    
    MOV BX, [BP+4]             ; array adresi
    MOV AL, [BX+SI]            ; o adresteki sayi
    
    
    XOR DL, DL                 ; o sayinin kac kere oldugunu sayicak
    
    
    PUSH SI                    ; dis dongu indexini pushla
    MOV DI, 0                  ; array'in basindan basla
    
inner_loop:
    CMP DI, CX                 ; ic dongu bitti mi diye bak
    JAE count_done           
    
    MOV BX, [BP+4]             ; array address
    MOV AH, [BX+DI]            ; number to compare
    
    CMP AL, AH                 ; o anki sayiyla karsilastir
    JNE not_equal
    INC DL                     ; sayilar esitse sayaci arttir
    
not_equal:
    INC DI                     ; sonraki indexe gec ve tekrarla
    JMP inner_loop
    
count_done:
    
    MOV BL, MaxCount
    CMP DL, BL                 ; o anki sayaci maxcount ile kiyasla
    JB skip_update             ; eger o anki sayi maxcounttan kucukse update yapma
    
    
    JA update_mode             ; eger o anki sayi maxcounttan buyukse update yap
    
    ; eger ayni sayidaysa 2 durum
    MOV BH, Mode
    CMP AL, BH                 ; o anki sayiyi o modla kiyasla
    JAE skip_update            ; eğer mode'dan büyükse degisiklik yapma
    
update_mode:
    MOV MaxCount, DL           
    MOV Mode, AL               
    
skip_update:
    POP SI                     ; dis dongu sayacini geri al
    INC SI                     ; 1 arttir
    JMP outer_loop
    
find_done:
    MOV AL, Mode               ; modeu al'ye ata
    
    POP BP
    RET 4                    
MYMOD ENDP


    GETC	PROC NEAR
        MOV AH, 1h
        INT 21H
        RET 
    GETC	ENDP 

    PUTC	PROC NEAR
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
        PUSH BX
        PUSH CX
        PUSH DX
    GETN_START:
        MOV DX, 1	                        
        XOR BX, BX 	                       
        XOR CX,CX	                       
    NEW:
        CALL GETC	                         
        CMP AL,CR 
        JE FIN_READ	                        
        CMP  AL, '-'	                        
        JNE  CTRL_NUM	                        
    NEGATIVE:
        MOV DX, -1	                        
        JMP NEW		                        
    CTRL_NUM:
        CMP AL, '0'	                        
        JB error 
        CMP AL, '9'
        JA error		                
        SUB AL,'0'	                        
        MOV BL, AL	                        
        MOV AX, 10 	                        
        PUSH DX		                        
        MUL CX		                        
        POP DX		                        
        MOV CX, AX	                        
        ADD CX, BX 	                        
        JMP NEW 		                
    ERROR:
        MOV AX, OFFSET HATA 
        CALL PUT_STR	                        
        JMP GETN_START                          
    FIN_READ:
        MOV AX, CX	                        
        CMP DX, 1	                        
        JE FIN_GETN
        NEG AX		                        
    FIN_GETN:
        POP DX
        POP CX
        POP DX
        RET 
    GETN 	ENDP 

    PUTN 	PROC NEAR
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

    PUT_STR	PROC NEAR
        PUSH BX 
        MOV BX,	AX			        
        MOV AL, BYTE PTR [BX]	                
    PUT_LOOP:   
        CMP AL,0		
        JE  PUT_FIN 			        
        CALL PUTC 			        
        INC BX 				        
        MOV AL, BYTE PTR [BX]
        JMP PUT_LOOP			        
    PUT_FIN:
        POP BX
        RET 
    PUT_STR	ENDP
CDSG ENDS

    END ANA