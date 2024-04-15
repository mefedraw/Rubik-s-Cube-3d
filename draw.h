#ifndef DRAW_H
#define DRAW_H
#include "draw2.h"
#include <thread>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

enum colors {
    red = 1,
    green,
    blue,
    pink,
    yellow,
    white,
    black
};

struct cubeEdge {
    colors l;
    colors sa;
    colors sf;

    cubeEdge() {
        l = black;
        sa = black;
        sf = black;
    }
};

void ShowWorld(vector<vector<vector<cubeEdge> > > &cubik3d);

void init_cubik3d(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    ///TODO: first layer
    cubik3d_f[0][0][0].l = white;
    cubik3d_f[0][0][0].sf = red;
    cubik3d_f[0][0][0].sa = blue;

    cubik3d_f[0][0][1].l = white;
    cubik3d_f[0][0][1].sf = red;

    cubik3d_f[0][0][2].l = white;
    cubik3d_f[0][0][2].sf = red;
    cubik3d_f[0][0][2].sa = green;

    cubik3d_f[0][1][0].l = white;
    cubik3d_f[0][1][0].sa = blue;

    cubik3d_f[0][2][0].l = white;
    cubik3d_f[0][2][0].sf = pink;
    cubik3d_f[0][2][0].sa = blue;

    cubik3d_f[0][1][2].l = white;
    cubik3d_f[0][1][2].sa = green;

    cubik3d_f[0][2][2].l = white;
    cubik3d_f[0][2][2].sf = pink;
    cubik3d_f[0][2][2].sa = green;

    cubik3d_f[0][2][1].l = white;
    cubik3d_f[0][2][1].sf = pink;

    cubik3d_f[0][1][1].l = white;
    ///TODO: end of first layer

    // TODO: second layer
    cubik3d_f[1][0][0].sf = red;
    cubik3d_f[1][0][0].sa = blue;

    cubik3d_f[1][0][1].sf = pink;

    cubik3d_f[1][0][2].sf = pink;
    cubik3d_f[1][0][2].sa = blue;

    cubik3d_f[1][1][0].sa = blue;

    cubik3d_f[1][0][2].sf = red;
    cubik3d_f[1][0][2].sa = green;

    cubik3d_f[1][1][2].sa = blue;

    cubik3d_f[1][2][0].sf = pink;
    cubik3d_f[1][2][0].sa = blue;

    cubik3d_f[1][2][2].sf = pink;
    cubik3d_f[1][2][2].sa = blue;

    cubik3d_f[1][2][2].sf = pink;
    cubik3d_f[1][2][2].sa = green;

    cubik3d_f[1][2][1].sf = red;
    /// TODO: end of second layer


    /// TODO: third layer
    cubik3d_f[2][0][0].l = yellow;
    cubik3d_f[2][0][0].sf = red;
    cubik3d_f[2][0][0].sa = blue;

    cubik3d_f[2][0][1].l = yellow;
    cubik3d_f[2][0][1].sf = red;

    cubik3d_f[2][0][2].l = yellow;
    cubik3d_f[2][0][2].sf = pink;
    cubik3d_f[2][0][2].sa = blue;

    cubik3d_f[2][1][0].l = yellow;
    cubik3d_f[2][1][0].sa = blue;

    cubik3d_f[2][2][0].l = yellow;
    cubik3d_f[2][2][0].sa = blue;
    cubik3d_f[2][2][0].sf = pink;

    cubik3d_f[2][0][2].l = yellow;
    cubik3d_f[2][0][2].sf = red;
    cubik3d_f[2][0][2].sa = green;

    cubik3d_f[2][1][2].l = yellow;
    cubik3d_f[2][1][2].sa = green;

    cubik3d_f[2][2][2].l = yellow;
    cubik3d_f[2][2][2].sf = pink;
    cubik3d_f[2][2][2].sa = green;

    cubik3d_f[2][2][1].l = yellow;
    cubik3d_f[2][2][1].sf = pink;

    cubik3d_f[2][1][1].l = yellow;
}

