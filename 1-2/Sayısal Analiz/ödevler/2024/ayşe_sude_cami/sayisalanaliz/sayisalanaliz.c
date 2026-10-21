#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100
#define EPSILON 1e-7
#define MAX_ITER 1000

struct Stack
{
    int top;
    int totalSize;
    char *arrayStack;
};

// Fonksiyon alma fonksiyonları (Shunting Yard)
void initializeStack(struct Stack *stack, int size);
void destroyStack(struct Stack *stack);
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
char peek(struct Stack *stack);
char pop(struct Stack *stack);
void push(char element, struct Stack *stack);
int precedence(char ch);
int isOperand(char element);
char* infixToPostfix(char *expressionArray, struct Stack *stack);

// Yöntem fonksiyonları
void BisectionFonkAl();
double bisection(double (*f)(char*, double), double a, double b, double tol, char *postfix);

void RegulaFalsiFonkAl();
double regulaFalsi(char *infix, double a, double b, double tol, int maxIter);

void NewtonRaphsonFonkAl();
double newtonRaphson(char* infix, double x0, double tolerance);

float determinant(float **matrix, int n);
void adjoint(float **matrix, float **adj, int n);
int inverse(float **matrix, float **inverse, int n);
void MatrisTersiAl();

void gauss_eleme(float **matris, float *sonuclar, int n);
int GauusElemeYontemi();

void GaussSeidelFonkAl();
void gaussSeidel(double matris[MAX_SIZE][MAX_SIZE], double sonuclar[MAX_SIZE], int n, double x[MAX_SIZE], double hata);

double forwardDifference(double (*func)(char*, double), char* postfix, double x, double h);
double backwardDifference(double (*func)(char*, double), char* postfix, double x, double h);
double centralDifference(double (*func)(char*, double), char* postfix, double x, double h);
void SayisalTurevFonkAl();

double simpsonsRule(char* postfix, double a, double b, int n);
void Simpson13FonkAl();

double trapezoidMethod(double a, double b, int n, char* function);
void TrapezFonkAl();

void calculateCoefficients(double x[], double y[], int n, double coeff[]);
double interpolate(double x[], double y[], int n, double coeff[], double xi);
void GregoryNewtonEnt();

//-----------------------------------------------Main------------------------------------------------//
int main() {
    char expression[MAX_SIZE];  
    int result;
    int yontem;
    printf("1. Bisection yontemi\n"
           "2. Regula-Falsi yontemi\n"
           "3. Newton-Rapshon yontemi\n"
           "4. NxNlik bir matrisin tersi\n"
           "5. Gauss Eleminasyon\n"
           "6. Gauss Seidal yontemleri\n"
           "7. Sayisal Turev\n"
           "8. Simpson yontemi\n"
           "9. Trapez yontemi\n"
           "10. Degisken donusumsuz Gregory Newton Enterpolasyonu\n"
           "Islem yapmak icin yontemin numarasini girin: ");

    scanf("%d", &yontem);

    switch(yontem) {
        case 1:
        BisectionFonkAl();
            break;
        case 2:
        RegulaFalsiFonkAl();
            break;
        case 3:
        NewtonRaphsonFonkAl();
            break;
        case 4:
        MatrisTersiAl();
            break;
        case 5:
        GauusElemeYontemi();
            break;
        case 6:
        GaussSeidelFonkAl();
            break;
        case 7:
        SayisalTurevFonkAl();
            break;
        case 8:
        Simpson13FonkAl();
            break;
        case 9:
        TrapezFonkAl();
            break;
        case 10:
        GregoryNewtonEnt();
            break;
        default:
            printf("Gecersiz yontem girdiniz.");
            break;
    }

    return 0;
}
//---------------------------------------------------------------------------------------------------//

//------------------------------------FonksiyonAlmaFonksiyonları-------------------------------------//
void initializeStack(struct Stack *stack, int size) {
    stack->totalSize = size;
    stack->top = -1;
    stack->arrayStack = (char *)malloc(stack->totalSize * sizeof(char));
}

void destroyStack(struct Stack *stack) {
    free(stack->arrayStack);
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == stack->totalSize - 1;
}

