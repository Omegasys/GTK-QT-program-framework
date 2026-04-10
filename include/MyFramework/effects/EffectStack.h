#pragma once

#include <vector>
#include <memory>

#include <MyFramework/core/Object.h>

namespace MyFramework {

class Widget;

/**
 * @brief Manages multiple visual effects on a widget.
 *
 * Effects are applied in order:
 * 1. Fade
 * 2. Blur
 * 3. Shadow
 * 4. Custom effects
 */
class EffectStack : public Object {
public:
    explicit EffectStack(Object* parent = nullptr);

    /**
     * @brief Attaches a widget to this effect stack.
     */
    void attachWidget(Widget* widget);

    /**
     * @brief Adds an effect.
     */
    void addEffect(Object* effect);

    /**
     * @brief Removes an effect.
     */
    void removeEffect(Object* effect);

    /**
     * @brief Clears all effects.
     */
    void clear();

    /**
     * @brief Updates all effects (called per frame).
     */
    void update(float deltaTime);

    /**
     * @brief Applies effects during rendering.
     */
    void apply();

private:
    Widget* m_widget;

    std::vector<Object*> m_effects;
};

} // namespace MyFramework
