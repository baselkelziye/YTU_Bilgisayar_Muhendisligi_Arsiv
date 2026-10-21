#include <stdio.h>
#include <stdlib.h>
#include "macro.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	srand(time(NULL));
	int ages[10];
	int i,j,k;
	for(i=0;i<10;i++){
		ages[i] = rand() % 30 +1;
	}
	printf("dizi\n");
	for(i=0;i<10;i++){
		printf("%d  ",ages[i]);
	}
	function(ages);
	return 0;
}
