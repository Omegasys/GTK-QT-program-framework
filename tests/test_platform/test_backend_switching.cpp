#include <MyFramework/platform/Platform.h>
#include <iostream>

using namespace MyFramework;

void run_backend_switching_tests() {
    std::cout << "[TEST] Backend Switching\n";

    Platform platform;

    bool success = true;

    // Try switching between backends
    success &= platform.setBackend("X11");
    success &= platform.setBackend("Wayland");
    success &= platform.setBackend("Win32");
    success &= platform.setBackend("Cocoa");

    if (success)
        std::cout << "  ✔ Backend switching succeeded\n";
    else
        std::cout << "  ✖ Backend switching failed (some backends may be unavailable on this OS)\n";
}
