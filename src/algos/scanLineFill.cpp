#include<iostream>
#include<vector>
#include<algorithm>

#include "utils.h"
#include "graphics_interface.h"

void scanLineFill(GraphicsInterface* graphics, std::vector<Point*> vertices, char color) {

    int miny = vertices[0]->y, maxy = vertices[0]->y;
    for (Point* point : vertices) {
        miny = std::min(miny, point->y);
        maxy = std::max(maxy, point->y);
    }


    for (int y = miny; y <= maxy; ++y) {
        std::vector<int> intersections;
        for (int i = 0; i < vertices.size(); ++i) {
            Point* p1 = vertices[i];
            Point* p2 = vertices[(i + 1) % vertices.size()];

            if ((p1->y <= y && y < p2->y) || (p1->y > y && y >= p2->y)) {
                if (p1->x == p2->x) {
                    intersections.push_back(p1->x);
                }
                else {
                    float m = ((p2->y * 1.0 - p1->y) / (p2->x - p1->x));
                    int x = ((y - p1->y) / m) + p1->x;
                    intersections.push_back(x);
                }
            }
        }

        sort(intersections.begin(), intersections.end());

        for (int i = 0; i < intersections.size(); i += 2) {
            for (int x = intersections[i]; x < intersections[i + 1]; ++x) {
                graphics->putPixel(x, y, color);
            }
        }

    }

}