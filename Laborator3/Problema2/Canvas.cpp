#include "Canvas.h"
#include <cmath>
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height)  {
    lat = width;
    inal = height;
    canvas = new char* [inal];
    for (int i = 0; i < inal; ++i) {
        canvas[i] = new char[lat];
        for (int j = 0; j < lat; ++j) {
            canvas[i][j] = ' ';
        }
    }
}



void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < inal; ++i) {
        for (int j = 0; j < lat; ++j) {
            if (pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2)) {
                canvas[i][j] = ch;
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    ray -= 1;
    for (int i = y - ray; i <= y + ray; ++i) {
        for (int j = x - ray; j <= x + ray; ++j) {
            if (pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2)) {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            if (i == top || i == bottom || j == left || j == right) {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    left++;
    top++;
    right--;
    bottom--;
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < lat && y >= 0 && y < inal) {
        canvas[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        SetPoint(x1, y1, ch);
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    SetPoint(x2, y2, ch); 
}

void Canvas::Print() {
    for (int i = 0; i < inal; ++i) {
        for (int j = 0; j < lat; ++j) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < inal; ++i) {
        for (int j = 0; j < lat; ++j) {
            canvas[i][j] = ' ';
        }
    }
}
