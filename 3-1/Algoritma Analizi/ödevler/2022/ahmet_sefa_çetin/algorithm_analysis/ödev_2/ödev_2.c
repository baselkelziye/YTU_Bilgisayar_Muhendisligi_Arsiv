#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *array, int left, int right, int k);
void merge(int array[], int left, int right, int k);
void insertionSort(int *array, int left, int right);
int* createRandomArray(int n);

int main() {

    srand(time(NULL));

    int i, j, k, n, x;
    int nValues[] = {100, 1000, 10000, 100000, 1000000, 10000000};
    int *array, *arrayCopy;
    double totalTime, averageTime;

    FILE *file = fopen("results.txt", "w");

    for (i = 0; i < 6; i++) { // for 6 n values
        n = nValues[i];

        array = createRandomArray(n); 

        for (k = 2; k <= 10; k++) { // for each k for same array
            totalTime = 0.0;

            for (j = 0; j < 10; j++) { // ten times
                arrayCopy = (int*)malloc(n * sizeof(int));
                for (x = 0; x < n; x++) { // copying the array to not lose the original array for other merge sorts
                    arrayCopy[x] = array[x];
                }

                clock_t start = clock();
                mergeSort(arrayCopy, 0, n - 1, k);
                clock_t end = clock();

                totalTime += (double)(end - start) / (CLOCKS_PER_SEC / 1000); 

                free(arrayCopy);
            }

            averageTime = totalTime / 10.0;
            printf("n = %d K = %d avarage time = %.8f\n", n, k, averageTime);
            fprintf(file, "%d %d %.8f\n", n, k, averageTime);
        }

        free(array);
    }

    fclose(file);

    return 0;
}

/*
@brief implements the k way merge sort for an array and k parameter

@param array array which we want to sort.
@param left left index of the current segment of array.
@param right right index of the current segment of array.
@param k number of segments that will be merged.

@return 
*/
void mergeSort(int *array, int left, int right, int k) {

    if (right - left + 1 <= k) { // base case, if k >= length of array
        insertionSort(array, left, right);
        return;
    }

    int i;
    int t = (right - left + 1) / k;
    int h = left;

    for (i = 0; i < k - 1; i++) { // sorts each segment recursively
        mergeSort(array, h, h + t - 1, k);
        h += t;
    }
    mergeSort(array, h, right, k);

    merge(array, left, right, k);

}

/*
@brief merges k sorted array and makes it one sorted array

@param array array which we want to sort.
@param left left index of the current segment of array.
@param right right index of the current segment of array.
@param k number of segments that will be merged.

@return
*/
void merge(int *array, int left, int right, int k) {

    int i, j;
    int minValue, minIndex;
    int x;

    int lengthOfAnArray = (right - left + 1) / k;
    int maxLengthOfAnArray = (right - left + 1) - (lengthOfAnArray * (k - 1)); 

    int* starts = (int*)malloc(k * sizeof(int));
    int* ends = (int*)malloc(k * sizeof(int));
    
    for (i = 0; i < k - 1; i++) { // saves left and right indexes of each segment of array
        starts[i] = left + i * lengthOfAnArray;
        ends[i] = starts[i] + lengthOfAnArray - 1;
    }
    starts[k - 1] = left + (k - 1) * lengthOfAnArray;
    ends[k - 1] = right;

    x = left;
    while (x <= right) { // searching linearly the smallest element of first indexes of segments in each iteration linealy
        minValue = 100000000;
        minIndex = -1;
        
        for (i = 0; i < k; i++) { // finding the smallest elements from first elements of k arrays
            if (starts[i] <= ends[i] && array[starts[i]] < minValue) {
                minValue = array[starts[i]];
                minIndex = i;
            }
        }

        array[x] = minValue;
        x++;
        starts[minIndex]++;
    }

    free(starts);
    free(ends);

}

/*
@brief implements insertion sort and sorts a segment of an array.

@param array array which we want to sort.
@param left left index of the current segment of array.
@param right right index of the current segment of array.

@return
*/
void insertionSort(int *array, int left, int right) {
    int i, j, key;

    for (i = left + 1; i <= right; i++) {
        key = array[i];
        j = i - 1;

        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

/*
@brief creates a random unique array by shuffling array

@param n the length of random array.

@return returns the random array
*/
int* createRandomArray(int n) {

    int i, j, temp;
    int* array = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) { // fills the array
        array[i] = i + 1;
    }

    for (i = n - 1; i > 0; i--) { // shuffles the array
        j = rand() % (i + 1);
        
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return array;
}