#pragma once

#include <string>
#include <vector>

namespace GQFusion {

class FrameResource;

/**
 * @brief A single render or compute pass in the FrameGraph.
 *
 * Examples:
 *  - UI Render Pass
 *  - Blur Compute Pass
 *  - Glow Pass
 *  - Shadow Pass
 */
class FramePass {
public:
    explicit FramePass(const std::string& name);
    ~FramePass() = default;

    // ------------------------------------------------------------
    // Resource Binding
    // ------------------------------------------------------------

    void addInput(FrameResource* resource);
    void addOutput(FrameResource* resource);

    // ------------------------------------------------------------
    // Execution
    // ------------------------------------------------------------

    void execute();

    const std::string& getName() const;

private:
    std::string name;

    std::vector<FrameResource*> inputs;
    std::vector<FrameResource*> outputs;
};

} // namespace GQFusion
