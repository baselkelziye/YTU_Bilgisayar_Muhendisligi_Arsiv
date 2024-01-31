//herkesin oyu eþit sayilmazsa
//ödediði vergi, ödediði/ödemesi gereken vergi, yaþý vb. ile aðýrlýklandýrýlmýþ
//ilk sutun agirlik, ikincisi oy
//n seçmen sayisi
#include <stdio.h>
int main()
{
	int oylar[10][2];
	static int p[10];
	int n,i,kazanan,partiSay=0, max=0;
	// n secmen sayisi 
	// 1,2,3,4 .. parti numaralari
	scanf ("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&oylar[i][0],&oylar[i][1]);
		if (oylar[i][0]>partiSay)
			partiSay=oylar[i][0];
	}
	partiSay++;
	for (i=0;i<n;i++)
		p[oylar[i][0]]=p[oylar[i][0]]+oylar[i][1];
	
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
