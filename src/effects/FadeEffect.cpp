#include <MyFramework/effects/FadeEffect.h>

namespace MyFramework {

FadeEffect::FadeEffect()
    : m_opacity(1.0f) {}

void FadeEffect::setOpacity(float opacity) {
    m_opacity = opacity;
}

float FadeEffect::opacity() const {
    return m_opacity;
}

void FadeEffect::apply() {
    // In real renderer: push opacity state
    // For now: placeholder (state would be used by Renderer)
}

} // namespace MyFramework
