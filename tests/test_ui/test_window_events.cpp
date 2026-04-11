#include <MyFramework/ui/Window.h>
#include <MyFramework/core/Event.h>
#include <iostream>

using namespace MyFramework;

void run_window_tests() {
    std::cout << "[TEST] Window Events\n";

    Window window(200, 200, "Test");

    bool handled = false;

    Event event(Event::Type::Custom);

    window.setEventHandler([&](Event&) {
        handled = true;
    });

    window.handleEvent(event);

    if (handled)
        std::cout << "  ✔ Window event handled\n";
    else
        std::cout << "  ✖ Window event handling failed\n";
}
