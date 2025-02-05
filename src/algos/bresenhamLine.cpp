#include<iostream>

#include "utils.h"
#include "graphics_interface.h"

void bresenhamLine(GraphicsInterface* graphics, Point* p1, Point* p2, char color) {

    int dx = p2->x - p1->x;
    int dy = p2->y - p1->y;

    int d = 2 * dy - dx;

    int xi = p1->x, yi = p1->y;

    while (xi < p2->x) {

        graphics->putPixel(xi, yi, color);

        if (d >= 0) {
            yi += 1;
            d = d + 2 * dy - 2 * dx;
        }
        else {
            d = d + 2 * dy;
        }
        xi += 1;
    }


}

