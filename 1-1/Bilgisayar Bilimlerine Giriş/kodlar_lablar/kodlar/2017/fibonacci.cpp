#include<stdio.h>
#include<stdlib.h>
int fonk(int x,int y,int n)
{
if(n==1) return y;
else return fonk(y,y+x,n-1);
}
int main()
{
printf("sayiyi giriniz...");
int n;
scanf("%d",&n);
printf("\n%d",fonk(1,1,n));
scanf("%d",&n);
}
