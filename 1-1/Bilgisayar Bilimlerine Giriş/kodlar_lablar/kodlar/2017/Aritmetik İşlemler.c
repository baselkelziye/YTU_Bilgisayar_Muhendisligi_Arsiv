#include <stdio.h>
//x%y x'in y'ye b�l�m�nden kalan� verir.
//-x x'i - ile �arpar.
int main(){

int x = 9, y = 4;
double z = 8.99;

printf("%d\n", x+y);
printf("%.2f", x*z);//virg�lden sonra 2 tane say� g�rmek istiyorum.
printf("\n%f\n", z/y);
printf("%d", x-y);
printf("\n%d\n", 2+3%4);
printf("%d", 2%3/4);

return 0;
}

