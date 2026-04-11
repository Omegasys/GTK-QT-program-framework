#include <iostream>

// Forward declarations
void run_window_creation_tests();
void run_input_event_tests();
void run_backend_switching_tests();

int main() {
    std::cout << "Running MyFramework Platform Tests...\n\n";

    run_window_creation_tests();
    run_input_event_tests();
    run_backend_switching_tests();

    std::cout << "\nAll platform tests executed.\n";
    return 0;
}
