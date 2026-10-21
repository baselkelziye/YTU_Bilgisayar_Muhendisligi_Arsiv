#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50

float bisectionmethod(float lower_bound, float upper_bound, float error, int maxiterasyon, int terim, float coefficient[MAX_SIZE][2]);
float calculate(int terim, float x, float coefficient[MAX_SIZE][2]);
float regulafalsi(float lower_bound, float upper_bound, float error, int maxiterasyon, int terim, float coefficient[MAX_SIZE][2]);
float newtonRaphson(float lower_bound, float error, int maxiterasyon, int terim, float coefficient[MAX_SIZE][2]);
float derivative(int terim, float x, float coefficient[MAX_SIZE][2]);
void matrixInverse(float matrix[MAX_SIZE][MAX_SIZE], int matrisboyut);
void gausselimination(int matrisboyut);
void gaussSeidel();
void polinomal(int terim, float coefficient[MAX_SIZE][2]);
double sayisalturev(float coefficient[MAX_SIZE][2], int terim);
double simpsonIntegration(float lower_bound, float upper_bound, int n, int rule, int terim, float coefficient[MAX_SIZE][2]);
double trapezIntegral(float lower_bound, float upper_bound, int n, int terim, float coefficient[MAX_SIZE][2]);
double gregoryNewtonInterpolation(double x, int n, double *xi[MAX_SIZE], double *fi[MAX_SIZE]);

int main()
{
    float lower_bound = 0, upper_bound = 0, error, root, root1, root2, root3, matrix[MAX_SIZE][MAX_SIZE], coefficient[MAX_SIZE][2];
    int terim, yontem, maxiterasyon, iterasyon = 0, matrisboyut, i, j, n, rule, cikis;
    double turev, x, *xi[MAX_SIZE], *fi[MAX_SIZE];
    do
    {
        printf("\n hangi yontem ile cozmek istediginizi seciniz \n");
        printf(" 0. cikmak icin sifir giriniz \n 1.	Bisection yontemi \n 2.	Regula-Falsi yontemi \n 3.	Newton-Rapshon yontemi \n 4.	NxN lik bir matrisin tersi yontemi \n 5.	Gauus Eleminasyon yontemi \n 6.	Gauss Seidal yontemleri \n 7.	Sayisal Turev (merkezi, ileri ve geri farklar opsiyonlu) \n 8.	Simpson yontemi \n 9.	Trapez yontemi \n 10.	Degisken donusumsuz Gregory newton Enterpolasyonu \n");
        scanf("%d", &yontem);
        if (yontem < 0 || yontem > 10)
            printf("Hatali giris! Gecerli bir yontem seciniz.\n");

        if (yontem == 1 || yontem == 2 || yontem == 3)
        {
            printf("hata payi kac olsun (ornek 0.01) \n");
            scanf("%f", &error);
            if (error <= 0)
                printf("Hatali giris! Gecerli bir hata payi giriniz.\n");

            printf("istediginiz iterasyon (max iteration) sayisini giriniz \n");
            scanf("%d", &maxiterasyon);
            if (maxiterasyon <= 0)
                printf("Hatali giris! Gecerli bir maksimum iterasyon sayisi giriniz.\n");

            printf("polinomun oldugu araliktaki en kucuk sayiyi giriniz \n");
            scanf("%f", &lower_bound);
            printf("polinomun oldugu araliktaki en buyuk sayiyi giriniz \n");
            scanf("%f", &upper_bound);

            int i = 0;
            printf(" girecegin fonksiyon kac terimden olusuyor ?\n ");
            scanf("%d", &terim);

            printf(" fonksiyondaki terimlerin katsayisini ve terim sayini giriniz\n ");
            for (i = terim - 1; i >= 0; i--)
            {
                printf("%d . bilinmeyen derecesi : ", i);
                scanf("%f", &coefficient[i][0]);
                printf("%d bilinmeyen katsayisi : ", i);
                scanf("%f", &coefficient[i][1]);
            }
        }

        /* simdi islem kismina baslioruz */
        if (yontem == 1)
        {
            root = bisectionmethod(lower_bound, upper_bound, error, maxiterasyon, terim, coefficient);
            printf(" \n the solution is : %f", root);
        }
        else if (yontem == 2)
        {
            root1 = regulafalsi(lower_bound, upper_bound, error, maxiterasyon, terim, coefficient);
            printf(" \n the solution is : %f", root1);
        }
        else if (yontem == 3)
        {
            root2 = newtonRaphson(lower_bound, error, maxiterasyon, terim, coefficient);
            printf(" \n the solution is : %f", root2);
        }
        else if (yontem == 4)
        {
            printf(" matrisin boyutu kac olsun ? \n ");
            scanf(" %d", &matrisboyut);
            if (matrisboyut <= 0)
            {
                printf(" HATALI GIRIS ! lutfen gecerli bir boyut giriniz");
            }
            printf("matrisin degerlerini giriniz :\n");
            for (i = 0; i < matrisboyut; i++)
            {
                for (j = 0; j < matrisboyut; j++)
                {
                    printf("Enter the value at position (%d, %d): ", i, j);
                    scanf("%f", &matrix[i][j]);
                }
            }
            matrixInverse(matrix, matrisboyut);
        }

        else if (yontem == 5)
        {

            printf("Enter the size of the matrix: ");
            scanf("%d", &matrisboyut);

            gausselimination(matrisboyut);
        }
        else if (yontem == 6)
        {
            gaussSeidel();
        }
        else if (yontem == 7)
        {
            turev = sayisalturev(coefficient, terim);
            printf("Turev sonucu: %.2f\n", turev);
        }
        else if (yontem == 8)
        {
            double result = simpsonIntegration(lower_bound, upper_bound, n, rule, terim, coefficient);

            printf("The result of integration: %lf\n", result);
        }
        else if (yontem == 9)
        {
            double integral = trapezIntegral(lower_bound, upper_bound, n, terim, coefficient);
            printf("Trapez y�ntemiyle hesaplanan integral: %lf\n", integral);
        }
        else if (yontem == 10)
        {
            double interpolation = gregoryNewtonInterpolation(x, n, xi, fi);
            printf("Gregory-Newton Enterpolasyonu sonucu: %lf\n", interpolation);
        }

    } while (cikis != 0);

    return 0;
}

