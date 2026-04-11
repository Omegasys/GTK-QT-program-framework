#include <MyFramework/theme/ThemeTransition.h>
#include <MyFramework/utils/Time.h>

namespace MyFramework {

ThemeTransition::ThemeTransition()
    : m_active(false),
      m_duration(1.0f),
      m_elapsed(0.0f) {}

void ThemeTransition::start(const Theme& from, const Theme& to, float duration) {
    m_from = from;
    m_to = to;
    m_duration = duration;
    m_elapsed = 0.0f;
    m_active = true;
}

void ThemeTransition::update(float dt) {
    if (!m_active) return;

    m_elapsed += dt;

    if (m_elapsed >= m_duration) {
        m_elapsed = m_duration;
        m_active = false;
    }
}

Theme ThemeTransition::current() const {
    if (!m_active) return m_to;

    float t = m_elapsed / m_duration;
    return Theme::blend(m_from, m_to, t);
}

bool ThemeTransition::isActive() const {
    return m_active;
}

} // namespace MyFramework
