#include "game.h"
#include "string.h"
#include "player.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void playersData(Player *players) {
  for (int i = 0; i < PLAYERS; i++) {
    printf("### Player %d\n", i + 1);

    Player *player = &players[i];
    while (1) {
      printf("Introduce your name: ");
      fgets(player->name, sizeof(player->name), stdin);

      int len = strlen(player->name);
      if (len > 0 && player->name[len - 1] == '\n') {
        player->name[len - 1] = '\0';
        break;
      }
      printf("Not valid name.\n");
    }

    while (1) {
      printf("Introduce the symbol you want to play with: ");
      char c = getchar();
      while ('\n' != getchar()); // delete all excess characters
      if (!isdigit(c)) {
        player->symbol = c;
        break;
      }
      printf("Please, do not choose a number\n");
    }

    player->turn = 0;

    for (int j = 0; j < CELLS; j++) {
      player->cells[j] = 0;
    }

    printf("Name: %s, Symbol: %c\n\n", player->name, player->symbol);
  }
}

void chooseCell(Player *player, bool choosed[], char symbols[]) {
  printf("\n## %s plays.\n", player->name);
  while (1) {
    printf("Choose a cell: ");

    int c;
    scanf("%d", &c);
    while ('\n' != getchar());
    if (c > 0 && c < 10 && !choosed[c - 1]) {
      choosed[c - 1] = 1;
      symbols[c - 1] = player->symbol;
      player->cells[c - 1] = 1;
      break;
    }

    printf("Try again.\n");
  }
}
