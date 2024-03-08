#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int RastgeleFib(int*, int);
int fibonacci(int);
bool Search(int*, int, int);
void EkranaYazdir(int*, int);
int MedianBul(int*, int);
void InsertionSort(int*, int*, int);

const int fibsize = 20;
int bir = 1;

int main(){
	srand(time(NULL));
	int i, fsize, fib[fibsize], med;
	printf("Fibonacci dizisinin boyutunu giriniz (<%d): ", fibsize);
	scanf("%d", &fsize);
	
	i = 0;
	for(i = 0; i < fsize; i++)
		fib[i] = RastgeleFib(fib, i);
		
	EkranaYazdir(fib, fsize);
	med =  MedianBul(fib, fsize);
	
	printf("Median degeri: %d\n\n", med);
	
	system("PAUSE");
	return 0;
}

int RastgeleFib(int* fib, int i_son){
	int rfib, f;
	do{
		rfib = (rand() % fibsize) + 1;
		f = fibonacci(rfib);
	}while(Search(fib, i_son, f));
	return f;	
}

int fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);	
}

bool Search(int* dizi, int n, int ara){
	int i = 0;
	bool ret = false;
	while(i < n && !ret)
		if(dizi[i++] == ara && bir != ara)
			ret = true;
	return ret;
}

void EkranaYazdir(int* dizi, int n){
	system("CLS");
	int i;
	printf("%d adet rastgele Fibonacci sayisi asagidaki gibi secildi...\n\n", n);
	
	for(i = 0; i < n; i++)
		printf("%d  ", dizi[i]);
	printf("\n\n");
}

int MedianBul(int* fib, int fsize){
	int yer, copy_fib[fibsize];
	InsertionSort(fib, copy_fib, fsize);
	yer = fsize/2;
	return copy_fib[yer];
}

void InsertionSort(int* dizi, int* copy_fib, int n){
	int i, j, tmp;
	for(i = 0; i < n; i++)
		copy_fib[i] = dizi[i];
	for(i = 1; i < n; i++){
		tmp = copy_fib[i];
		j = i - 1;
		while(j >= 0 && copy_fib[j] > tmp){
			copy_fib[j+1] = copy_fib[j];
			j = j - 1;
		}
		copy_fib[j+1] = tmp;
	}
}
