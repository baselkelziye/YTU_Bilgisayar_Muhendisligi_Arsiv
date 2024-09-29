#include <stdio.h>
int main(){
	int a,b,c,d,sayi;
	for(a=1;a<=9;a++){
		for(b=0;b<=9;b++){
			for(c=0;c<=9;c++){
				sayi=0;
				for(d=0;d<=9;d++){
					sayi=1000000*a+100000*b+10000*c+1000*d+100*c+10*b+a;
					printf("%d\n",sayi);
				}
			}
		}
	}
return 0;
}
//sayfa 9

