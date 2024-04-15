#ifndef DRAW2_H
#define DRAW2_H
#include <windows.h>
#include <iostream>
#include <gl/gl.h>
#include <math.h>
#include <random>

#include "GLFW/glfw3.h"
float vert[] = {1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 1, 0};
float Xalfa = 20;
float Zalfa = 0;
POINTFLOAT pos = {0, 0};
//float cube[] = {0, 0, 0, 1, 0, 0, 1, 0, -1, 0, 0, -1, 0, 1, -1, 1, 1, -1, 1, 1, 1, 0, 1, 0};
GLfloat cubeVertices[] = {
    // Вершины куба
    -0.5f, -0.5f, -0.5f, // 0
    0.5f, -0.5f, -0.5f, // 1
    0.5f, 0.5f, -0.5f, // 2
    -0.5f, 0.5f, -0.5f, // 3
    -0.5f, -0.5f, 1.f, // 4
    0.5f, -0.5f, 1.f, // 5
    0.5f, 0.5f, 1.f, // 6
    -0.5f, 0.5f, 1.f // 7
};

GLubyte cubeIndices[] = {
    // Индексы для отрисовки куба
    0, 1, 2, // Передняя грань
    2, 3, 0,
    4, 5, 6, // Задняя грань
    6, 7, 4,
    0, 4, 7, // Левая грань
    7, 3, 0,
    1, 5, 6, // Правая грань
    6, 2, 1,
    0, 1, 5, // Нижняя грань
    5, 4, 0,
    2, 3, 7, // Верхняя грань
    7, 6, 2
};

GLfloat squareVertices[] = {
    // Вершины квадрата
    -0.5f, -0.5f, 0.0f, // Нижний левый угол (0)
    0.5f, -0.5f, 0.0f, // Нижний правый угол (1)
    0.5f, 0.5f, 0.0f, // Верхний правый угол (2)
    -0.5f, 0.5f, 0.0f // Верхний левый угол (3)
};

float pyramid[] = {0, 0, 2, 1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 1, 0, 1, 1, 0};

void drawCube(float x, float y, float z, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    ///glScalef(1,1,0.5);
    glColor3f(r, g, b);
    glDrawElements(GL_TRIANGLES, sizeof(cubeIndices) / sizeof(cubeIndices[0]), GL_UNSIGNED_BYTE, cubeIndices);
    glPopMatrix();
}

void displayBigCube() {
    float red = 1;;
    float green = 0;
    float blue = 0;
    drawCube(5, 5, 4, red, green, blue);
    drawCube(6, 5, 4, red, green, blue);
    drawCube(7, 5, 4, red, green, blue);

    drawCube(5, 6, 4, red, green, blue);
    drawCube(6, 6, 4, red, green, blue);
    drawCube(7, 6, 4, red, green, blue);

    drawCube(5, 7, 4, red, green, blue);
    drawCube(6, 7, 4, red, green, blue);
    drawCube(7, 7, 4, red, green, blue);


    red = 0;
    green = 1;
    blue = 0;
    drawCube(5, 5, 5, red, green, blue);
    drawCube(6, 5, 5, red, green, blue);
    drawCube(7, 5, 5, red, green, blue);

    drawCube(5, 6, 5, red, green, blue);
    drawCube(6, 6, 5, red, green, blue);
    drawCube(7, 6, 5, red, green, blue);

    drawCube(5, 7, 5, red, green, blue);
    drawCube(6, 7, 5, red, green, blue);
    drawCube(7, 7, 5, red, green, blue);


    red = 0;
    green = 0;
    blue = 1;
    drawCube(5, 5, 6, red, green, blue);
    drawCube(6, 5, 6, red, green, blue);
    drawCube(7, 5, 6, red, green, blue);

    drawCube(5, 6, 6, red, green, blue);
    drawCube(6, 6, 6, red, green, blue);
    drawCube(7, 6, 6, red, green, blue);

    drawCube(5, 7, 6, red, green, blue);
    drawCube(6, 7, 6, red, green, blue);
    drawCube(7, 7, 6, red, green, blue);
}

