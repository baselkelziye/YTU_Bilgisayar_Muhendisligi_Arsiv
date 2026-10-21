STACK SEGMENT PARA STACK 'STACK'
    DW 64 DUP(?)
STACK ENDS

DATA SEGMENT PARA 'DATA'
DATA ENDS

CODE SEGMENT PARA 'CODE'
    ASSUME CS:CODE, DS:DATA, SS:STACK

START:
    MOV AX, DATA
    MOV DS, AX

MAIN_LOOP:
    MOV DX, 0400H  ;ADC portu
    OUT DX, AL	;write sinyali
    
    MOV DX, 0800H  ;ADC INTR adresi
CONVERSION:
    IN AL, DX	;tamponu okuma(ADC INTR)
    TEST AL, 10000000b ;D7 bit kontrolu
    
    ;convert oldugunda-> D7=0  
    JNZ CONVERSION        ;0 değilse bekle

    MOV DX, 400H ;ADC portu
    IN AL, DX	;digital veri-> AL
    
    MOV DX, 200H  ;DAC portu
    OUT DX, AL	;AL -> DAC
    
    JMP MAIN_LOOP

CODE ENDS
    END START