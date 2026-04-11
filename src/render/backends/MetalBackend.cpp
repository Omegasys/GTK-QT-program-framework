#include <GQFusion/render/backends/MetalBackend.h>
#include <GQFusion/render/RenderTarget.h>

#include <iostream>

namespace GQFusion {

// ------------------------------------------------------------
// Lifecycle
// ------------------------------------------------------------

bool MetalBackend::initialize() {
    std::cout << "[Metal] Initialize backend\n";
    // TODO: Create Metal device, command queue
    return true;
}

void MetalBackend::shutdown() {
    std::cout << "[Metal] Shutdown backend\n";
}

// ------------------------------------------------------------
// Frame
// ------------------------------------------------------------

void MetalBackend::beginFrame() {
    // TODO: Begin command buffer
}

void MetalBackend::endFrame() {
    // TODO: End encoding
}

void MetalBackend::present() {
    // TODO: Present drawable
}

// ------------------------------------------------------------
// Rendering
// ------------------------------------------------------------

void MetalBackend::drawRect(float x, float y, float w, float h) {
    // TODO: Encode draw calls
}

// ------------------------------------------------------------
// Render Target
// ------------------------------------------------------------

void MetalBackend::bindRenderTarget(RenderTarget* target) {
    // TODO: Set render pass descriptor
}

// ------------------------------------------------------------
// Compute
// ------------------------------------------------------------

void MetalBackend::bindComputeShader(void* shader) {
    // TODO: Set compute pipeline state
}

void MetalBackend::dispatchCompute(int x, int y, int z) {
    // TODO: dispatchThreadgroups / dispatchThreads
}

} // namespace GQFusion
