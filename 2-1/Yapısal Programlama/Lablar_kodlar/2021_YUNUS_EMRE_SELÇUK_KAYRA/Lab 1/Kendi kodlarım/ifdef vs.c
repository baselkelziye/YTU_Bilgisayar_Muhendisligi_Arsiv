#include <stdio.h>
#include <stdlib.h>
#define size 100
#define merhaba 15
int main(){
	printf("%d\n",size);
	printf("%d\n",merhaba);
#if size==1
	#undef size
	#define size 99
#elif merhaba==10
	#undef merhaba
	#define merhaba 15
#else
	#undef merhaba
	#define merhaba 25
#endif
	printf("%d\n",size);
	printf("%d\n",merhaba);

}
