#pragma once

#include <vector>
#include <memory>

#include <MyFramework/core/Object.h>
#include <MyFramework/animation/Animation.h>

namespace MyFramework {

/**
 * @brief Manages multiple animations over time.
 *
 * Used for:
 * - UI transitions
 * - theme blending
 * - complex motion sequences
 */
class Timeline : public Object {
public:
    explicit Timeline(Object* parent = nullptr);

    /**
     * @brief Adds animation to timeline.
     */
    void addAnimation(Animation* animation);

    /**
     * @brief Removes animation.
     */
    void removeAnimation(Animation* animation);

    /**
     * @brief Starts all animations.
     */
    void start();

    /**
     * @brief Stops all animations.
     */
    void stop();

    /**
     * @brief Updates all animations.
     */
    void update(float deltaTime);

    /**
     * @brief Whether any animation is running.
     */
    bool isRunning() const;

    /**
     * @brief Clears timeline.
     */
    void clear();

private:
    std::vector<Animation*> m_animations;
    bool m_running;
};

} // namespace MyFramework
