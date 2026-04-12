#include "ViewportRenderer.h"

#include <iostream>

ViewportRenderer::ViewportRenderer() {
    std::cout << "[ViewportRenderer] Created\n";
}

void ViewportRenderer::initialize() {
    std::cout << "[ViewportRenderer] Initialized\n";
}

void ViewportRenderer::render() {
    std::cout << "[ViewportRenderer] Rendering viewport\n";

    // Future:
    // - Scene rendering
    // - FrameGraph execution
    // - Post-processing
}
