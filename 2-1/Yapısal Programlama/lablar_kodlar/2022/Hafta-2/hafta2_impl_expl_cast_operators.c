#include <stdio.h>
#include <limits.h>
/* cd /Users/.../hafta2_codes
cc -o test hafta2_impl_expl_cast_operators.c 
*/
int main() {
  printf("-3 / 4 + 2.5 degeri: %f\n", -3 / 4 + 2.5);
  printf("-3 / 4 + 2.5 degeri: %f\n", -3 / 4.0 + 2.5);
  
  printf("1 + 2.5 degeri: %f\n", 1 + 2.5);
  printf("10u - 15 degeri: %u\n", 10u - 15); 
  
  float f=15; // executed as: float f=15.0;
  int j=5;
  printf("j + f + 2.5 degeri: %2.2f\n", j + f + 2.5);

  j=j + f + 2.5;
  printf("j + f + 2.5 degeri: %d\n", j);
  
  j=2.5;
  printf("j degeri: %d\n", j);
  
  j = 999.888888;
  printf("j degeri: %d---%d\n", j,INT_MAX);

  // explicit conversion:
  int k=3; 
  j=2;
  f=k/j;
  printf("f = k / j degeri: %f\n", f); 

  f=(float)k/j;
  printf("f = k / j degeri: %f\n", f); 
  
  // operators:
  printf("j / k * 3 degeri: %d\n", j / k * 3); 
  printf("'a' degeri: %d\n", 'a'); 
  printf("k –'a' degeri: %d\n", k-'a'); 
  printf("3 + (int) 5.5 degeri: %d\n", 3 + (int) 5.5); 
  printf("3 + (float) 4  degeri: %f\n", 3 + (float) 4 ); 

  double x=1, y=2;
  printf("x / y *5 degeri: %f\n", x / y *5); 
  
  
  // Precedence & associativity (oncelik sirasi ve birlesme ozelligi)
  float z=(3+2)/5*5;
  printf("z=(3+2) / 5*5 degeri: %f\n", z); 
  
  int a,b,c=3;
  a=b=c; // assign c to b, then assign b to a 
  printf("a: %d, b: %d, c: %d\n", a,b,c);
  
  // Operators:
  int m = 3, n = 4;
  x = 2.5, y = 1.0;

  m += n + x - y ; 			printf("m: %d\n", m);
  m = 3, n = 4;
  x = 2.5, y = 1.0;
  m = (m + ((n+x) -y )) ;   printf("m: %d\n", m);

  m = 3, n = 4;  x = 2.5, y = 1.0;
  m /= x * n + y;			printf("m: %d\n", m);
  m = 3, n = 4;  x = 2.5, y = 1.0;
  m = (m / ((x*n) + y ));	printf("m: %d\n", m);

  m = 3, n = 4;  x = 2.5, y = 1.0;  
  n %= (int) y + m;			printf("n: %d\n", n);
  m = 3, n = 4;  x = 2.5, y = 1.0;  
  n = (n % (int)(y + m) ); 	printf("n: %d\n", n);

  m = 3, n = 4;  x = 2.5, y = 1.0;
  x += y -= m;				printf("x: %f\n", x);
  m = 3, n = 4;  x = 2.5, y = 1.0;  
  x = ( x + ( y = (y-m)));	printf("x: %f\n", x);

  return 0;
}
