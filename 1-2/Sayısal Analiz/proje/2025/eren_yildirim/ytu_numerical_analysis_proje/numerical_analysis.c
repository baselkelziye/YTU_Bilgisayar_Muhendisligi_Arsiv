#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define max_length 10000

typedef enum {
    NODE_CONSTANT,
    NODE_VARIABLE,
    NODE_OPERATOR,
    NODE_FUNCTION
} NodeType;

typedef enum {
    OP_ADD, 
    OP_SUB, 
    OP_MUL, 
    OP_DIV, 
    OP_POW
} OperatorType;

typedef enum {
    FUNC_SIN, FUNC_COS, FUNC_TAN, FUNC_COT,
    FUNC_ARCSIN, FUNC_ARCCOS, FUNC_ARCTAN, FUNC_ARCCOT,
    FUNC_LOG, FUNC_LOG_BASE,
    FUNC_EXP
} FunctionType;

typedef struct Function {
    NodeType type;
    union {
        double value; 
        char variable;
        struct {
            OperatorType op;
            struct Function *left;
            struct Function *right;
        } op;
        struct {
            FunctionType func;
            struct Function *arg;
            double base;
        } func;
    };
    
} Function;

typedef struct {
    double forward_derivative;
    double backward_derivative;
    double central_derivative;
} Derivatives;

double** get_matrix(int n); // Matrix
double bisection(Function *root, double a, double b, double max_error, int max_iter); // Metod 1 - Bisection
double regula_falsi(Function *root, double a, double b, double max_error, int max_iter); // Metod 2 - Regula-Falsi
double newton_raphson(Function *root, double start, double max_error, int max_iter); // Metod 3 - Newton-Raphson
double** inverse_matrix(double **org_matrix, int n); // Metod 4 - Inverse Matrix
double** lu_decomposition(double** org_matrix, int n); // Metod 5 - Cholesky Metodu
int gauss_seidel(double** org_matrix, int n, int max_iter, double max_error, double* result); // Metod 6 - Gauss-Seidel
Derivatives numerical_differentiation(Function *root, double h, double x); // Metod 7 - Sayısal Türev
void simpson_integral(Function *root, double a, double b, int n); // Metod 8 - Simpson Metodu
double trapezoidal_rule(Function *root, double a, double b, int n); // Metod 9 - Trapez Metodu
void gregory_newton_interpolation(); // Metod 10 - Gregory-Newton Enterpolasyonu

char buffer[max_length];
const char *input;
int position = 0;

void skip_spaces() {
    while (isspace(input[position])) {
        position++;
    }
}


int match_symbol(const char *str) {
    skip_spaces();
    int length = strlen(str);

    if (strncmp(&input[position], str, length) == 0) {
        position += length;
        return 1;
    }
    
    else {
        return 0;
    }
}


double number_parser() {
    skip_spaces();
    double num = 0;
    int start = position;

    while (isdigit(input[position]) || input[position] == '.') {
        position++;
    }

    sscanf(&input[start], "%lf", &num);
    return num;
}


Function *addsub_parser();

