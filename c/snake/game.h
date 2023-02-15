#ifndef GAME
#define GAME

#include "square.h"
#include <vector>

using namespace std;

class Game {
public:
    Game();
    static float getXLen();
    static float getYLen();

  private:
    const static float xLen;
    const static float yLen;
    const static float fps;
    static vector<Square> snake;
    // next features:
    // - points

    void Display(void);
    static void generateMatrix();
    static void drawSnake();
    static void movement(int key, int x, int y);
    void Refresh(int state);
    static void Update(int state);
};

#endif // !GAME
