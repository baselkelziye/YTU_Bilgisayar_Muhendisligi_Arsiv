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
		//K���k metin kendini tekrar ediyorsa, bulunamay�nca en ba�tan arama yapmas�n diye, hangi harfte kendini nereye kadar tekrar etmi�, bunu bulup bir diziye yazd�r�yoruz.
		{
			len++;
			tekrar[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			//Burada len'i bir �nceki de�erine e�itliyoruz, ��nk� kendini tekrar etmiyor. i art�r�lm�yor, ��nk� kucukMetin[i], kucukMetin[len-1] ile e�it olabilir.
			{
	
				len = tekrar[len - 1];
			}
			else
			//len 0'a e�itse bir tekrar olmam��t�r ve bu harfte bir uyu�mazl�k olursa k���k metini en ba�tan aratmak gerekir.
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
		//E�itliklere bak�yoruz ve e�itlik varsa i ve j'yi art�r�yoruz.
		{
			j++;
			i++;
		}
		if(j == t)
		// j yeterince artarsa yazd�r�yoruz ve j'yi tekrar dizisininin j-1. eleman�na e�itliyoruz, kendini tekrar eden bir diziyse en ba�tan ba�lamamak i�in
		{
			printf("Buyuk metinde %d'den %d'ye kucuk metin bulundu.\n",i - j+1,i-j+t);
			j = tekrar[j-1];
		}
		else if(kucukMetin[j] != buyukMetin[i])
		{
			//e�er k���k metin kendini tekrar ediyorsa en ba�tan ba�lamamak i�in j'yi dizinin j-1. eleman�na e�itliyoruz i'yi art�rm�yoruz ��nk�, kucukMetin[tekrar[j-1]]'e e�itlik s�z konusu olabilir.
			if(j != 0)
				j = tekrar[j-1];
			else
			//art�k j==0'sa ve elemanlar dad e�it de�ilse, b�y�kMetinin sonraki eleman�na bakman�n zaman� gelmi�tir.
				i++;
		}
	}
}


























