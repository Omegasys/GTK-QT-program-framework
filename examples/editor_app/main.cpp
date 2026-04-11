#include <iostream>
#include <fstream>
#include <string>

#include <GQFusion/ui/Window.h>
#include <GQFusion/ui/Widget.h>
#include <GQFusion/ui/RenderTree.h>
#include <GQFusion/ui/GPUUIRenderer.h>
#include <GQFusion/render/backends/RendererBackend.h>

using namespace GQFusion;

static std::string loadFile(const std::string& path) {
    std::ifstream file(path);
    return std::string((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
}

int main() {
    std::cout << "[EditorApp] Starting GQFusion Editor...\n";

    // ------------------------------------------------------------
    // Window
    // ------------------------------------------------------------
    Window window(1400, 900, "GQFusion Editor");

    RendererBackend* backend = window.getBackend();

    // ------------------------------------------------------------
    // Root UI
    // ------------------------------------------------------------
    auto root = std::make_shared<Widget>();
    root->setSize(1400, 900);

    auto panel = std::make_shared<Widget>();
    panel->setPosition(50, 50);
    panel->setSize(400, 600);

    auto viewport = std::make_shared<Widget>();
    viewport->setPosition(500, 50);
    viewport->setSize(800, 700);

    root->addChild(panel.get());
    root->addChild(viewport.get());

    // ------------------------------------------------------------
    // Renderer
    // ------------------------------------------------------------
    RenderTree renderTree;
    GPUUIRenderer renderer;
    renderer.initialize(backend);

    // ------------------------------------------------------------
    // Load config (placeholder usage)
    // ------------------------------------------------------------
    std::string config = loadFile("editor.config");
    std::cout << "[EditorApp] Loaded config size: " << config.size() << "\n";

    // ------------------------------------------------------------
    // Main loop
    // ------------------------------------------------------------
    while (window.isOpen()) {
        window.pollEvents();

        renderTree.build(root.get());
        renderer.render(renderTree);

        window.swapBuffers();
    }

    std::cout << "[EditorApp] Shutdown\n";
    return 0;
}
