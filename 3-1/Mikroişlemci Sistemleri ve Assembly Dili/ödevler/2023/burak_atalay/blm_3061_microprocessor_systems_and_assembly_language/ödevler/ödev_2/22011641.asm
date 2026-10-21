
CDSG SEGMENT PARA 'CDSGM'
    ORG 100H
    ASSUME CS:CDSG, SS:CDSG, DS:CDSG, ES:CDSG
BILGI: JMP ANA ;to be able to define the data at the beginning
    nonPrimeOrEvenSum DB 15 DUP(0)
    primeOddSum DB 15 DUP(0)

    ANA PROC NEAR

    XOR SI, SI ;used for indexing nonPrimeOrEvenSum array
    XOR DI, DI ;used for indexing primeOddSum array
    XOR CX, CX
    MOV CL, 50
    
L1:

    MOV DH, CL ;DH will store the a value of Pythagorean theorem in the inner loop
    PUSH CX ;storing CX value of outer loop

L2:

    MOV AL, DH ;calculating a^2
    MUL AL
    MOV BX, AX
    MOV AL, CL ;calculating b^2 using CX of inner loop
    MUL AL
    ADD AX, BX ;calculating a^2 + b^2 = c^2
    CALL SQRT ;calling sqrt function to find c, c will be stored in DL
    CMP DL, 50 ;checking if c is bigger than 50 
    JA BREAKINNERLOOP ;CX in second loop (b) is increasing so if sqrt(a^2 + b^2) = c exceeds 50 we can break the inner loop 
    CMP AX, BX ;if AX becomes bigger than BX then c is not integer 
    JNZ CONT ;if c is not integer we can skip this step
    TEST DL, 1 ;checking if c is even
    JZ NONPRIMEOREVEN ;if it is even we can add it to nonPrimeOrEvenSum
    PUSH CX ;storing CX value of inner loop since it will be used in ISPRIME
    CALL ISPRIME ;calling ISPRIME to check whether c is prime if c is odd
    POP CX
    CMP AH, 0 ;checking if the remainder is 0 after ISPRIME
    JZ NONPRIMEOREVEN ;if it is 0 then we can add it to nonPrimeOrEvenSum
    MOV primeOddSum[DI], DL ;if it is not zero then it means it is both odd and prime
    INC DI
    JMP CONT
NONPRIMEOREVEN:
    PUSH CX ;storing CX value of inner loop since it will be used in ADDTONONPRIMEOREVEN
    CALL ADDTONONPRIMEOREVEN ;this will check whether c is added before in this array and will add it if not
    POP CX
CONT:
    CMP CX, 50 
    INC CX
    JB L2 ;if CX becomes 50 in inner loop we should break the loop since it is manually incremented after cmp
BREAKINNERLOOP:
    POP CX
    LOOP L1

    RET
ANA ENDP

;complexity of this algorithm is O(sqrt(n))
SQRT PROC NEAR ;we will increment DL until its square exceeds c^2 
    MOV BX, AX ;storing c^2 in BX
    XOR DL, DL
sqrtL:
    INC DL
    MOV AL, DL
    MUL AL ;AX will store square of DL
    CMP AX, BX
    JB sqrtL ;continue until AX is less than BX
    RET ;AX will be equal to BX if c is integer if not AX will be bigger than BX
SQRT ENDP

;complexity of this algorithm is also O(sqrt(n)) from O(2 * sqrt(n))
ISPRIME PROC NEAR ;after this function we will look AH to determine whether c is prime
    XOR CX, CX ;xor CX to use it in the loop
    XOR AX, AX 
    MOV AL, DL ;AL will store c
    CALL SQRT ;finding sqrt(c) which will be stored in DL to use it in the algorithm
    MOV CL, DL ;initialzing CL for the loop
    DEC CL ;we need to look the remainder of c in range [2, sqrt(c)] so loop iterates sqrt(c) - 1 times 
    MOV DL, BL ;BL stores c after sqrt function is done so we move the value to DL to add it to the appropriate array after ISPRIME
P:  
    MOV AX, BX ;storing c in AX in each iteration before DIV
    INC CL ;since CL will get values in range [1, sqrt(c) - 1] in the loop we need to increment it before DIV and after decrement it
    DIV CL
    CMP AH, 0 ;if AX % CL is 0 then this is not prime
    JZ NOTPRIME
    DEC CL ;decrementing CL after operation is done to not cause an infinite loop
    LOOP P
NOTPRIME: ;AH will be zero after early exit and nonzero if it completes the loop
    RET
ISPRIME ENDP

ADDTONONPRIMEOREVEN PROC NEAR ;this function does linear search to find whether DL is added before to nonPrimeOrEvenSum
    CMP SI, 0
    JZ FIRSTADD ;if it is the first time we will add the item since there is nothing to search
    MOV CX, SI
    MOV BX, SI
FIND:
    DEC BX
    CMP nonPrimeOrEvenSum[BX], DL
    JZ FOUND ;it wont be added
    LOOP FIND
FIRSTADD:    
    MOV nonPrimeOrEvenSum[SI], DL
    INC SI
FOUND:
    RET
ADDTONONPRIMEOREVEN ENDP

CDSG ENDS

END BILGI