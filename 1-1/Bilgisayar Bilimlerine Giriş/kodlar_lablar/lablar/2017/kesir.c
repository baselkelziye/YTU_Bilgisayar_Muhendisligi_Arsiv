#include <stdio.h>

int sadelestir(int ,int );
int topla(int ,int ,int , int );
int main()
{
	int pay1, payda1;
	int pay2,payda2;
	printf("1. Kesir Pay ve Payda");
	scanf("%d %d",&pay1,&payda1);
	printf("2. Kesir Pay ve Payda");
	scanf("%d %d",&pay2,&payda2);
	
	topla(pay1,payda1,pay2,payda2);
	return 0;
}

int topla(int pay1,int payda1,int pay2, int payda2){
	int pay, payda,x;
	
	pay=pay1*payda2 + pay2*payda1;
	payda=payda1*payda2;
	x=sadelestir(pay,payda);
	pay/=x;
	payda/=x;
	printf("Sonuc %d / %d",pay,payda);
	return pay,payda;
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
