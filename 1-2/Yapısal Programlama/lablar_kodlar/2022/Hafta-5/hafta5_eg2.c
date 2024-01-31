/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test _hafta6_eg2.c
*/

#include <stdio.h>
int main ()  {
    static int a[2][3]={ {-3, 14, 5} , {1, -10, 9} };
    int i, j=1, k=2; 
     int ncol=3;
    printf("*(a[j] +k) = %d\n", *(a[j] +k) );//9
  //printf("**(a[j+k]) = %d\n", **(a[j+k]) ); // indirection requires pointer operand ('int' invalid)
    printf("(*(a+j))[k] = %d\n", (*(a+j))[k] );//9
  printf("(*(a+k))[j] = %d\n", (*(a+k))[j] ); // a[k][j] a[2][1]
    printf("*(*(a+j) + k) = %d\n", *(*(a+j) + k) );//9
  printf("**(a+j) + k = %d\n", **(a+j) + k ); // a[j][0]+k //3
  printf("*(&a[0][0] + j + k) = %d\n", (&a[0][0] + j + k) ); // adres

   
    printf("*(&a[0][0] + j*3 + k) = %d\n", *(&a[0][0] + j*ncol + k) );//9

    return 0; 
}

