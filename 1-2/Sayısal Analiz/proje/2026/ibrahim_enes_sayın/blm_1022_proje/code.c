/*
 * Yildiz Teknik Universitesi
 * Elektrik-Elektronik Fakultesi
 * Bilgisayar Muhendisligi Bolumu
 * BLM1022 - Sayisal Analiz Projesi
 * Ogrenci No: 24011116
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_EXPR_LEN 512
#define MAX_TOKENS   256
#define PI_VAL       3.14159265358979323846
#define E_VAL        2.71828182845904523536

/* ===== TOKEN TYPES ===== */
#define TOK_NUM    1
#define TOK_VAR    2
#define TOK_PLUS   3
#define TOK_MINUS  4
#define TOK_MUL    5
#define TOK_DIV    6
#define TOK_POW    7
#define TOK_LPAREN 8
#define TOK_RPAREN 9
#define TOK_FUNC   10
#define TOK_END    11
#define TOK_LOG_BASE 12

/* ===== FUNCTION IDs ===== */
#define FN_SIN   1
#define FN_COS   2
#define FN_TAN   3
#define FN_COT   4
#define FN_SEC   5
#define FN_CSC   6
#define FN_ASIN  7
#define FN_ACOS  8
#define FN_ATAN  9
#define FN_ACOT  10
#define FN_ASEC  11
#define FN_ACSC  12
#define FN_EXP   13
#define FN_LN    14
#define FN_LOG   15
#define FN_LOG_B 16
#define FN_SQRT  17
#define FN_ABS   18

/* ===== STRUCTS ===== */
typedef struct {
    int type;
    double numVal;
    int funcId;
    double logBase;
} Token;

typedef struct {
    Token *tokens;
    int count;
    int pos;
} TokenStream;

typedef struct {
    double **data;
    int n;
} Matrix;

typedef struct {
    double *x;
    double *y;
    int n;
} DataPoints;

typedef struct {
    double a;
    double b;
    double eps;
} IntervalParams;

typedef struct {
    double x0;
    double eps;
} InitialParams;

typedef struct {
    double a;
    double b;
    int n;
} IntegralParams;

/* ===== FORWARD DECLARATIONS ===== */
double parseExpr(TokenStream *ts, double xVal);
double parseTerm(TokenStream *ts, double xVal);
double parseFactor(TokenStream *ts, double xVal);
double parsePrimary(TokenStream *ts, double xVal);
double evalExpr(const char *expr, double x);
TokenStream* tokenize(const char *expr);
void freeTokenStream(TokenStream *ts);

Matrix* createMatrix(int n);
void freeMatrix(Matrix *m);
void printMatrix(Matrix *m);

void bisection(void);
void regulaFalsi(void);
void newtonRaphson(void);
void inverseMatrix(void);
void choleskyMethod(void);
void gaussSeidel(void);
void numericalDerivative(void);
void simpsonMethod(void);
int trapezMethod(void);
void gregoryNewton(void);