float bisectionmethod(float lower_bound, float upper_bound, float error, int maxiterasyon, int terim, float coefficient[MAX_SIZE][2])
{
    float middle = 0.0;
    int iterasyon;
    float f_start = calculate(terim, lower_bound, coefficient);
    float f_end = calculate(terim, upper_bound, coefficient);
    float f_middle = calculate(terim, middle, coefficient);

    if (f_start != 0 && f_end != 0)
    {
        if (f_start * f_end > 0)
        {
            printf("girdiginiz sinir degerlerinde bir kok yoktur");
            return NAN;
        }
    }

    for (iterasyon = 1; iterasyon <= maxiterasyon; iterasyon++)
    {
        middle = (lower_bound + upper_bound) / 2.0;

        if (isnan(f_start) || isnan(f_end) || isnan(f_middle))
        {
            printf("Error: function value is not a number\n");
            return NAN;
        }

        printf(" \n ");
        printf("start : %f \n end : %f \n middle :%f \n f(start): %f \n f(end): %f \n f(middle): %f \n iterasyon : %d \n ", lower_bound, upper_bound, middle, f_start, f_end, f_middle, iterasyon);
        printf(" \n ");

        if (fabs(upper_bound - lower_bound) <= error || fabs(f_middle) < error)
        {
            // son iki kok hatadan kucukse yine sonuca ulasmis oluyoruz
            return middle;
        }
        if (f_start * f_middle < 0)
        {
            upper_bound = middle;
        }
        else if (f_end * f_middle < 0)
        {
            lower_bound = middle;
        }
    }
    printf("\n the solution is : %f \n ", middle);
    // cevap bulunmadan max iterasyon sayisina ulastiysak
    return middle;
}

float calculate(int terim, float x, float coefficient[MAX_SIZE][2])
{
    int i = 0;
    float result = 0.0;
    for (i = terim; i >= 0; i--)
    {
        result += (coefficient[i][1] * pow(x, coefficient[i][0]));
    }
    return result;
}

