#include <stdio.h>
int main(){
	int n1,n2;
	printf("lutfen 2 tane sayi giriniz\n");
	scanf("%d%d",&n1,&n2);
	
	n1=(n1>0)?n1:-n1;
	n2=(n2>0)?n2:-n2;
	
	while(n1!=n2){
		if(n1>n2){
			n1=n1-n2;
			
		}
		else{
			n2=n2-n1;
		}
	}
	printf("en buyuk ortak bolen=%d",n1);
	return 0;
}
//Example #3: GCD for both positive and negative numbers
