#include <stdio.h>
#include <stdlib.h>

#define ll long long

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  int items, queries;
  scanf("%d %d", &items, &queries);

  int prices[items];

  for (int i = 0; i < items; i++) {
    scanf("%d", &prices[i]);
  }

  qsort(prices, items, sizeof(int), cmpfunc);

  ll values[items + 1];
  values[0] = 0;

  for (int i = 1, j = items - 1; i <= items; i++, j--) {
    values[i] = values[i - 1] + prices[j];
  }

  int x, y;
  while (queries-- > 0) {
    scanf("%d %d", &x, &y);
    printf("%lld\n", values[x] - values[x - y]);
  }

  return 0;
}