/* ===== TOKENIZER ===== */
static int matchFunc(const char *s, int *funcId, int *logB_flag, double *base) {
    *logB_flag = 0;
    *base = 10.0;
    if (strncmp(s, "asin", 4) == 0)  { *funcId = FN_ASIN; return 4; }
    if (strncmp(s, "acos", 4) == 0)  { *funcId = FN_ACOS; return 4; }
    if (strncmp(s, "atan", 4) == 0)  { *funcId = FN_ATAN; return 4; }
    if (strncmp(s, "acot", 4) == 0)  { *funcId = FN_ACOT; return 4; }
    if (strncmp(s, "asec", 4) == 0)  { *funcId = FN_ASEC; return 4; }
    if (strncmp(s, "acsc", 4) == 0)  { *funcId = FN_ACSC; return 4; }
    if (strncmp(s, "sin",  3) == 0)  { *funcId = FN_SIN;  return 3; }
    if (strncmp(s, "cos",  3) == 0)  { *funcId = FN_COS;  return 3; }
    if (strncmp(s, "tan",  3) == 0)  { *funcId = FN_TAN;  return 3; }
    if (strncmp(s, "cot",  3) == 0)  { *funcId = FN_COT;  return 3; }
    if (strncmp(s, "sec",  3) == 0)  { *funcId = FN_SEC;  return 3; }
    if (strncmp(s, "csc",  3) == 0)  { *funcId = FN_CSC;  return 3; }
    if (strncmp(s, "exp",  3) == 0)  { *funcId = FN_EXP;  return 3; }
    if (strncmp(s, "sqrt", 4) == 0)  { *funcId = FN_SQRT; return 4; }
    if (strncmp(s, "abs",  3) == 0)  { *funcId = FN_ABS;  return 3; }
    if (strncmp(s, "ln",   2) == 0)  { *funcId = FN_LN;   return 2; }
    /* log_BASE(x) */
    if (strncmp(s, "log_", 4) == 0) {
        char buf[64];
        int i = 4;
        int j = 0;
        *logB_flag = 1;
        while (s[i] && s[i] != '(' && j < 63) {
            buf[j++] = s[i++];
        }
        buf[j] = '\0';
        if (strcmp(buf, "x") == 0) {
            *base = -1.0; /* dynamic base = x */
        } else {
            *base = atof(buf);
            if (*base <= 0.0 || *base == 1.0) *base = 10.0;
        }
        *funcId = FN_LOG_B;
        return i;
    }
    if (strncmp(s, "log",  3) == 0)  { *funcId = FN_LOG;  return 3; }
    return 0;
}

TokenStream* tokenize(const char *expr) {
    int capacity = MAX_TOKENS;
    int i = 0;
    int len = (int)strlen(expr);
    TokenStream *ts = (TokenStream*)malloc(sizeof(TokenStream));
    ts->tokens = (Token*)malloc(capacity * sizeof(Token));
    ts->count = 0;
    ts->pos = 0;
    while (i < len) {
        Token t;
        t.numVal = 0.0;
        t.funcId = 0;
        t.logBase = 10.0;

        if (isspace((unsigned char)expr[i])) { i++; }

        if (isdigit((unsigned char)expr[i]) || (expr[i] == '.' && isdigit((unsigned char)expr[i+1]))) {
            char buf[64];
            int j = 0;
            while (i < len && (isdigit((unsigned char)expr[i]) || expr[i] == '.') && j < 63) {
                buf[j++] = expr[i++];
            }
            buf[j] = '\0';
            t.type = TOK_NUM;
            t.numVal = atof(buf);
        } else if (expr[i] == 'e' && (i+1 >= len || (!isalpha((unsigned char)expr[i+1]) && expr[i+1] != '_'))) {
            t.type = TOK_NUM;
            t.numVal = E_VAL;
            i++;
        } else if (strncmp(expr+i, "pi", 2) == 0 && (i+2 >= len || !isalnum((unsigned char)expr[i+2]))) {
            t.type = TOK_NUM;
            t.numVal = PI_VAL;
            i += 2;
        } else if (isalpha((unsigned char)expr[i])) {
            int funcId = 0;
            int logBFlag = 0;
            double base = 10.0;
            int consumed = matchFunc(expr+i, &funcId, &logBFlag, &base);
            if (consumed > 0) {
                t.type = TOK_FUNC;
                t.funcId = funcId;
                t.logBase = base;
                i += consumed;
            } else if (expr[i] == 'x') {
                t.type = TOK_VAR;
                i++;
            } else {
                /* unknown identifier, skip */
                i++;
            }
        } else if (expr[i] == '+') { t.type = TOK_PLUS;  i++; }
        else if (expr[i] == '-') { t.type = TOK_MINUS; i++; }
        else if (expr[i] == '*') { t.type = TOK_MUL;   i++; }
        else if (expr[i] == '/') { t.type = TOK_DIV;   i++; }
        else if (expr[i] == '^') { t.type = TOK_POW;   i++; }
        else if (expr[i] == '(') { t.type = TOK_LPAREN; i++; }
        else if (expr[i] == ')') { t.type = TOK_RPAREN; i++; }
        else { i++; }

        if (ts->count >= capacity) {
            capacity *= 2;
            ts->tokens = (Token*)realloc(ts->tokens, capacity * sizeof(Token));
        }
        ts->tokens[ts->count++] = t;
    }
    {
        Token end;
        end.type = TOK_END;
        end.numVal = 0.0;
        end.funcId = 0;
        end.logBase = 0.0;
        ts->tokens[ts->count++] = end;
    }
    return ts;
}

