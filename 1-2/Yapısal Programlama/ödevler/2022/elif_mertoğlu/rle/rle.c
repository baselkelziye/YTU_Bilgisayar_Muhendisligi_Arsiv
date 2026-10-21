#include<stdio.h>
int main(){
	
	int i,j,M,N;
    
	printf("Matrisin satir ve sutun sayisini giriniz:\n");
	scanf("%d%d",&N,&M);
	int A[N][M];
	printf("Matrisin elemanlarini doldurunuz:\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
/*    for(i=0;i<N;i++){
    	printf("\n");
		for(j=0;j<M;j++){                <--kullanýcýnýn girdiði matrisi tablo halinde görebilmek için
			printf("%d",A[i][j]);
		}
	}
*/	
	int k,r,sayac;
	int dizi[100];
	int count[100];
	k=0;
	r=0;
	sayac=1;
	A[N][0]==-1;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(j==M-1){
				if(A[i][j]==A[i+1][0]){
					sayac=sayac+1;
				}else{
					dizi[k]=A[i][j];
					k=k+1;
					count[r]=sayac;
					r=r+1;
					sayac=1;
				}
			}else{
				if(A[i][j]==A[i][j+1]){
					sayac=sayac+1;
				}else{
					dizi[k]=A[i][j];
					k=k+1;
					count[r]=sayac;
					r=r+1;
					sayac=1;
				}
			}
		}
	}
	
	
	int encode[r+k-1];
	int a,b;
	
	b=0;
	
	for(a=0;a<=r-1;a++){
		if(a==r-1){
			encode[b]=count[a];
		}else{
			encode[b]=count[a];
			b=b+2;
		}
	}
	
	b=1;
	
	for(a=0;a<=k-1;a++){
		if(a==k-1){
			encode[b]=dizi[a];
		}else{
			encode[b]=dizi[a];
			b=b+2;
		}
	}
	
	printf("Matrisin RLE metoduyla daraltilmis hali: \n");
	for(a=0;a<=b;a++){
		printf("%d",encode[a]);
	}
	printf("\n\n");
	
	int p,s,l,sayac2;
	int decode[N][M];
	
	p=0; //satýr
	s=0; //sütun
	
	for(l=0;l<b;l=l+2){
		sayac2=0;
		while(sayac2<encode[l]){
			if(s==M){
				p=p+1;
				s=0;
			}else{
			}
		decode[p][s]=encode[l+1];
		s=s+1;
		sayac2=sayac2+1;	
		}
	}
	
	int e,f;
	
	printf("Matrisin acik hali:");
	for(e=0;e<N;e++){
		printf("\n");
		for(f=0;f<M;f++){
			printf("%d",decode[e][f]);
		}
	}
	
	printf("\n");
	float x,y,deger;
	x=b+1;
	y=N*M;
	deger=(1-x/y);
	printf("compression ratio:%f",deger); 
	//printf("compression ratio:%.2f",deger); <-- virgülden sonraki sadece 2 basamaðý görmek için
	
	return 0;
}
