#include <math.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

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

	short* yeni_resim = (short*)malloc(n * sizeof(n));

	for (int i = 0; i < n; i++) {
		yeni_resim[i] = resim_org[i];
	}

	__asm{

		xor ecx, ecx
		dec ecx

		FIND_SQRT :
					inc ecx
					mov eax, ecx
					mul eax
					cmp eax, n
					jne FIND_SQRT

		mov n, ecx


						// for (i = filter_size; i < n - filter_size; i++) {
						mov esi, filter_size; i = filtre_size
						mov edi, n
						sub edi, filter_size

				for1 :  cmp esi, edi
						ja endfor1
						// for (j = filter_size; j < n - filter_size; j++) {

						push eax
						push ebx
						push ecx
						push edi
						push esi
						push ebp


						mov ebx, filter_size
						mov edi, n; ebxte n var
						sub edi, filter_size	// ikinci loop donguyu ayarlama yine n - 2 tane filtresize kadar donucek

					for2 :  cmp ebx, edi
							ja endfor2

							push eax
							push ebx
							push ecx
							push edi
							push esi
							push ebp

							
								// for (k = -filter_size; k <= filter_size; k++) {
								mov ecx, filter_size		// k = filtre_size
								neg ecx					// 	ARTIK K = -FILTRESIZE
								mov edi, filter_size

								xor eax, eax 		// maxı tanımlama kismi. max için eax registerını kullanıyorum

							for3:
								cmp ecx, edi		//ucuncu for sartının ic kismini ayarlama
								jge endfor3

								push ebx
								push ecx
								push edx
								push edi
								push esi
								push ebp

								// for (l = -filter_size; l <= filter_size; l++) {
									mov edx, filter_size
									neg edx
									mov edi, filter_size

							for4: 	cmp edx, edi
									jge endfor4
									// if (resimadres[(i + k) * n + (j + l)] > max) 

									push ebx
									push ecx
									push edx
									push edi
									push esi
									push ebp

									push eax

									add esi, ecx
									mov eax, n
									mul esi

									add eax, ebx
									add eax, edx

									mov esi, eax
									pop eax

									shl esi , 1

									//(esi + ecx) * n + ebp + edx
									mov ebx, yeni_resim
									mov cx, WORD PTR [ebx + esi] 
									cmp cx, ax
									jg maxiguncelle
									jmp next_loop

								maxiguncelle :
												mov ax, cx

								next_loop :

												pop ebp
												pop esi
												pop edi
												pop edx
												pop ecx
												pop ebx

												inc edx
												jmp for4

								endfor4 :
												pop ebp
												pop esi
												pop edi
												pop edx
												pop ecx
												pop ebx

												inc ecx
												jmp for3
							


								endfor3 :

								// resimadres[i * n + j] = max;
								push eax
								push edx

								mov eax, esi
								mul n
								add eax, ebx

								shl eax, 1
								mov esi, eax

								pop edx
								pop eax

								mov ebx, resim_org
								mov WORD PTR [ebx + esi], ax

								pop ebp
								pop esi
								pop edi
								pop ecx
								pop ebx
								pop eax

								inc ebx
								jmp for2

					endfor2 :
								pop ebp
								pop esi
								pop edi
								pop ecx
								pop ebx
								pop eax

								inc esi
								jmp for1

					endfor1 : // end of the function

		mov n , edx

	}

	

	printf("\nDilation islemi sonucunda resim \"dilated.pgm\" ismiyle olusturuldu...\n");
}

void Erosion(int n, int filter_size, short* resim_org) {


	short* yeni_resim = (short*)malloc(n * sizeof(n));

	for (int i = 0; i < n; i++) {
		yeni_resim[i] = resim_org[i];
	}

	__asm {

		xor ecx, ecx
		dec ecx

		FIND_SQRT :
					inc ecx
					mov eax, ecx
					mul eax
					cmp eax, n
					jne FIND_SQRT

					mov n, ecx


			// for (i = filter_size; i < n - filter_size; i++) {
					mov esi, filter_size //i = filtre_size
					mov edi, n
					sub edi, filter_size

			for1 : 
					cmp esi, edi
					ja endfor1
				// for (j = filter_size; j < n - filter_size; j++) {

					push eax
					push ebx
					push ecx
					push edi
					push esi
					push ebp


					mov ebx, filter_size
					mov edi, n // edida n var
					sub edi, filter_size // loopdonguyu ayarladigim yer n - 2 filtresize kadar donucek

				for2: 
						cmp ebx, edi
						ja endfor2

						push eax
						push ebx
						push ecx
						push edi
						push esi
						push ebp


					// for (k = -filter_size; k <= filter_size; k++) {
						mov ecx, filter_size 	// k = filtre_size
						neg ecx 		// ARTIK K = -FILTRESIZE
						mov edi, filter_size

						mov eax , 255 // mini tanimladigim yer. her seferinde 255 ile karsilastirip kücükse degistirecegim.

					for3 :
							cmp ecx, edi 	// 3.for sartinin ayarlanmasi 
							jge endfor3

							push ebx
							push ecx
							push edx
							push edi
							push esi
							push ebp

						//for (l = -filter_size; l <= filter_size; l++) {
							mov edx, filter_size
							neg edx
							mov edi, filter_size

						for4: 	cmp edx, edi
								jge endfor4
								// if (resimadres[(i + k) * n + (j + l)] < MİN) 

								push ebx
								push ecx
								push edx
								push edi
								push esi
								push ebp

								push eax

								add esi, ecx
								mov eax, n
								mul esi

								add eax, ebx
								add eax, edx

								mov esi, eax
								pop eax

								shl esi, 1

							//(esi + ecx) * n + ebp + edx
							mov ebx, yeni_resim
							mov cx, WORD PTR[ebx + esi]
							cmp cx, ax
							jl miniguncelle
							jmp next_loop

			miniguncelle :
							mov ax, cx

			next_loop :
							pop ebp
							pop esi
							pop edi
							pop edx
							pop ecx
							pop ebx

							inc edx
							jmp for4

			endfor4 :
							pop ebp
							pop esi
							pop edi
							pop edx
							pop ecx
							pop ebx

							inc ecx
							jmp for3



			endfor3:
						// resimadres[i * n + j] = MİN;
							push eax
							push edx

							mov eax, esi
							mul n
							add eax, ebx

							shl eax, 1
							mov esi, eax

							pop edx
							pop eax

							mov ebx, resim_org
							mov WORD PTR[ebx + esi], ax


							pop ebp
							pop esi
							pop edi
							pop ecx
							pop ebx
							pop eax

							inc ebx
							jmp for2

				endfor2:
							pop ebp
							pop esi
							pop edi
							pop ecx
							pop ebx
							pop eax

							inc esi
							jmp for1

				endfor1: // end of the function

				mov n, edx

					}

	printf("\nErosion islemi sonucunda resim \"eroded.pgm\" ismiyle olusturuldu...\n");
}