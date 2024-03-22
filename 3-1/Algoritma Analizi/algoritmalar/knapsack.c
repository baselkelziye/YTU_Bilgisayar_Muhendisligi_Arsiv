#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int knapsack(int capacity, int n, int* weights, int* values) {
  int i, w;
  int** dp = malloc((n + 1) * sizeof(int*));
  for (i = 0; i <= n; i++) {
    dp[i] = malloc((capacity + 1) * sizeof(int));
  }

  for (i = 0; i <= n; i++) {
    for (w = 0; w <= capacity; w++) {
      if (i == 0 || w == 0) {
        dp[i][w] = 0;
      } else if (weights[i - 1] <= w) {
        dp[i][w] = MAX(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  int result = dp[n][capacity];

  for (i = 0; i <= n; i++) {
    free(dp[i]);
  }
  free(dp);

  return result;
}

int main(int argc, char** argv) {
  int capacity;
  int n, i;
  int *weights;
  int *values;
  printf("Enter The Capacity Of Bag: "); scanf("%d", &capacity);
  printf("Enter The Number Of Items: "); scanf("%d", &n);
  weights = (int*) malloc(n * sizeof(int));
  values = (int*) malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
  	printf("Enter %d.Item's Weight: ", i + 1); scanf("%d", &weights[i]);
  	printf("Enter The %d.Item's Value: ", i + 1); scanf("%d", &values[i]);
  }
  
  

  int result = knapsack(capacity, n, weights, values);
  printf("Result: %d\n", result);

  return 0;
}
