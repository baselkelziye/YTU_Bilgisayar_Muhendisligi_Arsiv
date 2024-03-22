#include <stdio.h> //printf ve scanf i�in
#include <stdbool.h> // bool de�i�ken tan�mlayabilmek i�in
#include <stdlib.h> // system("PAUSE") ve system("CLS") kodlar�n� kullanabilmek i�in

int main(void){
	//Bu uygulamada Selection Sort s�ralama algoritmas� ve Binary Search arama algoritmas� kodlanm��t�r.

	int n; //s�ralanacak dizinin boyutu
	int dizi[50]; //s�ralanacak dizi
	int i, j; // �evrim de�i�kenleri
	int min; // bulunan en k���k eleman�n indisini tutan ge�ici de�i�ken
	int tmp; // ara de�i�ken
	int ara; //binary search i�in aranacak eleman
	int ilk, son, orta; // binary search yaparken kullan�lacak dizi indisleri
   	bool bul; // binary search i�in bulundu durumunu tutan boolean de�i�ken
	
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d", &n);
	
	// Dizi d��ar�dan okunuyor.
	for(i = 0; i < n; i++){
		printf("\n%d. elemani giriniz: ",(i+1));
		scanf("%d", &dizi[i]);
	}
	
	printf("\n-------------------------------------------------");
	// Dizi k���kten b�y��e do�ru s�ralan�yor.
 	for (i = 0; i < n-1; i++) {
  		// minimum eleman bulunuyor
  		min = i;
  		for (j = i+1; j < n; j++) {
   			if (dizi[j] < dizi[min]) {
    			min = j;
   			}
  		}
	  	//  dizi[i] ile dizi[min] i�eri�i de�i�tiriliyor 
	  	tmp = dizi[i];
	  	dizi[i] = dizi[min];
	  	dizi[min] = tmp;
 	}
 	//printf("%%100 tamamlandi\n");
 	printf("\nGirilen dizinin siralama islemi tamamlandi.\n");
	printf("-------------------------------------------------\n");
	
	while(1){ //S�rekli ard���l arama yapabilmek i�in sonsuz d�ng� olu�turulmu�tur.
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
		
		// Bu a�amadan sonra BINARY SEARCH ba�l�yor.
		
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
