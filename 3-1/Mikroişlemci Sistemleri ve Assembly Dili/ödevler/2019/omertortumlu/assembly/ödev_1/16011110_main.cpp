#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "image_processing.cpp"

using namespace std;

void sagaDondur(short n, int resim);
void solaDondur(short n, int resim);

int main(void) {
	int M, N, Q, i, j, k;
	bool type;
	int efile, islem;
	char resimadi[100], sonek[10];
	do {
		printf("Islem yapilacak resmin yolunu (path) giriniz:\n-> ");
		scanf("%s", &resimadi);
		system("CLS");
		efile = readImageHeader(resimadi, N, M, Q, type);
	} while (efile > 1);
	printf("%s\n", resimadi);
	int** resim = resimOku(resimadi);

	short *resimdizi;
	resimdizi = (short*) malloc(N*M * sizeof(short));

	for (i = 0; i < N; i++) 
		for (j = 0; j < M; j++) 
			resimdizi[i*N + j] = (short) resim[i][j];

	int resimadres = (int) resimdizi;

	do {
		system("CLS");
		printf("\t     ISLEMLER\n");
		printf("------------------------------------\n");
		printf("1)  Resmi saga dondur\n");
		printf("2)  Resmi sola dondur\n");
		printf("0)  Cikis\n\n");
		printf("\"%s\" yolundaki resim icin yapilacak islemi seciniz\n-> ", resimadi);
		scanf("%d", &islem);
	} while (islem > 2 || islem < 0);

	switch (islem) {
		case 0:
			exit(0);
		case 1:
			sagaDondur(N, resimadres);
			strcpy(sonek, "_sag.pgm");
			break;
		case 2:
			solaDondur(N , resimadres);
			strcpy(sonek, "_sol.pgm");
			break;
		default:
			strcpy(sonek, "_orj.pgm");
			break;
	}

	for (k = 0; k < N * M; k++) {
		j = k % N;
		i = k / N;
		resim[i][j] = (int)resimdizi[k];
	}
	
	string::size_type pos = string(resimadi).find_last_of(".");
	resimadi[pos] = '\0';
	strcat(resimadi, sonek);
	resimYaz(resimadi, resim, N, M, Q);
	printf("\nIslem basariyla tamamlandi :)\n\"%s\" yolunda resim olusturuldu.\n\n", resimadi);
	system("PAUSE");
	return 0;
}

void sagaDondur(short n, int resim) {
	//KODUNUZU BURADAN BASLAYARAK YAZINIZ
	unsigned int bir, iki, i;
	unsigned short temp;

	__asm {
		xor ecx, ecx
		xor eax, eax
		mov ax, n
		shr eax, 1
		mov bir, eax

		l1 :
			xor eax, eax
				mov ax, n
				sub eax, ecx
				dec eax
				mov iki, eax
				mov i, ecx
				push ecx

		l2 :
			xor eax, eax
				mov ax, n
				dec eax
				sub eax, ecx
				xor ebx, ebx
				mov ebx, eax;N - 1 - j deðeri ebx e atandý

			;birinci exchange temp<-esi
				xor eax, eax
				mov ax, n
				mul i
				add eax, ecx
				shl eax, 1
				mov esi, resim
				add esi, eax
				mov ax, word ptr[esi]
				mov temp, ax

			;dorduncu exchange esi<-edi
				xor eax, eax
				mov ax, n
				mul ebx
				add eax, i
				shl eax, 1
				mov edi, resim
				add edi, eax
				mov ax, word ptr[edi]
				mov word ptr[esi], ax

			;ucuncu exchange edi<-esi
				xor eax, eax
				mov ax, n
				mul iki
				add eax, ebx;N*(N - 1 - i) + N - 1 - j deðeri eax e atandý

				shl eax, 1
				mov esi, resim
				add esi, eax
				mov ax, word ptr[esi]
				mov word ptr[edi], ax

			;ikinci exchange esi<-edi
				xor eax, eax
				mov ax, n
				mul ecx
				add eax, iki
				shl eax, 1
				mov edi, resim
				add edi, eax
				mov ax, word ptr[edi]
				mov word ptr[esi], ax
		
		
			;besinci exchange edi<-temp
				mov ax, temp
				mov word ptr[edi], ax


				inc ecx
				cmp ecx, iki
				jl l2
				pop ecx



			inc ecx
			cmp ecx, bir
			jl l1



	}
	//KODUNUZU YAZMAYI BURADA BITIRINIZ
}

void solaDondur(short n, int resim) {
	//KODUNUZU BURADAN BASLAYARAK YAZINIZ
	unsigned int bir, iki, i;
	unsigned short temp;

	__asm {
		xor ecx,ecx
		xor eax,eax
		mov ax,n
		shr eax,1
		mov bir,eax

		l1:
			xor eax,eax
			mov ax,n
			sub eax,ecx
			dec eax
			mov iki,eax
			mov i,ecx
			push ecx

		l2: 
		;birinci exchange temp<-esi
			xor eax,eax
			mov ax,n
			mul i
			add eax,ecx
			shl eax,1
			mov esi,resim
			add esi,eax
			mov ax, word ptr[esi]
			mov temp,ax
		;ikinci exchange esi<-edi
			xor eax,eax
			mov ax,n
			mul ecx
			add eax,iki
			shl eax,1
			mov edi,resim
			add edi,eax
			mov ax,word ptr[edi]
			mov word ptr[esi],ax
		;ucuncu exchange edi<-esi
			xor eax,eax
			mov ax,n
			dec eax
			sub eax,ecx
			xor ebx,ebx
			mov ebx,eax			;N-1-j deðeri ebx e atandý

			xor eax,eax
			mov ax,n
			mul iki
			add eax,ebx 		;N*(N-1-i)+N-1-j deðeri eax e atandý
			
			shl eax,1
			mov esi,resim
			add esi,eax
			mov ax,word ptr[esi]
			mov word ptr[edi],ax
		;dorduncu exchange esi<-edi
			xor eax,eax
			mov ax,n
			mul ebx
			add eax,i
			shl eax,1
			mov edi,resim
			add edi,eax
			mov ax,word ptr[edi]
			mov word ptr[esi],ax
		;besinci exchange edi<-temp
			mov ax,temp
			mov word ptr[edi],ax


			inc ecx
			cmp ecx,iki
				jl l2
			pop ecx



		inc ecx
		cmp ecx,bir
			jl l1
			

		
	}
	//KODUNUZU YAZMAYI BURADA BITIRINIZ
}
