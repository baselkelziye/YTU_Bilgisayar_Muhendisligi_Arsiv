#include <stdio.h>

int sadelestir(int ,int );
void topla(int ,int ,int , int ,int *,int *);
int main()
{
	int pay1, payda1;
	int pay2,payda2;
	int sonucpay,sonucpayda;
	printf("1. Kesir Pay ve Payda");
	scanf("%d %d",&pay1,&payda1);
	printf("2. Kesir Pay ve Payda");
	scanf("%d %d",&pay2,&payda2);
	
	topla(pay1,payda1,pay2,payda2,&sonucpay,&sonucpayda);
	
	printf("Sonuc %d / %d",sonucpay,sonucpayda);
	return 0;
}

void topla(int pay1,int payda1,int pay2, int payda2,int *y,int *z){
	int pay, payda, x, temp;
	
	pay=pay1*payda2 + pay2*payda1;
	payda=payda1*payda2;
	
	x=sadelestir(pay,payda);
	
	*y = pay / x;
	*z = payda / x;
	
}

int sadelestir(int x,int y){
	int min;
	if(x==y )
	   return x;
	else 
	min= (x<y) ? x:y;
	while(x % min!=0 || y % min!=0)
	{
		min--;		
	}	
	return min;
}
