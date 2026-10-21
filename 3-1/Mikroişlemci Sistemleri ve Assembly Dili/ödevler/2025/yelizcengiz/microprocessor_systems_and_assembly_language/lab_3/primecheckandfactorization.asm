SSEG    SEGMENT PARA STACK 'STACK'
        DW 32 DUP (?)
SSEG    ENDS

DSEG    SEGMENT PARA 'DATA'
        PRIMARY_LIST    DB 9 DUP(?)
        FACTORS         DW 16 DUP(0)
        NUMBER_LIST     DW 9 DUP(?)
        MAX_FACTORS   DW 9 DUP(0)
        
        CR              EQU 13
        LF              EQU 10
        MSG1            DB CR, LF, 'Sayi giriniz: ', 0
        HATA            DB CR, LF, 'Dikkat! Sayi vermediniz, yeniden giris yapiniz!', 0
        SONUC1          DB CR, LF, 'Sayilar: ', 0
        SONUC2          DB CR, LF, 'Asal Carpanlar: ', 0
        SONUC3          DB CR, LF, 'En Buyuk Asal Carpanlari: ', 0
        SONUC4          DB CR, LF, 'Asallik: ', 0
        TAB_STR         DB '   ', 0
DSEG    ENDS 

CSEG    SEGMENT PARA 'CODE'
        ASSUME CS:CSEG, DS:DSEG, SS:SSEG

READ_ARRAY MACRO size, NUMBER_LIST
        LOCAL RALOOP
        XOR SI, SI
        MOV CX, size
RALOOP: MOV AX, OFFSET MSG1
        CALL PUT_STR
        CALL GETN
        MOV NUMBER_LIST[SI], AX
        ADD SI, 2
        LOOP RALOOP
ENDM
PRINT_ARRAY MACRO size, array, msg
        LOCAL PALOOP
        XOR SI, SI
        MOV AX, OFFSET msg
        CALL PUT_STR
        MOV CX, size
PALOOP: MOV AX, array[SI]
        CALL PUTN
        MOV AX, OFFSET TAB_STR
        CALL PUT_STR
        ADD SI, 2
        LOOP PALOOP
ENDM
PRINT_ARRAY_BYTE MACRO size, array, msg
    LOCAL PALOOPB
    XOR SI, SI
    MOV AX, OFFSET msg
    CALL PUT_STR
    MOV CX, size
PALOOPB:
    MOV AL, array[SI]
    CBW
    CALL PUTN 
    MOV AX, OFFSET TAB_STR
    CALL PUT_STR
    INC SI
    LOOP PALOOPB
ENDM
PRINT_FACTORS MACRO
        LOCAL PFLOOP, PFEND
        XOR SI, SI
        MOV AX, OFFSET SONUC2
        CALL PUT_STR
PFLOOP: MOV AX, FACTORS[SI]
        CMP AX, 0       ; 0 gorunce bitir
        JE PFEND
        CALL PUTN
        MOV AX, OFFSET TAB_STR
        CALL PUT_STR
        ADD SI, 2
        JMP PFLOOP
PFEND:
ENDM

ANA     PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, DSEG 
        MOV DS, AX

        READ_ARRAY 9, NUMBER_LIST
        PRINT_ARRAY 9, NUMBER_LIST, SONUC1
        XOR DI, DI
        MOV CX, 9

MAIN_LOOP:
        PUSH CX
        
        PUSH DI
        XOR SI, SI
        MOV CX, 16
CLEAR_FACTORS:
        MOV FACTORS[SI], 0
        ADD SI, 2
        LOOP CLEAR_FACTORS
        POP DI
        
        MOV BX, DI
        SHL BX, 1
        MOV AX, NUMBER_LIST[BX]
        
        PUSH AX
        CALL IS_PRIME
        MOV PRIMARY_LIST[DI], AL
        
        POP AX
        CMP AL, 1
        JE CONTINUE_LOOP
        
        MOV BX, DI
        SHL BX, 1
        MOV AX, NUMBER_LIST[BX]
        CALL FACTORIZE
        
        PRINT_FACTORS 
        CALL MAX_FACTOR
        JMP CONTINUE_LOOP


CONTINUE_LOOP:
        POP CX
        INC DI
        LOOP MAIN_LOOP
        PRINT_ARRAY 9 ,MAX_FACTORS, SONUC3
        PRINT_ARRAY_BYTE 9 ,PRIMARY_LIST, SONUC4

        RETF 
ANA     ENDP

MAX_FACTOR PROC NEAR
        PUSH CX
        PUSH BX
        PUSH AX
        PUSH SI

        XOR SI, SI
        XOR AX, AX
        MOV CX,16
LOOP_MAX_FACTOR:        
        CMP FACTORS[SI], 0
        JE FOUND_MAX;arrayin sonu

        MOV BX, FACTORS[SI]
        CMP BX, AX
        JLE NOT_MAX
        MOV AX, BX
