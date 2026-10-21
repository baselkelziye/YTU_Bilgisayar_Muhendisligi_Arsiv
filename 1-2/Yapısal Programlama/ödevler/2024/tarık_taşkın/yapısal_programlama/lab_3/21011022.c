#include <stdio.h>

typedef struct {
	int kod;
	char ad[20];	
	double birimSatis;
	double kiloSatis;
}Urun;

void urunListele(Urun liste[], int N);
double tutarHesapla(Urun liste[], int N, int urunKodu, int alisTipi, int miktar);
double indirimliFiyatHesapla(double tutar);

int main(){
	int N = 6; // urun sayisi
	Urun liste[N];
	liste[0] = (Urun) {1, "domates", 8.25, 23.75};
	liste[1] = (Urun) {2, "biber", 6.25, 29.50};
	liste[2] = (Urun) {3, "sut", 15.85, 27.15};
	liste[3] = (Urun) {4, "peynir", 23.00, 95.50};
	liste[4] = (Urun) {5, "muz", 13.45, 45.50};
	liste[5] = (Urun) {6, "armut", 5.50, 20.15};
	char devam;
	int urunKodu;
	int alisTipi;
	int miktar;
	double tutar=0;
	double indirimliTutar;
	
	do{
		urunListele(liste,N);
		printf("Urun kodu giriniz: ");
		scanf("%d",&urunKodu);
		if(urunKodu<7 && urunKodu>0){
			printf("Alis tipi (1: Birim, 2: Kilo): ");
			scanf("%d",&alisTipi);
			if(alisTipi==1 || alisTipi==2){
				printf("Miktar giriniz: ");
				scanf("%d",&miktar);
				tutar += tutarHesapla(liste,N,urunKodu,alisTipi,miktar);
				printf("Toplam tutar: %.2f\n",tutar);				
				printf("Devam etmek istiyor musunuz? (E/H): ");
				scanf(" %c", &devam);	
			}else{
				devam = 'E';
				printf("Hatali alis tipi girdiniz.\n");
			}			
		}else{
			devam = 'E';
			printf("Hatali urun kodu girdiniz.\n");
		}
	}while(devam == 'E' || devam == 'e');
	printf("Toplam tutar: %.2f TL\n",tutar);
	printf("Indirimli tutar: %.2f TL\n",indirimliFiyatHesapla(tutar));
	printf("Programdan cikiliyor...");
	return 0;
}

void urunListele(Urun liste[], int N){
	int i;
	
	printf("\n%-5s %-15s %-15s %-15s \n","Kod", "Urun Adi", "Birim Fiyat", "Kilo Fiyat");
	for(i=0;i<N;i++){
		printf("%-5d %-15s %-15.2f %-15.2f \n",liste[i].kod,liste[i].ad,liste[i].birimSatis,liste[i].kiloSatis);
	}
}

double tutarHesapla(Urun liste[], int N, int urunKodu, int alisTipi, int miktar){
	double tutar;
	
	int i=0;
	while(i<N && liste[i].kod != urunKodu){
		i++;
	}
	if(alisTipi == 1){
		tutar = miktar * liste[i].birimSatis;
	}else{
		tutar = miktar * liste[i].kiloSatis;
	}
	
	return tutar;
}

double indirimliFiyatHesapla(double tutar){
	double indirimliTutar;
	if(tutar<50){ //50den kucukse indirim yok
		indirimliTutar = tutar;
	}else if(tutar<100){
		indirimliTutar = 0.95*tutar; //50-100 arasindaysa %5 indirim var, bu yuzden fiyat %100-5=%95 yani 0.95 ile carpilir
	}else if(tutar>100){
		indirimliTutar = 0.9*tutar; //100'den fazlaysa %10 indirim var, bu yuzden fiyat %100-10=%90 yani 0.90 ile carpilir
	}
	
	return indirimliTutar;	
}
