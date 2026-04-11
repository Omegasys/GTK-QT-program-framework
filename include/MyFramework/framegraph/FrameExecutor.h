#pragma once

#include <memory>

namespace GQFusion {

class FrameGraph;

/**
 * @brief Executes frame graph passes in correct order.
 */
class FrameExecutor {
public:
    FrameExecutor() = default;
    ~FrameExecutor() = default;

    void execute(FrameGraph& graph);

private:
    void executePasses(FrameGraph& graph);
};

} // namespace GQFusion
