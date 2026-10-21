SSEG    SEGMENT PARA STACK 'STACK'
        DW 64 DUP (?)
SSEG    ENDS

DSEG    SEGMENT PARA 'DATA'
        NUMBER_LIST     DB 10 DUP(?)
        NUMBER_COUNT    DB 10
        IS_SORTED_FLAG  DB 0
        KEY_VALUE       DB 0
        
        CR              EQU 13
        LF              EQU 10
        MSG2            DB CR, LF, 'Sayi giriniz : ', 0
        MSG_KEY         DB CR, LF, 'Aranacak degeri girin (q=cikis): ', 0
        HATA            DB CR, LF, 'Gecersiz giris, yeniden giris yapiniz!', 0
        SONUC1          DB CR, LF, 'Girilen Sayilar: ', 0
        SORTED_MSG      DB CR, LF, 'Dizi SIRALI', 0
        NOT_SORTED_MSG  DB CR, LF, 'Dizi SIRALI DEGIL', 0
        BS_NOT_FOUND_MSG   DB CR, LF, 'Dizide aranan eleman yok', 0
        BS_FOUND_MSG   DB CR, LF, 'Dizide aranan eleman indexi:', 0
        TAB_STR         DB '   ', 0
DSEG    ENDS 

CSEG    SEGMENT PARA 'CODE'
        ASSUME CS:CSEG, DS:DSEG, SS:SSEG

READ_ARRAY_BYTE MACRO size_var, array
        LOCAL RALOOP
        XOR SI, SI
        XOR CX, CX
        MOV CL, size_var
RALOOP: MOV AX, OFFSET MSG2
        CALL PUT_STR
        CALL GETN
        CMP AX, 250
        JA RALOOP       ; >250
        MOV array[SI], AL
        INC SI
        LOOP RALOOP
ENDM

PRINT_ARRAY_BYTE MACRO size_var, array, msg
        LOCAL PALOOP
        XOR SI, SI
        MOV AX, OFFSET msg
        CALL PUT_STR
        XOR CX, CX
        MOV CL, size_var
PALOOP:
        MOV AL, array[SI]
        XOR AH, AH
        CALL PUTN 
        MOV AX, OFFSET TAB_STR
        CALL PUT_STR
        INC SI
        LOOP PALOOP
ENDM

ANA     PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, DSEG 
        MOV DS, AX

        READ_ARRAY_BYTE NUMBER_COUNT, NUMBER_LIST
        PRINT_ARRAY_BYTE NUMBER_COUNT, NUMBER_LIST, SONUC1
        
        XOR AX, AX
        MOV AL, NUMBER_COUNT
        PUSH AX
        MOV AX, OFFSET NUMBER_LIST
        PUSH AX
        CALL IS_SORTED
        
        POP AX
        MOV IS_SORTED_FLAG, AL
        
        CMP IS_SORTED_FLAG, 1
        JE PRINT_SORTED
        
        MOV AX, OFFSET NOT_SORTED_MSG
        CALL PUT_STR
        JMP PROGRAM_END
        
PRINT_SORTED:
        MOV AX, OFFSET SORTED_MSG
        CALL PUT_STR

SEARCH:
        MOV AX,OFFSET MSG_KEY
        CALL PUT_STR

        CALL GETN_WITH_Q
        CMP AX, -1  ;q?
        JE PROGRAM_END
        
        MOV KEY_VALUE, AL

        XOR AX, AX
        MOV AL, NUMBER_COUNT
        DEC AL
        PUSH AX     ;max
        XOR AX, AX
        PUSH AX     ;min=0
        MOV AX, OFFSET NUMBER_LIST
        PUSH AX     ;dizi adresi
        MOV AL, KEY_VALUE
        XOR AH, AH
        PUSH AX     ;key
        
        CALL BINARY_SEARCH

        POP AX  ;SONUC
        JMP SEARCH

PROGRAM_END:
        RETF 
ANA     ENDP

BINARY_SEARCH PROC NEAR

        PUSH BP
        MOV BP, SP
        PUSH BX
        PUSH CX
        PUSH DX
        PUSH SI
        
        MOV AL, [BP+4]      ;key
        MOV SI, [BP+6]      ;dizi adresi
        MOV DL, [BP+8]      ;min index
        MOV DH, [BP+10]     ;max index
        
        ;MİN>MAX
        CMP DL, DH
        JG BS_NOT_FOUND
        
        MOV BL, DL
        ADD BL, DH
        SHR BL, 1   ;mid=(min+max)/2
        
        PUSH BX
        MOV BH, 0
        MOV CL, [SI+BX] ;[SI+BX]=array[mid]
        POP BX
        
        CMP AL, CL
        JE BS_FOUND
        JL BS_LESS
        
        MOV DL, BL
        INC DL;MİN=MİD+1
