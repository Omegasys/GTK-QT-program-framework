#include <MyFramework/core/Signal.h>
#include <iostream>

using namespace MyFramework;

void run_signal_tests() {
    std::cout << "[TEST] Signal System\n";

    Signal<int> signal;

    int result = 0;

    signal.connect([&](int value) {
        result = value;
    });

    signal.emit(42);

    if (result == 42)
        std::cout << "  ✔ Signal emitted correctly\n";
    else
        std::cout << "  ✖ Signal failed\n";
}