NOT_MAX:
        ADD SI, 2
        LOOP LOOP_MAX_FACTOR
FOUND_MAX:
        MOV BX, DI
        SHL BX, 1
        MOV MAX_FACTORS[BX], AX
        POP SI
        POP AX
        POP BX
        POP CX
MAX_FACTOR ENDP

FACTORIZE PROC NEAR
        PUSH CX
        PUSH DX
        PUSH BX
        PUSH SI
        
        XOR SI, SI
        
        CMP AX, 1
        JBE FACTOR_END

        MOV BX, AX
        MOV CX, 2
CHECK_TWO:
        MOV AX, BX
        XOR DX, DX
        DIV CX           
        CMP DX, 0
        JNE CONTINUE
        
        MOV FACTORS[SI], CX     ;2 carpanini ekleme
        ADD SI, 2
        MOV BX, AX
        CMP BX, 1
        JE FACTOR_END
        JMP CHECK_TWO
CONTINUE:
        MOV CX, 3 
FACTOR_LOOP:
        MOV AX, BX
        XOR DX, DX
        DIV CX
        CMP DX, 0
        JNE NEXT_FACTOR
        
        MOV FACTORS[SI], CX     ;carpani arraya ekleme
        ADD SI, 2
        MOV BX, AX 
        CMP BX, 1
        JE FACTOR_END
        JMP FACTOR_LOOP

NEXT_FACTOR:
        ADD CX, 2
        
        MOV AX, CX
        PUSH DX
        MUL CX
        POP DX
        CMP AX, BX
        JA LAST_FACTOR  ;SAYI<BOLEN*BOLEN
        
        JMP FACTOR_LOOP

LAST_FACTOR:
        CMP BX, 1
        JBE FACTOR_END          ;kendisi
        MOV FACTORS[SI], BX
        ADD SI, 2
        
FACTOR_END:
        MOV FACTORS[SI], 0; arrayin sonu
        POP SI
        POP BX
        POP DX
        POP CX
        RET
FACTORIZE ENDP

IS_PRIME PROC NEAR
        PUSH CX
        PUSH DX
        PUSH BX
        
        MOV BX, AX
        
        CMP BX, 1       ;0,1
        JBE NOT_PRIME

        CMP BX, 2       ;2
        JE PRIME

        MOV AX, BX
        MOV CX, 2
        XOR DX, DX
        DIV CX           ;/2
        CMP DX, 0
        JE NOT_PRIME

        MOV CX, 3
CHECK_LOOP:
        MOV AX, BX
        XOR DX, DX
        DIV CX         ;/TEKLER
        CMP DX, 0
        JE NOT_PRIME
        
        ADD CX, 2
        
        MOV AX, CX      
        PUSH DX
        MUL CX
        POP DX
        CMP AX, BX
        JBE CHECK_LOOP  ;SAYI<BOLEN*BOLEN =>KONTROLU

PRIME:  
        MOV AX, 1
        JMP IS_PRIME_END

NOT_PRIME:        
        MOV AX, 0

IS_PRIME_END:
        POP BX
        POP DX
        POP CX
        RET
IS_PRIME ENDP

GETC    PROC NEAR
        MOV AH, 1h
        INT 21H
        RET 
GETC    ENDP 

PUTC    PROC NEAR
        PUSH AX
        PUSH DX
        MOV DL, AL
        MOV AH, 2
        INT 21H
        POP DX
        POP AX
        RET 
PUTC    ENDP 

GETN    PROC NEAR
        PUSH BX
        PUSH CX
        PUSH DX

GETN_START:
        XOR BX, BX
        XOR CX, CX

NEW:
        CALL GETC
        CMP AL, CR 
        JE FIN_READ
        
        CMP AL, '0'
        JB ERROR 
        CMP AL, '9'
        JA ERROR
        
        SUB AL, '0'
        MOV BL, AL
        MOV AX, 10
        MUL CX  
        MOV CX, AX
        ADD CX, BX 
        JMP NEW

ERROR:
        MOV AX, OFFSET HATA 
        CALL PUT_STR
        JMP GETN_START

FIN_READ:
        MOV AX, CX
        POP DX
        POP CX
        POP BX
        RET 
GETN    ENDP 

PUTN    PROC NEAR
        PUSH CX
        PUSH DX 	
        
        XOR DX, DX
        PUSH DX
        MOV CX, 10
        
CALC_DIGITS:
        XOR DX, DX
        DIV CX  
        ADD DX, '0'
        PUSH DX
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
PUTN    ENDP 

PUT_STR PROC NEAR
        PUSH BX 
        PUSH AX
        MOV BX, AX
        MOV AL, BYTE PTR [BX]

PUT_LOOP:   
        CMP AL, 0
        JE PUT_FIN
        CALL PUTC
        INC BX
        MOV AL, BYTE PTR [BX]
        JMP PUT_LOOP

PUT_FIN:
        POP AX
        POP BX
        RET 
PUT_STR ENDP

CSEG    ENDS 
        END ANA