char peek(struct Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->arrayStack[stack->top];
}

char pop(struct Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->arrayStack[stack->top--];
}

void push(char element, struct Stack *stack) {
    if (isFull(stack)) {
        printf("Stack is already Full.");
        return;
    }
    stack->arrayStack[++stack->top] = element;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int isOperand(char element) {
    return (element >= 'A' && element <= 'Z') || (element >= 'a' && element <= 'z') || element == 'e';
}

int isInteger(char element) {
    return (element >= '0' && element <= '9');
}

char* infixToPostfix(char *expressionArray, struct Stack *stack) {
    initializeStack(stack, strlen(expressionArray));
    int postfixSize = strlen(expressionArray) * 2;
    char *postfix = (char *)malloc(postfixSize * sizeof(char));
    int postfixIndex = 0;
    int currIndex = 0; 

    while (expressionArray[currIndex] != '\0') {
        if (isOperand(expressionArray[currIndex]) || isInteger(expressionArray[currIndex])) {
            while (isOperand(expressionArray[currIndex]) || isInteger(expressionArray[currIndex])) {
                postfix[postfixIndex++] = expressionArray[currIndex++];
            }
            postfix[postfixIndex++] = ' '; 
        } else if (expressionArray[currIndex] == '(') {
            push(expressionArray[currIndex], stack);
            currIndex++;
        } else if (expressionArray[currIndex] == ')') {
            while (peek(stack) != '(') {
                postfix[postfixIndex++] = pop(stack);
                postfix[postfixIndex++] = ' ';
            }
            pop(stack);
            currIndex++;
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(expressionArray[currIndex])) {
                postfix[postfixIndex++] = pop(stack);
                postfix[postfixIndex++] = ' ';
            }
            push(expressionArray[currIndex], stack);            
            currIndex++;
        }
    }

    while (!isEmpty(stack)) {
        postfix[postfixIndex++] = pop(stack);
        postfix[postfixIndex++] = ' ';
    }
       
    postfix[postfixIndex] = '\0';
    destroyStack(stack);
    return postfix;
}

typedef struct {
    int top;
    double stack[MAX_SIZE];
} stack2;

void displayStack(stack2* s) {
    int i = 0;
    while (s->top >= i) {
        printf("%.2lf ", s->stack[i]);
        i++;
    }
    printf("stack ended\n");
}

void initializeStack2(stack2 *s) {
    s->top = -1;
}

void push2(stack2 *s, double item) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->stack[s->top] = item;
}

double pop2(stack2 *s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    double item = s->stack[s->top];
    s->top--;
    return item;
}

int is_operator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

double evaluate(char* expression, stack2 *s, double x) {
    double operand1, operand2, result;
    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) {
            push2(s, atof(token));
        } else if (*token == 'x') {
            push2(s, x);
        } else if (*token == 'e') {
            push2(s, 2.718);
        } else if (is_operator(*token)) {
            operand2 = pop2(s);
            operand1 = pop2(s);
            switch(*token) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    } 
                    result = operand1 / operand2; 
                    break;
                case '^': result = pow(operand1, operand2); break; 
            }
            push2(s, result);
        }
        token = strtok(NULL, " ");
    }
    return pop2(s);
}

double evaluateExpression(char* postfix, double x) {
    stack2 s;
    initializeStack2(&s);
    char* postfix_copy = strdup(postfix); 
    if (!postfix_copy) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    double result = evaluate(postfix_copy, &s, x);
    free(postfix_copy);
    return result;
}

