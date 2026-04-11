#include <MyFramework/theme/Theme.h>

namespace MyFramework {

Theme::Theme()
    : opacity(1.0f),
      blur(0.0f),
      cornerRadius(0.0f),
      shadowDistance(0.0f) {}

Theme Theme::blend(const Theme& a, const Theme& b, float t) {
    Theme result;

    result.leftColor   = Color::lerp(a.leftColor, b.leftColor, t);
    result.centerColor = Color::lerp(a.centerColor, b.centerColor, t);
    result.rightColor  = Color::lerp(a.rightColor, b.rightColor, t);

    result.shadowLeft   = Color::lerp(a.shadowLeft, b.shadowLeft, t);
    result.shadowCenter = Color::lerp(a.shadowCenter, b.shadowCenter, t);
    result.shadowRight  = Color::lerp(a.shadowRight, b.shadowRight, t);

    result.opacity        = a.opacity + (b.opacity - a.opacity) * t;
    result.blur           = a.blur + (b.blur - a.blur) * t;
    result.cornerRadius   = a.cornerRadius + (b.cornerRadius - a.cornerRadius) * t;
    result.shadowDistance = a.shadowDistance + (b.shadowDistance - a.shadowDistance) * t;

    return result;
}

} // namespace MyFramework
