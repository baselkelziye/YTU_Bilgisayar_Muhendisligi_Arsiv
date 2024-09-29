#include <stdio.h>
int main(){
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	while(n!=0){
		tutucu=sayi%10;
		digit=digit*10+tutucu;
		sayi=sayi/10;
	}
	printf("ters cevrilmis sayimiz=%d",digit);
	return 0;
}
//bir sayiyi ters cevirme
