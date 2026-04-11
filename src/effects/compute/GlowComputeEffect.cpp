#include <GQFusion/effects/compute/GlowComputeEffect.h>
#include <GQFusion/render/compute/ComputeShader.h>

#include <iostream>

namespace GQFusion {

GlowComputeEffect::GlowComputeEffect() = default;

// ------------------------------------------------------------
// Setup
// ------------------------------------------------------------

bool GlowComputeEffect::initialize(const std::string& shaderPath) {
    shader = std::make_shared<ComputeShader>();

    if (!shader->loadFromFile(shaderPath)) {
        std::cerr << "[GlowComputeEffect] Failed to load shader: "
                  << shaderPath << "\n";
        return false;
    }

    return true;
}

// ------------------------------------------------------------
// Usage
// ------------------------------------------------------------

void GlowComputeEffect::apply() {
    if (!shader) return;

    shader->bind();

    // TODO: pass uniforms (intensity, threshold)
    // Example:
    // glUniform1f(..., intensity);
    // glUniform1f(..., threshold);
}

void* GlowComputeEffect::getComputeShader() const {
    if (!shader) return nullptr;

    return reinterpret_cast<void*>(
        static_cast<uintptr_t>(shader->getID())
    );
}

// ------------------------------------------------------------
// Parameters
// ------------------------------------------------------------

void GlowComputeEffect::setIntensity(float value) {
    intensity = value;
}

float GlowComputeEffect::getIntensity() const {
    return intensity;
}

void GlowComputeEffect::setThreshold(float value) {
    threshold = value;
}

float GlowComputeEffect::getThreshold() const {
    return threshold;
}

} // namespace GQFusion
