#include<stdio.h>
#include<stdlib.h>
#define N 26

int main(){
	int i, j, *flavio;
		
	//baþta 0'lardan oluþan N'lik bir dizi oluþturuyoruz.
	flavio = (int*)malloc(N*sizeof(int));
	
	for(i=0; i<N; i++) flavio[i] = 1;

	for(i=2; i<=N; i++)
	{		
		for(j=i-1; j<N; j=j+i)
		{
			if(flavio[j] == 1)
			{
				flavio[j] = 0;
			}
			else
			{
				flavio[j] = 1;
			}
		}
	}
	for(i=0; i<N; i++)
	{
		printf("%d ", i+1);
		if(i<9) printf(" ");
	}
	printf("\n");
	for(i=0; i<N; i++) printf("%d  ", flavio[i]);
	free(flavio);
	
	return 0;
}
