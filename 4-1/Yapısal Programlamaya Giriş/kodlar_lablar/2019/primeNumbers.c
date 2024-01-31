// Her adýmda olusturulan asal sayi dizisi kontrol edilir 
#include <stdio.h>
#include <math.h>
int main()
{
	int i,N,pp=3,diziboy=1,spr;
	int prime[1000];
	prime[0]=2;
	printf("N?\n");
	scanf("%d",&N);
	while (pp<=N)
	{
		i=0;
		while ((i<diziboy) && (pp%prime[i]!=0))
			i++;
		if (i>=diziboy)	
		{
			prime[i]=pp;
			diziboy++;
		}
		pp=pp+2; //pp=pp+1; //		cift sayilara bakmayalim
	}
	
	for (i=0;i<diziboy;i++)
		printf("%d ",prime[i]);
	return 0;	
}
