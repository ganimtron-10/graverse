#ifndef GRAPHICS_INTERFACE_H
#define GRAPHICS_INTERFACE_H

#include <thread>
#include <chrono>

class GraphicsInterface {
public:

    GraphicsInterface(int width, int height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {}
    virtual ~GraphicsInterface() = default;

    int getScreenWidth() const { return  SCREEN_WIDTH; }
    int getScreenHeight() const { return SCREEN_HEIGHT; }

    virtual void init() = 0;
    virtual void putPixel(int x, int y, char color) = 0;
    virtual char getPixel(int x, int y) = 0;
    void sleep(int millisecond) {
        std::this_thread::sleep_for(std::chrono::milliseconds(millisecond));
    };


protected:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    bool animate = true;
};

#endif