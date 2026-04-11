#pragma once

#include <vector>
#include <memory>
#include <string>

namespace GQFusion {

class RenderTarget;
class Texture;

/**
 * @brief FrameGraph-based rendering system.
 *
 * Manages ordered rendering passes and resource dependencies.
 */
class FrameGraph {
public:
    struct Pass {
        std::string name;

        std::vector<RenderTarget*> inputs;
        std::vector<RenderTarget*> outputs;

        bool usesCompute = false;
    };

public:
    FrameGraph() = default;
    ~FrameGraph() = default;

    // ------------------------------------------------------------
    // Pass Management
    // ------------------------------------------------------------

    /**
     * @brief Add a render or compute pass.
     */
    void addPass(const Pass& pass);

    /**
     * @brief Execute all passes in dependency order.
     */
    void execute();

    /**
     * @brief Clear all passes.
     */
    void clear();

    // ------------------------------------------------------------
    // Debug
    // ------------------------------------------------------------

    void printGraph() const;

private:
    std::vector<Pass> passes;

    void executePass(const Pass& pass);
};

} // namespace GQFusion
