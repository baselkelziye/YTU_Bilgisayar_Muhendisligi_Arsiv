#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
@brief :  sorts an array using insertion sort algorithm. this will be used when number of elements in the array is less than k.
@param : arr: array to be sorted
@param : left: starting index of the array
@param : right: ending index of the array
@return : void
*/
void insertionSort(int arr[], int left, int right)
{

    int i, j, tmp;
    for (i = left + 1; i <= right; i++)
    {
        tmp = arr[i];
        j = i - 1;
        while (j >= left && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = tmp;
    }
}

/*
@brief :  function that finds the smallest element of k subarrays
@param : arr: array to be sorted
@param : indices: array of current indices of the subarrays
@param : ends: array of ending indices of the subarrays
@param : k: number of subarrays
@param : minIndex: index of the subarray that contains the smallest element
@return : minimum value of the subarrays
*/
int findMin(int arr[], int indices[], int ends[], int k, int *minIndex)
{
    int i;
    int min = INT_MAX; // initializing min value with the maximum int value so that the first element will be smaller

    *minIndex = -1;

    for (i = 0; i < k; i++)
    {
        if (indices[i] <= ends[i] && arr[indices[i]] < min)
        {
            min = arr[indices[i]];
            *minIndex = i;
        }
    }
    return min;
}

/*
@brief :  merges k sorted subarrays into a single sorted array
@param : arr: array to be sorted
@param : left: starting index of the array
@param : right: ending index of the array
@param : k: number of subarrays
*/
void merge(int arr[], int left, int right, int k)
{
    int total_elements = right - left + 1;
    if (total_elements <= 1)
        return;

    int i;
    int segment_size = (total_elements + k - 1) / k;
    int *tmp = (int *)malloc(total_elements * sizeof(int)); // temporary array to store the combined array
    int *indices = (int *)malloc(k * sizeof(int));          // array to store the current index of each subarray
    int *ends = (int *)malloc(k * sizeof(int));             // array to store the ending index of each subarray
    int tmp_index = 0;
    int actual_k = (total_elements + segment_size - 1) / segment_size;
    int minIndex; // index of the subarray that contains the smallest element

    if (actual_k > k)
    {
        actual_k = k;
    }

    // calculating the starting and ending indices of each subarray
    for (i = 0; i < actual_k; i++)
    {
        indices[i] = left + i * segment_size;
        if (i == actual_k - 1)
        {
            ends[i] = right;
        }

        else
        {
            ends[i] = left + (i + 1) * segment_size - 1;
        }

        if (ends[i] > right)
        {
            ends[i] = right;
        }
    }

    // the main loop that merges the subarrays.
    // it finds the smallest element of the subarrays and adds it to the temporary array
    // then increments the index of the subarray that contains the smallest element
    while (tmp_index < total_elements)
    {
        int min = findMin(arr, indices, ends, actual_k, &minIndex);
        // if there is no element to add,
        // it means that all elements are added to the temporary array
        if (minIndex == -1)
            break;

        // adding the smallest element to the temporary array and increment the index of the subarray
        tmp[tmp_index++] = min;
        indices[minIndex]++;
    }

    for (i = 0; i < total_elements; i++)
    {
        arr[left + i] = tmp[i];
    }

    free(tmp);
    free(indices);
    free(ends);
}

/*
@brief :  sorts an array using k-way merge sort algorithm
@param : arr: array to be sorted
@param : left: starting index of the array
@param : right: ending index of the array
@param : k: number of subarrays
@return : void
*/
void kWayMergeSort(int arr[], int left, int right, int k)
{
    int i;

    // stopping condition for the recursive function
    if (left >= right)
        return;

    int total_elements = right - left + 1;

    // if the number of elements is less than or equal to k, we use insertion sort
    if (total_elements <= k)
    {
        insertionSort(arr, left, right);
        return;
    }

    // calculating the size of each subarray
    int segment_size = (total_elements + k - 1) / k;
    int actual_k = (total_elements + segment_size - 1) / segment_size;

    if (actual_k > k)
        actual_k = k;

    // finding the starting and ending indices of each subarray and recursively sorting them
    for (i = 0; i < actual_k; i++)
    {
        int subarr_left = left + i * segment_size;
        int subarr_right;

        if (i == actual_k - 1)
            subarr_right = right;
        else
            subarr_right = left + (i + 1) * segment_size - 1;

        if (subarr_right > right)
            subarr_right = right;

        // recursively sorting each subarray
        kWayMergeSort(arr, subarr_left, subarr_right, k);
    }

    // merging the sorted subarrays
    merge(arr, left, right, k);
}

/*
@brief :  generates a random array of unique numbers from 1 to n
@param : n: size of the array
@return : randomly generated array with unique numbers. maximum number is n
*/
int *generateRandomArray(int n)
{
    int i;
    int *arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    // shuffling the array to make it random
    for (i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return arr;
}

/*
@brief: writes the test results to a file
@param: n: size of the array
@param: k: number of subarrays
@param: time_taken: time taken to sort the array
@return: void
*/
void writeResultsToFile(int n, int k, double time_taken)
{
    FILE *fp = NULL;
    // opening the file in append mode. if the file does not exist, it will be created.
    fp = fopen("kwayresults.txt", "a");

    if (fp == NULL)
    {
        printf("Error.\n");
        return;
    }

    fprintf(fp, "%d,%d,%.5f,%.5f\n", n, k, time_taken, time_taken / 1000);

    fclose(fp);
}

/*
@brief: runs the test for a given array and k value
@param: arr: array to be sorted
@param: n: size of the array
@param: k: number of subarrays
@return: void
*/
void testKWayMergeSort(int *arr, int n, int k)
{
    int *arr_copy = malloc(n * sizeof(int));
    if (!arr_copy)
    {
        printf("Error.\n");
        return;
    }

    // Copying the original array to avoid modifying it during sorting
    memcpy(arr_copy, arr, n * sizeof(int));

    // starting the timer to measure the running time
    clock_t start = clock();
    kWayMergeSort(arr_copy, 0, n - 1, k);
    // stopping the timer
    clock_t end = clock();

    double running_time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

    // writing the results to the file after the test is completed
    writeResultsToFile(n, k, running_time);

    free(arr_copy);
}

// main function
// runs the tests for different array sizes and k values
// writes the results to a file

int main()
{
    srand(time(NULL));
    int i, k;
    // different array sizes to test
    int test_sizes[] = {100, 10000, 100000, 1000000, 10000000};
    int num_of_test_sizes = 5;

    for (i = 0; i < num_of_test_sizes; i++)
    {
        int n = test_sizes[i];
        // Generating a single array to use for all k values
        int *arr = generateRandomArray(n);

        // k values from 2 to 10
        for (k = 2; k <= 10; k++)
        {
            testKWayMergeSort(arr, n, k);
        }

        free(arr); // Freeing the array after all k values are tested
    }

    printf("Completed.\n");

    return 0;
}
