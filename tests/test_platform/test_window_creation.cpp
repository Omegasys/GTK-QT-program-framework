#include <MyFramework/platform/Platform.h>
#include <MyFramework/platform/WindowImpl.h>
#include <iostream>

using namespace MyFramework;

void run_window_creation_tests() {
    std::cout << "[TEST] Window Creation\n";

    Platform platform;

    WindowImpl* window = platform.createWindow(800, 600, "Test Window");

    if (window != nullptr)
        std::cout << "  ✔ Window created successfully\n";
    else
        std::cout << "  ✖ Window creation failed\n";

    delete window;
}