Function *parse_primary() {
    skip_spaces();

    if (match_symbol("-")) {
        Function *expr = parse_primary();
        Function *zero = malloc(sizeof(Function));
        zero->type = NODE_CONSTANT;
        zero->value = 0;

        Function *node = malloc(sizeof(Function));
        node->type = NODE_OPERATOR;
        node->op.op = OP_SUB;
        node->op.left = zero;
        node->op.right = expr;
        return node;
    }

    if (match_symbol("(")) {
        Function *expr = addsub_parser();
        match_symbol(")");
        return expr;
    }

    if (isdigit(input[position])) {
        double val = number_parser();
        Function *node = malloc(sizeof(Function));
        node->type = NODE_CONSTANT;
        node->value = val;
        return node;
    }

    if (isalpha(input[position])) {
        int start = position;

        while (isalpha(input[position]) || input[position] == '_' || isdigit(input[position])) {
            position++;
        }

        int length = position - start;
        char name[20];
        int copy_length = length < 19 ? length : 19;

        strncpy(name, &input[start], copy_length);
        name[copy_length] = '\0';

        if (strcmp(name, "pi") == 0) {
            Function *node = malloc(sizeof(Function));
            node->type = NODE_CONSTANT;
            node->value = 3.141592653589793;
            return node;
        }

        if (strcmp(name, "e") == 0) {
            Function *node = malloc(sizeof(Function));
            node->type = NODE_CONSTANT;
            node->value = 2.718281828459045;
            return node;
        }

    if (match_symbol("(")) {
        Function *arg = addsub_parser();
        match_symbol(")");

        FunctionType func;
        double base = 0;

        if (strcmp(name, "sin") == 0) {
            func = FUNC_SIN;
        }

        else if (strcmp(name, "cos") == 0) {
            func = FUNC_COS;
        }

        else if (strcmp(name, "tan") == 0) {
            func = FUNC_TAN;
        }

        else if (strcmp(name, "cot") == 0) {
            func = FUNC_COT;
        }

        else if (strcmp(name, "arcsin") == 0) {
            func = FUNC_ARCSIN;
        }

        else if (strcmp(name, "arccos") == 0) {
            func = FUNC_ARCCOS;
        }

        else if (strcmp(name, "arctan") == 0) {
            func = FUNC_ARCTAN;
        }

        else if (strcmp(name, "arccot") == 0) {
            func = FUNC_ARCCOT;
        }

        else if (strcmp(name, "log") == 0) {
            func = FUNC_LOG;
        }

        else if (strncmp(name, "log_", 4) == 0) {
            func = FUNC_LOG_BASE;
            base = atof(&name[4]);
        }

        else if (strcmp(name, "exp") == 0) {
            func = FUNC_EXP;
        }

        else {
            printf("Unknown function type: %s\n", name);
            exit(1);
        }

            Function *node = malloc(sizeof(Function));
            node->type = NODE_FUNCTION;
            node->func.func = func;
            node->func.arg = arg;
            node->func.base = base;
            return node;
        }


        if (name[0] == 'x') {
            Function *node = malloc(sizeof(Function));
            node->type = NODE_VARIABLE;
            node->variable = 'x';
            return node;
        }

        printf("Unknown identifier: %s\n", name);
        exit(1);
    }

    printf("Unknown character: %c\n", input[position]);
    exit(1);

}




Function *exp_parser() {
    Function *left = parse_primary();
    int loop = 1;
    while (loop && match_symbol("^")) {
        Function *right = parse_primary();
        Function *node = malloc(sizeof(Function));
        node->type = NODE_OPERATOR;
        node->op.op = OP_POW;
        node->op.left = left;
        node->op.right = right;
        left = node;
    }

    return left;
}

Function *muldiv_parser() {
    Function *left = exp_parser();
    int loop = 1;
    while (loop) {
        if (match_symbol("*")) {
            Function *right = exp_parser();
            Function *node = malloc(sizeof(Function));
            node->type = NODE_OPERATOR;
            node->op.op = OP_MUL;
            node->op.left = left;
            node->op.right = right;
            left = node;
        }

        else if (match_symbol("/")) {
            Function *right = exp_parser();
            Function *node = malloc(sizeof(Function));
            node->type = NODE_OPERATOR;
            node->op.op = OP_DIV;
            node->op.left = left;
            node->op.right = right;
            left = node;
        } 
        else {
            loop = 0;
        }
    }

    return left;
}

Function *addsub_parser() {
    Function *left = muldiv_parser();
    int loop = 1;
    while (loop) {
        if (match_symbol("+")) {
            Function *right = muldiv_parser();
            Function *node = malloc(sizeof(Function));
            node->type = NODE_OPERATOR;
            node->op.op = OP_ADD;
            node->op.left = left;
            node->op.right = right;
            left = node;
        }

        else if (match_symbol("-")) {
            Function *right = muldiv_parser();
            Function *node = malloc(sizeof(Function));
            node->type = NODE_OPERATOR;
            node->op.op = OP_SUB;
            node->op.left = left;
            node->op.right = right;
            left = node;
        }

        else {
            loop = 0;
        }
    }

    return left;
}

