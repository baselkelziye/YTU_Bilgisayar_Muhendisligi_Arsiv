EXTRN DNUM:FAR;DNUM ve PRINTINT alt yordamlari maine eklendi
EXTRN PRINTINT:FAR
STEK SEGMENT PARA STACK 'STK';stack data ve kod segmentleri ayarlandi
DW 500 dup(?)
STEK ENDS 

DSG SEGMENT PARA 'DTS'
n dw 10 ;d(n) n degeri
DSG ENDS

CSG SEGMENT PARA 'CODE'
ASSUME CS:CSG, DS:DSG, SS:STEK

MAIN PROC FAR
;her kodda yazilan kemik kod yazildi
PUSH DS
XOR AX, AX
PUSH AX

MOV AX, DSG
MOV DS, AX

;dnumi hesaplamak icin gereken islemler
    push n ; n degeri stacke atildi
    call DNUM ; DNUM cagirildi
    CALL PRINTINT ;dnumdan cikan sonuc ile PRINTINT cagirildi
RETF
MAIN ENDP
CSG ENDS
END MAIN