#include "graphics_factory.h"
#include "algo.h"

int main() {

    auto graphics = std::move(createGraphics("terminal", 150, 40));
    if (graphics) {
        ddaLine(graphics.get(), new Point(10, 10), new Point(20, 20));
    }

    return 0;
}