;BS_GREATER:
        XOR AX, AX
        MOV AL, DH
        PUSH AX     ;max
        XOR AX, AX
        MOV AL, DL
        PUSH AX     ;min=mid+1
        PUSH SI     ;dizi adresi
        MOV AL, [BP+4]
        XOR AH, AH
        PUSH AX     ;key
        
        CALL BINARY_SEARCH
        POP CX  ;Sonuc
        
        MOV AX, CX
        JMP BS_END
        
BS_LESS:
        MOV DH, BL
        DEC DH;MAX=MİD-1
        ;
        XOR AX, AX
        MOV AL, DH
        PUSH AX     ;max=mid-1
        XOR AX, AX
        MOV AL, DL
        PUSH AX     ;min
        PUSH SI     ;dizi adresi
        MOV AL, [BP+4]
        XOR AH, AH
        PUSH AX     ;key
        
        CALL BINARY_SEARCH
        POP CX ;Sonuc
        
        MOV AX, CX
        JMP BS_END

BS_NOT_FOUND:
        MOV AX, OFFSET BS_NOT_FOUND_MSG
        CALL PUT_STR
        MOV AX, -1
        JMP BS_END
        
BS_FOUND:
        MOV AX, OFFSET BS_FOUND_MSG
        CALL PUT_STR
        MOV AL, BL;index
        XOR AH, AH
        CALL PUTN

BS_END:
        POP SI
        POP DX
        POP CX
        POP BX
        POP BP
        
        POP BX              ;Donus adresi
        ADD SP, 8           ;4*2 byte
        PUSH AX             ;Sonuc
        PUSH BX             ;Donus adresi
        
        RET
BINARY_SEARCH ENDP


IS_SORTED PROC NEAR
        PUSH BP
        MOV BP, SP
        PUSH BX
        PUSH CX
        PUSH SI
        
        MOV SI, [BP+4]      ;dizi adr
        MOV CX, [BP+6]      ;count
        
        CMP CX, 1
        JBE SORTED
        
        DEC CX 
CHECK_LOOP:
        MOV AL, [SI]
        MOV BL, [SI+1]
        
        CMP AL, BL  ;[SI] > [SI+1]
        JG NOT_SORTED
        
        INC SI
        LOOP CHECK_LOOP
        
SORTED:
        MOV AX, 1
        JMP IS_SORTED_END
        
NOT_SORTED:
        MOV AX, 0
        
IS_SORTED_END:
        POP SI
        POP CX
        POP BX
        POP BP
        
        POP DX              ;Donus adresi(IP)
        POP BX              ;Dizi adresi
        POP BX              ;Eleman sayisi
        
        PUSH AX             ;SONUC
        PUSH DX             ;IP
        
        RET
IS_SORTED ENDP



;---------INPUT-----------
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
GETN_WITH_Q PROC NEAR
        PUSH BX
        PUSH CX
        PUSH DX

        XOR BX, BX
        XOR CX, CX

NEW_Q:
        CALL GETC
        
        ;q veya Q
        CMP AL, 'q'
        JE QUIT_INPUT
        CMP AL, 'Q'
        JE QUIT_INPUT
        
        CMP AL, CR 
        JE FIN_READ_Q
        
        CMP AL, '0'
        JB ERROR_Q 
        CMP AL, '9'
        JA ERROR_Q
        
        SUB AL, '0'
        MOV BL, AL
        MOV AX, 10
        MUL CX  
        MOV CX, AX
        ADD CX, BX 
        JMP NEW_Q

ERROR_Q:
        MOV AX, OFFSET HATA 
        CALL PUT_STR
        XOR BX, BX
        XOR CX, CX
        JMP NEW_Q

QUIT_INPUT:
        CALL GETC
        MOV AX, -1 ;q
        JMP END_GETN_Q

FIN_READ_Q:
        MOV AX, CX

END_GETN_Q:
        POP DX
        POP CX
        POP BX
        RET 
GETN_WITH_Q ENDP

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