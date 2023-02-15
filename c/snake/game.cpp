#ifndef GLUT
#define GLUT
#include <GLUT/glut.h>
#endif // !GLUT

#ifndef OPENGL
#define OPENGL
#include <OpenGL/OpenGL.h>
#endif // !OPENGL

#include "game.h"
#include "square.h"
#include "direction.h"
#include <iostream>

using namespace std;

#define LOG(name, var) cout << name << " -> " << var << endl

const float Game::xLen = 1000.0;
const float Game::yLen = 750.0;
const float Game::fps = 30.0;
vector<Square> Game::snake;
/* Snake Game::snake; */

float Game::getXLen() {
    return xLen;
}

float Game::getYLen() {
    return yLen;
}

void Game::drawSnake() {
    float squareLen = Game::snake.front().getSideLen();

    for (auto currentSquare = Game::snake.begin(); currentSquare != Game::snake.end(); currentSquare++) {
        float snakeXPos = currentSquare->getXPosition();
        float snakeYPos = currentSquare->getYPosition();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(snakeXPos, snakeYPos);
        glVertex2f(snakeXPos + squareLen, snakeYPos);
        glVertex2f(snakeXPos + squareLen, snakeYPos + squareLen);
        glVertex2f(snakeXPos, snakeYPos + squareLen);
        glEnd();
    }
}

void Game::generateMatrix() {
    float squareLen = Game::snake.front().getSideLen();
    for (int x = 0; x < xLen; x += squareLen) {
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(x, yLen);
        glVertex2f(x, 0);
        glEnd();
    }

    for (int y = 0; y < yLen; y += squareLen) {
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(0, y);
        glVertex2f(xLen, y);
        glEnd();
    }
}

void Game::Update(int state) {
    Square::move();
    glutPostRedisplay();
    glutTimerFunc(1000.0/Square::getSpeed(), Game::Update, 0);
}

void *Game::Refresh(int state) {
    glutPostRedisplay();
    glutTimerFunc(1000.0/120.0, (void *) Game::Refresh, 0);
}

void Game::Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0, xLen, 0, yLen, -1, 1);

    // Dibujo ----
    Game::generateMatrix();
    Game::drawSnake();

    glFlush();
    glutSwapBuffers();
}

void Game::movement(int key, int x, int y) {
    glPushMatrix();
    switch (key) {
        case GLUT_KEY_UP:
            Square::setDirection(Direction::UP);
            break;
        case GLUT_KEY_DOWN:
            Square::setDirection(Direction::DOWN);
            break;
        case GLUT_KEY_RIGHT:
            Square::setDirection(Direction::RIGHT);
            break;
        case GLUT_KEY_LEFT:
            Square::setDirection(Direction::LEFT);
            break;
        default:
            
            break;
    }
    glPopMatrix();
    glutPostRedisplay();
}

void OpenGL() {
    glClearDepth(0.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_NORMALIZE);
}

Game::Game() {
    /* LOG("sideLen", this->snake.sideLen); */
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(xLen, yLen);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Snake");

    OpenGL();

    // Eventos de teclado ----
    glutSpecialFunc(movement);

    glutDisplayFunc(Display);

    Game::snake.push_back(*new Square());

    Game::Refresh(0);
    Game::Update(0);

    glutMainLoop();
}

