

DSEG	SEGMENT PARA 'DATA'

INPUTARRAY DW 10 DUP(0)
MODE_VAL DW ?
MAXLEN DB 10

CR	EQU 13
LF	EQU 10
INDEXOFIMESSAGE DB 19

WELCOMEMESSAGE	DB 'Hello, please enter the length for your array: ',0
ERRORMESSAGE DB CR,LF, 'Input error, you made an invalid enter. Please enter a number again!! ',0
INVALIDLENGTHMESSAGE DB CR,LF, 'Array length can not be longer than 10. Please enter a number less than 10: ',0
NOMODEMESSAGE DB CR,LF, 'There is no mode in the array',0
GETELEMENTMESSAGE DB CR,LF,'Please enter the i. element of array: ',0
MODEEXISTSMESSAGE DB CR,LF, 'Here is the mode of your array: ',0


DSEG 	ENDS 

SSEG 	SEGMENT PARA STACK 'STACK'
	DW 64 DUP (?)
SSEG 	ENDS


CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, SS:SSEG, DS:DSEG


;--------------------------------------------------------------------
PRINTFNUM MACRO
LOCAL getDecimalNumber,printNumber,donePrint
	PUSH CX
	PUSH DX
	
	XOR DX,DX
	PUSH DX
	
	MOV CX, 10
	CMP AX,0
	JGE getDecimalNumber ;if number is negative print - before number
	
	NEG AX
	PUSH AX
	MOV AL,'-'
	PRINTLETTERM
	POP AX
	
getDecimalNumber:	

	DIV CX
	ADD DX,'0' ;get ascii value of number
	PUSH DX
	XOR DX,DX
	CMP AX,0 ;check if number has remaining digits
	JNE getDecimalNumber
	
printNumber:
	POP AX
	CMP AX,0
	JE donePrint
	PRINTLETTERM
	JMP printNumber
	
donePrint:
	
	POP DX
	POP CX
ENDM		

;--------------------------------------------------------------------
PRINTFM MACRO MESSAGEADDRESS
LOCAL wordloop, doneWord

	PUSH AX
	PUSH BX
	XOR AX,AX
	MOV BX, OFFSET MESSAGEADDRESS
	MOV AL, BYTE PTR [BX]


wordloop:
	CMP AL,0
	JE doneWord
	PRINTLETTERM
	INC BL
	MOV AL, BYTE PTR [BX]
	JMP wordloop
doneWord:

	POP AX
	POP BX
ENDM

;------------------------------------------------------------------

PRINTLETTERM MACRO 
PUSH DX
PUSH AX
MOV DL,AL
MOV AH,2
INT 21H
POP AX
POP DX
ENDM
;-------------------------------------------------------------------

GETDIGIT MACRO
	MOV AH,1h
	INT 21H
ENDM


;-------------------------------------------------------------------

SCANFM MACRO
LOCAL scanfStart, getOneDigit, isNum, inputError, endScan, endScanf
	PUSH DX
	PUSH BX
	PUSH CX

scanfStart:
	
	MOV DX,1
	XOR BX,BX
	XOR CX,CX
	
getOneDigit:

	GETDIGIT
	CMP AL, CR ;check enter button
	JE endScan
	
	CMP AL, '-' ;checking negative values
	JNE isNum
	
	MOV DX, -1 ;if number is here, that means it is negative
	JMP getOneDigit ;get another digit
	
isNum:
	
	CMP AL,'0' ;check if input is a number
	JB inputError
	
	CMP AL,'9'
	JA inputError
	
	SUB AL,'0' ;getting number's value from input which here in ASCII
	MOV BL,AL
	MOV AX,10
	PUSH DX
	MUL CX
	POP DX
	MOV CX,AX
	ADD CX,BX ;add input to existing number
	
	JMP getOneDigit

inputError:

	PRINTFM ERRORMESSAGE
	JMP scanfStart

endScan:
	MOV AX,CX ;input number is in AX

	CMP DX,1;Check if negative
	JE endScanf
	NEG AX 
endScanf:

	POP CX
	POP BX
	POP DX
ENDM

;----------------------------------------------------------------
GIRIS_DIZI MACRO
LOCAL getEachElement

	PUSH CX ;protect length of array
	PUSH BX
	PUSH AX
	PUSH SI
	PUSH DX
	
	MOV DX,2
	XOR SI,SI
	
getEachElement:	
	MOV AX,SI
	DIV DL ; AX = i th element of array
	
	LEA BX, GETELEMENTMESSAGE
	ADD AX, '0'
	ADD BL, INDEXOFIMESSAGE
	MOV [BX],AL
	
	PRINTFM GETELEMENTMESSAGE ;ask user to enter i. element of array

	JMP getElement 
	; Due to the jump instruction's distance limitation, an additional jump label is required.
    ; Since we have to use macros to getting inputs from user and they expand inline with code, this loop is exceeding the jump range.
    ;To solve that problem I created a separate label, `getElement`, and moved one of the macro calls there.
	
