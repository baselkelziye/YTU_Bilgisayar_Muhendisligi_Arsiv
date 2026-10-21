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
	}while (efile > 1);
	int** resim_org = resimOku(org_resim);

	printf("Orjinal Resim Yolu: \t\t\t%s\n", org_resim);

	short *resimdizi_org = (short*) malloc(N*M*sizeof(short));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			resimdizi_org[i*N + j] = (short)resim_org[i][j];

	int menu;
	
	printf("Yapmak istediginiz islemi giriniz...\n");
	printf("1-) Dilation\n");
	printf("2-) Erosion\n");
	printf("3-) Cikis\n> ");
	scanf("%d", &menu);
	printf("Filtre boyutunu giriniz: ");
	scanf("%d", &filter_size);

	switch (menu){
		case 1:
			Dilation(N*M, filter_size, resimdizi_org);
			resimYaz(dil_resim, resimdizi_org, N, M, Q);
			break;
		case 2:
			Erosion(N*M, filter_size, resimdizi_org);
			resimYaz(ero_resim, resimdizi_org, N, M, Q);
			break;
		case 3:
			system("EXIT");
			break;
		default:
			system("EXIT");
	}

	system("PAUSE");
	return 0;
}

void Dilation(int n, int filter_size, short* resim_org) {

	short* resim = (short*)malloc(n * sizeof(short));
	int i;
	for (i = 0; i < n; i++) 
		resim[i] = resim_org[i];
		
	__asm {
		
		MOV EDI,resim_org
		MOV ESI,resim
		MOV EBX,filter_size
		SHR EBX,1
		XOR EDX,EDX
		MOV EAX,1026
		MUL EBX
		MOV EBX,EAX
		MOV ECX,513
		SUB ECX,filter_size
		
LOOP_1 :
		PUSH ECX
		PUSH EBX
		MOV ECX,513
		SUB ECX,filter_size

LOOP_2 :
		PUSH ECX
		PUSH EBX
		MOV EAX,1026
		XOR EDX,EDX
		MOV ECX,filter_size
		SHR ECX,1
		MUL ECX
		SUB EBX,EAX
		MOV ECX,filter_size
		MOV AX,0

LOOP_3 :
		PUSH ECX
		PUSH EBX
		MOV ECX, filter_size

LOOP_4 :
		CMP WORD PTR[ESI + EBX],AX
		JNA SMALLER
		MOV AX, WORD PTR[ESI + EBX]

SMALLER:
		ADD EBX,2
		LOOP LOOP_4
		
		POP EBX
		ADD EBX,1024
		POP ECX
		LOOP LOOP_3
		
		POP EBX
		POP ECX
		MOV WORD PTR[EDI + EBX],AX
		ADD EBX,2
		LOOP LOOP_2
		
		
		POP EBX
		ADD EBX,1024
		POP ECX
		LOOP LOOP_1
		
	}
	printf("\nDilation islemi sonucunda resim \"dilated.pgm\" ismiyle olusturuldu...\n");
}

void Erosion(int n, int filter_size, short* resim_org) {

	short* resim = (short*)malloc(n * sizeof(short));
	int i;
	for (i = 0; i < n; i++) 
		resim[i] = resim_org[i];
	
	__asm {
		MOV EDI,resim_org
		MOV ESI,resim
		MOV EBX,filter_size
		SHR EBX,1
		XOR EDX,EDX
		MOV EAX,1026
		MUL EBX
		MOV EBX,EAX
		MOV ECX,513
		SUB ECX,filter_size
		
LOOP_1 :
		PUSH ECX
		PUSH EBX
		MOV ECX,513
		SUB ECX,filter_size

LOOP_2 :
		PUSH ECX
		PUSH EBX
		MOV EAX,1026
		XOR EDX,EDX
		MOV ECX,filter_size
		SHR ECX,1
		MUL ECX
		SUB EBX,EAX
		MOV ECX,filter_size
		MOV AX,7FFFh  

LOOP_3:
		PUSH ECX	
		PUSH EBX
		MOV ECX,filter_size

LOOP_4 :
		CMP WORD PTR[ESI + EBX],AX
		JA BIGGER
		MOV AX,WORD PTR[ESI + EBX]

BIGGER :
		ADD EBX,2
		LOOP LOOP_4
		
		POP EBX
		ADD EBX,1024
		POP ECX
		LOOP LOOP_3
		
		POP EBX
		POP ECX
		MOV WORD PTR[EDI + EBX], AX
		ADD EBX, 2
		LOOP LOOP_2
		
		POP EBX
		ADD EBX, 1024
		POP ECX
		LOOP LOOP_1
		
	}
	printf("\nErosion islemi sonucunda resim \"eroded.pgm\" ismiyle olusturuldu...\n");
}
