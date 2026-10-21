#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 0.0000001
#define max 50

int menu();
int getPolynomial(double coefficient[max], int degree[max]);
void sortAndPrintPolynomial(double coefficient[max], int degree[max], int n);
double calculatePolynomial(double x, double coefficient[max], int degree[max], int n);
double calculateDeriative(double x, double coefficient[max], int degree[max], int n);

void bisection(double coefficient[max], int degree[max], int n);
void regulafalsi(double coefficient[max], int degree[max], int n);
void newtonRaphson(double coefficient[max], int degree[max], int n);
void inverseMatrixFunction(double matrix[max][max], double inverse_matrix[max][max]);
void gaussElimination(double matrix[max][max]);
void gaussSeidal(double matrix[max][max]);
double numericalDifferentiation(double coefficient[max], int degree[max], int n);
void simpsonMethod(double coefficient[max], int degree[max], int n);
double trapezialMethod(double coefficient[max], int degree[max], int n);
void gregoryNewton(double matrix[max][max]);

int main(){
	int n, degree[max], method, answer;
	double coefficient[max], matrix[max][max], inverse_matrix[max][max];
	
	do{
		method=menu();
		switch(method){
			case 1:
				n = getPolynomial(coefficient, degree);
				sortAndPrintPolynomial(coefficient, degree, n);
				bisection(coefficient, degree, n);
				break;
			case 2:
				n = getPolynomial(coefficient, degree);
				sortAndPrintPolynomial(coefficient, degree, n);
				regulafalsi(coefficient, degree, n);
				break;
			case 3:
				n = getPolynomial(coefficient, degree);
				sortAndPrintPolynomial(coefficient, degree, n);
				newtonRaphson(coefficient, degree, n);
				break;
			case 4:
				inverseMatrixFunction(matrix, inverse_matrix);
				break;
			case 5:
				gaussElimination(matrix);
				break;
			case 6:
				gaussSeidal(matrix);
				break;	
			case 7:
				n = getPolynomial(coefficient, degree);
				sortAndPrintPolynomial(coefficient, degree, n);
				printf("\nresult: %lf", numericalDifferentiation(coefficient, degree, n));	
				break;
			case 8:
				n = getPolynomial(coefficient, degree);
				sortAndPrintPolynomial(coefficient, degree, n);
				simpsonMethod(coefficient, degree, n);	
				break;
			case 9:
				n = getPolynomial(coefficient, degree);
				sortAndPrintPolynomial(coefficient, degree, n);
				printf("\nresult: %lf", trapezialMethod(coefficient, degree, n));	
				break;
			case 10:
				gregoryNewton(matrix);
				break;	
			default:
				printf("\nInvalid value...\n");								
		}
		printf("\n\nenter 1 if you want to return to the menu otherwise enter 0: ");
		scanf("%d", &answer);
	} while(answer == 1);
	return 0;
}

int getPolynomial(double coefficient[max], int degree[max]){
	int i, n;
	
	do{
		printf("\nhow many elements are there in the polynomial: ");
		scanf(" %d", &n);
		if(n <= 0) printf("Invalid value...\n");
	} while(n <= 0);
	
	for(i=0; i<n; i++){
		printf("\nthe cofficient of %d.th value: ", i+1);
		scanf(" %lf", &coefficient[i]);
		printf("\nthe degree of %d.th value: ", i+1);
		scanf(" %d", &degree[i]);
	}
	return n;
}

void sortAndPrintPolynomial(double coefficient[max], int degree[max], int n){
	int i, j;
	double temp1, temp2;
	//Insertion sort was used...
	for(i=1; i<n; i++){
		j = i-1;
		temp1 = degree[i];
		temp2 = coefficient[i];
		while(j >= 0 && degree[j] < temp1){
			degree[j+1] = degree[j];
			coefficient[j+1] = coefficient[j];
			j--;
		}
		degree[j+1] = temp1;
		coefficient[j+1] = temp2;
	}
	
	printf("\nFunction...\n\n");
	for(i=0;i<n-1;i++){
		printf("(%.3lf)x^%d + ", coefficient[i], degree[i]);
	}
	printf("(%.3lf)x^%d", coefficient[n-1], degree[n-1]);
}

double calculatePolynomial(double x, double coefficient[max], int degree[max], int n){
	int i, j;
	double sum = 0.0, temp = 1.0;
	for(i=0; i<n; i++){
		temp = 1.0;
		for(j=0; j<degree[i]; j++){
			temp = temp * x;
		}
		sum += coefficient[i] * temp;
	}
	return sum;
}

