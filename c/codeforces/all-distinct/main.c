#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  int t;
  scanf("%d", &t);

  short n;
  int *array, total, twos, amount;
  array = malloc(sizeof(int));
  for (int i = 0; i < t; i++) {
    scanf("%hd", &n);
    array = realloc(array, n * sizeof(int));
    for (int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), cmp);

    twos = 0;
    total = 0;
    amount = 1;
    for (int i = 1; i < n; i++) {
      if (array[i] == array[i - 1]) {
        amount++;
      } else {
        (amount % 2 == 0) ? twos++ : total++;
        amount = 1;
      }
    }

    (amount % 2 == 0) ? twos++ : total++;

    total += (twos / 2) * 2;
    printf("%d\n", total);
  }

  return 0;
}
