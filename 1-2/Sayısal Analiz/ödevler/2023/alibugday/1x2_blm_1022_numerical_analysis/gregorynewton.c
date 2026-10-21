#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fakt(int n);
float payHesapla(float x, int n);

int main() {
	int n,i,j;
	float dizi[MAX],F[MAX][MAX];
	printf("n sayýsýný giriniz");
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
    {
		printf("X:",i+1);
    	scanf("%f",&dizi[i]);				
	
    }
    
    for (i=0;i<n;i++)
    {
		printf("F[%d]:",i+1);
    	scanf("%f",&F[i][0]);				
    }
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++)
            F[j][i] = F[j + 1][i - 1] - F[j][i - 1];
    }
    
    //ileri fark tablosu
    printf("ileri fark tablosu:\n");
    for (i=0;i<n;i++)
    {
	    for (j=0;j<n;j++){
			printf("%0.4f",F[i][j]);				
	    }
	    printf("\n");
    }
    
    float deger;
    printf("bulmak istedigin deger");
    scanf("%f",&deger);
    
    float toplam = F[0][0];
    float u = (deger - dizi[0]) / (dizi[1] - dizi[0]);
    for (i = 1; i < n; i++) {
        toplam = toplam + (payHesapla(u, i) * F[0][i]) /
                                 fakt(i);
    }
 
 	printf("sonuc:%f",toplam);
	return 0;
}


float payHesapla(float x, int n)
{
	int i;
    float temp = x;
    for (i = 1; i < n; i++)
        temp = temp * (x - i);
    return temp;
}

int fakt(int n)
{
	int i;
    int x = 1;
    for (i = 2; i <= n; i++)
        x *= i;
    return x;
}



