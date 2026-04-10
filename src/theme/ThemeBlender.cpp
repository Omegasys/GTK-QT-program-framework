#include "MyFramework/theme/ThemeBlender.h"

namespace MyFramework {

static int lerp(int a, int b, float t) {
    return static_cast<int>(a + (b - a) * t);
}

static Color lerpColor(const Color& a, const Color& b, float t) {
    return Color(
        lerp(a.r, b.r, t),
        lerp(a.g, b.g, t),
        lerp(a.b, b.b, t)
    );
}

Theme ThemeBlender::blend(const Theme& a, const Theme& b, float t) {
    Theme result;

    result.windowLeft   = lerpColor(a.windowLeft,   b.windowLeft,   t);
    result.windowCenter = lerpColor(a.windowCenter, b.windowCenter, t);
    result.windowRight  = lerpColor(a.windowRight,  b.windowRight,  t);

    result.opacity       = lerp(a.opacity,       b.opacity,       t);
    result.blur          = lerp(a.blur,          b.blur,          t);
    result.cornerRadius  = lerp(a.cornerRadius,  b.cornerRadius,  t);
    result.shadowDistance= lerp(a.shadowDistance,b.shadowDistance,t);

    result.shadowLeft   = lerpColor(a.shadowLeft,   b.shadowLeft,   t);
    result.shadowCenter = lerpColor(a.shadowCenter, b.shadowCenter, t);
    result.shadowRight  = lerpColor(a.shadowRight,  b.shadowRight,  t);

    return result;
}

} // namespace MyFramework
