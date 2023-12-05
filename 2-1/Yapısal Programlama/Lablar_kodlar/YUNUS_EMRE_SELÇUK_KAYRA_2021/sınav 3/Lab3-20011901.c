#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ARAC{
char model[20];
int yil;
int fiyat;
int adet;	
}arac;
void swap(arac *a, arac *b);
void selectionSort(arac array[], int size, int (*compare)(char a[], char b[]));
int kucuktenbuyuge(char a[],char b[]);
int buyuktenkucuge(char a[],char b[]);
arac * elemanekle(arac * eleman,int k);
int main(){
	arac * araclar;
	int i,j,k=3,pause=1,order;
	araclar=(arac *)malloc(3*sizeof(arac));
	if(araclar==NULL)
	printf("Bellek ayrilamadi");
	else{
	strcpy(araclar[0].model,"Accent");
	araclar[0].yil=1999;
	araclar[0].fiyat=125;
	araclar[0].adet=15;
	strcpy(araclar[1].model,"PRimera");
	araclar[1].yil=1999;
	araclar[1].fiyat=10;
	araclar[1].adet=1;
	strcpy(araclar[2].model,"Lambo");
	araclar[2].yil=1989;
	araclar[2].fiyat=5;
	araclar[2].adet=1;
	while(pause){
		printf("Eleman eklemek icin 1 e basiniz \n eklememek icin 0 tusuna basiniz \n");
		scanf("%d",&pause);
		if(pause==1){
			k++;
			araclar=elemanekle(araclar,k);

		}
		
	}
	printf("Buyukten kucuge siralamak icin1 e basiniz \nKucukten buyuge siralamak icin 2 ye basiniz\n ");
	scanf("%d",&order);
	for(i=0;i<k;i++){
	if(order== 1)
	{
		selectionSort(araclar, k, kucuktenbuyuge);
	}
	else{
		selectionSort(araclar, k, buyuktenkucuge);
	}
	}
	for(i=0;i<k;i++){
		printf("Aracin modeli= %s Adeti =%d Adeti = %d Fiyati = %d\n",araclar[i].model,araclar[i].adet,araclar[i].yil,araclar[i].fiyat);
	}
	
	
	}
	return 0;
}
void swap(arac *a, arac *b)
{
	arac tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(arac array[], int size, int (*compare)(char a[], char b[]))
{
	int i, j, smallestOrLargest;
	char d1[20], d2[20];
	for(i=0; i < size-1; i++)
	{
		smallestOrLargest = i;
		for(j=i+1; j < size; j++)
		{
			strcpy(d1,array[smallestOrLargest].model);
			strcpy(d2,array[j].model);
			
			if(compare(d1, d2)>0)
				smallestOrLargest = j;
		}
		swap(&array[smallestOrLargest], &array[i]);
	}
}
arac * elemanekle(arac * eleman,int k){
	int i,j,l;
	arac * a;
	char b[20];
	a=(arac*)realloc(eleman,k*sizeof(arac));
	if(a==NULL)
	printf("Bellek ayrilamadi\n");
	else{
			eleman=a;
		
			printf("Arabanin modelini giriniz : ");
			scanf("%s",eleman[k-1].model);
			printf("Aracin fiyatini giriniz : ");
			scanf("%d",&eleman[k-1].fiyat);
			printf("Aracin adetini giriniz : ");
			scanf("%d",&eleman[k-1].adet);
			printf("Aracin yilini giriniz : ");
			scanf("%d",&eleman[k-1].yil);
	}
	return a;
}
int kucuktenbuyuge(char a[],char b[])
{
	return(strcmp(b,a));
}
int buyuktenkucuge(char a[],char b[]){
	return(strcmp(a,b));
}
