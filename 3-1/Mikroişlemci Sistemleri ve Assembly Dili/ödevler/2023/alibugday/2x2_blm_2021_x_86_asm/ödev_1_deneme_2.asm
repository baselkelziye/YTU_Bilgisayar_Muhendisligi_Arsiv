STEK SEGMENT PARA STACK 'STK'
DW 100 DUP(?)
STEK ENDS


DSG  SEGMENT PARA 'DTS'
    CR	EQU 13
    LF	EQU 10
    HATA	DB CR, LF, 'Dikkat !!! Sayi vermediniz yeniden giris yapiniz.!!!', 0        
    mesaj db CR, LF, "Hangi islemi yapmak istersiniz            M.Ali Bugday 19011076",0
    mesaj1 db CR, LF,"1)Dizi gir",0
    mesaj2 db CR, LF,"2)Linked goruntule",0
    mesaj3 db CR, LF,"3)Eleman ekle:",0
    mesaj4 db CR, LF,"4)cikis",0 
    mesaj5 db CR, LF,"dizinin uzunlugu:",0
    mesaj6 db CR, LF,"dizi degeri giriniz:",0
    mesaj7 db "-",0
    mesaj8 db ">",0
    mesaj9 db CR, LF,"Eklenecek dergeri giriniz:",0
    mesaj10 db CR, LF,"                                           M.Ali Bugday 19011076",0
    altsatir db CR, LF,"",0
    virgul db ", ",0
 
    dizi dw 0,15 dup(-100)
    dizi2 dw 0,15 dup(-100)
    max_si dw -1
    max_dizi dw -1000
    dizi_uzunluk dw 0 
    
DSG ENDS

CSG  SEGMENT PARA 'CODE'
ASSUME CS:CSG, DS:DSG, SS:STEK

BASLA   PROC FAR

PUSH DS
XOR AX,AX
PUSH AX

MOV AX, DSG
MOV DS, AX
 

 
;kod araligi basliyor
    MOV AX, OFFSET mesaj
    CALL PUT_STR
    
while:
    MOV AX, OFFSET mesaj1
    CALL PUT_STR
    MOV AX, OFFSET mesaj2
    CALL PUT_STR
    MOV AX, OFFSET mesaj3
    CALL PUT_STR   
    MOV AX, OFFSET mesaj4
    CALL PUT_STR
    CALL GETN
         
    cmp ax,1
    je bir
    
    cmp ax,2
    je iki
    
    cmp ax,3
    je uc
    
    cmp ax,4
    je son     
    
bir:
    
    MOV AX, OFFSET mesaj5
    CALL PUT_STR
    CALL GETN
    mov cx,ax
    mov dizi_uzunluk,cx
    
    call alt1      
    
    jmp secimsonu
      
iki:
    mov cx,dizi_uzunluk
    xor si,si
    
    MOV AX, OFFSET altsatir
    CALL PUT_STR
    
    call dizi2_yedekle
    mov max_dizi,-1000
    mov max_si,-1
    
    xor si,si
  l2:
    mov ax, dizi[si]
    call putn
    add si,2
    MOV AX, OFFSET virgul
    CALL PUT_STR
    loop l2
    
    MOV AX, OFFSET altsatir
    CALL PUT_STR
    
    mov cx,dizi_uzunluk
    l4:
        push cx
        mov cx,dizi_uzunluk
        xor si,si
        xor bx,bx             
                     
        mov ax,dizi[si]
        
        mov max_dizi,ax
         
      l5:
        add si,2
        mov ax,dizi[si]
        
        
        ;isaretli dallanma
        cmp dizi[si],-1
        jle isaretli
       
        cmp max_dizi,ax
        jg devam
       
        mov ax,dizi[si]
         
        mov max_dizi,ax
        mov bx,si
        jmp devam
        
 isaretli:
        cmp max_dizi,ax
        jg devam
        mov ax,dizi[si]
         
        mov max_dizi,ax
        mov bx,si      
        
    
    devam:
       
        loop l5
        
        xchg max_si,bx  
          
        mov ax,max_dizi
        call putn
        
        MOV AX, OFFSET mesaj7
        CALL PUT_STR
        MOV AX, OFFSET mesaj8
        CALL PUT_STR
        
        
        cmp bx,-1
        je ilk
        shr bx,1
        
        
     ilk:
        mov ax,bx
        call putn
        
        cmp bx,-1
        je ilk2
        shl bx,1
    ilk2:
        
        MOV AX, OFFSET virgul
        CALL PUT_STR
        
        xchg max_si,bx 
    
        mov dizi[bx],-100
        
        xchg max_si,bx
        
        pop cx
        sub cx,1
        jcxz devam2
        jmp l4
   devam2:     
    call dizi_yedekle
    jmp secimsonu
   


