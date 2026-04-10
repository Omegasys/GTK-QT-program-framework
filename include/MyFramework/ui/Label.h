#pragma once

#include <string>
#include <MyFramework/ui/Widget.h>
#include <MyFramework/utils/Color.h>

namespace MyFramework {

/**
 * @brief A simple text display widget.
 *
 * Supports:
 * - Text rendering
 * - Alignment
 * - Styling via Theme system
 */
class Label : public Widget {
public:
    enum class Alignment {
        Left,
        Center,
        Right
    };

    explicit Label(Object* parent = nullptr);

    /**
     * @brief Sets label text.
     */
    void setText(const std::string& text);
    const std::string& text() const;

    /**
     * @brief Sets text color.
     */
    void setColor(const Color& color);
    const Color& color() const;

    /**
     * @brief Sets text alignment.
     */
    void setAlignment(Alignment alignment);
    Alignment alignment() const;

    /**
     * @brief Sets font size.
     */
    void setFontSize(int size);
    int fontSize() const;

    /**
     * @brief Renders the label.
     */
    void render(Renderer& renderer) override;

private:
    std::string m_text;
    Color m_color;
    Alignment m_alignment;
    int m_fontSize;
};

} // namespace MyFramework
