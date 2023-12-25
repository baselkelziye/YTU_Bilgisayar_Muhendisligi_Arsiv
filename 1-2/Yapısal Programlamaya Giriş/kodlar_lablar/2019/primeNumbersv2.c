// N 'e kadar olan asal sayilari bulan program
// N'nin karekokune kadar ilerlemek yeterli
#include <stdio.h>
#include <math.h>
int main()
{
	int i,N,pp=3,diziboy=1,sqr;
	int prime[1000];
	prime[0]=2;
	
	printf("N?\n");
	scanf("%d",&N);
	
	while (pp<=N)
	{
		i=0;
		sqr=sqrt(pp);
		while ((prime[i]<=sqr) && (pp%prime[i]!=0))
			i++;
			
		if (prime[i]>sqr)	
		{
			prime[diziboy]=pp;
			diziboy++;
		}
		pp=pp+2; //pp=pp+1; 
	}
	
	for (i=0;i<diziboy;i++)
		printf("%d ",prime[i]);
	return 0;	
}
