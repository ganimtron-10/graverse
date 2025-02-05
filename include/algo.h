#ifndef ALGO_H
#define ALGO_H

#include "graphics_interface.h"
#include "utils.h"

void ddaLine(GraphicsInterface* graphics, Point* p1, Point* p2, char color);
void bresenhamLine(GraphicsInterface* graphics, Point* p1, Point* p2, char color);
void scanLineFill(GraphicsInterface* graphics, std::vector<Point*> vertices, char color);

#endif