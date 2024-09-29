#include <stdio.h>
#include <conio.h>
	
int fakt (int a)
{
 if (a==1) return 1;
 else return a*fakt(a-1);
}

int main(int argc, char* argv[])
{
 int N;
 scanf("%d",&N);
 printf("faktoriyeli=%d",fakt(N));
 getch();
 return 0;
}
