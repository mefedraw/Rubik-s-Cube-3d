#include <windows.h>
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

float randomNUM();

vector<vector<vector<cubeEdge> > > cubik3d(3, vector<vector<cubeEdge> >(3, vector<cubeEdge>(3)));
stack<string> rememberMoves;

void ShowWorld(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT, 0, &vert);
    for (int i = -10; i < 10; i++)
        for (int j = -10; j < 10; j++) {
            glPushMatrix();
            if ((i + j) % 2 == 0) {
                glColor3f(0.5, 0.5, 0.5);
            } else {
                glColor3f(0, 0, 0.4);
            }
            glTranslatef(i * 2, j * 2, 0);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glPopMatrix();
        }

    glVertexPointer(3, GL_FLOAT, 0, squareVertices);
    glColor3f(1.0f, 0.0f, 0.0f); // Красный цвет
    glDrawArrays(GL_QUADS, 0, 4);

    display_cube(cubik3d_f);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void MoveCamera(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    if (GetKeyState(VK_UP) < 0) Xalfa = ++Xalfa > 180 ? 180 : Xalfa += 5;
    if (GetKeyState(VK_DOWN) < 0) Xalfa = --Xalfa < 0 ? 0 : Xalfa -= 5;
    if (GetKeyState(VK_LEFT) < 0) Zalfa += 5;
    if (GetKeyState(VK_RIGHT) < 0) Zalfa -= 5;

    float angle = -Zalfa / 180 * M_PI;
    float speed = 0;
    if (GetKeyState('W') < 0) {
        speed = 0.15;
    }
    if (GetKeyState('S') < 0) {
        speed = -0.15;
    }
    if (GetKeyState('A') < 0) {
        speed = 0.15;
        angle -= M_PI * 0.5;
    }
    if (GetKeyState('D') < 0) {
        speed = 0.15;
        angle += M_PI * 0.5;
    }
    if (GetKeyState('1') < 0 && difftime(time(0), lastPressTime_1_button) >= 1) {
        cubik3d_ru_rotate(cubik3d_f);
        lastPressTime_1_button = time(0);
    }
    if (GetKeyState('2') < 0 && difftime(time(0), lastPressTime_2_button) >= 1) {
        cubik3d_lu_rotate(cubik3d_f);
        lastPressTime_2_button = time(0);
    }
    //cubik3d_dl_rotate
    if (GetKeyState('3') < 0 && difftime(time(0), lastPressTime_3_button) >= 1) {
        cubik3d_dl_rotate(cubik3d_f);
        lastPressTime_3_button = time(0);
    }
    if (GetKeyState('4') < 0 && difftime(time(0), lastPressTime_4_button) >= 1) {
        cubik3d_ul_rotate(cubik3d_f);
        lastPressTime_4_button = time(0);
    }
    if (GetKeyState('5') < 0 && difftime(time(0), lastPressTime_5_button) >= 1) {
        cubik3d_fs_rotate(cubik3d_f);
        lastPressTime_5_button = time(0);
    }
    if (GetKeyState('6') < 0 && difftime(time(0), lastPressTime_6_button) >= 1) {
        cubik3d_bs_rotate(cubik3d_f);
        lastPressTime_6_button = time(0);
    }
    if (GetKeyState('7') < 0 && difftime(time(0), lastPressTime_7_button) >= 1) {
        shuffle(cubik3d_f, rememberMoves);
        lastPressTime_7_button = time(0);
    }
    if (GetKeyState('8') < 0 && difftime(time(0), lastPressTime_8_button) >= 2) {
        fix_cube(cubik3d_f, rememberMoves);
        lastPressTime_8_button = time(0);
    }
    if (speed != 0) {
        pos.x += sin(angle) * speed;
        pos.y += cos(angle) * speed;
    }

    glRotatef(-Xalfa, 1, 0, 0);
    glRotatef(-Zalfa, 0, 0, 1);
    glTranslatef(-pos.x, -pos.y, -3);
}

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

void EnableOpenGL(HWND hwnd, HDC *, HGLRC *);

void DisableOpenGL(HWND, HDC, HGLRC);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1280,
                          1280,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);
    //glLoadIdentity();
    // glOrtho(-2, 2, -2, 2, -1, 1);
    glFrustum(-1, 1, -1, 1, 2, 10000);
    glEnable(GL_DEPTH_TEST);
    /* program main loop */
    init_cubik3d(cubik3d);
    init_mapColors();
    while (!bQuit) {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT) {
                bQuit = TRUE;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix();
            MoveCamera(cubik3d);
            ShowWorld(cubik3d);
            glPopMatrix();

            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep(1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            PostQuitMessage(0);
            break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN: {
            switch (wParam) {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                    break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC *hDC, HGLRC *hRC) {
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}


void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

float randomNUM() {
    int x = rand() % 1000;
    auto y = static_cast<float>(x);
    return y / 1000;
}

/*int main() {
    std::cout << randomNUM();
}*/
