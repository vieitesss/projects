#ifndef GAME
#define GAME

#include "player.h"

#define PLAYERS 2
#define CELLS 9
#define CHECK 3

typedef struct Game {
  Player players[2];
  char symbols[CELLS];
  int choosed[CELLS];
}Game;

void startGame();
int newTurn(Game*, int);
void initialize(Game*);
void printTable(char*, int*);
int checkFinish(Player*, int*);

#endif // !GAME
