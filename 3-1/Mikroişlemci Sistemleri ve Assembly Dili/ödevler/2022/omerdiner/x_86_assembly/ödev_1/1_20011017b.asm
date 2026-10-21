STACKSEG SEGMENT PARA STACK 'stackssg'

DW 200 DUP(?)

STACKSEG ENDS

DATASEG  SEGMENT PARA 'datassg'

n DW 500
sonuc DW ?
dizi DW 0,1,1, 997 DUP(-5)
sifirdurumu DB '0','$'

DATASEG ENDS

CODESEG  SEGMENT PARA 'codessg'
        ASSUME CS:CODESEG, DS:DATASEG, SS:STACKSEG

ANA	PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DATASEG
        MOV DS, AX
		
        PUSH n
		CALL FAR PTR DNUM
		POP sonuc
		
		PUSH sonuc
		CALL FAR PTR PRINTINT
		
        RETF
ANA   ENDP

DNUM	PROC FAR
		PUSH BP
		PUSH AX
		PUSH CX
		PUSH BX
		PUSH DI
        MOV BP, SP
        XOR DI,DI
		MOV BX, [BP+14] ; n değerini al
		MOV DI, BX
		ADD DI, DI
		MOV CX, dizi[DI]                                              
		CMP CX,0
		JGE MEVCUT
		MOV AX, BX
		DEC BX
		PUSH BX
		CALL FAR PTR DNUM ;d(n-1)
		CALL FAR PTR DNUM ;d(d(n-1))
		POP CX
		DEC AX
		DEC AX
		PUSH AX
		CALL FAR PTR DNUM ;d(n-2)
		POP BX
		INC AX
		SUB AX, BX
		PUSH AX
		CALL FAR PTR DNUM ; d(n-1-d(n-2))
		POP BX
		ADD CX, BX
		MOV WORD PTR dizi[DI], CX ; diziye yerleştir
MEVCUT:	MOV [BP+14], CX
		POP DI
		POP BX
		POP CX
		POP AX
		POP BP	
		RETF 
DNUM ENDP

PRINTINT PROC FAR
        
		PUSH BP
		PUSH AX
		PUSH BX
		PUSH CX
		PUSH DX
		MOV BP,SP
		MOV AX,[BP+14]  ; yazdıracağımız sayının tutulduğu yer
		XOR CX,CX    ; basamak sayısını tutacak

BASAMAKLARI_BUL:
		XOR DX,DX
        CMP AX,0
        JE YAZDIR  ; 0'sa direkt yazdır   
         
        MOV BX,10      ;10'a bölerek ilerlicez  
        DIV BX                    
        PUSH DX      ;kalanı stacke at       
        INC CX            
        JMP BASAMAKLARI_BUL
YAZDIR:  
        CMP CX,0
        JE SIFIR_DURUMU
                
        POP DX
        ADD DX,48  ; ascii karşılığına gelsin diye 48 ekliyoruz . 
        
        MOV AH,02h
        INT 21h
        
        LOOP YAZDIR
		JMP SON_
SIFIR_DURUMU:	
             MOV DX,OFFSET sifirdurumu
		     MOV AH,09H
		     INT 21H
SON_:   
        ;registerleri korumak amaçlı
        POP DX
		POP CX
		POP BX
		POP AX
		POP BP
		
        RETF 2     
PRINTINT ENDP

CODESEG  ENDS
        END ANA