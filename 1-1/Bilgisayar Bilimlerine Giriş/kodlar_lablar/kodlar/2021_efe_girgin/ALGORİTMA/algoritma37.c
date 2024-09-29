#include <stdio.h>
int main(){
	int N,M,k,i,j;
	printf("lutfen ankete kac kisinin katildigini giriniz:\n");
	scanf("%d",&N);
	
	printf("lutfen anketteki soru sayisini giriniz\n");
	scanf("%d",&M);
	
	int H[M];
	int E[M];
	int A[N][N];
	for(i=0;i<M;i++){
		H[i]=0;
		E[i]=0;
	}
	printf("evet ve hayirlarini giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	k=0;
	for(j=0;j<M;j++){
		for(i=0;i<N;i++){
			if(A[i][j]==0){
				H[k]++;
			}
			else{
				E[k]++;
			}
		}
		k++;
	}
	for(i=0;i<M;i++){
		printf("%d.soru icin %d evet %d hayir dendi\n",i+1,E[i],H[i]);
	}
}
//kod calýsýyor
//200 kiþiye 30 soruluk bir anket uyugulaniyor.cevaplar evet ve hayýrdan olusuyor.evetler 1,hayýrlar 0 ile gösteriliyor.
//buna göre her soruya verilen evet ve hayir sayilarini bir diziye yazdiran algoritma ve programi.
//sayfa 32
//1.soru

