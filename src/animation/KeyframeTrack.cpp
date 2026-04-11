#include <GQFusion/animation/KeyframeTrack.h>
#include <algorithm>

namespace GQFusion {

void KeyframeTrack::addKeyframe(float time, float value) {
    keyframes.push_back({ time, value });

    std::sort(keyframes.begin(), keyframes.end(),
        [](const Keyframe& a, const Keyframe& b) {
            return a.time < b.time;
        });
}

void KeyframeTrack::clear() {
    keyframes.clear();
}

float KeyframeTrack::evaluate(float time) const {
    if (keyframes.empty()) return 0.0f;

    if (time <= keyframes.front().time)
        return keyframes.front().value;

    if (time >= keyframes.back().time)
        return keyframes.back().value;

    for (size_t i = 0; i < keyframes.size() - 1; i++) {
        const auto& a = keyframes[i];
        const auto& b = keyframes[i + 1];

        if (time >= a.time && time <= b.time) {
            float t = (time - a.time) / (b.time - a.time);
            return interpolate(a.value, b.value, t);
        }
    }

    return 0.0f;
}

void KeyframeTrack::bind(std::function<void(float)> setter) {
    this->setter = setter;
}

void KeyframeTrack::update(float time) {
    if (setter) {
        setter(evaluate(time));
    }
}

float KeyframeTrack::interpolate(float a, float b, float t) const {
    return a + (b - a) * t;
}

} // namespace GQFusion
