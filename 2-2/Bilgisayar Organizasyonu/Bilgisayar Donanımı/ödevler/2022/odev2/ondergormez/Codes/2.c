#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

const int dimension = 64;
struct timeval tv;

double timestamp()
{
        double t;
        gettimeofday(&tv, NULL);
        t = tv.tv_sec + (tv.tv_usec / 1000000.0);
        return t;
}

int main(int argc, char *argv[])
{
        int i, j, k;
        double *A, *B, *C, start, end;

        FILE *out_file = fopen("2.txt", "w"); // write only

        // test for files not existing.
        if (out_file == NULL)
        {
                printf("Error! Could not open file\n");
                exit(-1); // must include stdlib.h
        }

        A = (double *)malloc(dimension * dimension * sizeof(double));
        B = (double *)malloc(dimension * dimension * sizeof(double));
        C = (double *)malloc(dimension * dimension * sizeof(double));

        srand(292);

        for (i = 0; i < dimension; i++)
                for (j = 0; j < dimension; j++)
                {
                        A[dimension * i + j] = (rand() / (RAND_MAX + 1.0));
                        B[dimension * i + j] = (rand() / (RAND_MAX + 1.0));
                        C[dimension * i + j] = 0.0;
                }

        start = timestamp();
        // ikj form
        for (i = 0; i < dimension; i++)
                for (k = 0; k < dimension; k++)
                        for (j = 0; j < dimension; j++)
                        {
                                C[dimension * i + j] += A[dimension * i + k] * B[dimension * k + j];
                                printf("C[%d] = C[%d] + A[%d] * B[%d];\n", dimension * i + j, dimension * i + j, dimension * i + k, dimension * k + j);
                                // write to file
                                fprintf(out_file, "C[%d] = C[%d] + A[%d] * B[%d];\n", dimension * i + j, dimension * i + j, dimension * i + k, dimension * k + j);
                        }

        end = timestamp();
        printf("\nsecs:%f\n", end - start);
        free(A);
        free(B);
        free(C);

        return 0;
}
