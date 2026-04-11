#include <MyFramework/animation/Animator.h>
#include <MyFramework/utils/Time.h>

namespace MyFramework {

Animator::Animator() {}

void Animator::add(Animation* animation) {
    if (!animation) return;
    m_animations.push_back(animation);
}

void Animator::remove(Animation* animation) {
    m_animations.erase(
        std::remove(m_animations.begin(), m_animations.end(), animation),
        m_animations.end()
    );
}

void Animator::update() {
    float dt = (float)Time::deltaTime();

    for (auto* anim : m_animations) {
        if (anim->isRunning())
            anim->update(dt);
    }
}

void Animator::clear() {
    m_animations.clear();
}

} // namespace MyFramework
