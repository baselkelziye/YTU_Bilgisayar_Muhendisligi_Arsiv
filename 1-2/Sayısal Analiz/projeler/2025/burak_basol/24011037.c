/*
 * File:         24011037.c
 * Description:  Numerical Analysis semester project
 * Author:       Burak Basol
 * Created:      2025-04-08
 * Updated:      2025-05-18
 * Version:      3.0
 */

 //---------------------------------------------Include Begin---------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>  

#define _USE_MATH_DEFINES
#include <math.h>

//----------------------------------------------Include End----------------------------------------------//

//----------------------------------------------strndup Implementation-----------------------------------//
#ifndef _GNU_SOURCE
#if !defined(strndup) && (!defined(__linux__) && !defined(__APPLE__))

char *strndup(const char *s, size_t n) {
    size_t len = 0;
    while (len < n && *(s + len) != '\0') {
        len++;
    }
    char *new_str = (char *)malloc(len + 1);
    if (new_str == NULL) {
        return NULL;
    }
    memcpy(new_str, s, len);
    *(new_str + len) = '\0';
    return new_str;
}
#endif
#endif
//----------------------------------------------strndup Implementation End-------------------------------//


//----------------------------------------------Struct Definitions Begin---------------------------------//

typedef enum {
    T_NUMBER,
    T_VARIABLE,
    T_CONSTANT,
    T_FUNCTION,
    T_OPERATOR,
    T_LPAREN,
    T_RPAREN
} TokenType;

typedef struct Token {
    TokenType type;
    char *lexeme;
    struct Token *next;
} Token;

typedef enum NodeType {
    N_NUMBER,
    N_VARIABLE,
    N_OPERATOR,
    N_FUNCTION
} NodeType;

typedef struct Node {
    NodeType type;
    union {
        double number;
        char op;
        char *name;
    } value;
    struct Node *left, *right, *arg;
} Node;

typedef struct {
    double **data;
    int size;
} Matrix;

typedef struct {
    double **data;
    int n_rows;
    int n_cols;
} AugmentedMatrix;

//----------------------------------------------Struct Definitions End-----------------------------------//

//----------------------------------------------Define Begin---------------------------------------------//

#define EPSILON    1e-6 
#define MAX_ITER   1000

//----------------------------------------------Define End-----------------------------------------------//

//----------------------------------------------Prototype Begin------------------------------------------//

void mainWindow();

char *getEquationString();
Matrix *getMatrixData();
AugmentedMatrix *getAugmentedMatrixData();
char *readStringInternal();
void clearScreen();
void flushInputBuffer();

Token *tokenize(const char *input_str);
Node *parse_expression(Token **curr);
Node *parse_term(Token **curr);
Node *parse_factor(Token **curr);
void  print_ast(Node *node, int level);
void free_ast(Node *node);
void free_tokens(Token *head);

Node *make_number_node(double number);
Node *make_variable_node(const char *var_name);
Node *make_operator_node(char op, Node *left, Node *right);
Node *make_function_node(const char *fname, Node *arg);

double evaluate(Node *node, double x_val);

double cotan(double x);
double sec(double x);
double csec(double x);
double actan(double x);
double asec(double x);
double acsec(double x);
double log_based(double x, double base);

void bisection_method(const char *equation_str);
void regula_falsi_method(const char *equation_str);
void newton_raphson_method(const char *equation_str);
void invert_matrix_method(Matrix *matrix_obj);
void cholesky_decomposition_method(Matrix *matrix_obj);
void gauss_seidel_method(AugmentedMatrix *aug_matrix);
void numerical_derivative_method(const char *equation_str);
void simpson_integration_method(const char *equation_str);
void trapezoidal_integration_method(const char *equation_str);
void gregory_newton_interpolation();

void freeMatrix(Matrix *matrix_obj);
void freeAugmentedMatrix(AugmentedMatrix *aug_matrix_obj);

//----------------------------------------------Prototype End--------------------------------------------//

//----------------------------------------------User Code Begin------------------------------------------//

int main() {
    int temp_choice = 1;
    int valid_choice = 1;
    do {
        clearScreen();
        mainWindow();

        printf("If you want to use another method, type 1 (or any other number to exit):\n");
        if (scanf("%d", &temp_choice) != 1) {
            valid_choice = 0;
            flushInputBuffer();
        }
        else {
            flushInputBuffer();
            if (temp_choice != 1) {
                valid_choice = 0;
            }
        }
    } while (valid_choice == 1);
    printf("Exiting program.\n");
    return 0;
}
//----------------------------------------------User Code End--------------------------------------------//

//----------------------------------------------Function Begin-------------------------------------------//

void mainWindow() {
    printf("  1. Bisection Method\n");
    printf("  2. Regula-Falsi Method\n");
    printf("  3. Newton-Raphson Method\n");
    printf("  4. Inverse of an NxN Matrix\n");
    printf("  5. Cholesky Method\n");
    printf("  6. Gauss-Seidel Method\n");
    printf("  7. Numerical Derivative\n");
    printf("  8. Simpson's Method\n");
    printf("  9. Trapezoidal Method\n");
    printf("  10. Gregory-Newton Interpolation\n");
    printf("Write the index of the method u want to use:\n");

    int choice;
    char *equation_str = NULL;
    Matrix *matrix_obj = NULL;
    AugmentedMatrix *aug_matrix_obj = NULL;

    if (scanf("%d", &choice) != 1) {
        flushInputBuffer();
        printf("Invalid input. Please enter a number corresponding to a method.\n\n");
        return;
    }
    flushInputBuffer();

    if (choice == 1) {
        equation_str = getEquationString();
        if (equation_str) {
            bisection_method(equation_str);
            free(equation_str);
        }
    }
    else if (choice == 2) {
        equation_str = getEquationString();
        if (equation_str) {
            regula_falsi_method(equation_str);
            free(equation_str);
        }
    }
    else if (choice == 3) {
        equation_str = getEquationString();
        if (equation_str) {
            newton_raphson_method(equation_str);
            free(equation_str);
        }
    }
    else if (choice == 4) {
        matrix_obj = getMatrixData();
        if (matrix_obj) {
            invert_matrix_method(matrix_obj);
            freeMatrix(matrix_obj);
        }
    }
    else if (choice == 5) {
        matrix_obj = getMatrixData();
        if (matrix_obj) {
            cholesky_decomposition_method(matrix_obj);
            freeMatrix(matrix_obj);
        }
    }
    else if (choice == 6) {
        aug_matrix_obj = getAugmentedMatrixData();
        if (aug_matrix_obj) {
            gauss_seidel_method(aug_matrix_obj);
            freeAugmentedMatrix(aug_matrix_obj);
        }
    }
    else if (choice == 7) {
        equation_str = getEquationString();
        if (equation_str) {
            numerical_derivative_method(equation_str);
            free(equation_str);
        }
    }
    else if (choice == 8) {
        equation_str = getEquationString();
        if (equation_str) {
            simpson_integration_method(equation_str);
            free(equation_str);
        }
    }
    else if (choice == 9) {
        equation_str = getEquationString();
        if (equation_str) {
            trapezoidal_integration_method(equation_str);
            free(equation_str);
        }
    }
    else if (choice == 10) {
        gregory_newton_interpolation();
    }
    else {
        printf("You have entered an invalid choice.\n\n");
    }
}

char *getEquationString() {
    printf("\nWrite the equation: ( ^ is power operator, _ in log_ for base)\n");
    printf("Supported constants: e, pi. Supported variable: x.\n");
    printf("Functions: sin, cos, tan, cot, sec, csc, asin, acos, atan, acot, asec, acsc, exp, log (natural), ln (natural), log_BASE (e.g., log_10, log_x)\n");

    char *eq_str = readStringInternal();
    if (eq_str == NULL) {
        printf("Failed to read equation string.\n");
        return NULL;
    }

    return eq_str;
}

