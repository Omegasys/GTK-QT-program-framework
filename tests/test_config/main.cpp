#include <iostream>

// Forward declarations
void run_config_parser_tests();
void run_live_reload_tests();
void run_config_validation_tests();
void run_timeframe_parsing_tests();

int main() {
    std::cout << "Running MyFramework Config Tests...\n\n";

    run_config_parser_tests();
    run_live_reload_tests();
    run_config_validation_tests();
    run_timeframe_parsing_tests();

    std::cout << "\nAll config tests executed.\n";
    return 0;
}
