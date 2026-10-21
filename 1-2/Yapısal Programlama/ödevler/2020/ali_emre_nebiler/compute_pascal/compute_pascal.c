#include <stdio.h>

// algorithm that prints Pascal's triangle up to the requested row count

void computePascal(int N) {
  int arr[N], temp1, temp2;
  int i, j;
  arr[0] = 1;

  for (i = 0; i < N; i++) {
    // print the row
    for (j = 0; j < i + 1; j++) {
      printf("%d ", arr[j]);
    }
    printf("\n");

    // calculate the next row
    temp1 = arr[0];
    temp2 = arr[1];
    for (j = 0; j < i; j++) {
      arr[j + 1] = temp1 + temp2;
      temp1 = temp2;
      temp2 = arr[j + 2];
    }
    arr[i + 1] = 1;
  }
}

int main() {
  int N;
  printf("\n - PASCAL TRIANGLE - \n");
  printf("\n Number of rows to compute = ");
  scanf("%d", &N);
  printf("\n");
  computePascal(N); // calculate and print Pascal's triangle
  return 0;
}
