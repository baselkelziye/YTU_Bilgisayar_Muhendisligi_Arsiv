#include<stdio.h>
void topla(int ,int ,int ,int ,int *,int *);
void get_value(int *,int *);
int minbul(int ,int );
int kesir_yaz(int ,int );
int gcd(int , int );

int main()
{
	int pay1,pay2,pay3;
	int payda1,payda2,payda3;
		
	get_value(&pay1,&payda1); //klavyeden oku call by reference neden kullandik SORU-1
	get_value(&pay2,&payda2);
	
	topla(pay1,pay2,payda1,payda2,&pay3,&payda3);

	int n=gcd(pay3,payda3); 
	pay3/=n;
	payda3/=n; // bunu uc(18-20) satir kod yazma acisindan iyilestirilebilir mi? SORU-2
	
	kesir_yaz(pay1,payda1);
	printf("+");
	kesir_yaz(pay2,payda2);
	printf("=");
	kesir_yaz(pay3,payda3);
	return 0;	
}
void get_value(int *pay,int *payda){ // neden * kullandik SORU-3
 printf("kesir pay ve payda (a b):");
 scanf("%d %d",pay,payda);
}

void topla(int pay1,int pay2,int payda1,int payda2,int *pay3,int *payda3){ // neden toplayip kesir return edemiyoruz? SORU-4
 	*pay3=pay1*payda2+pay2*payda1;
	*payda3=payda1*payda2;
}


int minbul(int pay3,int payda3){
	int min=(pay3<payda3)?pay3:payda3;
}

int kesir_yaz(int x,int y){
	printf("(%d / %d)",x,y);
}

int gcd(int pay3, int payda3){
	int min;
	if(pay3==payda3)
		return pay3;
	else{
		min=minbul(pay3,payda3);
		while((pay3%min!=0 || payda3%min!=0 ) && min>1){
			min--;
		}
	}
	printf("gcd:%d\n",min);	
	return min;
}
