#pragma once

#include <GQFusion/render/rendererbackend.h>

namespace GQFusion {

/**
 * @brief Vulkan rendering backend.
 */
class VulkanBackend : public RendererBackend {
public:
    VulkanBackend() = default;
    ~VulkanBackend() override = default;

    bool initialize() override;
    void shutdown() override;

    void beginFrame() override;
    void endFrame() override;
    void present() override;

    void drawRect(float x, float y, float w, float h) override;

    void bindRenderTarget(RenderTarget* target) override;

    // Compute
    void bindComputeShader(void* shader) override;
    void dispatchCompute(int x, int y, int z) override;
};

} // namespace GQFusion
