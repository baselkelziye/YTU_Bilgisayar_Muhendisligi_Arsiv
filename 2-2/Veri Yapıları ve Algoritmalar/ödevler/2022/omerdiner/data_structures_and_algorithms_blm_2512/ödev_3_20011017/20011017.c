#include <stdio.h>
#include <stdlib.h>
/*
@brief checks if the given array is empty or not
@param arr: array to be checked, n: size of the array
@return 1 if the array is empty, 0 otherwise
*/
int check_if_empty(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            return 0;
        }
    }
    return 1;
}
/*
@brief prints the given matrix
@param arr: matrix to be printed, n: number of rows, m: number of columns
*/
void print_matrix(int **arr, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
/*
@brief creates a max heap tree from the given array starting from the given index
@param arr: array to be converted to max heap tree, n: size of the array, i: index of the root node
*/
void max_heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, n, largest);
    }
}
/*
@brief makes all subtree of the given array max heap tree
@param arr: array to be converted to max heap tree, n: size of the array
*/
void make_array_max_heap_tree(int *arr, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}

/*
@brief main function where the program starts
*/
int main()
{

    int n; // number of rows
    int i, j;

    int *order_of_extinction = (int *)malloc(n * sizeof(int)); // final output array
    int order_of_extinction_index = 0;                         // index of the final output array

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // takes the number of columns for each row and finds the maximum number of columns
    int max = 0;
    int *size_of_rows = (int *)malloc(n * sizeof(int));
    int total_size = 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter the number of columns in row %d: ", i);
        scanf("%d", &size_of_rows[i]);
        total_size += size_of_rows[i];
        if (size_of_rows[i] > max)
        {
            max = size_of_rows[i];
        }
    }

    // creating a 2d array with n rows and max columns
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(max * sizeof(int));
    }

    // initializing the matrix with -1
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < max; j++)
        {
            arr[i][j] = -1;
        }
    }

    // creating an array with n*max elements and randomizing it
    int *random_numbers = (int *)malloc(n * max * sizeof(int));
    for (i = 0; i < n * max; i++)
    {
        random_numbers[i] = i;
    }

    for (i = 0; i < n * max; i++)
    {
        int random_index = rand() % (n * max);
        int temp = random_numbers[i];
        random_numbers[i] = random_numbers[random_index];
        random_numbers[random_index] = temp;
    }

    // filling the matrix with the randomized numbers
    int random_index = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < size_of_rows[i]; j++)
        {
            arr[i][j] = random_numbers[random_index];
            random_index++;
        }
    }

    print_matrix(arr, n, max);

    // converting each row to max heap tree
    for (i = 0; i < n; i++)
    {
        make_array_max_heap_tree(arr[i], max);
    }

    printf("\n\nNew matrix after converting each row to max heap tree: \n\n");
    print_matrix(arr, n, max);

    // taking the maximum element of each row of the matrix and finding the maximum of them. remove it from the matrix and put -1 instead of it. this process will be done total_size times.
    while (total_size > 0)
    {
        int tmp = -1;
        int max_row = -1;
        int max_col = -1;
        printf("Checked values: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i][0]);
            {
                if (arr[i][0] > tmp)
                {
                    tmp = arr[i][0];
                    max_row = i;
                }
            }
        }
        printf("\nChosen max value: %d\n", tmp);
        tmp = -1;
        arr[max_row][0] = -1;
        // if the row is full of -1's, add it to the order_of_extinction array
        if (check_if_empty(arr[max_row], max) == 1)
        {
            order_of_extinction[order_of_extinction_index] = max_row;
            order_of_extinction_index++;
        }
        total_size--;

        // reorder the max heap tree of the row
        make_array_max_heap_tree(arr[max_row], max);

        printf("\n\nNew matrix after removing the maximum element: \n\n");
        print_matrix(arr, n, max);
    }

    // printing the order of extinction, index+1 is printed because the indexes start from 0
    printf("\n\nOrder of extinction (index+1): \n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", order_of_extinction[i] + 1);
    }
    
     // freeing the allocated memory
    free(order_of_extinction);
    free(size_of_rows);
    free(random_numbers);
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
