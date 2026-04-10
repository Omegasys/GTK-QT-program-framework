#pragma once

#include <MyFramework/utils/Color.h>
#include <MyFramework/core/Object.h>

namespace MyFramework {

/**
 * @brief Drop shadow effect for UI elements.
 */
class ShadowEffect : public Object {
public:
    explicit ShadowEffect(Object* parent = nullptr);

    /**
     * @brief Shadow color.
     */
    void setColor(const Color& color);
    Color color() const;

    /**
     * @brief Shadow blur radius.
     */
    void setBlur(float blur);
    float blur() const;

    /**
     * @brief Shadow offset (x, y).
     */
    void setOffset(float x, float y);
    float offsetX() const;
    float offsetY() const;

    /**
     * @brief Shadow spread distance.
     */
    void setSpread(float spread);
    float spread() const;

    /**
     * @brief Enable/disable shadow.
     */
    void setEnabled(bool enabled);
    bool isEnabled() const;

private:
    Color m_color;

    float m_blur;
    float m_offsetX;
    float m_offsetY;
    float m_spread;

    bool m_enabled;
};

} // namespace MyFramework