double calculateDeriative(double x, double coefficient[max], int degree[max], int n){
	int i, j;
	double sum = 0.0, temp = 1.0;
	for(i=0;i<n;i++){
		temp = 1.0;
		for(j=0; j<degree[i]-1; j++){
			temp = temp * x;
		}
		sum += coefficient[i] * degree[i] * temp;
	}
	return sum;
}

void bisection(double coefficient[max], int degree[max], int n){
	double left, right, mid, expected_error, current_error=100, j = 2;
	int control = 0;
	
	do{
		printf("\n\nBeginning point of the interval: ");
    	scanf(" %lf", &left);
   		printf("\nEnding point of the interval: ");
    	scanf(" %lf", &right);
    	
    	if(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) > 0) printf("\nInvalid range...\n");
    	
	} while(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) > 0);
	
	printf("\nexpected error: ");
	scanf("%lf", &expected_error);
	
	if(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) == 0){
		if(calculatePolynomial(left, coefficient, degree, n) == 0) mid = left;
		else mid = right;
		control = 1;
	}
	
    while(control == 0 && current_error > expected_error){
    	mid = (left+right)/2;
    	
    	if(calculatePolynomial(mid, coefficient, degree, n) == 0) control = 1;
    	else if(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(mid, coefficient, degree, n) < 0) right = mid;
		else left = mid;
		
    	j*=2;
    	current_error = fabs((right-left)/j);
	}
	 
	printf("\nroot: %lf", mid);
}

void regulafalsi(double coefficient[max], int degree[max], int n){
	double left, right, mid, expected_error, current_error=100, j=2;
	int control = 0;
    
    do{
		printf("\n\nBeginning point of the interval: ");
    	scanf(" %lf", &left);
   		printf("\nEnding point of the interval: ");
    	scanf(" %lf", &right);
    	
    	if(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) > 0) printf("\nInvalid range...\n");
    	
	} while(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) > 0);
	
	printf("\nexpected error: ");
	scanf("%lf", &expected_error);
	
	if(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) == 0){
		if(calculatePolynomial(left, coefficient, degree, n) == 0) mid = left;
		else mid = right;
		control = 1;	
	}
	
    while(control == 0 && current_error > expected_error){	
    	mid = (calculatePolynomial(left, coefficient, degree, n) * right - calculatePolynomial(right, coefficient, degree, n) * left) / (calculatePolynomial(left, coefficient, degree, n) - calculatePolynomial(right, coefficient, degree, n));
    	if(calculatePolynomial(mid, coefficient, degree, n) == 0) control = 1;
    	else if(calculatePolynomial(mid, coefficient, degree, n) * calculatePolynomial(left, coefficient, degree, n) < 0) right = mid;
		else left = mid;
		
    	j*=2;
    	current_error = fabs((right-left)/j);
	}
	 
	printf("\nroot: %lf", mid);
}

void newtonRaphson(double coefficient[max], int degree[max], int n){
	double expected_error, x1, x0, left, right, current_error;
	int answer = 0, control = 0;
	
	printf("\n\nBeginning point of the interval: ");
    scanf(" %lf", &left);
    printf("\nEnding point of the interval: ");
    scanf(" %lf", &right);
    
    while(calculatePolynomial(left, coefficient, degree, n) * calculatePolynomial(right, coefficient, degree, n) > 0){
    	printf("\nInvalid range...\n");
		printf("\nBeginning point of the interval: ");
    	scanf(" %lf", &left);
   		printf("\nEnding point of the interval: ");
    	scanf(" %lf", &right);
	}
	
	printf("\nif you want to give initial value press 1 otherwise press 0 (Then initial value will be the beginning point of the interval...): ");
	scanf(" %d", &answer);
	
	if(answer == 1){
		printf("Ýnitial value: ");
		scanf(" %lf", &x0);
	}
	else x0 = left;
	
	printf("\nexpected error: ");
	scanf("%lf", &expected_error);
	
	do{
		if(fabs(calculateDeriative(x0, coefficient, degree, n)) < epsilon) control = 1;
		else{
			
			x1 = x0 - calculatePolynomial(x0, coefficient, degree, n) / calculateDeriative(x0, coefficient, degree, n);
			current_error = fabs(x1-x0);
			x0 = x1;
		}
	} while(control == 0 && current_error > expected_error);
	
	if(control == 1) printf("\nNewton-Raphson method is not applicable to this function since deriative is equal to zero...\n");
	else printf("root: %lf", x1);
}

