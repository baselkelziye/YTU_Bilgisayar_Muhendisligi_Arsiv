#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define SIZE 30000

void sieveOfEratosthenes(int i, int limit[], bool sieve[SIZE]) {
  int n, m;

  // mark all numbers as prime at the beginning
  for (n = 2; n <= limit[i]; n++) {
    sieve[n] = true;
  }

  // mark multiples of prime numbers as non-prime
  for (n = 2; n * n < limit[i]; n++) {
    if (sieve[n] == true) {
      for (m = n * n; m < limit[i]; m = m + n) {
        sieve[m] = false;
      }
    }
  }
}

void printPrimes(int i, int limit[], bool sieve[SIZE]) {
  int x = 0, n;
  printf("\n\nLimit = %d", limit[i]);
  printf("\nPrime Numbers:\n");
  for (n = 2; n < limit[i]; n++) {
    if (sieve[n] == true) {
      x = x + 1;
      printf("%d\t", n);
      if (x == 8) {
        printf("\n");
        x = 0;
      }
    }
  }
}

int main() {
  // limit[]: upper bounds of the intervals to search
  // sieve[]: array used to mark values as prime or non-prime
  // sieve[n] = true (prime)
  // sieve[n] = false (non-prime)
  int limit[8], i, j, max;
  bool sieve[SIZE];
  double duration[8];         // elapsed times
  struct timespec start, end; // start and end times

  // input positive integer limit values
  printf("-----");
  printf("\n\nSieve of Eratosthenes");
  printf("\n\nFind all prime numbers in the range starting from 2.");
  printf("\n\n-----");
  printf("\n\nUpper Limits of the Ranges\n");
  for (i = 0; i < 8; i++) {
    printf("Limit %d: ", i + 1);
    scanf("%d", &limit[i]);
    while (limit[i] <= 1) {
      printf("(!) The limit value must be a positive integer greater than 1.");
      printf("\nPlease enter a valid limit value: ");
      scanf("%d", &limit[i]);
    }
  }

  for (i = 0; i < 8; i++) {
    // record the start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // find prime numbers
    sieveOfEratosthenes(i, limit, sieve);

    // record the end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // print the prime numbers
    printPrimes(i, limit, sieve);

    // calculate the elapsed time
    duration[i] = (end.tv_sec - start.tv_sec) * 1e9;
    duration[i] = (duration[i] + (end.tv_nsec - start.tv_nsec)) * 1e-9;
  }

  // print the computation times
  printf("\n\n------------------");
  printf("\nComputation Times");
  printf("\n\nUpper Limit:\tTime:");
  printf("\n----------\t--------");
  for (i = 0; i < 8; i++) {
    printf("\n%10d\t%f sec", limit[i], duration[i]);
  }

  // print the bar chart
  printf("\n\nBar Chart");
  printf("\n--------------------------------------------------------> Time");
  for (i = 0; i < 8; i++) {
    printf("\n       | \n %5d | ", limit[i]);
    max = duration[i] * 200000;
    for (j = 0; j < max; j++) {
      printf("o");
    }
  }
  printf("\n       | \n       | \n       V");
  printf("\n       Inputs");
}
