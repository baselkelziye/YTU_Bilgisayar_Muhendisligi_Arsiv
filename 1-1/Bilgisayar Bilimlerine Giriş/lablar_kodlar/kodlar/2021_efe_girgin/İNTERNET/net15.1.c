#include <stdio.h>
int main(){
	double num;
	printf("lutfen bir sayi giriniz\n");
	scanf("%lf",&num);
	
	if(num>0.0){
		printf("sayimiz pozitiftir\n");
	}
	else if(num<0.0){
		printf("sayimiz negatiftr\n");
	}
	else{
		printf("sayiniz 0'dir\n");
	}
	return 0;
}
//Check Positive or Negative Using Nested if...else
