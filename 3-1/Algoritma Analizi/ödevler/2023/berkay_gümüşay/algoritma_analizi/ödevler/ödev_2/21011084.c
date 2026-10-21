#include <stdio.h>
#include <stdlib.h>

void matchKeysAndLocks(int** keys, int** lock, int low, int high);
int partition(int** arr, int low, int high, int pivotValue);
void swap(int* a, int* b);


int main() {
	
	// DEÐER TANIMLAMALARI VE DÝZÝNÝN KULLANICIDAN ALINMASI BAÞLANGIÇ
	int *key, *lock;
	int N,i;
	printf("Anahtar/Kilit Sayisini Giriniz (N): ");
	scanf("%d",&N);
	key = (int*)malloc(N* sizeof(int));
	lock  =(int*)malloc(N* sizeof(int));
	for(i=0;i<N;i++){
		printf("Anahtar Dizisi %d. Elemani : ",i+1);
		scanf("%d",&key[i]);
	}
	for(i=0;i<N;i++){
		printf("Kilit Dizisi %d. Elemani : ",i+1);
		scanf("%d",&lock[i]);
	}
	system("cls");
	// DEÐER TANIMLAMALARI VE DÝZÝNÝN KULLANICIDAN ALINMASI BÝTÝÞ
	
	// KULLANICIDAN ALINAN DÝZÝNÝN EKRANA YAZDIRILMASI BAÞLANGIÇ
	printf("\n\n\tKeys And Locks Lists :\n\n");
	printf("\tKey : ");
	for(i=0;i<N;i++){
		printf("%d ",key[i]);
	}
	printf("\n\tLock: ");
	for(i=0;i<N;i++){
		printf("%d ",lock[i]);
	}
	printf("\n\n------------------------------------------------\n\n\tKey-Lock Match !! \n\n");
	// KULLANICIDAN ALINAN DÝZÝNÝN EKRANA YAZDIRILMASI BÝTÝÞ
	
	// PROBLEMI COZEN FONKSÝYON
	matchKeysAndLocks(&key,&lock,0,N-1);

	// EÞLEÞMÝÞ ANAHTAR-KÝLÝT ÝKÝLÝLERÝNÝ EKRANA YAZDIRMA
	printf("\n\n");
	printf("\tKey : ");
	for(i=0;i<N;i++){
		printf("%d ",key[i]);
	}
	printf("\n\tLock: ");
	for(i=0;i<N;i++){
		printf("%d ",lock[i]);
	}
	printf("\n\n");
	free(key);free(lock);
	
	return 0;
}


void matchKeysAndLocks(int** keys, int** locks, int low, int high){
	int pivotValue;
	if(low <high){
		
		// ANAHTAR DÝZÝSÝNÝ KÝLÝT DÝZÝSÝNDEN ALINAN PÝVOTA GÖRE SIRALAMA
		pivotValue = partition(keys,low,high,(*locks)[high]);
		// KÝLÝT DÝZÝSÝNÝ ANAHTAR DÝZÝSÝNDEN ALINAN PÝVOTA GÖRE SIRALAMA
		partition(locks,low,high,(*keys)[pivotValue]);
		
		//RECURSÝVE OLARAK BU FONKSÝYONU DÖNDÜRME
		matchKeysAndLocks(locks,keys,low,pivotValue-1);
		matchKeysAndLocks(locks,keys,pivotValue+1,high);
	}
}

int partition(int** array, int low, int high, int pivotValue){
	int i = low, j = high;int k;	
	int *arr = *array;
	// i DÝZÝNÝN SOLUNDAN j ÝSE DÝZÝNÝN SAÐINDAN BAÞLAYARAK ORTAYA DOÐRU ÝLERLENÝR
	while(i<=j){
		// j ÝNDÝSÝ SOLA DOÐRUN ÝLERLETÝLÝR
		while(j>=0 && arr[j]>= pivotValue){
			// j PÝVOTA EÞÝTSE DÝZÝNÝN EN SAÐINDAKÝ ELEMAN ÝLE SWAP ÝÞLEMÝ YAPILIR
			if(arr[j] == pivotValue){
				swap(&arr[j],&arr[high]);
			}
			j--;
		}
		// i ÝNDÝSÝ SAÐA DOÐRU ÝLERLETÝLÝR
		while(arr[i]<pivotValue){
			i++;
		}
		swap(&arr[i],&arr[j]);		
	}
	swap(&arr[i],&arr[j]);
	swap(&arr[i],&arr[high]);

	return(i);
}

void swap(int* a, int* b){
	int t= *a;
	*a = *b;
	*b = t;
}
