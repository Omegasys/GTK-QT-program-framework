#pragma once

namespace GQFusion {

/**
 * @brief GPU resource used in frame graph (textures, buffers, etc).
 */
class FrameResource {
public:
    FrameResource() = default;
    ~FrameResource() = default;

    void* getHandle() const;

    void setHandle(void* h);

private:
    void* handle = nullptr;
};

} // namespace GQFusion