Matrix *getMatrixData() {
    Matrix *matrix_obj = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_obj) {
        printf("Memory allocation failed for Matrix struct.\n");
        return NULL;
    }
    matrix_obj->data = NULL;
    matrix_obj->size = 0;

    int i, j;
    int n_size;

    printf("\nWrite the size N of the NxN matrix:\n");
    if (scanf("%d", &n_size) != 1 || n_size <= 0) {
        flushInputBuffer();
        printf("Invalid matrix size.\n");
        free(matrix_obj);
        return NULL;
    }
    flushInputBuffer();

    matrix_obj->size = n_size;
    matrix_obj->data = (double **)malloc(n_size * sizeof(double *));
    if (!matrix_obj->data) {
        printf("Memory allocation failed for matrix rows.\n");
        free(matrix_obj);
        return NULL;
    }
    for (i = 0; i < n_size; i++) {
        *(matrix_obj->data + i) = (double *)malloc(n_size * sizeof(double));
        if (!(*(matrix_obj->data + i))) {
            printf("Memory allocation failed for matrix column %d.\n", i);
            for (j = 0; j < i; j++) {
                free(*(matrix_obj->data + j));
            }
            free(matrix_obj->data);
            free(matrix_obj);
            return NULL;
        }
    }

    printf("Write the matrix's values (row by row, %d values total for %dx%d matrix):\n", n_size * n_size, n_size, n_size);
    int read_success = 1;
    for (i = 0; i < n_size && read_success; i++) {
        for (j = 0; j < n_size && read_success; j++) {
            if (scanf("%lf", (*(matrix_obj->data + i) + j)) != 1) { 
                flushInputBuffer();
                printf("Invalid input for matrix element [%d][%d]. Aborting matrix input.\n", i, j);
                read_success = 0;
            }
        }
    }

    if (!read_success) {
        freeMatrix(matrix_obj);
        return NULL;
    }

    return matrix_obj;
}

AugmentedMatrix *getAugmentedMatrixData() {
    AugmentedMatrix *aug_matrix_obj = (AugmentedMatrix *)malloc(sizeof(AugmentedMatrix));
    if (!aug_matrix_obj) {
        printf("Memory allocation failed for AugmentedMatrix struct.\n");
        return NULL;
    }
    aug_matrix_obj->data = NULL;
    aug_matrix_obj->n_rows = 0;
    aug_matrix_obj->n_cols = 0;

    int n_rows_local, i, j;

    printf("\nEnter the size N (number of rows/equations) for the augmented matrix [A|b]:\n");
    if (scanf("%d", &n_rows_local) != 1 || n_rows_local <= 0) {
        flushInputBuffer();
        printf("Invalid size N for augmented matrix.\n");
        free(aug_matrix_obj);
        return NULL;
    }
    flushInputBuffer();

    aug_matrix_obj->n_rows = n_rows_local;
    aug_matrix_obj->n_cols = n_rows_local + 1;

    aug_matrix_obj->data = (double **)malloc(aug_matrix_obj->n_rows * sizeof(double *));
    if (!aug_matrix_obj->data) {
        printf("Memory allocation failed for augmented matrix rows.\n");
        free(aug_matrix_obj);
        return NULL;
    }
    for (i = 0; i < aug_matrix_obj->n_rows; i++) {
        *(aug_matrix_obj->data + i) = (double *)malloc(aug_matrix_obj->n_cols * sizeof(double));
        if (!(*(aug_matrix_obj->data + i))) {
            printf("Memory allocation failed for augmented matrix row %d columns.\n", i);
            for (j = 0; j < i; j++) {
                free(*(aug_matrix_obj->data + j));
            }
            free(aug_matrix_obj->data);
            free(aug_matrix_obj);
            return NULL;
        }
    }

    printf("Enter the augmented matrix [A|b] values, row by row (%d rows, %d columns):\n", aug_matrix_obj->n_rows, aug_matrix_obj->n_cols);
    int read_success = 1;
    for (i = 0; i < aug_matrix_obj->n_rows && read_success; ++i) {
        for (j = 0; j < aug_matrix_obj->n_cols && read_success; ++j) {
            if (scanf("%lf", (*(aug_matrix_obj->data + i) + j)) != 1) { // Pointer arithmetic
                flushInputBuffer(); printf("Invalid input for augmented matrix element [%d][%d].\n", i, j);
                read_success = 0;
            }
        }
    }

    if (!read_success) {
        freeAugmentedMatrix(aug_matrix_obj);
        return NULL;
    }

    return aug_matrix_obj;
}

char *readStringInternal() {
    int ch;
    char *temp_buffer = NULL;
    int current_len = 0;
    int capacity = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ') {
            if (current_len + 1 >= capacity) {
                capacity = (capacity == 0) ? 16 : capacity * 2;
                char *new_buffer = realloc(temp_buffer, capacity);
                if (!new_buffer) {
                    fprintf(stderr, "Error: Memory reallocation failed in readStringInternal.\n");
                    free(temp_buffer);
                    return NULL;
                }
                temp_buffer = new_buffer;
            }
            *(temp_buffer + current_len) = (char)ch;
            current_len++;
        }
    }

    if (temp_buffer) {
        *(temp_buffer + current_len) = '\0';
        return temp_buffer;
    }
    else {
        char *empty_str = strdup("");
        if (!empty_str) {
            fprintf(stderr, "Error: Memory allocation failed for empty string in readStringInternal.\n");
        }
        return empty_str;
    }
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void freeMatrix(Matrix *matrix_obj) {
    if (matrix_obj) {
        if (matrix_obj->data) {
            for (int i = 0; i < matrix_obj->size; i++) {
                if (*(matrix_obj->data + i)) {
                    free(*(matrix_obj->data + i));
                }
            }
            free(matrix_obj->data);
        }
        free(matrix_obj);
    }
}

void freeAugmentedMatrix(AugmentedMatrix *aug_matrix_obj) {
    if (aug_matrix_obj) {
        if (aug_matrix_obj->data) {
            for (int i = 0; i < aug_matrix_obj->n_rows; i++) {
                if (*(aug_matrix_obj->data + i)) {
                    free(*(aug_matrix_obj->data + i));
                }
            }
            free(aug_matrix_obj->data);
        }
        free(aug_matrix_obj);
    }
}

//----------------------------------------------Function End---------------------------------------------//

//----------------------------------------------Tokenizer/Parser Begin-----------------------------------//

Token *tokenize(const char *input_str) {
    Token *head = NULL, *tail = NULL;
    int i = 0;
    int input_len = strlen(input_str);
    int running = 1;

    while (i < input_len && running) {
        Token *tok = (Token *)malloc(sizeof(Token));
        if (!tok) {
            fprintf(stderr, "Error: Memory allocation failed for Token in tokenize.\n");
            free_tokens(head);
            return NULL;
        }
        tok->next = NULL;

        if (isdigit(*(input_str + i)) || (*(input_str + i) == '.' && i + 1 < input_len && isdigit(*(input_str + i + 1)))) {
            int j = i;
            while (j < input_len && (isdigit(*(input_str + j)) || *(input_str + j) == '.')) {
                j++;
            }
            tok->type = T_NUMBER;
            tok->lexeme = strndup(input_str + i, j - i);
            if (!tok->lexeme) {
                fprintf(stderr, "Error: Memory allocation failed for number lexeme.\n");
                free(tok); free_tokens(head); return NULL;
            }
            i = j;
        }
        else if (isalpha(*(input_str + i))) {
            int j = i;
            while (j < input_len && (isalnum(*(input_str + j)) || *(input_str + j) == '_')) {
                j++;
            }
            tok->lexeme = strndup(input_str + i, j - i);
            if (!tok->lexeme) {
                fprintf(stderr, "Error: Memory allocation failed for identifier lexeme.\n");
                free(tok); free_tokens(head); return NULL;
            }
            if (strcmp(tok->lexeme, "x") == 0) {
                tok->type = T_VARIABLE;
            }
            else if (strcmp(tok->lexeme, "e") == 0) {
                tok->type = T_CONSTANT;
            }
            else if (strcmp(tok->lexeme, "pi") == 0) {
                tok->type = T_CONSTANT;
            }
            else {
                tok->type = T_FUNCTION;
            }
            i = j;
        }
        else {
            char c = *(input_str + i);
            i++;
            char temp_lexeme[2] = { c, '\0' };
            tok->lexeme = strdup(temp_lexeme);
            if (!tok->lexeme) {
                fprintf(stderr, "Error: Memory allocation failed for operator/paren lexeme.\n");
                free(tok); free_tokens(head); return NULL;
            }

            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                tok->type = T_OPERATOR;
            }
            else if (c == '(') {
                tok->type = T_LPAREN;
            }
            else if (c == ')') {
                tok->type = T_RPAREN;
            }
            else {
                fprintf(stderr, "Warning: Unknown character '%c' in input, treating as operator.\n", c);
                tok->type = T_OPERATOR;
            }
        }

        if (!head) {
            head = tail = tok;
        }
        else {
            tail->next = tok;
            tail = tok;
        }
    }
    return head;
}

