#ifndef PLAYER
#define PLAYER

#include <stdbool.h>
#define MAX 9

typedef struct Player {
  char name[30];
  char symbol;
  int turn;
  bool cells[MAX];
} Player;

void playersData(Player*);
void chooseCell(Player*, bool*, char*);

#endif // !PLAYER
