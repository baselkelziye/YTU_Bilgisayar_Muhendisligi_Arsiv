#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//dependent variables in ODE
typedef struct derivative{
	double coefficient;
	double currentValue;
	double k1, k2, k3, k4;
}DERIVATIVE;

//independent variables in ODE
typedef struct polynomial{
	int degree;
	double coefficient;
}POLYNOMIAL;

//ODE is in this format: a(m) * y(m) + a(m-1) * y(m-1) + ..... + a(1) * y(1) + a(0) * y(0) = b(n) * x(n) + b(n-1) * x(n-1) + .... + b(0) * x(0)
//m is the order of the ODE and n is the number of terms in the polynomial that consists of only independent variables 

typedef struct de{
	int m; // the order of DE
	DERIVATIVE* derivatives;
	int n; // the number of terms in polynomial
	POLYNOMIAL* polynomial;
}DE;

DE takeDifferantialEquation();
double calculatePolynomial(double x, POLYNOMIAL* polynomial, int n);
void rungeKutto4(DE de);
void printDifferantialEquation(DE de);

int main(){
	int c1, c2 = 1;
	DE de;
	do{
		if(c2){
			de = takeDifferantialEquation();
			printDifferantialEquation(de);
		}
		rungeKutto4(de);
		printf("\nenter 1 if you want to continue\nenter 0 to exit\nanswer: ");
		scanf("%d", &c1);
		if(c1){
			printf("\nenter 1 if you want to give a new ODE to calculate\nenter 0 if you want to use the same ODE\nanswer: ");
			scanf("%d", &c2);
		}
	} while(c1);
	
	return 0;
}

/*
When we have an nth order ODE, to apply runge kutta 4 method to this ODE we need to use order reduction because we can apply this method only to first order ODEs
When we have an ODE like this -> 2y'' - 3y' + y = P(x); for y = z1, y' = z1' = z2, y'' = z2' = (3y' - y + P(x)) / 2 = (3 * z2 - z1 + P(x)) / 2.
After that we now have 2 first order equations so we can apply our method to these 2 ODEs.
In runge kutta method we first find k1, k2, k3 and k4 of first order variable and use these results to update 0th order variable in every iteration.
So for 2 first order equations that are connected with each other by some variables, we first calculate k1 of y' = z1' = z2 and after that
do the same for y'' = z2' = (3 * z2 - z1 + P(x)) / 2 after that calculate k2 for these two and so on. We do this because we will need k1 of first equation
when calculating k2 of second equation and vice versa and same for k3 and k4. And at the end of the iteration, we will update the value of 0th order variable
by using k1, k2, k3 and k4 of 1st order variable. Same for 1st and 2nd order variables. 
*/

void rungeKutto4(DE de){
	double x0, x, y0, realY, h;
	int i, j, iter, ctrl = 0;
	
	printf("\ninitial x value (x0): ");
	scanf("%lf", &x0);
	
	//getting the initial values of dependent values from 0th order to (m-1)th order for initial x value...
	for(i=0;i<de.m;i++){
		printf("\nwhat is the value of %d.th order derivative for %.2lf (x0): ", i, x0);
		scanf("%lf", &de.derivatives[i].currentValue);
	}
	
	y0 = de.derivatives[0].currentValue;
	
	printf("\ntarget x value: ");
	scanf("%lf", &x);
	
	printf("\nenter 1 if you have the real value of function for target x value: ");
	scanf("%d", &ctrl);
	
	if(ctrl){
		printf("\nreal y value for target x: ");
		scanf("%lf", &realY);
	}
	
	printf("\nstep size (it would be good to converge if you enter a value close to 0.1): ");
	scanf("%lf", &h);

	iter = (int) (fabs(x - x0) / h); //finding the number of iterations  
	
	if(x0 > x) h *= -1; 
	
	for(i=1;i<=iter;i++){
		//finding k1 of each derivative from 1st order to mth order
		for(j=1;j<de.m;j++){
			de.derivatives[j].k1 = h * de.derivatives[j].currentValue;
		}
		
		de.derivatives[de.m].k1 = calculatePolynomial(x0, de.polynomial, de.n);
		for(j=0;j<de.m;j++){
			de.derivatives[de.m].k1 -= de.derivatives[j].currentValue * de.derivatives[j].coefficient;
		}
		de.derivatives[de.m].k1 *= h / de.derivatives[de.m].coefficient;
		
		//finding k2 of each derivative from 1st order to mth order
		for(j=1;j<de.m;j++){
			de.derivatives[j].k2 = h * (de.derivatives[j].currentValue + 0.5 * de.derivatives[j+1].k1);
		}
		
		de.derivatives[de.m].k2 = calculatePolynomial(x0 + 0.5 * h, de.polynomial, de.n);
		for(j=0;j<de.m;j++){
			de.derivatives[de.m].k2 -= (de.derivatives[j].currentValue + 0.5 * de.derivatives[j+1].k1) * de.derivatives[j].coefficient;
		}
		de.derivatives[de.m].k2 *= h / de.derivatives[de.m].coefficient;
		
		//finding k3 of each derivative from 1st order to mth order
		for(j=1;j<de.m;j++){
			de.derivatives[j].k3 = h * (de.derivatives[j].currentValue + 0.5 * de.derivatives[j+1].k2);
		}
		
		de.derivatives[de.m].k3 = calculatePolynomial(x0 + 0.5 * h, de.polynomial, de.n);
		for(j=0;j<de.m;j++){
			de.derivatives[de.m].k3 -= (de.derivatives[j].currentValue + 0.5 * de.derivatives[j+1].k2) * de.derivatives[j].coefficient;
		}
		de.derivatives[de.m].k3 *= h / de.derivatives[de.m].coefficient;
		
		//finding k4 of each derivative from 1st order to mth order
		for(j=1;j<de.m;j++){
			de.derivatives[j].k4 = h * (de.derivatives[j].currentValue + de.derivatives[j+1].k3);
		}
		
		de.derivatives[de.m].k4 = calculatePolynomial(x0 + h, de.polynomial, de.n);
		for(j=0;j<de.m;j++){
			de.derivatives[de.m].k4 -= (de.derivatives[j].currentValue + de.derivatives[j+1].k3) * de.derivatives[j].coefficient;
		}
		de.derivatives[de.m].k4 *= h / de.derivatives[de.m].coefficient;

		//updating the value of each derivative for current x from 0th order to (m-1)th order
		for(j=0;j<de.m;j++){
			de.derivatives[j].currentValue += (de.derivatives[j+1].k1 + 2 * de.derivatives[j+1].k2 + 2 * de.derivatives[j+1].k3 + de.derivatives[j+1].k4) / 6.0;
		}
		
		x0 += h;
		
		printf("%3.d. iteration x: %lf - y: %lf\n", i, x0, de.derivatives[0].currentValue);
	}
	
	printf("\nresult for %.2lf: %lf", x, de.derivatives[0].currentValue);
	if(ctrl) printf("\nabsolute error: %lf", fabs(de.derivatives[0].currentValue - realY));
}

