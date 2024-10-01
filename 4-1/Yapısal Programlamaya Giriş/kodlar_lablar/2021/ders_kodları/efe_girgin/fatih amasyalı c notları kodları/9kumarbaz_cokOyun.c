#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int main()
{
	int m,n,h,t=0,i;
	float p;
	srand(time(NULL));   // bir kez cagirilmali
	printf("elinizdeki parayý ve kazanc hedefinizi veriniz\n");
	scanf("%d %d",&n,&m);
	printf("kumarhane kazandýrma oraný\n");
	scanf("%f",&p);
  	h=n+m; // elimizde olmasini hedefledigimiz toplam para
	int k=10000; // deneme sayýsý
	int kaz=0;	// kazanilan oyun sayisi
	int en=n;	// her oyunda paranin ilk seferki tutara donmesi icin
  	for (i=0;i<k;i++)
	{
		n=en;
		while ((n<h) && (n>0))
		{
			if ((rand()/(float)RAND_MAX)>(1-p))	//kazandýrma oranýndan buyukse
				n++;	//1 tl kazan
			else
				n--;	//1 tl kaybet
				
		}
		if (n==h) 
			kaz++;
	}
	printf("%f",(float)kaz/k);
	
	return 0;	
}
