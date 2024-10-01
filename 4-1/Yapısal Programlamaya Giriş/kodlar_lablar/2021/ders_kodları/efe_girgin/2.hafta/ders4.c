#include <stdio.h>
int main(){
	int N,i,j,x;
	float e,a,y;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	
	printf("e nin ussunu giriniz\n");
	scanf("%d",&x);
	
	e=1;
	for(i=1;i<=N-1;i++){
		y=1;
	
	for(j=1;j<=i;j++){
		y=(float)y*x;
	}
	a=1;
	for(j=1;j<=i;j++){
		a=(float)a*j;
	}
	e=(e+(float)y/a);
}
printf("%.10f",e);
return 0;
}
//1+x+x^2/2+x^3/6+x^4/24......
//kod calýsýyor
//sayfa 4
