;-----------------------------------------------
datasg	SEGMENT	PARA 'veri'
	num	DW 10
datasg ENDS
;-----------------------------------------------
stacksg	SEGMENT PARA STACK 'yigin'
	DW	300	DUP(?)
stacksg	ENDS
;-----------------------------------------------
codesg2	SEGMENT PARA 'kod2'
	ASSUME CS:codesg2,SS:stacksg,DS:datasg
DNUM	PROC FAR
		PUSH BP
		PUSH BX
		PUSH DI
		PUSH SI
		
		MOV BP,SP
		MOV DI,[BP+12]
		MOV AX,DI
		
		CMP AX,0
		JZ	SIFIR
		CMP AX,1
		JZ	BIR
		CMP AX,2
		JZ	BIR
		
		DEC AX
		PUSH AX
		CALL FAR PTR DNUM
		CALL FAR PTR DNUM
		POP SI	  ;D(D(n-1))
		MOV CX,DI
		SUB CX,2
		PUSH CX
		CALL FAR PTR DNUM
		POP CX
		MOV DX,DI
		DEC DX
		SUB DX,CX
		PUSH DX
		CALL FAR PTR DNUM
		POP DX
		ADD SI,DX
		MOV [BP+12],SI
		JMP SON

SIFIR:	MOV AX,0
		MOV [BP+12],AX
		JMP SON
		
BIR:	MOV AX,1
		MOV [BP+12],AX
SON:	POP SI
		POP DI
		POP BX
		POP BP
		RETF
DNUM	ENDP
codesg2	ENDS
;-----------------------------------------------
codesg1 SEGMENT PARA 'kod1'
	ASSUME CS:codesg1,SS:stacksg,DS:datasg
;-----------------------------------------------
PRINTINT PROC NEAR
    MOV CX,0
    MOV DX,0
    label1:
        CMP AX,0
        JE print1     
         
        MOV BX,10       
         
        DIV BX                 
         
        PUSH DX             
         
        INC CX             
         
        XOR DX,DX
        JMP label1
    print1:
        
        CMP CX,0
        JE exit
        POP DX
        ADD DX,48 ; ASCII
        MOV AH,02h
        INT 21h
        DEC cx
        JMP print1
exit:
	RET
PRINTINT ENDP
;-----------------------------------------------
ANA	PROC FAR
	PUSH DS
	XOR AX,AX
	PUSH AX
	MOV AX,datasg
	MOV DS,AX
	
	PUSH num
	CALL FAR PTR DNUM
	POP AX
	CALL PRINTINT
	RETF
ANA ENDP
codesg1	ENDS
		END ANA