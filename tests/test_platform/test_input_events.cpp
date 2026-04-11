#include <MyFramework/platform/Platform.h>
#include <MyFramework/core/Event.h>
#include <iostream>

using namespace MyFramework;

void run_input_event_tests() {
    std::cout << "[TEST] Input Events\n";

    Platform platform;
    WindowImpl* window = platform.createWindow(400, 300, "Input Test");

    bool received = false;

    window->setEventCallback([&](Event& event) {
        if (event.type() == Event::Type::MouseButtonPressed) {
            received = true;
        }
    });

    // Simulate input event
    Event testEvent(Event::Type::MouseButtonPressed);
    window->dispatchEvent(testEvent);

    if (received)
        std::cout << "  ✔ Input event received\n";
    else
        std::cout << "  ✖ Input event failed\n";

    delete window;
}
