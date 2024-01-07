datasg  SEGMENT PARA 'veri'
        rakimlar DW -200, 20, -40, -50, 70
	avg DW ?
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
        MOV DS, AX
        ;my code
        MOV CX, 5
        XOR SI, SI ;loop variable
	XOR DI, DI ;positive counter
	XOR BX, BX ;avg
lo1:	MOV AX, rakimlar[SI]
	SHL AX, 1
	JC cont
	RCR AX, 1
	ADD BX, AX
	INC DI
cont:   ADD SI, 2
	LOOP lo1
	MOV AX, BX
	XOR DX, DX
	DIV DI
	MOV avg, AX
        RETF
        MAIN ENDP
        codesg ENDS
        END MAIN
