#include <MyFramework/utils/Color.h>
#include <algorithm>

namespace MyFramework {

Color::Color()
    : r(0), g(0), b(0), a(1.0f) {}

Color::Color(float r, float g, float b, float a)
    : r(r), g(g), b(b), a(a) {}

Color Color::lerp(const Color& a, const Color& b, float t) {
    t = std::clamp(t, 0.0f, 1.0f);

    return Color(
        a.r + (b.r - a.r) * t,
        a.g + (b.g - a.g) * t,
        a.b + (b.b - a.b) * t,
        a.a + (b.a - a.a) * t
    );
}

Color Color::Black() { return Color(0, 0, 0, 1); }
Color Color::White() { return Color(1, 1, 1, 1); }

} // namespace MyFramework
