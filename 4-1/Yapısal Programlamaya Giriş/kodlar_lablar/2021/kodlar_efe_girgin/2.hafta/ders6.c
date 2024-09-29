#include <stdio.h>
int main(){
	int x,N,i;
	float e,y,a;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	
	printf("lutfen e nin ussunu giriniz\n");
	scanf("%d",&x);
	e=1;
	y=1;
	a=1;
	for(i=1;i<=N-1;i++){
		y=(float)y*x;
		a=(float)a*i;
		
		e=e+(float)y/a;
	}
	printf("%f",e);
	return 0;
}
//kod calýsýyor
//sayfa 6
