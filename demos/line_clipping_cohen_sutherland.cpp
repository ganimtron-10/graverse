#include<vector>
#include<utility>

#include "graphics_factory.h"
#include "algo.h"
#include "utils.h"

void drawBoundingBox(GraphicsInterface* graphics, Point* SCREEN_MIN, Point* SCREEN_MAX) {
    std::vector<Point*> bbPoints = { SCREEN_MIN, new Point{ SCREEN_MAX->x, SCREEN_MIN->y }, SCREEN_MAX, new Point{ SCREEN_MIN->x,SCREEN_MAX->y } };

    for (int i = 0; i < bbPoints.size(); i++) {
        ddaLine(graphics, bbPoints[i], bbPoints[(i + 1) % bbPoints.size()], 'R');
    }
}

void drawLines(GraphicsInterface* graphics, std::vector<std::pair<Point*, Point*>>& lines, char color = 'W', bool animate = true) {
    for (std::pair<Point*, Point*> line : lines) {
        ddaLine(graphics, line.first, line.second, color);
    }
}

std::vector<std::pair<Point*, Point*>> lineClipping(std::vector<std::pair<Point*, Point*>>& lines, Point* SCREEN_MIN, Point* SCREEN_MAX) {
    std::vector<std::pair<Point*, Point*>> clippedLines;

    // actual algorithm
    for (auto line : lines) {
        clippedLines.push_back(cohenSutherlandLineClipping(line, SCREEN_MIN, SCREEN_MAX));
    }

    return clippedLines;
}

void emulateLineClipping(GraphicsInterface* graphics, const int  WINDOW_WIDTH, const int  WINDOW_HEIGHT) {

    std::vector<std::pair<Point*, Point*>> lines;
    srand(time(0));
    for (int i = 0; i < 6; i++) {
        lines.push_back({ new Point{ rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT} , new Point{ rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT } });
    }

    drawLines(graphics, lines, 'M');

    int bbOffset = 100;
    Point* SCREEN_MIN = new Point{ bbOffset,bbOffset }, * SCREEN_MAX = new Point{ WINDOW_WIDTH - bbOffset, WINDOW_HEIGHT - bbOffset };
    // drawBoundingBox(graphics, SCREEN_MIN, SCREEN_MAX);
    graphics->sleep(1000);

    // graphics->clearScreen();
    graphics->setAnimateValue(false);
    drawBoundingBox(graphics, SCREEN_MIN, SCREEN_MAX);
    graphics->setAnimateValue(true);

    std::vector<std::pair<Point*, Point*>> clippedLines = lineClipping(lines, SCREEN_MIN, SCREEN_MAX);

    drawLines(graphics, clippedLines, 'W');

}

int main() {

    // const int WINDOW_WIDTH = 150, WINDOW_HEIGHT = 40;
    // auto graphics = std::move(createGraphics("terminal", WINDOW_WIDTH, WINDOW_HEIGHT));
    // if (graphics) {
    //     emulateLineClipping(graphics.get());
    // }

    const int WINDOW_WIDTH = 500, WINDOW_HEIGHT = 500;
    auto graphics = std::move(createGraphics("raylib", WINDOW_WIDTH, WINDOW_HEIGHT));
    if (graphics) {
        emulateLineClipping(graphics.get(), WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    return 0;
}