//function to take dependent variables first and independent variables after.
DE takeDifferantialEquation(){
	int i;
	DE de;
	do{
		printf("\nThe order of the differantial equation: ");
		scanf("%d", &de.m);
		if(de.m < 1) printf("Order cannot be less than 1...\n");
	} while(de.m < 1);
	
	de.derivatives = (DERIVATIVE*) malloc((de.m+1) * sizeof(DERIVATIVE));
	
	for(i=de.m;i>=0;i--){
		printf("\nthe coefficient of %d.th order derivative: ", i);
		scanf("%lf", &de.derivatives[i].coefficient);
	}
	
	do{
		printf("\nhow many elements are there in the polynomial: ");
		scanf("%d", &de.n);
		if(de.n <= 0) printf("\nInvalid value...\n");
	} while(de.n <= 0);
	
	de.polynomial = (POLYNOMIAL*) malloc(de.n * sizeof(POLYNOMIAL));
	
	for(i=0; i<de.n; i++){
		printf("\nthe coefficient of %d.th value: ", i+1);
		scanf("%lf", &de.polynomial[i].coefficient);
		do{
			printf("\nthe degree of %d.th value: ", i+1);
			scanf("%d", &de.polynomial[i].degree);
			if(de.polynomial[i].degree < 0) printf("\nthe degree of a term cannot be less than 0...");
		} while(de.polynomial[i].degree < 0);
	}
	
	return de;
}

//calculating the polynomial that consists of only independent variables
double calculatePolynomial(double x, POLYNOMIAL* polynomial, int n){
	int i, j;
	double sum = 0.0, temp = 1.0;
	for(i=0; i<n; i++){
		temp = 1.0;
		for(j=0; j<polynomial[i].degree; j++){
			temp = temp * x;
		}
		sum += polynomial[i].coefficient * temp;
	}
	return sum;
}

void printDifferantialEquation(DE de){
	int i, j;
	double temp1, temp2;
	
	//sorting the polynomial
	for(i=1;i<de.n;i++){
		j = i-1;
		temp1 = de.polynomial[i].degree;
		temp2 = de.polynomial[i].coefficient;
		while(j >= 0 && de.polynomial[j].degree < temp1){
			de.polynomial[j+1].degree = de.polynomial[j].degree;
			de.polynomial[j+1].coefficient = de.polynomial[j].coefficient;;
			j--;
		}
		de.polynomial[j+1].degree = temp1;
		de.polynomial[j+1].coefficient = temp2;
	}
	
	printf("\nLinear Differantial Equation...\n\n");
	for(i=de.m;i>0;i--){
		printf("(%.2lf)y(%d) + ", de.derivatives[i].coefficient, i);
	}
	
	printf("(%.2lf)y(0) = ", de.derivatives[0].coefficient);
	for(i=0;i<de.n - 1;i++){
		printf("(%.2lf)x^%d + ", de.polynomial[i].coefficient, de.polynomial[i].degree);
	}
	printf("(%.2lf)x^%d\n", de.polynomial[de.n-1].coefficient, de.polynomial[de.n-1].degree);
}