void cubik3d_ru_rotate(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    cubeEdge temp002 = cubik3d_f[0][0][2];
    cubeEdge temp102 = cubik3d_f[1][0][2];
    cubeEdge temp202 = cubik3d_f[2][0][2];

    cubik3d_f[0][0][2].l = cubik3d_f[2][0][2].sf;
    cubik3d_f[0][0][2].sa = cubik3d_f[2][0][2].sa;
    cubik3d_f[0][0][2].sf = cubik3d_f[2][0][2].l;

    cubik3d_f[1][0][2].sa = cubik3d_f[2][1][2].sa;
    cubik3d_f[1][0][2].sf = cubik3d_f[2][1][2].l;

    cubik3d_f[2][0][2].l = cubik3d_f[2][2][2].sf;
    cubik3d_f[2][0][2].sa = cubik3d_f[2][2][2].sa;
    cubik3d_f[2][0][2].sf = cubik3d_f[2][2][2].l;

    cubik3d_f[2][1][2].sa = cubik3d_f[1][2][2].sa;
    cubik3d_f[2][1][2].l = cubik3d_f[1][2][2].sf;

    cubik3d_f[2][2][2].l = cubik3d_f[0][2][2].sf;
    cubik3d_f[2][2][2].sa = cubik3d_f[0][2][2].sa;
    cubik3d_f[2][2][2].sf = cubik3d_f[0][2][2].l;

    cubik3d_f[1][2][2].sa = cubik3d_f[0][1][2].sa;
    cubik3d_f[1][2][2].sf = cubik3d_f[0][1][2].l;

    cubik3d_f[0][2][2].l = temp002.sf;
    cubik3d_f[0][2][2].sa = temp002.sa;
    cubik3d_f[0][2][2].sf = temp002.l;

    cubik3d_f[0][1][2].sa = temp102.sa;
    cubik3d_f[0][1][2].l = temp102.sf;
}

void cubik3d_lu_rotate(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    cubeEdge temp000 = cubik3d_f[0][0][0];
    cubeEdge temp100 = cubik3d_f[1][0][0];

    cubik3d_f[0][0][0].l = cubik3d_f[2][0][0].sf;
    cubik3d_f[0][0][0].sa = cubik3d_f[2][0][0].sa;
    cubik3d_f[0][0][0].sf = cubik3d_f[2][0][0].l;

    cubik3d_f[1][0][0].sa = cubik3d_f[2][1][0].sa;
    cubik3d_f[1][0][0].sf = cubik3d_f[2][1][0].l;

    cubik3d_f[2][0][0].l = cubik3d_f[2][2][0].sf;
    cubik3d_f[2][0][0].sa = cubik3d_f[2][2][0].sa;
    cubik3d_f[2][0][0].sf = cubik3d_f[2][2][0].l;

    cubik3d_f[2][1][0].sa = cubik3d_f[1][2][0].sa;
    cubik3d_f[2][1][0].l = cubik3d_f[1][2][0].sf;

    cubik3d_f[2][2][0].l = cubik3d_f[0][2][0].sf;
    cubik3d_f[2][2][0].sa = cubik3d_f[0][2][0].sa;
    cubik3d_f[2][2][0].sf = cubik3d_f[0][2][0].l;

    cubik3d_f[1][2][0].sa = cubik3d_f[0][1][0].sa;
    cubik3d_f[1][2][0].sf = cubik3d_f[0][1][0].l;

    cubik3d_f[0][2][0].l = temp000.sf;
    cubik3d_f[0][2][0].sa = temp000.sa;
    cubik3d_f[0][2][0].sf = temp000.l;

    cubik3d_f[0][1][0].sa = temp100.sa;
    cubik3d_f[0][1][0].l = temp100.sf;
}

