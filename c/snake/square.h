#ifndef SNAKE
#define SNAKE

#include "direction.h"

class Square {
public:
    Square();
    Square(float xPos, float yPos);
    static float getSideLen();
    static float getXPosition();
    static void setXPosition(float x);
    static float getYPosition();
    static void setYPosition(float y);
    static void setDirection(Direction direction);
    static Direction getDirection();
    static void setSpeed(float speed);
    static float getSpeed();
    static void move();

private:
    static float xPos;
    static float yPos;
    static float sideLen;
    static Direction direction;
    static float speed;
};

#endif // !SNAKE