double calculate_func(Function *node, double x) {
    switch (node->type) {

        case NODE_CONSTANT:
            return node->value;

        case NODE_VARIABLE:
            return x;

        case NODE_OPERATOR:
            switch (node->op.op) {

                case OP_ADD:
                    return calculate_func(node->op.left, x) + calculate_func(node->op.right, x);

                case OP_SUB:
                    return calculate_func(node->op.left, x) - calculate_func(node->op.right, x);

                case OP_MUL:
                    return calculate_func(node->op.left, x) * calculate_func(node->op.right, x);

                case OP_DIV:
                    return calculate_func(node->op.left, x) / calculate_func(node->op.right, x);

                case OP_POW:
                    return pow(calculate_func(node->op.left, x), calculate_func(node->op.right, x));
            }
            
            break;

        case NODE_FUNCTION:
            switch (node->func.func) {

                case FUNC_SIN:
                    return sin(calculate_func(node->func.arg, x));

                case FUNC_COS:
                    return cos(calculate_func(node->func.arg, x));

                case FUNC_TAN:
                    return tan(calculate_func(node->func.arg, x));

                case FUNC_COT:
                    return 1.0 / tan(calculate_func(node->func.arg, x));

                case FUNC_ARCSIN:
                    return asin(calculate_func(node->func.arg, x));

                case FUNC_ARCCOS:
                    return acos(calculate_func(node->func.arg, x));

                case FUNC_ARCTAN:
                    return atan(calculate_func(node->func.arg, x));

                case FUNC_ARCCOT:
                    return atan(1.0 / calculate_func(node->func.arg, x));

                case FUNC_LOG:
                    return log(calculate_func(node->func.arg, x));

                case FUNC_LOG_BASE:
                    return log(calculate_func(node->func.arg, x)) / log(node->func.base);

                case FUNC_EXP:
                    return exp(calculate_func(node->func.arg, x));
            }

            break;
    }

    return 0;
}



Function *get_user_function() {

    printf("You can enter mathematical equations using the rules below that:\n\n");

    printf("  Supported functions:\n");
    printf("  Trigonometric - sin(x), cos(x), tan(x), cot(x)..\n");
    printf("  Inverse Trigonometric - arcsin(x), arccos(x), arctan(x), arccot(x)..\n");
    printf("  Natural Log (lnx)  - log(x)..\n");
    printf("  Base Log - log_n(x) (use any base for n, like log_10(x))..\n");
    printf("  Exponential Functions -> e^x, exp(x), exp(2x), 2^x..\n\n");

    printf("  - For e number, you can use 2.718 and for pi number, you can use 3.1415.\n");
    printf("  - You must use radians instead of degrees in trigonometric functions.\n");

    printf("Please enter your function:\n> ");
    scanf(" %[^\n]", buffer);

    input = buffer;
    position = 0;

    return addsub_parser();
}