Node *parse_term(Token **cur) {
    Node *node = parse_factor(cur);
    if (!node) return NULL;

    int processing_term = 1;
    while (processing_term && *cur) {
        if ((*cur)->type == T_OPERATOR && ((*((*cur)->lexeme)) == '*' || (*((*cur)->lexeme)) == '/')) {
            char op = *((*cur)->lexeme);
            *cur = (*cur)->next;
            Node *rhs = parse_factor(cur);
            if (!rhs) { free_ast(node); return NULL; }
            Node *new_node = make_operator_node(op, node, rhs);
            if (!new_node) { free_ast(node); free_ast(rhs); return NULL; }
            node = new_node;
        }
        else if ((*cur)->type == T_NUMBER || (*cur)->type == T_VARIABLE ||
            (*cur)->type == T_CONSTANT || (*cur)->type == T_FUNCTION ||
            (*cur)->type == T_LPAREN) {
            Node *rhs = parse_factor(cur);
            if (!rhs) { free_ast(node); return NULL; }
            Node *new_node = make_operator_node('*', node, rhs);
            if (!new_node) { free_ast(node); free_ast(rhs); return NULL; }
            node = new_node;
        }
        else {
            processing_term = 0;
        }
    }
    return node;
}

Node *parse_factor(Token **cur) {
    if (!*cur) {
        fprintf(stderr, "Syntax Error: Unexpected end of expression in parse_factor.\n");
        return NULL;
    }

    Token *tok = *cur;
    Node *node = NULL;
    int factor_parsed = 0;

    if (tok->type == T_NUMBER) {
        double v = atof(tok->lexeme);
        node = make_number_node(v);
        if (node) { *cur = tok->next; factor_parsed = 1; }
    }
    else if (tok->type == T_VARIABLE) {
        node = make_variable_node(tok->lexeme);
        if (node) { *cur = tok->next; factor_parsed = 1; }
    }
    else if (tok->type == T_CONSTANT) {
        if (strcmp(tok->lexeme, "e") == 0) {
            node = make_number_node(M_E);
        }
        else if (strcmp(tok->lexeme, "pi") == 0) {
            node = make_number_node(M_PI);
        }
        else {
            fprintf(stderr, "Error: Unknown constant '%s'\n", tok->lexeme);
        }
        if (node) { *cur = tok->next; factor_parsed = 1; }
    }
    else if (tok->type == T_FUNCTION) {
        char *func_name = tok->lexeme;
        *cur = tok->next;
        Node *arg_node = NULL;
        int arg_parsed_ok = 1;
        if (*cur && (*cur)->type == T_LPAREN) {
            *cur = (*cur)->next;
            arg_node = parse_expression(cur);
            if (!arg_node) { arg_parsed_ok = 0; }
            else {
                if (*cur && (*cur)->type == T_RPAREN) {
                    *cur = (*cur)->next;
                }
                else {
                    fprintf(stderr, "Syntax Error: Missing ')' after function arguments for %s\n", func_name);
                    free_ast(arg_node); arg_parsed_ok = 0;
                }
            }
        }
        else {
            arg_node = parse_factor(cur);
            if (!arg_node) {
                fprintf(stderr, "Syntax Error: Missing argument for function %s\n", func_name);
                arg_parsed_ok = 0;
            }
        }
        if (arg_parsed_ok) {
            node = make_function_node(func_name, arg_node);
            if (node) { factor_parsed = 1; }
            else { free_ast(arg_node); }
        }
    }
    else if (tok->type == T_LPAREN) {
        *cur = tok->next;
        node = parse_expression(cur);
        if (node) {
            if (*cur && (*cur)->type == T_RPAREN) {
                *cur = (*cur)->next;
                factor_parsed = 1;
            }
            else {
                fprintf(stderr, "Syntax Error: Missing ')' in expression.\n");
                free_ast(node); node = NULL;
            }
        }
    }
    else if (tok->type == T_OPERATOR && *(tok->lexeme) == '-') {
        *cur = tok->next;
        Node *operand = parse_factor(cur);
        if (operand) {
            Node *zero_node = make_number_node(0.0);
            if (zero_node) {
                node = make_operator_node('-', zero_node, operand);
                if (node) { factor_parsed = 1; }
                else { free_ast(zero_node); free_ast(operand); }
            }
            else { free_ast(operand); }
        }
    }
    else {
        fprintf(stderr, "Syntax Error: Unexpected token '%s' in parse_factor.\n", tok->lexeme);
    }

    if (!factor_parsed && node == NULL) {
        return NULL;
    }

    if (*cur && (*cur)->type == T_OPERATOR && *((*cur)->lexeme) == '^') {
        if (!node) {
            fprintf(stderr, "Syntax Error: Missing base for exponentiation operator (^).\n");
            return NULL;
        }
        *cur = (*cur)->next;
        Node *exponent_node = parse_factor(cur);
        if (!exponent_node) {
            fprintf(stderr, "Syntax Error: Missing exponent for operator (^).\n");
            free_ast(node);
            return NULL;
        }
        Node *new_node = make_operator_node('^', node, exponent_node);
        if (!new_node) { free_ast(node); free_ast(exponent_node); return NULL; }
        node = new_node;
    }
    return node;
}

Node *parse_expression(Token **cur) {
    Node *node = parse_term(cur);
    if (!node) return NULL;

    int processing_expression = 1;
    while (processing_expression && *cur && (*cur)->type == T_OPERATOR && (*((*cur)->lexeme) == '+' || *((*cur)->lexeme) == '-')) {
        char op = *((*cur)->lexeme);
        *cur = (*cur)->next;
        Node *rhs = parse_term(cur);
        if (!rhs) { free_ast(node); return NULL; }
        Node *new_node = make_operator_node(op, node, rhs);
        if (!new_node) { free_ast(node); free_ast(rhs); return NULL; }
        node = new_node;
    }
    return node;
}

void print_ast(Node *node, int level) {
    if (!node) return;
    for (int i = 0; i < level * 2; i++) putchar(' ');

    if (node->type == N_NUMBER) {
        printf("NUMBER(%.2f)\n", node->value.number);
    }
    else if (node->type == N_VARIABLE) {
        printf("VARIABLE(%s)\n", node->value.name);
    }
    else if (node->type == N_OPERATOR) {
        printf("OPERATOR(%c)\n", node->value.op);
        print_ast(node->left, level + 1);
        print_ast(node->right, level + 1);
    }
    else if (node->type == N_FUNCTION) {
        printf("FUNCTION(%s)\n", node->value.name);
        print_ast(node->left, level + 1);
    }
}

void free_ast(Node *node) {
    if (node != NULL) {
        if (node->type == N_OPERATOR) {
            free_ast(node->left);
            free_ast(node->right);
        }
        else if (node->type == N_FUNCTION) {
            free_ast(node->left);
        }
        if (node->type == N_VARIABLE || node->type == N_FUNCTION) {
            if (node->value.name != NULL) {
                free(node->value.name);
            }
        }
        free(node);
    }
}

void free_tokens(Token *head) {
    Token *cur = head;
    Token *next;
    while (cur != NULL) {
        next = cur->next;
        if (cur->lexeme != NULL) {
            free(cur->lexeme);
        }
        free(cur);
        cur = next;
    }
}

Node *make_number_node(double number) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "Error: Malloc failed for number node.\n"); return NULL; }
    n->type = N_NUMBER;
    n->value.number = number;
    n->left = n->right = n->arg = NULL;
    return n;
}

Node *make_variable_node(const char *var_name) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "Error: Malloc failed for variable node.\n"); return NULL; }
    n->type = N_VARIABLE;
    n->value.name = strdup(var_name);
    if (!n->value.name) { fprintf(stderr, "Error: Strdup failed for var_name.\n"); free(n); return NULL; }
    n->left = n->right = n->arg = NULL;
    return n;
}

Node *make_operator_node(char op, Node *left, Node *right) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "Error: Malloc failed for operator node.\n"); return NULL; }
    n->type = N_OPERATOR;
    n->value.op = op;
    n->left = left;
    n->right = right;
    n->arg = NULL;
    return n;
}

