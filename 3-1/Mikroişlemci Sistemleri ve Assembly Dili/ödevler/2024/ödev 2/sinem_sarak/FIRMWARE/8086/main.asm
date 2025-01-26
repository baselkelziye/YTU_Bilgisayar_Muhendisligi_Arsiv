;====================================================================
;
; Created:   Prs Aralik 11 2024
; Creator:	Sinem Sarak
; Processor: 8086
; Compiler:  MASM32
;
;====================================================================

YIGIN SEGMENT PARA STACK 'STACK'
    DW 20 DUP(?)               
YIGIN ENDS

VERI SEGMENT PARA 'DATA'
    ALINANLAR DB 5 DUP(0)       ; Gelen karakterler dizisi
    GIRIS_SAYAC DW 0            ; Alinan karakter sayaci
    CIKIS_SAYAC DW 0            ; Gönderilen karakter sayaci
    HEPSI_GONDERILDI DB 1       ; Tüm karakterler gönderildi mi bayragi
VERI ENDS

KOD SEGMENT PARA 'CODE'
ASSUME CS:KOD, DS:VERI, SS:YIGIN

BASLA PROC FAR

    MOV AX, VERI                ; Veri segmentini yükle
    MOV DS, AX

    ; Kesme vektör tablosu ayarlari
    XOR AX, AX
    MOV ES, AX

    ; veri alma kesmesi
    MOV AL, 50H
    MOV AH, 4
    MUL AH
    MOV BX, AX
    LEA AX, GIRIS_KESME
    MOV WORD PTR ES:[BX], AX
    MOV AX, CS
    MOV WORD PTR ES:[BX+2], AX

    ; veri gönderme kesmesi 
    MOV AL, 51H
    MOV AH, 4
    MUL AH
    MOV BX, AX
    LEA AX, CIKIS_KESME
    MOV WORD PTR ES:[BX], AX
    MOV AX, CS
    MOV WORD PTR ES:[BX+2], AX

    ; 8251A ayarlari
    MOV AL, 01001101B           ;01 00 11 01 //1 stop bit, no parity, 8 bit data, factor 1
    OUT 5AH, AL
    MOV AL, 40H                 ; Iç reset
    OUT 5AH, AL
    MOV AL, 01001101B           ; Mod ayarlarini yeniden yükle
    OUT 5AH, AL
    MOV AL, 00010101B           ; clear error  bits, recieve transmit enabled
    OUT 5AH, AL

    ; 8259 ayarlari
    MOV AL, 13H
    OUT 34H, AL
    MOV AL, 50H
    OUT 36H, AL
    MOV AL, 03H
    OUT 36H, AL

    STI                         ; SET IF

SONSUZ:
    JMP SONSUZ                
BASLA ENDP

; Seri veri alma kesme alt programi
GIRIS_KESME PROC FAR
    IN AL, 58H                  ; karakteri oku
    SHR AL, 1                  
    INC AL                      ; ASCII degerini artir
    MOV BX, GIRIS_SAYAC
    MOV ALINANLAR[BX], AL       ; Diziye kaydet
    INC BX
    CMP BX, 5
    JNE GIRIS_DEVAM              ; 5 karakter tamamlanmadiysa devam et

    XOR BX, BX
    MOV HEPSI_GONDERILDI, 0
    MOV AL, ALINANLAR[0]
    OUT 58H, AL                 ; Ilk karakteri gönder
    MOV CIKIS_SAYAC, 1          ; Gönderme sayacini 1 yap
    
GIRIS_DEVAM:
    MOV GIRIS_SAYAC, BX
    IRET
GIRIS_KESME ENDP

; Seri veri gönderme kesme alt programi
CIKIS_KESME PROC FAR
    CMP HEPSI_GONDERILDI, 1     ; Tüm karakterler gönderildi mi?
    JE CIKIS_DEVAM
    MOV BX, CIKIS_SAYAC
    MOV AL, ALINANLAR[BX]
    OUT 58H, AL                 ; Siradaki karakteri gönder
    INC BX
    CMP BX, 5
    JNE CIKIS_DEVAM
    MOV HEPSI_GONDERILDI, 1     ; Tüm karakterler gönderildi
    XOR BX, BX
CIKIS_DEVAM:
    MOV CIKIS_SAYAC, BX
    IRET
CIKIS_KESME ENDP

KOD ENDS
END BASLA
