#include <stdio.h>
#include <math.h>

float calculate(float coefficients[10], float root, int degree);
int main()
{
    int i, j;
    float first, last, h, sum;
    int degree, n;
    float coefficients[10];
    printf("Enter the degree of the equation.");
    scanf("%d", &degree);
    for (i = degree; i >= 0; i--)
    {
        printf("Enter the coefficient of the %d-order element.", i);
        scanf("%f", &coefficients[i]);
    }
    printf("Enter the start and end of the range of integral");
    scanf("%f %f", &first, &last);
    printf("Enter n value");
    scanf("%d", &n);
    // formula: (b-a)(f(a)+4f((a+b)/2)+f(b))/6
    h = (last - first) / n;
    sum += calculate(coefficients, first, degree) + calculate(coefficients, last, degree);
    for (i = 1; i < n; i++)
    {
        first += h;
        if (i % 2 != 0)
        {
            sum += 4 * calculate(coefficients, first, degree);
        }
        else
        {
            sum += 2 * calculate(coefficients, first, degree);
        }
    }
    sum = sum * h / 3;
    printf("Area Value=%f", sum);
    return 0;
}

float calculate(float coefficients[10], float root, int degree)
{
    int i;
    float result = 0;
    for (i = 1; i <= degree; i++)
    {
        result += coefficients[i] * pow(root, i);
    }
    result += coefficients[0];
    return result;
}
