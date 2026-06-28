#include <stdio.h>
int main(){
	int i,sayi,sum=0;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	i=1;
	while(i<=sayi){
		sum=sum+i;
		i++;
	}
	printf("toplam=%d",sum);
	return 0;
}
//Sum of Natural Numbers Using while Loop
