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

// Bir 'x' degeri icin polinomun turevinin verecegi degeri bulan fonksiyon
double derivativeValue(float coeff[N], double x, int degree)
{
	int i;
	double result = 0;
	
	for(i=degree; i>=1; i--){
		result += coeff[i] * i * pow(x, i-1);
	}
	
	return result;
}

// Newton-Raphson Yontemi'nin adimlarini iceren fonksiyon
void newtonRaphson(float coeff[N], double error, double x0, int degree)
{
	int iteration = 0;
	double x, x_result, x0_polynomial, x0_derivative, controlValue;
	
	do{
		iteration++;
		
		x0_polynomial = functionValue(coeff, x0, degree); // 'x0' degeri icin polinom degeri hesaplanir.
		x0_derivative = derivativeValue(coeff, x0, degree); // 'x0' degeri icin polinomun turev degeri hesaplanir.
		
		x = x0 - (x0_polynomial / x0_derivative); // 'x' degeri, yontemdeki kurala gore hesaplanir.
		
		controlValue = fabs(x - x0); // Kontrol degeri hesaplanir.
		
		x_result = functionValue(coeff, x, degree); // 'x' degeri icin polinom degeri hesaplanir.
		
		printf("\n%d. ITERATION\n", iteration);	
		printf("- Root value (x%d): %.10lf\n", iteration, x);
		printf("- Function value of root: %.10lf\n", x_result);
		printf("- Control value: %.10lf\n", controlValue);
		
		x0 = x; // Bir sonraki adim icin 'x0' degerine 'x' degeri atanir.
		
	}while(controlValue > error);
	
	printf("\nRESULT:\n");
	printf("The approximate root value was found as %.10lf in a total of %d iterations.\n", x, iteration);
}

int main()
{
	int degree;
	float coeff[N]; 
	double x0, low_lim, up_lim, lowRes, upRes, error;
	
	printf("--> NEWTON-RAPHSON METHOD\n\n");
	
	printf("Enter the degree of the polynomial: ");
	scanf("%d", &degree);
	
	printf("\nEnter the coefficients of the elements of the polynomial in order, from high to low:\n");
	readPolynomial(coeff, degree);
	
	printf("\nThe polynomial you entered: ");
	printPolynomial(coeff, degree);
	
	printf("\n\nEnter a value range...\n");
	printf("Lower limit value: ");
	scanf("%lf", &low_lim);
	printf("Upper limit value: ");
	scanf("%lf", &up_lim);
	
	lowRes = functionValue(coeff, low_lim, degree);
	upRes = functionValue(coeff, up_lim, degree);
	
	while(low_lim > up_lim || lowRes * upRes > 0){
		system("cls");
		
		printf("The polynomial you entered: ");
		printPolynomial(coeff, degree);
		
		printf("\n\nYou have entered an inappropriate value range!\n\n");
		
		printf("Please enter a new value range....\n");
		printf("Lower limit value: ");
		scanf("%lf", &low_lim);
		printf("Upper limit value: ");
		scanf("%lf", &up_lim);
		
		lowRes = functionValue(coeff, low_lim, degree);
		upRes = functionValue(coeff, up_lim, degree);
	}
	
	printf("\nEnter an error value: ");
	scanf("%lf", &error);
	
	printf("\nEnter a starting point: ");
	scanf("%lf", &x0);
	
	newtonRaphson(coeff, error, x0, degree);
	
	getch();
	
	return 0;
}

