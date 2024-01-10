/* Berke Ozgen 20011602 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int **a;
	int i, j;
	int **adj;
	int start1, end1;
	int start2, end2;
	int menu;
	int found;

	printf("N:\n");
	scanf("%d", &n);

	a = (int **) malloc(n * sizeof(int *));
	for (i = 0; i < n; i++) {
		a[i] = (int *) malloc(2 * sizeof(int));
	}

	for (i = 0; i < n; i++) {
		printf("%d. dersin baslangic saati:\n", i);
		scanf("%d", &a[i][0]);
		printf("%d. dersin suresi:\n", i);
		scanf("%d", &a[i][1]);
	}

	adj = (int **) malloc(n * sizeof(int *));
	for (i = 0; i < n; i++) {
		adj[i] = (int *) calloc(n, sizeof(int));
	}

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (i != j) {
				start1 = a[i][0];
				end1 = start1 + a[i][1];
				start2 = a[j][0];
				end2 = start2 + a[j][1];
				if ((start1 >= start2 && start1 < end2)
				 || (start2 >= start1 && start2 < end1)) {
					adj[i][j] = 1;
					adj[j][i] = 1;
				}
			}
		}
	}

	printf("Komsuluk matrisi:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}

	menu = 0;
	while (menu != -1) {
		printf("Cikis: -1\nCakisma sorgula:\n");
		scanf("%d", &menu);
		if (menu >= 0 && menu < n) {
			printf("\n");
			found = 0;
			for (i = 0; i < n; i++) {
				if (adj[menu][i]) {
					found = 1;
					printf("%d numarali ders ile cakisiyor.\n", i);
				}
			}
			if (!found) {
				printf("Cakisan ders bulunamadi.\n");
			}
			printf("\n");
		}
	}

	for (i = 0; i < n; i++) {
		free(a[i]);
		free(adj[i]);
	}
	free(a);
	free(adj);

	return 0;
}