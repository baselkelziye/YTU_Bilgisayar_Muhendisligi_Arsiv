#include <stdio.h>
#include <math.h>
float calculate(float coefficients[10], float root, int degree);
int main()
{
    float first, n, last, error, epsilon;
    int i, degree;
    float coefficients[10], derivatized[10];
    printf("Enter the degree of the equation.");
    scanf("%d", &degree);
    for (i = degree; i >= 0; i--)
    {
        printf("Enter the coefficient of the %d-order element.", i);
        scanf("%f", &coefficients[i]);
    }
    for (i = 0; i < degree; i++)
    {
        derivatized[i] = coefficients[i + 1] * (i + 1);
    }
    printf("Enter the epsilon value");
    scanf("%f", &epsilon);
    printf("Enter the start and end of the range in order.");
    scanf("%f %f", &first, &last);
    printf("iteration	x		error\n");
    error = 0, i = 0;
    do
    {
        n = first - (calculate(coefficients, first, degree) / calculate(derivatized, first, degree));
        error = n - first;
        printf("%f	%f	%f\n", i, first, error);
        first = n;
        i++;
    } while (error > epsilon);
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