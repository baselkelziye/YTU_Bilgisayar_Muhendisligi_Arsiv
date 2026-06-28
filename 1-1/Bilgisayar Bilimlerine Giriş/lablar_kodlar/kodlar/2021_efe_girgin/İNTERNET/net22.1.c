#include <stdio.h>
int main(){
	int i,n1,n2,gcd,lcm;
	printf("lutfen 2 tane sayi giriniz\n");
	scanf("%d%d",&n1,&n2);
	
	for(i=1;i<=n1&&i<=n2;i++){
		if(n1%i==0&&n2%i==0){
			gcd=i;
		}
	}
	lcm=(n1*n2)/gcd;
	printf("sayilarimizin okeki=%d",lcm);
	return 0;
}
//LCM Calculation Using GCD
