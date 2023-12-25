#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, dizi[100], ara, say, i;
	
	//Dizi ve aranacak eleman kullanicidan okunuyor...
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Dizinin %d. elemanini giriniz: ", i+1);
		scanf("%d", &dizi[i]);
	}
	printf("Aranacak sayiyi giriniz: ");
	scanf("%d", &ara);
	
	//Eleman dizide araniyor
	say = 0;
	for(i = 0; i < n; i++)
		if(dizi[i] == ara)
			say++;
	
	//Aranan elemanin sayisi yazdiriliyor.
	printf("\n%d sayisi dizide %d kere gecmistir.\a", ara, say);	
	system("PAUSE");
	return 0;
}
