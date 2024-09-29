#include <stdio.h>
#define size 100
int main(){
	int N,t,k,e,i;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	
	t=0;					//üçüncü indis
	k=1;					//ikinci indis
	e=1;					//birinci indis
	for(i=3;i<N;i++){
		t=k+e;
		e=k;
		k=t;
	}
	printf("%d",t);
	return 0;
}
//e k t
//kod calýsýyor
//sayfa 8
