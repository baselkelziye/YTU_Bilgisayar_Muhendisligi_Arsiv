// Buyuk ya da kucuk harf olup olmad���na bakmaks�z�n verilen karaktere gore islem yapan program
#include <stdio.h>
int main()
{
	char x;
	int a=3,b=5,c;
	printf("Bir karakter giriniz\n");
	scanf("%c",&x);
	switch (x)		//switch ile verilen ifade char, int, short tipinde olabilir
	{
		//case ile verilen ifade SABIT olmal�d�r
		case 'a':	//x='a' ise alttaki i�lemi ger�ekler ve break ile ��kar
		case 'A':c=a+b; printf("Addition      :%d",c); break;	
		case 's':
		case 'S':c=a-b; printf("Substraction  :%d",c); break;
		case 'm':
		case 'M':c=a*b; printf("Multiplication:%d",c); break;
		default : 		printf("Invalid operand"); 	
	}
}