void drawPlate(float x, float y, float z, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    ///glScalef(1,1,0.5);
    glColor3f(r, g, b);
    glDrawElements(GL_TRIANGLES, sizeof(cubeIndices) / sizeof(cubeIndices[0]), GL_UNSIGNED_BYTE, cubeIndices);
    glPopMatrix();
}

void drawPlate() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 1, 0);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glEnd();
}

void drawSquare(float x, float y, float z, float size, float r, float g, float b) {
    // Сохраните текущую матрицу модели
    glPushMatrix();

    // Переместите и масштабируйте матрицу модели для отрисовки квадрата
    glTranslatef(x, y, z);
    glScalef(size, size, size);

    // Установите цвет для квадрата
    glColor3f(r, g, b);

    // Установите указатель на массив вершин квадрата
    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    // Отрисуйте квадрат
    glDrawArrays(GL_QUADS, 0, 4);

    // Восстановите исходную матрицу модели
    glPopMatrix();
}

void drawStandingSquare1(float x, float y, float z, float size, float r, float g, float b) {
    // Сохраните текущую матрицу модели
    glPushMatrix();

    // Переместите, масштабируйте и поверните матрицу модели для отрисовки стоячего квадрата
    glTranslatef(x, y, z);
    glRotatef(90, 1.0f, 0.0f, 0.0f); // Поворот на 90 градусов вокруг оси X
    glScalef(size, size, size);

    // Установите цвет для квадрата
    glColor3f(r, g, b);

    // Установите указатель на массив вершин квадрата
    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    // Отрисуйте квадрат
    glDrawArrays(GL_QUADS, 0, 4);

    // Восстановите исходную матрицу модели
    glPopMatrix();
}

void drawStandingSquare2(float x, float y, float z, float size, float r, float g, float b) {
    // Сохраните текущую матрицу модели
    glPushMatrix();

    // Переместите, масштабируйте и поверните матрицу модели для отрисовки стоячего квадрата
    glTranslatef(x, y, z);
    glRotatef(90, 0.0f, 0.0f, 1.0f); // Поворот на 180 градусов вокруг оси Y
    glRotatef(90, 1.0f, 0.0f, 0.0f); // Поворот на 90 градусов вокруг оси X
    glScalef(size, size, size);

    // Установите цвет для квадрата
    glColor3f(r, g, b);

    // Установите указатель на массив вершин квадрата
    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    // Отрисуйте квадрат
    glDrawArrays(GL_QUADS, 0, 4);

    // Восстановите исходную матрицу модели
    glPopMatrix();
}

enum RotationAxis {
    X_AXIS,
    Y_AXIS,
    Z_AXIS
};

enum RotationDirection {
    CLOCKWISE,
    COUNTER_CLOCKWISE
};

struct Rotation {
    RotationAxis axis;
    RotationDirection direction;
    int layer;
};

Rotation currentRotation = {X_AXIS, CLOCKWISE, 0};

// сделать куб немного прозрачным
void rotateFace(RotationAxis axis, int layer, RotationDirection direction) {
    for (int i = 0; i < 9; ++i) {
        float *vertex = &cubeVertices[layer * 9 + i * 3];
        float x = vertex[0];
        float y = vertex[1];
        float z = vertex[2];

        switch (axis) {
            case X_AXIS:
                if (direction == CLOCKWISE) {
                    vertex[1] = -z;
                    vertex[2] = y;
                } else {
                    vertex[1] = z;
                    vertex[2] = -y;
                }
                break;
            case Y_AXIS:
                if (direction == CLOCKWISE) {
                    vertex[0] = z;
                    vertex[2] = -x;
                } else {
                    vertex[0] = -z;
                    vertex[2] = x;
                }
                break;
            case Z_AXIS:
                if (direction == CLOCKWISE) {
                    vertex[0] = -y;
                    vertex[1] = x;
                } else {
                    vertex[0] = y;
                    vertex[1] = -x;
                }
                break;
        }
    }
}

