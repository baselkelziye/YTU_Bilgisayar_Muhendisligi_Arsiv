#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta4_codes
cc -o test hafta4_3_recrsv1.c 
*/

// loops forever:
/*
void recurse (int count)  {	printf("%d\n", count);	count++;	recurse(count);}
*/

// loops until a threshold
void recurse (int count)  {	printf("%d\n", count);	count++;
	if(count<101)		recurse(count);
	else{
		printf("The recursive function broke the infinite loop now\n");
	}		}
int main()  {
	int count=1;	recurse(count);
	return 0;}