uc:
    call alt2
    
    ;jmp iki
    
             
secimsonu:
    MOV AX, OFFSET mesaj10
    CALL PUT_STR    
    jmp while
    
    
son:
;kod araliði bitiyor



RETF
BASLA   ENDP 

alt1 proc 
    push cx
    push si
    push ax
    
    xor si,si
    
  l1:
    MOV AX, OFFSET mesaj6
    CALL PUT_STR
    CALL GETN
    mov dizi[si],ax
    add si,2
    loop l1      
    
    pop ax      
	pop si
	pop cx
    ret
alt1 endp

alt2 proc near
    push bx
    xor bx,bx
    
    MOV AX, OFFSET mesaj9
    CALL PUT_STR
    CALL GETN
    mov bx,dizi_uzunluk
    shl bx,1
    mov dizi[bx],ax
    add dizi_uzunluk,1
    
    
cikar:

        
    pop bx
    ret    
alt2 endp

dizi2_yedekle proc
    push cx
    push si
    
    mov cx,dizi_uzunluk
    xor si,si
    
  l6:
    mov ax,dizi[si]
    mov dizi2[si],ax
    add si,2
    loop l6  
    
    pop si
    pop cx
    ret
dizi2_yedekle endp

dizi_yedekle proc
    push cx
    push si
    
    mov cx,dizi_uzunluk
    xor si,si
    
  l7:
    mov ax,dizi2[si]
    mov dizi[si],ax
    add si,2
    loop l7  
    
    pop si
    pop cx
    ret
dizi_yedekle endp

GETC	PROC NEAR
        ;------------------------------------------------------------------------
        ; Klavyeden basýlan karakteri AL yazmacýna alýr ve ekranda gösterir. 
        ; iþlem sonucunda sadece AL etkilenir. 
        ;------------------------------------------------------------------------
        MOV AH, 1h
        INT 21H
        RET 
GETC	ENDP 

PUTC	PROC NEAR
        ;------------------------------------------------------------------------
        ; AL yazmacýndaki deðeri ekranda gösterir. DL ve AH deðiþiyor. AX ve DX 
        ; yazmaçlarýnýn deðerleri korumak için PUSH/POP yapýlýr. 
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
        ; Klavyeden basýlan sayiyi okur, sonucu AX yazmacý üzerinden dondurur. 
        ; DX: sayýnýn iþaretli olup/olmadýðýný belirler. 1 (+), -1 (-) demek 
        ; BL: hane bilgisini tutar 
        ; CX: okunan sayýnýn islenmesi sýrasýndaki ara deðeri tutar. 
        ; AL: klavyeden okunan karakteri tutar (ASCII)
        ; AX zaten dönüþ deðeri olarak deðiþmek durumundadýr. Ancak diðer 
        ; yazmaçlarýn önceki deðerleri korunmalýdýr. 
        ;------------------------------------------------------------------------
        PUSH BX
        PUSH CX
        PUSH DX
GETN_START:
        MOV DX, 1	                        ; sayýnýn þimdilik + olduðunu varsayalým 
        XOR BX, BX 	                        ; okuma yapmadý Hane 0 olur. 
        XOR CX,CX	                        ; ara toplam deðeri de 0’dýr. 
NEW:
        CALL GETC	                        ; klavyeden ilk deðeri AL’ye oku. 
        CMP AL,CR 
        JE FIN_READ	                        ; Enter tuþuna basilmiþ ise okuma biter
        CMP  AL, '-'	                        ; AL ,'-' mi geldi ? 
        JNE  CTRL_NUM	                        ; gelen 0-9 arasýnda bir sayý mý?
NEGATIVE:
        MOV DX, -1	                        ; - basýldý ise sayý negatif, DX=-1 olur
        JMP NEW		                        ; yeni haneyi al
