#include <stdio.h>
#include <math.h>
int main(){
    int a,b,t1,t2,k,l,i,j;
	printf("lutfen bir sayi giriniz \n");
	scanf("%d",&a);
	
	printf("lutfen bir sayi daha giriniz \n");
	scanf("%d",&b);
	
	t1=1;
	t2=1;
	k=sqrt(a);
	l=sqrt(b);
	
	for(i=2;i<=k;i++){
		if(a%i==0){
			t1=t1+i+a/i;
		}
	}
		for(j=2;j<=l;j++){
			if(b%j==0){
				t2=t2+j+b/j;
			}
		}
	if((t1==b)&& (t2==a)){
		printf("arkadastir");
	}
	else{
		printf("arkadas degildir");
	}
	return 0;
}
//carpanlarinin toplami karsilikli kendilerine esit olan iki sayiya"arkadas sayi"denir.
//buna göre girilen iki sayinin arkadas olup olmadigini bulan algoritma ve programi
//sayfa 18
//kod calisiyor