int main() {

    int operator; 

    printf("---------------------------------------------------------\n");
    printf("Quit: 0\nBisection: 1\nRegula-Falsi: 2\nNewton-Raphson: 3\nInverse Matrix: 4\nCholesky Method: 5\nGauss-Seidal: 6\nNumerical differentiation: 7\nSimpson's Rule: 8\nTrapezoidal Rule: 9\nGregory-Newton: 10\n");
    printf("---------------------------------------------------------\n");
   
    printf("Which operation do you want to do? ");
    scanf("%d", &operator);


    while (operator != 0) {
    if (operator == 1) {
        double a, b, max_error;
        int max_iter;

        Function *tree = get_user_function();

        printf("Enter a value: ");
        scanf("%lf", &a);

        printf("Enter b value: ");
        scanf("%lf", &b);

        if (fabs(calculate_func(tree, a)) < 1e-9 || fabs(calculate_func(tree, b)) < 1e-9){
            printf("One of the values you just entered is already a root!\n");
        }

        else {
        printf("Enter max error: ");
        scanf("%lf", &max_error);

        printf("Enter maximum iterations: ");
        scanf("%d", &max_iter);


        double root_value = bisection(tree, a, b, max_error, max_iter);
        printf("\nApproximate root: %.6lf\n", root_value);
        }

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    if (operator == 2){

        double a, b, max_error;
        int max_iter;

        Function *tree = get_user_function();

        printf("Enter the a value? ");
        scanf("%lf", &a);

        printf("Enter the b value? ");
        scanf("%lf", &b);

        if (fabs(calculate_func(tree, a)) < 1e-9 || fabs(calculate_func(tree, b)) < 1e-9){
            printf("One of the values you just entered is already a root!\n");     
        }

        else {
        printf("Enter max error? ");
        scanf("%lf", &max_error);

        printf("Enter maximum iterations? ");
        scanf("%d", &max_iter);

        double root_value = regula_falsi(tree, a, b, max_error, max_iter);
        printf("\nApproximate root: %.6lf\n", root_value);
        }

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    if (operator == 3){

        double x_start, max_error;
        int max_iter;

        Function *tree = get_user_function();

        printf("Enter the starting point for this method? ");
        scanf("%lf", &x_start);

        if (fabs(calculate_func(tree, x_start)) < 1e-9){
            printf("One of the values you just entered is already a root!\n");    
        }

        else {
        printf("Enter max error? ");
        scanf("%lf", &max_error);

        printf("Enter maximum iterations? ");
        scanf("%d", &max_iter);

        double root_value = newton_raphson(tree, x_start, max_error, max_iter);
        printf("\nApproximate root: %.6lf\n", root_value);
        }

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    if (operator == 4){
        int n;
        int i, j;

        printf("Enter the dimensions of your matrix (NxN)? ");
        scanf("%d", &n);

        double** matrix = get_matrix(n);
        double** inv_matrix = inverse_matrix(matrix, n);
        printf("-----------------------------------------------\n");

        printf("Original Matrix: \n\n");
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                printf("%.4lf ", matrix[i][j]);
            }
            printf("\n");
        }

        printf("-----------------------------------------------\n");
        
        if (inv_matrix != NULL) {
        
        printf("Inverse Matrix: \n\n");
        for (i = 0; i < n; i++){    
            for (j = 0; j < n; j++){
                printf("%.4lf ", inv_matrix[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < n; i++) {

            free(matrix[i]);
            free(inv_matrix[i]);
        }

        free(matrix);
        free(inv_matrix);

        printf("-----------------------------------------------\n");

    }

        else {
            
            printf("Matrix is singular and cannot be inverted.\n");
            printf("-----------------------------------------------\n");
        }

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    if (operator == 5) {
        int i, n;

        printf("Enter the dimension of the matrix (NxN)? ");
        scanf("%d", &n);

        double** matrix = get_matrix(n);
        lu_decomposition(matrix, n);

        for (i = 0; i < n; i++){
            free(matrix[i]);
        }

        free(matrix);

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);
    }


    if (operator == 6){
        int n, max_iter;
        int i, j;
        double max_error;

        printf("Enter the dimensions of your matrix (NxN)? ");
        scanf("%d", &n);

        printf("Enter max iterations? ");  
        scanf("%d", &max_iter);

        printf("Enter max error? ");
        scanf("%lf", &max_error);

        printf("------------------------------------------\n");

        double** matrix = get_matrix(n);
        double* results = (double*)malloc(n * sizeof(double));

        printf("\n------------------------------------------\n");

        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                printf("%.3lf ", matrix[i][j]);
            }
            printf("\n");
        }

        printf("------------------------------------------\n");
        int iter = gauss_seidel(matrix, n, max_iter, max_error, results);

        printf("-----------------------------------------------\n");
        
        if(iter != -1) {
        for (i = 0; i < n; i++){
            printf("\nx[%d] = %.3lf", i+1, results[i]);
        }
    }
        
        for (i = 0; i < n; i++){
            free(matrix[i]);
        }
        
        free(matrix);
        free(results);
    

        printf("\n\nWhich operation do you want to do? ");
        scanf("%d", &operator);

    }



    if (operator == 7){
        
        double x, h;

        Function *tree = get_user_function();
        
        printf("At what x value do you want to calculate the derivative? ");
        scanf("%lf", &x);

        printf("What will be the h value? (recommended to be small like 0.0001) ");
        scanf("%lf", &h);


        Derivatives derivatives = numerical_differentiation(tree, h, x);

        printf("Forward Difference Derivative: %.5lf\n", derivatives.forward_derivative);
        printf("Backward Difference Derivative: %.5lf\n", derivatives.backward_derivative);
        printf("Central Difference Derivative: %.5lf\n", derivatives.central_derivative);
        


        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    if (operator == 8){
        double a, b;
        int n;
        
        Function *tree = get_user_function();

        printf("Lower limit of the integration? ");
        scanf("%lf", &a);
    
        printf("Upper limit of the integration? ");
        scanf("%lf", &b);
    
        printf("How many parts do you want to split the integral into? ");
        scanf("%d", &n);
    
        simpson_integral(tree, a, b, n);

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);   

    }

    if (operator == 9){
        double a, b;
        int n;
        Function *tree = get_user_function();

        printf("Lower limit of the integration? ");
        scanf("%lf", &a);

        printf("Upper limit of the integration? ");
        scanf("%lf", &b);

        printf("Enter number of intervals(n)? ");
        scanf("%d", &n);

        double result = trapezoidal_rule(tree, a, b, n);
        printf("\nApproximate integral: %.5lf\n", result);

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    if (operator == 10){
        double a, b, x;
        int n;

        gregory_newton_interpolation();

        printf("Which operation do you want to do? ");
        scanf("%d", &operator);

    }

    }

    if(operator == 0) {
    printf("The program is closing...");
    return 0;
    }
    
}




double **get_matrix(int n){
    int i, j;
    double **matrix = (double **)malloc(n * sizeof(double*));
    if (matrix == NULL){
        printf("Memory error!");
        return NULL;
    }

    for (i = 0; i < n; i++){
        matrix[i] = (double *)malloc(n * sizeof(double));
        
        if (matrix[i] == NULL){
            printf("Memory error!");
            return NULL;
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Enter element [%d][%d]: ",i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    return matrix;
}

double bisection(Function *root, double a, double b, double max_error, int max_iter) {
    double fa = calculate_func(root, a);
    double fb = calculate_func(root, b);

    if (fa * fb > 0) {
        printf("f(a) and f(b) have the same sign. No root in this interval.\n");
        return NAN;
    }

    double c, fc, previous_c = 0.0;
    int iter = 0;

    while (iter < max_iter) {
        c = (a + b) / 2.0;
        fc = calculate_func(root, c);

        printf("Iteration %d\n", iter + 1);
        printf("------------------------------\n");
        printf("a = %.7lf\n", a);
        printf("b = %.7lf\n", b);
        printf("c = %.7lf\n", c);
        printf("f(a) = %.7lf\n", fa);
        printf("f(b) = %.7lf\n", fb);
        printf("f(c) = %.7lf\n\n", fc);

        if (fc == 0 || fabs(c - previous_c) < max_error) {
            return c;
        }

        if (fa * fc < 0){
            b = c;
            fb = fc;
        }

        if (fb * fc < 0){
            a = c;
            fa = fc;
        }

        previous_c = c;
        iter++;
    }

    return (a + b) / 2.0;
}

double regula_falsi(Function *root, double a, double b, double max_error, int max_iter){
    double fa = calculate_func(root,a);
    double fb = calculate_func(root,b);

    if (fa * fb > 0){
        printf("f(a) and f(b) have same sign. There are no roots in this area.");
        return NAN;
    }

    double c, fc, previous_c = 0.0;
    int iter = 0;   

    while (iter < max_iter){

        c = (b*fa - a*fb) / (fa-fb);
        fc = calculate_func(root, c);

        printf("Iteration %d\n", iter + 1);
        printf("------------------------------\n");
        printf("a = %.7lf\n", a);
        printf("b = %.7lf\n", b);
        printf("c = %.7lf\n", c);
        printf("f(a) = %.7lf\n", fa);
        printf("f(b) = %.7lf\n", fb);
        printf("f(c) = %.7lf\n\n", fc);

        if (fc == 0 || fabs(c - previous_c) < max_error){
            return c;
        }
        
        if (fa * fc < 0){
            b = c;
            fb = fc;
        }

        if (fb * fc < 0){
            a = c;
            fa = fc;

        }
        
        previous_c = c;
        iter++;

    }

    return (a+b) / 2.0;

}

double newton_raphson(Function *root, double start, double max_error, int max_iter){
    double c, fc, fstart;
    double h = 0.001;
    int iter = 0;
    Derivatives derivatives = numerical_differentiation(root, h, start);   
    fstart = calculate_func(root, start);
    
    while (iter < max_iter){
        c = start - (fstart / derivatives.central_derivative);
        fc = calculate_func(root, c);

        printf("Iteration %d\n", iter + 1);
        printf("------------------------------\n");
        printf("xn = %.7lf\n", start);
        printf("xn+1 = %.7lf\n", c);
        printf("f(xn) = %.7lf\n", fstart);
        printf("f(xn+1) = %.7lf\n\n", fc);
        
        if (fc == 0 || fabs(c - start) < max_error){
            return c;
        }

        start = c;
        fstart = calculate_func(root,start);
        derivatives = numerical_differentiation(root, h, start);

        iter++;
    }

    return start;

}

double** inverse_matrix(double **org_matrix, int n) {
    int i, j, k;
    double **temp_matrix, **inv_matrix;


    temp_matrix = (double **)malloc(n * sizeof(double *));
    inv_matrix = (double **)malloc(n * sizeof(double *));

    if (temp_matrix == NULL || inv_matrix == NULL) {
        printf("Memory error!\n");
        return NULL;
    }

    for (i = 0; i < n; i++){
        temp_matrix[i] = (double *)malloc(n * sizeof(double));
        inv_matrix[i] = (double *)malloc(n * sizeof(double));

        if (temp_matrix[i] == NULL || inv_matrix[i] == NULL) {
            printf("Memory error!\n");
            return NULL;
        }
    }

 
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            temp_matrix[i][j] = org_matrix[i][j];
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j){
                inv_matrix[i][j] = 1.0;
            } 
            
            else {
                inv_matrix[i][j] = 0.0;
            }
        }
    }

    for (i = 0; i < n; i++) {

        if (temp_matrix[i][i] == 0.0) {
            int found = 0;
            for (k = i + 1; k < n; k++) {
                if (temp_matrix[k][i] != 0.0) {

                    for (j = 0; j < n; j++) {
                        double temp = temp_matrix[i][j];
                        temp_matrix[i][j] = temp_matrix[k][j];
                        temp_matrix[k][j] = temp;

                        temp = inv_matrix[i][j];
                        inv_matrix[i][j] = inv_matrix[k][j];
                        inv_matrix[k][j] = temp;
                    }
                    
                    found = 1;
                }
            }
            if (!found) {
                return NULL;
            }
        }


        double pivot = temp_matrix[i][i];
        for (j = 0; j < n; j++) {
            temp_matrix[i][j] /= pivot;
            inv_matrix[i][j] /= pivot;
        }

        for (k = 0; k < n; k++) {
            if (k != i) {
                double factor = temp_matrix[k][i];
                for (j = 0; j < n; j++) {
                    temp_matrix[k][j] -= factor * temp_matrix[i][j];
                    inv_matrix[k][j] -= factor * inv_matrix[i][j];
                }
            }
        }
    }

    return inv_matrix;
}

double** lu_decomposition(double** org_matrix, int n) {
    int i, j, k;

    double** Lower = (double**)malloc(n * sizeof(double*));
    double** Upper = (double**)malloc(n * sizeof(double*));

    if (Lower == NULL || Upper == NULL){
        printf("Memory error!");
        return NULL;
    }
    
    for (i = 0; i < n; i++) {
        Lower[i] = (double*)calloc(n, sizeof(double));
        Upper[i] = (double*)calloc(n, sizeof(double));
        if (Lower[i] == NULL || Upper[i] == NULL){
            printf("Memory error!");
            return NULL;
        }
    }

    for (i = 0; i < n; i++) {
        for (k = i; k < n; k++) {

            double sum = 0.0;
            for (j = 0; j < i; j++) {

                sum += Lower[i][j] * Upper[j][k];
            }

            Upper[i][k] = org_matrix[i][k] - sum;
        }

        for (k = i; k < n; k++) {
            if (i == k) {
                Lower[i][i] = 1.0;

            } 
            
            else {
                double sum = 0.0;
                for (j = 0; j < i; j++) {

                    sum += Lower[k][j] * Upper[j][i];
                }

                Lower[k][i] = (org_matrix[k][i] - sum) / Upper[i][i];
            }
        }
    }

    double determinant = 1.0;
    for (i = 0; i < n; i++){
        determinant *= Upper[i][i];
    }

    if (fabs(determinant) < 1e-9){
        printf("Matrix is singular. Cholesky method cannot be calculated! \n");
    }

    else {
    printf("\n-----------------------------------------------");
    printf("\nThe original matrix: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.4lf ", org_matrix[i][j]);
        }

        printf("\n");
    }

    printf("\nLower matrix: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.4lf ", Lower[i][j]);
        }

        printf("\n");
    }

    printf("\nUpper matrix: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.4lf ", Upper[i][j]);
        }

        printf("\n");
    }

    printf("-----------------------------------------------\n");

    double* b = (double*)malloc(n * sizeof(double));
    printf("\nEnter the result vector b (Ax = b): \n");

    for (i = 0; i < n; i++) {
        printf("b[%d]: ", i);
        scanf("%lf", &b[i]);

    }

    double* y = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        y[i] = b[i];

        for (j = 0; j < i; j++) {
            y[i] -= Lower[i][j] * y[j];
        }

        y[i] /= Lower[i][i];

    }

    double* x = (double*)malloc(n * sizeof(double));
    for (i = n - 1; i >= 0; i--) {
        x[i] = y[i];

        for (j = i + 1; j < n; j++) {
            x[i] -= Upper[i][j] * x[j];
        }

        x[i] /= Upper[i][i];

    }


    printf("\nSolutions: \n");

    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);

    }

    printf("-----------------------------------------------\n");


    for (i = 0; i < n; i++) {
        free(Lower[i]);
        free(Upper[i]);
    }

    free(Lower);
    free(Upper);
    free(b);
    free(y);
    free(x);

    }

    return NULL;
}


