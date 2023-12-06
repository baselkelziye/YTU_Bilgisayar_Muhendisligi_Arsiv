datasg  SEGMENT PARA 'veri'
    sicaklik DB 294 DUP(?)
    ort      DB ? ;BX
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
        MOV DS, AX ;EXE tipi son

        XOR BX, BX ;ortalama
        XOR SI, SI ;loop degiskeni
        XOR DL, DL ;pos sayac
        MOV CX, 294
lo1:    MOV AL, sicaklik[SI]
        SHL AL, 1
        JC eksi
        RCR AL, 1
        CBW
        ADD BX, AX
        INC DL
eksi:   INC SI
        LOOP lo1
        MOV AX, BX
        DIV DL
        MOV CL, 3
        CBW
        DIV CL
        MOV ort, AL
        RETF
        MAIN ENDP
        codesg ENDS
        END MAIN
