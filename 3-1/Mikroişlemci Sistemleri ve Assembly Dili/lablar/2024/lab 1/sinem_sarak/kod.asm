datasg		SEGMENT PARA 'data'
vize		DB 77,85,64,96
final		DB 56,63,86,74
OBP			DB 4 DUP(0)
len			DW 4
datasg		ENDS
stacksg		SEGMENT PARA STACK 'stack'
			DW 12 DUP(?)
stacksg		ENDS
codesg		SEGMENT PARA 'code'
			ASSUME DS:datasg, SS:stacksg, CS:codesg	
			
INSERTIONSORT PROC NEAR
			
			XOR SI,SI ; i in for loop, j in while loop
			INC SI
			
			XOR BX,BX ; j-1 in while loop
			
insertionFor:
			CMP SI,CX
			JE sortCompleted
			
			PUSH SI ;SI = j=i
			MOV AL,OBP[SI] ; AL represents tmp 
			
insertionWhile:
			
			CMP AL,OBP[BX]
			JB whileOut ; finds number's location and end while
			
;inside while------------------
			
			MOV AH, OBP[BX] ; BL <- OBP [j-1]
			MOV OBP[SI],AH ; OBP[j]<- AH
			
			DEC SI ; j--	
			DEC BX; j-1 -- 
			
			CMP SI,0 
			JZ whileOut ;  j=0 condition, beginning of array, end while
			
			JMP insertionWhile
whileOut:
			
			MOV OBP[SI],AL
			
			POP SI
			MOV BX,SI
			INC SI

			JMP insertionFor
			
sortCompleted:	RET	

INSERTIONSORT ENDP	
	
MAIN		PROC FAR
			PUSH DS
			XOR AX,AX
			PUSH AX
			MOV AX, datasg
			MOV DS,AX
			
			XOR DX,DX
			XOR SI,SI

			MOV CX,len
			MOV DX, 10 
			
			MOV BH, 4
			MOV BL, 6 


createOBP:	CMP SI,CX
			JE endArray
			
			PUSH CX
						
			XOR AX,AX ; represents total
			MOV AL, vize[SI]
			MUL BH

			MOV CX, AX; CX represents temp
			
			XOR AX,AX
			
			MOV AL, final[SI]
			MUL BL	
			ADD AX, CX;
			DIV DL
			
			CMP AH, 5
			JB roundDown
			INC AL ;to round up
			
roundDown:  MOV  OBP[SI], AL
			
			POP CX
			INC SI
			JMP createOBP
			
endArray:	
			CALL INSERTIONSORT
			RETF
MAIN ENDP
codesg ENDS
END  MAIN
