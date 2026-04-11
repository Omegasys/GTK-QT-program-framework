#include <iostream>

// Forward declarations
void run_renderer_tests();
void run_draw_command_tests();
void run_render_target_tests();
void run_shader_tests();
void run_texture_tests();

int main() {
    std::cout << "Running MyFramework Render Tests...\n\n";

    run_renderer_tests();
    run_draw_command_tests();
    run_render_target_tests();
    run_shader_tests();
    run_texture_tests();

    std::cout << "\nAll render tests executed.\n";
    return 0;
}
