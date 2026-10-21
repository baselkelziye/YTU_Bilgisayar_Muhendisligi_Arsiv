#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "data.txt"

/**
 * Struct to hold the inputs read from file
 */
struct Data {
    int n;
    int* keys;
    int* locks;
};

void print(int[], int, int);
void swap(int*, int*);
int partition(int[], int, int, int);
void quicksort(int[], int[], int, int);
struct Data *readInput(char[]);

int main() {
    srand(time(NULL));
    
    struct Data *data = readInput(FILE_NAME);

    fputs("Unsorted keys: ", stdout);
    print(data->keys, 0, data->n-1);
   
    fputs("Unsorted locks: ", stdout);
    print(data->locks, 0, data->n-1);

    quicksort(data->keys, data->locks, 0, data->n-1);

    fputc('\n', stdout);

    fputs("Sorted keys: ", stdout);
    print(data->keys, 0, data->n-1);

    fputs("Sorted locks: ", stdout);
    print(data->locks, 0, data->n-1);
    
    return 0;
}

/**
 * @brief Simple swap function used to swap array elements.
 *
 * @param a: An integer pointer to be swapped.
 * @param b: Another integer pointer to be swapped.
 */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Simple function to print elements of an array in the given range.
 *
 * @param begin: An integer value that marks the beginning index of printing range.
 * @param end: An integer value that marks the ending index of printing range, `end` inclusive.
 */
void print(int arr[], int begin, int end) {
    int i = begin;
    for (; i < end + 1; ++i) {
        printf("%d ", arr[i]);
    }
    fputc('\n', stdout);
}

/**
 * @brief Partitions an array with given `pivot` value.
 *
 * Rearranges the given array so that all the elements to the left of the given pivot value
 * are smaller and all the elements to the right of said value are greater. Finally places
 * the pivot value in the middle as possible.
 *
 * @param arr: Integer array to be partitioned.
 * @param left: An integer to mark beginning of partitioning range.
 * @param right: An integer to mark ending of partitioning range.
 * @param pivot: An element of array to be used as the pivot value.
 *
 * @return Final index of pivot value residing in the array.
 */
int partition(int arr[], int left, int right, int pivot) {
    int i = left;
    int j = left;
    for (; j < right; ++j) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            ++i;
        } else if (arr[j] == pivot) {
            swap(&arr[j], &arr[right]);
            --j;
        }
    }
    swap(&arr[i], &arr[right]);                                     /**< Place pivot index in the middle, */ 
                                                                    /**< left partition is smaller, right partition is larger */
    return i;                                                       
}

/**
 * @brief Modified quicksort algorithm to sort two arrays with equivalent elements at the same
 * time using the same pivot value.
 * 
 * While left index is smaller than right, a random pivot index is generated from the given partition
 * in range `[left, right]`. That pivot index is moved to the end of `locks` array as to make swap managing
 * easier. First the `keys` array is partitioned using the element at generated pivot index, then the
 * `locks` array is partitioned using the same element. In the end, every element of both arrays are matching
 * and both arrays are sorted.
 * 
 * @param keys: Given keys to be sorted
 * @param locks: Given locks to be sorted
 * @param left: Leftmost index of the given array partition
 * @param right: Rightmost index of the given array partition
 */
void quicksort(int keys[], int locks[], int left, int right) {
    if (right <= left) { return; }                                  /**< Base case: left should be smaller than right */

    int pivotIdx = rand() % (right - left + 1) + left;

    swap(&keys[pivotIdx], &keys[right]);                            /**< Swap the pivot with rightmost element so that managing swaps are easier */

    int pivot = partition(locks, left, right, keys[right]);         /**< Get the corresponding element to that random index */
                                                                    /**< Partition the locks array using chosen random key */ 

    printf("\nRandom pivot: %d\n", keys[right]);

    partition(keys, left, right, locks[pivot]);                     /**< Partition the keys array using the chosen random key */


    fputs("Keys partitioned around random pivot: ", stdout);
    print(keys, left, right);
    fputs("Locks partitioned around random pivot: ", stdout);
    print(locks, left, right);

    quicksort(keys, locks, left, pivot-1);                          
    quicksort(keys, locks, pivot+1, right);
}

/**
 * @brief Reads the file with and writes the contents to a struct `Data`
 *
 * @param fileName: Name of file to be read.
 *
 * @return Pointer to a populated struct `Data` with read values.
 */
struct Data *readInput(char fileName[]) {
    FILE *file;
    fopen_s(&file, fileName, "r");

    struct Data *data = calloc(1, sizeof(*data));
    
    fscanf(file, "%d", &data->n);

    data->keys = calloc(data->n, sizeof(*data->keys));
    data->locks = calloc(data->n, sizeof(*data->locks));

    int i;
    for (i = 0; i < data->n; ++i) {
        fscanf(file, "%d", &data->keys[i]);
    }
    for (i = 0; i< data->n; ++i) {
        fscanf(file, "%d", &data->locks[i]);
    }

    fclose(file);

    return data;
}
