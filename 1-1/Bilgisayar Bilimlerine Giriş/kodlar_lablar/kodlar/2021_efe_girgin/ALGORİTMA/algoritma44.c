#include <stdio.h>
#define size 100
int main(){
	int j,k,i;

	
	int B[size];
	j=0;
	k=6;

	for(i=4;i<25;i++){
		k=k*i;
		B[j]=k;
		j=j+1;
		
	}
	for(i=0;i<21;i++){
		printf("%d\t",B[i]);
	}
	return 0;
}
//deneme ve compile yapildi
//3-25 sayilari arasindaki sayilarin faktoriyellerini hesaplayýp bir diziye yerlestiren algoritma ve programi
//sayfa 39
//1.soru
//kod calýsýyor
