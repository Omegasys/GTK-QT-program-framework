#pragma once

namespace MyFramework {

/**
 * @brief Time utilities for framework-wide use.
 */
class Time {
public:
    /**
     * @brief Returns time since app start (seconds).
     */
    static double now();

    /**
     * @brief Returns delta time between frames.
     */
    static double deltaTime();

    /**
     * @brief Sets delta time (called by main loop).
     */
    static void setDeltaTime(double dt);

private:
    static double s_deltaTime;
};

} // namespace MyFramework
