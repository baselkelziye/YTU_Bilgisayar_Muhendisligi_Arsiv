#include <stdio.h>
int main(){
	int sayi, a, b, c;
	//printf("Hello World!\n");
	//printf("Bir sayi giriniz: ");
	/*scanf("%d", &sayi);
	printf("Girilen sayi: %d\n", sayi); */
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	c = a + b;
	printf("c: %d\n\a", c);
	//printf("c: %d\n", a + b);
	printf("c+1: %d\n", c + 1);
	printf("c+1: %d\n", c++);
	printf("c+1: %d\n", ++c);
	return 0;
}
