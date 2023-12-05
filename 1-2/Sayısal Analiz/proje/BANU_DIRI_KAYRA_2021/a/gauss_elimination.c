#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 10

int main(void)
{
		 float a[SIZE][SIZE], s,b[SIZE],c[SIZE];
		 int i,j,k,n,m;
		 printf("Lutfen matrisin satir-sutun sayisini giriniz: ");
		 scanf("%d", &n);
		 printf("Lutfen matrisin elemanlarini giriniz:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   printf("a[%d][%d] = ",i,j);
				   scanf("%f", &a[i][j]);
			  }
			  printf("Lutfen matrisin %d. sonucunu giriniz:\n",i);
		 scanf("%f",&a[i][n+1]);
		 }
		 if(a[1][1]==0){
		 	for(i=1;i<=2*n;i++){
		 		m=a[1][i];
		 		a[1][i]=a[2][i];
		 		a[2][i]=m;
			 }
		 }
		 for(i=1;i<=n;i++)
		 {
			  for(j=i;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    s = a[j][i]/a[i][i];
					    for(k=1;k<=n+1;k++)
					    {
					     	a[j][k] = a[j][k] - s*a[i][k];
					    }
				   }
			  }
		 }
		 for(i=1;i<=n+1;i++){
		 	c[i]=0;
		 }
		 c[n]=a[n][n+1]/a[n][n];
		 for(i=n-1;i>=1;i--){
		 	for(j=1;j<=n;j++){
		 	c[i]-=a[i][j]*c[j];
		 }
		 c[i]=(c[i]+a[i][n+1])/a[i][i];
		 }
		 for(i=1;i<=n;i++){
		 	printf("%d. deger %lf\n",i,c[i]);
		 }
		 return 0;
	}
