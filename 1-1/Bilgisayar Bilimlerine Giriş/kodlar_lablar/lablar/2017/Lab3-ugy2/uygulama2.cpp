#include <stdio.h>
#include <string.h>
#include <math.h>
#include "image_processing.cpp"

void sagaDondur(int N, int M, int** resim);
void solaDondur(int N, int M, int** resim);
void sobel(int N, int M, int** resim);
void spatial(int N, int M, int** resim);

int main(void){
	//Verilen isimdeki resim okunuyor.
	int M, N, Q;
    bool type;
    int efile, islem;
    char resimadi[20], onek[5];
	do{	
		printf("Islem yapilacak resmin adini giriniz:\n-> ");
		scanf("%s", &resimadi);
		system("CLS");
		efile = readImageHeader(resimadi, N, M, Q, type);
	}while(efile > 1);
	int** resim = resimOku(resimadi); 
	//Okuma bitti
	
	
	do{
		system("CLS");
		printf("\t     ISLEMLER\n");
		printf("------------------------------------\n");
		printf("1)  Resmi saga dondur\n");
		printf("2)  Resmi sola dondur\n");
		printf("3)  Resmi spatial filtresinden gecir\n");
		printf("4)  Resmi sobel filtresinden gecir\n");
		printf("0)  Cikis\n\n");
		printf("\"%s\" resmi icin yapilacak islemi seciniz\n-> ", resimadi);
		scanf("%d", &islem);
	}while(islem > 4 || islem < 0);
	
	switch(islem){
		case 0:
			exit(0);
		case 1:
			sagaDondur(N, M, resim);
			strcpy(onek, "sag_");
			break;
		case 2:
			solaDondur(N, M, resim);
			strcpy(onek, "sol_");
			break;	
		case 3:
			spatial(N, M, resim);
			strcpy(onek, "spa_");
			break;
		case 4:
			sobel(N, M, resim);
			strcpy(onek, "sob_");
			break;	
		default:
			strcpy(onek, "orj_");
			break;
	}
	    
	//Okunduktan sonra üzerinde iþlem yapýlan resim verilen isimle yazdýrýlýyor.
	strcat(onek, resimadi);
	resimYaz(onek, resim, N, M, Q);
	//Yazdýrma bitti.
	
	printf("\nIslem basariyla tamamlandi :)\n%s isimli resim olusturuldu.\n\n",onek);
	
	system("PAUSE");
	return 0;
}

void sagaDondur(int N, int M, int** resim){
	if(N != M){
		printf("Saga dondurme sadece eni boyuna esit olan resimler icin yapilabilir !\n");
	}else{
		int i, j, tmp;
		for(i = 0; i < M/2; i++){
			for(j = i; j < M-1-i; j++){
				tmp = resim[i][j];
				resim[i][j] = resim[M-1-j][i];
				resim[M-1-j][i] = resim[M-1-i][M-1-j];
				resim[M-1-i][M-1-j] = resim[j][M-1-i];
				resim[j][N-1-i] = tmp;
			}
		}
	}
}

void solaDondur(int N, int M, int** resim){
	if(N != M){
		printf("Sola dondurme sadece eni boyuna esit olan resimler icin yapilabilir !\n");
	}else{
		int i, j, tmp;
		for(i = 0; i < M/2; i++){
			for(j = i; j < M-1-i; j++){
				tmp = resim[i][j];
				resim[i][j] = resim[j][M-1-i];
				resim[j][M-1-i] = resim[M-1-i][M-1-j];
				resim[M-1-i][M-1-j] = resim[M-1-j][i];
				resim[M-1-j][i] = tmp;
			}
		}
	}
}

void sobel(int N, int M, int** resim){
	int i, j; //çevrim deðiþkenleri
	int Gx, Gy;
	for(i = 0; i < N-2; i++){
		for(j = 0; j < M-2; j++){
			Gx = ((resim[i+2][j+1]*2+resim[i+2][j]+resim[i+2][j+2])-(resim[i][j+1]*2+resim[i][j]+resim[i][j+2]));
			Gy = ((resim[i+1][j+2]*2+resim[i][j+2]+resim[i+2][j+2])-(resim[i+1][j]*2+resim[i][j]+resim[i+2][j]));
			resim[i][j] = sqrt(pow(Gx, 2) + pow(Gy, 2));
		}
	}
}

void spatial(int N, int M, int** resim){
	int i,j; //çevrim deðiþkenleri
	int ustsatir; //bir pixel'in 8 komsuluðundan üstte olanlarýnýn toplamý
	int ortasatir; //bir pixel'in 8 komsuluðundan kendisiyle ayný satýrda olanlarýnýn toplamý
	int altsatir; //bir pixel'in 8 komsuluðundan altta olanlarýnýn toplamý
	
	for(i = 1; i < N-1; i++){
		for(j = 1; j < M-1; j++){
			ustsatir = resim[i-1][j-1] + resim[i-1][j] + resim[i-1][j+1];
			ortasatir = resim[i][j-1] + resim[i][j] + resim[i][j+1];
			altsatir = resim[i+1][j-1] + resim[i+1][j] + resim[i+1][j+1];
			resim[i][j] = (ustsatir + ortasatir + altsatir)/9;
		}
	}
}
