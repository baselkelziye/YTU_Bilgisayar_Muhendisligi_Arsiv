/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test _hafta6_eg3.c
*/

#include <stdio.h>int main ()  {    unsigned short int a, b;

    a=0x24A5; b=0x0452;    printf("a=%hx\tb=%hx\ta&b=%hx\tdecimal=%hd\n", a, b, a&b, a&b);

    a=0x2A65; b=0x5722;    printf("a=%hx\tb=%hx\ta|b=%hx\tdecimal=%hd\n", a, b, a|b, a|b);

    a=0x32BC; b=0x36DE;    printf("a=%hx\tb=%hx\ta^b=%hx\tdecimal=%hd\n", a, b, a^b, a^b);

    a=0xDB29;    printf("a=%hx\t~a=%hx\tdecimal=%hd\n", a, ~a, ~a);

    a=0x0452; b=a>>5;    printf("a=%hx\ta>>5=%hx\tdecimal=%hd\n", a, b, b);

    a=0x0452; b=a<<5;    printf("a=%hx\ta<<5=%hx\tdecimal=%d\n", a, b, b);
 
    return 0; 
}