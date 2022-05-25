#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
  int *w = malloc(MAX * sizeof(int));
  scanf("%d", w);

  if (*w % 2 == 0 && *w != 2)
    printf("YES");
  else
    printf("NO");

  return 0;
}
