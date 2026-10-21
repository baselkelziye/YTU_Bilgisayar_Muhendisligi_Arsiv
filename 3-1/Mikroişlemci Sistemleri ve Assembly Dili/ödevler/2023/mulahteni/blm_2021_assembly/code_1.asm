			EXTRN DNUM:FAR
myds 	SEGMENT PARA 'data'
N			DW 10					; n = 10 değerini atadım
;N1			DW 500					; n = 500 değerini atadım
;dizi		PUBLIC DB 501 DUP(?)

myds 	ENDS

myss 	SEGMENT PARA STACK 'yigin'
			DW 200 DUP(?)			; stackte yer ayırdım n=10 için fazla ama olsun
myss 	ENDS

mycs 	SEGMENT PARA 'code'
		ASSUME CS:mycs, SS:myss, DS:myds

PRINTINT	PROC NEAR
		PUSH BX						; bölme işleminde kaybolmasın diye stack attım
		PUSH BP						; bölme işleminde kaybolmasın diye stack attım
		PUSH DX 					; bölme işleminde kaybolmasın diye stack attım
		MOV BP, SP					; işlem yaparken bp kullanacağım ama stackte nerde olduğuma ihtiyacım var sp yi bp attım
		MOV AX, [BP+8] 				; yazdıracağım sayıyı stackten ax e aldım 
		MOV BX, 1					; P2 yazdırma döngüsünü bitimek için bildiğim bir değer atıyorum
		PUSH BX						; P2 yazdırma döngüsünü bitimek için atadığım değeri stack atıyorum
		XOR DX, DX 					; ax i word tipine böleceğim dx 0 olmalı
		MOV BX, 0Ah					; decimal için 10a bölmem lazım bx içine 10 attım
P1:		DIV BX						; ax/bx
		ADD DX, '0'					; P2 döngüsünün ayarlıyorum
		PUSH DX						; P2 döngüsünün ayarlıyorum
		XOR DX, DX					; işlem tekrar gerçekleşebilir diye tekrar sıfırlıyorum
		CMP AX, 0					; bölmeye gerek var mı diye bakıyorum
		JNZ P1						; gerek varsa başa zıplıyorum
P2:		POP AX						; döngüden çıkmak için bildiğim değere yaklaşıyorum
		CMP AX, 1					; döngü bildiğim değere ulaştı mı diye kontrol ediyorum
		JZ P3						; ulaştıysa çıkmak için P3 zıplıyorum
		MOV DL, AL					; ulaşmadıysa yazdırmak için gerekli kod
		MOV AH, 2					; yazdırmak için gerekli kod
		INT 21h						; yazdırmak için gerekli kod
		JMP P2						; döngü için koşulsuz jump
P3:		POP DX						; bölmede kaybolmasın diye kaybettiğim değeri geri alıyorum
		POP BP						; bölmede kaybolmasın diye kaybettiğim değeri geri alıyorum
		POP BX						; bölmede kaybolmasın diye kaybettiğim değeri geri alıyorum
		RET 2						; stackten 2 değer silerek fonksiyondan çıktım
PRINTINT	ENDP

MAIN 		PROC FAR
		PUSH DS						; EXE tipi zorunlu kodlar
		XOR AX, AX					; EXE tipi zorunlu kodlar
		PUSH AX						; EXE tipi zorunlu kodlar
		MOV AX, myds				; EXE tipi zorunlu kodlar
		MOV DS, AX 					; EXE tipi zorunlu kodlar
		
		; DNUM İSLEMLERİ
		MOV AX, N					; n değerini kullanmak için ax atıyorum
		PUSH AX						; dnum içinde kullanabilmek için stack atıyorum
		CALL DNUM					; dnum(ax) çağırıyorum
		CALL PRINTINT				; dnum(ax)ten dönen sonucu yazdırmak için printint çağırıyorum
		
		; DINAMIK DNUM İSLEMLERİ
;		XOR SI, SI
;		MOV dizi[SI], 0
;		ADD SI,2
;		MOV dizi[SI], 1
;		ADD SI,2
;		MOV dizi[SI], 1
;		ADD SI,2
;		MOV CX, N1					; n değerini kullanmak için ax atıyorum
;LOOP1:	MOV AX, SI
;		ADD SI,2
;		PUSH AX						; dnum içinde kullanabilmek için stack atıyorum
;		CALL DDNUM					; dnum(ax) çağırıyorum
;		LOOP LOOP1
;		MOV AX, dizi[SI]
;		XOR AH, AH
;		PUSH AX
;		CALL PRINTINT				; dinamik fonksiyonu data segmentten baktığım kadarıyla doğru hesaplıyor gibi ama
									; printint fonksiyonuyla birlikte kullanmayı başaramadım
									
		RETF						; fonksiyonumu bitiyorum
MAIN ENDP
mycs ENDS
END MAIN
