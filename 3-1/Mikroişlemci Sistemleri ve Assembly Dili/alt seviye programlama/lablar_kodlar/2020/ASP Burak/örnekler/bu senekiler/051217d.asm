; bu ornek code kesimlerinin birlesitirilmesin gostermek uzere yazildi		
		; YARDIMCI isimli yordam baska bir segmentteki kod tarafindan cagirilip
		; kullanilabilsin diye PUBLIC tanimlanir.
		public yardimci 
		; bu yordam kendisini cagiran kodun DATA alani icinde ismi DÝZÝ olan 
		; bir veriye erissin diye EXTRN tanimi yapilir.
		extrn dizi:word 
		; bu yordam calisabilsin diye CX yazmaci uzerinde de dizinin eleman
		; sayisini alir. 
mycs	segment para public 'code'
		assume cs:mycs
yardimci	proc far
			push si		; yordam calisirken cx, si degerlerini deðiþtirecek 
			push cx		; bunlarin onceki degerleri kayip olmasin 
			
			xor si,si
		l1:	push cx			; diziyi shift ile carpacagimzi icin  
			mov cl,3		; cl'Yi kullanmamiz lazim. CX bozulmadan
			shl dizi[si],cl 	; dizi elemanlarini 2^3 ile carpar.
			add si,2		; dizi word tanimli ise indis cift artar
			pop cx 
			loop l1 
			
			pop cx			; yigina koyduklarimi geri aliyorum.
			pop si
			
			ret 
yardimci	endp 
mycs		ends 
			end   ; bu kendi basina calismayacagi icin END kelimesinden 
				  ; sonra bir yordam ismi YAZILMAZ
				 