void cubik3d_dl_rotate(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    cubeEdge temp000 = cubik3d_f[0][0][0];
    cubeEdge temp001 = cubik3d_f[0][0][1];

    cubik3d_f[0][0][0].l = cubik3d_f[0][2][0].l;
    cubik3d_f[0][0][0].sa = cubik3d_f[0][2][0].sf;
    cubik3d_f[0][0][0].sf = cubik3d_f[0][2][0].sa;

    cubik3d_f[0][0][1].sf = cubik3d_f[0][1][0].sa;
    cubik3d_f[0][0][1].l = cubik3d_f[0][1][0].l;

    cubeEdge temp002 = cubik3d_f[0][0][2];
    cubik3d_f[0][0][2].l = temp000.l;
    cubik3d_f[0][0][2].sa = temp000.sf;
    cubik3d_f[0][0][2].sf = temp000.sa;

    cubeEdge temp012 = cubik3d_f[0][1][2];
    cubik3d_f[0][1][2].sa = temp001.sf;
    cubik3d_f[0][1][2].l = temp001.l;

    cubeEdge temp022 = cubik3d_f[0][2][2];
    cubik3d_f[0][2][2].l = temp002.l;
    cubik3d_f[0][2][2].sa = temp002.sf;
    cubik3d_f[0][2][2].sf = temp002.sa;

    cubeEdge temp021 = cubik3d_f[0][2][1];
    cubik3d_f[0][2][1].sf = temp012.sa;
    cubik3d_f[0][2][1].l = temp012.l;

    cubik3d_f[0][2][0].l = temp022.l;
    cubik3d_f[0][2][0].sa = temp022.sf;
    cubik3d_f[0][2][0].sf = temp022.sa;

    cubik3d_f[0][1][0].sa = temp021.sf;
    cubik3d_f[0][1][0].l = temp021.l;
}

void cubik3d_ul_rotate(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    cubeEdge temp000 = cubik3d_f[2][0][0];
    cubeEdge temp001 = cubik3d_f[2][0][1];

    cubik3d_f[2][0][0].l = cubik3d_f[2][2][0].l;
    cubik3d_f[2][0][0].sa = cubik3d_f[2][2][0].sf;
    cubik3d_f[2][0][0].sf = cubik3d_f[2][2][0].sa;

    cubik3d_f[2][0][1].sf = cubik3d_f[2][1][0].sa;
    cubik3d_f[2][0][1].l = cubik3d_f[2][1][0].l;

    cubeEdge temp002 = cubik3d_f[2][0][2];
    cubik3d_f[2][0][2].l = temp000.l;
    cubik3d_f[2][0][2].sa = temp000.sf;
    cubik3d_f[2][0][2].sf = temp000.sa;

    cubeEdge temp012 = cubik3d_f[2][1][2];
    cubik3d_f[2][1][2].sa = temp001.sf;
    cubik3d_f[2][1][2].l = temp001.l;

    cubeEdge temp022 = cubik3d_f[2][2][2];
    cubik3d_f[2][2][2].l = temp002.l;
    cubik3d_f[2][2][2].sa = temp002.sf;
    cubik3d_f[2][2][2].sf = temp002.sa;

    cubeEdge temp021 = cubik3d_f[2][2][1];
    cubik3d_f[2][2][1].sf = temp012.sa;
    cubik3d_f[2][2][1].l = temp012.l;

    cubik3d_f[2][2][0].l = temp022.l;
    cubik3d_f[2][2][0].sa = temp022.sf;
    cubik3d_f[2][2][0].sf = temp022.sa;

    cubik3d_f[2][1][0].sa = temp021.sf;
    cubik3d_f[2][1][0].l = temp021.l;
}

