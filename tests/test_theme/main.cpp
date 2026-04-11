#include <iostream>

// Forward declarations
void run_theme_parser_tests();
void run_theme_blending_tests();
void run_theme_scheduler_tests();
void run_theme_fallback_tests();

int main() {
    std::cout << "Running MyFramework Theme Tests...\n\n";

    run_theme_parser_tests();
    run_theme_blending_tests();
    run_theme_scheduler_tests();
    run_theme_fallback_tests();

    std::cout << "\nAll theme tests executed.\n";
    return 0;
}
