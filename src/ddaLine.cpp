#include<iostream>

#include "utils.h"
#include "graphics_interface.h"

void ddaLine(GraphicsInterface* graphics, Point* p1, Point* p2) {

    int xdiff = p2->x - p1->x;
    int ydiff = p2->y - p1->y;

    int steps = std::max(std::abs(xdiff), std::abs(ydiff));

    float xinc = (xdiff * 1.0) / steps;
    float yinc = (ydiff * 1.0) / steps;

    float xi = p1->x;
    float yi = p1->y;


    for (int i = 0; i < steps; ++i) {
        graphics->putPixel((int)xi, (int)yi, '*');
        xi += xinc;
        yi += yinc;
    }

}