void freeTokenStream(TokenStream *ts) {
    if (ts) {
        free(ts->tokens);
        free(ts);
    }
}

/*  PARSER (Recursive Descent)  */
static Token curTok(TokenStream *ts) {
    return ts->tokens[ts->pos];
}

static Token consume(TokenStream *ts) {
    Token t = ts->tokens[ts->pos];
    if (t.type != TOK_END) ts->pos++;
    return t;
}

double parsePrimary(TokenStream *ts, double xVal) {
    Token t = curTok(ts);

    if (t.type == TOK_NUM) {
        consume(ts);
        return t.numVal;
    }
    if (t.type == TOK_VAR) {
        consume(ts);
        return xVal;
    }
    if (t.type == TOK_LPAREN) {
        double val;
        consume(ts);
        val = parseExpr(ts, xVal);
        if (curTok(ts).type == TOK_RPAREN) consume(ts);
        return val;
    }
    if (t.type == TOK_MINUS) {
        consume(ts);
        return -parsePrimary(ts, xVal);
    }
    if (t.type == TOK_FUNC) {
        double base;
        double inner;
        int fid;
        consume(ts);
        base = t.logBase;
        fid = t.funcId;
        inner = 0.0;
        if (curTok(ts).type == TOK_LPAREN) {
            consume(ts);
            inner = parseExpr(ts, xVal);
            if (curTok(ts).type == TOK_RPAREN) consume(ts);
        } else {
            inner = parsePrimary(ts, xVal);
        }
        switch (fid) {
            case FN_SIN:  return sin(inner);
            case FN_COS:  return cos(inner);
            case FN_TAN:  return tan(inner);
            case FN_COT:  return 1.0 / tan(inner);
            case FN_SEC:  return 1.0 / cos(inner);
            case FN_CSC:  return 1.0 / sin(inner);
            case FN_ASIN: return asin(inner);
            case FN_ACOS: return acos(inner);
            case FN_ATAN: return atan(inner);
            case FN_ACOT: return PI_VAL/2.0 - atan(inner);
            case FN_ASEC: return acos(1.0/inner);
            case FN_ACSC: return asin(1.0/inner);
            case FN_EXP:  return exp(inner);
            case FN_LN:   return log(inner);
            case FN_LOG:  return log10(inner);
            case FN_LOG_B:
                if (base < 0.0) base = xVal; /* log_x means base=x */
                if (base <= 0.0 || base == 1.0) return 0.0;
                return log(inner) / log(base);
            case FN_SQRT: return sqrt(inner);
            case FN_ABS:  return fabs(inner);
            default: return inner;
        }
    }
    return 0.0;
}

double parseFactor(TokenStream *ts, double xVal) {
    double base;
    int neg = 0;
    if (curTok(ts).type == TOK_MINUS) {
        consume(ts);
        neg = 1;
    }
    base = parsePrimary(ts, xVal);
    while (curTok(ts).type == TOK_POW) {
        double expVal;
        consume(ts);
        expVal = parseFactor(ts, xVal);
        base = pow(base, expVal);
    }
    if (neg) base = -base;
    return base;
}

double parseTerm(TokenStream *ts, double xVal) {
    double result = parseFactor(ts, xVal);
    Token t = curTok(ts);
    while (t.type == TOK_MUL || t.type == TOK_DIV ||
           t.type == TOK_VAR || t.type == TOK_FUNC || t.type == TOK_LPAREN) {
        if (t.type == TOK_MUL) {
            consume(ts);
            result *= parseFactor(ts, xVal);
        } else if (t.type == TOK_DIV) {
            double denom;
            consume(ts);
            denom = parseFactor(ts, xVal);
            if (fabs(denom) < 1e-300) denom = 1e-300;
            result /= denom;
        } else {
            Token next = curTok(ts);
            if (next.type == TOK_VAR || next.type == TOK_FUNC || next.type == TOK_LPAREN) {
                result *= parseFactor(ts, xVal);
            }
        }
        t = curTok(ts);
    }
    return result;
}

