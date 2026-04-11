#include <MyFramework/effects/ShadowEffect.h>

namespace MyFramework {

ShadowEffect::ShadowEffect()
    : m_offsetX(0.0f),
      m_offsetY(0.0f),
      m_blur(5.0f),
      m_color(Color::Black()) {}

void ShadowEffect::setOffset(float x, float y) {
    m_offsetX = x;
    m_offsetY = y;
}

void ShadowEffect::setBlur(float blur) {
    m_blur = blur;
}

void ShadowEffect::setColor(const Color& color) {
    m_color = color;
}

float ShadowEffect::offsetX() const { return m_offsetX; }
float ShadowEffect::offsetY() const { return m_offsetY; }
float ShadowEffect::blur() const { return m_blur; }
const Color& ShadowEffect::color() const { return m_color; }

void ShadowEffect::apply() {
    // Placeholder:
    // In real rendering:
    // - draw blurred offset rectangle
    // - apply gradient shadow (matches your theme system)
}

} // namespace MyFramework
