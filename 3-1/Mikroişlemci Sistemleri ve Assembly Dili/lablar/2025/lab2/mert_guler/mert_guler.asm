STK SEGMENT PARA STACK 'STACK'
        DW 30 DUP(?)
STK ENDS

DSG SEGMENT PARA 'DATA'
        TOPLAM  DD 0 ; 50 - 32H
        ORT     DW    0 ; 7
        ORT_USTU DW    0  ; 5
        CELCIUS DW    0,  11,  -273, 72,  100, 27, -33
        FAHRENHEIT dw 7 dup(?) 
        ; Fahrenheit = {32, 51, −459, 161, 212, 80, −27}
        ; Fahrenheit = {20 00 33 00 35 FE A1 00 D4 00 50 00 E5 FF}
        N       DW    7
DSG ENDS

CSG SEGMENT PARA 'CODE'
	ASSUME CS:CSG, DS:DSG, SS:STK 
	
	START PROC FAR
		PUSH DS
		XOR AX, AX
		PUSH AX

		MOV AX, DSG
		MOV DS, AX

        ; Dizileri yukle
        LEA SI, CELCIUS
        LEA DI, FAHRENHEIT

        MOV CX,  WORD PTR [N]
        CALC_LOOP:
        MOV AX, [SI]

        ; 1.8 ile carp
        MOV BX, 9
        IMUL BX
        MOV BX, 5
        IDIV BX
        ; 32 ekle
        ADD AX, 32

        ; Fahrenheit dizisine yaz
        MOV [DI], AX

        ; Toplam degiskenine ekle
        CWD
        ADD  WORD PTR [TOPLAM], AX
        ADC  WORD PTR [TOPLAM+2], DX

        ; Donguyu devam ettir
        ADD SI, 2
        ADD DI, 2
        LOOP CALC_LOOP

        ; Ortalamayi hesapla
        MOV  AX, WORD PTR [TOPLAM]
        MOV  DX, WORD PTR [TOPLAM+2]
        IDIV N
        MOV ORT, AX

        ; Ortalamanin ustundekileri hesapla
        LEA DI, FAHRENHEIT
        MOV CX, WORD PTR [N]

        ORT_USTU_LOOP:
        MOV AX, [DI]

        CMP AX, ORT
        JLE DEVAM
        INC ORT_USTU
        
        DEVAM:
        ADD DI, 2
        LOOP ORT_USTU_LOOP
		
		RETF
	START ENDP
CSG ENDS
	END START