int gauss_seidel(double** org_matrix, int n, int max_iter, double max_error, double* result) {
    int i, j, k, iter = 0;
    double sum;


    double* results = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));
    double* x_old = (double*)malloc(n * sizeof(double));

    printf("Enter the results (b vector of Ax = B)\n");
    for (i = 0; i < n; i++) {
        printf("Enter the result for equation %d? ", i + 1);
        scanf("%lf", &results[i]);
    }

    for (i = 0; i < n; i++) {
        double max_val = org_matrix[i][i];
        int max_row = i;
    

        for (k = i + 1; k < n; k++) {
            if (org_matrix[k][i] > max_val) {
                max_val = org_matrix[k][i];
                max_row = k;
            }
        }
    
        if (max_row != i) {
            for (j = 0; j < n; j++) {
                double temp = org_matrix[i][j];
                org_matrix[i][j] = org_matrix[max_row][j];
                org_matrix[max_row][j] = temp;
            }

            double temp_result = results[i];
            results[i] = results[max_row];
            results[max_row] = temp_result;
        }

    }

    printf("------------------------------------------\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%.4lf ", org_matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nEnter the initially estimated values of the variables.\n");
    for (i = 0; i < n; i++) {
        printf("Enter the initially estimated value for x[%d]? ", i);
        scanf("%lf", &x[i]);
        x_old[i] = x[i];
    }

    double error = max_error + 1;

    while (error > max_error && iter < max_iter) {
        error = 0.0;

        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < n; j++) {

                if (j != i) {
                    sum += org_matrix[i][j] * x[j];
                }
            }

            x[i] = (results[i] - sum) / org_matrix[i][i];
            error += fabs(x[i] - x_old[i]);
            x_old[i] = x[i];
        }

    iter++;

    }

    for (i = 0; i < n; i++)
        result[i] = x[i];


    return iter;
}

