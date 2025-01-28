#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "graphics_interface.h"

class TerminalAdapter : public GraphicsInterface {
public:
    static const int MAX_Y = 40;
    static const int MAX_X = 150;
    static std::vector<std::vector<char>> screen;
    bool animate = true;

    void init() override;
    void clearScreen();
    void printScreen();
    void putPixel(int x, int y, char color) override;
    char getPixel(int x, int y) override;
    void sleep(int millisecond);
};

#endif