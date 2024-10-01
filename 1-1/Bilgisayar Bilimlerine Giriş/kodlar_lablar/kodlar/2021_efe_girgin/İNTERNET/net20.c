#include <stdio.h>
int main(){
	int N,i,t1=0,t2=1;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&N);
	
	int nextTerm=t1+t2;
	printf("fibonacci serileri %d,%d,",t1,t2);
	
	for(i=1;i<=N;i++){
		printf("%d,",nextTerm);
		t1=t2;
		t2=nextTerm;
		nextTerm=t1+t2;
	}
	return 0;
}
