#include <GQFusion/effects/compute/BlurComputeEffect.h>
#include <GQFusion/render/compute/ComputeShader.h>

#include <iostream>

namespace GQFusion {

BlurComputeEffect::BlurComputeEffect() = default;

// ------------------------------------------------------------
// Setup
// ------------------------------------------------------------

bool BlurComputeEffect::initialize(const std::string& shaderPath) {
    shader = std::make_shared<ComputeShader>();

    if (!shader->loadFromFile(shaderPath)) {
        std::cerr << "[BlurComputeEffect] Failed to load shader: "
                  << shaderPath << "\n";
        return false;
    }

    return true;
}

// ------------------------------------------------------------
// Usage
// ------------------------------------------------------------

void BlurComputeEffect::apply() {
    if (!shader) return;

    shader->bind();

    // TODO: pass uniforms (radius, etc.)
    // Example:
    // glUniform1f(location, radius);
}

void* BlurComputeEffect::getComputeShader() const {
    if (!shader) return nullptr;

    // Return raw GPU handle (used by backend)
    return reinterpret_cast<void*>(
        static_cast<uintptr_t>(shader->getID())
    );
}

// ------------------------------------------------------------
// Parameters
// ------------------------------------------------------------

void BlurComputeEffect::setRadius(float r) {
    radius = r;
}

float BlurComputeEffect::getRadius() const {
    return radius;
}

} // namespace GQFusion
