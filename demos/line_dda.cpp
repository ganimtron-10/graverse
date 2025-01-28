#include "graphics_factory.h"
#include "algo.h"

int main() {

    GraphicsInterface* graphics = createGraphics();
    ddaLine(graphics, new Point(10, 10), new Point(20, 20));

    return 0;
}