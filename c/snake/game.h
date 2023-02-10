#ifndef GAME
#define GAME

#include "snake.h"

class Game {
public:
    Game();
    static float getXLen();
    static float getYLen();

  private:
    const static float xLen;
    const static float yLen;
    const static float fps;
    static Snake snake;
    // next features:
    // - points

    static void Display();
    static void generateMatrix();
    static void drawSnake();
    static void movement(int key, int x, int y);
    static void Refresh(int state);
    static void Update(int state);
};

#endif // !GAME
