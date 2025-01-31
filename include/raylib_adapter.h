#ifndef RAYLIB_ADAPTER_H
#define RAYLIB_ADAPTER_H

#include <raylib.h>

#include "graphics_interface.h"

class RaylibAdapter : public GraphicsInterface {
public:
    RaylibAdapter(int width, int height);

    void init() override;
    void clearScreen();
    void putPixel(int x, int y, char color) override;
    char getPixel(int x, int y) override;
    Color colorToRaylibColor(char color);
};

#endif