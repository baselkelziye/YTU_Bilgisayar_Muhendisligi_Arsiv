/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test _hafta6_eg5.c
*/

#include <stdio.h>

int f1(){
    static int i=1;
    static int k=0;
    k++;
    return k;
}
void f2()
{
    int a = 10;
    static int sa = 10;
    a += 5;
    sa += 5;
    printf("a = %d, sa = %d\n", a, sa);
}

int c=0;
static int sc=0;

void f3() {
    c++;
    sc++;
    printf("c = %d\n", c);
    printf("sc = %d\n", sc);
}
int main ()  {    int i=0;

    printf("i: %d\n", i);
/*    printf("k: %d\n", f1());    printf("k: %d\n", f1());    printf("k: %d\n", f1());    int k=0;
    printf("k: %d\n", k);
    printf("k: %d\n", f1());    printf("k: %d\n", f1());    

    printf("sc: %d\n", sc);
    for (i = 0; i < 10; ++i)
	f2();
*/  
    f3();
    f3();
    f3();

    return 0; 
}