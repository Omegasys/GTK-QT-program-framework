#include <GQFusion/effects/compute/ShadowComputeEffect.h>
#include <GQFusion/render/compute/ComputeShader.h>

#include <iostream>

namespace GQFusion {

ShadowComputeEffect::ShadowComputeEffect() = default;

// ------------------------------------------------------------
// Setup
// ------------------------------------------------------------

bool ShadowComputeEffect::initialize(const std::string& shaderPath) {
    shader = std::make_shared<ComputeShader>();

    if (!shader->loadFromFile(shaderPath)) {
        std::cerr << "[ShadowComputeEffect] Failed to load shader: "
                  << shaderPath << "\n";
        return false;
    }

    return true;
}

// ------------------------------------------------------------
// Usage
// ------------------------------------------------------------

void ShadowComputeEffect::apply() {
    if (!shader) return;

    shader->bind();

    // TODO: pass uniforms (offset, blur, opacity)
    // Example:
    // glUniform2f(..., offsetX, offsetY);
    // glUniform1f(..., blur);
    // glUniform1f(..., opacity);
}

void* ShadowComputeEffect::getComputeShader() const {
    if (!shader) return nullptr;

    return reinterpret_cast<void*>(
        static_cast<uintptr_t>(shader->getID())
    );
}

// ------------------------------------------------------------
// Parameters
// ------------------------------------------------------------

void ShadowComputeEffect::setOffset(float x, float y) {
    offsetX = x;
    offsetY = y;
}

void ShadowComputeEffect::getOffset(float& x, float& y) const {
    x = offsetX;
    y = offsetY;
}

void ShadowComputeEffect::setBlur(float value) {
    blur = value;
}

float ShadowComputeEffect::getBlur() const {
    return blur;
}

void ShadowComputeEffect::setOpacity(float value) {
    opacity = value;
}

float ShadowComputeEffect::getOpacity() const {
    return opacity;
}

} // namespace GQFusion
