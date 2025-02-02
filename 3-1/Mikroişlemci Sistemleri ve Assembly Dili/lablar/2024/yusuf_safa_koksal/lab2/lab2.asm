mys SEGMENT PARA 'hepsi'
    ORG 100h
    ASSUME CS:mys, SS:mys, DS:mys
BASLA : JMP HIPOTENUS
    primeOddSum DB 15 DUP(0)
    nonPrimeOrEvenSum DB 15 DUP(0)
    primeIndex DW 0
    nonPrimeIndex DW 0
    c_kareLimit Dw 2500
    c_limit DB 50
    c_kare DW ?
    kosul1 DB 0
    kosul2 DB 0
HIPOTENUS PROC NEAR
        MOV SI, 1
        outerloop:
            CMP SI, 49
            JBE atla1
            JMP SON  ;uzun atlama icin jmp
            atla1:MOV DI, SI
            INC DI
            innerloop:
                CMP DI, 50
                JBE atla2
                JMP outerloopgec ;uzun atlama icin jump
                atla2:MOV AX, DI
                MOV CL, AL
                MUL CL
                MOV DX, AX
                MOV AX, SI
                MOV CL, AL
                MUL CL
                ADD AX, DX
                CMP AX, c_kareLimit
                JBE atla3
                JMP innerloopdevam ;uzun atlama icin jump
                atla3:MOV c_kare, AX
                MOV BX, 5
                tamkarekontroldongu:
                    MOV AX, BX
                    MOV CL, BL
                    MUL CL  ; AX <-- k^2 olur 
                    CMP AX, c_kare
                    JE hipotenusbulundu
                    CMP AX, c_kare
                    JBE atla4
                    JMP innerloopdevam
                    atla4:INC BX
                    JMP tamkarekontroldongu
                    hipotenusbulundu:
                        tekCiftKontrol:
                            XOR AX, AX
                            MOV AX, SI
                            ADD AX, DI
                            TEST AX, 0001h
                            JZ cift
                            MOV AX, 1
                            MOV kosul2, AL
                            JMP asalKontrol
                            cift:
                                MOV AX, 0
                                MOV kosul2, AL
                        asalKontrol:
                            MOV CX, BX ;CX <-- hipotenus
                            MOV BX, 2
                            asalKontrolDongu:
                                MOV AX, CX
                                CMP AX, BX
                                JBE asal
                                DIV BL
                                CMP AH, 0
                                JE asaldegil
                                INC BX
                                JMP asalKontrolDongu
                                asal:
                                    MOV DX, 1
                                    MOV kosul1, DL
                                    JMP diziyeAta
                                asaldegil:
                                    MOV DX, 0
                                    MOV kosul1, DL
                                    JMP diziyeAta
                        diziyeAta:
                            MOV AH, kosul1
                            MOV AL, kosul2
                            CMP AH,1
                            JNE nonPrimeDiziKontrol
                            CMP AL,1
                            JNE nonPrimeDiziKontrol
                            primeDiziKontrol:
                                MOV BX, 0
                                primeDiziKontrolDongu:
                                    MOV AX, primeIndex
                                    CMP BX, AX
                                    JA primeDiziEkle
                                    MOV DL, primeOddSum[BX]
                                    CMP DL, CL
                                    JE innerloopdevam
                                    INC BX
                                    JMP primeDiziKontrolDongu
                                    primeDiziEkle:
                                        MOV BX, primeIndex
                                        MOV primeOddSum[BX], CL
                                        INC BX
                                        MOV primeIndex, BX
                                        JMP innerloopdevam
                            nonPrimeDiziKontrol:
                                MOV BX, 0
                                nonPrimeDiziKontrolDongu:
                                    MOV AX, nonPrimeIndex
                                    CMP BX, AX
                                    JA nonPrimeDiziEkle
                                    MOV DL, nonPrimeOrEvenSum[BX]
                                    CMP DL, CL
                                    JE innerloopdevam
                                    INC BX
                                    JMP nonPrimeDiziKontrolDongu
                                    nonPrimeDiziEkle:
                                        MOV BX, nonPrimeIndex
                                        MOV nonPrimeOrEvenSum[BX], CL
                                        INC BX
                                        MOV nonPrimeIndex, BX
                innerloopdevam:
                    INC DI
                    JMP innerloop
                outerloopgec:
                    INC SI
                    JMP outerloop
SON:    RET
HIPOTENUS ENDP 
mys ENDS
    END BASLA