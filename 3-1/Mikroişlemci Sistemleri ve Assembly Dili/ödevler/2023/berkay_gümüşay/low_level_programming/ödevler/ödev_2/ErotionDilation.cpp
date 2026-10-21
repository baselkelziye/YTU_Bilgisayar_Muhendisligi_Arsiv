#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "image_processing.cpp"

using namespace std;

void Dilation(int n, int filter_size, short* resimadres_org);
void Erosion(int n, int filter_size, short* resimadres_org);

int main(void) {
	int M, N, Q, i, j, filter_size;
	bool type;
	int efile;
	char org_resim[100], dil_resim[] = "dilated.pgm", ero_resim[] = "eroded.pgm";
	do {
		printf("Orijinal resmin yolunu (path) giriniz:\n-> ");
		scanf("%s", &org_resim);
		system("CLS");
		efile = readImageHeader(org_resim, N, M, Q, type);
	} while (efile > 1);
	int** resim_org = resimOku(org_resim);

	printf("Orjinal Resim Yolu: \t\t\t%s\n", org_resim);

	short* resimdizi_org = (short*)malloc(N * M * sizeof(short));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			resimdizi_org[i * N + j] = (short)resim_org[i][j];

	int menu;
	printf("Yapmak istediginiz islemi giriniz...\n");
	printf("1-) Dilation\n");
	printf("2-) Erosion\n");
	printf("3-) Cikis\n> ");
	scanf("%d", &menu);
	printf("Filtre boyutunu giriniz: ");
	scanf("%d", &filter_size);

	switch (menu) {
	case 1:
		Dilation(N * M, filter_size, resimdizi_org);
		resimYaz(dil_resim, resimdizi_org, N, M, Q);
		break;
	case 2:
		Erosion(N * M, filter_size, resimdizi_org);
		resimYaz(ero_resim, resimdizi_org, N, M, Q);
		break;
	case 3:
		system("EXIT");
		break;
	default:
		system("EXIT");
		break;
	}

	system("PAUSE");
	return 0;
}

void Dilation(int n, int filter_size, short* resim_org) {
	//int i;
	short* tmp = (short*)malloc(262144 * sizeof(short));
	__asm {
			// resimde sütun / satir döngüsü
			mov eax, 512
			sub eax, filter_size
			inc eax
			mov ecx, eax
			mov edx, eax
			xor eax, eax

			//--------------------------------------------
			resimSatirLoop :
				push ecx
				mov edi, tmp
				mov esi, resim_org
				add esi, eax
				add edi, eax
				mov ecx, edx
				push edx
				xor edx, edx
				//--------------------------------------------
				resimSutunLoop :
						push ecx
						mov ecx, filter_size
						push eax
						xor eax, eax
						xor dx,dx
				//--------------------------------------------
					filtreSatirLoop:
						mov ebx, esi
						add ebx, eax
						push ecx
						mov ecx, filter_size
						//--------------------------------------------
						filtreSutunLoop :
								cmp dx, WORD PTR[ebx]
								jae buyuk
								mov dx, WORD PTR[ebx]
								buyuk : add ebx, 2
						loop filtreSutunLoop
						//--------------------------------------------
						pop ecx
						add eax, 1024
					loop filtreSatirLoop
				//--------------------------------------------
					sub ebx, 1030
					mov WORD PTR[edi], dx
					pop eax
					pop ecx
					add edi, 2
					add esi, 2
				loop resimSutunLoop
				//--------------------------------------------
				add eax, 1024
				pop edx
				pop ecx
			loop resimSatirLoop
				//--------------------------------------------
					// resimde sütun / satir döngüsü
				mov ebx, tmp
				mov esi,resim_org
				mov ecx,n
				loop1: mov ax,[ebx]
				mov [esi],ax
				add esi,2
				add ebx,2
				loop loop1
	
	}
	
	printf("\nDilation islemi sonucunda resim \"dilated.pgm\" ismiyle olusturuldu...\n");
	
}

void Erosion(int n, int filter_size, short* resim_org) {
	
	short* tmp = (short*)malloc(262144 * sizeof(short));
	__asm {
		// resimde sütun / satir döngüsü
		mov eax, 512
		sub eax, filter_size
		inc eax
		mov ecx, eax
		mov edx, eax
		xor eax, eax

		//--------------------------------------------
		resimSatirLoop :
			push ecx
				mov edi, tmp
				mov esi, resim_org
				add esi, eax
				add edi, eax
				mov ecx, edx
				push edx
				xor edx, edx
				//--------------------------------------------
				resimSutunLoop :
					push ecx
					mov ecx, filter_size
					push eax
					xor eax, eax
					mov dx, 255
					filtreSatirLoop:
						mov ebx, esi
						add ebx, eax
						push ecx
						mov ecx, filter_size
						//--------------------------------------------
						filtreSutunLoop :
							cmp dx, WORD PTR[ebx]
							jb kucuk
							mov dx, WORD PTR[ebx]
							kucuk : add ebx, 2
							loop filtreSutunLoop
						//--------------------------------------------
						pop ecx
						add eax, 1024
					loop filtreSatirLoop
					mov WORD PTR[edi], dx
					pop eax
					pop ecx
					add edi, 2
					add esi, 2
				loop resimSutunLoop
				//--------------------------------------------
				add eax, 1024
				pop edx
				pop ecx
			loop resimSatirLoop
			//--------------------------------------------
				// resimde sütun / satir döngüsü
			mov ebx, tmp
			mov esi, resim_org
			mov ecx, n
			loop1 : mov ax, [ebx]
			mov[esi], ax
			add esi, 2
			add ebx, 2
			loop loop1
	}
	
	printf("\nErosion islemi sonucunda resim \"eroded.pgm\" ismiyle olusturuldu...\n");
}
