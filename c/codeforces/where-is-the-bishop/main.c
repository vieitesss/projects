#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  char array[8][8], minus1, minus2, count;
  int target;
  for (int i = 0; i < t; i++) {
    for (int row = 1; row <= 8; row++) {
      scanf("%s", array[row]);
    }

    minus1 = 0;
    minus2 = 0;
    for (int row = 1; row <= 8; row++) {
      count = 0;
      for (int column = 0; column < 7; column++) {
        if (*(*(array + row) + column) == '#') {
          count++;
        }
      }

      if (minus2 == 2 && minus1 == 1 && count == 2) {
        target = row - 1;
        break;
      }
      minus2 = minus1;
      minus1 = count;
    }

    for (int j = 0; j < 8; j++) {
      if (*(*(array + target) + j) == '#') {
        printf("%d %d\n", target, j + 1);
        break;
      }
    }
  }

  return 0;
}
