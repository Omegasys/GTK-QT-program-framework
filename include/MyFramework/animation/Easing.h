#pragma once

namespace MyFramework {

/**
 * @brief Easing functions for animations.
 */
class Easing {
public:
    enum class Type {
        Linear,
        EaseIn,
        EaseOut,
        EaseInOut,
        Bounce,
        Elastic,
        SmoothStep
    };

    /**
     * @brief Applies easing to a normalized value (0.0 - 1.0).
     */
    static float apply(Type type, float t);

    /**
     * @brief Linear interpolation helper.
     */
    static float lerp(float a, float b, float t);
};

} // namespace MyFramework
