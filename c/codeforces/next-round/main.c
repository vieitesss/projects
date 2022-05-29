#include <stdio.h>

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (n < k) {
    int temp = k;
    k = n;
    n = temp;
  }

  int min = 0, total = 0, temp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);

    if (temp <= 0 || temp < min)
      break;

    if (i == k - 1) {
      min = temp;
    }

    total++;
  }

  printf("%d\n", total);

  return 0;
}
