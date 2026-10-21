STSG SEGMENT PARA STACK 'STSGM'
    DW 20 DUP (?)
STSG ENDS

DTSG SEGMENT PARA 'DTSGM'
    vize DW 77, 85, 64, 96 
    final DW 56, 63, 86, 74
    obp DW 0, 0, 0, 0
DTSG ENDS

CDSG SEGMENT PARA 'CDSGM'
    ASSUME CS:CDSG, DS:DTSG, SS:STSG

    ANA PROC FAR

        PUSH DS
        XOR AX, AX
        PUSH AX

        MOV AX, DTSG
        MOV DS, AX

        ;CODE

        ; tek tek tüm ogrencilerin obpsini hesaplama
        MOV CX, 4               ; dongu sayisi 4 olacagi icin 4 atadik
        MOV SI, 0               ; indexi 0 olarak set ediyoruz.

    OBP_HESAPLA:
        MOV AX, [vize + SI]     ; midterm notunu ax'e atama
        MOV BX, 4               ; agirligi 40 oldugu icin 4 ile carpicaz, bx'e 4 atadık
        MUL BX                  ; AX = AX * 4
        MOV BX, AX              ; hesaplanan degeri bx'e atama

        MOV AX, [final + SI]    ; final notunu ax'e atama
        MOV DX, 6               ; agirligi 60 oldugu icin 6 ile carpicaz, bx'e 6 atadık
        MUL DX                  ; AX = AX * 6

        ADD AX, BX              ; hesaplanan degerleri toplama

        ADD AX, 5               ; 8086 assembly'de round yapmak icin 5 ekliyoruz, daha sonrasinda toplami 10'a boldugumuzde round islemi gerceklestirmis olacak
        MOV BX, 10
        DIV BX                  ; 10'a boluyoruz.

        MOV [obp + SI], AX      ; obp dizisine buldugumuz sonucu atiyoruz.

        ADD SI, 2               ; word olarak tanimladigimiz icin bir sonraki notlara gecmek icin 2 ekliyoruz index'e
        LOOP OBP_HESAPLA           ; cx 0 olana kadar tekrarla

        
        MOV CX, 3               ; sort islemi icin cx'e 3 atiyoruz

    OBP_SIRALA:
        MOV SI, 0               ; index'i sifirliyoruz
        MOV BX, CX              ; ic dongu icin sayac

        IC_DONGU:
            MOV AX, [obp + SI]         ; obp degeri
            MOV DX, [obp + SI + 2]     ; bir sonraki obp degeri

            CMP AX, DX              ; karsilastir
            JAE SWAP_YAPMA           ; eger olmasi gerektigi gibi ax daha buyukse degistirmemek icin atla

            ; Swap islemi
            MOV [obp + SI], DX
            MOV [obp + SI + 2], AX    

        SWAP_YAPMA:
            ADD SI, 2               ; word olarak tanimladigimiz icin bir sonraki obp'ye gecmek icin 2 ekliyoruz index'e
            DEC BX
            JNZ IC_DONGU          ; ic dongu bitene kadar tekrarla

            DEC CX
            JNZ OBP_SIRALA            ; tum obp siralanana kadar tekrarla

            RETF
    ANA ENDP

CDSG ENDS

    END ANA