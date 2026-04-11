#include <iostream>

// Forward declarations
void run_object_tests();
void run_event_dispatcher_tests();
void run_signal_tests();
void run_timer_tests();
void run_logger_tests();

int main() {
    std::cout << "Running MyFramework Core Tests...\n\n";

    run_object_tests();
    run_event_dispatcher_tests();
    run_signal_tests();
    run_timer_tests();
    run_logger_tests();

    std::cout << "\nAll tests executed.\n";
    return 0;
}
