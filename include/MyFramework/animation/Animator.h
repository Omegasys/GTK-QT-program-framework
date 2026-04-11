#pragma once

#include <vector>
#include <memory>

namespace GQFusion {

class Animation;

/**
 * @brief Central animation manager.
 *
 * Responsible for updating and managing all active animations.
 */
class Animator {
public:
    static Animator& instance();

    // ------------------------------------------------------------
    // Control
    // ------------------------------------------------------------

    /**
     * @brief Add an animation to be managed.
     */
    void add(const std::shared_ptr<Animation>& animation);

    /**
     * @brief Remove all animations.
     */
    void clear();

    /**
     * @brief Update all animations (call once per frame).
     * @param deltaTime Time since last frame (seconds)
     */
    void update(float deltaTime);

private:
    Animator() = default;

private:
    std::vector<std::shared_ptr<Animation>> animations;
};

} // namespace GQFusion
