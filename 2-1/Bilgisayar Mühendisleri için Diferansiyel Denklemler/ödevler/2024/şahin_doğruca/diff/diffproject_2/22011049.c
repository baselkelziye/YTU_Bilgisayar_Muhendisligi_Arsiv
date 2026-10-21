#include <stdio.h>
#include <stdlib.h>

struct func{
    double A,B,Xl;
};

void getParameters(struct func * AandB, double * x0, double * y0, double * h, double * act) {
    printf("The function is like Ay' + By = g(t)\n");
    printf("please enter A, B, X values : ");
    scanf("%lf %lf %lf", &AandB->A, &AandB->B, &AandB->Xl);

    printf("f(x0, y0) = (g(x) - By) / A\n");

    printf("please enter x0 and y0 values : ");
    scanf("%lf %lf", x0, y0);

    printf("please enter h (step size) : ");
    scanf("%lf", h);

    
    printf("please enter actual y for x last : ");
    scanf("%lf", act);
}

double g_func(double x) {
    return 0;
}

double eval(struct func * AandB, double x0, double y) {
    return ((g_func(x0)) - (AandB->B * y)) / AandB->A;
    
}

void rungeKutta4(struct func * AandB, double x, double y0, double h, double act) {
    double k1, k2, k3, k4, y = y0;
    int i = 1, n = (AandB->Xl - x) / h;

    for(i = 1; i <= n; i++) {
        k1 = h * eval(AandB, x, y);
        k2 = h * eval(AandB, x + 0.5*h , y + 0.5*k1);
        k3 = h * eval(AandB, x + 0.5*h, y + 0.5*k2);
        k4 = h * eval(AandB, x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;

        printf("%d. epoc y:%.6f  y0:%.6f\n", i , y, y0);

        y0 = y;
        x += h;
    }
    
    printf("last y value is : %.6f\n", y);
    printf("err is : %.6f\n", act - y);

    
}

int main() {
    struct func * AandB = (struct func *) malloc(sizeof(struct func));
    double y0, x0, h, act;
    // function for get parameters
    getParameters(AandB, &x0, &y0, &h, &act);
    rungeKutta4(AandB, x0, y0, h, act);
    return 0;
}
