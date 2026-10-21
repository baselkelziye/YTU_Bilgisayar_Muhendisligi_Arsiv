#include <stdio.h>
#include <math.h>
#define N 10

// Polinomdaki elemanlarin katsayilarini kullanicidan alan fonksiyon
void readPolynomial(float coeff[N], int degree)
{
	int i;
	
	for(i=degree; i>=0; i--){
		printf("Coefficient of x^%d ---> ", i);
		scanf("%f", &coeff[i]);
	}
}

// Kullanicinin girdigi katsayilara gore polinomu yazdiran fonksiyon
void printPolynomial(float coeff[N], int degree)
{
	int i;
	
	for(i=degree; i>=0; i--){
		
		if(coeff[i] != 0 && i != 0){
			printf("[(%.3f)x^%d]", coeff[i], i);
		}
		else if(coeff[i] != 0 && i == 0){
			printf("[%.3f]", coeff[i]);
		}
		
		if(coeff[i-1] != 0 && i != 0){
			printf(" + ");
		}
	}
}

// Bir 'x' degeri icin polinomun verecegi degeri bulan fonksiyon
double functionValue(float coeff[N], double x, int degree)
{
	int i;
	double result = 0;
	
	for(i=degree; i>=0; i--){
		result += coeff[i] * pow(x, i);
	}
	
	return result;
}

// Trapez Yontemi'nin adimlarini iceren fonksiyon
void trapezoidal(float coeff[N], float low_lim, float up_lim, int degree, int trapezoid)
{
	int i;
	float x0, x1;
	double h, x0_result, x1_result, integral = 0;
	
	h = fabs(up_lim - low_lim) / trapezoid;
	x0 = low_lim;
	
	for(i=1; i<=trapezoid; i++){
		x1 = x0 + h;
		
		x0_result = functionValue(coeff, x0, degree);
		x1_result = functionValue(coeff, x1, degree);
		
		integral += h * (x0_result + x1_result) / 2;
		
		x0 = x1;
	}
	
	printf("\nApproximate integral value: %.10lf\n", integral);
}

int main()
{
	int degree, trapezoid;
	float low_lim, up_lim, coeff[N];
	
	printf("--> TRAPEZOIDAL RULE\n\n");
	
	printf("Enter the degree of the polynomial for which you want the approximate integral value to be calculated: ");
	scanf("%d", &degree);
	
	printf("\nEnter the coefficients of the elements of the polynomial in order, from high to low:\n");
	readPolynomial(coeff, degree);
	
	printf("\nThe polynomial you entered: ");
	printPolynomial(coeff, degree);
	
	printf("\n\nEnter the lower and upper limit values of the integral...\n");
	printf("Lower limit value: ");
	scanf("%lf", &low_lim);
	printf("Upper limit value: ");
	scanf("%lf", &up_lim);
	
	printf("\nEnter the number 'n' (number of trapezoids): ");
	scanf("%d", &trapezoid);
	
	trapezoidal(coeff, low_lim, up_lim, degree, trapezoid);
	
	getch();
	
	return 0;
}

