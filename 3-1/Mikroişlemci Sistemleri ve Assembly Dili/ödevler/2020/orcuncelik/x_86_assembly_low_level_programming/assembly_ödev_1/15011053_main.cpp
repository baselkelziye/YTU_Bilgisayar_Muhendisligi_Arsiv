#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "image_processing.cpp"

using namespace std;

void SteganografiBul(int n, int resimadres_org, int resimadres_ste, int steganografi_adres);

int main(void) {
	int M, N, Q, i, j;
	bool type;
	int efile;
	char org_resim[100], ste_resim[100], steganografi[100];
	do {
		printf("Orijinal resmin yolunu (path) giriniz:\n-> ");
		scanf("%s", &org_resim);
		system("CLS");
		efile = readImageHeader(org_resim, N, M, Q, type);
	} while (efile > 1);
	int** resim_org = resimOku(org_resim);

	do {
		printf("Steganografik resmin yolunu (path) giriniz:\n-> ");
		scanf("%s", &ste_resim);
		system("CLS");
		efile = readImageHeader(ste_resim, N, M, Q, type);
	} while (efile > 1);
	int** resim_ste = resimOku(ste_resim);

	printf("Orjinal Resim Yolu: \t\t\t%s\n", org_resim);
	printf("SteganografiK Resim Yolu: \t\t%s\n", ste_resim);

	short *resimdizi_org, *resimdizi_ste;
	resimdizi_org = (short*) malloc(N*M * sizeof(short));
	resimdizi_ste = (short*) malloc(N*M * sizeof(short));

	for (i = 0; i < N; i++) 
		for (j = 0; j < M; j++) {
			resimdizi_org[i*N + j] = (short) resim_org[i][j];
			resimdizi_ste[i*N + j] = (short) resim_ste[i][j];
		}

	int resimadres_org = (int) resimdizi_org;
	int resimadres_ste = (int) resimdizi_ste;
	int steganografi_adres = (int) steganografi;

	SteganografiBul(N*M, resimadres_org, resimadres_ste, steganografi_adres);

	printf("\nResim icerisinde gizlenmis kod: \t%s\n", steganografi);
	system("PAUSE");
	return 0;
}

void SteganografiBul(int n, int resim_org, int resim_ste, int steganografi_adres) {
	__asm {
		MOV ESI, resim_org            ;Orijinal resim dizisinin adresini ESI tutar.
		MOV EDI, resim_ste            ;Steganografik resim dizisinin adresini EDI tutar.
		MOV EBX, steganografi_adres   ;Sifreyi yazacagimiz dizinin adresini EBX tutar.
		MOV ECX, n              ;32 bitlik count registeri ECX matrisin a*a = n boyut tutar.
L1:		MOV AX, [EDI]           ;Steganografik resim dizini degerini AX e atariz.
		CMP AX, [ESI]           ;Steganografik resim dizisi ile orijinal resim dizisin karsilastirilmasi.
		JA toplam               ;Ste dizisi eger Org dizisinden buyuk ise mod alma durumu olmadan ekleme sozkonusu, toplam labelina gidilir.
	    JE ortak                ;Esit oldugunda ortak labelindan loopa devam eder.
		ADD AX, 256             ;Org dizisi eger Ste dizisinden buyukse 256 ya gore mod alma islemi.
toplam: SUB AX, WORD PTR[ESI]   ;Sifreyi bulmak icin Ste dizisinden Org dizisi cikarilir.
		MOV BYTE PTR[EBX], AL   ;AL registerindaki sifre steganografi_adres e atılır.
		INC EBX                 ;steganografi_adres in indisi 1 arttirilir.(1byte oldugundan)
		JMP ortak               ;ortak arttirilacak indislere dallanma yapilir.
ortak:	ADD EDI, 2			    ;Steganografik resim dizisinin indisi 2 arttirilir.(2byte oldugundan)
		ADD ESI, 2			    ;Steganografik resim dizisinin indisi 2 arttirilir.(2byte oldugundan)
		LOOP L1

	    ;Numara yazma islemi
	    MOV BYTE PTR[EBX], 45; Tire karakteri ASCII karşılığı
	    INC EBX
		MOV BYTE PTR[EBX], 49; 1 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 53; 5 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 48; 0 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 49; 1 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 49; 1 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 48; 0 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 53; 5 ASCII karşılığı
		INC EBX
		MOV BYTE PTR[EBX], 51; 3 ASCII karşılığı
		INC EBX
		MOV CX, 20
L0:		MOV BYTE PTR[EBX], 0; Gereksiz bolgeleri temizlemek icin.
		INC EBX
		LOOP L0
	}
}

