#ifndef UTILITY_H
#define UTILITY_H

#include<vector>
#include<utility>

#include "graphics_interface.h"

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {};
    Point(Point& point) : x(point.x), y(point.y) {};
    Point(Point* point);
    Point(int x, int y);
    Point(std::pair<int, int> pair);
    bool operator<(Point* otherPoint);
    bool operator>(Point* otherPoint);
};


class Polygon {
private:
    std::vector<Point*> vertices;
public:
    void addPoint(Point* p);
    void draw(GraphicsInterface* graphics, char color);
    void fill(GraphicsInterface* graphics, char color);
};

#endif