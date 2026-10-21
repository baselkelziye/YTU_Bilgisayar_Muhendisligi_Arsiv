#include<stdio.h>
#include<stdlib.h>
#define N 26

int main(){
	int i, j, *flavio;
	
	printf("     ");
	
	//en baþta 0'lardan oluþan N'lik bir dizi oluþturuyoruz.
	flavio = (int*)malloc(N*sizeof(int));
	for(i=0; i<N; i++)
	{
		flavio[i] = 1;
		printf("%d ", i+1);
		if(i<9) printf(" ");
	}
	printf("\n1    ");
	for(i=0; i<N; i++) printf("%d  ", flavio[i]);
	
	for(i=2; i<=N; i++)
	{
		printf("\n%d  ", i);
		if(i<10) printf(" ");
		
		for(j=0; j<N; j++)
		{
			if((j+1)%i == 0) // 0. indiste 1 var çünkü mesela
			{
				if(flavio[j] == 1)
				{
					flavio[j] = 0;
					printf(" 0 ");
				}
				else
				{
					flavio[j] = 1;
					printf(" 1 ");
				}
			}
			else printf("   ");
		}
	}
	free(flavio);
	return 0;
}
