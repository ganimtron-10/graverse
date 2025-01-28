#include "terminal_adapter.h"

std::vector<std::vector<char>> TerminalAdapter::screen(MAX_Y, std::vector<char>(MAX_X, ' '));

void TerminalAdapter::init() {
    screen.resize(MAX_Y);
    for (int i = 0; i < MAX_Y; i++) {
        screen[i] = std::vector<char>(MAX_X, ' ');
    }
}

void TerminalAdapter::clearScreen() {
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            screen[i][j] = ' ';
        }
    }
}

void TerminalAdapter::printScreen() {
    system("clear"); // system("cls");
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            std::cout << screen[i][j];
        }
        std::cout << std::endl;
    }
}

void TerminalAdapter::putPixel(int x, int y, char color = '*') {
    if (x < 0 or y < 0 or x >= MAX_X or y >= MAX_Y) {
        return;
    }

    screen[y][x] = color;
    if (animate) {
        printScreen();
        sleep(100);
    }
}

char TerminalAdapter::getPixel(int x, int y) {
    if (x < 0 or y < 0 or x >= MAX_X or y >= MAX_Y) {
        return '\0';
    }

    return screen[y][x];
}

void TerminalAdapter::sleep(int millisecond) {
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecond));
}

