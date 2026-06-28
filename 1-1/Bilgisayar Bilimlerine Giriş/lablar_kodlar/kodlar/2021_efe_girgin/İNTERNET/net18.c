#include <stdio.h>
int main(){
	int carpim=1,sayi,i;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	for(i=1;i<=sayi;i++){
		carpim=carpim*i;
	}
	printf("%d sayisinin faktoriyeli=%d",sayi,carpim);
	return 0;
}
//Factorial of a Number