void cubik3d_fs_rotate(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    cubeEdge temp000 = cubik3d_f[0][0][0];
    cubeEdge temp100 = cubik3d_f[1][0][0];

    cubik3d_f[0][0][0].l = cubik3d_f[2][0][0].sa;
    cubik3d_f[0][0][0].sa = cubik3d_f[2][0][0].l;
    cubik3d_f[0][0][0].sf = cubik3d_f[2][0][0].sf;

    cubik3d_f[1][0][0].sa = cubik3d_f[2][0][1].l;
    cubik3d_f[1][0][0].sf = cubik3d_f[2][0][1].sf;

    cubik3d_f[2][0][0].l = cubik3d_f[2][0][2].sa;
    cubik3d_f[2][0][0].sa = cubik3d_f[2][0][2].l;
    cubik3d_f[2][0][0].sf = cubik3d_f[2][0][2].sf;

    cubik3d_f[2][0][1].l = cubik3d_f[1][0][2].sa;
    cubik3d_f[2][0][1].sf = cubik3d_f[1][0][2].sf;

    cubik3d_f[2][0][2].l = cubik3d_f[0][0][2].sa;
    cubik3d_f[2][0][2].sa = cubik3d_f[0][0][2].l;
    cubik3d_f[2][0][2].sf = cubik3d_f[0][0][2].sf;

    cubik3d_f[1][0][2].sa = cubik3d_f[0][0][1].l;
    cubik3d_f[1][0][2].sf = cubik3d_f[0][0][1].sf;

    cubik3d_f[0][0][2].l = temp000.sa;
    cubik3d_f[0][0][2].sa = temp000.l;
    cubik3d_f[0][0][2].sf = temp000.sf;

    cubik3d_f[0][0][1].l = temp100.sa;
    cubik3d_f[0][0][1].sf = temp100.sf;
}

void cubik3d_bs_rotate(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    cubeEdge temp020 = cubik3d_f[0][2][0];
    cubeEdge temp120 = cubik3d_f[1][2][0];

    cubik3d_f[0][2][0].l = cubik3d_f[2][2][0].sa;
    cubik3d_f[0][2][0].sa = cubik3d_f[2][2][0].l;
    cubik3d_f[0][2][0].sf = cubik3d_f[2][2][0].sf;

    cubik3d_f[1][2][0].sa = cubik3d_f[2][2][1].l;
    cubik3d_f[1][2][0].sf = cubik3d_f[2][2][1].sf;

    cubik3d_f[2][2][0].l = cubik3d_f[2][2][2].sa;
    cubik3d_f[2][2][0].sa = cubik3d_f[2][2][2].l;
    cubik3d_f[2][2][0].sf = cubik3d_f[2][2][2].sf;

    cubik3d_f[2][2][1].l = cubik3d_f[1][2][2].sa;
    cubik3d_f[2][2][1].sf = cubik3d_f[1][2][2].sf;

    cubik3d_f[2][2][2].l = cubik3d_f[0][2][2].sa;
    cubik3d_f[2][2][2].sa = cubik3d_f[0][2][2].l;
    cubik3d_f[2][2][2].sf = cubik3d_f[0][2][2].sf;

    cubik3d_f[1][2][2].sa = cubik3d_f[0][2][1].l;
    cubik3d_f[1][2][2].sf = cubik3d_f[0][2][1].sf;

    cubik3d_f[0][2][2].l = temp020.sa;
    cubik3d_f[0][2][2].sa = temp020.l;
    cubik3d_f[0][2][2].sf = temp020.sf;

    cubik3d_f[0][2][1].l = temp120.sa;
    cubik3d_f[0][2][1].sf = temp120.sf;
}

unordered_map<int, pair<float, pair<float, float> > > mapColors;

void init_mapColors() {
    mapColors[1] = {1, {0, 0}};
    mapColors[2] = {0, {1, 0}};
    mapColors[3] = {0, {0, 1}};
    mapColors[4] = {1, {0.5, 1}};
    mapColors[5] = {1, {1, 0}};
    mapColors[6] = {1, {1, 1}};
    mapColors[7] = {0, {0, 0}};
}

