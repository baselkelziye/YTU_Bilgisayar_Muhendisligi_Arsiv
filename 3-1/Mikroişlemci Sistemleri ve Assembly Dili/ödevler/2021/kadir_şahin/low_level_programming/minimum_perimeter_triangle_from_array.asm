

stacksg SEGMENT PARA STACK'STACK'
       
        DW 32 DUP(?)                ; Dongu degiskenlerini vs tutmak
                                    ; icin 32 WORD boyutunda stack segment tanimlandi

stacksg ENDS

datasg  SEGMENT PARA 'DATA'
    
    CR EQU 13   ;        '\r' icin CR <-- 13 olarak tanimlandi  
    LF EQU 10   ;        '\n' icin LF <-- 10 olarak tanimlandi
    
    MSG1  DB 'eleman sayisini giriniz [3-100] : ',0 
    HATA  DB CR,LF, 'sayi disi karakter! '
    HATA1 DB CR,LF, 'eleman sayisi [3-100] arasi olmali! tekrar giriniz ',0 
    
    MSG2  DB CR,LF, '0-1000 arasi degerler giriniz: ',0  
    HATA2 DB CR,LF, 'aralik disi deger! ',0  
    
    
    MSG3  DB CR,LF, 'en kucuk cevreli ucgeni olusturan kenarlar: ',0 
    MSG4  DB CR,LF, 'dizide ucgen olusturacak kenar yok ',0  
    MSG5  DB CR,LF, 'girilen elemanlar: ',0
    MSG6  DB CR,LF, 'en kucuk ucgenin cevresi: ',0
    n     DW 0   ;       Dizi boyutu tutacak degisken               
    dizi  DW 100 DUP(0); Dizi tanimlandi    
    a     DW 0         ; Ucgen uygunluk kontrolu icin gecici kenar degiskenleri
    b     DW 0         
    c     DW 0
    min_a DW 0         ; Uygun kenarlarin atanacagi asil degiskenler
    min_b DW 0
    min_c DW 0
min_cevre DW 0         ; Cevre buyukluk kontrolu icin asil degisken
     bool DW 0         ; Daha once hic ucgen kenari girilmemisse min_cevre kontrolunu
                       ; atlatmak icin 1 kez kullanip sonra 1 yapacagimiz degisken

datasg ENDS
    
codesg SEGMENT PARA 'CODE'
    
    ASSUME CS:codesg, DS:datasg, SS:stacksg
    ANA PROC FAR 
        
    PUSH DS            ;Donus icin gerekli olan degerler yiginda saklaniyor
    XOR AX,AX          
    PUSH AX                                                               
    
    MOV AX,datasg      ;Data segment gosterildi
    MOV DS,AX
    
   
    MOV AX, OFFSET MSG1 ;Yazdirilacak mesajin adresi AX'e aliniyor
    
    CALL PUT_STR        ;Mesaj yazdirma yordamini cagir

n_kontrol:   
    CALL GETN           ;dizi boyutu almak icin n degerini okundu
    CMP AX,100          ;ust limit kontrolu
    JA nhatayazdir      
    
    CMP AX,3            ;alt limit kontrolu
    JB nhatayazdir  
    JMP n_ok            ; uygun n degeri bulundu 
nhatayazdir:
    MOV AX,OFFSET HATA1
    CALL PUT_STR  
    JMP n_kontrol       ; uygun n degeri bulunamadi, degeri tekrar almak icin geri ziplandi
 
n_ok:
    MOV n,AX            ;Okunan n degeri AX registerindan alinip datasgye yazildi
    MOV AX,OFFSET MSG2  
    CALL PUT_STR        ;dizi elemanlari istendi
    
                             
    MOV CX,n            ;dizi boyutu kadar donmek icin n degeri CX'e atildi  
    LEA SI,dizi         ;dizinin adresi SI'ya atildi
    
L0:                      ;Dizi aliniyor
    CALL GETN            
    CMP AX,1000          
    JA khatayazdir
    
    CMP AX,0
    JB khatayazdir
    JMP ekle             ;Dizi elemani uygun bulundu

khatayazdir:    
    MOV AX,OFFSET HATA2
    CALL PUT_STR
    JMP L0               ;Dizi elemani uygun bulunmadi, tekrar almak icin geri ziplandi
    
ekle:
    MOV WORD PTR[SI],AX  ;Uygun bulunan eleman SI'daki adresine yazildi  
    INC SI               ;Bir sonraki eleman WORD tipinde oldugu icin
    INC SI               ;SI adresi 2 kez arttirildi
    LOOP L0 
    
    
    MOV AX,OFFSET MSG5
    CALL PUT_STR   
   
               
    MOV CX,n               
    LEA DI,dizi


