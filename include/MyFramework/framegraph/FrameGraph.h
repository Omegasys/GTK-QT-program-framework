#pragma once

#include <vector>
#include <memory>
#include <string>

namespace GQFusion {

class FramePass;

/**
 * @brief Frame graph system for structured rendering.
 */
class FrameGraph {
public:
    FrameGraph() = default;
    ~FrameGraph() = default;

    void addPass(const std::shared_ptr<FramePass>& pass);

    void execute();

    void clear();

private:
    std::vector<std::shared_ptr<FramePass>> passes;
};

} // namespace GQFusion
