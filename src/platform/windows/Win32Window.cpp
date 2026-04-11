#include <GQFusion/platform/windows/Win32Window.h>

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace GQFusion {

bool Win32Window::create(int width, int height, const std::string& title) {
    std::cout << "[Win32] Creating window: " << title << "\n";

    this->width = width;
    this->height = height;
    this->title = title;

#ifdef _WIN32
    // TODO: RegisterClassEx, CreateWindowEx
#endif

    return true;
}

void Win32Window::pollEvents() {
#ifdef _WIN32
    // TODO: PeekMessage / TranslateMessage / DispatchMessage
#endif
}

void Win32Window::swapBuffers() {
    // TODO: SwapBuffers(hdc)
}

} // namespace GQFusion
