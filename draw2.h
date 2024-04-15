#ifndef DRAW2_H
#define DRAW2_H
#include <iostream>
#include <gl/gl.h>
#include "GLFW/glfw3.h"

float vert[] = {1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 1, 0};
float Xalfa = 20;
float Zalfa = 0;
POINTFLOAT pos = {0, 0};

GLfloat squareVertices[] = {
    -0.5f, -0.5f, 0.0f, // Нижний левый угол (0)
    0.5f, -0.5f, 0.0f, // Нижний правый угол (1)
    0.5f, 0.5f, 0.0f, // Верхний правый угол (2)
    -0.5f, 0.5f, 0.0f // Верхний левый угол (3)
};

void drawSquare(float x, float y, float z, float size, float r, float g, float b) {
    glPushMatrix();

    glTranslatef(x, y, z);

    glScalef(size, size, size);

    glColor3f(r, g, b);

    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    glDrawArrays(GL_QUADS, 0, 4);

    glPopMatrix();
}

void drawStandingSquare1(float x, float y, float z, float size, float r, float g, float b) {
    glPushMatrix();

    glTranslatef(x, y, z);

    glRotatef(90, 1.0f, 0.0f, 0.0f);

    glScalef(size, size, size);

    glColor3f(r, g, b);

    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    glDrawArrays(GL_QUADS, 0, 4);

    glPopMatrix();
}

void drawStandingSquare2(float x, float y, float z, float size, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(90, 0.0f, 0.0f, 1.0f); // поворот на 90 вокруг оси Z
    glRotatef(90, 1.0f, 0.0f, 0.0f); // поворот на 90 вокруг оси X
    glScalef(size, size, size);

    glColor3f(r, g, b);

    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    glDrawArrays(GL_QUADS, 0, 4);

    glPopMatrix();
}

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
