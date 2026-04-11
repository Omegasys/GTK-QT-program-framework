#pragma once

#include <vector>
#include <functional>

namespace GQFusion {

/**
 * @brief Generic keyframe-based animation track.
 *
 * Supports interpolation of any float-based property.
 */
class KeyframeTrack {
public:
    struct Keyframe {
        float time = 0.0f;
        float value = 0.0f;
    };

public:
    KeyframeTrack() = default;
    ~KeyframeTrack() = default;

    // ------------------------------------------------------------
    // Keyframe Management
    // ------------------------------------------------------------

    void addKeyframe(float time, float value);

    void clear();

    // ------------------------------------------------------------
    // Evaluation
    // ------------------------------------------------------------

    /**
     * @brief Evaluate track at given time.
     */
    float evaluate(float time) const;

    // ------------------------------------------------------------
    // Optional Callback Binding
    // ------------------------------------------------------------

    void bind(std::function<void(float)> setter);

    /**
     * @brief Update and apply to bound target.
     */
    void update(float time);

private:
    std::vector<Keyframe> keyframes;

    std::function<void(float)> setter;

    float interpolate(float a, float b, float t) const;
};

} // namespace GQFusion
