/*sirali bir dizi içerisindeki sayýlarý ikiþer ikiþer toplayarak toplamý
  sýrayý bozmadan ayný dizi içerisine yerleþtiren programýn akýþ diyagramý 
  dizinin eleman sayisi:7
  dizinin elemanlarini :10 15 45 65 100 120 160
  dizinin yeni hali:    10 15 25 45 65 70 100 120 135 160 220 295 515
*/
  
#include <stdio.h>
int main( ) {
int n, i, k, j, top;
static int a[20];
printf("dizinin eleman sayisi:\n");
scanf("%d",&n);
printf("dizinin elemanlarini veriniz:\n");
for (i=0;i<n;i++)
	scanf("%d",&a[i]);
i=0;
j=2;
while(i<n)
{
	top=a[i]+a[i+1];
	while ((a[j]<=top) && (j<n))
		j++;
	for (k=n-1;k>=j;k--)
		a[k+1]=a[k];
	a[j]=top;
	i=i+2;
	j=i+2;
	n++;
}
n--;
printf("dizinin yeni hali:\n");
for (i=0;i<n;i++)
	printf("%d ",a[i]);
return 0;
}




