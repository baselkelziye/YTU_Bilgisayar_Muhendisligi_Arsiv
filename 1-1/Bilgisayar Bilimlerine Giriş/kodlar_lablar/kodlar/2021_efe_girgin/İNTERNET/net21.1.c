#include <stdio.h>
int main(){
	int n1,n2;
	printf("lutfen 2 sayi giriniz\n");
	scanf("%d%d",&n1,&n2);
	
	while(n1!=n2){
		if(n1>n2){
			n1=n1-n2;
		}
		else{
			n2=n2-n1;
		}
	}
	printf("en buyuk ortak bolen =%d",n1);
	return 0;
}
//Example #2: GCD Using while loop and if...else Statement