void inverseMatrixFunction(double matrix[max][max], double inverse_matrix[max][max]){
	int n, i, row, column, control = 1;
	double row_division, column_division, temp;
	
	do{
		printf("\nn: ");
		scanf("%d", &n);
		if(n<=0) printf("\nInvalid value...\n");
	} while(n<=0);
	
	for(row=0; row<n; row++){
		for(column=0; column<n; column++){
			printf("%d. row and %d. column: ", row+1, column+1);
			scanf(" %lf", &matrix[row][column]);
			inverse_matrix[row][column] = 0;
		}
		inverse_matrix[row][row] = 1;
		printf("\n");
	}
	
	printf("\n\nMatrix...\n\n");
	for(row=0; row<n; row++){
		for(column=0; column<n; column++) printf("%6.4lf ", matrix[row][column]);
		printf("\n");
	}
	
	i = 0;
	while(control == 1 && i < n){
		row = i, column = i, control = 0;
		while(control == 0 && row < n){
			if(fabs(matrix[row][column]) >= epsilon) control = 1;
			row++;
		}
		
		if(control == 1){
			column = 0;
			while((row-1) != i && column < n){
				
				temp = matrix[i][column];
				matrix[i][column] = matrix[row-1][column];
				matrix[row-1][column] = temp;
				
				temp = inverse_matrix[i][column];
				inverse_matrix[i][column] = inverse_matrix[row-1][column];
				inverse_matrix[row-1][column] = temp;
				
				column++;
			}
			
			row_division = matrix[i][i];
			for(column=n-1; column>=0; column--){
				matrix[i][column] /= row_division;
				inverse_matrix[i][column] /= row_division;
			} 
			
			row = 0;
			while(row < i){
				column_division = matrix[row][i];
				for(column=0; column<n; column++){
					matrix[row][column] = matrix[row][column] - (column_division * matrix[i][column]);
					inverse_matrix[row][column] = inverse_matrix[row][column] - (column_division * inverse_matrix[i][column]);
				}
				row++;
			}
			
			row = i+1;
			while(row < n){
				column_division = matrix[row][i];
				for(column=0; column<n; column++){
					matrix[row][column] = matrix[row][column] - (column_division * matrix[i][column]);
					inverse_matrix[row][column] = inverse_matrix[row][column] - (column_division * inverse_matrix[i][column]);				
				}
				row++;
			}
		}
		else{
			printf("\nIt is a singular matrix...\n");
			control = 0;
		}
		i++;
	}
	
	if(control==1){	
		printf("\n\nInverse Matrix...\n\n");
		for(row=0; row<n; row++){
			for(column=0; column<n; column++) printf("%7.4lf ", inverse_matrix[row][column]);
			printf("\n");
		}
	}
}

void gaussElimination(double matrix[max][max]){
	int n, i, row, column, control=0;
	double column_division, temp;
	
	do{
		printf("\nn: ");
		scanf("%d", &n);
		if(n<=0) printf("\nInvalid value...\n");
	} while(n<=0);
	
	for(row=0; row<n; row++){
		printf("coefficients of %d.th equation... \n", row+1);
		for(column=0; column<n; column++){
			printf("coefficient of %d.th unknown: ", column+1);
			scanf(" %lf", &matrix[row][column]);
		}
		printf("\n");
	}
	
	printf("\nConstant matrix...\n");
	for(row=0;row<n;row++){
		printf("results of %d.th equation: ", row+1);
		scanf(" %lf", &matrix[row][column]);
	}
	
	printf("\nThe augmented matrix...\n");
	for(row=0; row<n; row++){
		for(column=0; column<=n; column++) printf("%7.4lf ", matrix[row][column]);
		printf("\n");
	}
	
	for(i=0; i<n; i++){
		row = i, column = i, control = 0;
		while(control == 0 && row<n){
			if(fabs(matrix[row][column]) >= epsilon) control = 1;
			row++;
		}
		
		if(control == 1){
			while((row-1) != i && column <= n){
				temp = matrix[i][column];
				matrix[i][column] = matrix[row-1][column];
				matrix[row-1][column] = temp;
				
				column++;
			}
			
			for(column=n; column>=i; column--){
				matrix[i][column] /= matrix[i][i];
			}
		
			row = i+1;
			while(row<n){
				column_division = matrix[row][i];
				for(column=i; column<=n; column++){
					matrix[row][column] = matrix[row][column] - (column_division * matrix[i][column]);
				} 
				row++;
			}
		}
	}
	
	printf("\nThe augmented gauss-elimination matrix...\n");
	for(row=0; row<n; row++){
		for(column=0; column<=n; column++) printf("%7.4lf ", matrix[row][column]);
		printf("\n");
	}
	printf("--------------------\n");
	control = 0;
	if(matrix[n-1][n-1] == 0){
		if(matrix[n-1][n] == 0) printf("\nThere are infinite solutions...\n");
		else printf("\nThere are no solution...\n");
		control = 1;
	}
	
	row = n-1;
	while(control == 0 && row >= 0){
		for(column=n-1; column>row; column--){
			matrix[row][n] -= matrix[row][column] * matrix[column][n];
		}
		printf("\n%d.th root: %7.4lf \n", row+1, matrix[row][n]);
		row--;
	}
}

