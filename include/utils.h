#ifndef COMMON_H
#define COMMON_H

#include<utility>

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


#endif