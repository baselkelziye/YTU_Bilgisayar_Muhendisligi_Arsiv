// a2 + b2 = c2 þeklinde yazilabilen pozitif tamsayilara Pythagorean triple denir
// verilen bir dizideki Pythagorean triple'lari bulan programi yaziniz
// n=7 a[]=3 8 5 15 4 17 9
// 3 5 4
// 8 15 17

#include <stdio.h>
int main()
{
	int n,i,j,k;
	int x,y,z;
	int a[30];
	printf("eleman sayisi?");
	scanf("%d",&n);
	printf("elemanlar?");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (i=0;i<n-2;i++)
	{
		x=a[i]*a[i];
		for (j=i+1;j<n-1;j++)
		{
			y=a[j]*a[j];
			for (k=j+1;k<n;k++)
			{
				z=a[k]*a[k];	
				if ((x==y+z) || (y==x+z) || (z==x+y))
					printf("%d %d %d\n",a[i],a[j],a[k]);
			}
		}
	}
	return 0;
}
