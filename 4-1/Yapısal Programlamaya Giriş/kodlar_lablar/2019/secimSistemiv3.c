//herkes her partiye 0-10 arasý oy verebilir
//toplamda en çok oyu alan kazanýr
//P parti sayýsý, N*P’lik bir matris
#include <stdio.h>
int main()
{
	char oylar[10][10];
	static int p[10];
	int n,i,j,kazanan,partiSay,max=0;
	// n secmen sayisi 
	// 1,2,3,4 .. parti numaralari
	scanf ("%d",&n);
	scanf ("%d",&partiSay);
	for (i=0;i<n;i++)
	{
		for (j=0;j<partiSay;j++)
			scanf("%d",&oylar[i][j]);
	}

	for (i=0;i<partiSay;i++)
	{
		for (j=0;j<n;j++)
			p[i]=p[i]+oylar[j][i];
	}
		
	
	for (i=0;i<partiSay;i++)
	{
		if (p[i]>max)
		{
			max=p[i];
			kazanan=i;
		}
	}
	
	printf("kazanan:%d oy:%d",kazanan,max);
	
	return 0;	
}
