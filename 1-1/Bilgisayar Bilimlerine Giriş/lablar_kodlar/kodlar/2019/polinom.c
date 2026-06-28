#include <stdio.h>
int main()
{
	int N,x;
	int i,j,top,carp;
	int usler[20],katsayilar[20];
	
	printf("terim sayisini veriniz\n");
	scanf("%d",&N);
	
	printf("x sayisini veriniz\n");
	scanf("%d",&x);
	
	printf("usleri ve katsayilari veriniz\n");
	for (i=0;i<N;i++)
		scanf("%d %d",&usler[i],&katsayilar[i]);
	top=0;
	for (i=0;i<N;i++)
	{
		carp=1;
		for (j=0;j<usler[i];j++)
			carp=carp*x;
		
		top=top+katsayilar[i]*carp;
	}
	printf("%d",top);
	return 0;	
}
