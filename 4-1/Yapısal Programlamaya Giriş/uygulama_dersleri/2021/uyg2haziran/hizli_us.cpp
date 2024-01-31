#include <stdio.h>
int main()
{
	int x,y,digit,carpim=1;
	printf("x^y icin x ve y degerlerini veriniz\n");
	scanf("%d %d",&x,&y);
	while (y>0)
	{
		digit=y%2;
		y=y/2;
		if (digit>0)
			carpim=carpim*x;
		x=x*x;
	}
	printf("sonuc:%d",carpim);
	return 0;
}

