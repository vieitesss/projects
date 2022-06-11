#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINES 24
#define COLUMS 50

int main() {
  int *n = (int *)malloc(LINES * sizeof(int));
  int *m = (int *)malloc(COLUMS * sizeof(int));

  scanf("%d %d", n, m);

  char snake = '#', empty = '.';
  /*
   * flag => tells if the line is full snake
   * end => tells if the snake is at the end of the line
   */
  bool flag = true, end = true;

  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      if (!flag) {
        if (end) {
          if (j != *m - 1) {
            printf("%c", empty);
          } else {
            printf("%c", snake);
            end = !end;
          }
        } else {
          printf("%c", (j == 0) ? snake : empty);
          end = (j == *m - 1) ? !end : end;
        }
      } else {
        printf("%c", snake);
      }
    }
    flag = !flag;
    printf("\n");
  }

  return 0;
}
