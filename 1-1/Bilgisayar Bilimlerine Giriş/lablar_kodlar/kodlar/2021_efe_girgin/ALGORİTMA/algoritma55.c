#include <stdio.h>
#define size 100
int main(){
	int N,M,i,j,sat=0;
	printf("lutfen matrisin satir ve sutunlarini giriniz\n");
	scanf("%d%d",&N,&M);
	int A[N][M],yeni[N*M/2][3];
	printf("A matrisini giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(A[i][j]!=0){
				yeni[sat][0]=i;
				yeni[sat][1]=j;
				yeni[sat][2]=A[i][j];
				sat=sat+1;
			}
		}
	}
	for(i=0;i<sat;i++){
		for(j=0;j<3;j++){
			printf("%d",yeni[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
//kod calýsýyor
//elemanlarinin yarýsýndan cogu sifir olan matrise"sparse matris denilir verilen bir sparse matrisin sýfýrdan farkli degerlerini saklamak için öyle bir yapý kurunuz ki 
//istenilen bir satir ve sutundaki degerin bu yeni yapý kullanýlarak elde edilebilmesi mumkun olsun.
//bu islemin algoritmasi ve programi.
//sayfa 47
//2.soru
