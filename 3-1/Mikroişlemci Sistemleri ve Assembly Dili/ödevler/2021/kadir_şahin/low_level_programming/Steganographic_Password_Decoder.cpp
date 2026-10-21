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
			MOV EBX, steganografi_adres // steganografi_adres dizisinin adresi EBX regiserina alindi, adres integer geldigi icin EBX kullanildi 
			MOV ESI, resim_org			// resim_org dizisinin adresi ESI registerina alindi
			MOV EDI, resim_ste			// resim_ste dizisinin adresi EDI registerina alindi
			MOV ECX, n					// dizi boyutu, dongu icin CX e atildi.

Loop_OS: 	MOV AL,[EDI]				//EDI adresindeki sayi AL'ye atildi
			CMP AL,[ESI]				//ESI adresindeki sayi deger ile AL registerina alinmis olan deger, sifre kontrolu icin kiyaslaniyor
			JE Ortak					// degerler ayni ise steganografi dizimize herhangi bir deger eklemeden dongunun ortak labelina ziplariz
										// cunku orada bir sifreleme yapilmamis
			JA TasmaYok					//resim_ste dizisinden aldigimiz ve AL'ye attigimiz deger ESI'daki orjinal degerden buyukse,
										//sifreleme yapilmis ve tasma olmamis demektir

			ADD AX, 256					//burasi calistiysa tasma durumu vardir, sifreli degere 256 ekleyip sonra resim_org dizindeki degeri cikararak
										//sifre olarak eklenen ASCII degerini buluruz
		
TasmaYok:   SUB AX, WORD PTR[ESI]		//256 eklenmis AX'teki sifreli degerden resim_org taki orjinal degeri cikartiyoruz
		    MOV BYTE PTR[EBX],AL		//AX'in low kisminda kalan deger sifre olarak eklenmis karakterin ASCII kodudur,
										//bu kodu EBX adresiyle gosterdigimiz steganografik_adres dizimize atiyoruz

			INC EBX						//yeni bir karakter eklendigi icin indisi artirmamiz lazim
				
Ortak:		INC ESI						//resim_org'un indisi arttiriliyor
			INC ESI
			INC EDI						//resim_ste'nin indisi arttiriliyor
			INC EDI

			LOOP Loop_OS				//bu kontrol dongusu, ECX registeri 0'lanincaya kadar donuyor

			MOV [EBX],' '				//bulmus oldugumuz sifreye numaramizi ekliyoruz >> 
			INC EBX
			MOV [EBX],'-'
			INC EBX
			MOV[EBX], ' '
			INC EBX
			MOV [EBX],'1'
			INC EBX
			MOV[EBX], '7'
			INC EBX
			MOV[EBX], '0'
			INC EBX
			MOV[EBX], '1'
			INC EBX
			MOV[EBX], '1'
			INC EBX
			MOV[EBX], '7'
			INC EBX
			MOV[EBX], '0'
			INC EBX
			MOV[EBX], '3'
			INC EBX
			MOV [EBX],'\0'				// sifremizi attigimiz dizideki string ifadenin bittigini belirtmek icin sonuna NULL karakter ekliyoruz
	}
}
