//herkes 3 partiye oy verebilir
//toplamda en çok oyu alan kazanýr
//(N*3’lük bir matris)
#include <stdio.h>
int main()
{
	char oylar[10][3];
	static int p[10];
	int n,i,j,kazanan,partiSay=0,max=0;
	// n secmen sayisi 
	// 1,2,3,4 .. parti numaralari
	scanf ("%d",&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<3;j++)
		{
			scanf("%d",&oylar[i][j]);
			if (oylar[i][j]>partiSay)
				partiSay=oylar[i][j];
		}
	}
	partiSay++;
	for (i=0;i<n;i++)
	{
		for (j=0;j<3;j++)
			p[oylar[i][j]]++;
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
