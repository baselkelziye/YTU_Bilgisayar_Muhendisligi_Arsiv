// Buyuk ya da kucuk harf olup olmadýðýna bakmaksýzýn verilen karaktere gore islem yapan program
#include <stdio.h>
int main()
{
	char x;
	int a=3,b=5,c;
	printf("Bir karakter giriniz\n");
	scanf("%c",&x);
	switch (x)		//switch ile verilen ifade char, int, short tipinde olabilir
	{
		//case ile verilen ifade SABIT olmalýdýr
		case 'a':	//x='a' ise alttaki iþlemi gerçekler ve break ile çýkar
		case 'A':c=a+b; printf("Addition      :%d",c); break;	
		case 's':
		case 'S':c=a-b; printf("Substraction  :%d",c); break;
		case 'm':
		case 'M':c=a*b; printf("Multiplication:%d",c); break;
		default : 		printf("Invalid operand"); 	
	}
}
