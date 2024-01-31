//a+b+c=1000, a^2+b^2=c^2, a,b,c>0 icin a,b,c sayþlari neler olabilir?
#include <stdio.h>
int main()
{
	int i,j,k;
	int t=0;
	// N^3 ile cozum
	for (i=1;i<=1000;i++)
		for (j=1;j<=1000;j++)
			for (k=1;k<=1000;k++)
			{
				t++;
				if( ((i*i+j*j)==k*k) && (i+j+k)==1000)
					printf("%d %d %d\n",i,j,k);
			}
	printf("%d\n\n",t);
	t=0;
	
	// N^2 / 2 ile cozum
	for (i=1;i<=1000;i++)
		for (j=1;j<=1000-i;j++)
		{
			k=1000-i-j;
			t++;
			if ((i*i+j*j)==k*k)
				printf("%d %d %d\n",i,j,k);
		}
	printf("%d\n\n",t);
	return 0;
}
