/* Berke Ozgen 20011602 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int *a;
	int i;
	int h;
	int start, end, mid;

	printf("N:\n");
	scanf("%d", &n);

	a = (int *) malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("%d. makalenin atif sayisi:\n", i);
		scanf("%d", &a[i]);
	}
	
	h = 0;
	start = 0;
	end = n - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (a[mid] >= mid + 1) {
			start = mid + 1;
			h = start;
		} else {
			end = mid - 1;
		}
	}

	printf("h-index: %d\n", h);

	free(a);
	return 0;
}