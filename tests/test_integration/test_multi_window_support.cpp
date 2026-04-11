#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>
#include <iostream>

using namespace MyFramework;

void run_multi_window_support_test() {
    std::cout << "[TEST] Multi-Window Support\n";

    Window window1(400, 300, "Window 1");
    Window window2(400, 300, "Window 2");

    window1.show();
    window2.show();

    window1.renderFrame();
    window2.renderFrame();

    if (window1.isOpen() && window2.isOpen())
        std::cout << "  ✔ Multiple windows active\n";
    else
        std::cout << "  ✖ Multi-window support failed\n";
}
