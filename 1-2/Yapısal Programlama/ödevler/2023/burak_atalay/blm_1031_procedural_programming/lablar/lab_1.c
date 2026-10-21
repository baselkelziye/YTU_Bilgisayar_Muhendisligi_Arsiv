#include <stdio.h>
#define MAX 50

void insertionSort(int*, int);
void notlariAl(int*, int);
void enYuksekYazdir(int*, int);
void enDusukYazdir(int*, int);
void enYuksekEnDusukYazdir(int);
int main(){
	int n, i;
	int arr[MAX];
	
	do{
		printf("n: ");
		scanf("%d", &n);
	} while(n < 6);
	
	notlariAl(arr, n);
	insertionSort(arr, n);
	enYuksekYazdir(arr, n);
	enDusukYazdir(arr, n);
	
	return 0;
}

void insertionSort(int* arr, int n){
	int i, j;
	int temp;
	
	for(i=1;i<n;i++){
		j=i-1;
		temp=arr[i];
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

void notlariAl(int* arr, int n){
	int i;
	
	printf("\nnotlar...\n");
	
	for(i=0;i<n;i++){
		printf("%d. not: ", i+1);
		scanf("%d", &arr[i]);
	}
}

void enYuksekYazdir(int* arr, int n){
	printf("\nen buyuk 3 elemanin toplami: %d\n", arr[n-1] + arr[n-2] + arr[n-3]);
	printf("\nen buyuk 3 eleman: %d %d %d\n", arr[n-1], arr[n-2], arr[n-3]);
}

void enDusukYazdir(int* arr, int n){
	printf("\nen kucuk 3 elemanin toplami: %d\n", arr[0] + arr[1] + arr[2]);
	printf("\nen kucuk 3 eleman: %d %d %d\n", arr[0], arr[1], arr[2]);
}

void enYuksekEnDusukYazdir(int n){
	printf("\n%d. not: ", 1);
	scanf("%d", &x);
	max1 = max2 = max3 = min1 = min2 = min3 = x;
	for(i=1;i<n;i++){
		printf("\n%d. not: ", i+1);
		scanf("%d", &x);
		if(x > max1){
			max3 = max2;
			max2 = max1;
			max1 = x;
		}
		else if(x <= max1 && x > max2){
			max3 = max2;
			max2 = x;
		}
		else if(x <= max2 && x > max3){
			max3 = x;
		}
		
		if(min1 > x){
			min3 = min2;
			min2 = min1;
			min1 = x;
		}
		else if(min1 <= x && min2 > x){
			min3 = min2;
			min2 = x;
		}
		else if(min2 <= x && min3 > x){
			min3 = x;
		}
	}
	
	printf("\nen buyuk 3 elemanin toplami: %d\n", max1 + max2 + max3);
	printf("\nen buyuk 3 eleman: %d %d %d\n", max1, max2, max3);
	
	printf("\nen kucuk 3 elemanin toplami: %d\n", min1 + min2 + min3);
	printf("\nen kucuk 3 eleman: %d %d %d\n", min1, min2, min3);
}
