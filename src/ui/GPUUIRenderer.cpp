#include <GQFusion/ui/GPUUIRenderer.h>
#include <GQFusion/ui/RenderTree.h>

#include <GQFusion/render/backends/RendererBackend.h>
#include <GQFusion/render/DrawCommand.h>

#include <iostream>

namespace GQFusion {

GPUUIRenderer::GPUUIRenderer() = default;

void GPUUIRenderer::initialize(RendererBackend* backend) {
    this->backend = backend;
}

void GPUUIRenderer::setFrameGraph(FrameGraph* frameGraph) {
    this->frameGraph = frameGraph;
}

void GPUUIRenderer::render(const RenderTree& tree) {
    buildCommands(tree);
    submit();
}

void GPUUIRenderer::buildCommands(const RenderTree& tree) {
    commands.clear();

    const auto& nodes = tree.getNodes();

    for (const auto& node : nodes) {
        if (node.culled || !node.visible)
            continue;

        generateDrawCommand(node);
    }
}

void GPUUIRenderer::generateDrawCommand(const RenderTree::Node& node) {
    if (!node.widget) return;

    auto cmd = std::make_unique<DrawCommand>();

    cmd->x = node.x;
    cmd->y = node.y;
    cmd->width = node.width;
    cmd->height = node.height;

    cmd->type = node.widget->getRenderType();

    commands.push_back(std::move(cmd));
}

void GPUUIRenderer::submit() {
    if (!backend) return;

    backend->beginFrame();

    for (auto& cmd : commands) {
        backend->drawRect(cmd->x, cmd->y, cmd->width, cmd->height);
    }

    backend->endFrame();
    backend->present();
}

} // namespace GQFusion
