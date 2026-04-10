#pragma once

#include <MyFramework/core/Object.h>

namespace MyFramework {

/**
 * @brief Applies blur effect to a widget or render target region.
 */
class BlurEffect : public Object {
public:
    explicit BlurEffect(Object* parent = nullptr);

    /**
     * @brief Sets blur radius (in pixels).
     */
    void setRadius(float radius);
    float radius() const;

    /**
     * @brief Sets blur quality (higher = slower, smoother).
     */
    void setQuality(int quality);
    int quality() const;

    /**
     * @brief Enables or disables blur.
     */
    void setEnabled(bool enabled);
    bool isEnabled() const;

private:
    float m_radius;
    int m_quality;
    bool m_enabled;
};

} // namespace MyFramework
