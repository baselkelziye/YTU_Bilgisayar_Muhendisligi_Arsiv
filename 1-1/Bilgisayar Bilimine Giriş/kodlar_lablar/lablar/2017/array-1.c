#include<stdio.h>

int main(){
	int dizi[5] = {7,3,4,2}; //we defined 5 indices array what would be the last value ?
	printf("%d\n",dizi[99]);
	int x;
	x = dizi[dizi[4]]/3 + dizi[3]; //dizi[0]/3 --> 7/3 + 2 = 4
	x = dizi[x-3]++;
	printf("%d\n", x);
	x=dizi[3];
	printf("\n", x);
	printf("%d\n", dizi[dizi[x]-1]);
	return 0;
}
