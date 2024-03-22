#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>


int BASKIN_KARAKTER(int[], int);
void TUM_METIN(char[], int[], int,int);
int main()
{	
	int n,i,byk;
	printf("Harf Sayisini girin:");
    scanf("%d",&n);
	char harf[]={'a','b','c','d','e'};
	//char harf[n];
	int frekans[n];
	srand(time(NULL));

	//random frekans dizisi oluþturulur.
	for (i=0;i<n;i++)
	{
		frekans[i] = (rand() % 10) + 1;
		printf("%d\n",frekans[i]);
	}
	
	//fonksiyondan dönen baskýn karakterin indisine göre baskýn karakter yazdýrýlýr
	byk=BASKIN_KARAKTER(frekans, n);
	printf("en baskin karakter=%c\n",harf[byk]);
	
	int toplam=0;
	for (i=0;i<n;i++)
	{
		toplam=toplam+frekans[i];		
	}
	printf("Tum metnin boyutu=%d\n",toplam);
	
	float ort=toplam/n;
	printf("Ortalama karakter sayýsý=%f\n",ort);
	
	printf("Ortalamadan fazla tekrar eden karakterler: ");
	for (i=0;i<n;i++)
	{
		if (frekans[i]>=ort)
		{
			printf("%c-",harf[i]);
		}		
	}
	printf("\n");
	
	TUM_METIN(harf, frekans, toplam,n);
	
}

int BASKIN_KARAKTER(int Fr[], int boyut)
{
   int i,byk=Fr[0],bykIndis=0;
   for (i=1;i<boyut;i++)
   {
   		if (Fr[i]>byk)
   		{
   			byk=Fr[i];
   			bykIndis=i;
   		}
   }
   return bykIndis;  
}

void TUM_METIN(char Hr[], int Fr[], int toplam,int n)
{
	int i,sayac=0,j,ind=0;
	char metin[toplam];
	for (i=0;i<n;i++)
	{
		sayac=Fr[i];
		for (j=0;j<sayac;j++)
		{
			metin[ind]=Hr[i];
			printf("%c-",metin[ind]);
			ind=ind+1;
		}
	}
}

