// Verilen bir n sayisi icin, bu sayiya kadar olan sayilardan tek olanlari bir dizinin basina, 
// cift olanlari dizinin sonuna yerlestiren program
#include <stdio.h>
int main()
{
	int dizi[20];
	int j=0,i,n,k;
	scanf("%d",&n);
	// COZUM 1: 2N iterasyon
	for (i=0;i<n;i++)
		if (i%2==1)
		{
			dizi[j]=i;
			j++;
		}
		
	for (i=n-1;i>=0;i--)
		if (i%2==0)
		{
			dizi[j]=i;
			j++;
		}
		
	for (i=0;i<n;i++)
		printf("%d ",dizi[i]);
	
	printf("\n");
	// COZUM 2: N iterasyon
	j=0;
	k=n-1;
	for (i=0;i<n;i++)
		if (i%2==0)
		{
			dizi[k]=i;
			k--;
		}
		else
		{
			dizi[k]=i;
			j++;
		}
	
	for (i=0;i<n;i++)
		printf("%d ",dizi[i]);
	
	printf("\n");
	// COZUM 3: N/2 iterasyon
	j=n/2;
	k=n-1;
	for (i=0;i<j;i++)
	{
		dizi[k]=2*i;
		dizi[i]=2*i+1;
		k--;
	}
	
	for (i=0;i<n;i++)
		printf("%d ",dizi[i]);
	
	return 0;
}
