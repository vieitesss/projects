#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 6

int main() {
  int *ptr = malloc(MAX * sizeof(int));
  scanf("%d", ptr);
  while ('\n' != getchar())
    ;

  unsigned short count, total = 0;
  char a[LEN];

  for (int i = 0; i < *ptr; i++) {
    count = 0;
    fgets(a, 7, stdin);
    for (int j = 0; j < LEN; j++) {
      if (a[j] == '1') {
        count++;
      }
    }
    if (count > 1) {
      total++;
    }
  }
  printf("%d\n", total);

  return 0;
}
