;====================================================================
; SIMPLE VAULT HOMEWORK
; 2019/1, YTU - CE
;====================================================================

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
	
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
DIGITS  DB 2 DUP(?)  ;pre-defined binary equalivent of "L" and "U" for corresponding 7seg
KEYS    DB 4 DUP(?)  ;to store value of keys if necassary
PINLOCK DW 0
MASTERUNLOCK DW 4545 ;pre-defined master unlock value. you may change the value as you wish
VALUE DW 0
STATUS DB 0 ; 0 unlocked, 1 locked
DATA    ENDS


START PROC
	 MOV AX, DATA
	 MOV DS, AX
	 
        ; do 8255 preparation

	 
MAINLOOP:
	;
	;Reset Variables if necassary
	;
	;
	;
	CALL READKEY
	;
	;according corresponding read key, store it or reset
	;
	;
	;
	CMP CX,4    ;if successfull reading of 4 digits, Store it to VALUE, CALL VAULT PROC.
	;
	;
	;
	;
	;
	JMP MAINLOOP
RET
START ENDP

;Functions


ARRAYTOINT PROC NEAR ;function that responsible of calculating actual integer from byte array KEYS, if array contains 3,4,5,5 it should return 3455 to corresponding accumulator
;
;
;
;
;
RET
ARRAYTOINT ENDP

VAULT PROC NEAR ;function that responsible for locking/unlocking vault according to status
;
;
;
;
;
;if vault locked:
;compare value with PINLOCK or MASTERUNLOCK
;if equals, unlock and write "U" to 7seg
;
;

;if vault is unlocked:
;check if star is pressed, otherwise reset.
;if star, lock, save PIN to PINLOCK, write 7seg "L"
;
;
;
RET
VAULT ENDP


READKEY PROC NEAR  ;function responsible for reading key from 4x3, it should store the value to some register.
;Typical keypad reader.
;It stores pressed button to next position of the array. 
;No boundary check

AGAIN:  	;Scan columns
		;
		;
		;
SUTUN:	 
		;do column scanning
		;
		;
		;
		;
		JNE SATIR    ;Button pressed jump for row determination
		LOOP SUTUN   ;Button not pressed, go next column
		JMP AGAIN    ;all columns scanned yet no button pressed, restart column scanning 
		;
		;
		;
SATIR:
		
KEYNOTRELEASED: ;Wait until button release	
		;
		;
		;
		JNE KEYNOTRELEASED
		;
		;
		;
		;From that point, you have column index, and row index
		;We need to calculate actual digit value from these indexes 
		;
		;
		;
		;
		;
	 
RET
READKEY ENDP



CODE    ENDS
        END START