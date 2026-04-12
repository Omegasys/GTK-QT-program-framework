#include "FrameGraphBuilder.h"
#include "UIPass.h"

#include <iostream>

FrameGraphBuilder::FrameGraphBuilder() {
    std::cout << "[FrameGraphBuilder] Created\n";
}

void FrameGraphBuilder::build() {
    std::cout << "[FrameGraphBuilder] Building frame graph\n";

    // Example: add UI pass
    UIPass uiPass;
    uiPass.execute();

    // Future:
    // - Viewport pass
    // - Compute passes (blur, glow)
    // - Post-processing
}
