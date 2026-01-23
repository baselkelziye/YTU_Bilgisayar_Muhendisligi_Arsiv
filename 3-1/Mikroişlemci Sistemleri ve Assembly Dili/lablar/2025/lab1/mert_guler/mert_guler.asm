;  MEAN SQUARED ERROR (MSE) HESAPLAMA

STK SEGMENT PARA STACK 'STACK'
        DW 30 DUP(?)
STK ENDS

DSG SEGMENT PARA 'DATA'
        SUM     DD    0 ; 412, 019C
        MSE     DW    0 ; 82, 0052
        VAR     DB  0FBH ; 251      
        ; VAR     DB  FBH  ; HATALI, basinda sifir olmali, herhangi bir yerde kullanilmiyor
        D1      DW   10,  1, -3,  7,  0
        D2      DW    5,  5,  8, -6,  9
        N       DW    5
DSG ENDS

CSG SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:DSG, SS:STK 
        ; ASSUME CS:CSG, DS:CSG, SS:CSG ; HATALI, DS ve SS kendi segmentine atanmali
START PROC FAR              

        PUSH  DS
        XOR   AX, AX
        PUSH  AX
        ; MOV   AX, STK ; HATALI, Data segmentini atmaliyiz STK degil.
        MOV   AX, DSG
        MOV DS, AX                  

        XOR   AX, AX
        ; MOV   [SUM],   AX   ; HATALI, basinda WORD PTR olmali, yoksa 4 bytelik yere 2 byte data yazmaya calismis oluruz            
        ; MOV   [SUM+2], AX ; //
        MOV   WORD PTR [SUM],   AX               
        MOV   WORD PTR [SUM+2], AX

        LEA   SI, D1
        LEA   DI, D2
        ; MOV   CX, N ; HATALI, LEA olmadan MOV'u bu sekilde kullanirsak degeri degil adresi yazmis oluruz
        MOV   CX, WORD PTR [N]         

    CALC_LOOP:
        MOV   AX, [SI]
        MOV   BX, [DI]
        SUB   AX, BX          
        ; JAE   NONNEG ; Bu kisim gereksiz zaten karesini aliyoruz             
        ; NOT   AX  ; //

        ; IMUL  BX ; HATALI, Sonuc BX'de degil AX'de. Bu sebeple AX'in karesi alinmali
        IMUL  AX                        

        ; ADD   [SUM],   AX ; HATALI, ayni sekilde WORD PTR etiketini yazmak zorundayiz.
        ; ADD   [SUM+2], DX ; ADC yapilip carry eklenmesi de gerekli //
        ADD   WORD PTR [SUM],   AX 
        ADC   WORD PTR [SUM+2], DX               

        ; ADD   SI, 1 ; HATALI, dizi indexini 1 byte degil 2 byte arttirmaliyiz.             
        ; ADD   DI, 1 ; // 
        ADD   SI, 2                    
        ADD   DI, 2
        LOOP  CALC_LOOP

        ; MOV   DX, [SUM]  ; HATALI, ayni sekilde WORD PTR etiketini koymaliyiz.      
        ; MOV   AX, [SUM+2] ; //
        MOV   AX, WORD PTR [SUM]                 
        MOV   DX, WORD PTR [SUM+2]

;       DIV   CL ; HATALI, DX:AX seklinde bolme yapmak icin CX kullanmaliyiz. Bit yetmediginden
;       Bu sadece AX'i boler. Ustelik CL ye oncelikle N degerini atamaliyiz.
        MOV  CX, WORD PTR [N]
        DIV   CX   

        MOV   MSE, AX

;     RET ; HATALI, bu programda FAR'dan donmezsek program sonlanip isletim sistemine geri donmez.
    RETF
START ENDP
CSG ENDS
END START

