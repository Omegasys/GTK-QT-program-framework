#include <iostream>

// Forward declarations
void run_easing_tests();
void run_timeline_tests();
void run_property_animation_tests();

int main() {
    std::cout << "Running MyFramework Animation Tests...\n\n";

    run_easing_tests();
    run_timeline_tests();
    run_property_animation_tests();

    std::cout << "\nAll animation tests executed.\n";
    return 0;
}
