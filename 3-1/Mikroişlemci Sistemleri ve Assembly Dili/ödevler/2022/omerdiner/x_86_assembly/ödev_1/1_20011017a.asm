STACKSSEG SEGMENT STACK PARA 'stacksg'

DW 200 DUP(?)

STACKSSEG ENDS

DATASEG SEGMENT PARA 'datasg'

n DW 10
sonuc DW ?
sifirdurumu DB '0','$'

DATASEG ENDS

CODESEG SEGMENT PARA 'codesg'
   ASSUME CS:CODESEG,SS:STACKSSEG,DS:DATASEG

ANA PROC FAR
	PUSH DS
	XOR AX,AX
	PUSH AX
	MOV AX,DATASEG
	MOV DS,AX
	
	PUSH n
	CALL FAR PTR DNUM
	POP sonuc
	
	PUSH sonuc
	CALL FAR PTR PRINTINT
	
	RETF
ANA ENDP

DNUM PROC FAR
	PUSH BP
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
	MOV BP, SP
	MOV AX,[BP+14] ; parametreye erişim
	CMP AX, 0
	JNE BIR_MI
	MOV WORD PTR [BP+14],0
	JMP SON
BIR_MI:
	CMP AX,1
	JNE IKI_MI
	MOV WORD PTR [BP+14],1
	JMP SON
IKI_MI:
	CMP AX,2
	JNE DIGER
	MOV WORD PTR [BP+14],1
	JMP SON
DIGER:
    DEC AX
	PUSH AX
	CALL FAR PTR DNUM   ;d(n-1)
	CALL FAR PTR DNUM    ;d(d(n-1))
	POP CX
	DEC AX
    PUSH AX
	CALL FAR PTR DNUM ;d(n-2)
    POP BX
    INC AX
    MOV DX,AX
	SUB DX,BX
    PUSH DX
	CALL FAR PTR DNUM ; d(n-1-d(n-2))
    POP BX
	ADD CX,BX
    MOV [BP+14],CX  ;  d(d(n-1))+d(n-1-d(n-2))
SON:
    POP DX
    POP CX
    POP BX
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
		MOV AX,[BP+14] ; yazdıracağımız sayının tutulduğu yer
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

CODESEG ENDS
	END ANA