Derivatives numerical_differentiation(Function *root, double h, double x){ 


    double fxplush = calculate_func(root, x+h);
    double fxminush = calculate_func(root, x-h);
    double fx = calculate_func(root, x);

    Derivatives result;
    result.forward_derivative = (fxplush - fx) / h;
    result.backward_derivative = (fx - fxminush) / h;
    result.central_derivative = (fxplush - fxminush) / (2 * h);

    return result;

    
}

void simpson_integral(Function *root, double a, double b, int n) {
    int i;
    
    double interval_length_13 = (b - a) / n;
    double result_13 = 0.0;

    for (i = 0; i < n; i++) {
        double sub13_a = a + i * interval_length_13;
        double sub13_b = sub13_a + interval_length_13;
        double h = (sub13_b - sub13_a) / 2.0;

        double x13_0 = sub13_a;
        double x13_1 = sub13_a + h;
        double x13_2 = sub13_b;

        double sum = calculate_func(root, x13_0) + 4 * calculate_func(root, x13_1) + calculate_func(root, x13_2);
        result_13 += (sub13_b - sub13_a) * sum / 6.0;

    }

    printf("Simpson 1/3 Result: %.5lf\n", result_13);
    
    double interval_length_38 = (b - a) / n;
    double result_38 = 0.0;

    for (i = 0; i < n; i++) {
        double sub38_a = a + i * interval_length_38;
        double sub38_b = sub38_a + interval_length_38;
        double h = (sub38_b - sub38_a) / 3.0;

        double x38_0 = sub38_a;
        double x38_1 = sub38_a + h;
        double x38_2 = sub38_a + 2 * h;
        double x38_3 = sub38_b;

        double sum = calculate_func(root, x38_0) + 3 * calculate_func(root, x38_1) + 3 * calculate_func(root, x38_2) + calculate_func(root, x38_3);
        result_38 += (sub38_b - sub38_a) * sum / 8.0;
    }

    printf("Simpson 3/8 Result: %.5lf\n", result_38);

}

