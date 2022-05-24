#ifndef PLAYER
#define PLAYER

#define MAX 9

typedef struct Player {
  char name[30];
  char symbol;
  int turn;
  int cells[MAX];
} Player;

void playersData(Player*);
void chooseCell(Player*, int*, char*);

#endif // !PLAYER
