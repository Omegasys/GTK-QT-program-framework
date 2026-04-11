#include <MyFramework/ui/Button.h>
#include <MyFramework/core/Event.h>
#include <iostream>

using namespace MyFramework;

void run_button_tests() {
    std::cout << "[TEST] Button Interaction\n";

    Button button;
    bool clicked = false;

    button.onClick = [&]() {
        clicked = true;
    };

    // Simulate click event
    Event clickEvent(Event::Type::MouseButtonPressed);
    button.handleEvent(clickEvent);

    if (clicked)
        std::cout << "  ✔ Button click handled\n";
    else
        std::cout << "  ✖ Button click failed\n";
}
