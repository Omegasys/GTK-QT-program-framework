#include <iostream>
#include <memory>

#include <GQFusion/ui/Widget.h>
#include <GQFusion/ui/Window.h>
#include <GQFusion/ui/RenderTree.h>
#include <GQFusion/ui/GPUUIRenderer.h>

#include <GQFusion/render/backends/RendererBackend.h>

using namespace GQFusion;

int main() {
    std::cout << "[GPU UI Demo] Starting...\n";

    // ------------------------------------------------------------
    // Window
    // ------------------------------------------------------------
    Window window(1280, 720, "GQFusion GPU UI Demo");

    // ------------------------------------------------------------
    // Backend (placeholder)
    // ------------------------------------------------------------
    RendererBackend* backend = window.getBackend();

    // ------------------------------------------------------------
    // UI Setup
    // ------------------------------------------------------------
    auto root = std::make_shared<Widget>();
    root->setSize(800, 600);

    auto button = std::make_shared<Widget>();
    button->setPosition(100, 100);
    button->setSize(200, 60);

    root->addChild(button.get());

    // ------------------------------------------------------------
    // Render pipeline
    // ------------------------------------------------------------
    RenderTree renderTree;
    GPUUIRenderer renderer;

    renderer.initialize(backend);

    // ------------------------------------------------------------
    // Main loop
    // ------------------------------------------------------------
    while (window.isOpen()) {
        window.pollEvents();

        renderTree.build(root.get());

        renderer.render(renderTree);

        window.swapBuffers();
    }

    std::cout << "[GPU UI Demo] Shutdown\n";
    return 0;
}
