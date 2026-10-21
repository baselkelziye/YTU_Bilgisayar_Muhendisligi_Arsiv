codeseg SEGMENT PARA 'CODE'
    ORG 100H
    ASSUME CS:codeseg, SS:codeseg, DS:codeseg, ES:codeseg

BASLA: JMP MAIN
    primeOddSum DB 15 DUP(0)
    nonPrimeOrEvenSum DB 15 DUP(0)
    n1 DB 0 ;primeOddSum dizisinin boyutu
    n2 DB 0 ;nonPrimeOrEvenSum dizisinin boyutu

    MAIN PROC NEAR
        MOV SI, 1 ; a = 1
        XOR DI, DI ; b = 0

loop1:  MOV DI, SI ; b = a

loop2:  MOV AX, SI ; AX = SI (a)
        MOV BX, SI ; BX = SI (a), a<50 oldugu icin BL'ye atanir.
        MUL BL ; AX = a*a
        MOV DX, AX ; DX = a*a

        MOV AX, DI ; AX = DI (b)
        MOV BX, DI ; BX = DI (b), b<50 oldugu icin BL'ye atanir.
        MUL BL ; AX = b*b
        ADD DX, AX ; DX = a*a + b*b (DX = c^2)

        MOV CX, 0
root:   INC CX ; CX += 1
        MOV AX, CX ; AX = CX
        MUL CL ; AX = CL * CL
        CMP AX, DX ; CX*CX < c^2 oldugu surece devam eder.
        JB root

        CMP AX, DX ; sqrt(DX) tam sayi mi kontrolu
        JNE next 

        CMP CL, 50 ; sqrt(DX) yani CL <= 50 olmali 
        JA next

        MOV AX, SI 
        ADD AX, DI ; AX = SI + DI (a+b) yani dik kenarlar toplami
        TEST AX, 1 ; son bit 1 mi? 1 ise tek degilse cift
        JZ  nonPrimeOrEven ; ciftse direkt atla, tekse asalligi kontrol et

        MOV BX, 1
        MOV DX, CX ; DX = CX
        SHR DX, 1 ; DX = DX / 2, sayinin yarisina kadar bolunup bolunmedigi test edilir.
checkPrime:
        INC BX
        MOV AX, CX ; AX = CX
        DIV BL ; AH = CL % BL
        CMP AH, 0 ; AH == 0 ise kalan yoktur, sayi asal degildir.
        JE nonPrimeOrEven
        CMP BX, DX ; BX < DX oldugu surece kontrol devam eder.
        JB checkPrime

        CMP n1, 0 ; Dizinin boyutu 0 ise direkt diziye eklenir.
        JE add1 ; Dizinin boyutu 0'dan buyukse CX dizide aranir.
        XOR BX, BX ; BX = 0
        XOR DX, DX ; DH = 0
        MOV DL, n1 ; DL = n1        
find1:  CMP primeOddSum[BX], CL 
        JE next ; Eger sayi dizide varsa eklenmeden devam edilir.
        INC BX        
        CMP BX, DX ; BX < n1 oldugu surece arama islemi devam eder.
        JB find1

add1:   XOR BX, BX ; BH = 0
        MOV BL, n1 ; BL = n1
        MOV primeOddSum[BX], CL ; primeOddSum[n1] = CX
        INC n1        
        JMP next

nonPrimeOrEven:
        CMP n2, 0 ; Dizinin boyutu 0 ise direkt diziye eklenir.
        JE add2 ; Dizinin boyutu 0'dan buyukse CX dizide aranir.
        XOR BX, BX ; BX = 0
        XOR DX, DX ; DH = 0
        MOV DL, n2 ; DL = n2             
find2:  CMP nonPrimeOrEvenSum[BX], CL
        JE next ; Eger sayi dizide varsa eklenmeden devam edilir.
        INC BX        
        CMP BX, DX ; BX < n2 oldugu surece arama islemi devam eder.
        JB find2

add2:   XOR BX, BX ; BH = 0
        MOV BL, n2 ; BL = n2
        MOV nonPrimeOrEvenSum[BX], CL ; nonPrimeOrEvenSum[n2] = CX
        INC n2

next:   INC DI ;loop2 kontrol kismi
        CMP DI, 50
        JAE end2 ; JAE loop2 range disinda oldugu icin iki asamali atlama yapilir.
        JMP loop2    

end2:   INC SI ;loop1 kontrol kismi
        CMP SI, 50
        JAE end1 ; JAE loop1 range disinda oldugu icin iki asamali atlama yapilir.
        JMP loop1

end1:   RET        
    MAIN ENDP
codeseg ENDS
    END BASLA