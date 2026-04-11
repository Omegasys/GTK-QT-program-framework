#pragma once

#include <memory>
#include <vector>

namespace GQFusion {

class RenderTree;
class RendererBackend;
class DrawCommand;
class FrameGraph;

/**
 * @brief GPU-based UI renderer.
 *
 * Converts a RenderTree into GPU draw commands and dispatches
 * them through the backend or frame graph.
 */
class GPUUIRenderer {
public:
    GPUUIRenderer();
    ~GPUUIRenderer() = default;

    // ------------------------------------------------------------
    // Setup
    // ------------------------------------------------------------

    void initialize(RendererBackend* backend);

    void setFrameGraph(FrameGraph* frameGraph);

    // ------------------------------------------------------------
    // Rendering
    // ------------------------------------------------------------

    /**
     * @brief Render the UI using GPU pipeline.
     */
    void render(const RenderTree& tree);

    /**
     * @brief Submit draw commands to GPU backend.
     */
    void submit();

    // ------------------------------------------------------------
    // Command Generation
    // ------------------------------------------------------------

    void buildCommands(const RenderTree& tree);

private:
    void generateDrawCommand(const RenderTree::Node& node);

private:
    RendererBackend* backend = nullptr;
    FrameGraph* frameGraph = nullptr;

    std::vector<std::unique_ptr<DrawCommand>> commands;
};

} // namespace GQFusion
