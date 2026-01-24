;  MEAN SQUARED ERROR (MSE) HESAPLAMA

STK SEGMENT PARA STACK 'STACK'
        DW 30 DUP(?)
STK ENDS

DSG SEGMENT PARA 'DATA'
        SUM     DD    0         
        MSE     DW    0
        VAR     DB  FBH              
        D1      DW   10,  1, -3,  7,  0
        D2      DW    5,  5,  8, -6,  9
        N       DW    5
DSG ENDS

CSG SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:CSG, SS:CSG   
START PROC                              

        PUSH  DS
        XOR   AX, AX
        PUSH  AX
        MOV   AX, STK                  

        XOR   AX, AX
        MOV   [SUM],   AX               
        MOV   [SUM+2], AX

        LEA   SI, D1
        LEA   DI, D2
        MOV   CX, N           

    CALC_LOOP:
        MOV   AX, [SI]
        MOV   BX, [DI]

        SUB   AX, BX          
        JAE   NONNEG                    
        NOT   AX                        
    NONNEG:
        IMUL  BX                        

        ADD   [SUM],   AX
        ADD   [SUM+2], DX               

        ADD   SI, 1                     
        ADD   DI, 1
        LOOP  CALC_LOOP

        MOV   DX, [SUM]                 
        MOV   AX, [SUM+2]
        DIV   CL                
        MOV   MSE, AX

    RET 
START ENDP
CSG ENDS

END START
