#include <GQFusion/platform/mac/CocoaWindow.h>

#include <iostream>

namespace GQFusion {

bool CocoaWindow::create(int width, int height, const std::string& title) {
    std::cout << "[Cocoa] Creating window: " << title << "\n";

    this->width = width;
    this->height = height;
    this->title = title;

    // TODO: NSWindow / NSApplication setup
    return true;
}

void CocoaWindow::pollEvents() {
    // TODO: NSEvent loop
}

void CocoaWindow::swapBuffers() {
    // TODO: CAMetalLayer presentDrawable
}

} // namespace GQFusion
