#pragma once

namespace GQFusion {

/**
 * @brief GPU resource used inside FrameGraph passes.
 *
 * Can represent:
 *  - Texture
 *  - Buffer
 *  - Render target
 *  - Compute output
 */
class FrameResource {
public:
    FrameResource() = default;
    ~FrameResource() = default;

    /**
     * @brief Get backend-specific GPU handle.
     */
    void* getHandle() const;

    /**
     * @brief Set backend-specific GPU handle.
     */
    void setHandle(void* handle);

private:
    void* handle = nullptr;
};

} // namespace GQFusion
