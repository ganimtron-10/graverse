#include "graphics_factory.h"
#include "algo.h"

int main() {

    // auto graphics = std::move(createGraphics("terminal", 150, 40));
    // if (graphics) {
    //     ddaLine(graphics.get(), new Point(10, 10), new Point(20, 20));
    // }

    auto graphics = std::move(createGraphics("raylib", 500, 500));
    if (graphics) {
        ddaLine(graphics.get(), new Point(10, 10), new Point(200, 200), 'R');
    }

    return 0;
}