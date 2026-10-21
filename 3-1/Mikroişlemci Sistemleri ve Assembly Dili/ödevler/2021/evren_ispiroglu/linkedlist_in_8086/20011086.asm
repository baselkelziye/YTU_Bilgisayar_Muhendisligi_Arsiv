myss SEGMENT PARA STACK 'stack'
    DW 32 DUP (?)
myss ENDS

myds SEGMENT PARA 'data'
    startIndex DW -1
    MIN DW 999
    MAX DW -999 

    MENU1  DB '1 - Dizi Girisi ',13,10
    MENU2  DB '2 - Dizi ve Liste Gosterimi ',13,10
    MENU3  DB '3 - Eleman Ekleme ',13,10
    MENU4  DB '-1 - Cikis Yapmak ',13,10,0

    N dw ?
    mainArray DW 100 dup(?)
    indexList DW 100 dup(-1)

    CR	EQU 13
    LF	EQU 10
    INFOS	DB '20011086 - Evren Ispiroglu ',0
    Done	DB 'Isleminiz Tamamlanmistir ',0
    MSG1	DB 'Girmis Oldugunuz Dizi ',0
    MSG2	DB 'Girmis Oldugunuz Dizinin Linkleri ',0
    MSG3	DB 'Linklerden Olusan Dizi ',0
    MSG4	DB 'Lutfen Dizinin Elemanlarini Byte Tanimli Olacak Sekilde Giriniz ',0
    MSG5	DB 'Lutfen Dizinizin Kac Elemanli Olacagini Giriniz ',0
    MSG6	DB 'Lutfen diziye eklemek istediginiz elemani giriniz ',0
    HATA	DB CR, LF, 'Dikkat !!! Sayi vermediniz yeniden giris yapiniz.!!!  ', 0
    SONUC	DB CR, LF, 'Toplam ', 0
myds ENDS

mycs SEGMENT PARA 'code'
        ASSUME CS:mycs, DS:myds, SS:myss
        MAIN PROC FAR 

        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, myds 
        MOV DS, AX

           

start:
                CALL printInfo          ;; Her menu baslangicinda ogrenci bilgilerimin yazdirilmasi.

                LEA AX, menu1
                CALL PUT_STR            ;; Menumun ekrana bastirilmasi. 
                CALL GETN               ;; Kullanicidan ne yapmak istediginin alinmasi.

                CMP AL, -1              ;; -1 kontrolu. -1 girilirse program kapaniyor.
                JE exit


                CMP AL, 1               ;; 1 kontorlu. 1 girilirse dizi initialize ediliyor.
                JNE not_1

                CALL printInfo          ;; Alt menude ogrenci bilgilerimin bastirilmasi.

                CALL getArray           ;; Ek bir yordam yardimiyla dizinin kullanicidan alinmasi
                LEA AX, Done            
                CALL PUT_STR            ;; Kullaniciya islemin tamamlandiginin bilgirilmesi

not_1:
                
                

                CMP AL, 2               ;; 2 kontrolu. 2 girilirse didi, linkler dizisi ve linklerin takibinden olusan
                JNE not_2               ;; dizinin yazdirilmasi.
                CALL printInfo          ;; Alt menude ogrenci bilgilerimin bastirilmasi.


                      
                MOV AX, LF              
                CALL PUTC

                LEA AX, MSG1
                CALL PUT_STR            ;; Kullanicinin girdigi dizinin basitirilmasi
                CALL printArray

                LEA AX, MSG2
                CALL PUT_STR            ;; Olusturulan link dizisinin basitirilmasi.
                CALL printList

                LEA AX, MSG3
                CALL PUT_STR            ;; Link dizisinin takibiyle olusan dizinin bastirilmasi.
                CALL listToArray
            
                MOV AX, LF 
                CALL PUTC

not_2:
                CMP AL, 3               ;; 3 kontorlu. 3 Girilirse diziye yeni eleman eklenecek

                JNE start

                CALL printInfo          ;; Alt menude ogrenci bilgilerimin yazdirilmasi.

                CALL insertInput        ;; Ek yordam yardimiyla kullanicidan alinan inputun insert edilmesi.

                LEA AX, Done            ;; Islemin bittigine dair kullanicinin bilgilendirilmesi.
                CALL PUT_STR


                JMP start

