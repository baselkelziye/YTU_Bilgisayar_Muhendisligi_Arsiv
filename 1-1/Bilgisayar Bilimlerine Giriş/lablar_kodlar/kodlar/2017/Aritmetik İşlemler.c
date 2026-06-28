#include <stdio.h>
//x%y x'in y'ye bölümünden kalaný verir.
//-x x'i - ile çarpar.
int main(){

int x = 9, y = 4;
double z = 8.99;

printf("%d\n", x+y);
printf("%.2f", x*z);//virgülden sonra 2 tane sayý görmek istiyorum.
printf("\n%f\n", z/y);
printf("%d", x-y);
printf("\n%d\n", 2+3%4);
printf("%d", 2%3/4);

return 0;
}

