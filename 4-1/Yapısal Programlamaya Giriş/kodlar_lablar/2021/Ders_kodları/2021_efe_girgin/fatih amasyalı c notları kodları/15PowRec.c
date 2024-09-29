#include <stdio.h>  
/* O(n) */
int powRv1(int x,int y)
{
	if (y==0)
		return 1;
	else
		return x*powRv1(x,y-1);		
}
/* O(logn)*/
int powRv2(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = powRv2(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main()
{
	int x=2,y=7;
	printf("%d\n",powRv1(x,y));
	printf("%d\n",powRv2(x,y));
}

