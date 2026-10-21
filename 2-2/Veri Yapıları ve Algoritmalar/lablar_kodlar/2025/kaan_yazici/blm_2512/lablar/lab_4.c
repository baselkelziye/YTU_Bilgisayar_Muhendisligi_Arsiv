#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Given a binary search tree represented as an array, find maximum element, its level, and its
 * cousin node values.
 */

void findMax(int tree[], size_t N) {
  /* Initial condition, max elem is root. */
  int max = tree[0];
  int idx_max = 0;

  size_t i = 0;
  for (; i < N; i = i*2 + 2) {    /* Always traverse to right child. */
    if (tree[i] != -1) {
      max = tree[i];
      idx_max = i;
    }
  }

  size_t level = (size_t)ceil(log(idx_max)/log(2));   /* lg(index) rounded up. */
  int parent = (idx_max-1) / 2;

  fprintf(stdout, "Max: %d\n", max);
  fprintf(stdout, "Level: %llu\n", level);

  fputs("Cousins: ", stdout);
  for (i = pow(2, level-1) - 1; i < pow(2, level) - 1; ++i) {       /* Traverse in level 4, printing values that are    */
    if (i != parent*2 + 1 && i != parent*2 + 2 && tree[i] != -1) {  /* not -1 and not children of max element's parent  */
      fprintf(stdout, "%d ", tree[i]);
    }
  }
}

int main() {
  size_t N = 15;

  /* Max: 30 | Level: 4 | Cousins: 4, 7 */
   int tree[] = {9, 6, 10, 5, 8, -1, 20, 4, -1, 7, -1, -1, -1, -1, 30};

  /* Max: 7 | Level: 3 | Cousins: 4, 5
   * int tree[] = {1, 2, 3, 4, 5, 6, 7};
   */

  findMax(tree, N);

  return 0;
}
