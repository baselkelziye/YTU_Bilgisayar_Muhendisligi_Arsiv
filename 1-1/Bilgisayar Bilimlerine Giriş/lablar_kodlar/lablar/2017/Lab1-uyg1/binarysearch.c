#include <stdio.h> //printf ve scanf için
#include <stdbool.h> // bool deðiþken tanýmlayabilmek için
#include <stdlib.h> // system("PAUSE") ve system("CLS") kodlarýný kullanabilmek için

int main(void){
	//Bu uygulamada Selection Sort sýralama algoritmasý ve Binary Search arama algoritmasý kodlanmýþtýr.

	int n; //sýralanacak dizinin boyutu
	int dizi[50]; //sýralanacak dizi
	int i, j; // çevrim deðiþkenleri
	int min; // bulunan en küçük elemanýn indisini tutan geçici deðiþken
	int tmp; // ara deðiþken
	int ara; //binary search için aranacak eleman
	int ilk, son, orta; // binary search yaparken kullanýlacak dizi indisleri
   	bool bul; // binary search için bulundu durumunu tutan boolean deðiþken
	
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d", &n);
	
	// Dizi dýþarýdan okunuyor.
	for(i = 0; i < n; i++){
		printf("\n%d. elemani giriniz: ",(i+1));
		scanf("%d", &dizi[i]);
	}
	
	printf("\n-------------------------------------------------");
	// Dizi küçükten büyüðe doðru sýralanýyor.
 	for (i = 0; i < n-1; i++) {
  		// minimum eleman bulunuyor
  		min = i;
  		for (j = i+1; j < n; j++) {
   			if (dizi[j] < dizi[min]) {
    			min = j;
   			}
  		}
	  	//  dizi[i] ile dizi[min] içeriði deðiþtiriliyor 
	  	tmp = dizi[i];
	  	dizi[i] = dizi[min];
	  	dizi[min] = tmp;
 	}
 	//printf("%%100 tamamlandi\n");
 	printf("\nGirilen dizinin siralama islemi tamamlandi.\n");
	printf("-------------------------------------------------\n");
	
	while(1){ //Sürekli ardýþýl arama yapabilmek için sonsuz döngü oluþturulmuþtur.
		system("PAUSE");
		system("CLS");
		printf("Arama yapilacak siralanmis dizi: ");
		
		for(i = 0; i < n-1; i++)
			printf("%d, ",dizi[i]);
		printf("%d\n",dizi[n-1]);
		
		printf("\nDizide aranacak elemani giriniz (-1 ile cikilir): ");
		scanf("%d", &ara);
		
		if(ara == -1)
			return 0;
		
		// Bu aþamadan sonra BINARY SEARCH baþlýyor.
		
		ilk = 0;
	   	son = n - 1;
	   	orta = (ilk+son)/2;
	   	bul = false;
	 
	   	while((ilk <= son) && !bul){
	   		if(dizi[orta] == ara){
	   			bul = true;
	   		}else{
		      	if (dizi[orta] < ara )
		         	ilk = orta + 1;    
		      	else 
		         	son = orta - 1;
		 		orta = (ilk + son)/2;
	   		}
	   	}
	   	
	   	if(!bul)
	      	printf("\nBulunamadi! Aranan %d sayisi girilen dizide yoktur.\n\n", ara);
	    else
	 		printf("\nBulundu! Aranan %d sayisi sirali dizinin %d. indisinde bulundu.\n\n", ara, (orta+1));
	}

}
