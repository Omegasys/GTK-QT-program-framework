#include <iostream>
#include <vector>
#include <memory>

#include <GQFusion/ui/Window.h>
#include <GQFusion/ui/Widget.h>
#include <GQFusion/ui/RenderTree.h>
#include <GQFusion/ui/GPUUIRenderer.h>

#include <GQFusion/render/backends/RendererBackend.h>

using namespace GQFusion;

struct WindowContext {
    std::unique_ptr<Window> window;
    std::unique_ptr<RenderTree> renderTree;
    std::unique_ptr<GPUUIRenderer> renderer;
    std::shared_ptr<Widget> root;
};

int main() {
    std::cout << "[MultiWindowDemo] Starting...\n";

    // ------------------------------------------------------------
    // Shared backend (important for multi-window GPU sharing)
    // ------------------------------------------------------------
    RendererBackend* sharedBackend = nullptr;

    // ------------------------------------------------------------
    // Create multiple windows
    // ------------------------------------------------------------
    std::vector<WindowContext> windows;

    for (int i = 0; i < 2; i++) {
        WindowContext ctx;

        ctx.window = std::make_unique<Window>(
            800, 600,
            "GQFusion Window " + std::to_string(i)
        );

        if (i == 0) {
            sharedBackend = ctx.window->getBackend();
        }

        ctx.renderTree = std::make_unique<RenderTree>();
        ctx.renderer = std::make_unique<GPUUIRenderer>();
        ctx.renderer->initialize(sharedBackend);

        // --------------------------------------------------------
        // Simple UI per window
        // --------------------------------------------------------
        ctx.root = std::make_shared<Widget>();
        ctx.root->setSize(800, 600);

        auto panel = std::make_shared<Widget>();
        panel->setPosition(50, 50);
        panel->setSize(200 + i * 50, 150);

        ctx.root->addChild(panel.get());

        windows.push_back(std::move(ctx));
    }

    // ------------------------------------------------------------
    // Main loop
    // ------------------------------------------------------------
    bool running = true;

    while (running) {
        running = false;

        for (auto& ctx : windows) {
            if (!ctx.window->isOpen())
                continue;

            running = true;

            ctx.window->pollEvents();

            ctx.renderTree->build(ctx.root.get());
            ctx.renderer->render(*ctx.renderTree);

            ctx.window->swapBuffers();
        }
    }

    std::cout << "[MultiWindowDemo] Shutdown\n";
    return 0;
}
