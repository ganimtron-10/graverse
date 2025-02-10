#include <raylib_adapter.h>
#include<iostream>


RaylibAdapter::RaylibAdapter(int width, int height) : GraphicsInterface(width, height) {}

void RaylibAdapter::init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib window");
    SetTargetFPS(60);
}

void RaylibAdapter::clearScreen() {
    ClearBackground(BLACK);
}

Color RaylibAdapter::colorToRaylibColor(char color) {
    switch (color) {
    case 'R': return RED;
    case 'G': return GREEN;
    case 'B': return BLUE;
    case 'Y': return YELLOW;
    case 'M': return MAGENTA;
    case 'K': return BLACK;
    case 'W': return WHITE;
    default: return WHITE; // Default color
    }
}

void RaylibAdapter::putPixel(int x, int y, char color) {
    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) {
        return;
    }

    DrawPixel(x, y, colorToRaylibColor(color));
    if (animate) {
        BeginDrawing();
        DrawPixel(x, y, colorToRaylibColor(color));
        EndDrawing();
        sleep(5);
    }
}

char RaylibAdapter::getPixel(int x, int y) {
    // putting default W as return value for time being
    return 'W';
}

