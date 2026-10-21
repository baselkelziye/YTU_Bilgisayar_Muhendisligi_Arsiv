#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PRODUCTS 6

typedef struct {
	int kod;
	char name[30];
	double birim;
	double kilo;
}URUN;

void printTablo(URUN* urunler, int size){
	int i;
	for(i=0;i<size;i++){
		printf("kod: %d || ", urunler[i].kod);
		printf("name: %s || ", urunler[i].name);
		printf("birim fiyat: %.2lf || ", urunler[i].birim);
		printf("kilo fiyat: %.2lf\n\n" , urunler[i].kilo);
	}
}

int validKod(URUN* urunler, int size, int kod){
	int i;
	for(i=0;i<size;i++){
		if(urunler[i].kod == kod) return i;
	}
	return -1;
}

void total(URUN* urunler, int size, int kod, int tip, int miktar, double* toplam){
	int i=0;
	while(i<size && urunler[i].kod != kod) i++;
	if(tip == 1){
		*toplam += urunler[i].birim * miktar;	
	}
	else{
		*toplam += urunler[i].kilo * miktar;
	}
}

double indirim(double toplam){
	if(toplam >= 50 && toplam < 100) return (toplam * 95) / 100;
	if(toplam >= 100) return (toplam * 90) / 100;
	return toplam;
}

int main(){
	int i, kod, tip, miktar;
	char answer;
	double toplam = 0;
	
	URUN urunler[NUM_PRODUCTS] = {
        {1, "domates", 8.25, 23.75},
        {2, "biber", 6.25, 29.50},
        {3, "sut", 15.85, 27.15},
        {4, "peynir", 23.00, 95.50},
        {5, "muz", 13.45, 45.50},
        {6, "armut", 5.50, 20.15}
    };
	
	do{
		printTablo(urunler, 6);	
		do{
			printf("urun kodu gir: ");
			scanf("%d", &kod);
		} while(validKod(urunler, NUM_PRODUCTS, kod) == -1);
		
		do{
			printf("alis tipi gir (birim 1, kilo 2): ");
			scanf("%d", &tip);
		} while(tip != 1 && tip != 2);
		
		do{
			printf("miktar gir: ");
			scanf("%d", &miktar);
		} while(miktar <= 0);
		
		total(urunler, NUM_PRODUCTS, kod, tip, miktar, &toplam);
		printf("toplam tutar: %.2lf\n", toplam);
		printf("devam? (E/H): ");
		scanf("\n%c", &answer);
	} while(answer == 'e' || answer == 'E');
	
	printf("toplam tutar: %.2lf\n", toplam);
	printf("indirimli tutar: %.2lf\n", indirim(toplam));
	
	return 0;
}