double trapezoidal_rule(Function *root, double a, double b, int n){
    int i;
    double h = (b-a) / n;
    double sum = (calculate_func(root,a) + calculate_func(root,b))/2 ;

    for (i=1; i<n; i++){
        double x = a + i*h;
        sum += calculate_func(root,x);
    }

    return (h) * sum;

}

void gregory_newton_interpolation() {
    int i, j, n;
    double point;
    double p_term = 1;
    int fact = 1;

    printf("How many points will you enter for the Gregory-Newton Interpolation? ");
    scanf("%d", &n);

    double* x_values = (double*)malloc(n * sizeof(double));
    double* fx_results = (double*)malloc(n * sizeof(double));
    double** diff = (double**)malloc(n * sizeof(double*));

    for (i = 0; i < n; i++) {
        diff[i] = (double*)calloc(n, sizeof(double));
    }

    if (x_values == NULL || fx_results == NULL || diff == NULL) {
        printf("Memory error!\n");
        return;
    }

    printf("Please enter x values. (The difference between x values must be same!)\n");
    for (i = 0; i < n; i++) {
        printf("x%d: ", i+1);
        scanf("%lf", &x_values[i]);
    }

    double difference = x_values[1] - x_values[0];

    for (i = 0; i < n; i++) {
        printf("f(%.4lf): ", x_values[i]);
        scanf("%lf", &fx_results[i]);

        diff[i][0] = fx_results[i];
    }

    double sum = fx_results[0];

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    printf("\nDifference Table:\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("%10.6lf ", diff[i][j]);
        }

        printf("\n");
    }

    printf("\nWhich value you want to calculate with this method? ");
    scanf("%lf", &point);

    double p = (point - x_values[0]) / difference;

    for (i = 1; i < n; i++) {
        p_term = p_term * (p - (i - 1));
        fact = fact * i;
        sum += (p_term * diff[0][i]) / fact;
    }

    printf("\nGregory-Newton Interpolation result: %.6lf\n", sum);

    for (i = 0; i < n; i++) {
        free(diff[i]);
    }

    free(diff);
    free(fx_results);
    free(x_values);
    
}


