#include <MyFramework/animation/PropertyAnimation.h>
#include <MyFramework/animation/Easing.h>

namespace MyFramework {

PropertyAnimation::PropertyAnimation(Object* parent)
    : Animation(parent),
      m_startValue(0.0f),
      m_endValue(1.0f),
      m_currentValue(0.0f),
      m_easing(Easing::Type::Linear) {}

void PropertyAnimation::setStartValue(float value) {
    m_startValue = value;
}

void PropertyAnimation::setEndValue(float value) {
    m_endValue = value;
}

void PropertyAnimation::setEasing(Easing::Type type) {
    m_easing = type;
}

float PropertyAnimation::currentValue() const {
    return m_currentValue;
}

void PropertyAnimation::update(float dt) {
    Animation::update(dt);

    float t = m_duration > 0.0f ? (m_elapsed / m_duration) : 1.0f;
    t = Easing::apply(m_easing, t);

    m_currentValue = Easing::lerp(m_startValue, m_endValue, t);

    if (onValueChanged)
        onValueChanged(m_currentValue);
}

} // namespace MyFramework
