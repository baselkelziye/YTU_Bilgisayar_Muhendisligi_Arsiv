datasg  SEGMENT PARA 'veri'
katlar DW 270 DUP(?)
ortalama DW ? ;BX
datasg  ENDS
stacksg SEGMENT PARA STACK 'yigin'
        DW 20 DUP(?)
stacksg ENDS
codesg  SEGMENT PARA 'kod'
        ASSUME CS:codesg, SS:stacksg, DS:datasg
MAIN    PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, datasg
        MOV DS, AX ;EXE default end
        ;my code
        XOR AX, AX
        XOR BX, BX ;ortalama
        XOR SI, SI
        XOR DI, DI ;poz sayi
        MOV CX, 270
        MOV DL, 3 ;bolen
lo1:    MOV AX, katlar[SI]
        SHL AX, 1
        JC negatif
        RCR AX, 1
        DIV DL
        CBW
        ADD BX, AX
        ADD DI, 1
negatif:ADD SI, 2
        LOOP lo1
        XOR DX, DX
        MOV AX, BX
        DIV DI
        MOV ortalama, AX
son:    RETF
        MAIN ENDP
        codesg ENDS
        END MAIN