double parseExpr(TokenStream *ts, double xVal) {
    double result = parseTerm(ts, xVal);
    Token t = curTok(ts);
    while (t.type == TOK_PLUS || t.type == TOK_MINUS) {
        if (t.type == TOK_PLUS) {
            consume(ts);
            result += parseTerm(ts, xVal);
        } else {
            consume(ts);
            result -= parseTerm(ts, xVal);
        }
        t = curTok(ts);
    }
    return result;
}

double evalExpr(const char *expr, double x) {
    double result;
    TokenStream *ts = tokenize(expr);
    ts->pos = 0;
    result = parseExpr(ts, x);
    freeTokenStream(ts);
    return result;
}


double numericalDeriv(const char *expr, double x) {
    double h = 1e-7;
    return (evalExpr(expr, x + h) - evalExpr(expr, x - h)) / (2.0 * h);
}

/* ===== MATRIX FUNCTIONS ===== */
Matrix* createMatrix(int n) {
    int i;
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    m->n = n;
    m->data = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        m->data[i] = (double*)calloc(n, sizeof(double));
    }
    return m;
}

void freeMatrix(Matrix *m) {
    int i;
    if (!m) return;
    for (i = 0; i < m->n; i++) free(m->data[i]);
    free(m->data);
    free(m);
}

