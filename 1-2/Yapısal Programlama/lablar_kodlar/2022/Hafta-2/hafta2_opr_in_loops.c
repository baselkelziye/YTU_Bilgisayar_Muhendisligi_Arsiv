#include <stdio.h>
// cd /Users/.../hafta2_codes
// cc -o test hafta2_opr_in_loops.c 
struct Complex{
    float r;
	float i;
	int j;	
};
int main ()  {
    int a[] = {8,0,1,2,3,4,6};
    int x= sizeof(a);
    int y= sizeof(a[0]);
    printf("%d -- %d -- %d\n",x,y,x/y);
	int j, k;
	int count=0;
	for (j = 0, k = 100; k-j > 0; j++, k-- ){
		//printf("j: %d\t, k:%d\n", j, k);
		count++;
	}
	printf("count: %d\n", count);
	
	printf("sizeof(3+5): %lu\n", sizeof(3+5));
    	printf("sizeof(short): %lu\n", sizeof(short));
    	printf("sizeof(int): %lu\n", sizeof(int));
    	printf("sizeof(long): %lu\n", sizeof(long));
	printf("sizeof(float): %lu\n", sizeof(float));
	printf("sizeof(double): %lu\n", sizeof(double));
    printf("szeof(struct Complex):%d",sizeof(struct Complex));
	return 0;
}
