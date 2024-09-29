#include <stdio.h>
int main(){
	int N,i;
	float p;
	printf("lutfen N sayisi giriniz\n");
	scanf("%d",&N);
	
	p=0;
	for(i=1;i<=N;i++){
		
		
		if(i%2==1){
			p=p+1/(float)(2*i-1);
		}
		else{
			p=p-1/(float)(2*i-1);
		}
			
		
	}
	
	printf("%f",4*p);
	
	return 0;
}
//kod calýsýyor
//4-4/3+4/5-4/7+4/9--------=pi
//n sayisini ne kadar fazla alýrsanýz pi nin degerine o kadar yaklaþýrsýnýz
//1.çözüm
//sayfa 2
