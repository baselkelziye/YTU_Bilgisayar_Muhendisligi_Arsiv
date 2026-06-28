#include<stdio.h>

int main(){
	int i,j,n,counter=0;
	
	printf("Kare matrisin boyutunu giriniz.\n");
	scanf("%d",&n);
	int A[n][n];
	
	printf("Matrisin elemanlarini giriniz.\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j]==1){
				counter++;
			}
		}
	}
	
	printf("\nMatrisin %d elemani 1'den olusmaktadir.",counter);
	
	return 0;
}
//denendi ve compile edildi
//elemanlari sadece 0 ve 1 den olusan NxN lik bir matriste kac elemanin 1 den olustugunu bulan algoritma ve programi
//sayfa 49
//1.soru
//kod çalýþýyor
