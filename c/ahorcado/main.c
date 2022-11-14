#include <stdio.h>
#include <stdlib.h>

#include "ahorcado.h"

int main(int argc, char *argv[]) {
  game g;
  initialize(&g);

  int win;
  while ((win = menu(&g)) == 2)
    ;

  switch (win) {
  case 1:
    printf("Has ganado\n");
    break;
  case 0:
    printf("Has perdido\n");
    break;
  }

  finish(&g);

  exit(EXIT_SUCCESS);
}
