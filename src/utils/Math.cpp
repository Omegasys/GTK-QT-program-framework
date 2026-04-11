#include <MyFramework/utils/Math.h>
#include <cmath>

namespace MyFramework {

float Math::clamp(float value, float min, float max) {
    return std::fmax(min, std::fmin(max, value));
}

float Math::lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

float Math::smoothstep(float edge0, float edge1, float x) {
    float t = clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
    return t * t * (3 - 2 * t);
}

float Math::degToRad(float deg) {
    return deg * 3.14159265f / 180.0f;
}

float Math::radToDeg(float rad) {
    return rad * 180.0f / 3.14159265f;
}

} // namespace MyFramework
