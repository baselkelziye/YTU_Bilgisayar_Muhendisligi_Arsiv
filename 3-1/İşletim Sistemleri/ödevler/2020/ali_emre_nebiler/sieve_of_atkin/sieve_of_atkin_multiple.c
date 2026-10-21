#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define SIZE 30000

void sieveOfAtkin(int i, int limit[], bool sieve[SIZE]) {
  // n: value to test
  int x, y, n;

  // mark all numbers as non-prime at the beginning
  for (n = 2; n <= limit[i]; n++) {
    sieve[n] = false;
  }
  // case for limit = 2
  if (limit[i] >= 2) {
    sieve[2] = true;
  }
  // case for limit = 3
  if (limit[i] >= 3) {
    sieve[3] = true;
  }

  // test the conditions starting from x = 1 and y = 1
  for (x = 1; x * x < limit[i]; x++) {
    for (y = 1; y * y < limit[i]; y++) {

      // rule: 4*x*x + y*y mod 12
      n = 4 * x * x + y * y;
      if (n <= limit[i] && (n % 12 == 1 || n % 12 == 5)) {
        sieve[n] ^= true;
      }
      // rule: 3*x*x + y*y mod 12
      n = 3 * x * x + y * y;
      if (n <= limit[i] && n % 12 == 7) {
        sieve[n] ^= true;
      }
      // rule: 3*x*x - y*y mod 12
      n = 3 * x * x - y * y;
      if (x > y && n <= limit[i] && n % 12 == 11) {
        sieve[n] ^= true;
      }
    }
  }

  // eliminate multiples of squares of discovered primes
  for (n = 5; n * n < limit[i]; n++) {
    if (sieve[n] == true) {
      for (x = n * n; x < limit[i]; x = x + n * n) {
        sieve[x] = false;
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
  printf("\n\nSieve of Atkin");
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
    sieveOfAtkin(i, limit, sieve);

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