//---------------------------------------YontemFonksiyonları-----------------------------------------//
float determinant(float **matrix, int n) {
    int i,x,j;
    float det = 0.0;
    if (n == 1) {
        return matrix[0][0];
    }

    float **submatrix = (float **)malloc((n-1) * sizeof(float *));
    for (i = 0; i < n-1; i++) {
        submatrix[i] = (float *)malloc((n-1) * sizeof(float));
    }

    for (x = 0; x < n; x++) {
        int subi = 0;
        for (i = 1; i < n; i++) {
            int subj = 0;
            for (j = 0; j < n; j++) {
                if (j != x) {
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n-1);
    }

    for (i = 0; i < n-1; i++) {
        free(submatrix[i]);
    }
    free(submatrix);

    return det;
}

void adjoint(float **matrix, float **adj, int n) {
	int i,j,x,y;
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    float **submatrix = (float **)malloc((n-1) * sizeof(float *));
    for (i = 0; i < n-1; i++) {
        submatrix[i] = (float *)malloc((n-1) * sizeof(float));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int subi = 0;
            for (x = 0; x < n; x++) {
                if (x != i) {
                    int subj = 0;
                    for (y = 0; y < n; y++) {
                        if (y != j) {
                            submatrix[subi][subj] = matrix[x][y];
                            subj++;
                        }
                    }
                    subi++;
                }
            }
            sign = ((i+j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(submatrix, n-1);
        }
    }

    for (i = 0; i < n-1; i++) {
        free(submatrix[i]);
    }
    free(submatrix);
}

int inverse(float **matrix, float **inverse, int n) {
	int i,j;
    float det = determinant(matrix, n);
    if (det == 0) {
        printf("Matrisin tersi yok.\n");
        return 0;
    }

    float **adj = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        adj[i] = (float *)malloc(n * sizeof(float));
    }

    adjoint(matrix, adj, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inverse[i][j] = adj[i][j] / det;
        }
    }

    for (i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return 1;
}

void MatrisTersiAl() {
    int n,i,j;
    printf("Matris boyutunu girin: ");
    scanf("%d", &n);

    float **matrix = (float **)malloc(n * sizeof(float *));
    float **inverseMatrix = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        matrix[i] = (float *)malloc(n * sizeof(float));
        inverseMatrix[i] = (float *)malloc(n * sizeof(float));
    }

    printf("Matris elemanlarini girin:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    if (inverse(matrix, inverseMatrix, n)) {
        printf("Matrisin tersi:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%0.4f ", inverseMatrix[i][j]);
            }
            printf("\n");
        }
    }

    for (i = 0; i < n; i++) {
        free(matrix[i]);
        free(inverseMatrix[i]);
    }
    free(matrix);
    free(inverseMatrix);
}

void gauss_eleme(float **matris, float *sonuclar, int n) {
    int i, j, k;
    float oran, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            oran = matris[j][i] / matris[i][i];
            for (k = i; k < n; k++) {
                matris[j][k] -= oran * matris[i][k];
            }
            sonuclar[j] -= oran * sonuclar[i];
        }
    }

    for (i = n - 1; i >= 0; i--) {
        temp = 0;
        for (j = i + 1; j < n; j++) {
            temp += matris[i][j] * sonuclar[j];
        }
        sonuclar[i] = (sonuclar[i] - temp) / matris[i][i];
    }
}

int GauusElemeYontemi() {
    int n, i, j;

    printf("Denklem sisteminin boyutunu girin: ");
    scanf("%d", &n);

    float **matris = (float **)malloc(n * sizeof(float *));
    float *sonuclar = (float *)malloc(n * sizeof(float));

    printf("Katsayi matrisinin elemanlarini girin:\n");
    for (i = 0; i < n; i++) {
        matris[i] = (float *)malloc(n * sizeof(float));
        for (j = 0; j < n; j++) {
            scanf("%f", &matris[i][j]);
        }
    }

    printf("Sonuclar vektorunu girin:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &sonuclar[i]);
    }

    gauss_eleme(matris, sonuclar, n);
    printf("Denklem sisteminin cozumleri:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, sonuclar[i]);
    }

    for (i = 0; i < n; i++) {
        free(matris[i]);
    }
    free(matris);
    free(sonuclar);

    return 0;
}

