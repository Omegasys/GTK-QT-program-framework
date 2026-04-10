#pragma once

#include <functional>
#include <memory>

#include <MyFramework/core/Object.h>

namespace MyFramework {

/**
 * @brief Base animation class.
 *
 * Animations interpolate values over time.
 */
class Animation : public Object {
public:
    explicit Animation(Object* parent = nullptr);
    virtual ~Animation() = default;

    /**
     * @brief Starts the animation.
     */
    virtual void start();

    /**
     * @brief Stops the animation.
     */
    virtual void stop();

    /**
     * @brief Updates animation progress (0.0 - 1.0).
     */
    virtual void update(float deltaTime);

    /**
     * @brief Returns whether animation is running.
     */
    bool isRunning() const;

    /**
     * @brief Sets duration in seconds.
     */
    void setDuration(float seconds);
    float duration() const;

protected:
    float m_duration;
    float m_elapsed;
    bool m_running;
};

} // namespace MyFramework
