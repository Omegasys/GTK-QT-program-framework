#include "UIPass.h"

#include <iostream>

UIPass::UIPass() {
    std::cout << "[UIPass] Created\n";
}

void UIPass::execute() {
    std::cout << "[UIPass] Rendering UI\n";

    // Future:
    // - GPU UI renderer
    // - Panel rendering
    // - Text + widgets
}