CTRL_NUM:
        CMP AL, '0'	                        ; sayýnýn 0-9 arasýnda olduðunu kontrol et.
        JB error 
        CMP AL, '9'
        JA error		                ; deðil ise HATA mesajý verilecek
        SUB AL,'0'	                        ; rakam alýndý, haneyi toplama dâhil et 
        MOV BL, AL	                        ; BL’ye okunan haneyi koy 
        MOV AX, 10 	                        ; Haneyi eklerken *10 yapýlacak 
        PUSH DX		                        ; MUL komutu DX’i bozar iþaret için saklanmalý
        MUL CX		                        ; DX:AX = AX * CX
        POP DX		                        ; iþareti geri al 
        MOV CX, AX	                        ; CX deki ara deðer *10 yapýldý 
        ADD CX, BX 	                        ; okunan haneyi ara deðere ekle 
        JMP NEW 		                ; klavyeden yeni basýlan deðeri al 
ERROR:
        MOV AX, OFFSET HATA 
        CALL PUT_STR	                        ; HATA mesajýný göster 
        JMP GETN_START                          ; o ana kadar okunanlarý unut yeniden sayý almaya baþla 
FIN_READ:
        MOV AX, CX	                        ; sonuç AX üzerinden dönecek 
        CMP DX, 1	                        ; Ýþarete göre sayýyý ayarlamak lazým 
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
        ; AX de bulunan sayiyi onluk tabanda hane hane yazdýrýr. 
        ; CX: haneleri 10’a bölerek bulacaðýz, CX=10 olacak
        ; DX: 32 bölmede iþleme dâhil olacak. Soncu etkilemesin diye 0 olmalý 
        ;------------------------------------------------------------------------
        PUSH CX
        PUSH DX 	
        XOR DX,	DX 	                        ; DX 32 bit bölmede soncu etkilemesin diye 0 olmalý 
        PUSH DX		                        ; haneleri ASCII karakter olarak yýðýnda saklayacaðýz.
                                                ; Kaç haneyi alacaðýmýzý bilmediðimiz için yýðýna 0 
                                                ; deðeri koyup onu alana kadar devam edelim.
        MOV CX, 10	                        ; CX = 10
        CMP AX, 0
        JGE CALC_DIGITS	
        NEG AX 		                        ; sayý negatif ise AX pozitif yapýlýr. 
        PUSH AX		                        ; AX sakla 
        MOV AL, '-'	                        ; iþareti ekrana yazdýr. 
        CALL PUTC
        POP AX		                        ; AX’i geri al 
        
CALC_DIGITS:
        DIV CX  		                ; DX:AX = AX/CX  AX = bölüm DX = kalan 
        ADD DX, '0'	                        ; kalan deðerini ASCII olarak bul 
        PUSH DX		                        ; yýðýna sakla 
        XOR DX,DX	                        ; DX = 0
        CMP AX, 0	                        ; bölen 0 kaldý ise sayýnýn iþlenmesi bitti demek
        JNE CALC_DIGITS	                        ; iþlemi tekrarla 
        
DISP_LOOP:
                                                ; yazýlacak tüm haneler yýðýnda. En anlamlý hane üstte 
                                                ; en az anlamlý hane en alta ve onu altýnda da 
                                                ; sona vardýðýmýzý anlamak için konan 0 deðeri var. 
        POP AX		                        ; sýrayla deðerleri yýðýndan alalým
        CMP AX, 0 	                        ; AX=0 olursa sona geldik demek 
        JE END_DISP_LOOP 
        CALL PUTC 	                        ; AL deki ASCII deðeri yaz
        JMP DISP_LOOP                           ; iþleme devam
        
END_DISP_LOOP:
        POP DX 
        POP CX
        RET
PUTN 	ENDP 

PUT_STR	PROC NEAR
        ;------------------------------------------------------------------------
        ; AX de adresi verilen sonunda 0 olan dizgeyi karakter karakter yazdýrýr.
        ; BX dizgeye indis olarak kullanýlýr. Önceki deðeri saklanmalýdýr. 
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
        JMP PUT_LOOP			        ; yazdýrmaya devam 
PUT_FIN:
	POP BX
	RET 
PUT_STR	ENDP

CSG  ENDS
END BASLA