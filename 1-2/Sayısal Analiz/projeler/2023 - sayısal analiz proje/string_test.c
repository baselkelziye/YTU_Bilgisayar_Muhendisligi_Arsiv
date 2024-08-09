#include <stdio.h>

const int MACRO = 6;

int main() {
  printf("Hello Admin Please Enter the  Items:\n");
  int i;
  char items[MACRO][20];

  for (i = 0; i < MACRO; ++i) {
    scanf("%s", items[i]);

  }

  for (i = 0; i < MACRO; ++i) {
    printf("%s ", items[i]);
  }

  return 0;
}
