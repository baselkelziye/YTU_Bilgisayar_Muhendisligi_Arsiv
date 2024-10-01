#include <stdio.h>
int main(){
	float a,y,e;
	int i,j,N,x;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	
	printf("e nin ussunu giriniz\n");
	scanf("%d",&x);
	e=1;
	for(i=1;i<=N-1;i++){
		a=1;
		y=1;
		for(j=1;j<=i;j++){
			y=(float)y*x;
			a=(float)a*j;
		}
		e=e+(float)y/a;
	}
	printf("%f",e);
	return 0;
}
//kod calýsýyor
//sayfa 5
