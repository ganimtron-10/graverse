#ifndef TERMINAL_ADAPTER_H
#define TERMINAL_ADAPTER_H

#include <iostream>
#include <vector>

#include "graphics_interface.h"

class TerminalAdapter : public GraphicsInterface {
public:
    TerminalAdapter(int width, int height);

    void init() override;
    void clearScreen();
    void printScreen();
    void putPixel(int x, int y, char color) override;
    char getPixel(int x, int y) override;

private:
    std::vector<std::vector<char>> screen;
};

#endif