#include <stdio.h>
#include <stdlib.h>

#define MAX 150

int main() {
  int *n = (int *)malloc(MAX * sizeof(int));
  scanf("%d", n);

  char s[3] = "";
  int *x = (int *)calloc(MAX, sizeof(int));
  for (int i = 0; i < *n; i++) {
    scanf("%s", s);
    if (s[1] == '+') {
      *x = *x + 1;
    } else {
      *x = *x - 1;
    }
  }
  printf("%d\n", *x);

  return 0;
}
