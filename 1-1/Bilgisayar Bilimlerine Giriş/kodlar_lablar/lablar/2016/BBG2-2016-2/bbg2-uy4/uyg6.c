#include <stdio.h>

int DizidenBykBul(int*, int);
int MutlakDegerAl(int tmp);

int main(){
	int i, dizi[10], n = 7, byk;
	printf("7 deger gireceksiniz...\n");
	for(i = 0; i < n; i++){
		printf("dizi[%d]: ", i+1);
		scanf("%d", &dizi[i]);
	}
	
	byk = DizidenBykBul(dizi, n);
	
	printf("En byk deger : %d\n", dizi[byk]);
	
	return 0;
}

int DizidenBykBul(int* dizi, int n){
	int i;
	int byk_i = 0;
	for(i = 1; i < n; i++)
		if(MutlakDegerAl(dizi[byk_i]) <  MutlakDegerAl(dizi[i]))
			byk_i = i;
	return byk_i;
}

int MutlakDegerAl(int sayi){
	if(sayi < 0)
		return sayi * -1;
	else
		return sayi;	
}
