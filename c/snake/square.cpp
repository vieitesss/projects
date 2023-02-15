#include "square.h"
#include "game.h"
#include "direction.h"
/* #include <iostream> */

/* using namespace std; */

float Square::sideLen;
float Square::xPos;
float Square::yPos;
Direction Square::direction;
float Square::speed;

Square::Square() {
    this->sideLen = 25.0;
    this->xPos = 0.0;
    this->yPos = 0.0;
    this->direction = Direction::RIGHT;
    this->speed = 6;
}

Square::Square(float xPos, float yPos) {
    Square();
    this->xPos = xPos;
    this->yPos = yPos;
}

float Square::getSideLen() {
    return Square::sideLen;
}

float Square::getXPosition() {
    return Square::xPos;
}

void Square::setXPosition(float x) {
    Square::xPos = x;
}

float Square::getYPosition() {
    return Square::yPos;
}

void Square::setYPosition(float y) {
    Square::yPos = y;
}

void Square::setDirection(Direction direction){
    Square::direction = direction;
}

Direction Square::getDirection(){
    return direction;
}

void Square::setSpeed(float speed) {
    Square::speed = speed;
}

float Square::getSpeed() {
    return Square::speed;
}

void Square::move() {
    Direction direction = Square::getDirection();
    if (direction == Direction::UP && yPos < Game::getYLen() - Square::sideLen) {
        Square::setYPosition(yPos + Square::sideLen);
    } else if (direction == Direction::DOWN && yPos >= Square::sideLen) {
        Square::setYPosition(yPos - Square::sideLen);
    } else if (direction == Direction::LEFT && xPos >= Square::sideLen) {
        Square::setXPosition(xPos - Square::sideLen);
    } else if (direction == Direction::RIGHT && xPos < Game::getXLen() - Square::sideLen) {
        Square::setXPosition(xPos + Square::sideLen);
    }
}