saveElement:	
	MOV INPUTARRAY[SI],AX
	ADD SI,2
	
	LOOP getEachElement 
	JMP endGetArray

getElement:
 SCANFM ;element is in AX
 JMP saveElement

endGetArray:

	POP DX
	POP SI
	POP AX
	POP BX
	POP CX
ENDM

;----------------------------------------------------------------

MAIN   PROC FAR

		

		PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DSEG 
        MOV DS, AX

		XOR AX,AX
		
		PRINTFM WELCOMEMESSAGE

getLength:	
		SCANFM ;Get length of array; 
		
		CMP AX,10
		JNG validLength ;if length is grater than 10, ask again
		
		PRINTFM INVALIDLENGTHMESSAGE
		JMP getLength	
		
validLength:		
		
		MOV CX,AX 
		GIRIS_DIZI
		
		
		MOV BX,INPUTARRAY 
		
		PUSH BX ; Transfer of array's location in memory to FINDMOD procedure
		PUSH CX ; Transfer of array's length to FINDMOD procedure
		
		CALL FINDMOD
		
		POP AX ;maxCount
		POP CX ;modeVal

		CMP AX,1
		JNE modExists
		PRINTFM NOMODEMESSAGE
		XOR CX,CX
		MOV MODE_VAL,CX
		JE endMain

modExists:
		
		MOV MODE_VAL,CX
		PRINTFM MODEEXISTSMESSAGE
		MOV AX,CX
		PRINTFNUM
		JE endMain

endMain:
		RETF
MAIN ENDP



	FINDMOD PROC NEAR

		PUSH BP
		PUSH AX
		PUSH BX
		PUSH CX
		PUSH DX
		PUSH SI
		
		MOV BP,SP
		
		
		MOV CX, [BP+14] ; getting length of array from stack
		MOV SI, [BP+16] ; getting address of array from stack
		
		
		PUSH CX ;transfer the length of array to INSERTIONSORT
		
		CALL INSERTIONSORT
		;now i have address and length on top of stack 
		
		POP CX ;get length back
		XOR SI,SI
		DEC CX ;Loop executes N-1 times
		;ADD SI,2
		XOR BX,BX ; modeVal
		XOR AX,AX ; AX = maxCount
		XOR DX,DX ; DX = count
		INC DX
		
	scanArray:
		PUSH AX ;Protect maxCount
		MOV AX,[SI] ;AX = arr[i-1]
		ADD SI,2
		CMP [SI],AX ; if(arr[i-1] == arr[i])
		POP AX	
		JNE elementDifferent
		INC DX
		JMP moveNextElement
		
	elementDifferent:	
		CMP AX,DX 
		JA noNewMode
		MOV AX,DX
		MOV BX,[SI-2]; modeVal = arr[i-1]

	noNewMode:
		XOR DX,DX
		INC DX

	moveNextElement:
		LOOP scanArray
		
		CMP AX,DX ;last control
		JA endProc
		MOV BX,[SI]
		MOV AX,DX
		
		
	;return to modeVal and maxCount to check if mode exists
	;if maxCount = 1, then there is no mode

endProc:
		MOV [BP+14], AX ; maxCount
		MOV [BP+16], BX ; modeVal
		
		
		POP SI
		POP DX
		POP CX
		POP BX
		POP AX
		POP BP

	RET

	FINDMOD ENDP


	INSERTIONSORT PROC NEAR

				PUSH BP
				PUSH SI
				PUSH BX
				PUSH AX
				PUSH CX
				PUSH DX
				
				MOV BP,SP
				MOV CX,[BP+14]
				
				XOR AX,AX
				MOV AX,2
				MUL CL
				MOV CX,AX

				XOR SI,SI ; i in for loop, j in while loop
				INC SI
				INC SI
				
				XOR BX,BX ; j-1 in while loop
				
	insertionFor:
				CMP SI,CX
				JE sortCompleted
				
				PUSH SI ;SI = j=i
				MOV AX,INPUTARRAY[SI] ; Ax represents tmp 
				
	insertionWhile:
				
				CMP AX,INPUTARRAY[BX]
				JB whileOut ; finds number's location and end while
				
	;inside while------------------
				
				MOV DX, INPUTARRAY[BX] ; DX <- INPUTARRAY [j-1]
				MOV INPUTARRAY[SI],DX ; INPUTARRAY[j]<- DX
				
				DEC SI ; j--
				DEC SI
				DEC BX; j-1 -- 
				DEC BX
				
				CMP SI,0 
				JZ whileOut ;  j=0 condition, beginning of array, end while
				
				JMP insertionWhile
	whileOut:
				
				MOV INPUTARRAY[SI],AX
				
				POP SI
				MOV BX,SI
				INC SI
				INC SI
				
				JMP insertionFor
				
	sortCompleted:	
		
		
				POP DX
				POP CX
				POP AX
				POP BX
				POP SI
				POP BP
		
		
		RET	

	INSERTIONSORT ENDP	


CODESG  ENDS
        END MAIN