void printMatrix(Matrix *m) {
    int i, j;
    printf("\n");
    for (i = 0; i < m->n; i++) {
        for (j = 0; j < m->n; j++) {
            printf("%10.6f ", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void readInput(char *expr) {
    printf("Denklemi giriniz (^ ust alma, _ log tabaninda, ornek: x^3-x-2):\n");
    printf("Desteklenen: sin,cos,tan,cot,sec,csc,asin,acos,atan,acot,asec,acsc,exp,log,ln,log_B(x),sqrt\n> ");
    fgets(expr, MAX_EXPR_LEN, stdin);
    expr[strcspn(expr, "\n")] = '\0';
}

static double readEps() {
    double eps;
    int expVal;
    printf("Hata payi ussu (ornek: 6 -> 10^-6): ");
    scanf("%d", &expVal);
    getchar();
    eps = pow(10.0, -(double)expVal);
    printf("Kullanilan hata payi: %e\n", eps);
    return eps;
}

/* ===== METHOD 1: BISECTION ===== */
void bisection(void) {
    char expr[MAX_EXPR_LEN];
    double a, b, eps, fa, fb, fc, c;
    int iter;

    printf("\n====== BISECTION YONTEMI ======\n");
    readInput(expr);

    printf("Aralik giriniz [a b]: ");
    scanf("%lf %lf", &a, &b);
    getchar();
    eps = readEps();

    fa = evalExpr(expr, a);
    fb = evalExpr(expr, b);

    if (fa * fb > 0) {
        printf("HATA: f(a) ve f(b) ayni isarete sahip!\n");
        return;
    }

    printf("\n%4s %12s %12s %12s %12s %12s %12s\n",
           "Iter", "a", "f(a)", "b", "f(b)", "c=(a+b)/2", "f(c)");
    printf("%.100s\n", "----------------------------------------------------------------------------------------------------");

    iter = 0;
    fc = evalExpr(expr, (a + b) / 2.0);
    while ((b - a) > eps && iter < 1000 && fabs(fc) >= eps) {
        c = (a + b) / 2.0;
        fc = evalExpr(expr, c);
        fa = evalExpr(expr, a);
        fb = evalExpr(expr, b);

        printf("%4d %12.8f %12.8f %12.8f %12.8f %12.8f %12.8f\n",
               iter + 1, a, fa, b, fb, c, fc);

        if (fa * fc < 0.0) b = c;
        else a = c;
        iter++;
    }

    c = (a + b) / 2.0;
    fc = evalExpr(expr, c);
    printf("\n>>> Kok yaklasimi: %.10f\n", c);
    printf(">>> f(kok) = %e, iterasyon sayisi = %d\n", fc, iter);
}

/* ===== METHOD 2: REGULA FALSI ===== */
void regulaFalsi(void) {
    char expr[MAX_EXPR_LEN];
    double a, b, eps, fa, fb, c, fc;
    int iter;

    printf("\n====== REGULA-FALSI YONTEMI ======\n");
    readInput(expr);

    printf("Aralik giriniz [a b]: ");
    scanf("%lf %lf", &a, &b);
    getchar();
    eps = readEps();

    fa = evalExpr(expr, a);
    fb = evalExpr(expr, b);

    if (fa * fb > 0) {
        printf("HATA: f(a) ve f(b) ayni isarete sahip!\n");
        return;
    }

    printf("\n%4s %12s %12s %12s %12s %12s %12s\n",
           "Iter", "a", "f(a)", "b", "f(b)", "c", "f(c)");
    printf("%.100s\n", "----------------------------------------------------------------------------------------------------");

    iter = 0;
    c = a;
    fc = evalExpr(expr, c);
    fa = evalExpr(expr, a);
    fb = evalExpr(expr, b);
    {
        int converged = 0;
        while (iter < 1000 && !converged) {
            double old_c;
            fa = evalExpr(expr, a);
            fb = evalExpr(expr, b);
            old_c = c;
            c = a - fa * (b - a) / (fb - fa);
            fc = evalExpr(expr, c);

            printf("%4d %12.8f %12.8f %12.8f %12.8f %12.8f %12.8f\n",
                   iter + 1, a, fa, b, fb, c, fc);

            if (fa * fc < 0.0) b = c;
            else a = c;

            iter++;

            if (fabs(fc) < eps || fabs(c - old_c) < eps) {
                converged = 1;
            }
        }
    }

    printf("\n>>> Kok yaklasimi: %.10f\n", c);
    printf(">>> f(kok) = %e, iterasyon sayisi = %d\n", fc, iter);
}

/* ===== METHOD 3: NEWTON-RAPHSON ===== */
void newtonRaphson(void) {
    char expr[MAX_EXPR_LEN];
    double x0, eps, fx, dfx, x1;
    int iter;

    printf("\n====== NEWTON-RAPHSON YONTEMI ======\n");
    readInput(expr);

    printf("Baslangic degeri x0: ");
    scanf("%lf", &x0);
    getchar();
    eps = readEps();

    printf("\n%4s %14s %14s %14s %14s\n",
           "Iter", "x_curr", "f(x)", "f'(x)", "x_next");
    printf("%.80s\n", "--------------------------------------------------------------------------------");

    iter = 0;
    x1 = x0;
    fx  = evalExpr(expr, x1);
    dfx = numericalDeriv(expr, x1);
    while (iter < 1000 && fabs(dfx) >= 1e-15 && (iter == 0 || fabs(x1 - x0) >= eps)) {
        fx  = evalExpr(expr, x1);
        dfx = numericalDeriv(expr, x1);

        if (fabs(dfx) < 1e-15) {
            printf("HATA: Turev sifira cok yakin, diverge!\n");
            iter = 1000;
        } else {
            x0 = x1;
            x1 = x0 - fx / dfx;

            printf("%4d %14.10f %14.10f %14.10f %14.10f\n",
                   iter + 1, x0, fx, dfx, x1);
            iter++;
        }
    }

    fx = evalExpr(expr, x1);
    printf("\n>>> Kok yaklasimi: %.10f\n", x1);
    printf(">>> f(kok) = %e, iterasyon sayisi = %d\n", fx, iter + 1);
}

/* ===== METHOD 4: INVERSE MATRIX (Gauss-Jordan) ===== */
void inverseMatrix(void) {
    int n, i, j, k;
    double **aug, pivot, factor;

    printf("\n====== MATRIS TERSI (NxN) ======\n");
    printf("N degerini giriniz: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("N en az 2 olmalidir.\n");
        return;
    }

    
    aug = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        aug[i] = (double*)calloc(2*n, sizeof(double));
    }

    printf("Matris degerlerini satirlar halinde giriniz (%d deger toplam):\n", n*n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &aug[i][j]);
        }
    }
    getchar();

    
    for (i = 0; i < n; i++) aug[i][n + i] = 1.0;

    printf("\nGirilmis Matris:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%10.4f ", aug[i][j]);
        printf("\n");
    }

    
    for (k = 0; k < n; k++) {
        /* Find pivot */
        int maxRow = k;
        for (i = k+1; i < n; i++) {
            if (fabs(aug[i][k]) > fabs(aug[maxRow][k])) maxRow = i;
        }
        /* Swap rows */
        {
            double *tmp = aug[k];
            aug[k] = aug[maxRow];
            aug[maxRow] = tmp;
        }

        pivot = aug[k][k];
        if (fabs(pivot) < 1e-14) {
            printf("HATA: Matris tekil (tersi yok)!\n");
            for (i = 0; i < n; i++) free(aug[i]);
            free(aug);
            return;
        }

        for (j = 0; j < 2*n; j++) aug[k][j] /= pivot;

        for (i = 0; i < n; i++) {
            if (i != k) {
                factor = aug[i][k];
                for (j = 0; j < 2*n; j++) {
                    aug[i][j] -= factor * aug[k][j];
                }
            }
        }
    }

    printf("\nMatrisin Tersi:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%10.6f ", aug[i][n+j]);
        printf("\n");
    }

    for (i = 0; i < n; i++) free(aug[i]);
    free(aug);
}

