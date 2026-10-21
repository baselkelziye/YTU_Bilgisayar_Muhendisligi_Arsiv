#include<stdio.h>
#include<stdlib.h>
//insertion sort (küçükten büyüðe sýralar)
void selectionSort(int , int *);
void myPrint(int , int *);
int main(){
	
	int *dizi,n,i;
	printf("dizinin boyutunu giriniz.\n");
	scanf("%d",&n);
	dizi=(int*)malloc(n*sizeof(int));
	printf("dizinin elemanlarini giriniz.\n");
	for(i=0;i<n;i++){
		scanf("%d",&dizi[i]);
	}
	
	myPrint(n,dizi);
	printf("\n");
	selectionSort(n,dizi);
	myPrint(n,dizi);
	return 0;
}

void selectionSort(int size, int *array){
	int i,j,key;
	for(i=0;i<size;i++){
		key=array[i];
		j=i-1;
		while(array[j]>key&&j!=-1){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
}

void myPrint(int size, int *array){
	int i;
	for(i=0;i<size;i++){
		printf("%d	",array[i]);
	}
}
