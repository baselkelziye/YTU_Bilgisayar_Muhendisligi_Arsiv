#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, dizi[100], i, j, tmp;
	
	//Dizi kullanicidan okunuyor...
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("dizi[%d]: ", i);
		scanf("%d", &dizi[i]);
	}
	
	//Insertion sort islemi gerceklestiriliyor
	for(i = 1; i < n; i++){
		tmp = dizi[i];
		j = i - 1;
		while(j >= 0 && dizi[j] > tmp){
			dizi[j+1] = dizi[j];
			j = j - 1;
		}
		dizi[j+1] = tmp;
	}
	
	//Siralanan dizi ekrana yazdiriliyor.
	for(i = 0; i < n-1; i++)
		printf("%d, ", dizi[i]);
	printf("%d", dizi[n-1]);	
	system("PAUSE");
	return 0;
}
