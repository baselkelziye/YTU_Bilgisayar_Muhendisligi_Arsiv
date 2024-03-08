#include <stdio.h>

int KareAlValue(int);
int KareAlRef(int*);
void KupAlRef(int*);

int main(){
	int a;
	int *b;
	a = -9;
	b = &a;
	
	printf("%d^2 -> %d\n", a, KareAlValue(a));
	printf("%d^2 -> %d\n", *b, KareAlRef(b));
	printf("%d^3 -> ", *b);
	KupAlRef(b);
	printf("%d\n", *b);
	
	/*printf("a: %d\n", a);
	printf("&a: %d\n", &a);
	printf("b: %d\n", b);
	printf("*b: %d\n", *b);*/
	
	return 0;
}

int KareAlValue(int k){
	return k * k;
}

int KareAlRef(int* k){
	return *k**k;
}

void KupAlRef(int* k){
	*k = *k * *k * *k;	
}
