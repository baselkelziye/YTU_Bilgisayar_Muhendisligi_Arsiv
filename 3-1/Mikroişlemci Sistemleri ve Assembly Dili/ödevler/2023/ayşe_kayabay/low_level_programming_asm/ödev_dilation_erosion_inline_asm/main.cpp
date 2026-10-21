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

	short *resimdizi_org = (short*) malloc(N*M * sizeof(short));

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			resimdizi_org[i*N + j] = (short)resim_org[i][j];
			/*if (i<3)
			{
				printf("%d-", resimdizi_org[i*N + j]);

			}*/
		}
		//if (i < 3)
		//{
		//	printf("\n---------\n", resimdizi_org[i*N + j]);

		//}
	}

			

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
			break;
	}

	system("PAUSE");
	return 0;
}
void Dilation(int n, int filter_size, short* resim_org) {

	__asm {
		mov ax,-1
		mov bl,1
		mul bl
		MOV ECX, n
		MOV EBX, resim_org
		O1 : MOVSX EAX, WORD PTR[EBX]
		CMP EAX, 128
		JB A1
		MOV WORD PTR[EBX], 255
		JMP O2
		A1 : MOV WORD PTR[EBX], 0
		O2 : ADD EBX, 2
		LOOP O1
		MOV EBX, resim_org
		MOV EDI, EBX
		MOV n, 512
		MOV EAX, n                   
		SUB EAX, filter_size
		INC EAX
		MUL EAX
		MOV ECX, EAX
		MOV ESI, 1                   
		A2:	MOV EAX, filter_size      
		MUL EAX
		PUSH ECX                     
		MOV ECX, EAX
		XOR EDX, EDX                  
		A3 : MOVSX EAX, WORD PTR[EBX]
		CMP EAX, 255      
		JNE L1
		MOV WORD PTR[EDI], 255        
		L1 : PUSH EDX               
		INC EDX                       
		MOV EAX, EDX
		XOR EDX, EDX
		DIV filter_size               
		CMP EDX, 0
		JNZ L2
		MOV EAX, n                    
		SUB EAX, filter_size          
		INC EAX                       
		SHL EAX, 1                    
		ADD EBX, EAX                  
		JMP L3
		L2 : ADD EBX, 2               
		L3 : POP EDX
		INC EDX                       
		LOOP A3
		POP ECX                       
		MOV EAX, ESI                  
		MUL n
		SUB EAX, EDI
		CMP EAX, filter_size
		JNE L4
		MOV EAX, filter_size
		SHL EAX, 1
		ADD EDI, EAX                  
		INC ESI                       
		JMP L5
		L4 : ADD EDI, 2          
		L5 : MOV EBX, EDI         
		LOOP A2
	}
	printf("\nDilation islemi sonucunda resim \"dilated.pgm\" ismiyle olusturuldu...\n");
}

void Erosion(int n, int filter_size, short* resim_org) {
	__asm {
		MOV ECX, n
		MOV EBX, resim_org
		O1 : MOVSX EAX, WORD PTR[EBX]
		CMP EAX, 128
		JB A1
		MOV WORD PTR[EBX], 255
		JMP O2
		A1 : MOV WORD PTR[EBX], 0
		O2 : ADD EBX, 2
		LOOP O1
		MOV EBX, resim_org
		MOV EDI, EBX
		MOV n, 512
		MOV EAX, n                 
		SUB EAX, filter_size
		INC EAX
		MUL EAX
		MOV ECX, EAX
		MOV ESI, 1									
		A2:MOV EAX, filter_size		            
		MUL EAX
		PUSH ECX									
		MOV ECX, EAX
		XOR EDX, EDX								
		A3 : MOVSX EAX, WORD PTR[EBX]
		CMP EAX, 0									
		JNE L1
		MOV WORD PTR[EDI], 0						
		L1 : PUSH EDX								
		INC EDX														
		MOV EAX, EDX
		XOR EDX, EDX
		DIV filter_size												
		CMP EDX, 0
		JNZ L2
		MOV EAX, n													
		SUB EAX, filter_size										
		INC EAX											
		SHL EAX, 1					
		ADD EBX, EAX				
		JMP L3
		L2 : ADD EBX, 2				
		L3 : POP EDX
		INC EDX						
		LOOP A3
		POP ECX						
		MOV EAX, ESI									
		MUL n	
		SUB EAX, EDI
		CMP EAX, filter_size
		JNE L4
		MOV EAX, filter_size
		SHL EAX, 1
		ADD EDI, EAX												
		INC ESI														
		JMP L5
		L4 : ADD EDI, 2												
		L5 : MOV EBX, EDI											
		LOOP A2
	}
	printf("\nErosion islemi sonucunda resim \"eroded.pgm\" ismiyle olusturuldu...\n");
}


