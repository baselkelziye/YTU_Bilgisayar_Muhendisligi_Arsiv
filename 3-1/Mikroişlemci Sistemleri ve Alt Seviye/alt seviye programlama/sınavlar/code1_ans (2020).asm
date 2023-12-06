datasg  SEGMENT PARA 'data'
    change DB 262 DUP(?)
    avg      DB ?
datasg  ENDS
stacksg SEGMENT PARA STACK 'yigin'
        DW 20 DUP(?)
stacksg ENDS
codesg  SEGMENT PARA 'code'
        ASSUME CS:codesg, SS:stacksg, DS:datasg
MAIN    PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, datasg
        MOV DS, AX ;EXE tipi son

        XOR BL, BL
        XOR DX, DX
        XOR SI, SI
        MOV CX, 4
lo1:    MOV AL, change[SI]
        SHL AL, 1
        JNC pos
        RCR AL, 1
        CBW
        ADD DX, AX
        INC BL
pos:    INC SI
        LOOP lo1
        MOV AX, DX
        IDIV BL
        MOV CL, 5
        CBW
        IDIV CL
        MOV avg, AL
        RETF
        MAIN ENDP
        codesg ENDS
        END MAIN
