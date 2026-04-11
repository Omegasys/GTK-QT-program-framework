#include <GQFusion/platform/linux/WaylandWindow.h>

#include <iostream>

namespace GQFusion {

bool WaylandWindow::create(int width, int height, const std::string& title) {
    std::cout << "[Wayland] Creating window: " << title << "\n";

    this->width = width;
    this->height = height;
    this->title = title;

    // TODO: wl_display_connect, surface creation
    return true;
}

void WaylandWindow::pollEvents() {
    // TODO: Wayland event dispatch
}

void WaylandWindow::swapBuffers() {
    // TODO: EGL swap buffers
}

} // namespace GQFusion
