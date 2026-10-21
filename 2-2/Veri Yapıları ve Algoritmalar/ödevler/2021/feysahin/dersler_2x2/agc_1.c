
//2^10'DAN SONRASINI HESAPLAMAMAKTA (ya da bayaðý uzun sürüyor bilemedim)

#include<stdio.h>
#include<math.h>

int main(){
	int a=11, found=0;
	long long x, i;
	
	//printf("a sayisini giriniz: ");
	//scanf("%d", &a);
	
	x = pow(10,a) - 1;
	
	while(found == 0){
		i=3;
		while(x%i != 0 && i < x/2){
			i+=2;
		}
		if(i>=x/2) found=1;
		else x-=2;
	}
	printf("%d basamakli en buyuk asal sayi: %lli", a, x);
	return 0;
}
