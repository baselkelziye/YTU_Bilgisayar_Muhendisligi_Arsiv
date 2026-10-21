#include<stdio.h>
int main(){
	int filtretoplam=0;
	int a,b,c,d;
	int n,m,k;
	int toplam;
	int goruntu[50][50];
	int filtre[50][50];
	int result[50][50];
	int i,j;
	printf("goruntu matrisinin row sayisini gir:");
	scanf( "%d",&n);
	printf("goruntu matrisinin column sayisini gir:");
	scanf( "%d",&m);
	printf("filtre kare matrisinin row/column sayisini gir:");
	scanf( "%d",&k);
	a=0;
	c=0;
	b=k-1;
	d=k-1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("goruntu matrisi icin deger gir:");
			scanf( "%d",&goruntu[i][j]);}}
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			printf("filtre matrisi icin deger gir:");
			scanf( "%d",&filtre[i][j]);
			filtretoplam+=filtre[i][j];}}		
	while(b<=n-1){
		while(d<=m-1){
			toplam=0;
			for(i=a;i<b+1;i++){
				for(j=c;j<d+1;j++){
					toplam+=goruntu[i][j]*filtre[i-a][j-c];}}
			result[a][c]=(toplam/filtretoplam);
			c++;
			d++;}
		a++;
		b++;}		
	for(i=0;i<(n-k+1);i++){
		for(j=0;j<(m-k+1);j++){
		printf("%d",result[i][j]);}
		printf("\n");}	
	return 0;											
}