auto take_color(colors clr) {
    return mapColors[clr];
}

void display_ru(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    auto c = take_color(cubik3d_f[0][0][2].sf);
    drawStandingSquare2(9.5, 10, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][2].sa);
    drawStandingSquare1(10, 9.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][2].l);
    drawSquare(10, 10, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][0][2].sf);
    drawStandingSquare2(9.5, 10, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[1][0][2].sa);
    drawStandingSquare1(10, 9.5, 5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][0][2].sf);
    drawStandingSquare2(9.5, 10, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][2].sa);
    drawStandingSquare1(10, 9.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][2].l);
    drawSquare(10, 10, 6.5, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][1][2].sa);
    drawStandingSquare1(11, 9.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][1][2].l);
    drawSquare(11, 10, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][1][2].l);
    drawSquare(11, 10, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][1][2].sa);
    drawStandingSquare1(11, 9.5, 6, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][2][2].sf);
    drawStandingSquare2(12.5, 10, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][2].sa);
    drawStandingSquare1(12, 9.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][2].l);
    drawSquare(12, 10, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][2][2].sf);
    drawStandingSquare2(12.5, 10, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[1][2][2].sa);
    drawStandingSquare1(12, 9.5, 5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][2].sf);
    drawStandingSquare2(12.5, 10, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][2].sa);
    drawStandingSquare1(12, 9.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][2].l);
    drawSquare(12, 10, 6.5, 1, c.first, c.second.first, c.second.second);
}

void display_lu(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    auto c = take_color(cubik3d_f[0][0][0].sf);
    drawStandingSquare2(9.5, 12, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][0].sa);
    drawStandingSquare1(10, 12.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][0].l);
    drawSquare(10, 12, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][0][0].sf);
    drawStandingSquare2(9.5, 12, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[1][0][0].sa);
    drawStandingSquare1(10, 12.5, 5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][0][0].sf);
    drawStandingSquare2(9.5, 12, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][0].sa);
    drawStandingSquare1(10, 12.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][0].l);
    drawSquare(10, 12, 6.5, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][1][0].sa);
    drawStandingSquare1(11, 12.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][1][0].l);
    drawSquare(11, 12, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][1][0].l);
    drawSquare(11, 12, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][1][0].sa);
    drawStandingSquare1(11, 12.5, 6, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][2][0].sf);
    drawStandingSquare2(12.5, 12, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][0].sa);
    drawStandingSquare1(12, 12.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][0].l);
    drawSquare(12, 12, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][2][0].sf);
    drawStandingSquare2(12.5, 12, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[1][2][0].sa);
    drawStandingSquare1(12, 12.5, 5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][0].sf);
    drawStandingSquare2(12.5, 12, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][0].sa);
    drawStandingSquare1(12, 12.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][0].l);
    drawSquare(12, 12, 6.5, 1, c.first, c.second.first, c.second.second);
}

void display_dl(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    auto c = take_color(cubik3d_f[0][0][2].sf);
    drawStandingSquare2(9.5, 10, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][1].sf);
    drawStandingSquare2(9.5, 11, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][0].sf);
    drawStandingSquare2(9.5, 12, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][2][2].sf);
    drawStandingSquare2(12.5, 10, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][1].sf);
    drawStandingSquare2(12.5, 11, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][0].sf);
    drawStandingSquare2(12.5, 12, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][2][2].sa);
    drawStandingSquare1(12, 9.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][1][2].sa);
    drawStandingSquare1(11, 9.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][2].sa);
    drawStandingSquare1(10, 9.5, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][2][0].sa);
    drawStandingSquare1(12, 12.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][1][0].sa);
    drawStandingSquare1(11, 12.5, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][1][0].sa);
    drawStandingSquare1(10, 12.5, 4, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][0][0].l);
    drawSquare(10, 12, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][1].l);
    drawSquare(10, 11, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][2].l);
    drawSquare(10, 10, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][1][2].l);
    drawSquare(11, 10, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][1][0].l);
    drawSquare(11, 12, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][2][0].l);
    drawSquare(12, 12, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][1].l);
    drawSquare(12, 11, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][2].l);
    drawSquare(12, 10, 3.5, 1, c.first, c.second.first, c.second.second);
}

