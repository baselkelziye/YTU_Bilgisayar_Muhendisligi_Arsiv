#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int main()
{
	int m,n,h,t=0,i;
	static int R[10000];
	float p;
	srand(time(NULL));   // bir kez cagirilmali
	printf("elinizdeki parayý ve kazanc hedefinizi veriniz\n");
	scanf("%d %d",&n,&m);
	printf("kumarhane kazandýrma oraný\n");
	scanf("%f",&p);
  	h=n+m; // elimizde olmasini hedefledigimiz toplam para
	while ((n<h) && (n>0))
	{
		if ((rand()/(float)RAND_MAX)>(1-p))	//kazandýrma oranýndan buyukse
			n++;	//1 tl kazan
		else
			n--;	//1 tl kaybet
		R[t]=n;
		t++;		
	}
	if (n>0) printf("kazandi\n");
	for (i=0;i<t;i++)
		printf("-%d-",R[i]);
	return 0;	
}
