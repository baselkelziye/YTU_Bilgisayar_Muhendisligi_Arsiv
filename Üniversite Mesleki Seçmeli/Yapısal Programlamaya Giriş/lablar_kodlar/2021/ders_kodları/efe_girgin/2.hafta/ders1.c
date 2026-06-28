#include <stdio.h>
int main(){
	int x,N,k,i;
	
	
	printf("lutfen tabani giriniz\n");
	scanf("%d",&x);
	printf("lutfen ussu giriniz\n");
	scanf("%d",&N);
	k=1;
	for(i=0;i<N;i++){
		k=k*x;
	}
	printf("%d",k);
	return 0;
}
//sayfa 1
//ÜSLÜ BÝR SAYININ DEÐERÝNÝ BULMA
//kod calýsýyor
