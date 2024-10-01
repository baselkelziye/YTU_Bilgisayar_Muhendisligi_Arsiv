#include <stdio.h>
int main(){
	double a,b,temp,first,second;
	printf("lutfen 2 tane sayi giriniz\n");
	scanf("%lf%lf",&first,&second);
	
	temp=first;
	first=second;
	second=temp;
	
	printf("birinci sayim=%lf ve ikinci sayim=%lf",first,second);
	return 0;
	
}
//Swap Numbers Using Temporary Variable
