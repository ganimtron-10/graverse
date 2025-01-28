#include "utils.h"

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