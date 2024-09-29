#include<stdio.h>
int main(){
	int i,sayi,sum=0;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	for(i=0;i<=sayi;i++){
		sum=sum+i;
	}
	printf("toplam=%d",sum);
	return 0;
}
//Sum of Natural Numbers Using for Loop
