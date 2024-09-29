#include <stdio.h>
int main(){
	double a,b;
	printf("iki tane sayi giriniz\n");
	scanf("%lf%lf",&a,&b);
	
	a=a-b;
	b=a+b;
	a=b-a;
	
	printf("birinci sayimiz =%.2lf ve ikinci sayimiz=%.2lf",a,b);
	return 0;
}
//Swap Numbers Without Using Temporary Variables

