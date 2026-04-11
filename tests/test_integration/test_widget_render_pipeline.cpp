#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Button.h>
#include <iostream>

using namespace MyFramework;

void run_widget_render_pipeline_test() {
    std::cout << "[TEST] Widget Render Pipeline\n";

    Window window(800, 600, "Pipeline Test");

    Button button(&window);
    button.setText("Render Test");
    button.setPosition(100, 100);

    window.show();

    // Simulate a frame render
    window.renderFrame();

    std::cout << "  ✔ Widget rendered through pipeline (visual verification)\n";
}
