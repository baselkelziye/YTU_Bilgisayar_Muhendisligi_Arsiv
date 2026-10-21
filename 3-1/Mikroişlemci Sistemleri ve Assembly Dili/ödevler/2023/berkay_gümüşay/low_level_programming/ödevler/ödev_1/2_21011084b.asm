datasg	SEGMENT PARA 'veri'
 dizi	DB	501 DUP(0)
	n	DW 	500
datasg	ENDS
;--------------------------------------------
stacksg	SEGMENT PARA STACK 'yigin'
		DW 300 DUP(?)
stacksg	ENDS
;--------------------------------------------
codesg2	SEGMENT PARA 'kod2'
		ASSUME CS:codesg2,SS:stacksg,DS:datasg
DNUM	PROC FAR
		
loop1:	
		XOR AX,AX
		MOV AL,BYTE PTR dizi[SI-1] ; D(N-1)
		MOV DI,AX
		MOV AL,BYTE PTR dizi[DI] ;D(D(n-1))
;-------------------------------------------------
		MOV DL,BYTE PTR dizi[SI-2] ;D(n-2)
		MOV BX,SI ;CX = n
		DEC BX		;CX = n-1
		XOR DH,DH
		SUB BX,DX	;CX = n-1-D(n-2)
		MOV BL,BYTE PTR dizi[BX]
		ADD BX,AX
		MOV BYTE PTR dizi[SI],BL
		
		INC SI
		loop loop1
				;D(D(n-1)) + D(n-1-D(n-2))
		
		
		RETF
DNUM 	ENDP
codesg2	ENDS
codesg1	SEGMENT PARA 'kod1'
		ASSUME CS:codesg1,SS:stacksg,DS:datasg
;--------------------------------------------
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
;--------------------------------------------

ANA		PROC FAR
		
		PUSH DS
		XOR AX,AX
		PUSH AX
		MOV AX,datasg
		MOV DS,AX
		
		LEA SI,dizi
		MOV AL,0
		MOV BYTE PTR dizi[SI],AL
		INC SI
		MOV AL,1
		MOV BYTE PTR dizi[SI],AL
		INC SI
		MOV BYTE PTR dizi[SI],AL
		INC SI
		MOV CX,n
		SUB CX,2
		CALL FAR PTR DNUM
		LEA SI,dizi
		XOR AX,AX
		MOV AL,BYTE PTR dizi[SI+500]
		CALL PRINTINT
		
		
		RETF
ANA 	ENDP
codesg1	ENDS
		END ANA