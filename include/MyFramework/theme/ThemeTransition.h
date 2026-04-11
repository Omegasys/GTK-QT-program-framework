#pragma once

#include <memory>

namespace GQFusion {

class Theme;

/**
 * @brief Handles smooth transitions between two themes.
 *
 * Used for:
 *  - theme switching
 *  - redshift blending
 *  - UI animations
 */
class ThemeTransition {
public:
    ThemeTransition();
    ~ThemeTransition() = default;

    /**
     * @brief Start a transition between two themes.
     * @param from Starting theme
     * @param to Target theme
     * @param duration Duration in seconds
     */
    void start(const Theme& from,
               const Theme& to,
               float duration);

    /**
     * @brief Update transition (call per frame).
     * @param deltaTime Time since last frame
     */
    void update(float deltaTime);

    /**
     * @brief Get interpolated theme.
     */
    Theme current() const;

    /**
     * @brief Check if transition is active.
     */
    bool isActive() const;

private:
    Theme interpolate(const Theme& a,
                      const Theme& b,
                      float t) const;

private:
    Theme* fromTheme = nullptr;
    Theme* toTheme = nullptr;

    float duration = 0.0f;
    float elapsed = 0.0f;

    bool active = false;
};

} // namespace GQFusion
