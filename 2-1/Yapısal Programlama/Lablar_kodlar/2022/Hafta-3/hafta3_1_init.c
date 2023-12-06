#include <stdio.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta3_codes
cc -o test hafta3_1_init.c 
*/

int main() {
  int a_ar[5]={1, 2, 3, 4, 5, 6};
  int b_ar[5] = {1, 2, 3.5, 4, 5};
  int c_ar[5] = {1, 2, 3};
  char d_ar[] = {'a', 'b', 'c', 'd'};

  for (int i=0; i<5; i++)
  	printf("i-th value: %d\t", a_ar[i]);
  printf("\n");
  
  for (int i=0; i<5; i++)
  	printf("i-th value: %d\t", c_ar[i]);
  printf("\n");

  for (int i=0; i<5; i++)
  	printf("i-th value: %d\t", b_ar[i]);
  printf("\n");

  short ar[4]={10, 20, 30, 40};
  short *p;
  p = &ar[0]; // assigns the address of array element 0 to p.
  printf("*(p+3): %d; ar[3]: %d\n", *(p+3), ar[3]);
  p = ar; // is same as above assignment! 
  printf("*(p+3): %d; ar[3]: %d\n", *(p+3), ar[3]);

  return 0;
}
