#include "Viewport.h"

#include <iostream>

Viewport::Viewport()
    : Panel("Viewport") {}

void Viewport::update() {
    // Future: camera controls, input
}

void Viewport::render() {
    std::cout << "[Viewport] Rendering scene\n";

    // Future:
    // - FrameGraph execution
    // - GPU UI rendering
    // - Debug overlays
}
