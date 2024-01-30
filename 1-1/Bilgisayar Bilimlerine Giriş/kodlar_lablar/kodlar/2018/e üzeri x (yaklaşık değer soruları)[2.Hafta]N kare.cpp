#include <stdio.h>
#include <conio.h>


int main() {
	int N;int x;printf("Terim sayisini giriniz ve e uzeri ussu giriniz : ");scanf("%d",&N);scanf("%d",&x);	
	double T = 1;
	for(int i = 1; i <= N; i++){
		double k = 1;
		for(int j = 1; j <= i; j++){
			k = k * x;
		}
		double f = 1;
		for(int j = 1; j <= i; j++){
			f = f * j;
		}
		T = T + (k/f);
	}
	printf("%f",T);
	
	getch();
	return 0;
}
