#include<stdio.h>
#include<stdlib.h>

struct urun{
	int kod;
	char *isim;
	float birimFiyat;
	float kiloFiyat;
};

void urunListele(struct urun *urunler, int urunSayisi);
float tutarHesapla(struct urun *urunler, int urunKodu, int alisTipi ,int miktar);
float indirimliTutarHesapla(float toplamTutar);

int main(){
	int urunSayisi=6, urunKodu, alisTipi, miktar;
	char choice;
	float toplamFiyat=0, indirimliFiyat=0;
	struct urun *urunler;
	urunler = (struct urun*)malloc(urunSayisi*sizeof(struct urun));
	
	urunler[0].kod = 1;
	urunler[0].isim = "domates";
	urunler[0].birimFiyat = 8.25;
	urunler[0].kiloFiyat = 23.75;
	
	urunler[1].kod = 2;
	urunler[1].isim = "biber";
	urunler[1].birimFiyat = 6.25;
	urunler[1].kiloFiyat = 29.50;
	
	urunler[2].kod = 3;
	urunler[2].isim = "sut";
	urunler[2].birimFiyat = 15.85;
	urunler[2].kiloFiyat = 27.15;
	
	urunler[3].kod = 4;
	urunler[3].isim = "peynir";
	urunler[3].birimFiyat = 23.00;
	urunler[3].kiloFiyat = 95.50;
	
	urunler[4].kod = 5;
	urunler[4].isim = "muz";
	urunler[4].birimFiyat = 13.45;
	urunler[4].kiloFiyat = 45.50;
	
	urunler[5].kod = 6;
	urunler[5].isim = "armut";
	urunler[5].birimFiyat = 5.50;
	urunler[5].kiloFiyat = 20.15; 
	
	do{
		urunListele(urunler, urunSayisi);
		
		do{
			printf("\nUrun kodu giriniz: ");
			scanf("%d",&urunKodu);
			if(urunKodu<1 || urunKodu>6){
				printf("\nGirdiginiz kodda bir urun yok lutfen tekrar girin");
			}	
		}while(urunKodu<1 || urunKodu>6);
		
		
		do{
			printf("\nAlis tipi giriniz(Birim Fiyat ustunden 1, Kilo ustunden 2): ");
			scanf("%d",&alisTipi);
			if(alisTipi<1 || alisTipi>2){
				printf("\nGirdiginiz degerde bir alis tipi yok lutfen tekrar girin: ");
			}
		}while(alisTipi<1 || alisTipi>2);
		
		
		do{
			printf("\nAlicaginiz miktari girin: ");
			scanf("%d",&miktar);
			if(miktar<0){
				printf("\ngecerli bir deger girin: ");
			}
			
		}while(miktar<0);
		
		toplamFiyat+=tutarHesapla(urunler, urunKodu, alisTipi, miktar);
		printf("\nToplam Tutar: %.2f",toplamFiyat);
		
		printf("\n\nDevam etmek istiyor musunuz ? (E/H): ");
		scanf(" %c",&choice);
		
		if(choice=='H'){
			indirimliFiyat = indirimliTutarHesapla(toplamFiyat);
			printf("\nToplam Tutar: %.2f",toplamFiyat);
			printf("\nIndirimli Tutar: %.2f",indirimliFiyat);
			printf("\nProgramdan cikis yapiliyor");
		}
		
	}while(choice == 'E');
	
	
	
	return 0;
}



void urunListele(struct urun *urunler, int urunSayisi){
	int i;
	printf("Kod\tUrun Adi\tBirim Fiyat\tKilo Fiyat\n\n");
	for(i=0; i < urunSayisi; i++){
		printf("%d\t%s\t\t%.2f\t\t%.2f\n",urunler[i].kod, urunler[i].isim, urunler[i].birimFiyat, urunler[i].kiloFiyat);
	}
}

float tutarHesapla(struct urun *urunler, int urunKodu, int alisTipi ,int miktar){
	int i;
	float total = 0;
	if(alisTipi == 1){
		total+=urunler[urunKodu-1].birimFiyat*miktar;
	}else if(alisTipi == 2){
		total+=urunler[urunKodu-1].kiloFiyat*miktar;
	}
	return total;
}

float indirimliTutarHesapla(float toplamTutar){
	
	if(toplamTutar>=50 && toplamTutar<100){
		return toplamTutar -= toplamTutar*0.05;
	}else if(toplamTutar>100){
		return toplamTutar -= toplamTutar*0.1;
	}
	return toplamTutar;
}
