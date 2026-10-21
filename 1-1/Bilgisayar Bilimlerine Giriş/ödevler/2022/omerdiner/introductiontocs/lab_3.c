#include <stdio.h>

int main(){
	int N,M,matrix[50][50],emptyLines[50],i,j,k=0,onesCount=0;
	
	printf("Satir sayisini giriniz:");
	scanf("%d",&N);
	printf("\nSutun sayisini giriniz:");
	scanf("%d",&M);
	//matrisi alýr
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("[%d][%d] indisli elemani girin:",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
	//içinde bir olmayan satirlari emptyLines adli matrise ekliyor.ekledikçe k artýyor ki yerlerini tutabilsin
	for(i=0;i<N;i++){
		onesCount=0;
		for(j=0;j<M;j++){
			if(matrix[i][j]==1){
				onesCount=1;
			}
		}
		if(onesCount==0){
			emptyLines[k]=i;
			k++;
		}
	}
	
	//kullanýcýnýn girdiði matrisi ekranda gösterir
	printf("\n\nGirilen matrix\n");
		for(i=0;i<N;i++){
	    	for(j=0;j<M;j++){
			printf("%d ",matrix[i][j]);
		}printf("\n");
	}
	// içinde bir olmayan satirlari yazar
	printf("\nCikti:\n");
	for(i=0;i<k;i++){
		printf("%d  ",(emptyLines[i]+1));
	} 
	
	
	return 0;
}
