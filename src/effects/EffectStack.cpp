#include <MyFramework/effects/EffectStack.h>

namespace MyFramework {

EffectStack::EffectStack() {}

void EffectStack::addEffect(Effect* effect) {
    if (!effect) return;
    m_effects.push_back(effect);
}

void EffectStack::removeEffect(Effect* effect) {
    m_effects.erase(
        std::remove(m_effects.begin(), m_effects.end(), effect),
        m_effects.end()
    );
}

void EffectStack::clear() {
    m_effects.clear();
}

void EffectStack::apply() {
    for (auto* effect : m_effects) {
        if (effect && effect->isEnabled())
            effect->apply();
    }
}

const std::vector<Effect*>& EffectStack::effects() const {
    return m_effects;
}

} // namespace MyFramework
