#include <stdio.h>
#include <math.h>
float calculate(float coefficients[10], float root, int degree);
int main()
{
    int i;
    int degree;
    float root, h, coefficients[10];
    float forward, backward, central;

    printf("Enter the degree of the equation.");
    scanf("%d", &degree);

    for (i = degree; i >= 0; i--)
    {
        printf("Enter the coefficient of the %d-order element.", i);
        scanf("%f", &coefficients[i]);
    }
    printf("Enter the x value.");
    scanf("%f", &root);

    printf("Enter the h value");
    scanf("%f", &h);

    forward = (calculate(coefficients, root + h, degree) - calculate(coefficients, root, degree)) / h;
    backward = (calculate(coefficients, root, degree) - calculate(coefficients, root - h, degree)) / h;
    central = (calculate(coefficients, root + h, degree) - calculate(coefficients, root - h, degree)) / (2 * h);

    printf("Analytical Result: %f, Backward Difference: %f, Forward Difference: %f, Central Difference: %f", calculate(coefficients, root, degree), backward, forward, central);
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