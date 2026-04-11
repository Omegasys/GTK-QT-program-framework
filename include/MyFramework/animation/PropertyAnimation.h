#pragma once

#include <functional>

#include <GQFusion/animation/Animation.h>

namespace GQFusion {

/**
 * @brief Animates a float property over time.
 *
 * Uses a setter callback to update the target value.
 */
class PropertyAnimation : public Animation {
public:
    PropertyAnimation();
    ~PropertyAnimation() override = default;

    // ------------------------------------------------------------
    // Setup
    // ------------------------------------------------------------

    /**
     * @brief Set the value range.
     */
    void setRange(float start, float end);

    /**
     * @brief Set the setter callback.
     */
    void setSetter(std::function<void(float)> setter);

    // ------------------------------------------------------------
    // Animation Override
    // ------------------------------------------------------------

    void update(float deltaTime) override;

protected:
    /**
     * @brief Apply interpolated value.
     */
    void apply(float t);

private:
    float startValue = 0.0f;
    float endValue = 1.0f;

    std::function<void(float)> setter;
};

} // namespace GQFusion