Node *make_function_node(const char *func_name, Node *argument) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "Error: Malloc failed for function node.\n"); return NULL; }
    n->type = N_FUNCTION;
    n->value.name = strdup(func_name);
    if (!n->value.name) { fprintf(stderr, "Error: Strdup failed for func_name.\n"); free(n); return NULL; }
    n->left = argument;
    n->right = NULL;
    n->arg = argument;
    return n;
}

double evaluate(Node *node, double x_val) {
    if (node == NULL) {
        fprintf(stderr, "Error: Trying to evaluate a NULL AST node.\n");
        return NAN;
    }

    double result = NAN;

    if (node->type == N_NUMBER) {
        result = node->value.number;
    }
    else if (node->type == N_VARIABLE) {
        if (strcmp(node->value.name, "x") == 0) {
            result = x_val;
        }
        else {
            fprintf(stderr, "Error: Unknown variable '%s' in evaluate.\n", node->value.name);
        }
    }
    else if (node->type == N_OPERATOR) {
        double left_val = evaluate(node->left, x_val);
        double right_val = evaluate(node->right, x_val);

        if (!isnan(left_val) && !isnan(right_val)) {
            char op_char = node->value.op;
            if (op_char == '+') { result = left_val + right_val; }
            else if (op_char == '-') { result = left_val - right_val; }
            else if (op_char == '*') { result = left_val * right_val; }
            else if (op_char == '/') {
                if (fabs(right_val) < EPSILON) {
                    fprintf(stderr, "Error: Division by zero.\n");
                }
                else {
                    result = left_val / right_val;
                }
            }
            else if (op_char == '^') {
                result = pow(left_val, right_val);
            }
            else {
                fprintf(stderr, "Error: Unknown operator '%c' in evaluate.\n", op_char);
            }
        }
    }
    else if (node->type == N_FUNCTION) {
        double arg_val = evaluate(node->left, x_val);
        if (!isnan(arg_val)) {
            char *name = node->value.name;
            if (strcmp(name, "sin") == 0) { result = sin(arg_val); }
            else if (strcmp(name, "cos") == 0) { result = cos(arg_val); }
            else if (strcmp(name, "tan") == 0) { result = tan(arg_val); }
            else if (strcmp(name, "cot") == 0) { result = cotan(arg_val); }
            else if (strcmp(name, "sec") == 0) { result = sec(arg_val); }
            else if (strcmp(name, "csc") == 0) { result = csec(arg_val); }
            else if (strcmp(name, "asin") == 0) {
                if (arg_val < -1.0 || arg_val > 1.0) { fprintf(stderr, "Error: Argument out of domain for asin.\n"); }
                else { result = asin(arg_val); }
            }
            else if (strcmp(name, "acos") == 0) {
                if (arg_val < -1.0 || arg_val > 1.0) { fprintf(stderr, "Error: Argument out of domain for acos.\n"); }
                else { result = acos(arg_val); }
            }
            else if (strcmp(name, "atan") == 0) { result = atan(arg_val); }
            else if (strcmp(name, "acot") == 0) { result = actan(arg_val); }
            else if (strcmp(name, "asec") == 0) { result = asec(arg_val); }
            else if (strcmp(name, "acsc") == 0) { result = acsec(arg_val); }
            else if (strcmp(name, "exp") == 0) { result = exp(arg_val); }
            else if (strcmp(name, "log") == 0 || strcmp(name, "ln") == 0) {
                if (arg_val <= 0) { fprintf(stderr, "Error: Logarithm of non-positive value.\n"); }
                else { result = log(arg_val); }
            }
            else if (strncmp(name, "log_", 4) == 0) {
                const char *base_str = name + 4;
                double base_val;
                if (strcmp(base_str, "x") == 0) { base_val = x_val; }
                else if (strcmp(base_str, "e") == 0) { base_val = M_E; }
                else { base_val = atof(base_str); }

                if (arg_val <= 0) { fprintf(stderr, "Error: Logarithm argument must be positive (got %f for log_%s).\n", arg_val, base_str); }
                else if (base_val <= 0 || fabs(base_val - 1.0) < EPSILON) { fprintf(stderr, "Error: Logarithm base must be positive and not 1 (got %f for log_%s).\n", base_val, base_str); }
                else { result = log_based(arg_val, base_val); }
            }
            else {
                fprintf(stderr, "Error: Unknown function '%s' in evaluate.\n", name);
            }
        }
    }
    else {
        fprintf(stderr, "Error: Unknown node type in evaluate.\n");
    }
    return result;
}
//----------------------------------------------Tokenizer/Parser End-------------------------------------//

//----------------------------------------------Math Begin-----------------------------------------------//

double cotan(double x) {
    if (fabs(sin(x)) < EPSILON) { fprintf(stderr, "Error: cotan domain (sin(x) is near zero).\n"); return NAN; }
    return 1.0 / tan(x);
}

double sec(double x) {
    if (fabs(cos(x)) < EPSILON) { fprintf(stderr, "Error: sec domain (cos(x) is near zero).\n"); return NAN; }
    return 1.0 / cos(x);
}

double csec(double x) {
    if (fabs(sin(x)) < EPSILON) { fprintf(stderr, "Error: csc domain (sin(x) is near zero).\n"); return NAN; }
    return 1.0 / sin(x);
}

double actan(double x) {
    return M_PI_2 - atan(x);
}

double asec(double x) {
    if (fabs(x) < 1.0) { fprintf(stderr, "Error: asec domain (|x| < 1).\n"); return NAN; }
    return acos(1.0 / x);
}

double acsec(double x) {
    if (fabs(x) < 1.0) { fprintf(stderr, "Error: acsc domain (|x| < 1).\n"); return NAN; }
    return asin(1.0 / x);
}

double log_based(double val, double base) {
    if (val <= 0) { fprintf(stderr, "Error: log_based arg must be > 0.\n"); return NAN; }
    if (base <= 0 || fabs(base - 1.0) < EPSILON) { fprintf(stderr, "Error: log_based base must be > 0 and != 1.\n"); return NAN; }
    return log(val) / log(base);
}
//----------------------------------------------Math End-------------------------------------------------//

//----------------------------------------------Method Begin---------------------------------------------//

