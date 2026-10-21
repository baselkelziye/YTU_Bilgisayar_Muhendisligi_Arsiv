CODE    SEGMENT PUBLIC  'CODE'
        ASSUME CS:CODE

START:
	 
        MOV AL, 00110111b ;counter 0 için, lsb msb, mode 3, bcd
        OUT 7EH, AL

        MOV AL, 01110111b ;counter 1için, lsb msb, mode 3, bcd
        OUT 7EH, AL

	 XOR AL, AL
	 OUT 78H, AL
	 OUT 7AH, AL
	
	;2 Mhz --> 2 x 10^6 hz 
	;istenen frekans 1 sn'de 4 dalga --> 4 Hz
	; 2 x 10^6 / 4 Hz = 500000 (65535'ten büyük bir değer bu nedenle iki counter kullanılacak)
	;counter0 --> 5000 , counter1 --> 100

        ;5000 bcd olarak okunacak
	MOV AL, 00H
	OUT 78H, AL
        MOV AL, 50h
        OUT 78H, AL

        ;0100 bcd olarak okunacak
	 MOV AL, 00H
	 OUT 7AH, AL
        MOV AL, 01h
        OUT 7AH, AL

ENDLESS:
        JMP ENDLESS

CODE    ENDS
        END START
