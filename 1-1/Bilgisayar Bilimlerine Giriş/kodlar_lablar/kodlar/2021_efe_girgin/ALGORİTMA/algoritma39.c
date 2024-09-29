/*1 2 3 4 8
2 5 6 1 3
3 6 7 2 4
4 1 2 3 5
8 3 4 5 7*/
#include <stdio.h>
int main(){
	int i,j,k;
	int A[15];
	int B[5][5];
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			B[i][j]=0;
			
		}
	}
	for(i=0;i<15;i++){
		scanf("%d",&A[i]);
		
	}
	k=0;
	for(i=0;i<5;i++){
		for(j=i;j<5;j++){
			B[i][j]=A[k];
			B[j][i]=B[i][j];
			k++;
		}
		
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",B[i][j]);
			
		}
		printf("\n");
		
	}
	
}



//deneme ve compile yapildi
//15 elemanli bir dizi ile 5x5 lik simetrik bir matris olusturan algoritma ve programi
//sayfa 34
//1.soru
//kod calısıyor
