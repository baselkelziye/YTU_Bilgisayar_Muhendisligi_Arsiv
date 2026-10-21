STK SEGMENT PARA STACK 'STACK'
        DW 30 DUP(?)
STK ENDS

DSG SEGMENT PARA 'DATA'
        SUM     DD    0
        MSE     DW    0

        D1      DW   10,  1, -3,  7,  0
        D2      DW    5,  5,  8, -6,  9
        N       DW    5
DSG ENDS

CSG SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:DSG, SS:STK
START PROC                              

        PUSH  DS
        XOR   AX, AX
        PUSH  AX
        MOV   AX, DSG
        MOV DS,AX

        XOR   AX, AX
        MOV   WORD PTR [SUM],   AX               
        MOV   WORD PTR [SUM+2], AX

        LEA   SI, D1
        LEA   DI, D2
        MOV   CX, [N]

    CALC_LOOP:
        MOV   AX, [SI]
        MOV   BX, [DI]

        SUB   AX, BX          
        JGE   NONNEG                    
        NEG   AX        
    NONNEG:
        MUL  AX        ;unsigned           

        ADD   WORD PTR [SUM],   AX
        ADC   WORD PTR [SUM+2], DX

        ADD   SI, 2
        ADD   DI, 2
        LOOP  CALC_LOOP

        MOV   AX, WORD PTR [SUM]         
        MOV   DX, WORD PTR [SUM+2] 
        DIV   [N]
        MOV   MSE, AX

    RET 
START ENDP
CSG ENDS

END START