#include <stdio.h>
void swap(int* a ,int* b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int main(void){
	int i=2,k=3;
	swap(&i,&k);
	printf("%d   %d",i,k);
	return 0;
}
