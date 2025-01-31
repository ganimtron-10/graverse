#include "terminal_adapter.h"

TerminalAdapter::TerminalAdapter(int width, int height) : GraphicsInterface(width, height) {}

void TerminalAdapter::init() {
    animate = true;
    screen.resize(SCREEN_HEIGHT);
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        screen[i] = std::vector<char>(SCREEN_WIDTH, ' ');
    }
}

void TerminalAdapter::clearScreen() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

void TerminalAdapter::printScreen() {
    system("clear"); // system("cls");
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            std::cout << screen[i][j];
        }
        std::cout << std::endl;
    }
}

void TerminalAdapter::putPixel(int x, int y, char color = '*') {
    if (x < 0 or y < 0 or x >= SCREEN_WIDTH or y >= SCREEN_HEIGHT) {
        return;
    }

    screen[y][x] = color;
    if (animate) {
        printScreen();
        sleep(100);
    }
}

char TerminalAdapter::getPixel(int x, int y) {
    if (x < 0 or y < 0 or x >= SCREEN_WIDTH or y >= SCREEN_HEIGHT) {
        return '\0';
    }

    return screen[y][x];
}

