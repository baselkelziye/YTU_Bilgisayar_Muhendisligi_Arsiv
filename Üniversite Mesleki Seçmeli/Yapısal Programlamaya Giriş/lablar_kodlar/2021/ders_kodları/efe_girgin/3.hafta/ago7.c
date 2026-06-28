#include <stdio.h>
int main(){
	int a,b,c,sayi;
	for(a=0;a<=9;a++){
		for(b=0;b<=9;b++){
			sayi=0;
			for(c=0;c<=9;c++){
				sayi=100000*a+10000*b+1000*c+100*c+10*b+a;
				printf("%d\n",sayi);
			}
		}
	}
	
	return 0;
}
//kod calýsýyor
//sayfa 8
