#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Mert Guler */
/* Complex version for better explanation of the solution */

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

const char mainMenuText[] =
"\n***************************************\n"
"     ** Lock & Keys by Mert Guler **\n"
"     ** Custom Lomuto Technique **\n"
"***************************************\n"
"                MENU                 \n\n"
"   Any Key - Read Data From File\n"
"   Q - Quit\n\n"
"***************************************\n";

/*
@brief Clears screen with choosing right method for current operating system.
 
@return
*/
void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
@brief Swaps two integer pointers
 
@param a  The first pointer
@param b  The second pointer

@return
*/
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
@brief Prints given array in the range: [low, high)
 
@param arr  The array to be printed
@param low  The lower bound (inclusive)
@param high  The higher bound (exclusive)

@return
*/
void printArray(int arr[], int low, int high){
    int i;
    for (i = low; i < high; i++){
        printf("%d ", arr[i]);
    }
}

/*
@brief Prints array in the range: [low, high), and marks elements at indexes: 'a' and 'b'
 
@param arr  The array to be printed
@param low  Lower bound (inclusive)
@param high  Higher bound (exclusive)
@param a  The first index to be marked
@param b  The second index to be marked
 
@return
*/
void printSwaps(int arr[], int low, int high, int a, int b){
    int i;
    printf("\n");
    for (i = low; i < high; i++){
        if (i == a || i == b){
            printf(ORANGE "%d " RESET, arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

/*
@brief Loads data from a file with the specified filename and writes it to dynamic arrays
 
@param n  The size of the arrays and first row of the data
@param keys  The keys array and second row of the data
@param locks  The locks array and third row of the data
 
@return
*/
void loadData(int* n, int** keys, int** locks){
    char fileName[100];
    FILE *file = NULL;
    int validFile = 0;
    int i;
    
    printf("\nEnter the name of the file you want to load (with .txt)\nEnter Q to Quit: ");
    
    while (validFile == 0) {
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = 0;
        
        if (strcmp(fileName,"q") == 0 || strcmp(fileName,"Q") == 0){
            printf("\nExiting...\n");
            exit(1);
        }

        file = fopen(fileName, "r");
        
        if (file != NULL) {
            validFile = 1;
        } else {
            printf("\nFile could not be opened or found. Please try again: ");
        }
    }
    
    /* Write data, assuming data is perfectly fits the specified template */
    
    fscanf(file, "%d", n);
    
    /* Locate memory dynamicly */
    *keys = (int*)malloc(*n * sizeof(int));
    *locks = (int*)malloc(*n * sizeof(int));

    for (i = 0; i < *n; i++) {
        fscanf(file, " %d", &(*keys)[i]);
    }
    
    for (i = 0; i < *n; i++) {
        fscanf(file, " %d", &(*locks)[i]);
    }
    
    fclose(file);
    printf("Successfully Loaded File!\n\n");
}

/*
@brief Loads the main menu screen and proceeds with data loading
 
@param n  The size of the arrays
@param keys  The array contains the keys
@param locks  The array contains the locks
 
@return
*/
void mainMenu(int* n, int** keys, int** locks){
    char input[100];
    printf("%s", mainMenuText);
    
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    if (strcmp(input,"q") == 0 || strcmp(input,"Q") == 0){
        printf("\nExiting...\n");
        exit(1);
    } else {
        loadData(n, keys, locks);
    }
}

/*
@brief Checks if two arrays are equal and sorted correctly
 
@param keys  The array containing the keys
@param locks  The array containing the locks
@param n  The array size
 
@return
*/
void check(int* keys, int* locks, int n){
    int i = 0;
    int equal = 1;
    int keysSorted = 1;
    int locksSorted = 1;
    
    while (equal == 1 && i < n) {
        if (keys[i] != locks[i]){
            equal = 0;
        }
        i++;
    }
    
    if (equal == 1){
        printf("\n\n" GREEN "Equal!\n" RESET);
    } else {
        printf("\n\n" RED "Equality is failed for this data :(\n" RESET);
        return;
    }
    
    i = 0;
    while (keysSorted == 1 && locksSorted == 1 && i < n - 1) {
        if (keys[i] > keys[i + 1]){
            printf("\n" RED "Keys are not sorted correctly!" RESET);
            keysSorted = 0;
            return;
        }
        
        if (locks[i] > locks[i + 1]){
            printf("\n" RED "Locks are not sorted correctly!" RESET);
            locksSorted = 0;
            return;
        }
        i++;
    }
    
    if (locksSorted == 1 && keysSorted == 1){
        printf(GREEN "Sorted Correctly!" RESET);
    }
}

/*
@brief Selects and returns a random number from the array with range of: [low, high]
 
@param arr, the array to get a random element
@param low, lower index to be selected (included)
@param high, higher index to be selected (included)
 
@return Return a random number from the array
*/
int selectRandom(int arr[], int low, int high){
    int random;
    srand((unsigned int) time(NULL)); /* Seed the random number generator */
    random = low + rand() % (high + 1 - low); /* Select a index between low and high */
    return arr[random]; /* Return the element at the random index in the array */
}

/*
@brief Sorts and divides the array into two parts using a custom Lomuto partition, placing the pivot in the middle. Returns the final index of the pivot.
 
@param arr  The array to be sorted
@param low  Lower index of the array
@param high  Higher index of the array
@param pivot  The reference value for comparison
 
@return Return the final index of the pivot
*/
int divide(int arr[], int low, int high, int pivot){
    int i = low - 1; /* Left iterator */
    int j; /* Right iterator */
    
    for (j = low; j < high; j++) { /* Iterate through the array from arr[start] up to arr[high - 1] */
        if (arr[j] == pivot){ /* If a key & lock match is found */
            
            printSwaps(arr,low, high + 1, j, high);
            printf("- Swap Pivot with Highest: %d & %d", arr[j], arr[high]);
            
            swap(&arr[j], &arr[high]); /* Swap the highest index with the match index */
        }
        
        if (arr[j] < pivot) { /* If the current element is less than the pivot */
            i++; /* Increase left index */
            if (i != j){ /* Check for equality between left and right indices to avoid unnecessary swapping */
                
                printSwaps(arr,low, high + 1, i, j);
                printf("- Swap: %d & %d", arr[i], arr[j]);
                
                swap(&arr[i], &arr[j]); /* Swap the left and right elements */
            }
        }
    }

    /* i + 1 is the correct pivot index. The highest index and the pivot index must be swapped to ensure the correct index is returned */
    
    if (i + 1 != high){ /* Check if the pivot is equal to the highest index to avoid unnecessary swapping */
        
        printSwaps(arr,low, high + 1, i + 1, high);
        printf("- Pivot Swap: %d & %d", arr[i + 1], arr[high]);
        
        swap(&arr[i + 1], &arr[high]); /* Place the pivot at its correct index */
    }

    printf("\n"RED);
    printArray(arr, low, i + 1);
    printf(RESET "%d " GREEN, arr[i + 1]);
    printArray(arr, i + 2, high + 1);
    printf(RESET "\n");

    return i + 1; /* Return the pivot's final index in the divided array */
}

/*
@brief Sorts two arrays containing the same elements in random order using a custom Lomuto QuickSort implementation with recursion
 
@param keys  The array containing the keys
@param locks  The array containing the locks
@param low  The lowest index of the arrays
@param high  The highest index of the arrays
 
@return
*/
void reflectionSort(int* keys, int* locks, int low, int high){
    int key; /* The random key to search for in the locks */
    int pivotIndex; /* Pivot's final position in the divided array */
    int lock; /* The matching lock to search for in the keys */
    
    if (low >= high){ /* Check if the array is too small to be sorted */
        return;
    }
    
    key = selectRandom(keys, low, high); /* Select a random key */
    
    printf("\nSorting Locks - " YELLOW "Key" RESET ": %d\n", key);
    
    pivotIndex = divide(locks, low, high, key); /* Sort & Divide the locks and get the final pivot index */
    
    lock = locks[pivotIndex]; /* Get the matching lock from the locks using the final pivot index */
    
    printf("\nSorting Keys" " - " BLUE "Lock" RESET ": %d\n", lock);
    
    divide(keys, low, high, lock); /* Sort & Divide the keys with the matching lock */
    
    reflectionSort(keys, locks, low, pivotIndex - 1); /* Sort the array elements before the pivot */
    reflectionSort(keys, locks, pivotIndex + 1, high); /* Sort the array elements after the pivot */
}


/*
@brief Runs the program and frees memory at the finish
 
@return
*/
void run(void){
    int* keys;
    int* locks;
    int n; /* size of the arrays */

    mainMenu(&n, &keys, &locks); /* Data reading and memory allocation is included */
    
    clearScreen();
    printf(GREEN "Green" RESET " : Higher than pivot\n");
    printf(RED "Red" RESET " : Lower than pivot\n");
    printf(BLUE "Blue" RESET " : Locks\n");
    printf(YELLOW "Yellow" RESET " : Keys\n");
    printf(ORANGE "Orange" RESET " : Swaps\n");
    
    
    reflectionSort(locks, keys, 0, n - 1); /* the forth param must be 'last index'. Not size */
    
    
    printf("\nLock " RED "&" RESET " Keys!\n\nLocks:\n");
    printArray(keys, 0, n);
    printf("\n\nKeys:\n");
    printArray(locks, 0, n);
    
    check(keys, locks, n);
    
    free(keys);
    free(locks);
}

int main(int argc, char *argv[])
{
    char input[100];
    int restart = 1;
    
    while (restart == 1) {
        run();
        
        printf("\n\nAny Key - Go back to main menu\n");
        printf("Q - Quit\nInput: ");
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input,"q") == 0 || strcmp(input,"Q") == 0){
            restart = 0;
        }
        
        clearScreen();
    }
}
