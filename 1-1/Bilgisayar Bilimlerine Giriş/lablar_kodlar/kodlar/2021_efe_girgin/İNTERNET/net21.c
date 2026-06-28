#include <stdio.h>
int main(){
	int i,gcd,a,b;
	printf("lutfen 2 tane sayi giriniz\n");
	scanf("%d%d",&a,&b);
	
	for(i=1;i<=a&&i<=b;i++){
		if(a%i==0&&b%i==0){
			gcd=i;
		}
	}
	printf("%d ve %d sayilarin en buyuk ortak boleni=%d",a,b,gcd);
	return 0;
}
//Example #1: GCD Using for loop and if Statement
