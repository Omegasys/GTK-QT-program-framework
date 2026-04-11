#include <MyFramework/animation/Timeline.h>

namespace MyFramework {

Timeline::Timeline(Object* parent)
    : Object(parent),
      m_running(false) {}

void Timeline::addAnimation(Animation* animation) {
    if (!animation) return;
    m_animations.push_back(animation);
}

void Timeline::removeAnimation(Animation* animation) {
    m_animations.erase(
        std::remove(m_animations.begin(), m_animations.end(), animation),
        m_animations.end()
    );
}

void Timeline::start() {
    m_running = true;

    for (auto* anim : m_animations)
        anim->start();
}

void Timeline::stop() {
    m_running = false;

    for (auto* anim : m_animations)
        anim->stop();
}

void Timeline::update(float dt) {
    if (!m_running) return;

    bool anyRunning = false;

    for (auto* anim : m_animations) {
        if (anim->isRunning()) {
            anim->update(dt);
            anyRunning = true;
        }
    }

    m_running = anyRunning;
}

bool Timeline::isRunning() const {
    return m_running;
}

void Timeline::clear() {
    m_animations.clear();
}

} // namespace MyFramework
