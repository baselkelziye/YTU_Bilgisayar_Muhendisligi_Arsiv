#include <stdio.h>
int main(){
	int i,e,N;
	float p;
	printf("lutfen bir N sayisini giriniz\n");
	scanf("%d",&N);
	
	p=0;
	e=1;
	for(i=1;i<=N;i++){
		p=p+e*(1/(float)(2*i-1));
		e=e*(-1);
	}
	printf("%f",4*p);
	return 0;
	
}
//kod calýsýyor
//çözüm 2
//sayfa 3