void BisectionFonkAl() {
    char expressionArray[40];
    struct Stack stack;
    double x;

    printf("Bir fonksiyon giriniz: ");
    scanf("%s", expressionArray);
    printf("Girilen fonksiyon: %s\n", expressionArray);

    char *postfix = infixToPostfix(expressionArray, &stack);
    printf("Postfix hali: %s\n", postfix);

    double a, b, tol;
    printf("Araligin basi: ");
    scanf("%lf", &a);
    printf("Araligin sonu: ");
    scanf("%lf", &b);
    printf("Durdurmak icin tolerans degeri: ");
    scanf("%lf", &tol);

    double result = bisection(evaluateExpression, a, b, tol, postfix);
    printf("Kok: %lf\n", result);

    free(postfix);
}
double bisection(double (*f)(char*, double), double a, double b, double tol, char *postfix) {
    double c;
    int iter = 0;
    int itercarpim = 1;

    if (f(postfix, a) * f(postfix, b) >= 0) {
        printf("Belirtilen aralikta kok yok veya tek sayida kok var.\n");
        return -1; // Geçersiz aralık
    }

    while ((b - a)/itercarpim >= tol) {
        c = (a + b) / 2.0; 
        double func_c = f(postfix, c);
        printf("%d. iterasyon sonucu: %lf\n",iter,func_c);
        if (func_c == 0.0) {
            printf("Kok bulundu: %lf\n", c);
            return c;
        } else if (func_c * f(postfix, a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        iter++;
        itercarpim *= 2;
    }

    printf("Iterasyon sayisi: %d\n", iter);
    printf("Kok tahmini: %lf\n", c);
    return c;
}

double regulaFalsi(char *infix, double a, double b, double tol, int maxIter) {
	int i;
    struct Stack stack;
    char* postfix = infixToPostfix(infix, &stack);
    
    double fa = evaluateExpression(postfix, a);
    double fb = evaluateExpression(postfix, b);
    if (fa * fb > 0) {
        printf("Fonksiyon a ve b noktalarinda ayni isaretlere sahip. Aralikta kok bulunamadi.\n");
        free(postfix);
        return NAN;
    }
    
    double c, fc;
    for (i = 0; i < maxIter; ++i) {
        c = b - (fb * (b - a)) / (fb - fa);
        fc = evaluateExpression(postfix, c);
        
        if (fabs(fc) < tol) {
            free(postfix);
            return c;
        }
        
        if (fc * fa < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    
    free(postfix);
    return c;
}

void RegulaFalsiFonkAl() {
    char expressionArray[40];
    struct Stack stack;
    double x;
    double a, b, tol;
    int maxIter;

    printf("Fonksiyonu giriniz: ");
    scanf("%s", expressionArray);
    printf("Girilen fonksiyon: %s\n", expressionArray);

    char *postfix = infixToPostfix(expressionArray, &stack);
    printf("Postfix hali: %s\n", postfix);

    printf("Araligin uc noktalarini girin [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Hata payini girin: ");
    scanf("%lf", &tol);

    printf("Maximum iterasyon sayisini giriniz: ");
    scanf("%d", &maxIter);

    double root = regulaFalsi(expressionArray, a, b, tol, maxIter);
    if (!isnan(root)) {
        printf("Kok: %lf\n", root);
    } else {
        printf("Verilen aralikta kok bulunamadi.\n");
    }
}

double newtonRaphson(char* infix, double x0, double tolerance) {
    struct Stack stack;
    char* postfix = infixToPostfix(infix, &stack);
    printf("Fonksiyonu giriniz:: %s\n", postfix);
    double x = x0;
    double fx, dfx;
    double x1;

    while (1) {
        fx = evaluateExpression(postfix, x);

        double h = 1e-7; 
        double fxh1 = evaluateExpression(postfix, x + h);
        double fxh2 = evaluateExpression(postfix, x - h);
        dfx = (fxh1 - fxh2) / (2 * h);

        x1 = x - fx / dfx;

        if (fabs(x1 - x) < tolerance) {
            free(postfix);
            return x1;
        }

        x = x1;
    }
}

void NewtonRaphsonFonkAl() {
    char expressionArray[40];
    double x0, tolerance;
    int maxIter;

    printf("Fonksiyonu girin: ");
    scanf("%s", expressionArray);
    printf("Girilen fonksiyon: %s\n", expressionArray);

    printf("Baslangic degerini girin: ");
    scanf("%lf", &x0);

    printf("Hata payini girin: ");
    scanf("%lf", &tolerance);

    double root = newtonRaphson(expressionArray, x0, tolerance);
    printf("Bulunan kok: %.7lf\n", root);
}

void gaussSeidel(double matris[MAX_SIZE][MAX_SIZE], double sonuclar[MAX_SIZE], int n, double x[MAX_SIZE], double hata) {
	int i,j;
    double yeni_x[MAX_SIZE];
    double max_hata;
    int iterasyon = 0;

    do {
        max_hata = 0.0;

        for (i = 0; i < n; ++i) {
            double sum = 0.0;

            for (j = 0; j < n; ++j) {
                if (j != i) {
                    sum += matris[i][j] * x[j];
                }
            }

            yeni_x[i] = (sonuclar[i] - sum) / matris[i][i];

            double current_hata = fabs((yeni_x[i] - x[i]));
            if (current_hata > max_hata) {
                max_hata = current_hata;
            }

            x[i] = yeni_x[i];
        }

        ++iterasyon;
    } while (max_hata > hata && iterasyon < 1000);

    printf("\n%d iterasyon sonra hata: %.6lf\n", iterasyon, max_hata);
}

void GaussSeidelFonkAl() {
    int n,i,j,k;
    printf("Denklem sayisini girin: ");
    scanf("%d", &n);

    double matris[MAX_SIZE][MAX_SIZE];
    double sonuclar[MAX_SIZE];
    double x[MAX_SIZE];
    double hata;

    printf("Denklemleri girin (matris formunda):\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("Matris[%d][%d]: ", i+1, j+1);
            scanf("%lf", &matris[i][j]);
        }
    }

    printf("Sonuclari girin:\n");
    for (i = 0; i < n; ++i) {
        printf("Sonuc[%d]: ", i+1);
        scanf("%lf", &sonuclar[i]);
    }

    for (i = 0; i < n; ++i) {
        double max = fabs(matris[i][i]);
        int max_index = i;
        for (j = i + 1; j < n; ++j) {
            if (fabs(matris[j][i]) > max) {
                max = fabs(matris[j][i]);
                max_index = j;
            }
        }

        if (max_index != i) {
            for (k = 0; k < n; ++k) {
                double temp = matris[i][k];
                matris[i][k] = matris[max_index][k];
                matris[max_index][k] = temp;
            }
            double temp = sonuclar[i];
            sonuclar[i] = sonuclar[max_index];
            sonuclar[max_index] = temp;
        }
    }

    printf("Diyagonal elemanlari maksimum yapildiktan sonra matris:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%.2lf ", matris[i][j]);
        }
        printf(" | %.2lf\n", sonuclar[i]);
    }

    printf("Baslangic degerlerini girin:\n");
    for (i = 0; i < n; ++i) {
        printf("x[%d]: ", i+1);
        scanf("%lf", &x[i]);
    }

    printf("Hata payini girin: ");
    scanf("%lf", &hata);

    gaussSeidel(matris, sonuclar, n, x, hata);

    printf("\nGauss-Seidel ile bulunan kokler:\n");
    for (i = 0; i < n; ++i) {
        printf("x[%d] = %.6lf\n", i+1, x[i]);
    }
}

void calculateCoefficients(double x[], double y[], int n, double coeff[]) {
    int i, j;

    for (i = 0; i < n; i++) {
        coeff[i] = y[i];
    }

    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            coeff[j] = (coeff[j] - coeff[j - 1]) / (x[j] - x[j - i]);
        }
    }
}


