#include <MyFramework/effects/BlurEffect.h>

namespace MyFramework {

BlurEffect::BlurEffect()
    : m_radius(0.0f) {}

void BlurEffect::setRadius(float radius) {
    m_radius = radius;
}

float BlurEffect::radius() const {
    return m_radius;
}

void BlurEffect::apply() {
    // Placeholder: real implementation would:
    // - apply Gaussian blur
    // - use framebuffer passes
}

} // namespace MyFramework
