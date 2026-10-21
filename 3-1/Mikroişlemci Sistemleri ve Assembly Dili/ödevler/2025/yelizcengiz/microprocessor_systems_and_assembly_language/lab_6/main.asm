STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DSG     SEGMENT PARA 'DATA'
        BUFFER DB 3 DUP(0)
DSG     ENDS


CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DSG, SS:STAK
START:
        MOV AX, DSG
        MOV DS, AX

        MOV DX, 015Ah
        MOV AL, 01001101B;1 stop bit,parity yok,8 data bit,faktör 1
        OUT DX, AL;mod set
        
        MOV AL, 40H;internal reset
        OUT DX, AL
        
        MOV AL, 01001101B;tekrar mode set
        OUT DX, AL
        
        MOV AL, 00010101B;transmit ve receive
        OUT DX, AL;kontrol set
        
        MOV BP,SP 

ENDLESS:
        MOV SP,BP ;stack reset

        MOV CX, 3
	MOV DI, 0
	
CLR_BUF:
        MOV BUFFER[DI], 0
        INC DI
        LOOP CLR_BUF


TEKRAR:
        MOV DX, 015AH
        IN AL, DX
        AND AL, 02H;receive ready bit conrtol
        JZ TEKRAR
        
        MOV DX, 0158H
        IN AL, DX;input alma
        SHR AL, 1
        
        CMP AL, '0' ;0 ise cikis
        JE INPUT_FIN
        
        CMP AL, 'A'
        JB TEKRAR;A dan kucukse atla
        CMP AL, 'Z'
        JA TEKRAR;Z den buyukse atla
        
        
        ;kayitlari kaydirma
        MOV BL, BUFFER[1]
        MOV BUFFER[0],BL
        
        MOV BL, BUFFER[2]
        MOV BUFFER[1],BL 
        
        MOV BUFFER[2],AL
        
        JMP TEKRAR
	
	

INPUT_FIN:
        MOV CX, 3
        XOR DI, DI;index counter

YAZDIR_DONGU:
        MOV AL, BUFFER[DI]
        
        CMP AL, 0;BUFFER[DI]==0
        JE NEXT
        
        ADD AL,3 ;ASCII+3
        
        PUSH AX 
TX_READY:
        MOV DX, 015AH
        IN AL, DX
        TEST AL, 01H ;transmit ready bit control
        JZ TX_READY
        
        MOV DX, 0158H
        POP AX  ;karakteri geri al
        OUT DX, AL ;yazdirma

NEXT:
        INC DI	;index++
        LOOP YAZDIR_DONGU
        
        JMP ENDLESS

CODE    ENDS
        END START