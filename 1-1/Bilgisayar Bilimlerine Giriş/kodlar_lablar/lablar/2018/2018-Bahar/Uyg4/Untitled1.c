#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.1415926535897

void deney(int m);
int main(){
	srand(time(NULL));
	int i;
	for(i = 10; i < 50; i++){
		deney(i);
	}
	for(i = 1; i <= 8; i++){
		deney(pow(10,i));//Math.pow(10,i) denersin
	}
	
}
double rastgele(){
	return (double)rand()/RAND_MAX;//[0,1]
}

void deney(int m){
	double x,y,mypi;
	int i;
	int n = 0;
	clock_t start,stop;
	start = clock();
	for(i = 1; i < m; i++){
		x = rastgele();
		y = rastgele();
		if((x*x+y*y) <= 1){
			n++;
		}
	}
	
	mypi = (double)4.0*n/m;//*1.0 yaparsan double a da dönüþür
	stop = clock();
	printf("\ndeney sayisi %d, ---- Sonuc : %f, ---- Zaman : %d\n",m,mypi,stop-start);
}