exit:
        RETF
        MAIN ENDP


      getArray PROC NEAR                ;; Kullanicidan diziyi alacak yordam.

        PUSH AX
        PUSH CX
        PUSH SI

                MOV AX, LF              ;; Kullaniciyi yonlendirmek icin
                CALL PUTC               ;; Gerekli mesajlarin bastirilmasi
                LEA AX, MSG4
                CALL PUT_STR
                MOV AX, LF 
                CALL PUTC
                MOV AX, LF 
                CALL PUTC
                LEA AX, MSG5
                CALL PUT_STR
                MOV AX, LF 
                CALL PUTC
                MOV AX, LF 
                CALL PUTC

                CALL GETN               ;; Kullanicidan dizideki eleman
                MOV n, AX               ;; Sayisinin alinmasi

                MOV CX, AX              
                XOR SI, SI

    getLoop:
                LEA AX, MSG6            ;; Dizinin elemanlarinin tek tek alinmasi
                CALL PUT_STR
                XOR AX, AX
                CALL GETN
                MOV mainArray[SI], AX
                CALL insertNode         ;; Ek yordam yardimi ile her eleman alindiginda
                                        ;; linkli listeye eleman eklenmesi

                ADD SI, 2
                LOOP getLoop            

        POP SI
        POP CX
        POP AX
        RET

       getArray ENDP

        insertNode proc NEAR            ;; Linkli liste icin insert yapan yordam
         PUSH SI                        
         PUSH DI                
         PUSH BX
         PUSH AX

                CMP AX, min             ;; Girilen elemanin linkli listede
                JGE NOTLESS             ;; En bastaki elemandan kucuk mu kontrolu
                        MOV min, AX             
                        MOV BX, startIndex      ;; Kucuk olması durmunda linkli listede
                        mov indexList[SI], BX   ;; Head node'unun degisimi
                        MOV startIndex, SI
                        JMP link_end
NOTLESS:
                MOV DI, startIndex


                cmp AX, MAX             ;; Girilen elemanin linkli listede
                JLE NOTGREATER          ;; En sondaki elemandan buyuk mu kontorlu
                        MOV MAX, AX     
                        MOV AX, -1
                                                ;; Buyuk olması durumunda listenin sonuna kadar ilerleyip
wLoop:                                          ;; Son elemaninin degistirilmesi.
                        CMP AX, indexList[DI]
                        JE true1
                        MOV DI, indexList[DI]
                        JMP wLoop
true1:
                MOV indexList[DI], SI
                MOV indexList[SI], -1
                JMP link_end

NOTGREATER:
        CMP indexList[DI], -1           ;; Girilen elemanin en buyuk ya da en kucuk olmamasi durumunda 
        JE link_end                     ;; linkedList'te indexin bir yeri gosterdiginden emin olduktan sonra
                MOV BX, indexList[DI]
                CMP AX, mainArray[BX]           ;; Girilen elemanin kendisinden kucuk en buyuk
                JLE true2                       ;; Elemana kadar ulasilmasi ve
                MOV DI, indexList[DI]           ;; sonraki node'ların Duzenlenmesi
                JMP NOTGREATER
 true2:       
                MOV AX, indexList[DI]
                MOV indexList[SI], AX 
                MOV indexList[DI], SI

        
link_end: 
                CMP SI, 0
                JNE ENDD
                MOV AX, mainArray[SI]
                MOV MAX, AX
                MOV MIN, AX
