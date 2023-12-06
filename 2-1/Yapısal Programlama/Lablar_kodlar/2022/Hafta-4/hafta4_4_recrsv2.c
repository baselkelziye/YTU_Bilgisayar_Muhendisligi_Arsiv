#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta4_codes
cc -o test hafta4_4_recrsv2.c 
*/

int fact( int n )  {	if( n <= 1 )		return 1;	else  		return n*fact(n-1);}int main()  {	printf("7! is %d\n", fact(7) );}