/*
if (GetKeyState('E') < 0) {
        currentRotation.axis = X_AXIS;
        currentRotation.direction = COUNTER_CLOCKWISE;
        currentRotation.layer = 2;
        rotateFace(currentRotation.axis, currentRotation.layer, currentRotation.direction);
    }
 */

void drawUpSide(float z) {
    //
    drawSquare(10, 12, z, 1, 1, 1, 0);
    drawSquare(10, 11, z, 1, 1, 1, 0);
    drawSquare(10, 10, z, 1, 1, 1, 0);

    drawSquare(11, 10, z, 1, 1, 1, 0);
    drawSquare(11, 11, z, 1, 1, 1, 0);
    drawSquare(11, 12, z, 1, 1, 1, 0);

    drawSquare(12, 10, z, 1, 1, 1, 0);
    drawSquare(12, 11, z, 1, 1, 1, 0);
    drawSquare(12, 12, z, 1, 1, 1, 0);
}

void drawDownSide() {
    //
    drawSquare(10, 12, 3.5, 1, 1, 1, 1);
    drawSquare(10, 11, 3.5, 1, 1, 1, 1);
    drawSquare(10, 10, 3.5, 1, 1, 1, 1);

    drawSquare(11, 10, 3.5, 1, 1, 1, 1);
    drawSquare(11, 11, 3.5, 1, 1, 1, 1);
    drawSquare(11, 12, 3.5, 1, 1, 1, 1);

    drawSquare(12, 12, 3.5, 1, 1, 1, 1);
    drawSquare(12, 11, 3.5, 1, 1, 1, 1);
    drawSquare(12, 10, 3.5, 1, 1, 1, 1);
}

