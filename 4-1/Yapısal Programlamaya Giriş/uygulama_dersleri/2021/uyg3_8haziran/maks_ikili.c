#include <stdio.h>
#include <time.h> 

void mostFrequent(int D[], int N,int *max_i,int *max){
	int i,j;
	int freq[100]={0};// her ikilinin frekansýný tutan bir frekans dizisi
	
	for(i=0;i<N-1;i++){
		freq[10*D[i]+D[i+1]]++;
	}	
	printf("\n");
	for(i=0;i<100;i++){
		if(freq[i]>*max){
			*max=freq[i];
			*max_i=i;
		}	
		printf("%d ",freq[i]);	
	}
	printf("\n");
}

int main()
{
	int N,i;
	int D[500];
	srand ( time(NULL) );
	printf("Dizinin eleman sayisi:\n");
	scanf ("%d",&N);
	
	for (i=0;i<N;i++)// diziyi uretelim
	{
		D[i]=rand()%10;
		printf("%d ",D[i]); // yazdiralim
	}
	printf("\n");	
	int max_fre_sayi=0;
	int max_fre=0;
	mostFrequent(D,N,&max_fre_sayi,&max_fre);
	
	printf("\nArka arkaya en cok gecen %d sayi ikilisidir %d kez gecmistir",max_fre_sayi,max_fre);
		
}
