#include "ahorcado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAYLEN(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
  int *s;
  unsigned int n;
} state;

int state1[] = {168, 169, 170, 171, 172, 173, 174,
                175, 176, 177, 178, 179, 180, 181};
int state2[] = {2, 16, 30, 44, 58, 72, 86, 100, 114, 128, 142, 156};
int state3[] = {3, 4, 5, 6, 7, 8, 9};
int state4[] = {19, 32, 45};
int state5[] = {23, 36, 38, 51};
int state6[] = {65, 79, 93, 107};
int state7[] = {64, 77};
int state8[] = {66, 81};
int state9[] = {120, 133};
int state10[] = {122, 137};

state states[] = {
    {state1, ARRAYLEN(state1)}, {state2, ARRAYLEN(state2)},
    {state3, ARRAYLEN(state3)}, {state4, ARRAYLEN(state4)},
    {state5, ARRAYLEN(state5)}, {state6, ARRAYLEN(state6)},
    {state7, ARRAYLEN(state7)}, {state8, ARRAYLEN(state8)},
    {state9, ARRAYLEN(state9)}, {state10, ARRAYLEN(state10)},
};

void _getWord(char *g);
void _draw(game g);
int _printGuessing(game g);
void _chooseChar(game *g);

void initialize(game *g) {
  _getWord(g->word);

  for (int i = 0; i < strlen(g->word); i++) {
    g->guessing[i] = '*';
  }

  g->chosen = (char *)malloc(sizeof(char) * (strlen(g->word) + 10));
  g->nchosen = 0;
  g->state = 0;
}

void _getWord(char *word) {
  FILE *file;
  int count = 0;

  srand(time(NULL));
  int r = rand() % WORDS;

  if ((file = fopen(FILENAME, "r")) != NULL) {
    fscanf(file, "%s\n", word);
    while (count != r) {
      fscanf(file, "%s\n", word);
      count++;
    }
  } else {
    perror("Error opening de file");
  }

  fclose(file);
}

int menu(game *g) {
  _draw(*g);

  _chooseChar(g);

  int guessed;
  guessed = _printGuessing(*g);

  int result;
  if ((result = hasWon(g)) != 2) {
    return result;
  }

  return 2;
}

void _draw(game g) {
  printf("estado: %i\n", g.state);
  if (g.state == 0) {
    return;
  }

  char draw[ROWS * COLUMNS];

  for (int i = 0; i < g.state; i++)
    for (int j = 0; j < states[i].n; j++)
      draw[states[i].s[j]] = '.';

  for (int i = 0; i < ROWS * COLUMNS; i++) {
    if (draw[i] != '.')
      draw[i] = ' ';
    if (i % COLUMNS == 0)
      printf("\n");

    printf("%c", draw[i]);
  }
  printf("\n");
}

int _printGuessing(game g) {
  int guessed = 0;
  unsigned int flag = 0;

  for (int i = 0; i < strlen(g.word); i++) {
    flag = 0;
    for (int j = 0; j < g.nchosen; j++) {
      if (g.word[i] == g.chosen[j]) {
        printf("%c", g.chosen[j]);
        guessed++;
        flag = 1;
        continue;
      }
    }
    if (!flag) {
      printf("*");
    }
  }
  printf("\n");

  return guessed;
}

int hasWon(game *g) { return 2; }

void _chooseChar(game *g) {
  printf("Escoge una letra: ");
  char c;
  scanf(" %c", &c);

  g->chosen[g->nchosen] = c;
  g->nchosen++;
}

void finish(game *g) { free(g->chosen); }
