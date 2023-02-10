#ifndef GLUT
#define GLUT
#include <GLUT/glut.h>
#endif // !GLUT

#include "game.h"

int main (int argc, char *argv[]) {
    glutInit(&argc, argv);
    Game *game = new Game();
    return 0;
}
