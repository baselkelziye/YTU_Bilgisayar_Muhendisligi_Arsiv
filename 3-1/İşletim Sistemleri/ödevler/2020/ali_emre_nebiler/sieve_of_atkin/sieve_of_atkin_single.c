#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define SIZE 30000

void sieveOfAtkin(int limit, bool sieve[SIZE]) {
  // n: value to test
  int x, y, n;

  // mark all numbers as non-prime at the beginning
  for (n = 2; n <= limit; n++) {
    sieve[n] = false;
  }
  // case for limit = 2
  if (limit >= 2) {
    sieve[2] = true;
  }
  // case for limit = 3
  if (limit >= 3) {
    sieve[3] = true;
  }

  // test the conditions starting from x = 1 and y = 1
  for (x = 1; x * x < limit; x++) {
    for (y = 1; y * y < limit; y++) {

      // rule: 4*x*x + y*y mod 12
      n = 4 * x * x + y * y;
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
        sieve[n] ^= true;
      }
      // rule: 3*x*x + y*y mod 12
      n = 3 * x * x + y * y;
      if (n <= limit && n % 12 == 7) {
        sieve[n] ^= true;
      }
      // rule: 3*x*x - y*y mod 12
      n = 3 * x * x - y * y;
      if (x > y && n <= limit && n % 12 == 11) {
        sieve[n] ^= true;
      }
    }
  }

  // eliminate multiples of squares of discovered primes
  for (n = 5; n * n < limit; n++) {
    if (sieve[n] == true) {
      for (x = n * n; x < limit; x = x + n * n) {
        sieve[x] = false;
      }
    }
  }
}

void printPrimes(int limit, bool sieve[SIZE]) {
  int x = 0, n;
  printf("\nPrime Numbers:\n");
  for (n = 2; n < limit; n++) {
    // print 8 prime numbers per line
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
  // limit: upper bound of the interval to search
  // sieve[]: array used to mark values as prime or non-prime
  // sieve[n] = true (prime)
  // sieve[n] = false (non-prime)
  int limit;
  bool sieve[SIZE];
  double duration;            // elapsed time
  struct timespec start, end; // start and end times

  // input a positive integer limit value
  printf("-----");
  printf("\n\nSieve of Atkin");
  printf("\n\nFind all prime numbers in the range starting from 2.");
  printf("\n\n-----");
  printf("\n\nUpper Limit of the Range: ");
  scanf("%d", &limit);
  while (limit <= 1) {
    printf("(!) The limit value must be a positive integer greater than 1.");
    printf("\nPlease enter a valid limit value: ");
    scanf("%d", &limit);
  }

  // record the start time
  clock_gettime(CLOCK_MONOTONIC, &start);

  // find prime numbers
  sieveOfAtkin(limit, sieve);

  // record the end time
  clock_gettime(CLOCK_MONOTONIC, &end);

  // print the prime numbers
  printPrimes(limit, sieve);

  // calculate the elapsed time
  duration = (end.tv_sec - start.tv_sec) * 1e9;
  duration = (duration + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  // print the computation time
  printf("\n\nComputation Time: %f sec", duration);
}
