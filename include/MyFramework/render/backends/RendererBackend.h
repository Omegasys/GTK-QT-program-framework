#pragma once

namespace GQFusion {

class RenderTarget;
class ComputeShader;

/**
 * @brief Abstract rendering backend interface.
 *
 * Implemented by:
 * - VulkanBackend
 * - OpenGLBackend
 * - MetalBackend
 */
class RendererBackend {
public:
    virtual ~RendererBackend() = default;

    // ------------------------------------------------------------
    // Lifecycle
    // ------------------------------------------------------------

    virtual bool initialize() = 0;
    virtual void shutdown() = 0;

    // ------------------------------------------------------------
    // Frame Control
    // ------------------------------------------------------------

    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;
    virtual void present() = 0;

    // ------------------------------------------------------------
    // Rendering
    // ------------------------------------------------------------

    virtual void drawRect(float x, float y, float w, float h) = 0;

    virtual void bindRenderTarget(RenderTarget* target) = 0;

    // ------------------------------------------------------------
    // Compute
    // ------------------------------------------------------------

    virtual void bindComputeShader(void* shader) = 0;

    virtual void dispatchCompute(int x, int y, int z) = 0;
};

} // namespace GQFusion