Lyazdir:                 ;Girilen dizi yazdiriliyor

    MOV AX,[DI] 
    CALL PUTN  
    INC DI 
    INC DI
    MOV AX,32            ;dizi elemanlari arasinda bosluk birakmak icin
    CALL PUTC
    
    LOOP Lyazdir   
         
         
         
    MOV CX,n
    SUB CX,2                ;Tum elemanlarin ucgen olusturma kontrolu icin en distaki
                            ;dongunun n-2 kez olmali 
    
    LEA SI,dizi     ;       i-->SI 
     
L1:                
    PUSH CX         ; Ic ice 3 for dongusu kullanacagimiz icin,icteki dongulerde de CX
                    ; registeri lazim olacak, dis dongunun cevrim sayisini
                    ; tutan CX degeri kaybolmamasi lazim, o yuzden stacke atiyoruz
    MOV DI,SI       ;       j=i--- >DI     
    
    MOV AX,WORD PTR[SI]
    MOV a,AX                ; ilk dongunun baktigi deger gecici degiskene alindi
L2: 
    INC DI                  ;j=i+1  ;icteki dongu bir sonraki adresten baslamali
    INC DI
    MOV AX,WORD PTR[DI] 
    MOV b,AX                
    PUSH CX         ; En icteki donguye girerken de CX korunmasi lazim, bir kez daha sakliyoruz
    
    MOV BX,DI               ;k=i--->BX
L3: 
    INC BX                  
    INC BX                  ;k=j+1  ; en icteki dongu de bir dis dongunun bir sonraki 
                            ;         adresinden baslamali  
    MOV AX,WORD PTR[BX]
    MOV c,AX
                  
                ; Ucgen olusturabilme kurali 
                ; (|b-c|<a<(b+c)) && (|a-c|<b<(a+c)) &&(|a-b|<c<(a+b)) 
                
                ; fakat kontrol kolayligi icin ucgen olusturmama durumlari dislandi
                
                ; Ucgen olusturmama kurali
                ; ((a+b)<=c) || ((a+c)<=b) || ((b+c)<=a) olarak dusunulebilir
                
                
                
                
    MOV AX,a    ; a degeri AX'te
    ADD AX,b    ; (a+b) degeri AX'te
    CMP AX,c    ; ((a+b)<=c) durumu kontrol edildi    
    
    JBE  ortak  ; ucgen olusturmama durumu saglandi,
                ; hicbir deger atamasi yapilmadan donguden cikildi
    
    
    
    SUB AX,b    ;(a+b) AX'teydi b cikartildi
    ADD AX,c    ;(a+c) degeri AX'te
    CMP AX,b    ;((a+c)<=b) ?
    
    JBE  ortak  ; ucgen olusturmama durumu saglandi,
                ; donguden cikildi
    
    SUB AX,a    ;(a+c) AX'teydi a cikartildi
    ADD AX,b    ;(b+c) degeri AX'te
    CMP AX,a    ;((b+c)<=a) ?
    
    JBE  ortak ; ucgen olusturmama durumu saglandi,
               ; donguden cikildi
    
    
    ADD AX,a   ; Ucgen olusturma durumu saglandi,
               ; (b+c) degeri AX'teydi, minimum cevre uzunlugu
               ;kontrolu icin c degeri de AX'e atildi 
               ;(a+b+c) AX'te  
    
    
    
    
    
    CMP bool,0 ; Daha  once herhangi bir uygun ucgen bulunmus ise,
               ; yeni toplam, minimum cevre uzunlugu kontrolune girecek
               ; bu kontrolu yapmadan min_cevre kontrolunu yaparsak her turlu
               ;ilk 0 olarak tanimlanan min_cevre uzunlugu yeni ucgenimizden daha 
               ;kisa cevreli gorulecegi icin hicbir uygun ucgenimiz min_cevre 
               ; ucgeni olarak atanamaz
    
    JZ ilk_min ; Henuz hic uygun ucgen girilmemis, o yuzden min_cevre 
               ; kontrolunu atlatip direk ilk minimum kenarlarimizi atiyoruz
  
    CMP AX,min_cevre
    JAE ortak  ; Daha once uygun kenarli ucgen girilmis ve yeni cevremiz 
               ; o cevreden kucuk bulundu
                
               ;min_cevre ve kenarlar guncellenecek
ilk_min:
     
    MOV min_cevre,AX 
    MOV AX,a
    MOV min_a,AX
    MOV AX,b
    MOV min_b,AX
    MOV AX,C
    MOV min_c,AX   
    MOV bool,1  ;Artik uygun bir ucgen girilmis oldugu icin bool'un 1 olmasi lazim
    
   
  
