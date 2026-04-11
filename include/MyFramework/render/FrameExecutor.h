#pragma once

namespace GQFusion {

class FrameGraph;

/**
 * @brief Executes a FrameGraph in correct order.
 *
 * Responsible for running all passes and coordinating GPU submission.
 */
class FrameExecutor {
public:
    FrameExecutor() = default;
    ~FrameExecutor() = default;

    /**
     * @brief Execute full frame graph.
     */
    void execute(FrameGraph& graph);

private:
    void executePasses(FrameGraph& graph);
};

} // namespace GQFusion
