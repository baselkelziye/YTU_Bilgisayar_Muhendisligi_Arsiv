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

// Sayisal Turev Yontemi'nin adimlarini iceren fonksiyon
double finiteDiff(float coeff[N], float x, float h, int degree)
{
	float x1, x2;
	double x_result, x1_result, x2_result, derivative;
	
	x1 = x - h;
	x2 = x + h;
	
	x_result = functionValue(coeff, x, degree); // 'x' icin fonksiyon degeri hesaplanir.
	x1_result = functionValue(coeff, x1, degree); // 'x-h' icin fonksiyon degeri hesaplanir.
	x2_result = functionValue(coeff, x2, degree); // 'x+h' icin fonksiyon degeri hesaplanir.
	
	derivative = (x_result - x1_result) / h;
	printf("\n--> NUMERICAL DIFFERENTIATION WITH BACKWARD DIFFERENCE\n");
	printf("Approximate derivative value: %.10lf\n", derivative);
	
	derivative = (x2_result - x_result) / h;
	printf("\n--> NUMERICAL DIFFERENTIATION WITH FORWARD DIFFERENCE\n");
	printf("Approximate derivative value: %.10lf\n", derivative);
	
	derivative = (x2_result - x1_result) / (2 * h);
	printf("\n--> NUMERICAL DIFFERENTIATION WITH CENTRAL DIFFERENCE\n");
	printf("Approximate derivative value: %.10lf\n", derivative);
}

int main()
{
	int i, degree;
	float h, x, coeff[N];
	
	printf("--> NUMERICAL DIFFERENTIATION\n\n");
	
	printf("Enter the degree of the polynomial: ");
	scanf("%d", &degree);
	
	printf("\nEnter the coefficients of the elements of the polynomial in order, from high to low:\n");
	readPolynomial(coeff, degree);
	
	printf("\nThe polynomial you entered: ");
	printPolynomial(coeff, degree);
	
	printf("\n\nEnter the value 'x': ");
	scanf("%f", &x);
	
	printf("\n'h' degerini giriniz: ");
	scanf("%f", &h);
	
	finiteDiff(coeff, x, h, degree);
	
	getch();
	
	return 0;
}