ortak:
     LOOP L3  ; En ic dongu tanimlandi   
          
    POP CX  ;ortadaki dongunun cevrim sayisi stackten geri alindi
    
    LOOP L2   ; Ortanca dongu tanimlandi
    POP CX  ;en distaki dongunun cevrim sayisi stackten geri alindi
    
    INC SI  ;en dis dongunun cevrim degiskeni i(SI) artirildi
    INC SI 
    
    LOOP L1  ; En dis dongu tanimlandi
    
             
             
             
             
             ;Kontroller tamamlandi, varsa en kucuk kenarlar yazdirilacak
             
             
             
             
    
    MOV AX,min_cevre
    CMP AX,0  ; Uygun ucgen bulunup bulunmadigi kontrol ediliyor
    JE hatali_exit  ; min_cevre hala 0 ise uygun bir kenar bulunamamistir, hata yazdir
    
    
    MOV AX,OFFSET MSG6
    CALL PUT_STR
    
    MOV AX,min_cevre   ;burasi calistiysa uygun bir ucgen bulunmustur, cevresini yazdir
    CALL PUTN
    MOV AX,32
    CALL PUTC
    
    
    MOV AX,OFFSET MSG3 ;bulunan ucgenin kenarlarini yazdir
    CALL PUT_STR
    
   
    MOV AX,min_a
    CALL PUTN
    MOV AX,32
    CALL PUTC
    
    MOV AX,min_b
    CALL PUTN
    MOV AX,32
    CALL PUTC
    
    MOV AX,min_c
    CALL PUTN
    MOV AX,32
    CALL PUTC
     
    JMP exit        ;kenar bulunduktan sonra hata yazdirmadan basarili cikisa ziplandi

hatali_exit:
    MOV AX,OFFSET MSG4
    CALL PUT_STR        

exit:               
        
                    
    RETF
ANA ENDP            ; programin ana procedure'unden basariyla cikildi
    
GETC PROC NEAR      ; klavyeden deger alma fonksiyonu
                    
    
    MOV AH,1h       ; DOS'un 21h kesmesinin 1. (ekrandan karakter okuma) fonksiyon nosu AH a atildi
    INT 21h         ; klavyeden karakter almak icin DOS'un 21H kesmesi cagrildi
    RET
GETC ENDP

PUTC PROC NEAR      ; ekrana karakter basma fonksiyonu
    
    PUSH AX 
    PUSH DX
    MOV DL,AL       ;ekrana basilacak degerin ASCII'si AL'den DL'e alindi
    MOV AH,2        ;DOS'un 21h kesmesinin 1. (ekrana karakter basma) fonksiyon nosu AH a atildi
    INT 21h         ;DOS'un 21h kesmesi ekrana karakter basmak icin cagrildi 
    POP DX           
    POP AX
    RET
PUTC ENDP 

GETN PROC NEAR     ; klavyeden sayi okuma fonksiyonu
    
    PUSH BX        ;etkilenecek registerlarin degerleri saklaniyor
    PUSH CX
    PUSH DX
GETN_START:

    MOV DX,1       ;isaret bilgisi tutacak
    XOR BX,BX      ; hane okurken ara deger olarak kullanilacak
    XOR CX,CX      ;ara toplam degeri tutulacak
NEW:
    CALL GETC
    CMP AL,CR    ;enter tusuna basilip basilmadigini CR'deki 13 degeriyle AL'deki alinan
                 ;karakterini kiyaslayarak buluyor
                 
    JE FIN_READ  ; enter ise okumayi bitirmek icin fin_read'e zipla
    CMP AL,'-'   ;negatif sayi girilip girilmedigini kontrol icin '-' degerinin ASCII'siyle
                 ;AL'deki alinmis karakterin ASCII'sini karsilastiriyor
    
    JNE CTRL_NUM ;negatif degilse DX'i -1 yapmadan 0-9 arasi kontrolune zipla
NEGATIVE:
    MOV DX,-1    ;'-' karakteri girildigi icin isaret icin kullandigimiz DX'i 1 yaptik
    JMP NEW      ;yeni haneyi almak icin NEW'e zipladik
    
CTRL_NUM:        ;Girilen sayi 0-9 arasinda mi kontrolu
    
    CMP AL, '0'
    JB ERROR     ; 0'dan kucukse error yazdir
    CMP AL, '9'
    JA ERROR     ; 9'dan buyukse error yazdir
    SUB AL,'0'
    MOV BL,AL    ; alinan haneyi BL'ye koy
    MOV AX,10    ; haneyi eklerken *10 ile carpa carpa ekleyecegimiz icin, AX'e 10 attik
    
    PUSH DX      ; MUL komutu DX'i bozacagi icin sayinin isaret bilgisi saklanmali
    MUL CX       ;DX:AX = AX*CX 
    
    POP DX       ; saklanan isaret bilgisini geri aliyoruz
    MOV CX,AX    ; CX'teki ara deger *10 yapildi
    
    ADD CX,BX    ;alinan yeni hane ara degere eklendi
    
    JMP NEW      ;klavyeden yeni basilan degeri almak icin NEW'e zipladik
