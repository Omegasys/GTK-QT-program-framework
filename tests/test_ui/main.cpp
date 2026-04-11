#include <iostream>

// Forward declarations
void run_widget_hierarchy_tests();
void run_layout_tests();
void run_button_tests();
void run_label_tests();
void run_window_tests();

int main() {
    std::cout << "Running MyFramework UI Tests...\n\n";

    run_widget_hierarchy_tests();
    run_layout_tests();
    run_button_tests();
    run_label_tests();
    run_window_tests();

    std::cout << "\nAll UI tests executed.\n";
    return 0;
}
