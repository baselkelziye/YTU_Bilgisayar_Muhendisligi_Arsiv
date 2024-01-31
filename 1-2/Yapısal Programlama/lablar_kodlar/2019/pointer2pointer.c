#include <stdio.h>
int main()
{
	int a=20;
	int *b=&a;
	int **c=&b;
	printf("%d %d %d",a,*b,**c);

	return 0;
}
