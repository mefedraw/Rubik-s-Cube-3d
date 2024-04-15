#include <iostream>
#include <gl/gl.h>
#include <math.h>
#include <random>
#include "draw.h"
#include "draw2.h"
#include <ctime>
#include "GLFW/glfw3.h"

time_t lastPressTime_1_button = 0;
time_t lastPressTime_2_button = 0;
time_t lastPressTime_3_button = 0;
time_t lastPressTime_4_button = 0;
time_t lastPressTime_5_button = 0;
time_t lastPressTime_6_button = 0;
time_t lastPressTime_7_button = 0;
time_t lastPressTime_8_button = 0;
time_t lastPressTime_9_button = 0;


vector<vector<vector<cubeEdge> > > cubik3d(3, vector<vector<cubeEdge> >(3, vector<cubeEdge>(3)));
stack<string> rememberMoves;

void MoveCamera(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    if (GetKeyState(VK_UP) < 0) Xalfa = ++Xalfa > 180 ? 180 : Xalfa += 3;
    if (GetKeyState(VK_DOWN) < 0) Xalfa = --Xalfa < 0 ? 0 : Xalfa -= 3;
    if (GetKeyState(VK_LEFT) < 0) Zalfa += 3;
    if (GetKeyState(VK_RIGHT) < 0) Zalfa -= 3;

    float angle = -Zalfa / 180 * M_PI;
    float speed = 0;
    if (GetKeyState('W') < 0) {
        speed = 0.1;
    }
    if (GetKeyState('S') < 0) {
        speed = -0.1;
    }
    if (GetKeyState('A') < 0) {
        speed = 0.1;
        angle -= M_PI * 0.5;
    }
    if (GetKeyState('D') < 0) {
        speed = 0.1;
        angle += M_PI * 0.5;
    }
    if (GetKeyState('1') < 0 && difftime(time(0), lastPressTime_1_button) >= 1) {
        cubik3d_ru_rotate(cubik3d_f);
        rememberMoves.push("ru");
        lastPressTime_1_button = time(0);
    }
    if (GetKeyState('2') < 0 && difftime(time(0), lastPressTime_2_button) >= 1) {
        cubik3d_lu_rotate(cubik3d_f);
        rememberMoves.push("lu");
        lastPressTime_2_button = time(0);
    }
    //cubik3d_dl_rotate
    if (GetKeyState('3') < 0 && difftime(time(0), lastPressTime_3_button) >= 1) {
        cubik3d_dl_rotate(cubik3d_f);
        rememberMoves.push("dl");
        lastPressTime_3_button = time(0);
    }
    if (GetKeyState('4') < 0 && difftime(time(0), lastPressTime_4_button) >= 1) {
        cubik3d_ul_rotate(cubik3d_f);
        rememberMoves.push("ul");
        lastPressTime_4_button = time(0);
    }
    if (GetKeyState('5') < 0 && difftime(time(0), lastPressTime_5_button) >= 1) {
        cubik3d_fs_rotate(cubik3d_f);
        rememberMoves.push("fs");
        lastPressTime_5_button = time(0);
    }
    if (GetKeyState('6') < 0 && difftime(time(0), lastPressTime_6_button) >= 1) {
        cubik3d_bs_rotate(cubik3d_f);
        rememberMoves.push("bs");
        lastPressTime_6_button = time(0);
    }
    if (GetKeyState('7') < 0 && difftime(time(0), lastPressTime_7_button) >= 1) {
        shuffle(cubik3d_f, rememberMoves);
        lastPressTime_7_button = time(0);
    }
    if (GetKeyState('8') < 0 && difftime(time(0), lastPressTime_8_button) >= 2) {
        solve(cubik3d_f, rememberMoves);
        lastPressTime_8_button = time(0);
    }
    if (GetKeyState('9') < 0 && difftime(time(0), lastPressTime_9_button) >= 2) {
        init_cubik3d(cubik3d_f);
        while(!rememberMoves.empty()) {
            rememberMoves.pop();
        }
        lastPressTime_9_button = time(0);
    }
    if (speed != 0) {
        pos.x += sin(angle) * speed;
        pos.y += cos(angle) * speed;
    }

    glRotatef(-Xalfa, 1, 0, 0);
    glRotatef(-Zalfa, 0, 0, 1);
    glTranslatef(-pos.x, -pos.y, -3);
}

int Run_Window() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 1280, "Rubik's Cube", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glFrustum(-1, 1, -1, 1, 2, 10000);
    glEnable(GL_DEPTH_TEST);

    init_cubik3d(cubik3d);
    init_mapColors();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        MoveCamera(cubik3d);
        ShowWorld(cubik3d);
        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main() {
    Run_Window();
    return 0;
}
