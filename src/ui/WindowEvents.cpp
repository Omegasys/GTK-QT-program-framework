#include <GQFusion/ui/Window.h>
#include <GQFusion/core/EventDispatcher.h>

#include <iostream>

namespace GQFusion {

void Window::pollEvents() {
    // Platform-specific event polling hook
    // (actual OS backend fills this in)

    processInputEvents();
}

void Window::processInputEvents() {
    // Placeholder event handling pipeline

    if (onResizeCallback) {
        onResizeCallback(width, height);
    }

    if (onMouseMoveCallback) {
        onMouseMoveCallback(mouseX, mouseY);
    }

    if (onKeyCallback) {
        // Example key event dispatch
    }
}

void Window::setResizeCallback(std::function<void(int,int)> cb) {
    onResizeCallback = cb;
}

void Window::setMouseMoveCallback(std::function<void(int,int)> cb) {
    onMouseMoveCallback = cb;
}

void Window::setKeyCallback(std::function<void(int)> cb) {
    onKeyCallback = cb;
}

} // namespace GQFusion
