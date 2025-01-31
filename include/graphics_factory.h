#ifndef GRAPHICS_FACTORY_H
#define GRAPHICS_FACTORY_H

#include "graphics_interface.h"
#include "terminal_adapter.h"
#include "raylib_adapter.h"

std::unique_ptr<GraphicsInterface> createGraphics(const std::string& type, int width, int height) {
    if (type == "terminal") {
        std::unique_ptr<GraphicsInterface> graphics = std::make_unique<TerminalAdapter>(width, height);
        graphics->init();
        return graphics;
    }
    else if (type == "raylib") {
        std::unique_ptr<GraphicsInterface> graphics = std::make_unique<RaylibAdapter>(width, height);
        graphics->init();
        return graphics;
    }

    return nullptr;
}

#endif