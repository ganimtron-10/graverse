#ifndef GRAPHICS_INTERFACE_H
#define GRAPHICS_INTERFACE_H

class GraphicsInterface {
public:
    bool animate = false;
    virtual void init() = 0;
    virtual void putPixel(int x, int y, char color) = 0;
    virtual char getPixel(int x, int y) = 0;
};

#endif