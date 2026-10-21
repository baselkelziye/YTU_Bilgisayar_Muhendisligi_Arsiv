;Mikroslemciler Dersi 5. Labi
;Hazırlayan Orcun Celik
;Ogrenci Numarasi: 15011053
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS
DATA    SEGMENT PARA 'DATA'
DIGITS  DB 00H
DATA    ENDS
CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
START:
        MOV AX, DATA
	MOV DS, AX
	;Control Word Islemleri Counter 0 Mode 2
	MOV AL, 00110101B 
	OUT 87H, AL
	;Control Word Islemleri Counter 1 Mode 2
	MOV AL, 01110101B
	OUT 87H, AL
	;lsb degerlerin gonderimi
	XOR AL, AL
	OUT 81H, AL
	OUT 83H, AL
	;msb degerlerin gonderimi
	MOV AL, 10H
	OUT 81H, AL
	MOV AL, 10H
	OUT 83H, AL
ENDLESS:
        JMP ENDLESS
CODE    ENDS
        END START
