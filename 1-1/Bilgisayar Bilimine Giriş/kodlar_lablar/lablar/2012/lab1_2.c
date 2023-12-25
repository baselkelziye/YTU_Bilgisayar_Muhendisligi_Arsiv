/*
	Cift sayida bir boyuta sahip dizinin elemanlarini ikiser ikiser toplayarak, 
	sayilar ve arkasinda toplamlari gelecek sekilde yeni bir dizi olusturma
	
	Girilen dizi		: 1 3 5 7 9 4

	Olusan yeni dizi	: 1 3 4 5 7 12 9 4 13
*/

#include <stdio.h>

int main(){

	int i, j, n;
	int dizi1[50], dizi2[50];

	do{
		printf("Cift sayida bir dizi boyutunu veriniz: ");
		scanf("%d", &n);
	} while(n % 2 == 1);

	printf("Diziyi veriniz:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &dizi1[i]);
	}

	j = 0;
	for (i = 0; i < n; i += 2){
		dizi2[j]	 = dizi1[i];
		dizi2[j + 1] = dizi1[i + 1];
		dizi2[j + 2] = dizi1[i] + dizi1[i + 1];
		j += 3;
	}

	printf("Olusan yeni dizi: ");
	for (i = 0; i < (n + n / 2); i++){
		printf("%d ", dizi2[i]);
	}

	return 0;
}