/* ===== METHOD 5: CHOLESKY  ===== */
void choleskyMethod(void) {
    int n, i, j, k;
    double sum;
    double **A, **L;

    printf("\n====== CHOLESKY (ALU) YONTEMI ======\n");
    printf("N degerini giriniz: ");
    scanf("%d", &n);

    A = (double**)malloc(n * sizeof(double*));
    L = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        A[i] = (double*)calloc(n, sizeof(double));
        L[i] = (double*)calloc(n, sizeof(double));
    }

    printf("Matris degerlerini giriniz (%d deger):\n", n*n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    getchar();

    printf("\nGirdi Matrisi A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%10.4f ", A[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            sum = 0.0;
            for (k = 0; k < j; k++) sum += L[i][k] * L[j][k];
            if (i == j) {
                double val;
                val = A[i][i] - sum;
                if (val < 0.0) {
                    printf("UYARI: Matris pozitif tanimsiz olabilir! Negatif karekök aliniyor.\n");
                    val = fabs(val);
                }
                L[i][j] = sqrt(val);
            } else {
                if (fabs(L[j][j]) < 1e-14) L[i][j] = 0.0;
                else L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    printf("\nAlt Ucgensel L Matrisi (A = L * L^T):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%10.6f ", L[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++) { free(A[i]); free(L[i]); }
    free(A); free(L);
}

/* ===== METHOD 6: GAUSS-SEIDEL ===== */
void gaussSeidel(void) {
    int n, i, j, maxIter;
    double eps, diff, maxDiff, sum;
    double **A, *b, *x, *xNew;

    printf("\n====== GAUSS-SEIDEL YONTEMI ======\n");
    printf("Denklem sayisi N: ");
    scanf("%d", &n);

    A    = (double**)malloc(n * sizeof(double*));
    b    = (double*)calloc(n, sizeof(double));
    x    = (double*)calloc(n, sizeof(double));
    xNew = (double*)calloc(n, sizeof(double));
    for (i = 0; i < n; i++) {
        A[i] = (double*)calloc(n, sizeof(double));
        x[i] = 0.0;
    }

    printf("Arttirilmis matrisi [A|b] giriniz (%d satir, %d sutun):\n", n, n+1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%lf", &A[i][j]);
        scanf("%lf", &b[i]);
    }
    getchar();
    eps = readEps();

    printf("\n%5s", "Iter");
    for (i = 0; i < n; i++) printf(" %14s", (i==0) ? "x[0]" : (i==1) ? "x[1]" : "x[i]");
    printf(" %14s\n", "max_diff");
    printf("%.90s\n", "------------------------------------------------------------------------------------------");

    maxIter = 1;
    maxDiff = eps + 1.0;
    while (maxIter <= 500 && maxDiff >= eps) {
        int diagOk = 1;
        maxDiff = 0.0;
        for (i = 0; i < n && diagOk; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i) sum -= A[i][j] * x[j];
            }
            if (fabs(A[i][i]) < 1e-14) {
                printf("HATA: Diagonal sifir!\n");
                diagOk = 0;
            } else {
                xNew[i] = sum / A[i][i];
                diff = fabs(xNew[i] - x[i]);
                if (diff > maxDiff) maxDiff = diff;
                x[i] = xNew[i];
            }
        }
        if (diagOk) {
            printf("%5d", maxIter);
            for (i = 0; i < n; i++) printf(" %14.8f", x[i]);
            printf(" %14.2e\n", maxDiff);
            if (maxDiff < eps) {
                printf("Yakinsamadi! %d iterasyonda eps = %e saglandi.\n", maxIter, eps);
            }
            maxIter++;
        } else {
            maxDiff = 0.0;
        }
    }

    printf("\nSonuc:\n");
    for (i = 0; i < n; i++) printf("  x%d = %.8f\n", i, x[i]);

    for (i = 0; i < n; i++) free(A[i]);
    free(A); free(b); free(x); free(xNew);
}

/* ===== METHOD 7: NUMERICAL DERIVATIVE ===== */
void numericalDerivative(void) {
    char expr[MAX_EXPR_LEN];
    double x0, h, fwd, bwd, cen;

    printf("\n====== SAYISAL TUREV ======\n");
    readInput(expr);

    printf("Turev noktasi x0 ve adim h (ornek: 1.0 0.001): ");
    scanf("%lf %lf", &x0, &h);
    getchar();

    fwd = (evalExpr(expr, x0 + h) - evalExpr(expr, x0)) / h;
    bwd = (evalExpr(expr, x0) - evalExpr(expr, x0 - h)) / h;
    cen = (evalExpr(expr, x0 + h) - evalExpr(expr, x0 - h)) / (2.0 * h);

    printf("\n--- Sayisal Turev Sonuclari (x0=%.6f, h=%.6f) ---\n", x0, h);
    printf("  Ileri fark  (forward)  : %.10f\n", fwd);
    printf("  Geri fark   (backward) : %.10f\n", bwd);
    printf("  Merkezi fark (central)  : %.10f\n", cen);
}

/* ===== METHOD 8: SIMPSON ===== */
void simpsonMethod(void) {
    char expr[MAX_EXPR_LEN];
    double a, b, h, sum13, sum38;
    int n13, n38, i;

    printf("\n====== SIMPSON YONTEMI ======\n");
    readInput(expr);

    printf("Entegral sinirlarini giriniz [a b]: ");
    scanf("%lf %lf", &a, &b);
    getchar();

    /* 1/3 Rule */
    printf("-- Simpson 1/3 kurali --\n");
    printf("Alt aralik sayisi n (cift sayi ve >= 2): ");
    scanf("%d", &n13);
    getchar();
    if (n13 % 2 != 0) { n13++; printf("n tek geldi, n=%d yapildi.\n", n13); }
    if (n13 < 2) n13 = 2;

    h = (b - a) / n13;
    sum13 = evalExpr(expr, a) + evalExpr(expr, b);
    for (i = 1; i < n13; i++) {
        double xi;
        xi = a + i * h;
        if (i % 2 == 0) sum13 += 2.0 * evalExpr(expr, xi);
        else             sum13 += 4.0 * evalExpr(expr, xi);
    }
    sum13 *= h / 3.0;
    printf("Simpson 1/3 kurali sonucu (n=%d): %.10f\n", n13, sum13);

    /* 3/8 Rule */
    printf("-- Simpson 3/8 kurali --\n");
    printf("Alt aralik sayisi n (3'un kati ve >= 3): ");
    scanf("%d", &n38);
    getchar();
    while (n38 % 3 != 0 || n38 < 3) { n38++; }
    printf("Kullanilan n = %d\n", n38);

    h = (b - a) / n38;
    sum38 = evalExpr(expr, a) + evalExpr(expr, b);
    for (i = 1; i < n38; i++) {
        double xi;
        xi = a + i * h;
        if (i % 3 == 0) sum38 += 2.0 * evalExpr(expr, xi);
        else             sum38 += 3.0 * evalExpr(expr, xi);
    }
    sum38 *= 3.0 * h / 8.0;
    printf("Simpson 3/8 kurali sonucu (n=%d): %.10f\n", n38, sum38);
}

/* ===== METHOD 9: TRAPEZOIDAL ===== */
int trapezMethod(void) {
    char expr[MAX_EXPR_LEN];
    double a, b, h, sum;
    int n, i;

    printf("\n====== TRAPEZ YONTEMI ======\n");
    readInput(expr);

    printf("Entegral sinirlarini ve alt aralik sayisini giriniz [a b n]: ");
    scanf("%lf %lf %d", &a, &b, &n);
    getchar();
    if (n < 1) n = 1;

    h = (b - a) / n;
    sum = evalExpr(expr, a) + evalExpr(expr, b);
    for (i = 1; i < n; i++) {
        sum += 2.0 * evalExpr(expr, a + i * h);
    }
    sum *= h / 2.0;

    printf("\nTrapez Yontemi Sonucu (n=%d): %.10f\n", n, sum);
    return 0;
}

/* ===== METHOD 10: GREGORY-NEWTON INTERPOLATION ===== */
void gregoryNewton(void) {
    int n, i, j;
    double xInterp, h, s, result, *y, *x, **diff, term, prod;

    printf("\n====== GREGORY-NEWTON ENTERPOLASYONU ======\n");
    printf("Nokta sayisi n (>= 2): ");
    scanf("%d", &n);
    if (n < 2) { printf("En az 2 nokta gerekli.\n"); return; }

    x    = (double*)malloc(n * sizeof(double));
    y    = (double*)malloc(n * sizeof(double));
    diff = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        diff[i] = (double*)malloc(n * sizeof(double));
    }

    printf("x ve y degerlerini giriniz (esit aralikli x varsayilir):\n");
    for (i = 0; i < n; i++) {
        printf("Nokta %d (x y): ", i);
        scanf("%lf %lf", &x[i], &y[i]);
        diff[i][0] = y[i];
    }
    getchar();

    h = x[1] - x[0];

    
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    printf("Enterpolasyon noktasi X: ");
    scanf("%lf", &xInterp);
    getchar();

    s = (xInterp - x[0]) / h;
    result = diff[0][0];
    for (j = 1; j < n; j++) {
        prod = 1.0;
        for (i = 0; i < j; i++) {
            prod *= (s - i);
        }
        {
            double fact = 1.0;
            int k;
            for (k = 1; k <= j; k++) fact *= k;
            term = prod * diff[0][j] / fact;
        }
        result += term;
    }

    printf("\nEnterpolasyon sonucu P(%.4f) = %.10f\n", xInterp, result);

    free(x); free(y);
    for (i = 0; i < n; i++) free(diff[i]);
    free(diff);
}

/* ===== MAIN ===== */
int main(void) {
    int choice;
    char menuBuf[32];

    printf("============================================================\n");
    printf("  Yildiz Teknik Universitesi - Sayisal Analiz Projesi\n");
    printf("  Ogrenci: Ibrahim Enes Sayin | No: 24011116\n");
    printf("============================================================\n");

    do {
        printf("\n--- ANA MENU ---\n");
        printf("  1.  Bisection Yontemi\n");
        printf("  2.  Regula-Falsi Yontemi\n");
        printf("  3.  Newton-Raphson Yontemi\n");
        printf("  4.  NxN Matrisin Tersi\n");
        printf("  5.  Cholesky (ALU) Yontemi\n");
        printf("  6.  Gauss-Seidel Yontemi\n");
        printf("  7.  Sayisal Turev\n");
        printf("  8.  Simpson Yontemi\n");
        printf("  9.  Trapez Yontemi\n");
        printf("  10. Gregory-Newton Enterpolasyonu\n");
        printf("  0.  Cikis\n");
        printf("Seciminiz: ");
        fflush(stdout);
        if (fgets(menuBuf, sizeof(menuBuf), stdin) == NULL) {
            choice = 0;
        } else {
            choice = atoi(menuBuf);
        }

        switch (choice) {
            case 1:  bisection();          break;
            case 2:  regulaFalsi();        break;
            case 3:  newtonRaphson();      break;
            case 4:  inverseMatrix();      break;
            case 5:  choleskyMethod();     break;
            case 6:  gaussSeidel();        break;
            case 7:  numericalDerivative(); break;
            case 8:  simpsonMethod();      break;
            case 9:  trapezMethod();       break;
            case 10: gregoryNewton();      break;
            case 0:  printf("Program sonlandiriliyor...\n"); break;
            default: printf("Gecersiz secim!\n"); break;
        }
    } while (choice != 0);

    return 0;
}
