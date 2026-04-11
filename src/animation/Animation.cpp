#include <MyFramework/animation/Animation.h>

namespace MyFramework {

Animation::Animation(Object* parent)
    : Object(parent),
      m_duration(1.0f),
      m_elapsed(0.0f),
      m_running(false) {}

void Animation::start() {
    m_elapsed = 0.0f;
    m_running = true;
}

void Animation::stop() {
    m_running = false;
}

void Animation::update(float dt) {
    if (!m_running) return;

    m_elapsed += dt;

    if (m_elapsed >= m_duration) {
        m_elapsed = m_duration;
        m_running = false;
    }
}

bool Animation::isRunning() const {
    return m_running;
}

void Animation::setDuration(float seconds) {
    m_duration = seconds;
}

float Animation::duration() const {
    return m_duration;
}

} // namespace MyFramework
