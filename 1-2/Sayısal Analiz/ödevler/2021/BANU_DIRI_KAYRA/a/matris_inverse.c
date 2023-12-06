#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 10

int main(void)
{
		 float a[SIZE][SIZE], s;
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
		 }
		 
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
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
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    s = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - s*a[i][k];
					    }
				   }
			  }
		 }
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
		 printf("\nMatrisin tersi:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	printf("%0.3f\t",a[i][j]);
			  }
			  printf("\n");
		 }
		 return 0;
}
