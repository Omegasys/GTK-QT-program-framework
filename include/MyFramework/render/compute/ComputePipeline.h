#pragma once

#include <memory>

namespace GQFusion {

class ComputeShader;

/**
 * @brief High-level wrapper for compute execution.
 *
 * Handles binding, dispatch, and synchronization.
 */
class ComputePipeline {
public:
    ComputePipeline();
    ~ComputePipeline() = default;

    void setShader(std::shared_ptr<ComputeShader> shader);

    /**
     * @brief Execute compute workload.
     */
    void dispatch(int x, int y, int z);

private:
    std::shared_ptr<ComputeShader> shader;
};

} // namespace GQFusion
