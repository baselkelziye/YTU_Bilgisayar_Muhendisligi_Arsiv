/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test _hafta6_eg1.c
*/

#include <stdio.h>int main ()  {    static int a[2][3]={ {-3, 14, 5} , {1, -10, 8} };
    static int *b[]={ a[0], a[1] };
    int *p=b[1];

    printf("*b[1] = %d\n", *b[1]);
    printf("*(++p) = %d\n", *(++p));
    printf("*(*(a+1)+1) = %d\n",  *(*(a+1)+1) );

    // yukaridaki ++p'y' geri alalim, ilk degeri olan b[1]'yi atayalım: 
    p=b[1];
    printf("*(--p-2) = %d\n",  *(--p-2) );

    for(int i=0; i<2; i++) printf("a: %d \t", *a[i]);
    printf("\n");
    return 0; 
}