void bisection_method(const char *equation_str) {


    Token *toks = tokenize(equation_str);
    if (!toks) { return; }

    Token *cur = toks;
    Node *root_node = parse_expression(&cur);
    if (!root_node) {
        free_tokens(toks);
        return;
    }

    double a, b, fa, fb, m = NAN, fm = NAN;
    int err_exp;
    double epsilon_user;

    printf("Enter desired error tolerance exponent (e.g., 6 for 10^-6): ");
    if (scanf("%d", &err_exp) != 1 || err_exp < 0) {
        flushInputBuffer();
        printf("Invalid exponent for error tolerance. Using default 10^-%.0f.\n", -log10(EPSILON));
        epsilon_user = EPSILON;
    }
    else {
        flushInputBuffer();
        epsilon_user = pow(10, -err_exp);
    }
    printf("Using error tolerance: %.2e\n", epsilon_user);

    int iter = 0;
    printf("Enter interval endpoints a and b: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        flushInputBuffer(); printf("Invalid input for a or b.\n");
        free_ast(root_node); free_tokens(toks); return;
    }
    flushInputBuffer();

    fa = evaluate(root_node, a);
    fb = evaluate(root_node, b);

    if (isnan(fa) || isnan(fb)) {
        printf("Function evaluation failed at interval endpoints. Cannot proceed.\n");
        free_ast(root_node); free_tokens(toks); return;
    }

    printf("\nIter |      a      |     f(a)     |      b      |     f(b)     |      m      |     f(m)     |    b-a  \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("%4d | %.5e | %.5e | %.5e | %.5e |    -    |    -    | %.2e\n", iter, a, fa, b, fb, b - a);

    int proceed_iteration = 1;
    if (fa * fb > 0.0) {
        printf("f(a) and f(b) have the same sign (fa=%.2e, fb=%.2e). No root guaranteed by bisection in [%g, %g].\n", fa, fb, a, b);
        proceed_iteration = 0;
    }
    if (proceed_iteration && fabs(fa) < epsilon_user) {
        printf("Approximate root at a: %.8f (f(a) is near zero)\n", a);
        m = a; fm = fa;
        proceed_iteration = 0;
    }
    if (proceed_iteration && fabs(fb) < epsilon_user) {
        printf("Approximate root at b: %.8f (f(b) is near zero)\n", b);
        m = b; fm = fb;
        proceed_iteration = 0;
    }

    while (proceed_iteration && (b - a) / 2.0 > epsilon_user && iter < MAX_ITER) {
        iter++;
        m = a + (b - a) / 2.0;
        fm = evaluate(root_node, m);

        if (isnan(fm)) {
            printf("Function evaluation failed at midpoint m=%.5e. Cannot proceed.\n", m);
            proceed_iteration = 0;
        }
        else {
            printf("%4d | %.5e | %.5e | %.5e | %.5e | %.5e | %.5e | %.2e\n", iter, a, fa, b, fb, m, fm, b - a);
        }

        if (proceed_iteration && fabs(fm) < epsilon_user) {
            proceed_iteration = 0;
        }

        if (proceed_iteration) {
            if (fa * fm < 0.0) {
                b = m;
                fb = fm;
            }
            else {
                a = m;
                fa = fm;
            }
        }
    }

    printf("--------------------------------------------------------------------------------------\n");
    if (iter == MAX_ITER && proceed_iteration && (b - a) / 2.0 > epsilon_user) {
        printf("Bisection reached max iterations (%d) without full convergence to epsilon.\n", MAX_ITER);
    }

    double final_root = m;
    if (isnan(final_root) && !isnan(a) && !isnan(b)) final_root = (a + b) / 2.0;

    printf("Approximate root: %.8f\n", final_root);
    printf("f(root) = %.2e, iterations = %d\n", evaluate(root_node, final_root), iter);

    free_ast(root_node);
    free_tokens(toks);
}

void regula_falsi_method(const char *equation_str) {
    Token *toks = tokenize(equation_str);
    if (!toks) { return; }
    Token *cur = toks;
    Node *root_node = parse_expression(&cur);
    if (!root_node) { free_tokens(toks); return; }

    double a, b, fa, fb, m = NAN, fm = NAN;
    int err_exp;
    double epsilon_user;

    printf("Enter desired error tolerance exponent (e.g., 6 for 10^-6): ");
    if (scanf("%d", &err_exp) != 1 || err_exp < 0) {
        flushInputBuffer();
        printf("Invalid exponent. Using default 10^-%.0f.\n", -log10(EPSILON));
        epsilon_user = EPSILON;
    }
    else {
        flushInputBuffer();
        epsilon_user = pow(10, -err_exp);
    }
    printf("Using error tolerance: %.2e\n", epsilon_user);

    int iter = 0;
    printf("Enter interval endpoints a and b: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        flushInputBuffer(); printf("Invalid input for a or b.\n");
        free_ast(root_node); free_tokens(toks); return;
    }
    flushInputBuffer();

    fa = evaluate(root_node, a);
    fb = evaluate(root_node, b);

    if (isnan(fa) || isnan(fb)) {
        printf("Function evaluation failed at endpoints. Cannot proceed.\n");
        free_ast(root_node); free_tokens(toks); return;
    }

    printf("\nIter |    a    |   f(a)   |    b    |   f(b)   |    m    |   f(m)   |  |m-prev_m| |  b-a\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("%4d | %.5e | %.5e | %.5e | %.5e |    -    |    -    |     -     | %.2e\n", iter, a, fa, b, fb, b - a);

    int proceed_iteration = 1;
    if (fa * fb > 0.0) {
        printf("f(a) and f(b) have the same sign. No root guaranteed.\n");
        proceed_iteration = 0;
    }
    if (proceed_iteration && fabs(fa) < epsilon_user) {
        printf("Approximate root at a: %.8f\n", a); m = a; fm = fa; proceed_iteration = 0;
    }
    if (proceed_iteration && fabs(fb) < epsilon_user) {
        printf("Approximate root at b: %.8f\n", b); m = b; fm = fb; proceed_iteration = 0;
    }

    double prev_m = NAN;
    double m_diff = NAN;

    while (proceed_iteration && iter < MAX_ITER) {
        iter++;
        if (fabs(fb - fa) < EPSILON) {
            printf("Denominator (fb - fa) is too small (%.2e). Cannot proceed reliably.\n", fb - fa);
            proceed_iteration = 0;
        }

        if (proceed_iteration) {
            m = (a * fb - b * fa) / (fb - fa);
            fm = evaluate(root_node, m);
            if (isnan(fm)) {
                printf("Function evaluation failed at m=%.5e.\n", m);
                proceed_iteration = 0;
            }
        }

        if (!isnan(prev_m) && !isnan(m)) m_diff = fabs(m - prev_m); else m_diff = NAN;

        if (proceed_iteration) {
            printf("%4d | %.5e | %.5e | %.5e | %.5e | %.5e | %.5e | %.2e | %.2e\n",
                iter, a, fa, b, fb, m, fm, m_diff, b - a);
        }

        if (proceed_iteration && fabs(fm) < epsilon_user) {
            printf("Convergence: |f(m)| < tolerance.\n");
            proceed_iteration = 0;
        }
        if (proceed_iteration && !isnan(prev_m) && fabs(m - prev_m) < epsilon_user * (fabs(m) + 1.0)) {
            printf("Convergence stagnated (change in m < tolerance).\n");
            proceed_iteration = 0;
        }
        if (proceed_iteration && fabs(b - a) < epsilon_user && iter > 1) {
            printf("Interval width |b-a| < tolerance.\n");
            proceed_iteration = 0;
        }

        if (proceed_iteration) {
            if (fa * fm < 0.0) {
                b = m;
                fb = fm;
            }
            else {
                a = m;
                fa = fm;
            }
            prev_m = m;
        }
    }

    printf("---------------------------------------------------------------------------------------------------\n");
    if (iter == MAX_ITER && proceed_iteration && (isnan(m) || fabs(fm) >= epsilon_user)) {
        printf("Regula Falsi reached max iterations (%d) without desired convergence.\n", MAX_ITER);
    }

    if (isnan(m)) {
        printf("Regula Falsi could not find a root within the criteria.\n");
    }
    else {
        printf("Approximate root: %.8f\n", m);
        printf("f(root) = %.2e, iterations = %d\n", evaluate(root_node, m), iter);
    }

    free_ast(root_node);
    free_tokens(toks);
}

void newton_raphson_method(const char *equation_str) {
    Token *toks = tokenize(equation_str);
    if (!toks) { return; }
    Token *cur = toks;
    Node *root_node = parse_expression(&cur);
    if (!root_node) { free_tokens(toks); return; }

    double x_current, f_current, df_current, x_next = NAN;
    int err_exp;
    double epsilon_user;

    printf("Enter desired error tolerance exponent (e.g., 6 for 10^-6): ");
    if (scanf("%d", &err_exp) != 1 || err_exp < 0) {
        flushInputBuffer();
        printf("Invalid exponent. Using default 10^-%.0f.\n", -log10(EPSILON));
        epsilon_user = EPSILON;
    }
    else {
        flushInputBuffer();
        epsilon_user = pow(10, -err_exp);
    }
    printf("Using error tolerance: %.2e\n", epsilon_user);

    int iter = 0;
    printf("Enter initial guess x0: ");
    if (scanf("%lf", &x_current) != 1) {
        flushInputBuffer(); printf("Invalid input for x0.\n");
        free_ast(root_node); free_tokens(toks); return;
    }
    flushInputBuffer();

    printf("\nIter |   x_curr  |  f(x_curr) | df(x_curr) |   x_next  | |x_next-x_curr|\n");
    printf("--------------------------------------------------------------------------------------\n");

    int proceed_iteration = 1;
    while (proceed_iteration && iter < MAX_ITER) {
        iter++;
        f_current = evaluate(root_node, x_current);
        if (isnan(f_current)) {
            printf("Function evaluation f(x_current) failed at x=%.5e.\n", x_current);
            proceed_iteration = 0;
        }

        if (proceed_iteration) {
            double x_plus_h = evaluate(root_node, x_current + EPSILON);
            double x_minus_h = evaluate(root_node, x_current - EPSILON);
            if (isnan(x_plus_h) || isnan(x_minus_h)) {
                printf("Function evaluation for derivative failed at x=%.5e.\n", x_current);
                df_current = NAN;
            }
            else {
                df_current = (x_plus_h - x_minus_h) / (2.0 * EPSILON);
            }

            if (isnan(df_current)) {
                printf("%4d | %.5e | %.5e |    NAN    |    -    |      -\n", iter, x_current, f_current);
                proceed_iteration = 0;
            }
            else if (fabs(df_current) < EPSILON) {
                printf("%4d | %.5e | %.5e | %.5e |    -    |      -\n", iter, x_current, f_current, df_current);
                printf("Derivative is near zero (f'(x) = %g). Cannot proceed.\n", df_current);
                proceed_iteration = 0;
            }
        }

        if (proceed_iteration) {
            x_next = x_current - f_current / df_current;
            double x_diff = fabs(x_next - x_current);
            printf("%4d | %.5e | %.5e | %.5e | %.5e | %.2e\n", iter, x_current, f_current, df_current, x_next, x_diff);

            if (fabs(f_current) < epsilon_user) {
                printf("Convergence: |f(x_current)| < tolerance.\n");
                proceed_iteration = 0;
            }
            if (proceed_iteration && x_diff < epsilon_user && iter > 1) {
                printf("Convergence: |x_next - x_current| < tolerance.\n");
                proceed_iteration = 0;
            }
            if (proceed_iteration) {
                x_current = x_next;
            }
        }
    }

    printf("--------------------------------------------------------------------------------------\n");
    if (iter == MAX_ITER && proceed_iteration && (fabs(f_current) >= epsilon_user && (isnan(x_next) || fabs(x_next - x_current) >= epsilon_user))) {
        printf("Newton-Raphson reached max iterations (%d) without desired convergence.\n", MAX_ITER);
    }

    printf("Approximate root: %.8f\n", x_current);
    printf("f(root) = %.2e, iterations = %d\n", evaluate(root_node, x_current), iter);

    free_ast(root_node);
    free_tokens(toks);
}

void invert_matrix_method(Matrix *matrix_obj) {
    if (!matrix_obj || !matrix_obj->data || matrix_obj->size == 0) {
        printf("Invalid matrix provided for inversion.\n");
        return;
    }
    int n = matrix_obj->size;
    int i, j, k;

    double **aug = (double **)malloc(n * sizeof(double *));
    if (!aug) {
        printf("Memory allocation failed for augmented matrix rows.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        *(aug + i) = (double *)calloc(2 * n, sizeof(double));
        if (!(*(aug + i))) {
            printf("Memory allocation failed for augmented matrix row %d columns.\n", i);
            for (j = 0; j < i; j++) free(*(aug + j));
            free(aug);
            return;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            *(*(aug + i) + j) = *(*(matrix_obj->data + i) + j);
        }
        *(*(aug + i) + (n + i)) = 1.0;
    }

    printf("Initial Augmented Matrix [A|I]:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++) { printf("%10.4lf ", *(*(aug + i) + j)); }
        printf("\n");
    }
    printf("------------------------------------------------------------\n");

    int possible_to_invert = 1;
    for (i = 0; i < n && possible_to_invert; i++) {
        int pivot_row = i;
        double max_val = fabs(*(*(aug + i) + i));
        for (k = i + 1; k < n; k++) {
            if (fabs(*(*(aug + k) + i)) > max_val) {
                max_val = fabs(*(*(aug + k) + i));
                pivot_row = k;
            }
        }

        if (max_val < EPSILON) {
            printf("Matrix is singular or numerically unstable at column %d. Cannot invert.\n", i);
            possible_to_invert = 0;
        }
        else {
            if (pivot_row != i) {
                printf("Swapping row %d and row %d\n", i, pivot_row);
                double *temp_row = *(aug + i);
                *(aug + i) = *(aug + pivot_row);
                *(aug + pivot_row) = temp_row;
            }

            double pivot_val_actual = *(*(aug + i) + i);
            if (fabs(pivot_val_actual) < EPSILON) { 
                printf("Pivot value is zero after swap at row %d. Matrix is singular.\n", i);
                possible_to_invert = 0;
            }
            else {
                printf("Normalizing pivot row %d (dividing by %.4lf)\n", i, pivot_val_actual);
                for (k = 0; k < 2 * n; k++) {
                    *(*(aug + i) + k) /= pivot_val_actual;
                }

                for (j = 0; j < n; j++) {
                    if (j != i) {
                        double factor = *(*(aug + j) + i);
                        printf("Eliminating in row %d using row %d (factor %.4lf)\n", j, i, factor);
                        for (k = 0; k < 2 * n; k++) {
                            *(*(aug + j) + k) -= factor * (*(*(aug + i) + k));
                        }
                    }
                }
                printf("Matrix after processing column %d:\n", i);
                for (int r_print = 0; r_print < n; r_print++) {
                    for (int c_print = 0; c_print < 2 * n; c_print++) { printf("%10.4lf ", *(*(aug + r_print) + c_print)); }
                    printf("\n");
                }
                printf("------------------------------------------------------------\n");
            }
        }
    }

    if (possible_to_invert) {
        printf("Final Inverted Matrix (A^-1 from right side of [I|A^-1]):\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%10.6lf ", *(*(aug + i) + (j + n)));
            }
            printf("\n");
        }
    }
    else {
        printf("Matrix inversion failed.\n");
    }

    for (i = 0; i < n; i++) free(*(aug + i));
    free(aug);
}

void cholesky_decomposition_method(Matrix *matrix_obj) {
    if (!matrix_obj || !matrix_obj->data || matrix_obj->size == 0) {
        printf("Invalid matrix for Cholesky decomposition.\n");
        return;
    }
    int n = matrix_obj->size;
    int i, j, k;
    double **L_data = matrix_obj->data;

    printf("Original Matrix A (will be transformed into L):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) { printf("%10.4lf ", *(*(L_data + i) + j)); }
        printf("\n");
    }
    printf("------------------------------------------------------------\n");

    int possible_to_decompose = 1;
    for (j = 0; j < n && possible_to_decompose; j++) {
        double sum_diag_sq = 0.0;
        for (k = 0; k < j; k++) {
            sum_diag_sq += (*(*(L_data + j) + k)) * (*(*(L_data + j) + k));
        }
        double L_jj_squared = *(*(L_data + j) + j) - sum_diag_sq;

        if (L_jj_squared <= EPSILON * EPSILON) {
            printf("Matrix is not positive-definite or Cholesky failed at L[%d][%d]. L_jj_squared = %lf\n", j, j, L_jj_squared);
            possible_to_decompose = 0;
        }
        else {
            *(*(L_data + j) + j) = sqrt(L_jj_squared);

            for (i = j + 1; i < n && possible_to_decompose; i++) {
                double sum_nondiag = 0.0;
                for (k = 0; k < j; k++) {
                    sum_nondiag += (*(*(L_data + i) + k)) * (*(*(L_data + j) + k));
                }
                if (fabs(*(*(L_data + j) + j)) < EPSILON) {
                    printf("Division by zero for L[%d][%d] (L[%d][%d] is zero).\n", i, j, j, j);
                    possible_to_decompose = 0;
                }
                else {
                    *(*(L_data + i) + j) = (*(*(L_data + i) + j) - sum_nondiag) / (*(*(L_data + j) + j));
                }
            }
        }
        if (possible_to_decompose) {
            printf("Matrix L after processing column %d:\n", j);
            for (int r_print = 0; r_print < n; r_print++) {
                for (int c_print = 0; c_print < n; c_print++) {
                    if (c_print > r_print) printf("%10.4lf ", 0.0);
                    else printf("%10.4lf ", *(*(L_data + r_print) + c_print));
                }
                printf("\n");
            }
            printf("------------------------------------------------------------\n");
        }
    }

    if (possible_to_decompose) {
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                *(*(L_data + i) + j) = 0.0;
            }
        }
        printf("Final L Matrix (Lower Triangular from Cholesky A = L*L^T):\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%10.6lf ", *(*(L_data + i) + j));
            }
            printf("\n");
        }
    }
    else {
        printf("Cholesky decomposition failed.\n");
    }
}

