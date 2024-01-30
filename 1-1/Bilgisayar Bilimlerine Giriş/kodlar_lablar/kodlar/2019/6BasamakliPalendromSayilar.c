#include <stdio.h>
// 6 basamaklý palendrom sayilari ekrana yazdýr
int main()
{
	int i,j,temp,n=6;
	int basamaklar[6];
	char basamak1, basamak2,basamak3;
	//6 basamakli palendrom sayilari bulan program 
	//COZUM 1 : 900000*(6+3) kez doner
	//6 basamaklý her i sayýsý icin
	for (i=100000;i<=999999;i++)
	{
	//o sayinin basamaklarýnin sayi degerlerini bir diziye at
	temp=i;
	j=5;
	while (temp>0)
	{
		basamaklar[j]=temp%10;
		temp=temp/10;
		j--;
	}
	
	//dizinin palendrom olup olmadigini kontrol et
	j=0;
	while ((j<n/2) && (basamaklar[j]==basamaklar[n-j-1]))
		j++;
	
	if (j>=n/2)
		printf("palendrom: %d\n",i);
	
	}
	//COZUM 2 : 900 kez doner
	for (i=100;i<=999;i++)
	{
		temp=i;
		basamak1=temp%10;
		temp=temp/10;
		basamak2=temp%10;
		temp=temp/10;
		basamak3=temp%10;
		printf("palendrom: %d%d%d%d\n",i,basamak1,basamak2,basamak3);
		
	}
	
	return 0;
}
