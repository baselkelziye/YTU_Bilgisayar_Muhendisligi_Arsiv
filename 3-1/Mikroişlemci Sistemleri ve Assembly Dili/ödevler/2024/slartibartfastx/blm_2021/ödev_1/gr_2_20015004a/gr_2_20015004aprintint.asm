PUBLIC PRINTINT
mycode1	SEGMENT PARA 'k'
        RES  DB 3 DUP ('$');degerin konulacagi string
		ASSUME CS:mycode1
		PRINTINT	PROC FAR
			MOV BP, SP
			MOV AX, [BP+4];DNUM'dan gelen sonucu stackten aldik
							
			
			LEA SI, RES	;arrayin efektif adresini SI'ya koyduk			
			MOV CX, 0
			MOV BX, 10
            ;L2'deki islemlere integerin ascii valuelarini bulduk
L2: 		MOV DX,0 
			DIV BX;ona bolerek her basamak hesaplanir
			ADD DL,30H ;30h ile ascii valuesu hesaplanir
			PUSH DX
			INC CX
			CMP AX,9;10dan kucuk olana kadar tekrarlanir
			JG L2
     
			ADD AL,30H
			MOV [SI],AL
     
L3: 		POP AX
			INC SI
			MOV [SI],AL
			LOOP L3			
			
			LEA DX,RES
			MOV AH,9
			INT 21H ;bu interrupted ile stringi output olarak yazdirdik 09h - WRITE STRING TO STANDARD OUTPUT
            
			MOV AH,4CH
			INT 21H 
			
			RET FAR
PRINTINT	ENDP

mycode1 ENDS
		END