endd:
        POP AX               
        POP BX
        POP DI
        POP SI
        RET
        insertNode ENDP




        printArray PROC NEAR    ;; Kullanici dizisinin bastirilmasi icin kullanilan yordam.
        PUSH SI
        PUSH CX
        PUSH AX

            XOR SI, SI
            MOV CX, n
            XOR AX, AX

    printLoop:
            
            MOV AX, mainArray[SI]
            CALL PUTN
            MOV AX, ' '         ;; Elemanlar arasinda BOSLUK karakterinin koyulmasi
            CALL PUTC
            ADD SI, 2
            LOOP printLoop  

        MOV AX, LF
        CALL PUTC
        POP AX
        POP CX
        POP SI
        RET
       printArray ENDP

       printList PROC NEAR      ;; Linkli listenin bastirilmasi icin kullanilan yordam.
        PUSH BX
        PUSH SI
        PUSH CX
        PUSH AX

            XOR SI, SI
            MOV CX, n
            XOR AX, AX

    printLoop2:

            MOV AX, indexList[SI]
            CMP AX, -1
            JE minusOne
            SHR AX,1            ;; SHR yapilmasinin sebebi kullanicidan alinan dizinin WORD tanimli olması.
                                ;; linkli listede tutulan indexlerin kullanicida kafa karistirmamasi acisindan 
 minusOne:                      ;; SADECE print isleminde bir manipulasyon yapilip
                                ;; Kullanicida ust seviye dillerdeki gibi bir index bilgisinin verilmesi.
            CALL PUTN
            MOV AX, ' '
            CALL PUTC
            ADD SI, 2
            LOOP printLoop2 

        MOV AX, LF
        CALL PUTC
        POP AX
        POP CX
        POP SI
        POP BX
        RET
       printList ENDP

       listToArray PROC NEAR    ;; Linkli listede tutulan index degerlerinden
        PUSH SI                 ;; Yola cikilarak kullanicidan alinan dizideki degerlerin 
        PUSH CX                 ;; Sirali bir bicimde yazdirilmasini saglayan yordam.
        PUSH AX
        PUSH BX

            XOR SI, SI
            MOV CX, n
            XOR AX, AX
            MOV BX, startIndex

    printLoop3:
            MOV AX, mainArray[BX]
            CALL PUTN
            MOV AX, ' '
            CALL PUTC
            MOV BX, indexList[BX]
            ADD SI, 2
            LOOP printLoop3  

        MOV AX, LF
        CALL PUTC

        POP BX
        POP AX
        POP CX
        POP SI
        RET
       listToArray ENDP

        insertInput PROC NEAR   ;; Kullanicidan alinan alinan bir inputun diziye eklenmesi
        PUSH AX                 ;; Ve linkli listenin buna gore tekrar duznelenmesini
        PUSH CX                 ;; Saglayan yordam.
        PUSH BX
        PUSH SI


                MOV AX, n
                INC n
                MOV CX, AX              ;; Diziye eklenecek olan elemanin
                SAL AX, 1               ;; Indisinin ele edilmesi.
                MOV SI, AX              ;; Word tabanlı bir dizi oldugundan
                LEA AX,MSG6             ;; Eleman sayisi * 2 bizim eklenecek indisimiz olackatir.
                CALL PUT_STR
                CALL GETN
                MOV mainArray[SI], AX   ;; Dizinin sonuna elemanin eklenmesi.

                CALL insertNode         ;; Onceden yazilmis instert yordamini tekrar
                                        ;; Kullanarak linkliListenin duzenlenmesi.       
        POP SI
        POP BX
        POP CX
        POP AX

       RET
       insertInput ENDP



        printInfo PROC NEAR
        PUSH AX
                MOV AX, LF
                CALL PUTC
                MOV AX, LF
                CALL PUTC
                LEA AX, INFOS
                CALL PUT_STR 
                MOV AX, LF
                CALL PUTC
                MOV AX, LF
                CALL PUTC
        POP AX
        RET
        printInfo ENDP

                ;------------------------------------------------------------------------
                ; BU SATIRDAN ASAGISI KITAPTAN ALINAN
                ; INPUT VE OUTPUT ICIN KULLANILAN YORDAMLAR
                ;------------------------------------------------------------------------
                

        GETC	PROC NEAR
                ;------------------------------------------------------------------------
                ; Klavyeden basılan karakteri AL yazmacına alır ve ekranda gösterir. 
                ; işlem sonucunda sadece AL etkilenir. 
                ;------------------------------------------------------------------------
                MOV AH, 1h
                INT 21H
                RET 
        GETC	ENDP 

        PUTC	PROC NEAR
                ;------------------------------------------------------------------------
                ; AL yazmacındaki değeri ekranda gösterir. DL ve AH değişiyor. AX ve DX 
                ; yazmaçlarının değerleri korumak için PUSH/POP yapılır. 
                ;------------------------------------------------------------------------
                PUSH AX
                PUSH DX
                MOV DL, AL
                MOV AH,2
                INT 21H
                POP DX
                POP AX
                RET 
        PUTC 	ENDP 


        GETN 	PROC NEAR
                ;------------------------------------------------------------------------
                ; Klavyeden basılan sayiyi okur, sonucu AX yazmacı üzerinden dondurur. 
                ; DX: sayının işaretli olup/olmadığını belirler. 1 (+), -1 (-) demek 
                ; BL: hane bilgisini tutar 
                ; CX: okunan sayının islenmesi sırasındaki ara değeri tutar. 
                ; AL: klavyeden okunan karakteri tutar (ASCII)
                ; AX zaten dönüş değeri olarak değişmek durumundadır. Ancak diğer 
                ; yazmaçların önceki değerleri korunmalıdır. 
                ;------------------------------------------------------------------------
                PUSH BX
                PUSH CX
                PUSH DX
        GETN_START:
                MOV DX, 1	                        ; sayının şimdilik + olduğunu varsayalım 
                XOR BX, BX 	                        ; okuma yapmadı Hane 0 olur. 
                XOR CX,CX	                        ; ara toplam değeri de 0’dır. 
        NEW:
                CALL GETC	                        ; klavyeden ilk değeri AL’ye oku. 
                CMP AL,CR 
                JE FIN_READ	                        ; Enter tuşuna basilmiş ise okuma biter
                CMP  AL, '-'	                        ; AL ,'-' mi geldi ? 
                JNE  CTRL_NUM	                        ; gelen 0-9 arasında bir sayı mı?
        NEGATIVE:
                MOV DX, -1	                        ; - basıldı ise sayı negatif, DX=-1 olur
                JMP NEW		                        ; yeni haneyi al
        CTRL_NUM:
                CMP AL, '0'	                        ; sayının 0-9 arasında olduğunu kontrol et.
                JB error 
                CMP AL, '9'
                JA error		                ; değil ise HATA mesajı verilecek
                SUB AL,'0'	                        ; rakam alındı, haneyi toplama dâhil et 
                MOV BL, AL	                        ; BL’ye okunan haneyi koy 
                MOV AX, 10 	                        ; Haneyi eklerken *10 yapılacak 
                PUSH DX		                        ; MUL komutu DX’i bozar işaret için saklanmalı
                MUL CX		                        ; DX:AX = AX * CX
                POP DX		                        ; işareti geri al 
                MOV CX, AX	                        ; CX deki ara değer *10 yapıldı 
                ADD CX, BX 	                        ; okunan haneyi ara değere ekle 
                JMP NEW 		                ; klavyeden yeni basılan değeri al 
        ERROR:
                MOV AX, OFFSET HATA 
                CALL PUT_STR	                        ; HATA mesajını göster 
                JMP GETN_START                          ; o ana kadar okunanları unut yeniden sayı almaya başla 
        FIN_READ:
                MOV AX, CX	                        ; sonuç AX üzerinden dönecek 
                CMP DX, 1	                        ; İşarete göre sayıyı ayarlamak lazım 
                JE FIN_GETN
                NEG AX		                        ; AX = -AX
        FIN_GETN:
                POP DX
                POP CX
                POP DX
                RET 
        GETN 	ENDP 

        PUTN 	PROC NEAR
                ;------------------------------------------------------------------------
                ; AX de bulunan sayiyi onluk tabanda hane hane yazdırır. 
                ; CX: haneleri 10’a bölerek bulacağız, CX=10 olacak
                ; DX: 32 bölmede işleme dâhil olacak. Soncu etkilemesin diye 0 olmalı 
                ;------------------------------------------------------------------------
                PUSH CX
                PUSH DX 	
                XOR DX,	DX 	                        ; DX 32 bit bölmede soncu etkilemesin diye 0 olmalı 
                PUSH DX		                        ; haneleri ASCII karakter olarak yığında saklayacağız.
                                                        ; Kaç haneyi alacağımızı bilmediğimiz için yığına 0 
                                                        ; değeri koyup onu alana kadar devam edelim.
                MOV CX, 10	                        ; CX = 10
                CMP AX, 0
                JGE CALC_DIGITS	
                NEG AX 		                        ; sayı negatif ise AX pozitif yapılır. 
                PUSH AX		                        ; AX sakla 
                MOV AL, '-'	                        ; işareti ekrana yazdır. 
                CALL PUTC
                POP AX		                        ; AX’i geri al 
                
        CALC_DIGITS:
                DIV CX  		                ; DX:AX = AX/CX  AX = bölüm DX = kalan 
                ADD DX, '0'	                        ; kalan değerini ASCII olarak bul 
                PUSH DX		                        ; yığına sakla 
                XOR DX,DX	                        ; DX = 0
                CMP AX, 0	                        ; bölen 0 kaldı ise sayının işlenmesi bitti demek
                JNE CALC_DIGITS	                        ; işlemi tekrarla 
                
        DISP_LOOP:
                                                        ; yazılacak tüm haneler yığında. En anlamlı hane üstte 
                                                        ; en az anlamlı hane en alta ve onu altında da 
                                                        ; sona vardığımızı anlamak için konan 0 değeri var. 
                POP AX		                        ; sırayla değerleri yığından alalım
                CMP AX, 0 	                        ; AX=0 olursa sona geldik demek 
                JE END_DISP_LOOP 
                CALL PUTC 	                        ; AL deki ASCII değeri yaz
                JMP DISP_LOOP                           ; işleme devam
                
        END_DISP_LOOP:
                POP DX 
                POP CX
                RET
        PUTN 	ENDP 

        PUT_STR	PROC NEAR
                ;------------------------------------------------------------------------
                ; AX de adresi verilen sonunda 0 olan dizgeyi karakter karakter yazdırır.
                ; BX dizgeye indis olarak kullanılır. Önceki değeri saklanmalıdır. 
                ;------------------------------------------------------------------------
            PUSH BX 
                MOV BX,	AX			        ; Adresi BX’e al 
                MOV AL, BYTE PTR [BX]	                ; AL’de ilk karakter var 
        PUT_LOOP:   
                CMP AL,0		
                JE  PUT_FIN 			        ; 0 geldi ise dizge sona erdi demek
                
                CALL PUTC 			        ; AL’deki karakteri ekrana yazar
                INC BX 				        ; bir sonraki karaktere geç
                MOV AL, BYTE PTR [BX]
                JMP PUT_LOOP			        ; yazdırmaya devam 
        PUT_FIN:
            POP BX
            
            
            
            
            RET 
        PUT_STR	ENDP


mycs ENDS  
        END MAIN