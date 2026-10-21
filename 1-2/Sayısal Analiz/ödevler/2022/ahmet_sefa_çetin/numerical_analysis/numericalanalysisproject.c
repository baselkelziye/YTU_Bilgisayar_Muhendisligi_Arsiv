#include <stdio.h>
#include <math.h>

#define MAX 50

typedef struct term {
	double coef;
	int exp;
} TERM;

typedef struct poly {
	TERM t[MAX];
	int n;
} POLY;

POLY getPoly(POLY p);
POLY sortPoly(POLY p);
double calculatePoly(POLY p, double x);
void writePoly(POLY p);
POLY getDeriative(POLY p);

double bisection(POLY p);
double regulaFalsi(POLY p);
double newtonRaphson(POLY p);
int invertMatrix(double matrix[MAX][MAX], int n);
void gaussElemination(double matrix[MAX][MAX], int n);
void gaussSeidel(double matrix[MAX][MAX], int n);
void numericalDiferantation(POLY p);
void simpsonsRule(POLY p);
double trapezoidalRule(POLY p);
void gregoryNewton();

int main() {
	
	int method, n, i, j, end;
	POLY polynomial;
	double result, matrix[MAX][MAX];
	
	do {
		printf("Quit: 0\n");
		printf("Bisection: 1\n");
		printf("Regula-Falsi: 2\n");
		printf("Newton Raphson: 3\n");
		printf("Inverse Matrix: 4\n");
		printf("Gauss Elemination: 5\n");
		printf("Gasuss-Seidel: 6\n");
		printf("Numerical Differantitaion: 7\n");
		printf("Simpson's Rule: 8\n");
		printf("Trapezoidal Rule: 9\n");
		printf("Gregory-Newton: 10\n");
		printf("Choice: ");
		scanf("%d", &method);
		
		switch (method) {
			case 1:
				polynomial = getPoly(polynomial);
				writePoly(polynomial);
				result = bisection(polynomial);
				printf("Result: %lf", result);
				break;
			case 2:
				polynomial = getPoly(polynomial);
				writePoly(polynomial);
				result = regulaFalsi(polynomial);
				printf("Result: %lf", result);
				break;
			case 3:
				polynomial = getPoly(polynomial);
				writePoly(polynomial);
				result = newtonRaphson(polynomial);
				printf("Result: %lf", result);
				break;
			case 4:
				printf("size of matrix: ");
				scanf("%d", &n);
				invertMatrix(matrix, n);
				break;
			case 5:
				printf("number of unknowns: ");
				scanf("%d", &n);
				gaussElemination(matrix, n);
				break;
			case 6:
				printf("number of unknowns: ");
				scanf("%d", &n);
				gaussSeidel(matrix, n);			
				break;
			case 7:
				polynomial = getPoly(polynomial);
				writePoly(polynomial);
				numericalDiferantation(polynomial);
				break;
			case 8:
				polynomial = getPoly(polynomial);
				writePoly(polynomial);
				simpsonsRule(polynomial);
				break;
			case 9:
				polynomial = getPoly(polynomial);
				writePoly(polynomial);
				result = trapezoidalRule(polynomial);
				printf("Estimated integral: %lf", result);
				break;
			case 10:
				gregoryNewton();
				break;
		}
		
		printf("\n\ncontinue the program: 0\n");
		printf("end the program: 1\n");
		printf("choice: ");
		scanf("%d", &end);
	} while (!end);
	
	return 0;
}

POLY getPoly(POLY p) {
	int i;
	
	printf("Number of elements: ");
	scanf("%d", &p.n);
	
	for (i = 0; i < p.n; i++) {
		printf("coefficent of %d. element: ", i+1);
		scanf("%lf", &p.t[i].coef);
		
		printf("exponent of %d. element: ", i+1);
		scanf("%d", &p.t[i].exp);
	}
	p = sortPoly(p);
	
	return p;
}

POLY sortPoly(POLY p) {
	int i, j;
	TERM temp;
	
	for (i = 0; i < p.n; i++) {
		for (j = 0; j < p.n - i - 1; j++) {
			if (p.t[j].exp < p.t[j + 1].exp) {
				temp = p.t[j];
				p.t[j] = p.t[j + 1];
				p.t[j + 1] = temp;
			}
		}
	}
	
	return p;
}

