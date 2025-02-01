#include "graphics_factory.h"
#include "algo.h"
#include "utils.h"


void createConcavePolygon(GraphicsInterface* graphics, char color) {

    std::vector<std::vector<int>> points = {
        {17,18},
        {11,19},
        {14,12},
        {4,14},
        {8,7},
        {3,4},
        {11,0},
        {15,3},
        {22,1},
        {24,5},
        {29,0},
        {38,4},
        {36,7},
        {34,9},
        {36,12},
        {37,18},
        {31,16},
        {30,20},
        {25,17},
        {25,37},
        {19,37}
    };

    Polygon* poly = new Polygon();
    for (std::vector<int> point : points) {
        // cout << point[0] << " " << point[1] << endl;
        poly->addPoint(new Point{ point[0] * 10, point[1] * 10 });
    }
    poly->draw(graphics, color);
    poly->fill(graphics, color);
}

int main() {

    auto graphics = createGraphics("raylib", 500, 500);
    // auto graphics = createGraphics("terminal", 150, 40);

    if (graphics) {
        createConcavePolygon(graphics.get(), 'W');
    }

    return 0;
}

