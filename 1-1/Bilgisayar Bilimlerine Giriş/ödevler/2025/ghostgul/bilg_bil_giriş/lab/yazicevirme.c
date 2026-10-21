#include <stdio.h>

int main() {
  int i, j, n, m;
  scanf("%d%d", &n, &m);
  int matrix[n][m];

  // Matrisi oku
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

  // Matrisi 180 derece dondur
  int rotated[m][n];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      rotated[i][j] = matrix[n - 1 - j][i];
    }
  }

  // Dondurulmus matrisi yaz
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", rotated[i][j]);
    }
    printf("\n");
  }

  return 0;
}
