#include "game.h"
#include "player.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void startGame() {
  Game game;
  Game *g = &game;

  initialize(&game);

  for (int i = 0; i < CELLS; i++) {
    printTable(game.symbols, game.choosed);
    int finish = newTurn(g, i % 2);
    if (finish) {
      break;
    }
  }
  printTable(game.symbols, game.choosed);
}

void initialize(Game *game) {
  playersData(game->players);

  for (int i = 0; i < CELLS; i++) {
    game->symbols[i] = ' ';
    game->choosed[i] = 0;
  }
}

void printTable(char symbols[], int choosed[]) {
  char constLine[13] = "|---|---|---|";

  for (int i = 0; i < CELLS; i++) {
    if (i % 3 == 0) {
      printf("\n%s\n|", constLine);
    }
    printf(" %c |", (choosed[i])? symbols[i] : (i + 1) + '0');
  }
  printf("\n%s\n", constLine);
}

int newTurn(Game *game, int turn) {
  Player *player = &game->players[turn];
  player->turn++;
  chooseCell(player, game->choosed, game->symbols);
  int f = checkFinish(player, game->choosed);
  if (f == 1) {
    printf("%s WINS!!!\n", player->name);
    return 1;
  }
  else if (f == 2) {
    printf("IT'S A DRAW!!!\n");
    return 1;
  }
  return 0;
}

/*
 *  return:
 *    0: Not finished
 *    1: Player wins
 *    2: Draw
 */
int checkFinish(Player *player, int choosed[]) {
  if (player->turn < 3) {
    return 0;
  }
  int *pCells = player->cells;
  int l = 0;
  int c = 0;

  for (int i = 0; i < CHECK; i++) {
    // Lines
    if (pCells[l] && pCells[l + 1] && pCells[l + 2] && 
        choosed[l] && choosed[l + 1] && choosed[l + 2]){
      printf("\nLINES WINNING\n");
      return 1;
    }

    // Columns
    if (pCells[c] && pCells[c + 3] && pCells[c + 6] && 
        choosed[c] && choosed[c + 3] && choosed[c + 6]){
      printf("\nCOLUMNS WINNING\n");
      return 1;
    }

    // Diagonals
    if (c == 0) {
      if (pCells[c] && pCells[c + 4] && pCells[c + 8] &&
          choosed[c] && choosed[c + 4] && choosed[c + 8]) {
        printf("\nDIAGONAL 1 WINNING\n");
        return 1;
      }
    }

    if (c == 2) {
      if (pCells[c] && pCells[c + 2] && pCells[c + 4] &&
          choosed[c] && choosed[c + 2] && choosed[c + 4]) {
        printf("\nDIAGONAL 2 WINNING\n");
        return 1;
      }
    }
    
    c++;
    l = l + 3;
  }

  int cc = 0; // cells choosed
  for (int i = 0; i < CELLS; i++) {
    if (choosed[i]) cc++;
  }
  if (cc == 9) return 2;

  return 0;
}
