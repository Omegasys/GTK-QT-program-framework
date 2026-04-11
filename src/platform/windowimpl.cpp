#include <GQFusion/platform/windowimpl.h>

namespace GQFusion {

WindowImpl::WindowImpl() = default;

WindowImpl::~WindowImpl() = default;

bool WindowImpl::create(int width, int height, const std::string& title) {
    this->width = width;
    this->height = height;
    this->title = title;
    return true;
}

void WindowImpl::pollEvents() {
    // OS-specific implementations override behavior
}

void WindowImpl::swapBuffers() {
    // Backend-specific swap
}

void WindowImpl::close() {
    shouldClose = true;
}

bool WindowImpl::isOpen() const {
    return !shouldClose;
}

int WindowImpl::getWidth() const {
    return width;
}

int WindowImpl::getHeight() const {
    return height;
}

} // namespace GQFusion
