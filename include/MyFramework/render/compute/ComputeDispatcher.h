#pragma once

#include <memory>
#include <vector>

namespace GQFusion {

class ComputeShader;

/**
 * @brief Orchestrates compute shader execution.
 *
 * Handles batching, dispatch scheduling, and compute effects pipeline.
 */
class ComputeDispatcher {
public:
    struct DispatchCommand {
        ComputeShader* shader = nullptr;
        int groupsX = 0;
        int groupsY = 0;
        int groupsZ = 0;
    };

public:
    ComputeDispatcher() = default;
    ~ComputeDispatcher() = default;

    // ------------------------------------------------------------
    // Dispatch Management
    // ------------------------------------------------------------

    void addDispatch(const DispatchCommand& cmd);

    void clear();

    /**
     * @brief Execute all queued compute dispatches.
     */
    void execute();

    // ------------------------------------------------------------
    // Utilities
    // ------------------------------------------------------------

    void dispatch(ComputeShader* shader, int x, int y, int z);

private:
    std::vector<DispatchCommand> queue;
};

} // namespace GQFusion