double interpolate(double x[], double y[], int n, double coeff[], double xi) {
    double result = coeff[n - 1]; 
    int i;

    for (i = n - 2; i >= 0; i--) {
        result = result * (xi - x[i]) + coeff[i];
    }
    return result;
}

void GregoryNewtonEnt() {
    int n,i;
    printf("Kac adet x ve y degeri gireceksiniz: ");
    scanf("%d", &n);

    double x[n], y[n]; 
    printf("x ve y degerlerini girin:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    double coeff[n];
    calculateCoefficients(x, y, n, coeff);

    double xi;
    printf("Enterpolasyon yapilacak x degerini girin: ");
    scanf("%lf", &xi);

    double interpolatedValue = interpolate(x, y, n, coeff, xi);

    printf("Enterpolasyon sonucu: %.2f\n", interpolatedValue);
}

double forwardDifference(double (*func)(char*, double), char* postfix, double x, double h) {
    double xh = x + h;
    double fxh = func(postfix, xh);
    double fx = func(postfix, x);
    return (fxh - fx) / h;
}

double backwardDifference(double (*func)(char*, double), char* postfix, double x, double h) {
    double xh = x - h;
    double fxh = func(postfix, xh);
    double fx = func(postfix, x);
    return (fx - fxh) / h;
}

double centralDifference(double (*func)(char*, double), char* postfix, double x, double h) {
    double xph = x + h;
    double xmh = x - h;
    double fxph = func(postfix, xph);
    double fxmh = func(postfix, xmh);
    return (fxph - fxmh) / (2 * h);
}

void SayisalTurevFonkAl() {
 char expressionArray[40];
    struct Stack stack;
    stack2 stack2;
    double x,h;

    printf("Fonksiyonu giriniz: ");
    scanf("%s", expressionArray);
    printf("Girilen fonksiyon: %s\n", expressionArray);

    char *postfix = infixToPostfix(expressionArray, &stack);
    printf("Postfix hali: %s\n", postfix);

    printf("x degerini girin: ");
    scanf("%lf", &x);
    printf("h degerini girin: ");
    scanf("%lf", &h);

    double forwardDiff = forwardDifference(evaluateExpression, postfix, x, h);
    double backwardDiff = backwardDifference(evaluateExpression, postfix, x, h);
    double centralDiff = centralDifference(evaluateExpression, postfix, x, h);

    printf("Ileri fark ile: %.10lf\n", forwardDiff);
    printf("Geri fark ile: %.10lf\n", backwardDiff);
    printf("Merkezi fark ile: %.10lf\n", centralDiff);

    free(postfix);
}

double simpsonsRule(char* postfix, double a, double b, int n) {
	int i;
    if (n % 2 != 0) {
        printf("n cift olmali\n");
        exit(EXIT_FAILURE);
    }

    double h = (b - a) / n;
    double sum = 0.0;
    double x;

    sum += evaluateExpression(postfix, a);
    sum += evaluateExpression(postfix, b);

    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * evaluateExpression(postfix, x);
        } else {
            sum += 4 * evaluateExpression(postfix, x);
        }
    }

    return (h / 3) * sum;
}

