#include<iostream>
#include<utility>

#include "utils.h"
#include "graphics_interface.h"


int getPointCode(Point* point, Point* SCREEN_MIN, Point* SCREEN_MAX) {
    int code = 0;

    if (point->y < SCREEN_MIN->y) {
        code |= 8;
    }
    if (point->y > SCREEN_MAX->y) {
        code |= 4;
    }
    if (point->x < SCREEN_MIN->x) {
        code |= 2;
    }
    if (point->x > SCREEN_MAX->x) {
        code |= 1;
    }

    return code;
}

Point* getIntersectionPoint(Point* p1, Point* p2, Point* SCREEN_MIN, Point* SCREEN_MAX, int code) {
    Point* intersectionPoint = new Point(0, 0);

    if (code & 8) {
        // Top
        intersectionPoint->y = SCREEN_MIN->y;
        intersectionPoint->x = p1->x + ((p2->x - p1->x * 1.0) / (p2->y - p1->y)) * (SCREEN_MIN->y - p1->y);
    }
    else if (code & 4) {
        // Bottom
        intersectionPoint->y = SCREEN_MAX->y;
        intersectionPoint->x = p1->x + ((p2->x - p1->x * 1.0) / (p2->y - p1->y)) * (SCREEN_MAX->y - p1->y);
    }
    else if (code & 2) {
        // Left
        intersectionPoint->x = SCREEN_MIN->x;
        intersectionPoint->y = p1->y + ((p2->y - p1->y * 1.0) / (p2->x - p1->x)) * (SCREEN_MIN->x - p1->x);
    }
    else if (code & 1) {
        // Right
        intersectionPoint->x = SCREEN_MAX->x;
        intersectionPoint->y = p1->y + ((p2->y - p1->y * 1.0) / (p2->x - p1->x)) * (SCREEN_MAX->x - p1->x);
    }

    return intersectionPoint;
}

std::pair<Point*, Point*> cohenSutherlandLineClipping(std::pair<Point*, Point*>& line, Point* SCREEN_MIN, Point* SCREEN_MAX) {
    std::pair<Point*, Point*> clippedLine = { new Point(line.first), new Point(line.second) };

    int p1Code = getPointCode(line.first, SCREEN_MIN, SCREEN_MAX);
    int p2Code = getPointCode(line.second, SCREEN_MIN, SCREEN_MAX);

    while (true) {
        if (!(p1Code | p2Code)) {
            // completely inside
            break;
        }
        else if (p1Code & p2Code) {
            // completely outside
            clippedLine.first = new Point(0, 0);
            clippedLine.second = new Point(0, 0);
            return clippedLine;
        }
        else {
            // partially inside
            if (p1Code) {
                // p1 is outside
                clippedLine.first = getIntersectionPoint(clippedLine.first, clippedLine.second, SCREEN_MIN, SCREEN_MAX, p1Code);
                p1Code = getPointCode(clippedLine.first, SCREEN_MIN, SCREEN_MAX);
            }
            else {
                // p2 is outside
                clippedLine.second = getIntersectionPoint(clippedLine.first, clippedLine.second, SCREEN_MIN, SCREEN_MAX, p2Code);
                p2Code = getPointCode(clippedLine.second, SCREEN_MIN, SCREEN_MAX);
            }
        }
    }

    return clippedLine;
}