float regulafalsi(float lower_bound, float upper_bound, float error, int maxiterasyon, int terim, float coefficient[MAX_SIZE][2])
{
    float newroot = 0.0;
    int iterasyon;
    float f_newroot = calculate(terim, newroot, coefficient);
    float f_start = calculate(terim, lower_bound, coefficient);
    float f_end = calculate(terim, upper_bound, coefficient);
    if (f_start != 0 && f_end != 0)
    {
        if (f_start * f_end > 0)
        {
            printf("girdiginiz sinir degerlerinde bir kok yoktur");
            return NAN;
        }
    }

    for (iterasyon = 1; iterasyon <= maxiterasyon; iterasyon++)
    {
        // bisectionmethod dan farki bu new root islemidir
        newroot = ((lower_bound * f_end) - (upper_bound * f_start)) / (f_end - f_start);

        if (isnan(f_start) || isnan(f_end) || isnan(f_newroot))
        {
            printf("Error: function value is not a number\n");
            return NAN;
        }

        printf(" \n ");
        printf("start : %f \n end : %f \n newroot :%f \n f(start): %f \n f(end): %f \n f(newroot): %f \n iterasyon : %d \n ", lower_bound, upper_bound, newroot, f_start, f_end, f_newroot, iterasyon);
        printf(" \n ");

        if (fabs(upper_bound - lower_bound) <= error || fabs(newroot) < error)
        {
            // son iki kok hatadan kucukse yine sonuca ulasmis oluyoruz
            return newroot;
        }

        if (f_start * f_newroot < 0)
        {
            upper_bound = newroot;
            f_end = newroot;
        }
        else if (f_end * f_newroot < 0)
        {
            lower_bound = newroot;
            f_start = newroot;
        }
    }
    printf("\n the solution is : %f \n ", newroot);
    // cevap bulunmadan max iterasyon sayisina ulastiysak
    return NAN;
}

float derivative(int terim, float x, float coefficient[MAX_SIZE][2])
{
    int i = 0;
    float result = 0.0;
    for (i = terim; i >= 1; i--)
    {
        result += (i * coefficient[i][1] * pow(x, coefficient[i - 1][0]));
    }
    return result;
}

float newtonRaphson(float lower_bound, float error, int maxiterasyon, int terim, float coefficient[MAX_SIZE][2])
{
    float x = lower_bound;
    int iterasyon = 0;
    float x_new = 0.0, f_x, f_turev_x;

    for (iterasyon = 1; iterasyon <= maxiterasyon; iterasyon++)
    {
        if (isnan(x_new) || isnan(f_x) || isnan(f_turev_x))
        {
            printf("Error: function value is not a number\n");
            return NAN;
        }

        f_x = calculate(terim, x, coefficient);
        f_turev_x = derivative(terim, x, coefficient);
        x_new = x - (f_x / f_turev_x);

        printf(" \n ");
        printf("Xn : %f \n Xn+1 : %f \n f(Xn): %f \n f^(Xn): %f \n iterasyon : %d \n ", x, x_new, f_x, f_turev_x, iterasyon);
        printf(" \n ");

        if (fabs(x_new) < error)
        {
            return x_new;
        }

        if (fabs(f_turev_x) < 0.000001)
        {
            printf("Error: derivative is too small\n");
            return NAN;
        }
        if (fabs(x_new - x) < error)
        {
            return x_new;
        }

        x = x_new;
    }

    printf("Error: method did not converge\n");
    return NAN;
}

