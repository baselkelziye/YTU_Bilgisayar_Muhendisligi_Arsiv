// Sirali iki diziyi birlestiren program
#include <stdio.h>
int main()
{
	int dizi1[10],dizi2[10];
	int dizi3[20];
	int n,m,i,j,k;
	scanf ("%d %d",&n,&m);
	for (i=0;i<n;i++)
		scanf("%d",&dizi1[i]);
		
	for (i=0;i<m;i++)
		scanf("%d",&dizi2[i]);
		
	dizi1[n]=dizi2[m+1];
	dizi2[m]=dizi1[n+1];
	i=0;
	j=0;	
	for (k=0;k<m+n;k++)
	{
		if (dizi1[i]>dizi2[j])
		{
			dizi3[k]=dizi2[j];
			printf("%d ",dizi2[j]);
			j++;
		}
		else
		{
			dizi3[k]=dizi1[i];
			printf("%d ",dizi1[i]);
			i++;
		}
		
	}
	for (k=0;k<m+n;k++)
		printf("\n%d ",dizi3[k]);
	return 0;	
}
