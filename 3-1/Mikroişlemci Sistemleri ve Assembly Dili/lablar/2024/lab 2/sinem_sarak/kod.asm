CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
START:  JMP MAIN

; Data definitions for arrays and constants
primeOddSum DB 15 DUP(0)
nonPrimeOrEvenSum DB 15 DUP(0)
maxLengthSquare DW 2500
maxLength DW 50
;Data definition ends

MAIN   PROC NEAR
		XOR BX,BX ; BX will be used for index for primeOddSum
		XOR DI,DI ; DI will be used for index for nonPrimeOrEvenSum
		XOR AX,AX
		
fTFor: 
		; Outer for loop to count edge a from 1 to maxLength (50)
		
		INC SI ; Increment SI to represent side 'i'
		CMP SI,maxLength
		JA trianglesFound ; If exceeded, that means all triangles found
		
		PUSH SI ; Store current 'i' value in stack
		
		MOV AX,SI
		MUL AL 
		MOV DX,AX  ;Store i^2 in DX
		XOR AX,AX
	
nextTriangle:
		; ; Inner while loop to count edge b from 1 to maxLength (50)
		
		INC SI ; Increment SI to represent side 'j'
		CMP SI,maxLength
		JA fTWhileEnd ; End the inner loop and return to for if 'j' > maxLength
		
		MOV AX,SI ;AX = j
		MUL AL ;AX = j^2
		
		ADD AX,DX ; AX = i^2+j^2 = hyp^2
		
		CMP AX,maxLengthSquare ;hyp <= 50, that's why hyp^2<=2500
		JA fTWhileEnd ; If exceeded, skip this edge a value. 
		
		; Since b > a+1 and b is increasing in this for loop, we can say if that hyp^2 > 2500 for the current values 
		; of a and b it will exceed 2500 for all subsequent values of b in this while loop. To avoid unnecessary calculations,
		; we can skip the remaining iterations of the while loop and start a new iteration with new a value.

		PUSH BX ; BX = primeOddSumIndex pushed to stack
		PUSH DX ; DX = i^2 pushed to stack
		PUSH AX ;  AX = hyp^2  pushed to stack

		CALL GETROOT
		
		POP AX
		POP DX 
		POP BX 		
		;BX = primeOddSumIndex, DX = i^2 , AX = hyp^2   CX square root of hyp^2 (if it’s a perfect square, else 0)

		CMP CX,0
		JE nextTriangle ; If CX=0 that means hyp value is not integer , skip this triangle
		
		PUSH DX ; DX = i^2 pushed to stack
		PUSH SI ;  SI = j pushed to stack
		CALL CHECKALREADYADDED
		POP SI
		POP DX 
		;BX = primeOddSumIndex, DX = i^2 , AX = 0 if not already added, 1 if added), CX = hyp

		CMP AX,0 ; AX = 0 if not already added, 1 if added
		JNE nextTriangle

		PUSH BX ; BX = primeOddSumIndex pushed to stack
		PUSH CX ; CX = hyp pushed to stack
		PUSH DX ; DX = i^2 pushed to stack
		
		CALL CHECKPRIMARY ; Check if hypotenuse is prime
		
		POP DX 
		POP CX
		POP BX
		; AX = 1 if prime , 0 if nonprime ; BX = primeOddSumIndex ; CX = hyp ; i^2 popped from stack

		CMP AX,0
		JE addNPOES ; If hypotenuse is not prime, add to nonPrimeOrEvenSum
		
		; Check if the sum of edges is odd
		
		XOR AX,AX
		POP AX ; AX = i
		PUSH AX ; Push i back to stack
		ADD AX,SI ; AX = i+j

		MOV CH,2
		DIV CH
		CMP AH,0
		JE addNPOES  ; If even, add to nonPrimeOrEvenSum
		
		; If satisfied two condition add to primeOddSum
		MOV primeOddSum[BX],CL
		INC BX
		JMP nextTriangle
		
addNPOES:
		; If one of the conditions not met, add hypotenuse to nonPrimeOrEvenSum
		MOV nonPrimeOrEvenSum[DI],CL
		INC DI ; Increase j
		JMP nextTriangle
		
fTWhileEnd: 
		POP SI ; Pull i to SI
		JMP fTFor ; Continue outer for loop
		
trianglesFound: 
        RET
MAIN   ENDP


; CHECKALREADYADDED: Check if hypotenuse is already added to one of the arrays
CHECKALREADYADDED PROC NEAR

	; CX = SQRT(T), CL = Hypotenuse value to check	
	XOR DX,DX
	XOR SI,SI
