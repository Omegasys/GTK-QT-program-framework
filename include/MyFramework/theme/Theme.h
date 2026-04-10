#pragma once

#include <MyFramework/config/ConfigTypes.h>

namespace MyFramework {

/**
 * @brief Utility functions for working with themes.
 */
class ThemeUtils {
public:
    /**
     * @brief Clamps theme values to valid ranges.
     */
    static Theme normalize(const Theme& theme);

    /**
     * @brief Validates a theme.
     */
    static bool isValid(const Theme& theme);
};

/**
 * @brief Handles blending between two themes.
 *
 * Used when time ranges overlap.
 */
class ThemeBlender {
public:
    /**
     * @brief Linearly interpolates between two colors.
     *
     * @param a First color
     * @param b Second color
     * @param t Blend factor (0.0 → 1.0)
     */
    static Color blendColor(const Color& a, const Color& b, float t);

    /**
     * @brief Blends two themes.
     *
     * @param a First theme
     * @param b Second theme
     * @param t Blend factor (0.0 → 1.0)
     */
    static Theme blend(const Theme& a, const Theme& b, float t);
};

/**
 * @brief Resolves active themes based on time.
 */
class ThemeScheduler {
public:
    /**
     * @brief Resolves the active theme for a given time.
     *
     * Handles:
     * - Normal theme selection
     * - Overlapping themes (blending)
     * - Fallback usage
     *
     * @param themes List of theme entries
     * @param fallback Fallback theme
     * @param currentTime Current time
     */
    static Theme resolveTheme(
        const std::vector<ThemeEntry>& themes,
        const Theme& fallback,
        const Time& currentTime
    );

private:
    static float computeBlendFactor(
        const ThemeEntry& a,
        const ThemeEntry& b,
        const Time& currentTime
    );
};

/**
 * @brief Applies themes to widgets/windows.
 *
 * (Bridge between theme system and UI system)
 */
class ThemeApplier {
public:
    /**
     * @brief Applies theme to a window and its children.
     */
    static void applyToWindow(class Window* window, const Theme& theme);

    /**
     * @brief Applies theme recursively to widgets.
     */
    static void applyToWidget(class Widget* widget, const Theme& theme);
};

} // namespace MyFramework