void gaussSeidal(double matrix[max][max]){
	int n, i, row, column, max_row, max_iteration, control=0;
	double temp, solution[max], sum, row_sum, expected_error, current_error;
	
	do{
		printf("\nn: ");
		scanf("%d", &n);
		if(n<=0) printf("\nInvalid value...\n");
	} while(n<=0);
	
	printf("\n\nplease provide a diagonally dominant matrix...\n\n");
	for(row=0; row<n; row++){
		printf("coefficients of %d.th equation... \n", row+1);
		for(column=0; column<n; column++){
			printf("coefficient of %d.th unknown: ", column+1);
			scanf(" %lf", &matrix[row][column]);
		}
		printf("\n");
	}
	
	printf("\nconstant matrix...\n");
	for(row=0; row<n; row++){
		printf("\nresults of %d.th equation: ", row+1);
		scanf(" %lf", &matrix[row][column]);
	}
	
	row=0;
	while(control==0 && row<n){
		row_sum = 0;
		for(column=0; column<n; column++){
			row_sum += fabs(matrix[row][column]);	
		}
		row_sum -= fabs(matrix[row][row]);
		
		if(row_sum > fabs(matrix[row][row])) control=1;
		row++;
	}
	
	if(control==0){
	
		printf("\n\nexpected error: ");
		scanf("%lf", &expected_error);
	
		printf("\nmaximum iteration: ");
		scanf(" %d", &max_iteration);

		printf("\nInitial values for unknowns... \n");
		for(i=0; i<n; i++){
			printf("Initial value for %d. unknown: ", i+1);
			scanf(" %lf", &solution[i]);
		}
	
		i = 0;
		while(control == 0 && i < max_iteration){
			printf("\n%d. iteration...\n", i+1);
			control = 1;
			for(row=0; row<n; row++){
				sum = 0;
				for(column=0; column<n; column++){
					sum += matrix[row][column] * solution[column];	
				}
			
				sum -= (matrix[row][row] * solution[row]);
				sum = (matrix[row][n] - sum) / matrix[row][row];
				current_error = fabs(solution[row] - sum);
			
				if(current_error > expected_error) control = 0;
			
				solution[row] = sum;
				printf("%d. unknown: %lf\n", row+1, solution[row]);
			}
			i++;
		}
		
		printf("\n\nThe augmented matrix..\n\n");
		for(row=0; row<n; row++){
			for(column=0; column<=n; column++) printf("%7.4lf ", matrix[row][column]);
		printf("\n");
		}
			
		printf("\n\nResults...\n\n");
    	for (i=0;i <n; i++) {
    	    printf("%dth unknown: %lf\n", i+1, solution[i]);
    	}
	}
	else{
		printf("--------------------------------------\n");
		printf("\nGauss-Seidal method is not applicable to this matrix since it is not diagonally dominant...\n");
	}
}

double numericalDifferentiation(double coefficient[max], int degree[max], int n){
	int choice;
	double x, h, result;
	
	printf("\n\nenter the value of which you want to calculate the deriative: ");
	scanf("%lf", &x);
	printf("h: ");
	scanf("%lf", &h);
	printf("\nBackward differentiation: 1\nCentral differentiation: 2\nForward Differentiation: 3\nChoice: ");
    scanf("%d", & choice);
	
	if(choice == 1){
		result = (calculatePolynomial(x, coefficient, degree, n) - calculatePolynomial(x - h, coefficient, degree, n))/h;
		return result;
	}
   	else if(choice == 2){
    	result = (calculatePolynomial(x + h, coefficient, degree, n) - calculatePolynomial(x - h, coefficient, degree, n)) / (2 * h);
		return result;
	}
	else if(choice == 3){
		result = (calculatePolynomial(x + h, coefficient, degree, n) - calculatePolynomial(x, coefficient, degree, n)) / h;
		return result;
	}
	else{
		printf("\nInvalid value...\n");
	}
}

