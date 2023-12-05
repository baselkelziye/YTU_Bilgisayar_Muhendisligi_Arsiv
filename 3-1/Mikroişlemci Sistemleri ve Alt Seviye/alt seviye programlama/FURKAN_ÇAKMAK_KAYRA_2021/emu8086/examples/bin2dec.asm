; input8 bit binary number and print out decimal to screen.
; zeros and ones -> decimal value

ORG 100h

; macro

; this macro prints a char in AL and advances
; the current cursor position:
PUTC    MACRO   char
        PUSH    AX
        MOV     AL, char
        MOV     AH, 0Eh
        INT     10h     
        POP     AX
ENDM

.data
; null terminated input string:
DB "0"
s1 DB "00000000", 0
sum DW 0  ; result.
flag DB 0


.code
CALL print
DB 0dh, 0ah, "8 bit binary: ", 0



; get string:
MOV DX, 9   ; buffer size (1+ for zero terminator).
LEA DI, s1
CALL GET_STRING


; check that we really got 8 zeros and ones
MOV CX, 8
MOV SI, OFFSET s1
check_s:
        CMP [SI], 0 
        JNE ok0         
        MOV flag, 1     ; terminated.
        JMP convert
    ok0:
        CMP [SI], 'b' 
        JNE ok1         
        MOV flag, 1     ; terminated.
        JMP convert        
    ok1:    
        ; wrong digit? Not 1/0?
        CMP [SI], 31h
        JNA ok2
        JMP error_not_valid     
    ok2:
        INC SI
    LOOP check_s







; start the conversion from string to value in SUM variable.
convert:
MOV BL, 1   ; multiplier.
MOV CX, SI
SUB CX, OFFSET s1
DEC SI

JCXZ stop_program

next_digit:
    MOV AL, [SI]  ; get digit.
    SUB AL, 30h
    MUL BL      ; no change to AX.
    ADD SUM, AX
    SHL BL, 1
    DEC SI          ; go to previous digit.
    LOOP next_digit

; done! converted number is in SUM.

; check if signed
TEST sum, 0000_0000_1000_0000b
JNZ  print_signed_unsigned

print_unsigned:
CALL print
DB 0dh, 0ah, "decimal: ", 0
MOV  AX, SUM
CALL PRINT_NUM_UNS
JMP  stop_program

print_signed_unsigned:
CALL print
DB 0dh, 0ah, "unsigned decimal: ", 0
; print out unsigned:
MOV  AX, SUM
CALL PRINT_NUM_UNS
CALL print
DB 0dh, 0ah, "signed decimal: ", 0
; print out singed:
MOV  AX, SUM
CBW  ; convert byte into word.
CALL PRINT_NUM
JMP  stop_program


error_not_valid:
CALL print
DB 0dh, 0ah, "error: only zeros and ones are allowed!", 0

stop_program:

; wait for any key....
CALL print
DB 0dh, 0ah, "press any key...", 0
MOV AH, 0
INT 16h
RET


; procedures



; copied from c:\emu8086\emu8086.inc
GET_STRING      PROC    NEAR
PUSH    AX
PUSH    CX
PUSH    DI
PUSH    DX

MOV     CX, 0                   ; char counter.

CMP     DX, 1                   ; buffer too small?
JBE     empty_buffer            ;

DEC     DX                      ; reserve space for last zero.


;============================
; loop to get and processes key presses:

wait_for_key:

MOV     AH, 0                   ; get pressed key.
INT     16h

CMP     AL, 13                  ; 'RETURN' pressed?
JZ      exit


CMP     AL, 8                   ; 'BACKSPACE' pressed?
JNE     add_to_buffer
JCXZ    wait_for_key            ; nothing to remove!
DEC     CX
DEC     DI
PUTC    8                       ; backspace.
PUTC    ' '                     ; clear position.
PUTC    8                       ; backspace again.
JMP     wait_for_key

add_to_buffer:

        CMP     CX, DX          ; buffer is full?
        JAE     wait_for_key    ; if so wait for 'BACKSPACE' or 'RETURN'...

        MOV     [DI], AL
        INC     DI
        INC     CX
        
        ; print the key:
        MOV     AH, 0Eh
        INT     10h

JMP     wait_for_key
;============================

exit:

; terminate by null:
MOV     [DI], 0

empty_buffer:

POP     DX
POP     DI
POP     CX
POP     AX
RET
GET_STRING      ENDP




; copied from c:\emu8086\emu8086.inc
PRINT_NUM       PROC    NEAR
        PUSH    DX
        PUSH    AX

        CMP     AX, 0
        JNZ     not_zero

        PUTC    '0'
        JMP     printed_pn

not_zero:
        ; the check SIGN of AX,
        ; make absolute if it's negative:
        CMP     AX, 0
        JNS     positive
        NEG     AX

        PUTC    '-'

positive:
        CALL    PRINT_NUM_UNS
printed_pn:
        POP     AX
        POP     DX
        RET
ENDP



; copied from c:\emu8086\emu8086.inc
PRINT_NUM_UNS   PROC    NEAR
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX

        ; flag to prevent printing zeros before number:
        MOV     CX, 1

        ; (result of "/ 10000" is always less or equal to 9).
        MOV     BX, 10000       ; 2710h - divider.

        ; AX is zero?
        CMP     AX, 0
        JZ      print_zero

begin_print:

        ; check divider (if zero go to end_print):
        CMP     BX,0
        JZ      end_print

        ; avoid printing zeros before number:
        CMP     CX, 0
        JE      calc
        ; if AX<BX then result of DIV will be zero:
        CMP     AX, BX
        JB      skip
calc:
        MOV     CX, 0   ; set flag.

        MOV     DX, 0
        DIV     BX      ; AX = DX:AX / BX   (DX=remainder).

        ; print last digit
        ; AH is always ZERO, so it's ignored
        ADD     AL, 30h    ; convert to ASCII code.
        PUTC    AL


        MOV     AX, DX  ; get remainder from last div.

skip:
        ; calculate BX=BX/10
        PUSH    AX
        MOV     DX, 0
        MOV     AX, BX
        DIV     CS:ten  ; AX = DX:AX / 10   (DX=remainder).
        MOV     BX, AX
        POP     AX

        JMP     begin_print
        
print_zero:
        PUTC    '0'
        
end_print:

        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
ten             DW      10      ; used as divider.      
ENDP


; print text that follows the caller
print PROC
MOV     CS:temp1, SI  ; store SI register.
POP     SI            ; get return address (IP).
PUSH    AX            ; store AX register.
next_char:      
        MOV     AL, CS:[SI]
        INC     SI            ; next byte.
        CMP     AL, 0
        JZ      printed_ok
        MOV     AH, 0Eh       ; teletype function.
        INT     10h
        JMP     next_char     ; loop.
printed_ok:
POP     AX            ; re-store AX register.
; SI should point to next command after
; the CALL instruction and string definition:
PUSH    SI            ; save new return address into the Stack.
MOV     SI, CS:temp1  ; re-store SI register.
RET
temp1  DW  ?    ; variable to store original value of SI register.
ENDP