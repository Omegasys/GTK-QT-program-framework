#include <GQFusion/render/compute/ComputePipeline.h>
#include <iostream>

namespace GQFusion {

ComputePipeline::ComputePipeline() = default;

bool ComputePipeline::create(void* shaderHandle) {
    shader = shaderHandle;
    return shader != nullptr;
}

void ComputePipeline::bind() {
    // Backend-specific binding happens elsewhere
}

void ComputePipeline::dispatch(int x, int y, int z) {
    std::cout << "[ComputePipeline] Dispatch: "
              << x << "," << y << "," << z << "\n";
}

void* ComputePipeline::getShader() const {
    return shader;
}

} // namespace GQFusion