void gauss_seidel_method(AugmentedMatrix *aug_matrix) {
    if (!aug_matrix || !aug_matrix->data || aug_matrix->n_rows == 0) {
        printf("Invalid augmented matrix for Gauss-Seidel.\n");
        return;
    }

    int n = aug_matrix->n_rows;
    int n_cols = aug_matrix->n_cols;
    double **A_aug = aug_matrix->data;
    int i, j;

    int err_exp;
    double epsilon_user;
    printf("Enter desired error tolerance exponent for Gauss-Seidel (e.g., 6 for 10^-6): ");
    if (scanf("%d", &err_exp) != 1 || err_exp < 0) {
        flushInputBuffer();
        printf("Invalid exponent. Using default 10^-%.0f.\n", -log10(EPSILON));
        epsilon_user = EPSILON;
    }
    else {
        flushInputBuffer();
        epsilon_user = pow(10, -err_exp);
    }
    printf("Using error tolerance: %.2e\n", epsilon_user);

    int diag_dominant_strict = 1;
    int diag_zero_found = 0;
    for (i = 0; i < n; ++i) {
        double diag_val = fabs(*(*(A_aug + i) + i));
        if (diag_val < EPSILON) {
            printf("Warning: Diagonal element A[%d][%d] is zero or very small (%.2e).\n", i, i, *(*(A_aug + i) + i));
            diag_zero_found = 1;
        }
        double sum_off_diag = 0.0;
        for (j = 0; j < n; ++j) {
            if (i != j) { sum_off_diag += fabs(*(*(A_aug + i) + j)); }
        }
        if (diag_val <= sum_off_diag) {
            diag_dominant_strict = 0;
        }
    }
    if (diag_zero_found) printf("Gauss-Seidel may fail due to zero on diagonal.\n");
    if (!diag_dominant_strict) printf("Warning: Matrix is not strictly diagonally dominant. Gauss-Seidel convergence not guaranteed.\n");


    double *x = (double *)malloc(n * sizeof(double));
    double *x_prev = (double *)malloc(n * sizeof(double));
    if (!x || !x_prev) {
        printf("Memory allocation failed for solution vectors.\n");
        free(x); free(x_prev); return;
    }
    for (i = 0; i < n; ++i) *(x + i) = 0.0;

    printf("\nIter | ");
    for (i = 0; i < n; ++i) printf("  x[%d]    | ", i);
    printf(" max_diff\n");
    printf("------|-"); for (i = 0; i < n; ++i) printf("----------|-"); printf("----------\n");

    int iter_count = 0;
    int converged = 0;
    int proceed_iteration = 1;

    while (proceed_iteration && iter_count < MAX_ITER && !converged) {
        iter_count++;
        for (i = 0; i < n; ++i) *(x_prev + i) = *(x + i);

        for (i = 0; i < n && proceed_iteration; ++i) {
            double sum_ax = 0.0;
            for (j = 0; j < n; ++j) {
                if (i != j) {
                    sum_ax += (*(*(A_aug + i) + j)) * (*(x + j));
                }
            }
            double A_ii = *(*(A_aug + i) + i);
            if (fabs(A_ii) < EPSILON) {
                printf("\nError: Division by zero (A[%d][%d] is effectively zero). Cannot proceed.\n", i, i);
                proceed_iteration = 0;
            }
            else {
                *(x + i) = (*(*(A_aug + i) + (n_cols - 1)) - sum_ax) / A_ii;
            }
        }

        if (proceed_iteration) {
            double max_diff = 0.0;
            for (i = 0; i < n; ++i) {
                double diff = fabs(*(x + i) - *(x_prev + i));
                if (diff > max_diff) {
                    max_diff = diff;
                }
            }
            printf("%5d | ", iter_count);
            for (i = 0; i < n; ++i) printf("%.5e | ", *(x + i));
            printf("%.2e\n", max_diff);

            if (max_diff < epsilon_user) {
                converged = 1;
                printf("Gauss-Seidel converged in %d iterations.\n", iter_count);
            }
        }
    }

    if (!converged && iter_count == MAX_ITER) {
        printf("Gauss-Seidel reached maximum iterations (%d) without converging to tolerance %.2e.\n", MAX_ITER, epsilon_user);
    }
    if (!proceed_iteration && !converged) {
        printf("Gauss-Seidel stopped due to an error (e.g., division by zero).\n");
    }

    printf("\nFinal Solution x:\n");
    for (i = 0; i < n; ++i) {
        printf("x%d = %10.6lf\n", i, *(x + i));
    }

    free(x);
    free(x_prev);
}

