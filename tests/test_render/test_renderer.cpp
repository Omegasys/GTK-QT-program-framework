#include <MyFramework/render/Renderer.h>
#include <MyFramework/render/RenderTarget.h>
#include <iostream>

using namespace MyFramework;

void run_renderer_tests() {
    std::cout << "[TEST] Renderer\n";

    Renderer renderer;
    RenderTarget target(800, 600);

    renderer.begin(nullptr, &target);
    renderer.drawRect(10, 10, 100, 50, Color::White());
    renderer.end();

    std::cout << "  ✔ Renderer executed draw commands (check console output)\n";
}
