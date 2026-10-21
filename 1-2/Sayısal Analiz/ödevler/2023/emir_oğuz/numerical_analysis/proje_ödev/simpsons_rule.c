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

// Simpson 1/3 Yontemi'nin adimlarini iceren fonksiyon
void simpson13(float coeff[N], float low_lim, float up_lim, int degree, int interval)
{
	int i;
	float x0, x_mid1, x1;
	double h, x0_result, x_mid1Result, x1_result, integral = 0;
	
	h = fabs(up_lim - low_lim) / interval;
	x0 = low_lim;
	
	for(i=1; i<=interval; i++){
		x1 = x0 + h;
		x_mid1 = (x0 + x1) / 2;
		
		x0_result = functionValue(coeff, x0, degree);
		x_mid1Result = functionValue(coeff, x_mid1, degree);
		x1_result = functionValue(coeff, x1, degree);
		
		integral += h * (x0_result + (4 * x_mid1Result) + x1_result) / 6;
		
		x0 = x1;
	}
		
	printf("\n--> RESULT OF SIMPSON'S 1/3 RULE\n");
	printf("Approximate integral value: %.10lf\n", integral);
}

// Simpson 3/8 Yontemi'nin adimlarini iceren fonksiyon
void simpson38(float coeff[N], float low_lim, float up_lim, int degree, int interval)
{
	int i;
	float x0, x_mid1, x_mid2, x1;
	double h, x0_result, x_mid1Result, x_mid2Result, x1_result, integral = 0;
	
	h = fabs(up_lim - low_lim) / interval;
	x0 = low_lim;
	
	for(i=1; i<=interval; i++){
		x1 = x0 + h;
		x_mid1 = x0 + ((x1 - x0) / 3);
		x_mid2 = x0 + (2 * (x1 - x0) / 3);
		
		x0_result = functionValue(coeff, x0, degree);
		x_mid1Result = functionValue(coeff, x_mid1, degree);
		x_mid2Result = functionValue(coeff, x_mid2, degree);
		x1_result = functionValue(coeff, x1, degree);
		
		integral += h * (x0_result + (3 * x_mid1Result) + (3 * x_mid2Result) + x1_result) / 8;
		
		x0 = x1;
	}
		
	printf("\n--> RESULT OF SIMPSON'S 3/8 RULE\n");
	printf("Approximate integral value: %.10lf\n", integral);
}

int main()
{
	int choice, degree, interval;
	float low_lim, up_lim, coeff[N];
	
	printf("--> SIMPSON'S RULE\n\n");
	
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
	
	printf("\nEnter the number 'n' (number of intervals): ");
	scanf("%d", &interval);
	
	printf("\nSelect '1' for Simpson's 1/3 Rule, '2' for Simpson's 3/8 Rule...\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	
	while(choice<1 || choice>2){
		system("cls");
		
		printf("You entered an incorrect value in your selection!\n\n");
		printf("Select '1' for Simpson's 1/3 Rule, '2' for Simpson's 3/8 Rule...\n");
		printf("Your choice: ");
		scanf("%d", &choice);
	}
	
	if(choice == 1){
		simpson13(coeff, low_lim, up_lim, degree, interval);
	}
	else{
		simpson38(coeff, low_lim, up_lim, degree, interval);
	}
	
	getch();
	
	return 0;
}

