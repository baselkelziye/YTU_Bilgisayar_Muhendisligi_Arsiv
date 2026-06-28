#include <stdio.h>
//faktoriyel hesabý
int main(void){
	int n,i,mul=1;
	
	printf("please enter a number:\n");
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		mul=mul*i;
	}
	printf("%d! is equal to %d\n",n,mul);
	
	return 0;
}
//deneme ve compile yapildi 1
