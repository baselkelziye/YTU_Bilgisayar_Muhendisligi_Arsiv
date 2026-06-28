#include<stdio.h>

int main(){
	int i,j,n,m,x,tmp;
	printf("Matrisin boyutlarini giriniz.\n");
	scanf("%d %d",&n,&m);
	
	int A[n][m];

	printf("Matrisin elemanlarini giriniz.\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&A[i][j]);
		}
	}
	x=0;
	for(i=0;i<n;i++){
		for(j=x+1;j<m;j++){
			tmp=A[i][j];
			A[i][j]=A[j][i];
			A[j][i]=tmp;
		}
		x++;
	}
	
	printf("\nMatrisin transpozesi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
//denendi ve compile edildi
//bir matrisin transpozesini bulan algoritma ve programi
//sayfa 48
//1.soru
//kod çalýþýyor
