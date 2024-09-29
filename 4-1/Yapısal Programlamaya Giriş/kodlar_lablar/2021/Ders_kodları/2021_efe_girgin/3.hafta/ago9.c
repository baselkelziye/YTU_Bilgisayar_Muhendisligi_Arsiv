#include <stdio.h>
int main(){
	int N,i,A,carpim=1,C;
	printf("bir sayi giriniz\n");
	scanf("%d",&N);
	A=(N-1)/2;
	for(i=0;i<A;i++){
		carpim=carpim*10;
	}
	C=carpim*9;
	printf("%d basamakli %d tane sayi vardir",N,C);
	return 0;
}
