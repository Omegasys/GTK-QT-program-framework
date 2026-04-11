#include <MyFramework/core/Event.h>
#include <MyFramework/core/EventDispatcher.h>
#include <iostream>

using namespace MyFramework;

void run_event_dispatcher_tests() {
    std::cout << "[TEST] EventDispatcher\n";

    Event event(Event::Type::Custom);
    EventDispatcher dispatcher(event);

    bool handled = false;

    dispatcher.dispatch(Event::Type::Custom, [&](Event&) {
        handled = true;
    });

    if (handled)
        std::cout << "  ✔ Event dispatched successfully\n";
    else
        std::cout << "  ✖ Event dispatch failed\n";
}
