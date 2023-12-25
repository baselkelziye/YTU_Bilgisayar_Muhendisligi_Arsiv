#include <stdio.h>
#include <conio.h>

double f(double x);
int main() {
	double a,b,c;
	a = 1.75;
	b = 2.5;
	c = (a+b)/2;
	while(f(c) == 0 || f(c) < 0.007){
		c = (a+b)/2;
		printf("%f %f %f %f %f %f\n",a,f(a),b,f(b),c,f(c));
		if(f(a)*f(c) < 0){
			b = c;
		}
		if(f(b)*f(c) < 0){
			a = c;
		}
		if(f(c) < 0){f(c) = f(c) * -1;}
	}
	
	
	
	
	getch();
	return 0;
}
double f(double x){
	double result;
	
	result = (x*x*x)-(6.5*(x*x))+(13.5*x)-9;	
	
	
	return result;
}
