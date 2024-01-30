#include <stdio.h>

int main(){

int a = 10;
int b = 4 , c = 5;//virgül kullandýk...
double z = 4.23;
float y = 2.6;
char f = 'X';
char g = 42;

printf("%d\n", a);
printf("\n\t%d %d %f %f %c %c%s", b, c, z, y, f, g, "Naber lan tirrek\n");

a = 99; b = 88; c = 74;//Noktalý virgül kullandýk...

printf("%d %d %d\n",a , b, c);
a = 11; b = 5; c = 6;
printf("%d %d %d\n", a, b, c);

int x;
printf("Bir sayi giriniz : ");
scanf("%d", &x);
printf("Girilen sayi : %d", x);

printf("\n%d\n", sizeof(int));
printf("%d byte\n", sizeof(double));
printf("%d\n", sizeof(float));
printf("%d byte\n", sizeof(char));
printf("%d byte\n", sizeof(long int));

return 0;
}

