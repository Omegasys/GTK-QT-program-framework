#pragma once

#include <MyFramework/core/Object.h>

namespace MyFramework {

/**
 * @brief Handles opacity transitions for widgets.
 */
class FadeEffect : public Object {
public:
    explicit FadeEffect(Object* parent = nullptr);

    /**
     * @brief Sets target opacity (0.0 - 1.0).
     */
    void setOpacity(float opacity);
    float opacity() const;

    /**
     * @brief Sets fade speed (units per second).
     */
    void setSpeed(float speed);
    float speed() const;

    /**
     * @brief Updates fade over time.
     */
    void update(float deltaTime);

    /**
     * @brief Instantly sets opacity without animation.
     */
    void setInstant(float opacity);

private:
    float m_opacity;
    float m_targetOpacity;
    float m_speed;
};

} // namespace MyFramework
