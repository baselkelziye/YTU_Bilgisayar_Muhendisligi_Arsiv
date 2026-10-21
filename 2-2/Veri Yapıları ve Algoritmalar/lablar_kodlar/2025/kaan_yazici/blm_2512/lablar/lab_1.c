#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;
  fputs("Enter dimensions:\n", stdout);
  scanf(" %d %d", &n, &m);
  int** matrix = calloc(n, sizeof(*matrix));
  int i, j;
  for (i = 0; i < n; ++i) {
    matrix[i] = calloc(m, sizeof(**matrix));
  }
  fputs("Enter data:\n", stdout);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      int num;
      scanf("%d", &num);
      matrix[i][j] = num;
    }
  }

  int non_zero = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (matrix[i][j] != 0) { ++non_zero; }
    }
  }

  int** n_mat = calloc(non_zero, sizeof(*n_mat));
  for (i = 0; i < non_zero; ++i) {
    n_mat[i] = calloc(3, sizeof(**n_mat));
  }

  int search, search_x, search_y;
  fputs("\nSearch elem:\n", stdout);
  scanf("%d %d", &search_x, &search_y);

  size_t idx = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (i == search_x && j == search_y) {
        search = matrix[i][j];
      }
      if (matrix[i][j] != 0) {
        n_mat[idx][0] = i;
        n_mat[idx][1] = j;
        n_mat[idx][2] = matrix[i][j];
        ++idx;
      }
    }
  }

  fputs("\nNew matrix:\n", stdout);
  for (i = 0; i < non_zero; ++i) {
    for (j = 0; j < 3; ++j) {
      printf("%d ", n_mat[i][j]);
    }
    fputc('\n', stdout);
  }

  int found = 0;

  for (i = 0; i < non_zero; ++i) {
    if (n_mat[i][0] == search_x && n_mat[i][1] == search_y) {
      printf("\nSearched elem: %d", n_mat[i][2]);
      found = 1;
    }
  }

  if (!found) { printf("\nNot found"); }

  return 0;
}
