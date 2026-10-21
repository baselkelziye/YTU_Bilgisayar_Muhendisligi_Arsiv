PUBLIC DNUM
mycode2	SEGMENT PARA 'k'
		ASSUME CS:mycode2
DNUM	PROC FAR
    PUSH BP ; kullanilacak registerlar stacke atildi.
	PUSH BX
	PUSH DI
	PUSH SI
	
	
    MOV BP, SP			;sp bpye atandi
	MOV DI, [BP+12]		;yigindaki n degeri alindi ve ax'e ve DI'ya  atandi
	MOV AX, DI	

    CMP AX,0			;AX'I 0,1,2 baslangic degerleri icin kontrol ederm
	JE SIFIR
	CMP AX,1
	JE BIR
	CMP AX,2
	JE BIR	
    ;eger 0,1 ya da 2 degilse bu islemi yap
    DEC  AX ; n-1
	PUSH AX
	CALL DNUM ;D(N-1) hesaplanir
	CALL DNUM ; D(D(N-1)) hesaplanir
	POP  SI ; SI'ya D(D(n-1)) degeri atilir
	MOV  CX,DI ;CX'e n atanir
	DEC  CX
	DEC  CX;cx n-2 oldu
	PUSH CX
	CALL DNUM ;D(N-2)hesaplanir
	POP  CX ; cxe d(n-2)yi konulur
	MOV  DX,DI ;dx n atanir
	DEC  DX
	SUB  DX,CX ;yeni dx (n-1 -D(N-2)) olur
	PUSH DX
	CALL DNUM; D(n-1-D(n-2)) degeri hesaplanir
	POP  DX ; son deger dxa atilir.
	ADD SI,DX;D(D(n-1))+D(n-1 -D(N-2)) sonuc boylelikle ortaya cikar
	MOV [BP+12], SI			;elde edilen sonuc yigina atildi
									
	JMP DONUS
	
SIFIR:		MOV  AX, 0
			MOV  [BP+12], AX					
			JMP DONUS
			
BIR:		MOV  AX, 1		
			MOV  [BP+12], AX
			
DONUS:		POP SI ; registerlar stackten poplandi yordam sona erdi
			POP DI
			POP BX
			POP BP
			RETF 
DNUM ENDP
mycode2 ENDS
		END