#include <stdio.h>
#define my_sum(a,b) (a+b) // macro definition
int main()
{
	int a=3, b=4; //Numbers for summation
	printf("Result: %d\n", my_sum(a,b));
	return 0;
}
