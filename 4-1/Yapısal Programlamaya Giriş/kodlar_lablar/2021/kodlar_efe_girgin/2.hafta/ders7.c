#include <stdio.h>
#define size 100
int main(){
	int N,i;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	int f[size];
	f[0]=1;
	f[1]=1;

	for(i=2;i<=N+2;i++){
		f[i]=f[i-1]+f[i-2];
	}
	printf("f[%d]=%d",i-3,f[N-2]);
	return 0;
}
//kod calýsýyor
//sayfa 7
