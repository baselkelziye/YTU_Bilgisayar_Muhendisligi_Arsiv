#include <stdio.h>
int main(){
	int t1=0,t2=1,sayi,nextTerm;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	nextTerm=t1+t2;
	printf("fibonacci serileri=%d,%d,",t1,t2);
	
	while(nextTerm<=sayi){
		printf("%d,",nextTerm);
		t1=t2;
		t2=nextTerm;
		nextTerm=t1+t2;
		
	}
	return 0;
}

