#include <MyFramework/animation/Easing.h>
#include <cmath>

namespace MyFramework {

float Easing::apply(Type type, float t) {
    switch (type) {
        case Type::Linear:
            return t;

        case Type::EaseIn:
            return t * t;

        case Type::EaseOut:
            return t * (2 - t);

        case Type::EaseInOut:
            return t < 0.5f
                ? 2 * t * t
                : -1 + (4 - 2 * t) * t;

        case Type::Bounce:
            return std::abs(std::sin(6.28f * (t + 1) * (1 - t)));

        case Type::Elastic:
            return std::sin(13 * 3.14f * t) * std::pow(2, 10 * (t - 1));

        case Type::SmoothStep:
            return t * t * (3 - 2 * t);
    }

    return t;
}

float Easing::lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

} // namespace MyFramework
