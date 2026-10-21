			PUBLIC DNUM
;			EXTERN dizi
mycs2 	SEGMENT PARA 'code'
			ASSUME CS:mycs2
			
			;Iki dnum fonk isimleri aynı oldugu ici yoruma aldım
			
;DNUM		PROC FAR			
;			PUSH BP					; BP Kullanacağım için stack atıyorum
;			PUSH BX					; BX Kullanacağım için stack atıyorum
;			PUSH AX					; AX Kullanacağım için stack atıyorum
;			MOV BP, SP				; Stackten veri çekmek için bp içine sp atıyorum
;			MOV BX, [BP+8]			; stackten veri çekiyorum
;			PUSH BX					; çektiğim n değerini stack atıyorum
;			DEC BX					; dnum(n-1) icin 1 azaltiyorum
;			MOV BX, dizi[BX]		; dnum degerini bx icine atıyorum
;			MOV AX, dizi[BX]		; dnum(dnum(n-1)) hesapliyorum
;			POP BX					; n degerine geri donuyorum
;			PUSH BX					; n degerini tekrar kaydediyorum
;			SUB BX, 2				; n-2 yapıyorum
;			MOV DX, dizi[BX]		; dnum(n-2) hesapliyorum
;			POP BX					; n degerine geri donuyorum
;			PUSH BX					; n degerini kaydediyorum
;			SUB BX, DX				; n-dnum(n-2) hesapliyorum
;			DEC BX					; n-1-dnum(n-2) hesapliyorum
;			MOV DX, dizi[BX]		; dnum(n-1-dnum(n-2))
;			ADD AX, DX				; dnum(dnum(n-1))+ dnum(n-1-dnum(n-2))
;			POP BX 					; nereye kaydedecegimi cekiyorum
;			MOV dizi[BX], AX		; dizi[n] kaydediyorum
;			POP AX					; basta pushladığım ax i cikariyorum
;			POP BX					; basta pushladığım bx i cikariyorum
;			POP BP					; basta pushladığım bp yi
;			RETF

;DNUM 		ENDP			
	
	
DNUM 		PROC FAR
			PUSH BP					; önceki stack yerimizi kaybolmasın diye stack e atıyorum
			PUSH CX					; önceki n değeri kaybolmasın diye stack e atıyorum
			MOV BP, SP				; işlem yaparken bp kullanacağım ama stackte nerde olduğuma ihtiyacım var sp yi bp attım
			MOV CX, [BP+8] 			; n değerini stackten aldım 		; AX + BP + CX + FAR?
			CMP CX, 0				; n değeri 0 mı diye bakıyorum özel durum var 0 için
			JNZ D1					; n değeri 0 değilse D1 labelına atlıyoruz  
			POP CX					; n değeri 0 ise fonksiyondan çıkmak için pushladığım CX değerini geri alıyorum
			POP BP					; pushladığım BP değerini geri alıyorum			
			RETF					; nerde çağırıldıysam oraya dönüyorum
D1:			CMP CX, 2				; n in 0 olmadığın ıöğrendik 2 iel  karşılaştırıyorum
			JA D2					; n>2 ise dnum(dnum(n-1))+dnum(n-1-dnum(n-2)) yapmak için D2 labelına atlıyorum
			MOV WORD PTR [BP+8], 1	; n<2 değerleri için özel durumdan n değerine 1 atıyoruz
			POP CX					; n değeri 0 ise fonksiyondan çıkmak için pushladığım CX değerini geri alıyorum
			POP BP					; pushladığım BP değerini geri alıyorum
			RETF					; nerde çağırıldıysam oraya dönüyorum
D2:			PUSH BX					; recursive taraftaki fonksiyonlardadeğişen n değerlerini tutmak için b kullanıyorum
									; kaybolmasın diye stack e atıyorum
			PUSH AX					; toplama işleminin sonucunu AX te tutucam önceki değer kaybolmasın diye stack attım
			MOV BX, CX				; n değerini bx atıyorum
			DEC BX					; n-1 yapıyorum
			PUSH BX					; n-1i tekrar kullanıcam stack atıyorum
			CALL DNUM 				; dnum(n-1) hesaplıyor
			POP AX					; hesaplanan değeri ax içine koyuyor
			PUSH AX					; çıkan değeri direkt kullanacağız stack attım
			CALL DNUM 				; dnum(dnum(n-1)) hesapliyor
			POP AX					; sonucu ax icine atıyor
			PUSH AX					; başka şeyler de hesaplıcaz değerimizi kaybetmeyelim diye stack attım
			PUSH CX					; n değerini işlemde kullancağız kaybolmasın diye stack attım
			SUB CX, 2				; dnum(n-2) hesaplamak için n değerini 2 azalttım
			PUSH CX					; dnum kullanmak için n-2 yi stack attım
			CALL DNUM 				; dnum(n-2)
			POP AX					; dnum(n-2) sonucunu ax attım
			POP CX 					; n değerini kullanmak için stackten aldım
			DEC CX					; n-a(n-2) değerini hesapladım
			SUB CX, AX				; n-1-a(n-2) değerini hesapladım
			PUSH CX					; dnumda kullanmak için stack attım
			CALL DNUM				; dnum çağırdım
			POP BX					; dnum(n-1-dnum(n-2)) sonuncu bx attım toplama yapıcaz
			POP AX					; önceden stack attığım dnum(dnum(n-1)) değerini ax attım
			ADD AX, BX 				; bu değerleri ax içinde topladım
			MOV [BP+8], AX 			; ax içindeki değeri stackte tutulan n içine attım
			POP AX					; D2 labelının orda stack attığım ax değerini geri aldım
			POP BX					; D2 labelının orda stack attığım bx değerini geri aldım
			POP CX					; en basta stack attığım cx i geri aldım
			POP BP					; en basta stack attığım bp yi geri aldım			
			RETF					; fonksiyondan çıktım
DNUM ENDP

mycs2 ENDS
END 
