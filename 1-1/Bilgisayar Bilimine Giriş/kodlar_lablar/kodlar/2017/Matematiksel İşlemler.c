#include <stdio.h>

int main(){

int a = 10, b = 3;

printf("%d\n", a+b); //13
printf("%d", a<<2); //40
printf("\n%d", a>>2); //2
printf("\n%d", a+b*2); //16
printf("\n%d", a%b); //1
printf("\n%d", a==b); //0
printf("\n%d", a>b); //1
printf("\n%d", a++); //10
printf("\n%d", ++a); //12

return 0;
}