void numerical_derivative_method(const char *equation_str) {
    Token *toks = tokenize(equation_str);
    if (!toks) { return; }
    Token *cur = toks;
    Node *root_node = parse_expression(&cur);
    if (!root_node) { free_tokens(toks); return; }

    double x0, h;
    printf("Enter point x0 and step size h (e.g., 1.0 0.001): ");
    if (scanf("%lf %lf", &x0, &h) != 2 || fabs(h) < EPSILON * EPSILON) {
        flushInputBuffer(); printf("Invalid input for x0 or h (h cannot be effectively zero).\n");
        free_ast(root_node); free_tokens(toks); return;
    }
    flushInputBuffer();
    if (h < 0) h = -h;
    if (h < EPSILON * 100 && h > 0) printf("Warning: h (%g) is very small, may lead to precision issues.\n", h);

    double fx0 = evaluate(root_node, x0);
    double fx0_plus_h = evaluate(root_node, x0 + h);
    double fx0_minus_h = evaluate(root_node, x0 - h);

    if (isnan(fx0) || isnan(fx0_plus_h) || isnan(fx0_minus_h)) {
        printf("Function evaluation failed at one or more points. Cannot compute derivatives.\n");
    }
    else {
        double forward_diff = (fx0_plus_h - fx0) / h;
        double backward_diff = (fx0 - fx0_minus_h) / h;
        double central_diff = (fx0_plus_h - fx0_minus_h) / (2.0 * h);

        printf("Forward difference derivative at x0=%.4f (h=%.4g):  %.8f\n", x0, h, forward_diff);
        printf("Backward difference derivative at x0=%.4f (h=%.4g): %.8f\n", x0, h, backward_diff);
        printf("Central difference derivative at x0=%.4f (h=%.4g):  %.8f\n", x0, h, central_diff);
    }

    free_ast(root_node);
    free_tokens(toks);
}

void simpson_integration_method(const char *equation_str) {
    Token *toks = tokenize(equation_str);
    if (!toks) { return; }
    Token *cur = toks;
    Node *root_node = parse_expression(&cur);
    if (!root_node) { free_tokens(toks); return; }

    double a, b, h_13, h_38;
    int n_13, n_38, i;

    printf("Enter interval endpoints a and b for integration: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        flushInputBuffer(); printf("Invalid input for a or b.\n");
        free_ast(root_node); free_tokens(toks); return;
    }
    flushInputBuffer();
    if (fabs(a - b) < EPSILON) { printf("Interval [a,b] has (near) zero width. Integral is (near) 0.\n"); free_ast(root_node); free_tokens(toks); return; }

    if (a > b) {
        printf("Warning: a > b. Swapping them for calculation. Integral result will correspond to integral from new 'a' to new 'b'.\n");
        double temp_val = a; a = b; b = temp_val;
    }

    printf("--- Simpson's 1/3 Rule ---\n");
    printf("Enter number of subintervals n for 1/3 rule (must be EVEN and >= 2): ");
    if (scanf("%d", &n_13) != 1 || n_13 < 2 || n_13 % 2 != 0) {
        flushInputBuffer();
        printf("Invalid n for Simpson's 1/3 rule. Skipped.\n");
    }
    else {
        flushInputBuffer();
        h_13 = (b - a) / n_13;
        double sum_f_xi = 0.0;
        double fa_13 = evaluate(root_node, a);
        double fb_13 = evaluate(root_node, b);
        int eval_ok = 1;
        if (isnan(fa_13) || isnan(fb_13)) { printf("Eval failed at endpoints for 1/3 rule.\n"); eval_ok = 0; }

        if (eval_ok) {
            sum_f_xi += fa_13;
            sum_f_xi += fb_13;
            for (i = 1; i < n_13 && eval_ok; i++) {
                double xi = a + i * h_13;
                double fxi = evaluate(root_node, xi);
                if (isnan(fxi)) { printf("Eval failed at x%d for 1/3 rule.\n", i); eval_ok = 0; }
                else {
                    if (i % 2 == 0) { sum_f_xi += 2.0 * fxi; }
                    else { sum_f_xi += 4.0 * fxi; }
                }
            }
            if (eval_ok) {
                double result_13 = (h_13 / 3.0) * sum_f_xi;
                printf("Simpson's 1/3 rule result (n=%d): %.8f\n", n_13, result_13);
            }
        }
    }

    printf("--- Simpson's 3/8 Rule ---\n");
    printf("Enter number of subintervals n for 3/8 rule (must be a MULTIPLE OF 3 and >=3): ");
    if (scanf("%d", &n_38) != 1 || n_38 < 3 || n_38 % 3 != 0) {
        flushInputBuffer();
        printf("Invalid n for Simpson's 3/8 rule. Skipped.\n");
    }
    else {
        flushInputBuffer();
        h_38 = (b - a) / n_38;
        double sum_f_xi = 0.0;
        double fa_38 = evaluate(root_node, a);
        double fb_38 = evaluate(root_node, b);
        int eval_ok = 1;
        if (isnan(fa_38) || isnan(fb_38)) { printf("Eval failed at endpoints for 3/8 rule.\n"); eval_ok = 0; }

        if (eval_ok) {
            sum_f_xi += fa_38;
            sum_f_xi += fb_38;
            for (i = 1; i < n_38 && eval_ok; i++) {
                double xi = a + i * h_38;
                double fxi = evaluate(root_node, xi);
                if (isnan(fxi)) { printf("Eval failed at x%d for 3/8 rule.\n", i); eval_ok = 0; }
                else {
                    if (i % 3 == 0) { sum_f_xi += 2.0 * fxi; }
                    else { sum_f_xi += 3.0 * fxi; }
                }
            }
            if (eval_ok) {
                double result_38 = (3.0 * h_38 / 8.0) * sum_f_xi;
                printf("Simpson's 3/8 rule result (n=%d): %.8f\n", n_38, result_38);
            }
        }
    }
    free_ast(root_node);
    free_tokens(toks);
}