void display_ul(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    auto c = take_color(cubik3d_f[2][0][2].sf);
    drawStandingSquare2(9.5, 10, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][1].sf);
    drawStandingSquare2(9.5, 11, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][0].sf);
    drawStandingSquare2(9.5, 12, 6, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][2].sf);
    drawStandingSquare2(12.5, 10, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][1].sf);
    drawStandingSquare2(12.5, 11, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][0].sf);
    drawStandingSquare2(12.5, 12, 6, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][2].sa);
    drawStandingSquare1(12, 9.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][1][2].sa);
    drawStandingSquare1(11, 9.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][2].sa);
    drawStandingSquare1(10, 9.5, 6, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][0].sa);
    drawStandingSquare1(12, 12.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][1][0].sa);
    drawStandingSquare1(11, 12.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][1][0].sa);
    drawStandingSquare1(10, 12.5, 6, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[2][0][0].l);
    drawSquare(10, 12, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][1].l);
    drawSquare(10, 11, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][2].l);
    drawSquare(10, 10, 6.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][1][2].l);
    drawSquare(11, 10, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][1][0].l);
    drawSquare(11, 12, 6.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][0].l);
    drawSquare(12, 12, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][1].l);
    drawSquare(12, 11, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][2].l);
    drawSquare(12, 10, 6.5, 1, c.first, c.second.first, c.second.second);
}

void display_fs(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    auto c = take_color(cubik3d_f[2][0][0].l);
    drawSquare(10, 12, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][1].l);
    drawSquare(10, 11, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][2].l);
    drawSquare(10, 10, 6.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][0][0].l);
    drawSquare(10, 12, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][1].l);
    drawSquare(10, 11, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][2].l);
    drawSquare(10, 10, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][0][0].sa);
    drawStandingSquare1(10, 12.5, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][0].sa);
    drawStandingSquare1(10, 12.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][0].sa);
    drawStandingSquare1(10, 12.5, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][0][2].sa);
    drawStandingSquare1(10, 9.5, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][2].sa);
    drawStandingSquare1(10, 9.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][2].sa);
    drawStandingSquare1(10, 9.5, 4, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][0][2].sf);
    drawStandingSquare2(9.5, 10, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][1].sf);
    drawStandingSquare2(9.5, 11, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][0][0].sf);
    drawStandingSquare2(9.5, 12, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][0][2].sf);
    drawStandingSquare2(9.5, 10, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[1][0][0].sf);
    drawStandingSquare2(9.5, 12, 5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][0][2].sf);
    drawStandingSquare2(9.5, 10, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][1].sf);
    drawStandingSquare2(9.5, 11, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][0][0].sf);
    drawStandingSquare2(9.5, 12, 6, 1, c.first, c.second.first, c.second.second);
}

