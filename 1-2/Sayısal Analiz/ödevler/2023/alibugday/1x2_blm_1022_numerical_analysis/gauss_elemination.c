#include<stdio.h>
#define MAX 20


int main(){
	float dizi[MAX][MAX],oran;
	//dizi
	//oran daha sonra kösegen elemanlarýyla diðer elemanlarýn oraný olacak
	int i,j,k,n;
	
	printf("matris N degerini giriniz: ");
	scanf("%d", &n);
	 printf("matris asagidaki sekilde alinacaktir\n");
	 printf(". . . : .\n");
	 printf(". . . : .\n");
	 printf(". . . : .\n");
	 //matrisi alýnýyor
	 for(i=1;i<=n;i++)
     {
	     for(j=1;j<=n+1;j++)
	  {
		   printf("%d inci satir %d inci stun matris degeri = ",i,j);
		   scanf("%f", &dizi[i][j]);
	  }
	}
	
	for(i=1;i<=n-1;i++)
	 {
		  //
		  
		  
		  
		  
		  for(j=i+1;j<=n;j++)
		  {
			   oran = dizi[j][i]/dizi[i][i];
			   
			   for(k=1;k<=n+1;k++)
			   {
			  		dizi[j][k] = dizi[j][k] - oran*dizi[i][k];
			   }
		  }
	 }
	//cevaplarýn oldugu matris
	float deger[MAX];
	deger[n] = dizi[n][n+1]/dizi[n][n];
	
	
	
	
	
	//tek tek sonuclar bulunuyor
	for(i=n-1;i>=1;i--)
	   		{
		  deger[i] = dizi[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		deger[i] = deger[i] - dizi[i][j]*deger[j];
		  }
		  deger[i] = deger[i]/dizi[i][i];
	   }
	   
	//cýktýnýn ekrana bastýrýlmasý
	printf("==========\nsonuc:\n");
	 for(i=1;i<=n;i++)
	 {
	  	printf("deger[%d] = %0.4f\n",i, deger[i]);
	 }
	 
	 return 0;
}



