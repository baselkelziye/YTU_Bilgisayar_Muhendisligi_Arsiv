;------------------------------------------------------------------.
;This program calculates the nth element of Newman-Conway Sequence.|
;The user enters n (index of element to calculate) then chooses    |
;a calculation method (dynamic or recursive)                       |
;If dynamic programming method is chosen then the user can choose  |
;to print every calculated element up to the nth element           |
;------------------------------------------------------------------.
datasg SEGMENT PARA 'data'
	CR		EQU 13
	LF		EQU 10
	SPACE		EQU 32
	WHSPACE		DB CR, LF, 0
	MSGCHOICE 	DB 'Press Enter for dynamic. Anything else for recursive CONWAY: ', 0
	MSGRES		DB 'Result : ', 0
	MSGQ		DB 'Print all sequence elements? (Enter): ', 0
	MSGN 		DB 'Enter n: ', 0
	nindex		DW 0 ;last calculated index
	conarr		DW 0, 1, 1, 1000 DUP(?)
datasg ENDS
stacksg SEGMENT PARA STACK 'yigin'
	DW 200 DUP(?)
stacksg ENDS
codes		SEGMENT PARA 'kod'
ASSUME CS:codes, DS:datasg
CONWAY PROC FAR
		PUSH BP
		PUSH CX
		MOV BP, SP
		MOV CX, [BP+8] ; 2 RW + CS + IP = 8bytes
		CMP CX, 0
		JA notz
		MOV WORD PTR [BP+8], 0
		POP CX
		POP BP
		RETF
notz:		CMP CX, 2
		JA gthan2
		MOV WORD PTR [BP+8], 1
		POP CX
		POP BP
		RETF
gthan2:		PUSH BX
		PUSH AX
		MOV BX, CX
		DEC BX
		PUSH BX
		CALL CONWAY ; calculate a(n-1)
		POP AX
		SUB CX, AX ; mov n-a(n-1) to cx
		PUSH AX
		CALL CONWAY ; calculate a(a(n-1))
		POP AX
		PUSH CX
		CALL CONWAY ; calculate a(n-a(n-1))
		POP BX
		ADD AX, BX ; a(a(n-1))+a(n-a(n-1))
		MOV [BP+8], AX ; BP still the same. prev caclulation applies
		POP AX
		POP BX
		POP CX
		POP BP
		RETF
CONWAY ENDP

DCONWAY PROC FAR
		PUSH BP
		PUSH CX
		MOV BP, SP
		MOV CX, [BP+8] ; 2 RW + CS + IP = 8bytes
		CMP CX, 0
		JA notzero
		MOV WORD PTR [BP+8], 0
		POP CX
		POP BP
		RETF
notzero:	CMP CX, 2
		JA gt2
		MOV WORD PTR [BP+8], 1
		POP CX
		POP BP
		RETF
gt2:		PUSH BX ;used to access address
		PUSH AX
		CMP CX, nindex
		JA notcalced
		SHL CX, 1
		MOV BX, CX
		MOV AX, conarr[BX]
		MOV [BP+8], AX ; BP still the same. prev caclulation applies
		POP AX
		POP BX
		POP CX
		POP BP
		RETF
notcalced:	PUSH DX
		MOV BX, CX
		MOV DX, CX
		DEC DX
		PUSH DX
		CALL DCONWAY ; calculate a(n-1)
		POP AX
		SUB CX, AX ; mov n-a(n-1) to cx
		PUSH AX
		CALL DCONWAY ; calculate a(a(n-1))
		POP AX
		PUSH CX
		CALL DCONWAY ; calculate a(n-a(n-1))
		POP DX
		ADD AX, DX ; a(a(n-1))+a(n-a(n-1))
		MOV [BP+8], AX ; BP still the same. prev caclulation applies
		MOV nindex, BX
		SHL BX, 1
		MOV conarr[BX], AX
		POP DX
		POP AX
		POP BX
		POP CX
		POP BP
		RETF
DCONWAY ENDP
codes		ENDS

codesg SEGMENT PARA 'code'
ASSUME CS:codesg, SS:stacksg, DS:datasg

PRINTINT	PROC NEAR ; prints integer from stack pops it afterwards
		PUSH BX
		PUSH BP
		PUSH DX
		MOV BP, SP
		MOV AX, [BP+8] 	; get int from stack PROC is NEAR so 3 RW + IP = 8 bytes
		MOV BX, 1
		PUSH BX
		XOR DX, DX ; will use div should be zero
		MOV BX, 0Ah
more:		DIV BX
		ADD DX, '0'
		PUSH DX
		XOR DX, DX
		CMP AX, 0
		JNZ more
printlo:	POP AX
		CMP AX, 1
		JZ done
		MOV DL, AL
		MOV AH, 2
		INT 21h
		JMP printlo
done:		POP DX
		POP BP
		POP BX
		RET 2
PRINTINT	ENDP

PRINTS PROC NEAR ; prints string addressed by AX char by char untill 0 is encountered
		; similar to int21's 9. procedure
		PUSH SI
		PUSH DX
		MOV SI, AX
		MOV AL, BYTE PTR [SI]
notnull:	CMP AL, 0
		JZ gotnull
		MOV DL, AL
		MOV AH, 2
		INT 21h
		INC SI
		MOV AL, BYTE PTR [SI]
		JMP notnull
gotnull:	POP DX
		POP SI
		RET			
PRINTS		ENDP

GETCHAR PROC NEAR ; writes input char to AL
		MOV AH, 1h
		INT 21h
		RET
GETCHAR		ENDP

GETINT PROC NEAR ; Reads char from stdin parses it to number and returns the value using AX
		PUSH DX ;using MUL RW will be effected
		PUSH CX
		PUSH BX
		XOR CX, CX
		XOR BX, BX
getdigit:	CALL GETCHAR
		CMP AL, CR
		JZ endofstr
		SUB AL, '0'
		MOV CL, AL
		MOV AX, 10
		MUL BX
		MOV BX, AX
		ADD BX, CX
		JMP getdigit
endofstr:	MOV AX, BX
		POP BX
		POP CX
		POP DX
		RET
GETINT		ENDP

PRINTALL PROC NEAR
		PUSH AX
		PUSH DX
		PUSH CX
		PUSH SI
		MOV CX, nindex
		INC CX
		XOR SI, SI
again:		MOV AX, conarr[SI]
		ADD SI, 2
		PUSH AX
		CALL PRINTINT
		MOV DL, SPACE
		MOV AH, 2
		INT 21h
		LOOP again
		POP SI
		POP DX
		POP BX
		POP AX
		RET
PRINTALL ENDP

MAIN PROC FAR
		PUSH DS
		XOR AX, AX
		PUSH AX
		MOV AX, datasg
		MOV DS, AX ;EXE tipi son
		LEA AX, MSGN
		CALL PRINTS ; get n from user
		CALL GETINT ; get number
		PUSH AX
		LEA AX, MSGCHOICE 
		CALL PRINTS ; ask for method (dynamic / recursive)
		CALL GETCHAR 
		CMP AL, CR
		JNZ weirduser
		CALL DCONWAY
		LEA AX, MSGQ
		CALL PRINTS ; ask to print all numbers
		CALL GETCHAR
		CMP AL, CR
		JNZ printres
		CALL PRINTALL
		JMP printres
weirduser:	CALL CONWAY	
printres:	LEA AX, WHSPACE
		CALL PRINTS
		LEA AX, MSGRES
		CALL PRINTS
		CALL PRINTINT
		RETF
MAIN ENDP
codesg ENDS
END MAIN
