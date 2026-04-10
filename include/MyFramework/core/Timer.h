#pragma once

#include <functional>
#include <chrono>

namespace MyFramework {

/**
 * @brief High precision timer.
 */
class Timer {
public:
    Timer();

    /**
     * @brief Resets timer.
     */
    void reset();

    /**
     * @brief Returns elapsed time in seconds.
     */
    double elapsed() const;

    /**
     * @brief Returns elapsed time in milliseconds.
     */
    long long elapsedMs() const;

private:
    std::chrono::steady_clock::time_point m_start;
};

/**
 * @brief Simple repeating timer (frame-based or async loop use).
 */
class IntervalTimer {
public:
    IntervalTimer();

    /**
     * @brief Starts timer with interval callback.
     *
     * @param intervalMs Time between calls
     * @param callback Function to call
     */
    void start(int intervalMs, std::function<void()> callback);

    /**
     * @brief Stops timer.
     */
    void stop();

    /**
     * @brief Checks if running.
     */
    bool isRunning() const;

private:
    bool m_running;
};

} // namespace MyFramework
