#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double r2();
int main() {
	srand(time(NULL));
	
	int count = 0;
	for(double i = 0; i <= 1000000; i++){
		int x = r2();
		int y = r2();
		
		if( (x*x)+(y*y)<1 ){
			count++;
		}
	}
	printf("%d\n",count);
	double T = (4*(count/1000000));
	printf("%lf",T);
	
		
	return 0;
}

double r2()
{
    return (double)rand() / (double)2 ;
}
