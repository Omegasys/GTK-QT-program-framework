#pragma once

#include <cmath>

namespace MyFramework {

/**
 * @brief Basic math utilities for UI and rendering.
 */
class Math {
public:
    static float clamp(float value, float min, float max);
    static float lerp(float a, float b, float t);
    static float map(float value, float inMin, float inMax, float outMin, float outMax);

    static float sin(float value);
    static float cos(float value);
    static float abs(float value);

    static float distance(float x1, float y1, float x2, float y2);
};

} // namespace MyFramework
