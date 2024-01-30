#include <stdio.h>
#include <stdlib.h>

int EnBykBul(int*);
void BykElemanCikar(int*, int*, int);
int main(){
	
	int i, dizi[100], farkli[100];
	i = 0;
	printf("Son elemani -1 olacak bir pozitif tam sayi dizisi gireceksiniz...\n");
	do{
		printf("dizi[%d]: ", i);
		scanf("%d", &dizi[i]);
	}while(dizi[i++] >= 0);
	
	printf("\nGirilen dizi: \t");
	i = 0;
	while(dizi[i] >= 0)
		printf("%2d ", dizi[i++]);
		
	int enbyk = dizi[EnBykBul(dizi)];
	printf("\nDizinin en buyuk elemani: %d", enbyk);
	
	BykElemanCikar(dizi, farkli, enbyk);
	
	printf("\nFark dizisi: \t");
	i = 0;
	while(dizi[i] >= 0)
		printf("%2d ", farkli[i++]);
	printf("\n\n");
	system("PAUSE");
	return 0;
}

int EnBykBul(int* dizi){
	int enbyk = *dizi++;
	if(enbyk < 0)
		return 0;
	int idx = 0, en_idx = 0;
	while(*dizi >= 0){
		idx++;
		if(*dizi++ > enbyk){
			enbyk = *(dizi-1);
			en_idx = idx;
		}
	}
	return en_idx;
}

void BykElemanCikar(int* dizi, int* farkli, int byk){
	while(*dizi >= 0)
		*farkli++ = byk - *dizi++;
}
