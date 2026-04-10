#pragma once

#include <string>
#include <functional>

#include <MyFramework/Widget.h>

namespace MyFramework {

/**
 * @brief A clickable button widget.
 *
 * Supports text display, click handling,
 * and integrates with theming and events.
 */
class Button : public Widget {
public:
    /**
     * @brief Creates a button with optional text.
     */
    explicit Button(const std::string& text = "");

    /**
     * @brief Destructor.
     */
    ~Button();

    /**
     * @brief Sets button text.
     */
    void setText(const std::string& text);

    /**
     * @brief Returns button text.
     */
    const std::string& text() const;

    /**
     * @brief Sets click callback.
     */
    void onClick(std::function<void()> callback);

    /**
     * @brief Sets pressed state manually.
     */
    void setPressed(bool pressed);

    /**
     * @brief Returns pressed state.
     */
    bool isPressed() const;

    /**
     * @brief Sets hover state manually.
     */
    void setHovered(bool hovered);

    /**
     * @brief Returns hover state.
     */
    bool isHovered() const;

protected:
    /**
     * @brief Paint override.
     */
    void paint() override;

    /**
     * @brief Mouse press event.
     */
    void onMousePress(int x, int y) override;

    /**
     * @brief Mouse release event.
     */
    void onMouseRelease(int x, int y) override;

    /**
     * @brief Mouse move event.
     */
    void onMouseMove(int x, int y) override;

    /**
     * @brief Apply theme override.
     */
    void applyTheme(const Theme& theme) override;

private:
    std::string m_text;

    bool m_pressed;
    bool m_hovered;

    std::function<void()> m_onClick;
};

} // namespace MyFramework
