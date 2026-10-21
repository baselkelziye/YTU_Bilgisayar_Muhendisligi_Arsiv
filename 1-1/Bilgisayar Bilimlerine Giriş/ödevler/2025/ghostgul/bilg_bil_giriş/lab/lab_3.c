#include <stdio.h>

int main()
{	
	int N = 0, M = 0, K = 0;
    int i, j, k , l;
	printf("Enter rows and columns of image: ");
	scanf("%d %d", &M, &N);
	int image[M][N];
    printf("Enter the image matrix (%dx%d):\n", M, N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            scanf("%d", &image[i][j]);
    }
	
	printf("Enter the filter matrix row-column count (KxK): ");
	scanf("%d", &K);
	int filter[K][K];
    printf("Enter the filter matrix (%dx%d):\n", K, K);
    
	for (i = 0; i < K; i++)
    {
        for (j = 0; j < K; j++)
            scanf("%d", &filter[i][j]);
    }
	
    int convolved[M-K+1][N-K+1];
	
    for (i = 0; i <= M-K; i++)
    {
        for (j = 0; j <= N-K; j++)
        {
            int sum = 0;
            int fsum = 0;
            for (k = 0; k < K; k++)
            {
                for (l = 0; l < K; l++)
                {
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < M && y >= 0 && y < N)
                    {
                        sum += image[x][y] * filter[k][l];
                        fsum += filter[k][l];
                    }
                }
            }
            convolved[i][j] = sum/fsum;
        }
    }

    printf("Convolved image:\n");
    for (i = 0; i <= M-K; i++)
    {
        for (j = 0; j <= N-K; j++)
            printf("%d ", convolved[i][j]);
        printf("\n");
    }

    return 0;
}
