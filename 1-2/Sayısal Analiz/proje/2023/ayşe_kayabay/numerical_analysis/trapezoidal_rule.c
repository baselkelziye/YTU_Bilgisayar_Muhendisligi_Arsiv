#include <stdio.h>
#include <math.h>

float calculate(float coefficients[10], float root, int degree);
int main()
{
    int i;
    float first, last, h, area;
    int degree, n;
    float coefficients[10];
    printf("Enter the degree of the equation.");
    scanf("%d", &degree);
    for (i = degree; i >= 0; i--)
    {
        printf("Enter the coefficient of the %d-order element.", i);
        scanf("%f", &coefficients[i]);
    }
    printf("Enter the start and end of the range of integral.");
    scanf("%f %f", &first, &last);
    printf("Enter the n value.");
    scanf("%d", &n);
    h = (last - first) / n;
    for (i = 0; i < n; i++)
    {
        area += (calculate(coefficients, first, degree) + calculate(coefficients, first + h, degree)) * h / 2;
        first += h;
    }
    printf("Area Value=%f", area);
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
