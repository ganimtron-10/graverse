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

class Shape2D {
public:
    virtual void translate(std::pair<int, int> offset) = 0;
    virtual void scale(std::pair<float, float> scale) = 0;
    virtual void rotate(int rotation) = 0;
};

class Polygon : public Shape2D {
private:
    std::vector<Point*> vertices;
    std::vector<Point*> verticesCopy;
public:
    void addPoint(Point* p);
    void draw(GraphicsInterface* graphics, char color);
    void fill(GraphicsInterface* graphics, char color);

    void translate(std::pair<int, int> offset) override;
    void scale(std::pair<float, float> scale) override;
    void rotate(int rotation) override;

    void copyVertices();
    void resetVertices();
};

#endif