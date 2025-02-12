#include "graphics_factory.h"
#include "algo.h"
#include "utils.h"


void polyTranslate(GraphicsInterface* graphics, char color, Polygon* poly)
{
    int offsetValue = 90;

    for (int i = 0; i < offsetValue; i += 5) {
        graphics->clearScreen();
        poly->translate({ i,0 });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }

    for (int i = 0; i < offsetValue; i += 5) {
        graphics->clearScreen();
        poly->translate({ 0,i });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }

    for (int i = 0; i < offsetValue; i += 5) {
        graphics->clearScreen();
        poly->translate({ -i,0 });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }

    for (int i = 0; i < offsetValue; i += 5) {
        graphics->clearScreen();
        poly->translate({ 0,-i });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }

    for (int i = 0; i < offsetValue / 4; i += 5) {
        graphics->clearScreen();
        poly->translate({ i,i });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }


}

void polyScale(GraphicsInterface* graphics, char color, Polygon* poly)
{
    int scaleSteps = 15;
    for (int i = 0; i < scaleSteps; i++) {
        graphics->clearScreen();
        poly->scale({ 1.1,1.1 });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }

    for (int i = 0; i < scaleSteps; i++) {
        graphics->clearScreen();
        poly->scale({ 0.9,0.9 });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }
}

void polyRotate(GraphicsInterface* graphics, char color, Polygon* poly)
{
    poly->copyVertices();
    for (int i = 0; i < 360; i += 10) {
        graphics->clearScreen();
        poly->rotate(i);
        poly->draw(graphics, color);
        graphics->sleep(500);
    }
    poly->resetVertices();

}

void polyRotateCenter(GraphicsInterface* graphics, char color, Polygon* poly)
{
    poly->copyVertices();
    for (int i = 0; i < 360; i += 10) {
        graphics->clearScreen();
        poly->rotate(i);
        poly->translate({ 500,500 });
        poly->draw(graphics, color);
        graphics->sleep(100);
    }
    poly->resetVertices();

}

void createTransformPolygon(GraphicsInterface* graphics, char color) {

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
        poly->addPoint(new Point{ point[0] * 5, point[1] * 5 });
    }

    graphics->setAnimateValue(false);
    poly->draw(graphics, color);


    polyScale(graphics, color, poly);
    polyTranslate(graphics, color, poly);
    // polyRotate(graphics, color, poly);
    polyRotateCenter(graphics, color, poly);
}

int main() {

    auto graphics = createGraphics("raylib", 1000, 1000);
    // auto graphics = createGraphics("terminal", 150, 40);

    if (graphics) {
        createTransformPolygon(graphics.get(), 'W');
        graphics->sleep(5000);
    }

    return 0;
}

