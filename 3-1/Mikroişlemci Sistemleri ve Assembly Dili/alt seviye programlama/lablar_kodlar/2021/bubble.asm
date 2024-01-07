myss SEGMENT PARA STACK 'stack'
	DW 20 DUP(?)
myss ENDS

myds SEGMENT PARA 'data'
	arr DW 9,2,5,1,3,4,8
	n DW 7
myds ENDS

mycs SEGMENT PARA 'code'
	ASSUME CS:mycs, SS:myss, DS:myds
	
	MAIN PROC FAR
	PUSH DS
	XOR AX,AX
	PUSH AX
	MOV AX,myds
	MOV DS,AX
	
	XOR SI,SI
	MOV CX,n
	DEC CX
l2:	
	PUSH CX
	
		MOV CX,n
		SUB CX,SI
		DEC CX
	
		XOR DI,DI
l1:		MOV AX, arr[DI]
		CMP AX, arr[DI + 2]
		JLE false
		XCHG AX, arr[DI + 2]
		MOV arr[DI], AX
false:  ADD DI,2	
		LOOP l1
	INC SI
	
	POP CX
	LOOP l2
	
	
	RETF
	MAIN ENDP
mycs ENDS
	END MAIN