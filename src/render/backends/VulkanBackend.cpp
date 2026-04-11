#include <GQFusion/render/backends/VulkanBackend.h>
#include <GQFusion/render/RenderTarget.h>

#include <iostream>

namespace GQFusion {

// ------------------------------------------------------------
// Lifecycle
// ------------------------------------------------------------

bool VulkanBackend::initialize() {
    std::cout << "[Vulkan] Initialize backend\n";
    // TODO: Create instance, device, swapchain
    return true;
}

void VulkanBackend::shutdown() {
    std::cout << "[Vulkan] Shutdown backend\n";
}

// ------------------------------------------------------------
// Frame
// ------------------------------------------------------------

void VulkanBackend::beginFrame() {
    // TODO: Begin command buffer
}

void VulkanBackend::endFrame() {
    // TODO: End command buffer
}

void VulkanBackend::present() {
    // TODO: vkQueuePresentKHR
}

// ------------------------------------------------------------
// Rendering
// ------------------------------------------------------------

void VulkanBackend::drawRect(float x, float y, float w, float h) {
    // TODO: Record draw command
}

// ------------------------------------------------------------
// Render Target
// ------------------------------------------------------------

void VulkanBackend::bindRenderTarget(RenderTarget* target) {
    // TODO: Bind framebuffer / render pass
}

// ------------------------------------------------------------
// Compute
// ------------------------------------------------------------

void VulkanBackend::bindComputeShader(void* shader) {
    // TODO: Bind compute pipeline
}

void VulkanBackend::dispatchCompute(int x, int y, int z) {
    // TODO: vkCmdDispatch(commandBuffer, x, y, z);
}

} // namespace GQFusion
