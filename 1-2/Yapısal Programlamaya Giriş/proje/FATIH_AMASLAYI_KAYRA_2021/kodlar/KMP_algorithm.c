#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
void tekrarhesap(char *kucukMetin, int t, int *tekrar);
void KMP(char *kucukMetin, char *buyukMetin);

int main()
{
	char buyukMetin[SIZE*10];
	char kucukMetin[SIZE];
	printf("Lutfen metini bosluksuz giriniz\n");
	scanf("%s",buyukMetin);
	printf("Lutfen aranan kucuk metini giriniz\nkucuk metin :");
	scanf("%s",kucukMetin);
	if(strlen(kucukMetin)<=strlen(buyukMetin))
	KMP(kucukMetin, buyukMetin);
	else
	printf("Aranan kucuk metin, normal metinden buyuk oldugu icin kucuk metin bulunamadi.");
	return 0;
}
void tekrarhesap(char *kucukMetin, int t, int *tekrar)
{
	int len = 0;
	int i ;
	
	tekrar[0] = 0 ;
	i = 1;

	while(i <  t)
	{
		if(kucukMetin[i] == kucukMetin[len])
		//Küçük metin kendini tekrar ediyorsa, bulunamayýnca en baþtan arama yapmasýn diye, hangi harfte kendini nereye kadar tekrar etmiþ, bunu bulup bir diziye yazdýrýyoruz.
		{
			len++;
			tekrar[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			//Burada len'i bir önceki deðerine eþitliyoruz, çünkü kendini tekrar etmiyor. i artýrýlmýyor, çünkü kucukMetin[i], kucukMetin[len-1] ile eþit olabilir.
			{
	
				len = tekrar[len - 1];
			}
			else
			//len 0'a eþitse bir tekrar olmamýþtýr ve bu harfte bir uyuþmazlýk olursa küçük metini en baþtan aratmak gerekir.
			{
				tekrar[i] = 0;
				i++;
			}
		}
	}
}
void KMP(char *kucukMetin, char *buyukMetin)
{
	int t = strlen(kucukMetin);
	int q = strlen(buyukMetin);

	int tekrar[100];
	int j = 0;

	tekrarhesap(kucukMetin, t, tekrar);
	
	int i = 0;
	while(i < q)
	{
		if(kucukMetin[j] == buyukMetin[i])
		//Eþitliklere bakýyoruz ve eþitlik varsa i ve j'yi artýrýyoruz.
		{
			j++;
			i++;
		}
		if(j == t)
		// j yeterince artarsa yazdýrýyoruz ve j'yi tekrar dizisininin j-1. elemanýna eþitliyoruz, kendini tekrar eden bir diziyse en baþtan baþlamamak için
		{
			printf("Buyuk metinde %d'den %d'ye kucuk metin bulundu.\n",i - j+1,i-j+t);
			j = tekrar[j-1];
		}
		else if(kucukMetin[j] != buyukMetin[i])
		{
			//eðer küçük metin kendini tekrar ediyorsa en baþtan baþlamamak için j'yi dizinin j-1. elemanýna eþitliyoruz i'yi artýrmýyoruz çünkü, kucukMetin[tekrar[j-1]]'e eþitlik söz konusu olabilir.
			if(j != 0)
				j = tekrar[j-1];
			else
			//artýk j==0'sa ve elemanlar dad eþit deðilse, büyükMetinin sonraki elemanýna bakmanýn zamaný gelmiþtir.
				i++;
		}
	}
}


























