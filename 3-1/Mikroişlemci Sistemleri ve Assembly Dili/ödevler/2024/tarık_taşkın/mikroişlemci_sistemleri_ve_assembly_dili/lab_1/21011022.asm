dataseg SEGMENT PARA 'dataseg'
    ;vize DB 96, 64, 85, 77
    ;final DB 74, 86, 63, 56
    ;obp DB 4 DUP(?)
    ;siraliObp DB 4 DUP(?)
    ;n DW 4

    vize DB 0, 10, 64, 85, 100, 33, 12, 100
    final DB 0, 54, 46, 69, 90, 80, 2, 100
    obp DB 8 DUP(?)
    siraliObp DB 8 DUP(?)
    n DW 8
dataseg ENDS

stackseg SEGMENT PARA STACK 'stackseg'
    DW 10 DUP(?)
stackseg ENDS

codeseg SEGMENT PARA 'codeseg'
    ASSUME CS:codeseg, DS:dataseg, SS:stackseg
    MAIN PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, dataseg
        MOV DS, AX

        MOV CX, n
        XOR SI, SI ; i = 0
        
loop1:  MOV AL, vize[SI] ; AL = vize[i]
        MOV BL, 4 
        MUL BL ; AX = AL * 4
        MOV DX, AX ; DX = AX
               
        MOV AL, final[SI] ; AL = final[i]
        MOV BL, 6 
        MUL BL ; AX = AL * 6
        ADD AX, DX ; AX = AX + DX
        MOV BL, 10 
        DIV BL ; AX = AX / 10, AL = (vize*4 + final*6)/10
        CMP AH, 5 ; eger AH >= 5 ise sayi uste yuvarlanir.
        JB noround
        ADD AL, 1 
noround:MOV obp[SI], AL
        MOV siraliObp[SI], AL ; obp degerleri bu dizide asagidaki dongude siralanacaktir.
        INC SI
        LOOP loop1

        MOV CX, n
        DEC CX ; CX = n-1
        XOR SI, SI ; i = 0

outer:  MOV BX, SI ; max = i
        MOV DI, SI ; j = i
        INC DI ; j = i + 1
inner:  MOV AL, siraliObp[DI] ; AL = siraliObp[j]
        CMP AL, siraliObp[BX] ; siraliObp[j] > siraliObp[max] ise max = j olarak guncellenir.
        JBE noswap
        MOV BX, DI
noswap: INC DI ; j++
        CMP DI, n ; icteki dongu j != n oldugu surece devam eder
        JNE inner 

        MOV AL, siraliObp[SI] ; siraliObp[i] ile siraliObp[max] yer degistirir.
        XCHG siraliObp[BX], AL 
        MOV siraliObp[SI], AL 
        INC SI ; i++
        LOOP outer
        
        RETF
    MAIN ENDP
codeseg ENDS
    END MAIN