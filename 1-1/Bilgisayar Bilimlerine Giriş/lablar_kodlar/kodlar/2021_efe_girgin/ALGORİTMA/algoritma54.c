#include <stdio.h>
int main(){
	int rnk,i,j,N,M,adr;
	
	printf("matrisin satir ve sutun sayisini giriniz\n");
	scanf("%d %d",&N,&M);
	
	int A[N][M];
	
	printf("renk sayisi giriniz\n");
	scanf("%d",&rnk);
	
	int renk[rnk];
	printf("A matrisini giriniz\n");
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	for(i=0;i<rnk;i++){
		renk[i]=0;
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			adr=A[i][j];
			renk[adr-1]=renk[adr-1]+1;
		}
	}
	for(i=0;i<rnk;i++){
			printf("renk[%d]=%d\n",i+1,renk[i]);
	}
return 0;
}










//kod calýsýyor
//renklerin 1-8 arasi sayilarla gösterildigi 50ye 50lik bir resimde her rengin kac defa kullanýldýgýný bulan algoritma ve programi
//sayfa 47
//1.soru