void trapezoidal_integration_method(const char *equation_str) {
    Token *toks = tokenize(equation_str);
    if (!toks) { return; }
    Token *cur = toks;
    Node *root_node = parse_expression(&cur);
    if (!root_node) { free_tokens(toks); return; }

    double a, b, h, sum_internal_y = 0.0;
    int n_intervals, i;

    printf("Enter interval endpoints a and b, and number of subintervals n (n >= 1): ");
    if (scanf("%lf %lf %d", &a, &b, &n_intervals) != 3 || n_intervals < 1) {
        flushInputBuffer();
        printf("Invalid input for a, b, or n (n must be >= 1).\n");
        free_ast(root_node); free_tokens(toks); return;
    }
    flushInputBuffer();
    if (fabs(a - b) < EPSILON) { printf("Interval [a,b] has (near) zero width. Integral is (near) 0.\n"); free_ast(root_node); free_tokens(toks); return; }

    h = (b - a) / n_intervals;
    double fa_trap = evaluate(root_node, a);
    double fb_trap = evaluate(root_node, b);
    int eval_ok = 1;

    if (isnan(fa_trap) || isnan(fb_trap)) {
        printf("Function evaluation failed at interval endpoints. Cannot compute integral.\n");
        eval_ok = 0;
    }

    if (eval_ok) {
        for (i = 1; i < n_intervals && eval_ok; i++) {
            double xi = a + i * h;
            double fxi = evaluate(root_node, xi);
            if (isnan(fxi)) {
                printf("Function evaluation failed at an internal point x%d. Cannot compute integral.\n", i);
                eval_ok = 0;
            }
            else {
                sum_internal_y += fxi;
            }
        }
    }

    if (eval_ok) {
        double integral_result = (h / 2.0) * (fa_trap + 2.0 * sum_internal_y + fb_trap);
        printf("Trapezoidal rule result (n=%d): %.8f\n", n_intervals, integral_result);
    }

    free_ast(root_node);
    free_tokens(toks);
}

void gregory_newton_interpolation() {
    int num_points, i, j, k_loop;
    double *x_vals = NULL, *y_vals = NULL;
    double **diff_table = NULL;
    int setup_ok = 1;

    printf("Enter number of data points n (>= 2): ");
    if (scanf("%d", &num_points) != 1 || num_points < 2) {
        flushInputBuffer();
        printf("Invalid number of points. Must be at least 2.\n");
        setup_ok = 0;
    }
    if (setup_ok) flushInputBuffer();

    if (setup_ok) {
        x_vals = (double *)malloc(num_points * sizeof(double));
        y_vals = (double *)malloc(num_points * sizeof(double));
        if (!x_vals || !y_vals) {
            printf("Memory allocation failed for x or y values.\n");
            setup_ok = 0;
        }
    }

    if (setup_ok) {
        printf("Enter x[i] and y[i] pairs (assuming x values are equally spaced):\n");
        for (i = 0; i < num_points && setup_ok; i++) {
            printf("Point %d (x y): ", i);
            if (scanf("%lf %lf", (x_vals + i), (y_vals + i)) != 2) {
                flushInputBuffer(); printf("Invalid input for data point %d.\n", i);
                setup_ok = 0;
            }
        }
        if (setup_ok) flushInputBuffer();
    }

    double h_spacing = 0;
    if (setup_ok) {
        h_spacing = (*(x_vals + 1)) - (*(x_vals + 0));
        if (fabs(h_spacing) < EPSILON) {
            printf("Error: Spacing h between first two x-values is zero or too small.\n");
            setup_ok = 0;
        }
        for (i = 1; i < num_points - 1 && setup_ok; i++) {
            if (fabs((*(x_vals + i + 1) - (*(x_vals + i))) - h_spacing) > EPSILON * (fabs(h_spacing) + 1.0)) {
                printf("Warning: x values do not appear equally spaced. Results may be inaccurate.\n");
            }
        }
    }

    if (setup_ok) {
        diff_table = (double **)malloc((num_points - 1) * sizeof(double *));
        if (!diff_table) { printf("Malloc failed for difference table rows.\n"); setup_ok = 0; }
        else {
            for (i = 0; i < num_points - 1; ++i) *(diff_table + i) = NULL;

            if (num_points > 1) {
                *(diff_table + 0) = (double *)malloc((num_points - 1) * sizeof(double));
                if (!(*(diff_table + 0))) { printf("Malloc failed for first differences.\n"); setup_ok = 0; }
                else {
                    for (i = 0; i < num_points - 1; i++) {
                        *(*(diff_table + 0) + i) = (*(y_vals + i + 1)) - (*(y_vals + i));
                    }
                }
            }

            for (j = 1; j < num_points - 1 && setup_ok; j++) {
                *(diff_table + j) = (double *)malloc((num_points - 1 - j) * sizeof(double));
                if (!(*(diff_table + j))) {
                    printf("Malloc failed for %d-th order differences.\n", j + 1);
                    for (k_loop = 0; k_loop < j; ++k_loop) if (*(diff_table + k_loop)) free(*(diff_table + k_loop));
                    setup_ok = 0;
                }
                else {
                    for (i = 0; i < num_points - 1 - j; i++) {
                        *(*(diff_table + j) + i) = (*(*(diff_table + j - 1) + i + 1)) - (*(*(diff_table + j - 1) + i));
                    }
                }
            }
        }
    }

    if (setup_ok) {
        double X_interpolate, P_n_X;
        double u_val, term_numerator;

        printf("Enter interpolation point X: ");
        if (scanf("%lf", &X_interpolate) != 1) {
            flushInputBuffer(); printf("Invalid input for X.\n");
        }
        else {
            flushInputBuffer();
            u_val = (X_interpolate - (*(x_vals + 0))) / h_spacing;
            P_n_X = *(y_vals + 0);
            term_numerator = 1.0;
            double term_factorial = 1.0;
            int term_loop_proceed = 1;

            for (j = 0; j < num_points - 1 && term_loop_proceed; j++) {
                term_numerator *= (u_val - j);
                term_factorial *= (j + 1.0);
                if (*(diff_table + j) != NULL) {
                    P_n_X += (term_numerator / term_factorial) * (*(*(diff_table + j) + 0));
                }
                else {
                    printf("Error: Unexpected NULL difference table row during calculation.\n");
                    term_loop_proceed = 0;
                }
            }
            if (term_loop_proceed) {
                printf("Interpolated value P(%.4f) = %.6f\n", X_interpolate, P_n_X);
            }
        }
    }

    if (diff_table) {
        for (i = 0; i < num_points - 1; i++) {
            if (*(diff_table + i)) free(*(diff_table + i));
        }
        free(diff_table);
    }
    free(x_vals);
    free(y_vals);
}
//----------------------------------------------Method End-----------------------------------------------//