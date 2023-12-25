#include <stdio.h>
// 6 basamaklý palendrom sayilari ekrana yazdýr
int main()
{
	int i,j,temp,n=6;
	int basamaklar[6];
	char basamak1, basamak2,basamak3;
	//7 basamakli palendrom sayilari bulan program 
	for (i=100;i<=999;i++)
	{
		temp=i;
		basamak1=temp%10;
		temp=temp/10;
		basamak2=temp%10;
		temp=temp/10;
		basamak3=temp%10;
		
		for (j=0;j<=9;j++)
		{
		printf("palendrom: %d%d%d%d%d\n",i,j,basamak1,basamak2,basamak3);
		}
	}
	return 0;
}
