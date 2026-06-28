#include <stdio.h>
int main(){
	int num;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&num);
	
	(num%2==0)?printf("%d sayisi cifttir",num):printf("%d sayisi tektir",num);
	return 0;
}
//Program to Check Odd or Even Using the Ternary Operator