checkArr1:
	
	CMP SI,DI
	JE notFound1
	MOV DL,nonPrimeOrEvenSum[SI]
	CMP CL,DL 
	JE alreadyAdded
	INC SI
	JMP checkArr1
	
notFound1:
	XOR SI,SI
	
checkArr2:
	CMP SI,BX
	JE notFound2
	MOV DL,primeOddSum[SI]
	CMP CL,DL
	JE alreadyAdded
	INC SI
	JMP checkArr2


notFound2:
	XOR AX,AX
	JMP finishProc

alreadyAdded:

	XOR AX,AX
	INC AX
	
	
finishProc:	RET
CHECKALREADYADDED ENDP

; CHECKPRIMARY: Check if hypotenuse is a prime number
CHECKPRIMARY PROC NEAR
	
	; CL = Hypotenuse (to check if prime)
	XOR AX,AX
	MOV AX,CX
	
	XOR BX,BX
	MOV BX,2
	DIV BL
	
	CMP AH,0
	JE nonPrime ; If divisible by 2, it's not prime
	
	PUSH CX
	MOV AX,CX
	CALL GETROOT
	MOV CX,AX ; CX = largest integer <= sqrt(hypotenuse)
	POP AX ; AX = hyp
	MOV BX, 3 ;BX = i, Start division from 3
	
primeWhile:
	CMP BX,CX
	JA prime
	
	PUSH AX
	DIV BL
	CMP AH,0
	POP AX
	JE nonPrime   ; If divisible, not a prime
	
	ADD BX,2 ;Skip even values since number can not be divided by 2 and other even values
	JMP primeWhile 
	
nonPrime:	
	XOR AX,AX ; AX = 0 for non-prime
	JMP finish
	
prime:
	XOR AX,AX
	INC AX ; AX = 1 for prime
	
finish:
	RET
CHECKPRIMARY ENDP

; GETROOT: Calculate square root of a given value
GETROOT PROC NEAR
	; This procedure calculates the integer square root of a given value using binary search. 
	; The initial left boundary is set to 1 (stored in CX) and the right boundary is set to i^2 + j^2 / 2 (stored in DX). 
	; The midpoint (center) is calculated by averaging the left and right boundaries, then squared and compared to i^2 + j^2 (computed in main).
	; However with values too large(for example 2500 (50^2)) calculating square might overflow.
	; To prevent overflow with large values like 2500 (50^2), an upper limit condition (hyp <= 50) is applied.
	; If the value exceeds this limit, the right boundary is set to 51 (maxLength + 1) instead of i^2 + j^2 / 2.

	; AX = i^2+j^2
	
	PUSH AX 
	
	CMP AX,maxLength
	JB hypDependentRight
	JNB minimisedRight ; If more than maxLength, minimise right to maxLength+1
	
		
		
hypDependentRight:
		MOV BL,2 
		DIV BL  ; AL = i^2+j^2/2 (rolled down)
		XOR AH,AH
		MOV DX,AX ; DX = i^2+j^2/2, DX = right
		JMP commonpath
		

minimisedRight:
		MOV DX,maxLength;DX = right
		INC DX
		
commonpath:
			
		POP BX; ;BX = i^2+j^2
		
		XOR AX,AX ; AX = center
		
		XOR CX,CX ;CX= left 
		INC CX
		
gRWhile:

		INC CX
		CMP CX,DX
		DEC CX
		JNB NonSquareNum ;i^2+j^2 is not a square number
		
		MOV AX,DX ; center = right
		ADD AX,CX ; center = left + right
		
		PUSH BX;
		MOV BL,2 
		DIV BL ; center =center/2 => AL = center, might center%2 in AH
		XOR AH,AH
		POP BX ;BX = i^2+j^2
		PUSH AX ; push center to stack
		MUL AL; center = center^2
		
		CMP AX,BX
		POP AX ; AX = center
		JA changeRight
		JB changeLeft
		JE rootFound
		
changeRight:		
		MOV DX,AX
		JMP gRWhile
		
changeLeft:		
		MOV CX,AX		
		JMP gRWhile

rootFound:
		MOV CX,AX ;CX = sqrt(i^2+j^2)	
		JMP returnLabel

NonSquareNum:		
		
		XOR AX,AX
		MOV AX,CX
		ADD AX,DX
		MOV CL,2
		DIV CL
		XOR AH,AH
		XOR CX,CX
		;if number is nonsquare cx = 0
		;if number is nonsquare AL = root of the biggest square number below i^2+j^2, which will be useful in CHECKPRIMARY
		
returnLabel:
		RET
GETROOT ENDP

CODESG  ENDS
        END START
