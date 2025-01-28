#ifndef GRAPHICS_FACTORY_H
#define GRAPHICS_FACTORY_H

#include "graphics_interface.h"
#include "terminal_adapter.h"

GraphicsInterface* createGraphics(std::string type = "terminal") {
    if (type == "terminal") {
        return new TerminalAdapter();
    }

    return nullptr;
}

#endif