#include<stdio.h>
#include<stdlib.h>
//Selection Sort (küçükten büyüðe sýralar)
void mySelection(int , int *);
void myPrint(int , int *);
int main(){
	
	int n,*dizi,i;
	printf("dizinin eleman sayisini giriniz.\n");
	scanf("%d",&n);
	dizi=(int*)malloc(n*sizeof(int));
	printf("dizinin elemanlarini giriniz\n");
	for(i=0;i<n;i++){
		scanf("%d",&dizi[i]);
	}
	
	myPrint(n,dizi);
	printf("\n");
	mySelection(n,dizi);
	myPrint(n,dizi);
	
	
	return 0;
}
void mySelection(int size, int *array){
	int i,j,min,temp;
	for(i=0;i<=size-2;i++){
		min=i;
		for(j=i+1;j<size;j++){
			if(array[j]<array[min]){
				min=j;
			}
		}
		temp=array[min];
		array[min]=array[i];
		array[i]=temp;
	}
}

void myPrint(int size, int *array){
	int i;
	for(i=0;i<size;i++){
		printf("%d	",array[i]);
	}
}
