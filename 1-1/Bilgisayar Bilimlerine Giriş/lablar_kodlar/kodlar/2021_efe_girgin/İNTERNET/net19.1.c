#include <stdio.h>
int main(){
	int sayi,N,i;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	printf("lutfen siniri giriniz\n");
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		printf("%d*%d=%d\n",sayi,i,sayi*i);
	}
	return 0;
}
//Multiplication Table Up to a range
