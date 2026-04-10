#pragma once

namespace MyFramework {

/**
 * @brief RGBA color representation.
 */
class Color {
public:
    float r, g, b, a;

    Color();
    Color(float r, float g, float b, float a = 1.0f);

    // Common preset colors
    static Color White();
    static Color Black();
    static Color Red();
    static Color Green();
    static Color Blue();
    static Color Transparent();

    /**
     * @brief Linear interpolation between colors.
     */
    static Color lerp(const Color& a, const Color& b, float t);
};

} // namespace MyFramework
