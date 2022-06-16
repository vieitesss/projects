#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int a, runner, total;
  for (int i = 0; i < n; i++) {
    total = 0;
    scanf("%d", &a);
    for (int i = 0; i < 3; i++) {
      scanf("%d", &runner);
      if (runner > a) {
        total++;
      }
    }
    printf("%d\n", total);
  }

  return 0;
}
