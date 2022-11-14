#ifndef AHORCADO
#define AHORCADO

#define WORDS 9200
#define NSTATES 10
#define MAXDRAW 14
#define ROWS 13
#define COLUMNS 14
#define LENWORD 20
#define FILENAME "palabras.txt"

typedef struct {
  char word[LENWORD];
  char guessing[LENWORD];
  char *chosen;
  unsigned int nchosen;
  unsigned int state;
} game;

// Inicializa el struct game
void initialize(game *g);

// Menu principal
int menu(game *g);

// Indica si se ha ganado
int hasWon(game *g);

// Libera el espacio ocupado
void finish(game *g);

#endif // AHORCADO
