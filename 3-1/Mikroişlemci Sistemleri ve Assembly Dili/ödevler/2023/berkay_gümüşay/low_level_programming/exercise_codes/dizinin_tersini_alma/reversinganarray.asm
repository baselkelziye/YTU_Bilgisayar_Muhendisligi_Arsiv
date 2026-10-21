mySS SEGMENT STACK PARA 'STACK'
    DW 20 (?)
mySS ENDS

myDS SEGMENT PARA 'DATA'
    dizi db 1,2,3,4,5,6,7
    uzunluk db 7
    bol db 2
myDS ENDS

myCODE SEGMENT PARA 'CODE'
    ASSUME SS:MYSS,DS:MYDS,CS:MYCODE
MAIN PROC FAR
    PUSH DS
    XOR AX,AX
    PUSH AX
    MOV AX,myDS
    MOV DS,AX
    ; AL = BASTAKI SAYI / AH = SONDAKI SAYI / CX = LOOP
    MOV SI,OFFSET dizi
    LEA DI,dizi[6]
    MOV AL,uzunluk
    XOR AH,AH
    DIV bol
    XOR AH,AH
    CBW
    MOV CX,AX
L1: MOV AL,[SI]
    MOV AH,[DI]
    XCHG AL,AH
    MOV [SI],AL
    MOV [DI],AH
    INC SI
    DEC DI
    LOOP L1  
    MOV CX,7
    XOR AH,AH
    MOV BX, OFFSET dizi
L2: MOV AL,[BX]
    INC BX
    LOOP L2
   RETF
    MAIN ENDP
myCODE ENDS
    END MAIN