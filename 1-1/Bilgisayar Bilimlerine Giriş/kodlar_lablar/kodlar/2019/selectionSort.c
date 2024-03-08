//selection sort ile siralama
#include <stdio.h>
int main()
{
	int n,i,j,min,temp;
	int dizi[50];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&dizi[i]);
	 for (i=0; i<n-1; i++)
     {
         //bastaki elemani local min olarak alalim
		 min = i;
		 //ilgili bolgedeki min elemani bulalim
         for (j=i+1; j<n; j++)
         {
             if (dizi[j] < dizi [min])
             min = j;
         }
         //bastaki eleman ile yer degistirelim
         temp = dizi[i];
         dizi[i] = dizi[min];
         dizi[min] = temp;
     }

	for (i=0;i<n;i++)
		printf("%d",dizi[i]);
	return 0;
}