void matrixInverse(float matrix[MAX_SIZE][MAX_SIZE], int matrisboyut)
{
    int i = 0, j = 0, k = 0;
    float inverse[MAX_SIZE][MAX_SIZE], c, pivot;

    printf("orjinal matris :\n");
    for (i = 0; i < matrisboyut; i++)
    {
        for (j = 0; j < matrisboyut; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    i = 0, j = 0;
    // Birim matris olusturma
    for (i = 0; i < matrisboyut; i++)
    {
        for (j = 0; j < matrisboyut; j++)
        {
            if (i == j)
            {
                inverse[i][j] = 1.0;
            }
            else
            {
                inverse[i][j] = 0.0;
            }
        }
    }
    i = 0, j = 0;
    // Gauss-Jordan y�ntemi ile matrisin tersini bulma
    for (j = 0; j < matrisboyut; j++)
    {
        for (i = 0; i < matrisboyut; i++)
        {
            if (i != j)
            {
                c = matrix[i][j] / matrix[j][j];
                for (k = 0; k < matrisboyut; k++)
                {
                    matrix[i][k] -= c * matrix[j][k];
                    inverse[i][k] -= c * inverse[j][k];
                }
            }
        }
    }
    i = 0, j = 0;
    // Matrisin ana k�segen elemanlarini 1'e normalize etme
    for (i = 0; i < matrisboyut; i++)
    {
        pivot = matrix[i][i];
        for (j = 0; j < matrisboyut; j++)
        {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }
    }
    i = 0, j = 0;
    printf("Matrisin Tersi:\n");
    for (i = 0; i < matrisboyut; i++)
    {
        for (j = 0; j < matrisboyut; j++)
        {
            printf("%.2f ", inverse[i][j]);
        }
        printf("\n");
    }
}

void gausselimination(int matrisboyut)
{
    int i = 0, j = 0, k = 0;
    // Allocate memory for the matrix
    float **matrix = (float **)malloc(matrisboyut * sizeof(float *));
    for (i = 0; i < matrisboyut; i++)
    {
        matrix[i] = (float *)malloc((matrisboyut + 1) * sizeof(float));
    }
    i = 0;
    // Read the values of the matrix
    printf("Enter the values of the AUGMENTED matrix:\n");
    for (i = 0; i < matrisboyut; i++)
    {
        for (j = 0; j < matrisboyut + 1; j++)
        {
            printf("Enter the value at position (%d, %d): ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Perform Gaussian elimination
    j = 0, i = 0;
    // Convert to upper triangular form
    for (j = 0; j < matrisboyut - 1; j++)
    {
        for (i = j + 1; i < matrisboyut; i++)
        {
            float ratio = matrix[i][j] / matrix[j][j];
            for (k = j; k < matrisboyut + 1; k++)
            {
                matrix[i][k] = matrix[i][k] - (ratio * matrix[j][k]);
            }
        }
    }

    // Solve for unknown variables
    float *value = (float *)malloc(matrisboyut * sizeof(float));
    value[matrisboyut - 1] = matrix[matrisboyut - 1][matrisboyut] / matrix[matrisboyut - 1][matrisboyut - 1];
    i = 0, j = 0;
    for (i = matrisboyut - 2; i >= 0; i--)
    {
        float sum = 0;
        for (j = i + 1; j < matrisboyut; j++)
        {
            sum += matrix[i][j] * value[j];
        }
        value[i] = (matrix[i][matrisboyut] - sum) / matrix[i][i];
    }
    i = 0;
    printf("bilinmyenler:\n");
    for (i = 0; i < matrisboyut; i++)
    {
        printf("value[%d] = %.6f\n", i, value[i]);
    }
    i = 0;
    // Free the allocated memory
    for (i = 0; i < matrisboyut; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(value);
}

void gaussSeidel()
{
    float x[MAX_SIZE], prevX, error, matrix[MAX_SIZE][MAX_SIZE + 1]; // Initial values for the unknowns
    int iterasyon = 0, maxiterasyon, matrisboyut, i, j;
    int converged = 0;

    printf(" Enter the size of the matrix:? \n ");
    scanf(" %d", &matrisboyut);
    if (matrisboyut <= 0)
    {
        printf(" HATALI GIRIS ! lutfen gecerli bir boyut giriniz");
    }
    printf("Enter the values of the AUGMENTED matrix:\n");
    for (i = 0; i < matrisboyut; i++)
    {
        for (j = 0; j < matrisboyut + 1; j++)
        {
            printf("Enter the value at position (%d, %d): ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }
    i = 0;
    // Initialize the unknowns to 0
    for (i = 0; i < matrisboyut; i++)
    {
        x[i] = 0.0;
    }

    // Perform Gauss-Seidel iterations
    while (!converged && iterasyon < maxiterasyon)
    {
        converged = 1;
        i = 0, j = 0;
        for (i = 0; i < matrisboyut; i++)
        {
            float sum = 0.0;

            for (j = 0; j < matrisboyut; j++)
            {
                if (j != i)
                {
                    sum += matrix[i][j] * x[j];
                }
            }

            prevX = x[i]; // Store previous value

            // Update the current value of the unknown
            x[i] = (matrix[i][matrisboyut] - sum) / matrix[i][i];

            // Check for convergence
            if (fabs(x[i] - prevX) > error)
            {
                converged = 0;
            }
        }

        iterasyon++;
    }

    // Print the results
    if (converged)
    {
        printf("Solution converged after %d iterations:\n", iterasyon);
        i = 0;
        for (i = 0; i < matrisboyut; i++)
        {
            printf("x[%d] = %f\n", i, x[i]);
        }
    }
    else
    {
        printf("Solution did not converge after %d iterations.\n", iterasyon);
    }
}

double sayisalturev(float coefficient[MAX_SIZE][2], int terim)
{
    int secim;
    double turev = 0.0;
    float h;
    double fonk1, fonk2, fonk3, x;

    printf("polinomdaki en buyuk us kactir \n");
    scanf("%d", &terim);
    if (terim <= 0)
        printf("Hatali giris! Gecerli bir terim  giriniz.\n");

    polinomal(terim, coefficient);
    printf("h (noktalararasi fark) degerini giriniz \n");
    scanf("%f", &h);

    printf("turevi hesaplanacak noktayi giriniz \n");
    scanf("%f", &x);

    fonk1 = calculate(terim, (x + h), coefficient);
    fonk2 = calculate(terim, (x - h), coefficient);
    fonk3 = calculate(terim, (x), coefficient);

    printf("hangi turev cesidi ile hesaplamak istersiniz ? \n ");
    printf("1- merkezi fark yontemi \n 2- ileri fark yotemi \n 3- geri fark yontemi \n");
    scanf("%d", &secim);

    if (secim == 1)
    {
        // Merkezi fark y�ntemi
        // turev = (f(x + h) - f(x - h)) / (2 * h)
        turev = (fonk1 - fonk2) / (2 * h);
    }
    else if (secim == 2)
    {
        // Ileri fark y�ntemi
        // turev = (f(x + h) - f(x)) / h;
        turev = (fonk1 - fonk3) / h;
    }
    else if (secim == 3)
    {
        // Geri fark y�ntemi
        // turev = (f(x) - f(x - h)) / h;
        turev = (fonk3 - fonk2) / h;
    }
    else
    {
        printf("Hatali se�im!\n");
        return 0.0;
    }

    return turev;
}

void polinomal(int terim, float coefficient[MAX_SIZE][2])
{
    int i = 0;
    printf(" girecegin fonksiyon kac terimden olusuyor ?\n ");
    scanf("%d", &terim);

    printf(" fonksiyondaki terimlerin katsayisini ve terim sayini giriniz\n ");
    for (i = terim - 1; i >= 0; i--)
    {
        printf("%d . bilinmeyen derecesi : ", i);
        scanf("%f", &coefficient[i][0]);
        printf("%d bilinmeyen katsayisi : ", i);
        scanf("%f", &coefficient[i][1]);
    }
}

double simpsonIntegration(float lower_bound, float upper_bound, int n, int rule, int terim, float coefficient[MAX_SIZE][2])
{
    int i = 0;
    double h = (upper_bound - lower_bound) / n; // Step size
    double sum = 0.0;
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    printf("polinomun oldugu araliktaki en kucuk sayiyi giriniz \n");
    scanf("%f", &lower_bound);
    printf("polinomun oldugu araliktaki en buyuk sayiyi giriniz \n");
    scanf("%f", &upper_bound);
    polinomal(terim, coefficient);

    printf("Select the rule:\n");
    printf("1. 1/3 Rule\n");
    printf("2. 3/8 Rule\n");
    printf("Enter your choice: ");
    scanf("%d", &rule);

    for (i = 0; i <= n; i++)
    {
        double x = lower_bound + i * h;
        double y = calculate(terim, x, coefficient);

        if (i == 0 || i == n)
            sum += y;
        else if (rule == 1 && i % 2 == 1)
            sum += 4 * y; // 1/3 rule: odd terms
        else if (rule == 2)
        {
            if (i % 3 == 0)
                sum += 2 * y; // 3/8 rule: terms divisible by 3
            else
                sum += 3 * y; // 3/8 rule: remaining terms
        }
    }

    return (h / 3) * sum;
}

double trapezIntegral(float lower_bound, float upper_bound, int n, int terim, float coefficient[MAX_SIZE][2])
{
    int i = 0;
    printf("Integralin baslangic noktasini (a): ");
    scanf("%lf", &lower_bound);

    printf("Integralin bitis noktasini (b): ");
    scanf("%lf", &upper_bound);
    polinomal(terim, coefficient);

    printf("Bolum sayisini (n): ");
    scanf("%d", &n);
    double h = (upper_bound - lower_bound) / n; // Adim boyutu

    double sum = (calculate(terim, lower_bound, coefficient) + calculate(terim, upper_bound, coefficient)) / 2.0; // Ilk ve son terimleri topla

    for (i = 1; i < n; i++)
    {
        double x = lower_bound + i * h;          // x degeri
        sum += calculate(terim, x, coefficient); // Ara terimleri topla
    }
    double integral = h * sum; // Sonucu adim boyutuyla �arp

    return integral;
}

double gregoryNewtonInterpolation(double x, int n, double *xi[MAX_SIZE], double *fi[MAX_SIZE])
{
    int i = 0;
    double factorial = 1.0;
    double term = 1.0;

    printf("Degerlerin sayisini giriniz (n): ");
    scanf("%d", &n);

    printf("x degerlerini giriniz:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d: ", i);
        scanf("%lf", &xi[i]);
    }
    i = 0;
    printf("f(x) degerlerini giriniz:\n");
    for (i = 0; i < n; i++)
    {
        printf("f(x%d): ", i);
        scanf("%lf", &fi[i]);
    }
    printf("Enterpole edilecek x degerini giriniz: ");
    scanf("%lf", &x);
    double result = *fi[0]; // Baslangic degeri
    i = 0;
    for (i = 1; i < n; i++)
    {
        factorial *= i;
        term *= (x - *xi[i - 1]);
        result += (*fi[i] * term) / factorial;
    }

    return result;
}
