#include <GQFusion/platform/linux/X11Window.h>

#include <iostream>

namespace GQFusion {

bool X11Window::create(int width, int height, const std::string& title) {
    std::cout << "[X11] Creating window: " << title << "\n";

    this->width = width;
    this->height = height;
    this->title = title;

    // TODO: XOpenDisplay, XCreateWindow
    return true;
}

void X11Window::pollEvents() {
    // TODO: XNextEvent loop
}

void X11Window::swapBuffers() {
    // TODO: GLX swap buffers
}

} // namespace GQFusion
