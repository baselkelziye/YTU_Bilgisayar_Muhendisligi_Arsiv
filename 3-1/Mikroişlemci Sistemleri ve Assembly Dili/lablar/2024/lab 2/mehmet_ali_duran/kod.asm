codesg  		SEGMENT PARA 'kod'
				ORG 100h
				ASSUME CS:codesg, DS:codesg, SS:codesg
Bilgi:			JMP ANA
n					DW 50
dikUcgenBuldu		DB 0
i2					DW 0
j2					DW 0
k2					DW 0
iDonguAdimi			DW 0
jDonguAdimi			DW 0
kDonguAdimi			DW 0
p 					DW 0
e 					DW 0
primeOddSum			DW 15 DUP(0)
nonPrimeOrEvenSum	DW 15 DUP(0)
limit				DW ?
ANA PROC NEAR
					XOR AX, AX	; AX=0, 
					XOR BX, BX  ; BX=0, i
					XOR CX, CX  ; CX=0, j
					XOR DX, DX	; DX=0, k
					XOR SI, SI
					XOR DI, DI
OuterLoop:	 		INC BX
					CMP BX, n
					JA ARA 
					MOV CX, BX
InnerLoop:			INC CX
					CMP CX, n
					JA OuterLoop
					MOV dikUcgenBuldu, 0
					MOV DX, CX
InnerMostLoop:		INC DX
					CMP DX, n
					JA InnerLoop
					CMP dikUcgenBuldu, 0
					JNE InnerLoop
					MOV iDonguAdimi, BX
					MOV jDonguAdimi, CX
					MOV kDonguAdimi, DX
					MOV AX, BX
					PUSH DX
					MUL AX
					MOV i2, AX
					MOV AX, CX
					MUL AX
					MOV j2, AX
					POP DX
					MOV AX, DX
					PUSH DX
					MUL AX
					POP DX
					MOV k2, AX
					MOV AX, i2
					ADD AX, j2
					CMP AX, k2 ; hipotenus kontrolu
					JNE DegerleriYukle
					MOV dikUcgenBuldu, 1
					MOV AX, iDonguAdimi
					ADD AX, jDonguAdimi
					TEST AX, 0001h
					JZ cift_label
					MOV AX, kDonguAdimi
					MOV CX, 2; i degiskeni icin atadigim 2
					MOV DL, 2; bolme islmi icin atadigim 2
					MOV BX, AX
					DIV DL
					XOR DH, DH ; buralar AL yi saklamak için yani k / 2 yani limit değerini oluşturabilmek için
					MOV DL, AL ;
					MOV AL, AH
					CBW
					CMP DX, DX
					JE ATLAMA
ARA:				JMP Son
ATLAMA:				INC DX
					MOV limit, DX
isPrimeDongu:		MOV AX, BX
					CMP CX, limit
					JAE isPrimeAtama
					XOR DX, DX
					DIV CX				
					CMP DX, 0
					JZ isPrimeAtama
					INC CX
					JMP isPrimeDongu
isPrimeAtama:		CMP CX, limit
					JZ tek_label
cift_label:			MOV AX, kDonguAdimi
					MOV SI, e
					MOV nonPrimeOrEvenSum[SI], AX
					ADD SI, 2
					MOV e, SI
					JMP DegerleriYukle
tek_label:     		MOV AX, kDonguAdimi
					MOV SI, p
					MOV primeOddSum[SI], AX
					ADD SI, 2
					MOV p, SI
DegerleriYukle: 	MOV BX, iDonguAdimi
					MOV CX, jDonguAdimi
					MOV DX, kDonguAdimi
					JMP InnerMostLoop
Son:				RET
ANA 				ENDP
codesg  			ENDS
					END Bilgi