void display_bs(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    auto c = take_color(cubik3d_f[2][2][0].l);
    drawSquare(12, 12, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][1].l);
    drawSquare(12, 11, 6.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][2].l);
    drawSquare(12, 10, 6.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[0][2][0].l);
    drawSquare(12, 12, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][1].l);
    drawSquare(12, 11, 3.5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][2].l);
    drawSquare(12, 10, 3.5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][2][0].sa);
    drawStandingSquare1(12, 12.5, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][0].sa);
    drawStandingSquare1(12, 12.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][0].sa);
    drawStandingSquare1(12, 12.5, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][2][2].sa);
    drawStandingSquare1(12, 9.5, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][2].sa);
    drawStandingSquare1(12, 9.5, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][2].sa);
    drawStandingSquare1(12, 9.5, 4, 1, c.first, c.second.first, c.second.second);


    c = take_color(cubik3d_f[0][2][2].sf);
    drawStandingSquare2(12.5, 10, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][1].sf);
    drawStandingSquare2(12.5, 11, 4, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[0][2][0].sf);
    drawStandingSquare2(12.5, 12, 4, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[1][2][2].sf);
    drawStandingSquare2(12.5, 10, 5, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[1][2][0].sf);
    drawStandingSquare2(12.5, 12, 5, 1, c.first, c.second.first, c.second.second);

    c = take_color(cubik3d_f[2][2][2].sf);
    drawStandingSquare2(12.5, 10, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][1].sf);
    drawStandingSquare2(12.5, 11, 6, 1, c.first, c.second.first, c.second.second);
    c = take_color(cubik3d_f[2][2][0].sf);
    drawStandingSquare2(12.5, 12, 6, 1, c.first, c.second.first, c.second.second);
}

void display_cube(vector<vector<vector<cubeEdge> > > &cubik3d_f) {
    drawCenters();
    display_ru(cubik3d_f);
    display_lu(cubik3d_f);
    display_ul(cubik3d_f);
    display_dl(cubik3d_f);
    display_fs(cubik3d_f);
    display_bs(cubik3d_f);
}

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
    glColor3f(1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_QUADS, 0, 4);

    display_cube(cubik3d_f);

    glDisableClientState(GL_VERTEX_ARRAY);
}

auto initiate_move(int moveNum, vector<vector<vector<cubeEdge> > > &cubik3d_f,
                   stack<string> &rememberMoves) -> void {
    if (moveNum == 1) {
        cubik3d_ru_rotate(cubik3d_f);
        rememberMoves.push("ru");
    } else if (moveNum == 2) {
        cubik3d_lu_rotate(cubik3d_f);
        rememberMoves.push("lu");
    } else if (moveNum == 3) {
        cubik3d_fs_rotate(cubik3d_f);
        rememberMoves.push("fs");
    } else if (moveNum == 4) {
        cubik3d_bs_rotate(cubik3d_f);
        rememberMoves.push("bs");
    } else if (moveNum == 5) {
        cubik3d_dl_rotate(cubik3d_f);
        rememberMoves.push("dl");
    } else {
        cubik3d_ul_rotate(cubik3d_f);
        rememberMoves.push("ul");
    }
}


void shuffle(vector<vector<vector<cubeEdge> > > &cubik3d_f, stack<string> &rememberMoves) {
    for (int i = 0; i < 15; i++) {
        int move = (rand() % 6) + 1;
        int times = (rand() % 3);
        for (int j = 0; j < times; j++) {
            initiate_move(move, cubik3d_f, rememberMoves);
        }
    }
}

void solve(vector<vector<vector<cubeEdge> > > &cubik3d_f, stack<string> &rememberMoves) {
    while (!rememberMoves.empty()) {
        string curMove = rememberMoves.top();

        if (curMove == "ru") {
            for (int i = 0; i < 3; i++) {
                cubik3d_ru_rotate(cubik3d_f);
            }
        } else if (curMove == "lu") {
            for (int i = 0; i < 3; i++) {
                cubik3d_lu_rotate(cubik3d_f);
            }
        } else if (curMove == "fs") {
            for (int i = 0; i < 3; i++) {
                cubik3d_fs_rotate(cubik3d_f);
            }
        } else if (curMove == "bs") {
            for (int i = 0; i < 3; i++) {
                cubik3d_bs_rotate(cubik3d_f);
            }
        } else if (curMove == "ul") {
            for (int i = 0; i < 3; i++) {
                cubik3d_ul_rotate(cubik3d_f);
            }
        } else {
            for (int i = 0; i < 3; i++) {
                cubik3d_dl_rotate(cubik3d_f);
            }
        }
        rememberMoves.pop();
        ShowWorld(cubik3d_f);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

#endif //DRAW_H
