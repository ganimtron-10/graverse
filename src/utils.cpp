#include "utils.h"
#include "algo.h"

Point::Point(Point* point) {
    this->x = point->x;
    this->y = point->y;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(std::pair<int, int> pair) {
    this->x = pair.first;
    this->y = pair.second;
}

bool Point::operator<(Point* otherPoint) {
    if (this->x < otherPoint->x) {
        return true;
    }
    else {
        return this->y < otherPoint->y;
    }
}

bool Point::operator>(Point* otherPoint) {
    if (this->x > otherPoint->x) {
        return true;
    }
    else {
        return this->y > otherPoint->y;
    }
}

// Polygon

void Polygon::addPoint(Point* p) {
    vertices.push_back(p);
}

void Polygon::draw(GraphicsInterface* graphics, char color) {
    for (int i = 0; i < vertices.size(); ++i) {
        int j = (i + 1) % vertices.size();
        ddaLine(graphics, vertices[i], vertices[j], color);
    }
}

void Polygon::fill(GraphicsInterface* graphics, char color) {
    scanLineFill(graphics, vertices, color);
}