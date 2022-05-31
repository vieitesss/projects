#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1e5

int main() {
  int *cases = malloc(MAX * sizeof(int));
  scanf("%d", cases);

  int *a, *b, *length, i, j, consec, total;
  bool impar;
  for (i = 0; i < *cases; i++) {
    total = 0;
    length = (int *)malloc(MAX * sizeof(int));
    scanf("%d", length);

    a = (int *)calloc(*length, sizeof(int));
    b = (int *)calloc(*length, sizeof(int));

    consec = 1;
    for (j = 0; j < *length; j++) {
      if (*a == 0) {
        scanf("%d", a);
        continue;
      } else {
        scanf("%d", b);
      }

      if (*a > *b) {
        consec++;
      } else {
        total += consec / 2;
        consec = 1;
      }

      *a = *b;
    }

    total += consec / 2;

    free(length);
    free(a);
    free(b);

    printf("%d\n", total);
  }

  return 0;
}
