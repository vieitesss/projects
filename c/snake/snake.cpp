#include "snake.h"
#include "game.h"
#include "direction.h"
/* #include <iostream> */

/* using namespace std; */

float Snake::snakeLen;
float Snake::xPos;
float Snake::yPos;
Direction Snake::direction;
float Snake::speed;

Snake::Snake() {
    this->snakeLen = 25.0;
    this->xPos = 0.0;
    this->yPos = 0.0;
    this->direction = Direction::RIGHT;
    this->speed = 6;
}

Snake::Snake(float xPos, float yPos) {
    Snake();
    this->xPos = xPos;
    this->yPos = yPos;
}

float Snake::getSideLen() {
    return Snake::snakeLen;
}

float Snake::getXPosition() {
    return Snake::xPos;
}

void Snake::setXPosition(float x) {
    Snake::xPos = x;
}

float Snake::getYPosition() {
    return Snake::yPos;
}

void Snake::setYPosition(float y) {
    Snake::yPos = y;
}

void Snake::setDirection(Direction direction){
    Snake::direction = direction;
}

Direction Snake::getDirection(){
    return direction;
}

void Snake::setSpeed(float speed) {
    Snake::speed = speed;
}

float Snake::getSpeed() {
    return Snake::speed;
}

void Snake::move() {
    Direction direction = Snake::getDirection();
    if (direction == Direction::UP && yPos < Game::getYLen() - snakeLen) {
        Snake::setYPosition(yPos + snakeLen);
    } else if (direction == Direction::DOWN && yPos >= snakeLen) {
        Snake::setYPosition(yPos - snakeLen);
    } else if (direction == Direction::LEFT && xPos >= snakeLen) {
        Snake::setXPosition(xPos - snakeLen);
    } else if (direction == Direction::RIGHT && xPos < Game::getXLen() - snakeLen) {
        Snake::setXPosition(xPos + snakeLen);
    }
}
