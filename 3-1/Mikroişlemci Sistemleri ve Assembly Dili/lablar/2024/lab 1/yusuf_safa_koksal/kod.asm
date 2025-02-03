datasg SEGMENT PARA 'veri'
    n DW 4
    vize DB 77,85,64,96
    final DB 56,63,86,74
    obp DB 4 DUP(0)
    ortalama DW ?
    virgul DB ?
datasg ENDS

stacksg SEGMENT PARA STACK 'yigin'
    DW 20 DUP(3)
stacksg ENDS

codesg SEGMENT PARA 'kod'
        ASSUME cs:codesg, ss:stacksg, ds:datasg
        MAIN PROC FAR
            PUSH DS
            XOR AX, AX
            PUSH AX
            MOV AX, datasg
            MOV DS, AX
            
            MOV CX, n
            XOR SI, SI
            dongu:
                XOR AX, AX
                MOV AL, BYTE PTR vize[SI]
                MOV BL, 4
                MUL BL
                MOV DX, AX
                XOR AX, AX
                MOV AL, BYTE PTR final[SI]
                MOV BL, 6
                MUL BL
                ADD AX, DX
                ADC AX, 0

                MOV BL, 10
                DIV BL  ; AH <-- virgulden sonraki kisim olur
                CMP AH, 5
                JB L1
                INC AL
                L1:
                    MOV BYTE PTR obp[SI], AL
                    INC SI
                    LOOP dongu
                

                XOR SI, SI
                XOR DI, DI
                MOV CH, BYTE PTR n
                SUB CH, 2
                MOV CL, BYTE PTR n
                DEC CL

                outerloop:
                    MOV BX, SI
                    CMP BL, CH
                    JA son
                    MOV DI,SI
                    INC DI

                    innerloop:
                        MOV AL, obp[SI]
                        CMP AL, obp[DI]
                        JA devam
                        XCHG AL, obp[DI]
                        MOV obp[SI], AL
                        devam:
                            INC DI
                            MOV BX, DI
                            CMP BL, CL
                            JA outerloopartir
                            JMP innerloop
                            outerloopartir:
                                INC SI
                                JMP outerloop
                son:
                    RETF
        MAIN ENDP
codesg ENDS
    END MAIN