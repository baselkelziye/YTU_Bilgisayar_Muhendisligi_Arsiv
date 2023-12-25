// Seçim sistemleri
// En çok oyu alan partiyi bulmak (N seçmen sayýsý, N elemanlý bir dizi)
#include <stdio.h>
int main()
{
	char oylar[10];
	static int p[10];
	int n,i,kazanan,partiSay=0,max=0;
	// n secmen sayisi 
	// 1,2,3,4 .. parti numaralari
	scanf ("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&oylar[i]);
		if (oylar[i]>partiSay)
			partiSay=oylar[i];
	}
	partiSay++;
	for (i=0;i<n;i++)
		p[oylar[i]]++;
	
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
