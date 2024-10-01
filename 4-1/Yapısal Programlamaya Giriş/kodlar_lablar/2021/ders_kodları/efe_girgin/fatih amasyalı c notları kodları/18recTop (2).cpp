#include <stdio.h>
#include <conio.h>
	
int top(int x)
{
 if (x==1) return 1;
 else return x+top(x-1);
}

int main(int argc, char* argv[])
{
 int N;
 scanf("%d",&N);
 printf("top=%d",top(N));
 getch();
 return 0;
}
