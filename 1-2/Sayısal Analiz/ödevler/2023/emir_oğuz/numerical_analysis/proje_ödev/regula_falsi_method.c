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

// Regula-Falsi Yontemi'nin adimlarini iceren fonksiyon
void regulaFalsi(float coeff[N], double low_lim, double up_lim, double error, int degree)
{
	int iteration = 0;
	double mid_lim, lowRes, midRes, upRes, controlValue;
	
	lowRes = functionValue(coeff, low_lim, degree); // Alt sinir icin polinom degeri hesaplanir.
	upRes = functionValue(coeff, up_lim, degree); // Ust sinir icin polinom degeri hesaplanir.
	
	do{
		iteration++;
		
		printf("\n%d. ITERATION\n", iteration);
		printf("- Lower limit value: %.10lf\n", low_lim);
		printf("- Function value for lower limit: %.10lf\n", lowRes);
		printf("- Upper limit value: %.10lf\n", up_lim);
		printf("- Function value for upper limit: %.10lf\n", upRes);
		
		midRes = 0;
		
		mid_lim = (low_lim * upRes - up_lim * lowRes) / (upRes - lowRes); // Orta deger, yontemdeki kurala gore hesaplanir.
		
		controlValue = (up_lim - low_lim) / pow(2, iteration); // Kontrol degeri hesaplanir.
		
		midRes = functionValue(coeff, mid_lim, degree); // Orta degerin polinom degeri hesaplanir.
		
		if(midRes * lowRes < 0){
			up_lim = mid_lim;
			upRes = midRes;
		}
		else if(midRes * upRes < 0){
			low_lim = mid_lim;
			lowRes = midRes;
		}
	
		printf("+ Root value (x%d): %.10lf\n", iteration, mid_lim);
		printf("+ Function value of root: %.10lf\n", midRes);
		printf("+ (b-a) / 2^n value: %.10lf\n", controlValue);
		
	}while(controlValue > error);
	
	printf("\nRESULT:\n");
	printf("The approximate root value was found as %.10lf in a total of %d iterations.\n", mid_lim, iteration);
}

int main()
{
	int degree;
	float coeff[N]; 
	double low_lim, mid_lim, up_lim, lowRes, midRes, upRes, error;
	
	printf("--> REGULA-FALSI METHOD\n\n");
	
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
		
		lowRes = 0, upRes = 0;
		
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
	
	regulaFalsi(coeff, low_lim, up_lim, error, degree);
	
	getch();
	
	return 0;
}

