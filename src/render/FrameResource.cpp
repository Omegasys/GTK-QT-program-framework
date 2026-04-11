#include <GQFusion/framegraph/FrameResource.h>

namespace GQFusion {

void* FrameResource::getHandle() const {
    return handle;
}

void FrameResource::setHandle(void* h) {
    handle = h;
}

} // namespace GQFusion
