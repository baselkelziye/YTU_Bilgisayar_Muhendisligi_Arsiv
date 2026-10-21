CODESG SEGMENT PARA 'CODE'
    ORG 100H
    ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
    
BILGI:  JMP BASLA   ; Başlangıç noktasına atla

; Değişken tanımlamaları
primeOddSum       DW 15 DUP(0)       ; Asal ve tek toplam koşullarını sağlayan hipotenüsler
nonPrimeOrEvenSum DW 15 DUP(0)       ; Diğer durumlar için hipotenüsler
primeCount        DW 0               ; primeOddSum dizisinin sayacı
nonPrimeCount     DW 0               ; nonPrimeOrEvenSum dizisinin sayacı
gecici            DW 0                ; Geçici değişkenler için

BASLA PROC NEAR
    MOV SI, 0                
    MOV DI, 0                
    MOV AX, 0                
    XOR CX, CX               

next_a:	
    INC CX                    ; a++
    MOV DX, CX                ; b = a

dongu:  
    INC DX                    ; b++

    MOV AX, CX                ; a'nın karesini hesapla
    MUL AL                    ; AX = a^2

    PUSH AX                   ; a^2'yi stack'e ekle

    MOV AX, DX                ; b'nin karesini hesapla
    MUL AL                    ; AX = b^2
    MOV BX, AX                ; BX = b^2
    POP AX                    ; AX = a^2

    ADD AX, BX                ; AX = c^2 yani a^2 + b^2

sqrt:
    PUSH CX                   ; CX'yi stack'e ekle
    PUSH DX                   ; DX'yi stack'e ekle 

    MOV gecici, AX           ; gecici değişkenine c^2'yi at
    MOV CX, 1                ; CX'yi 1 olarak ayarla

sqrt_loop:
    MOV AX, CX               ; AX'yi CX'ye ata
    MUL CX                   ; AX = CX * CX (CX^2)
    CMP AX, gecici           ; AX ile gecici değişkenini karşılaştır
    JE tamkare               ; Eşitse tam kare olduğunu belirt
    JA buyuk                 ; Eğer büyükse, döngüyü bitir. tam kare degildir demektir
    
    INC CX                   ; CX'yi 1 artır
    JMP sqrt_loop            ; Döngüye geri dön

tamkare:
    MOV BX, 1                ; Tam kare ise BX'yi 1 yap
    MOV AX, CX                ; AX'ye CX'yi ata
    JMP bitir                ; Bitir etiketine geç

buyuk:
    MOV BX, 0                ; Tam kare değilse BX'yi 0 yap
    
bitir: 
    POP DX                   ; DX'yi stack'ten al
    POP CX                   ; CX'yi stack'ten al

    CMP BX, 0                ; BX'yi kontrol et
    JE sonrakiadim          ; 0 ise sonraki adıma geç

    CMP AX, 50               ; AX'yi 50 ile karşılaştır
    JA sonrakiadim          ; Eğer 50'den büyükse sonraki adıma geç

    CALL ifPrime             ; ifPrime fonksiyonunu çağır
    CMP BX, 0                ; BX'yi kontrol et
    JZ nonPrimeOrEvenSum_ekle ; Eğer 0 ise nonPrimeOrEvenSum dizisine ekle

    MOV BX, CX               ; BX'ye CX'yi ata
    ADD BX, DX               ; BX'ye DX'yi ekle
    RCR BX, 1                ; Eğer son bit 1 ise sayı tektir. RCR işleminden artan gelecektir.
    JNC nonPrimeOrEvenSum_ekle ; Rotate ten carry gelirse sayı tektir.

    MOV primeOddSum[SI], AX  ; Asal ve tek sayı dizisine ekle
    INC SI                   ; SI'yi artır
    JMP sonrakiadim          ; Sonraki adıma geç

nonPrimeOrEvenSum_ekle:
    MOV nonPrimeOrEvenSum[DI], AX ; Diğer durumlar dizisine ekle
    INC DI                   ; DI'yi artır

sonrakiadim:      ; b değeri 50'ye gidene kadar 1 artırarak devam et.
    CMP DX, 50              ; DX'yi kontrol et
    JB dongu                ; 50'den küçükse döngüye devam et

    CMP CX, 50              ; CX'yi kontrol et
    JB next_a              ; 50'den küçükse a döngüsüne geri dön
    
    MOV DX, SI              ; DX'ye SI'yi ata (Asal ve tek sayıların toplamı)

    RET                     ; Prosedürü sonlandır
BASLA ENDP

ifPrime     PROC NEAR
    PUSH CX                 ; CX'yi stack'e ekle
    PUSH DX                 ; DX'yi stack'e ekle
    PUSH AX                 ; AX'yi stack'e ekle
    MOV gecici, AX         ; Orijinal sayıyı gecici değişkenine ata
                
    CMP AX, 2              ; AX'yi 2 ile karşılaştır
    JL prime_degil         ; 2'den küçükse asal değildir
    JE prime               ; 2 ise asaldır

    ; Sayı 2'den büyükse asal kontrolü için döngü
    MOV BX, 1              ; BX'yi 1 olarak başlat (asal varsayıyoruz)
                
    MOV CX, 2              ; Bölen sayısını 2 olarak başlat

prime_dongu:     
    MOV AX, gecici          ; Orijinal sayıyı AX'ye yükle
    MOV DX, 0               ; DX'yi 0 olarak sıfırla
    DIV CX                   ; AX'yi CX'ye böl (Orijinal sayıyı böldük)
    CMP DX, 0              ; Kalan 0 ise asal değildir
    JE prime_degil          ; Eğer kalan 0 ise asal değil

    INC CX                  ; Sıradaki böleni artır

    MOV AX, gecici          ; Sayının köküne kadar gitmek için orijinal sayıyı yükle
    MOV DX, 0
    DIV CX                   ; Orijinal sayıyı böldük
    CMP CX, AX             ; CX**2 ile AX'i karşılaştır
    JB prime_dongu         ; CX**2 orijinal sayının altındaysa devam et

prime:          
    MOV BX, 1              ; BX=1 --> ASAL SAYI
    POP AX                 ; AX'yi stack'ten al
    POP DX                 ; DX'yi stack'ten al
    POP CX                 ; CX'yi stack'ten al

    RET                     ; Prosedürü sonlandır

prime_degil:      
    MOV BX, 0              ; BX=0 --> ASAL SAYI DEĞİL
    POP AX                 ; AX'yi stack'ten al
    POP DX                 ; DX'yi stack'ten al
    POP CX                 ; CX'yi stack'ten al

    RET                     ; Prosedürü sonlandır

ifPrime ENDP

end_program2:
    RET                     ; Programı sonlandır
CODESG ENDS
END BILGI
