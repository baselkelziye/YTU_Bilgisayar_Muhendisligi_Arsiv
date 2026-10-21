#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    double coef;
    int exp;
} TERM;

typedef struct ordinaryDifferantialEquention {
	double coefDerivativeY;
	double coefY;
    TERM *t;
    int n;
} ODE;

ODE getDifferantialEquation(ODE ode);
void writeODE(ODE ode);
double calculateODE(ODE ode, double x, double y);
void rungeKuttaMethod(ODE ode);

int main() {
	ODE ode;
	
	ode = getDifferantialEquation(ode);
    writeODE(ode);
    
	rungeKuttaMethod(ode);
    
    return 0;
}

ODE getDifferantialEquation(ODE ode) {
	int i;
	
	printf("differantial equation: ay' = by + Q(x)\n");
	
	printf("enter a: ");
	scanf("%lf", &ode.coefDerivativeY);
	
	printf("enter b: ");
	scanf("%lf", &ode.coefY);
	
	printf("Number of elements in Q(x): ");
	scanf("%d", &ode.n);
	
	ode.t = (TERM*)malloc((2 + ode.n) * sizeof(TERM));
	
	for (i = 0; i < ode.n; i++) {
		printf("coefficent of %d. element: ", i+1);
		scanf("%lf", &ode.t[i].coef);
		
		printf("exponent of %d. element: ", i+1);
		scanf("%d", &ode.t[i].exp);
	}
	
	return ode;
}

void writeODE(ODE ode) {
	int i;
	
	printf("Ordinary Differantial Equation: ");
	
	printf("%2.2fy' = %2.2fy + ", ode.coefDerivativeY, ode.coefY);
	
	for (i = 0; i < ode.n - 1; i++) {
		printf("%2.2fx^%d + ", ode.t[i].coef, ode.t[i].exp);
	}
	printf("%2.2fx^%d\n", ode.t[i].coef, ode.t[i].exp);
}

double calculateODE(ODE ode, double x, double y) {
	int i, j;
	
	double temp, result = 0;
	
	for (i = 0; i < ode.n; i++) {
		temp = 1;
		for (j = 0; j < ode.t[i].exp; j++) {
			temp *= x;
		}
		temp *= ode.t[i].coef;
		result += temp;
	}
	result += ode.coefY * y;
	result /= ode.coefDerivativeY;
	
	return result;
}

void rungeKuttaMethod(ODE ode) {
	double k1, k2, k3, k4, h, xi, yi, x;
	int i;
	
	printf("initial values: \n");
	
	printf("enter x0: ");
	scanf("%lf", &xi);
	
	printf("enter y(%2.2lf): ", xi);
	scanf("%lf", &yi);
	
	printf("enter h: ");
	scanf("%lf", &h);
	
	printf("enter x that you want to find y(x): ");
	scanf("%lf", &x);
	
	i = 0;
	while (xi < x) {
		k1 = calculateODE(ode, xi, yi);
		k2 = calculateODE(ode, xi + h / 2, yi + k1 * h / 2);
		k3 = calculateODE(ode, xi + h / 2, yi + k2 * h / 2);
		k4 = calculateODE(ode, xi + h, yi + k3 * h);
		
		yi += (k1 + 2 * k2 + 2 * k3 + k4) * h / 6;
		xi += h;
		
		printf("%d. iteration: x = %lf, y = %lf\n", i + 1, xi, yi);
		i++;
	}
	
	printf("estimated y(%2.2f) = %lf", xi, yi);

}
