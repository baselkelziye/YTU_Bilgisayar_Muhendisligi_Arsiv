/*
	Kucukten buyuge dogru sirali bir diziye, dizinin sirasini bozmayacak sekilde, verilen bir elemani ekleme
	
	Girilen dizi		: 1 3 5 7 9
	Eklenecek sayi		: 4
	
	Dizinin son hali 	: 1 3 4 5 7 9
*/

#include <stdio.h>

int main(){

	int i, j, n, sayi;
	int dizi[50];

	printf("Dizinin boyutunu veriniz: ");
	scanf("%d", &n);

	printf("Diziyi veriniz:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &dizi[i]);
	}

	printf("Diziye eklenecek sayiyi veriniz: ");
	scanf("%d", &sayi);

	i = 0;
	while ((i < n) && (sayi > dizi[i])){
		i++;
	}

	for(j = n - 1; j >= i; j--){
		dizi[j + 1] = dizi[j];
	}
	dizi[i] = sayi;

	printf("Dizinin son hali: ");
	for(i = 0; i <= n; i++){
		printf("%d ", dizi[i]);
	}

	return 0;
}