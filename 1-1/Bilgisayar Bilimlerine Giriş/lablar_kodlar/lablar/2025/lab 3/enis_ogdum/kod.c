#include <stdio.h>

#define MAX_LENGTH 100

int main()
{
    int matrix[MAX_LENGTH][MAX_LENGTH];
    int array[MAX_LENGTH * MAX_LENGTH];
    int backup_array[MAX_LENGTH * MAX_LENGTH];

    int i, j;
    int n, m;
    int control;
    int k = 0;

    printf("Matris boyutlarini giriniz:\n");
    scanf("%d %d", &n, &m);

    printf("Matris elemanlarini giriniz:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);

            array[k] = matrix[i][j];
            k++;
        }
    }

    for (i = 0; i < n * m; i++)
    {
        backup_array[i] = 1;
    }

    for (j = 0; j < n * m - 1; j++)
    {
        if (backup_array[j] != 0)
        {
            control = array[j];

            for (i = j + 1; i < n * m; i++)
            {
                if (control == array[i])
                {
                    backup_array[j] = 0;
                    backup_array[i] = 0;
                }
            }
        }
    }

    printf("Sonuclar:\n");

    for (i = 0; i < n * m; i++)
    {
        if (backup_array[i] != 0)
        {
            printf("%d ", array[i]);
        }
    }

    return 0;
}


