#include <stdio.h>

int toplama(int, int);

int main(){
	int a, b;
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("%d + %d = %d\n", a, b, toplama(a, b));
	return 0;
}

int toplama(int y, int z){
	return y + z;
}

