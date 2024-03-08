#include <stdio.h>
int FindPrimeFactor (int, int *, int *);
void FindPrime(int , int *);
int* FindCommonFactor(int *,int ,int *,int , int *);

int FindPrimeFactor (int N, int *prime, int *factors)
{
	int next=0, x=0;
	while (N>1)
	{
		if (N%prime[next]==0)
		{
			factors[x]=prime[next];
			while ((N%prime[next])==0)
				N=N/prime[next];
			x++;
		}
		next++;
	}
	return x;
}

void FindPrime(int N, int *prime)
{
	int i,pp=3,diziboy=1,spr;
	prime[0]=2;
	
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
		pp=pp+2;
	}
}
int* FindCommonFactor(int factors1[],int N,int *factors2,int M, int *x)
{

	int i=0,j=0;   int common[100];
	*x=0;
	while (i<N && j<M)
	{
		if (factors1[i]==factors2[j])
		{
			common[*x]=factors1[i];
			(*x)=(*x)+1;  //  ++ nin onceligi daha yuksek (*)'a gore  
			i++;
			j++;
		}
		else
		if (factors1[i]<factors2[j])
			i++;
		else
			j++;
	}

	return common;

}

int main()
{
	int prime[100],i;
	int CommonFactorNum;
	int *common;
	int sayi1,sayi2,factorNum1,factorNum2;
	int factors1[50],factors2[50];
	printf("give the numbers\n");
	scanf("%d %d",&sayi1,&sayi2);
	if (sayi1>sayi2)
		FindPrime(sayi1,prime);
	else
		FindPrime(sayi2,prime);

	factorNum1=FindPrimeFactor(sayi1,prime,&factors1[0]);
	factorNum2=FindPrimeFactor(sayi2,prime,factors2);
	common=FindCommonFactor(factors1,factorNum1,factors2,factorNum2,&CommonFactorNum);
	printf("CommonFactorNum:%d\n",CommonFactorNum);
	for (i=0;i<CommonFactorNum;i++)
	{
		printf("commanFactors: %d\n",common[i]);
	}
	return 0;
}