ERROR:
    MOV AX,OFFSET HATA  ; sayi disi karakter basilmis, hata mesajinin OFFSET'i AX'e atiliyor.
    CALL PUT_STR
    JMP GETN_START      ;hata verildigi icin oncekileri unut, en basa donup tekrar okumaya basla

FIN_READ:
    MOV AX,CX           ;ENTER basildi, okuma bitirilecek, o ana kadar okunan ve ara degere
                        ; eklenen toplam, AX'te donecek
    CMP DX,1            ;sayiyi isarete gore eklemek icin isaret bilgisi tutan DX'i 1'le kiyasla
    
    JE FIN_GETN  ;isaret =1 , sayi pozitif, AX'i oldugu gibi birak
    NEG AX       ;isaret =-1, sayi negatif,AX'in complementini al
FIN_GETN:
    POP DX       ; saklanan degerler birakiliyor
    POP CX
    POP BX
    RET
GETN ENDP 

PUTN PROC NEAR   ; Ekrana sayi yazdirma fonksiyonu
    
    PUSH CX
    PUSH DX      ; AX'teki degerin hanelerini DIV ile bolecegimiz icin, etkilenecek
                 ; registerlar saklaniyor
    
    XOR DX,DX    ; yazilacak 
                 ;haneleri stackte tutacagimiz icin, hanelerin bittigini anlamak icin yigina
                 ; en ilk bi 0 degeri atacagiz,yigindan cikartirken 0'i gorunce islemi
                 ;bitirecegiz
    PUSH DX
    
    MOV CX,10    ;haneyi yazdirirken 10'a bole bole yazdiracagimiz icin CX=10
    CMP AX,0     ;girilen karakter 0'dan buyuk ise hane hesaplama fonksiyonuna zipla
    JGE CALC_DIGITS
    NEG AX        ; hane 0'dan kucuk ise, ilk biti sign bit alip gerisini pozitif yapmak
                    ;icin AX'i NEG yapariz
    PUSH AX        ; AX saklanir
    MOV AL,'-'     ;sayinin isareti ekrana basilmak icin AL'ye '-' ASCII'si atildi
    CALL PUTC
    POP AX         ;AX cikarildi
CALC_DIGITS:
    
    DIV CX         ;DX:AX = AX/CX AX=bolum DX=kalan
    ADD DX, '0'    ; kalan degerinin ASCII'sini almak icin DX'e '0'in ASCII'sini ekleriz
    PUSH DX        ;kalani yigina at
    XOR DX,DX
    CMP AX,0       ; bolen 0 kaldiysa tum haneler bolunerek yazdirilmistir
    JNE CALC_DIGITS
DISP_LOOP:

    POP AX         ;stack'e atilan haneleri sirayla aliyoruz
    CMP AX,0       ; hanelerin bitip bitmedigini anlamak icin cikani 0'la kiyasliyoruz
    JE END_DISP_LOOP  ; 0 ise yazdirmayi bitir
    
    CALL PUTC        ; hala yazilacak haneler var, karakter basma fonksiyonunu tekrar cagir
    JMP DISP_LOOP
END_DISP_LOOP:
    
    POP DX           ;etkilenen registerlarin fonksiyona girmeden onceki
    POP CX           ; degerleri cikariliyor
    RET
PUTN ENDP

PUT_STR PROC NEAR    ;Ekrana bir string yazdirma fonksiyonu
    
    PUSH BX          
    MOV BX,AX        ;Yazilacak stringin adresi BX e alindi
    MOV AL,BYTE PTR[BX] ;BX adresindeki karakter, yazilmak icin AL'ye alindi
PUT_LOOP:
    CMP AL,0     ;AL'deki karakter 0 ise stringin sonuna gelinmistir, yazmayi bitir
    JE PUT_FIN
    
    CALL PUTC    ; 0 degilse alinan karakteri yazdirmaya devam et
    INC BX       ; karakter yazdirildi,indisi arttir
    MOV AL,BYTE PTR[BX] 
    JMP PUT_LOOP ; yazdirma dongusune devam et
PUT_FIN:
    POP BX    ; saklanan BX cikarildi
    RET
PUT_STR ENDP  ; String yazdirma fonksiyonunu bitir



codesg ENDS   ; code segmenti bitir
    END ANA   ; ANA procedure'unu sonlandir
    
