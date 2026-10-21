myss		SEGMENT PARA STACK 'yigin'
			DW 200 DUP(?)
myss		ENDS
mydata		SEGMENT PARA 'veri'
INPUT		DW 10
msgError	DB	'Hatali deger girdiniz','$'
mydata		ENDS
mycode		SEGMENT PARA 'kod'
			ASSUME CS:mycode, SS:myss, DS:mydata
DNUM		PROC NEAR
			PUSH BP
			PUSH AX
			MOV BP,SP
			MOV AX, [BP+6]
			CMP AX, 2
			JA recursive
			CMP AX, 0
			JA sonuc1
			MOV WORD PTR [BP+6],0
			POP AX
			POP BP
			RET
sonuc1:		MOV WORD PTR [BP+6],1
			POP AX
			POP BP
			RET
recursive:	PUSH BX
			DEC AX ; AX = n-1
			MOV BX,AX ; BX = n-1
			PUSH BX
			PUSH AX
			CALL DNUM
			POP AX ; AX = D(n-1)
			POP BX ; BX = n-1 olarak geri döndü
			PUSH AX
			CALL DNUM
			POP AX ; AX = D(D(n-1))
			PUSH DX
			MOV DX,BX ; DX = n-1
			DEC BX ; BX = n-2
			PUSH BX
			CALL DNUM
			POP BX ; BX = D(n-2)
			SUB DX,BX; DX = n-1 - D(n-2)
			PUSH DX
			CALL DNUM
			POP DX ; DX = D(n-1 + D(n-2))
			ADD AX,DX ; AX = D(D(n-1)) + D(n-1 + D(n-2))
			MOV [BP+6],AX
			POP DX
			POP BX
			POP AX
			POP BP
			RET
DNUM		ENDP
MYPRINT		PROC NEAR
			PUSH AX
			PUSH DX
			ADD AL,30H
			MOV DL,AL
			MOV AH,02H
			INT 21H
			POP DX
			POP AX
			RET
MYPRINT		ENDP
PRERROR		PROC NEAR
			PUSH AX
			PUSH DX
			LEA DX,msgError
			MOV AH,09H
			INT 21H
			POP DX
			POP AX
			RET
PRERROR		ENDP	
MAIN		PROC FAR
			PUSH DS
			XOR AX, AX
			PUSH AX
			MOV AX, mydata
			MOV DS, AX
			MOV AX, INPUT
			CMP AX,0
			JNL gecerli
			CALL PRERROR
			JMP son
gecerli:	PUSH AX
			CALL DNUM
			POP AX
			CALL MYPRINT
son:		RETF
MAIN		ENDP
mycode		ENDS
			END MAIN