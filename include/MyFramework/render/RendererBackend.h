#pragma once

#include <vector>
#include <MyFramework/render/DrawCommand.h>
#include <MyFramework/render/RenderTarget.h>

namespace MyFramework {

/**
 * @brief Abstract backend for rendering.
 *
 * Implementations:
 * - OpenGLBackend
 * - VulkanBackend
 * - SoftwareBackend
 */
class RendererBackend {
public:
    virtual ~RendererBackend() = default;

    /**
     * @brief Called at start of frame.
     */
    virtual void beginFrame(RenderTarget* target) = 0;

    /**
     * @brief Submit draw commands.
     */
    virtual void submit(const std::vector<DrawCommand>& commands) = 0;

    /**
     * @brief Called at end of frame.
     */
    virtual void endFrame() = 0;

    /**
     * @brief Present final frame to screen.
     */
    virtual void present() = 0;
};

} // namespace MyFramework
