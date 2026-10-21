#include <stdio.h>

void compare(int a, int mins[], int maxs[]);

int main() {
    
    int n, a, i, mins[3] = {100, 100, 100}, maxs[3] = {0};
    
    do {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
    } while (n < 6);    
    
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a);    
        compare(a, mins, maxs);
    }
    
    printf("Sum of the largest 3 elements: %d\n", maxs[0] + maxs[1] + maxs[2]);
    printf("The largest 3 elements: %d, %d, %d\n", maxs[0], maxs[1] ,maxs[2]);
    printf("Sum of the smallest 3 elements: %d\n", mins[0] + mins[1] + mins[2]);
    printf("The smallest 3 elements: %d, %d, %d\n", mins[0], mins[1], mins[2]);
    
    return 0;
}

void compare(int a, int mins[], int maxs[]) {
    if (a > maxs[0]) {
        maxs[2] = maxs[1];
        maxs[1] = maxs[0];
        maxs[0] = a;
    }
    else if (a > maxs[1]) {
        maxs[2] = maxs[1];
        maxs[1] = a;
    }
    else if (a > maxs[2]) {
        maxs[2] = a;
    }
    if (a < mins[0]) {
        mins[2] = mins[1];
        mins[1] = mins[0];
        mins[0] = a;
    }
    else if (a < mins[1]) {
        mins[2] = mins[1];
        mins[1] = a;
    }
    else if (a < mins[2]) {
        mins[2] = a;
    }
}