void drawGreenSide() {
    //
    drawStandingSquare1(10, 12.5, 5, 1, 0, 1, 0);
    drawStandingSquare1(10, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(10, 12.5, 4, 1, 0, 1, 0);

    drawStandingSquare1(11, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(11, 12.5, 5, 1, 0, 1, 0);
    drawStandingSquare1(11, 12.5, 4, 1, 0, 1, 0);

    drawStandingSquare1(12, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(12, 12.5, 4, 1, 0, 1, 0);
    drawStandingSquare1(12, 12.5, 5, 1, 0, 1, 0);
}

void drawBlueSide() {
    //
    drawStandingSquare1(10, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 4, 1, 0, 0, 1);

    drawStandingSquare1(11, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 4, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 6, 1, 0, 0, 1);

    drawStandingSquare1(12, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(12, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(12, 9.5, 4, 1, 0, 0, 1);
}

void drawPinkSide() {
    drawStandingSquare2(9.5, 10, 4, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 11, 4, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 4, 1, 1, 0.5, 1);

    drawStandingSquare2(9.5, 10, 5, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 11, 5, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 5, 1, 1, 0.5, 1);

    drawStandingSquare2(9.5, 10, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 11, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 6, 1, 1, 0.5, 1);
}

void drawOrangeSide() {
    drawStandingSquare2(12.5, 10, 4, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 11, 4, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 4, 1, 1, 0, 0);

    drawStandingSquare2(12.5, 10, 5, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 11, 5, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 5, 1, 1, 0, 0);

    drawStandingSquare2(12.5, 10, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 11, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 6, 1, 1, 0, 0);
}

void drawEdge1() {
    drawSquare(10, 12, 6.5, 1, 1, 1, 0);
    drawSquare(10, 11, 6.5, 1, 1, 1, 0);
    drawSquare(10, 10, 6.5, 1, 1, 1, 0);

    drawSquare(10, 12, 3.5, 1, 1, 1, 1);
    drawSquare(10, 11, 3.5, 1, 1, 1, 1);
    drawSquare(10, 10, 3.5, 1, 1, 1, 1);

    drawStandingSquare1(10, 12.5, 5, 1, 0, 1, 0);
    drawStandingSquare1(10, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(10, 12.5, 4, 1, 0, 1, 0);

    drawStandingSquare1(10, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 4, 1, 0, 0, 1);
}

void drawEdge2() {
    drawSquare(12, 10, 6.5, 1, 1, 1, 0);
    drawSquare(12, 11, 6.5, 1, 1, 1, 0);
    drawSquare(12, 12, 6.5, 1, 1, 1, 0);

    drawSquare(12, 12, 3.5, 1, 1, 1, 1);
    drawSquare(12, 11, 3.5, 1, 1, 1, 1);
    drawSquare(12, 10, 3.5, 1, 1, 1, 1);

    drawStandingSquare1(12, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(12, 12.5, 4, 1, 0, 1, 0);
    drawStandingSquare1(12, 12.5, 5, 1, 0, 1, 0);

    drawStandingSquare1(12, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(12, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(12, 9.5, 4, 1, 0, 0, 1);
}

void drawEdge3() {
    drawSquare(11, 12, 6.5, 1, 1, 1, 0);
    drawSquare(12, 12, 6.5, 1, 1, 1, 0);
    drawSquare(10, 12, 6.5, 1, 1, 1, 0);

    drawStandingSquare2(12.5, 12, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 5, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 4, 1, 1, 0, 0);

    drawStandingSquare2(9.5, 12, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 5, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 4, 1, 1, 0.5, 1);

    drawSquare(11, 12, 3.5, 1, 1, 1, 1);
    drawSquare(12, 12, 3.5, 1, 1, 1, 1);
    drawSquare(10, 12, 3.5, 1, 1, 1, 1);
}

void drawEdge4() {
    drawSquare(11, 10, 6.5, 1, 1, 1, 0);
    drawSquare(12, 10, 6.5, 1, 1, 1, 0);
    drawSquare(10, 10, 6.5, 1, 1, 1, 0);

    drawStandingSquare2(12.5, 10, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 10, 5, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 10, 4, 1, 1, 0, 0);

    drawStandingSquare2(9.5, 10, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 10, 5, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 10, 4, 1, 1, 0.5, 1);

    drawSquare(11, 10, 3.5, 1, 1, 1, 1);
    drawSquare(12, 10, 3.5, 1, 1, 1, 1);
    drawSquare(10, 10, 3.5, 1, 1, 1, 1);


}

void drawEdge5() {
    drawStandingSquare2(9.5, 10, 4, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 11, 4, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 4, 1, 1, 0.5, 1);

    drawStandingSquare2(12.5, 10, 4, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 11, 4, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 4, 1, 1, 0, 0);

    drawStandingSquare1(12, 9.5, 4, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 4, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 4, 1, 0, 0, 1);

    drawStandingSquare1(12, 12.5, 4, 1, 0, 1, 0);
    drawStandingSquare1(11, 12.5, 4, 1, 0, 1, 0);
    drawStandingSquare1(10, 12.5, 4, 1, 0, 1, 0);
}

void drawEdge6() {
    drawStandingSquare2(9.5, 10, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 11, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 6, 1, 1, 0.5, 1);

    drawStandingSquare2(12.5, 10, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 11, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 12, 6, 1, 1, 0, 0);

    drawStandingSquare1(12, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 6, 1, 0, 0, 1);

    drawStandingSquare1(12, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(11, 12.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(10, 12.5, 6, 1, 0, 1, 0);
}

void drawCenters() {
    drawSquare(11, 11, 3.5, 1, 1, 1, 1);
    drawSquare(11, 11, 6.5, 1, 1, 1, 0);

    drawStandingSquare2(9.5, 11, 5, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 11, 5, 1, 1, 0.5, 1);

    drawStandingSquare1(11, 12.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 5, 1, 0, 1, 0);
}

void draw_ru_base() {
    drawSquare(11, 10, 6.5, 1, 1, 1, 0);
    drawSquare(12, 10, 6.5, 1, 1, 1, 0);
    drawSquare(10, 10, 6.5, 1, 1, 1, 0);

    drawStandingSquare2(12.5, 10, 6, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 10, 5, 1, 1, 0, 0);
    drawStandingSquare2(12.5, 10, 4, 1, 1, 0, 0);

    drawStandingSquare2(9.5, 10, 6, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 10, 5, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 10, 4, 1, 1, 0.5, 1);

    drawSquare(11, 10, 3.5, 1, 1, 1, 1);
    drawSquare(12, 10, 3.5, 1, 1, 1, 1);
    drawSquare(10, 10, 3.5, 1, 1, 1, 1);

    ///

    drawStandingSquare1(10, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(10, 9.5, 4, 1, 0, 0, 1);

    //drawStandingSquare1(11, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 4, 1, 0, 0, 1);
    drawStandingSquare1(11, 9.5, 6, 1, 0, 0, 1);

    drawStandingSquare1(12, 9.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(12, 9.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(12, 9.5, 4, 1, 0, 0, 1);
}

void draw_dl_base() {
    drawStandingSquare2(9.5, 10, 4, 1, 1, 0, 0);
    drawStandingSquare2(9.5, 11, 4, 1, 1, 0, 0);
    drawStandingSquare2(9.5, 12, 4, 1, 1, 0, 0);

    drawStandingSquare2(12.5, 10, 4, 1, 1, 0.5, 1);
    drawStandingSquare2(12.5, 11, 4, 1, 1, 0.5, 1);
    drawStandingSquare2(12.5, 12, 4, 1, 1, 0.5, 1);

    drawStandingSquare1(12, 9.5, 4, 1, 0, 1, 0);
    drawStandingSquare1(11, 9.5, 4, 1, 0, 1, 0);
    drawStandingSquare1(10, 9.5, 4, 1, 0, 1, 0);

    drawStandingSquare1(12, 12.5, 4, 1, 0, 0, 1);
    drawStandingSquare1(11, 12.5, 4, 1, 0, 0, 1);
    drawStandingSquare1(10, 12.5, 4, 1, 0, 0, 1);


    drawSquare(10, 12, 3.5, 1, 1, 1, 1);
    drawSquare(10, 11, 3.5, 1, 1, 1, 1);
    drawSquare(10, 10, 3.5, 1, 1, 1, 1);

    drawSquare(11, 10, 3.5, 1, 1, 1, 1);
    //drawSquare(11, 11, 3.5, 1, 1, 1, 1);
    drawSquare(11, 12, 3.5, 1, 1, 1, 1);

    drawSquare(12, 12, 3.5, 1, 1, 1, 1);
    drawSquare(12, 11, 3.5, 1, 1, 1, 1);
    drawSquare(12, 10, 3.5, 1, 1, 1, 1);
}

void draw_fs_base() {
    drawSquare(10, 12, 6.5, 1, 1, 1, 0);
    drawSquare(10, 11, 6.5, 1, 1, 1, 0);
    drawSquare(10, 10, 6.5, 1, 1, 1, 0);

    drawSquare(10, 12, 3.5, 1, 1, 1, 1);
    drawSquare(10, 11, 3.5, 1, 1, 1, 1);
    drawSquare(10, 10, 3.5, 1, 1, 1, 1);

    drawStandingSquare1(10, 12.5, 5, 1, 0, 0, 1);
    drawStandingSquare1(10, 12.5, 6, 1, 0, 0, 1);
    drawStandingSquare1(10, 12.5, 4, 1, 0, 0, 1);

    drawStandingSquare1(10, 9.5, 5, 1, 0, 1, 0);
    drawStandingSquare1(10, 9.5, 6, 1, 0, 1, 0);
    drawStandingSquare1(10, 9.5, 4, 1, 0, 1, 0);


    drawStandingSquare2(9.5, 10, 4, 1, 1, 0, 0);
    drawStandingSquare2(9.5, 11, 4, 1, 1, 0, 0);
    drawStandingSquare2(9.5, 12, 4, 1, 1, 0, 0);

    drawStandingSquare2(9.5, 10, 5, 1, 1, 0, 0);
    //drawStandingSquare2(9.5, 11, 5, 1, 1, 0.5, 1);
    drawStandingSquare2(9.5, 12, 5, 1, 1, 0, 0);

    drawStandingSquare2(9.5, 10, 6, 1, 1, 0, 0);
    drawStandingSquare2(9.5, 11, 6, 1, 1, 0, 0);
    drawStandingSquare2(9.5, 12, 6, 1, 1, 0, 0);
}
#endif //DRAW2_H