void simpsonMethod(double coefficient[max], int degree[max], int n){
	double left, right, h, result;
	int m, i;
	do{
		printf("\nBeginning point of the interval: ");
    	scanf(" %lf", &left);
   		printf("\nEnding point of the interval: ");
    	scanf(" %lf", &right);
    	
    	if(left > right) printf("\nInvalid range...\n");
	} while(left > right);
	
	printf("\nEnter the amount of subdivisions(m):");
    scanf(" %d", &m);
    
    h = (right-left)/m;
    // 1/3 rule
    result = (calculatePolynomial(left, coefficient, degree, n) + calculatePolynomial(right, coefficient, degree, n));
    for(i=1; i<m; i++){
    	result += (calculatePolynomial(left + h * i, coefficient, degree, n) * ((i % 2) * 2 + 2));
	}
	printf("\nResult for Simpson 1/3 rule: %lf", result * h / 3);
	
	// 3/8 rule
	result = (calculatePolynomial(left, coefficient, degree, n) + calculatePolynomial(right, coefficient, degree, n));
	for(i=1; i<m; i++){
    	if(i % 3 == 0) result += calculatePolynomial(left + h*i, coefficient, degree, n) * 2;
    	else result += calculatePolynomial(left + h*i, coefficient, degree, n) * 3;
	}
	printf("\nResult for Simpson 3/8 rule: %lf", result * 3 * h / 8);
}

double trapezialMethod(double coefficient[max], int degree[max], int n){
	double left, right, h, result;
	int m, i;
	do{
		printf("\nBeginning point of the interval: ");
    	scanf(" %lf", &left);
   		printf("\nEnding point of the interval: ");
    	scanf(" %lf", &right);
    	
    	if(left > right) printf("\nInvalid range...\n");
	} while(left > right);
	
	printf("\nEnter the amount of subdivisions(m):");
    scanf(" %d", &m);
    
	h = (right-left)/m;
	result=(calculatePolynomial(left, coefficient, degree, n) + calculatePolynomial(right, coefficient, degree, n)) / 2;
	
	for(i=1; i<m; i++){
		result += calculatePolynomial(left + h*i, coefficient, degree, n);
	}
	return (result * h);
}

void gregoryNewton(double matrix[max][max]){
	int n, i, j;
	double h, x0, x, factorial=1, result=0, factor, k;
	
	printf("\nHow many points will you give: ");
	scanf(" %d", &n);
	
	printf("\nFirst point (x0): ");
	scanf(" %lf", &x0);
	
	printf("\nThe difference between each point (h): ");
	scanf(" %lf", &h);
	
	for(i=0; i<n; i++){
		matrix[i][0] = x0 + i*h; 
		printf("\nValue of the function for %.2lf: ", x0 + i*h);
		scanf("%lf", &matrix[i][1]);
	}
	
	for(i=2; i<n; i++){
		for(j=i-1; j<=n; j++){
			matrix[j][i] = matrix[j][i-1] - matrix[j-1][i-1];
		}	
	}
	printf("--------------------\n");
	printf("\nThe Difference Table...\n\n");
	for(i=0; i<n; i++){
		for(j=0; j<=n; j++){
			printf("%5.2lf ", matrix[i][j]);
		}	
		printf("\n");
	}
	
	printf("\n\nWhich point you want to calculate: ");
	scanf(" %lf", &x);
	
	result += matrix[0][1];
	k = (x-x0) / h;
	factor=k;
	for(i=1; i<n; i++){
		result += (factor * matrix[i][i+1]) / factorial;
		factor *= (k-i);
		factorial = (i+1) * factorial;
	}
	printf("--------------------\n");
	printf("\n\nRESULT: %lf", result);
}

int menu(){
	int method;
	
	printf("\n\nBisection Method: 1 \nRegula-Falsi Method: 2 \nNewton-Raphson Method: 3 \nInverse of a matrix: 4 \nGauss elimination: 5"
	"\nGauss seidel Method: 6 \nNumerical Differentiation: 7 \nSimpson Method: 8 \nTrapezoidal Method: 9 \nGregory Newton Interpolation: 10"
	"\n\nMethod of choice: ");
	scanf("%d", & method);
	return method;
}
