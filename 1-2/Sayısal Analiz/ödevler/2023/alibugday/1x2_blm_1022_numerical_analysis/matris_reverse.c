#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,j,n,k;
	float dizi[MAX][MAX], dizi_2[MAX][MAX],oran;
	
	printf("Matrix N sayisini giriniz");
    scanf("%d",&n);
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
	    {
			if(i==j)
			{
			   	dizi_2[i][j] = 1;
			}
			else
			{
			    dizi_2[i][j] = 0;
			}
		}
	}
	
    
    for (i=1;i<=n;i++)
    {
	    for (j=1;j<=n;j++){
			printf("%d\'inci satir %d\'inci stun matris elemani  giriniz:",i,j);
    		scanf("%f",&dizi[i][j]);				
	    }
    }
    
	for(i=1;i<=n;i++)
	{
		if(dizi[i][i] == 0.0)
		{
		   printf("sifir bolmesi tekrar calistirin");
		   return 0;
	    }
		for(j=1;j<=n;j++)
		{
		   if(i!=j)
		   {
			    oran = dizi[j][i]/dizi[i][i];
			    for(k=1;k<=n;k++)
			    {
				   	dizi[j][k] = dizi[j][k] - oran*dizi[i][k];
				   	dizi_2[j][k] = dizi_2[j][k] - oran*dizi_2[i][k];
				}
			}
		}
	}
	//ters matrisin her bir satýrý ilk matrisin köþegenlerine bölümü
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
		{
			dizi_2[i][j] = dizi_2[i][j]/dizi[i][i];
		}
	}
	
	printf("\ninverse matris:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%0.4f\t",dizi_2[i][j]);
		}
		printf("\n");
 	}
	
	return(0);
	




	return 0;
}
