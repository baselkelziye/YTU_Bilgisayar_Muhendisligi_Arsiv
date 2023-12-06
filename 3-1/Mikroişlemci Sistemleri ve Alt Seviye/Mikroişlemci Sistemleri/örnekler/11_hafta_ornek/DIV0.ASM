        PAGE 60,80
        TITLE ornek____
    
STACKSG SEGMENT PARA STACK 'STACK'
        DW 12 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
DIZI1       DW 1,2,3,4,5,6,7
DIZI2       DW 1,0,3,4,5,6,7
ELEMAN      DW 7
OLDOF       DW 0
OLDSG       DW 0   

DATASG ENDS

CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

NEWINT  PROC FAR
        PUSH BP
        MOV BP, SP
        MOV AX, [BP+2]
        ADD AX, 2
        MOV [BP+2], AX
        MOV AX, 0FFFFH
        POP BP

        IRET
NEWINT  ENDP

BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DATASG
        MOV DS, AX

        XOR AX, AX
        MOV ES, AX
        MOV AX, WORD PTR ES:[0]
        MOV OLDOF, AX
        MOV AX, WORD PTR ES:[2]
        MOV OLDSG, AX
        LEA AX, NEWINT
        MOV WORD PTR ES:[0], AX
        MOV AX, CS
        MOV WORD PTR ES:[2], AX        

	STI
        XOR SI, SI

        MOV CX, ELEMAN

 TEKRAR:      
        XOR DX, DX
        MOV AX, DIZI1[SI]
        MOV BX, DIZI2[SI]
        DIV BX
        ADD SI, 2

        LOOP TEKRAR
        
        XOR AX, AX
        MOV ES, AX
        MOV AX, OLDOF
        MOV WORD PTR ES:[0], AX
        MOV AX, OLDSG
        MOV WORD PTR ES:[2], AX
        


        RETF
BASLA   ENDP

CODESG  ENDS
        END BASLA