double calculatePoly(POLY p, double x) {
	int i, j;
	
	double temp, result = 0;
	
	for (i = 0; i < p.n; i++) {
		temp = 1;
		for (j = 0; j < p.t[i].exp; j++) {
			temp *= x;
		}
		temp *= p.t[i].coef;
		result += temp;
	}
	
	return result;
}

void writePoly(POLY p) {
	int i;
	
	printf("The function: ");
	
	for (i = 0; i < p.n - 1; i++) {
		printf("%2.2fx^%d + ", p.t[i].coef, p.t[i].exp);
	}
	printf("%2.2fx^%d\n", p.t[i].coef, p.t[i].exp);
	
}

POLY getDeriative(POLY p) {
	int i;
	
	for (i = 0; i < p.n; i++) {
		if (p.t[i].exp != 0) {	
			p.t[i].coef *= p.t[i].exp;
			p.t[i].exp--;
		}
		else {
			p.t[i].coef = 0;
		}
	}
	p = sortPoly(p);
	
	return p;
}

double bisection(POLY p) {
	double a, b, c, epsilon, stop = 100;
	int n = 1, stoppingCriterion;
	
	printf("Stopping criterion: \nf(x) <= epsilon: 1 \n(end - start) / 2^n <= epsilon: 2\nChoice: ");
	scanf("%d", &stoppingCriterion);
	
	printf("epsilon: ");
	scanf("%lf", &epsilon);
	
	printf("start point: ");
	scanf("%lf", &a);
	
	printf("end point: ");
	scanf("%lf", &b);
	
	if (calculatePoly(p, a) * calculatePoly(p, b) > 0) {
		printf("Invalid range!");
		return 0;
	}
	
	else if (calculatePoly(p, a) == 0) {
		return a;
	}
	
	else if (calculatePoly(p, b) == 0) {
		return b;
	}
	
	else {
		while (stop > epsilon) {
			c =  (a + b) / 2;
			if (calculatePoly(p, a) * calculatePoly(p, c) < 0) {
				b = c;
			}
			else if (calculatePoly(p, b) * calculatePoly(p, c) < 0) {
				a = c;
			}
			
			if (stoppingCriterion == 1) {
				stop = fabs(calculatePoly(p, c));
			}
			else if (stoppingCriterion == 2) {
				stop = (b - a) / (pow(2, n));
			}
			
			n++;
		} 
	}
		
	return c;
}

double regulaFalsi(POLY p) {
	double a, b, c, epsilon, stop = 100;
	int n = 1, stoppingCriterion;
	
	printf("Stopping criterion: \nf(x) <= epsilon: 1 \n(end - start) / 2^n <= epsilon: 2\nChoice: ");
	scanf("%d", &stoppingCriterion);
	
	printf("epsilon: ");
	scanf("%lf", &epsilon);
	
	printf("start point: ");
	scanf("%lf", &a);
	
	printf("end point: ");
	scanf("%lf", &b);
	
	if (calculatePoly(p, a) * calculatePoly(p, b) > 0) {
		printf("Invalid range!");
		return 0;
	}
	
	else if (calculatePoly(p, a) == 0) {
		return a;
	}
	
	else if (calculatePoly(p, b) == 0) {
		return b;
	}
	
	else {
		while (stop > epsilon) {
			c =  (a * calculatePoly(p, b) - b * calculatePoly(p, a)) / (calculatePoly(p, b) - calculatePoly(p, a));
			if (calculatePoly(p, a) * calculatePoly(p, c) < 0) {
				b = c;
			}
			else if (calculatePoly(p, b) * calculatePoly(p, c) < 0) {
				a = c;
			}
			
			if (stoppingCriterion == 1) {
				stop = fabs(calculatePoly(p, c));			
			}
			else if (stoppingCriterion == 2) {
				stop = (b - a) / (pow(2, n));
			}
			
			n++;
		}
	}
		
	return c;
}

double newtonRaphson(POLY p) {
	double x, prevX, epsilon, a, b;
	
	printf("x0: ");
	scanf("%lf", &x);
	
	printf("epsilon: ");
	scanf("%lf", &epsilon);
	
	do {
		if (fabs(calculatePoly(getDeriative(p), x)) == 0) {
			printf("\nNewton-Raphson method is not applicable to this function since deriative is equal to zero...\n");
			return 0;
		}
		prevX = x;
		x = x - (calculatePoly(p, x) / calculatePoly(getDeriative(p), x));
	} while (fabs(prevX - x) > epsilon);
	
	return x;
}

