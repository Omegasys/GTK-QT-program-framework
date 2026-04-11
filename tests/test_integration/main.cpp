#include <iostream>

// Forward declarations
void run_full_app_boot_test();
void run_widget_render_pipeline_test();
void run_theme_live_reload_ui_test();
void run_multi_window_support_test();

int main() {
    std::cout << "Running MyFramework Integration Tests...\n\n";

    run_full_app_boot_test();
    run_widget_render_pipeline_test();
    run_theme_live_reload_ui_test();
    run_multi_window_support_test();

    std::cout << "\nAll integration tests executed.\n";
    return 0;
}