void Simpson13FonkAl() {
    char expressionArray[40];
    struct Stack stack;
    double a, b;
    int n;

    printf("Fonksiyonu giriniz: ");
    scanf("%s", expressionArray);
    printf("Girilen fonksiyon: %s\n", expressionArray);

    char *postfix = infixToPostfix(expressionArray, &stack);
    printf("Postfix hali: %s\n", postfix);

    printf("Alt siniri girin (a): ");
    scanf("%lf", &a);
    printf("Ust siniri girin (b): ");
    scanf("%lf", &b);
    printf("Aralik sayisini girin (n) (cift olmali): ");
    scanf("%d", &n);

    double result = simpsonsRule(postfix, a, b, n);
    printf("Integrasyonun sonucu: %.4lf\n", result);

    free(postfix);
}

double trapezoidMethod(double a, double b, int n, char* function) {
	int i;
    double h = (b - a) / n;

    double sum = 0.0;

    for (i = 0; i <= n; i++) {
        double x = a + i * h;
        if (i == 0 || i == n) {
            sum += evaluateExpression(function, x);
        } else {
            sum += 2 * evaluateExpression(function, x);
        }
    }

    sum *= h / 2.0;

    return sum;
}

void TrapezFonkAl() {
    char function[MAX_SIZE];
    int n;
    double a, b;

    printf("Fonksiyonunuzu girin: ");
    scanf("%s", function);

    printf("Araligin uc noktalarini girin [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Araliklarin sayisini girin (n): ");
    scanf("%d", &n);

    struct Stack stack;
    char* postfix = infixToPostfix(function, &stack);

    double result = trapezoidMethod(a, b, n, postfix);

    printf("Sonuc: %.6f\n", result);

    free(postfix);
}