int invertMatrix(double matrix[MAX][MAX], int n) {
	int i, j, k;
	double inverseMatrix[MAX][MAX] = {0}, temp;
	
	printf("elements of matrix: \n");
	
	for (i = 0; i < n; i++) {
		inverseMatrix[i][i] = 1;
        for (j = 0; j < n; j++) {
        	printf("%d, %d element: ", i + 1, j  + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
	
	for (i = 0; i < n; i++) {
        if (matrix[i][i] != 0) {
            temp = matrix[i][i];
            for (j = 0; j < n; j++) {
                matrix[i][j] /= temp;
                inverseMatrix[i][j] /= temp;
            }
            for (j = 0; j < n; j++) {
                if (j != i) {
                    temp = matrix[j][i];
                    for (k = 0; k < n; k++) {
                        matrix[j][k] -= temp * matrix[i][k];
                        inverseMatrix[j][k] -= temp * inverseMatrix[i][k];
                    }
                }
            }
        }
        else {
            printf("Error: Matrix is singular.\n");
            return 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        	printf("%lf\t ", inverseMatrix[i][j]);
        }
        printf("\n");
    }
	
	return 1;
}

void gaussElemination(double matrix[MAX][MAX], int n) {
	int i, j, k, control, rowOfZeros;
	double temp, results[MAX] = {0};
    
    for (i = 0; i < n; i++) {
        printf("unknowns of the %d. equation: \n", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d. unknown: ", j + 1);
            scanf("%lf", & matrix[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("result of the %dth equation: ", i + 1);
        scanf("%lf", & matrix[i][j]);
    }
	
	for (i = 0; i < n; i++) {
		if (matrix[i][i] != 0) {
			temp = matrix[i][i];
	        for (j = 0; j <= n; j++) {
	            matrix[i][j] /= temp;
	        }
	        for (j = 0; j < n; j++) {
	            if (j > i) {
	                temp = matrix[j][i];
	                for (k = 0; k <= n; k++) {
	                    matrix[j][k] -= temp * matrix[i][k];
	                }
	            }
	        }
		}
    }
    
	printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
        	printf("%lf\t ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    control = 0;
    i = n - 1;
    while (i >= 0 && control == 0) {
        j = 0;
        while (j < n && matrix[i][j] == 0) {
            j++;
        }
        if (j == n) { 
            control = 1;
            rowOfZeros = i;
        }
        i--;
    }
    
    if (control == 1) {
    	if (matrix[rowOfZeros][n] == 0) {
    		printf("INFINITE AMOUNT OF SOLUTIONS");
		}
		else {
			printf("NO SOLUTION AVALIABLE");
		}
		return;
	}
	else { 
		for (i = n - 1; i >= 0; i--) {
			results[i] =  matrix[i][n];
        	for (j = n - 1; j >= 0; j--) {
        		if (i != j) {
        			results[i] -= (results[j] * matrix[i][j]);
				}
    		}
    	}
    
	    for (i = 0; i < n; i++) {
	        printf("%d. root: %lf\n", i + 1, results[i]);
	    }
	}
		
}

void gaussSeidel(double matrix[MAX][MAX], int n) {
	int i, j, k, flag = 1, control = 1, maxIndex, temp;
	double epsilon, diagonal, roots[MAX], prevRoots[MAX] = {0}, maxValue;
	
	for (i = 0; i < n; i++) {
        printf("unknowns of the %d. equation: \n", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d. unknown: ", j + 1);
            scanf("%lf", & matrix[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("result of the %dth equation: ", i + 1);
        scanf("%lf", & matrix[i][j]);
    }
    
    printf("epsilon: ");
	scanf("%lf", &epsilon);
	
	for (i = 0; i < n; i++) {
        maxIndex = i;
        maxValue = fabs(matrix[i][i]);

        for (j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > maxValue) {
                maxIndex = j;
                maxValue = fabs(matrix[j][i]);
            }
        }

        for (j = 0; j <= n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[maxIndex][j];
            matrix[maxIndex][j] = temp;
        }
    }
    
    for(i = 0; i < n; i++){
		diagonal = matrix[i][i];
		for(j = 0; j < n; j++){
			if(fabs(diagonal) < fabs(matrix[i][j])){
				flag = 0;
			}
		}
	}
	
	if (flag) {
		for (i = 0; i < n; i++) {
	        for (j = 0; j <= n; j++) {
	        	printf("%lf\t ", matrix[i][j]);
	        }
	        printf("\n");
	    }
		
		for (i = 0; i < n; i++) {
			roots[i] = 1;
		}
		
		while (control == 1) {
			
			for (i = 0; i < n; i++) {
				roots[i] = matrix[i][n];
				for (j = 0; j < n; j++) {
					if (i != j) {
						roots[i] -= roots[j] * matrix[i][j];
					}
				}
				roots[i] /= matrix[i][i];
			}
	
			control = 0;
			i = 0;
			while (i < n && control == 0) {
				if (fabs(roots[i] - prevRoots[i]) >= epsilon) {
					control = 1;
				}
				i++;
			}
					
			for (i = 0; i < n; i++) {
				prevRoots[i] = roots[i];
			}
			
		}
		
		for (i = 0; i < n; i++) {
		    printf("%d. root: %lf\n", i + 1, roots[i]);
		}
	}
	
	else {
		printf("matrix is not diagonally dominant");
	}
}

void numericalDiferantation(POLY p) {
	double h, x;
	
	printf("Which x do you want to differentiate: ");
	scanf("%lf", &x);
	
	printf("h: ");
	scanf("%lf", &h);
	
	printf("Backward Difference: %lf\n", (calculatePoly(p, x) - calculatePoly(p, x - h)) / h);
	printf("Centered Difference: %lf\n", (calculatePoly(p, x + h) - calculatePoly(p, x - h)) / (2 * h));
	printf("Forward Difference: %lf\n", (calculatePoly(p, x + h) - calculatePoly(p, x)) / h);
}

void simpsonsRule(POLY p) {
	int n, i;
	double start, end, result, h, a, b, x1, x2;
	
	printf("Starting value of integral: ");
	scanf("%lf", &start);
							
	printf("Ending value of integral: ");
	scanf("%lf", &end);
	
	printf("n: ");
	scanf("%d", &n);
	
	h = (end - start) / n;
	
	a = start;
	b = start + h;
	
	result = 0;
	for (i = 0; i < n; i++) {
		result += (h * (calculatePoly(p, a) + 4 * calculatePoly(p, (a + b) / 2) + calculatePoly(p, b))) / 6;
		a += h;
		b += h; 
	}
	
	printf("Simpson's 1/3: %lf\n", result);
	
	h = (end - start) / n;
	
	a = start;
	b = start + h;
	
	result = 0;
	for (i = 0; i < n; i++) {
		x1 = a + ((b - a) / 3);
		x2 = a + 2 * ((b - a) / 3);
		result += (h * (calculatePoly(p, a) + 3 * calculatePoly(p, x1) + 3 * calculatePoly(p, x2) + calculatePoly(p, b))) / 8;
		a += h;
		b += h; 
	}
	
	printf("Simpson's 3/8: %lf", result);
}

double trapezoidalRule(POLY p) {
	int n, i;
	double start, end, result, h, a, b;
	
	printf("Starting value of integral: ");
	scanf("%lf", &start);
							
	printf("Ending value of integral: ");
	scanf("%lf", &end);
	
	printf("n: ");
	scanf("%d", &n);
	
	h = (end - start) / n;
	
	a = start;
	b = start + h;
	
	for (i = 0; i < n; i++) {
		result += (h * (calculatePoly(p, a) + calculatePoly(p, b))) / 2;
		a += h;
		b += h; 
	}				
	
	return result;
}

void gregoryNewton() {
	int n, i, j;
	double function[MAX][2], x0, h, matrix[MAX][MAX], x, result, temp;
	
	printf("number of given values: ");
	scanf("%d", &n);
	printf("x0:");
    scanf("%lf", &x0);
    printf("h:");
    scanf("%lf", &h);
    
    for (i = 0; i < n; i++) {
    	printf("f(%lf) = ", x0 + i * h);
    	scanf("%lf", &function[i][1]);
    	function[i][0] = x0 + i * h;
	}
	
	printf("which x value do you want to calculate: ");
	scanf("%lf", &x);
	
	for (i = 0; i < n; i++) {
		matrix[i][0] = function[i][1];
	}
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			matrix[j][i + 1] = matrix[j + 1][i] - matrix[j][i];
		}
	}
    
    result = function[0][1];
    
    for (i = 1; i <= n; i++) {
    	temp = 1;
    	for (j = i; j > 0; j--) {
    		temp *= (x - function[j - 1][0]) / (h * j);
		}
		temp *= matrix[0][i];
		result += temp;
	}
	
	printf("result: %lf", result);
	
}
