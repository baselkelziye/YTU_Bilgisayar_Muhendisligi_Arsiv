#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1000

int countPrimes(int *, int);
int *eratosthenes(int);
void printIndex(int *, int);
void printPrimes(int *, int);

int main(){
	
	int *era, counter, n;
	era = eratosthenes(N);
	n=1000;
	counter = countPrimes(era,n);
	printf("There are %d prime numbers until %d.\n\n", counter, n);	
	printIndex(era,n);
	printf("\n\n");
	printPrimes(era,n);
	free(era);
}

int *eratosthenes(int n)
{
	int i, j, x, *era;
	x = (int) sqrt(n);
	
	era = (int*)malloc(N*sizeof(int));
	
	for(i=0; i<n; i++) era[i]=1;
	
	for(i=2; i<=x; i++)
	{
		for(j=i; j<=n; j=j+i)
		{
			if(j!=i && era[j-1]==1) era[j-1]=0;
		}
	}
	era[0]=0;
	return era;
}

int countPrimes(int *arr, int n)
{
	int i, counter=0;
	for(i=0; i<n; i++)
	{
		if(arr[i]==1) counter++;
	}
	return counter;
}

void printIndex(int *arr, int n)
{
	int i;
	for(i=0; i<n; i++) printf("%d  ", arr[i]);
}

void printPrimes(int *arr, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(arr[i]==1) printf("%d  ", i+1);
	}
}
