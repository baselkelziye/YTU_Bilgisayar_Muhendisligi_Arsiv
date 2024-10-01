#include <stdio.h>
int main(){
	int taban,exp;
	long long sonuc=1;
	printf("lutfen taban sayisini giriniz\n");
	scanf("%d",&taban);
	
	printf("lutfen ussu giriniz\n");
	scanf("%d",&exp);
	
	while(exp!=0){
		sonuc=sonuc*taban;
		exp--;
	}
	printf("cevap=%lld",sonuc);
	return 0;
}
//Power of a Number Using the while Loop
