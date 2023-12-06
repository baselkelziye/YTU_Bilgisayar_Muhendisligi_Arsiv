#include <stdio.h>
// cd /Users/.../hafta2_codes
// cc -o test hafta2_operators2.c 

/*
int main ()  {
	int j=5, k=5;
	printf("j: %d\t k : %d\n", j++, k--);
	printf("j: %d\t k : %d\n", j, k);
	return 0;
}
*/

int main ()  {
	int j=5, k=5;
	printf("j: %d\t k : %d\n", ++j, --k);
	printf("j: %d\t k : %d\n", j, k);
	
	int m=1, n;
	n=m++ * m++;
	printf("m++ * m++ : %d\n", n);
	printf("m=%d",m);
	return 0;
}
