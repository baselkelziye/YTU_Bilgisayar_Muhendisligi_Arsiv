#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int AsalMi(int, int);
void KartiYazdir(int *);
bool Search(int *, int, int);
int SearchRetYer(int *, int, int);
int RastgeleAsalSayiCek(int*, int);
bool VarMi(int, int *, int *);

const int tomsize = 8, ikiliasal = 22, iki = 2;
bool yerler[8];

int main(){
	srand(time(NULL));
	int i, j, rast;
	int tombala[tomsize], cek[ikiliasal];
	
	for(i = 0; i < tomsize; i++){
		tombala[i] = 0;
		yerler[i] = false;
	} 
	for(i = 0; i < ikiliasal; i++)
		cek[i] = 0;

	for(i = 0; i < tomsize; i++){
		system("CLS");
		printf("Tombala Kartinin Iki Basamakli Asal Sayilarini Giriyorsunuz...\n\n");
		KartiYazdir(tombala);
		do{
			printf("tombala[%d]: ", i);
			scanf("%d", &tombala[i]);
		}while((Search(tombala, i-1, tombala[i])) || (AsalMi(tombala[i], iki) != tombala[i]));		
	}
	system("CLS");
	printf("Tombala Karti Asagidaki Gibi Olusturuldu...\n\n");
	KartiYazdir(tombala);
	
	i = 0;
	j = 0;
	while(i < tomsize){
		rast = RastgeleAsalSayiCek(cek, j);
		cek[j++] = rast;
		if(VarMi(rast, tombala, cek))
			i++;
		system("PAUSE");
	}
	
	printf("\nToplam %d tas cekilerek tombala yapilmistir !\n\n", j);
	
	system("PAUSE");
	return 0;
}

int AsalMi(int a, int b){
	if(a < 10)
		return 0;
	else{
		if((a % b) == 0)
			return b;
		else
			return AsalMi(a, b+1);	
	}
}

void KartiYazdir(int* kart){
	int i;
	for(i = 0; i < tomsize; i++)
		if(kart[i] == 0)
			printf("__  ");
		else
			printf("%d  ", kart[i]);
	printf("\n");
	for(i = 0; i < tomsize; i++)
		if(yerler[i])
			printf("%c%c  ", 94, 94);
		else
			printf("    ");
	printf("\n");
}

bool Search(int *dizi, int son, int ara){
	bool bul = false;
	while(!bul && son >= 0)
		if(dizi[son--] == ara)
			bul = true;
	return bul;
}
int SearchRetYer(int *dizi, int son, int ara){
	bool bul = false;
	int yer = -1;
	while(yer == -1 && son >= 0)
		if(dizi[son--] == ara)
			yer = son + 1;
	return yer;
}

int RastgeleAsalSayiCek(int* cek, int son){
	int sayi;
	bool whilestate = false;
	do{
		sayi = rand() % 90 + 10;
		if(Search(cek, son, sayi))
			whilestate = true;
		else if(AsalMi(sayi, iki) != sayi)
			whilestate = true;
		else
			whilestate = false;	
	}while(whilestate);
	return sayi;
}

bool VarMi(int rast, int* kart, int* cek){
	int i, yer = SearchRetYer(kart, tomsize, rast);
	bool ret = false;
	if(yer != -1){
		yerler[yer] = true;
		ret = true;
	}
	
	system("CLS");
	printf("*** Tombala Karti ***\n");
	KartiYazdir(kart);
	
	printf("\n*** Cekilen Taslar ***\n");
	i = 0;
	while(cek[i] != 0)
		printf("%d, ", cek[i++]);
	
	printf("\n\nCekilen sayi: %d\n\n", rast);	
	
	return ret;
}
