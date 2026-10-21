STSG SEGMENT PARA STACK 'STSGM'
         DW 20 DUP(?)
STSG ENDS

DTSG SEGMENT PARA 'DTSGM'
    vize  DB 77,85,64,96 ;diziler byte tipinde saklaniyor
    final DB 56,63,86,74
    obp   DB 4 DUP(?)
    n     DW 4
DTSG ENDS

CDSG SEGMENT PARA 'CDSGM'
    ASSUME CS:CDSG, SS:STSG, DS:DTSG

    ANA PROC FAR

        PUSH   DS ;geri donus adreslerinin ayarlanmasi
        XOR    AX, AX
        PUSH   AX

        MOV    AX, DTSG ;DS degerinin ayarlanmasi
        MOV    DS, AX

        ;obp degerlerini hesaplamak icin girilecek dongu
        XOR    SI, SI
        MOV    CX, n

    L1:   

        MOV    AL, [vize + SI] ;vize degerine dolayli adresleme ile erişip 4 ile carpilip BX'te saklanmasi
        MOV    DL, 4
        MUL    DL
        MOV    BX, AX

        MOV    AL, [final + SI] ;final degerinin 6 ile carpilmasi
        MOV    DL, 6
        MUL    DL
        ADD    AX, BX ;vize * 4 + final * 6 islemi

        MOV    BL, 10
        DIV    BL ;toplamin 10'a bolunmesi, bolum AL'de kalan AH'de sakalanacak

        CMP    AH, 5 ;eger AH'de sakalanan kalan degeri 5'ten buyuk esitse, AL degeri 1 artirilacak
        JB     true1 
        INC    AL
    true1:
        MOV    [obp + SI], AL ; bulunan obp degerinin obp dizisine kaydedilmesi

        INC    SI 

        LOOP   L1

    ;obp dizisini buyukten kucuge siralamak icin girelecek icice dongu (bubble sort yapiliyor)
        MOV    CX, n
        DEC    CX ;dis dongu n - 1 defa donecek

    L2:   

        PUSH   CX ;dis dongu icin CX degerinin stackte saklanmasi
        XOR    SI, SI ;ic donguye girmeden adreslemede kullanacagimiz SI'nin sifirlanmasi 

    L3:   ;ic dongu dis dongunun bu iterasyondaki CX degeri kadar donecek

        MOV    AL, [obp + SI] ;pair'in ilkini AL'ye atiyoruz
        CMP    AL, [obp + SI + 1] ;pair'in ikincisini AL'de bulunan ilkiyle karsilastiriyoruz, eger kucukse swap yapacagiz
        JAE    true2
        XCHG   AL, [obp + SI + 1] ;iki adimda swap isleminin yapılmasi
        MOV    [obp + SI], AL
    true2:
        INC    SI ;ic dongude SI'nin artirilmasi

        LOOP   L3

        POP    CX ;dis dongu icin CX'in stackten alinmasi
        
        LOOP   L2

    RETF
    
ANA ENDP


CDSG ENDS

END ANA