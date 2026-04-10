#pragma once

#include <vector>

#include <MyFramework/Widget.h>

namespace MyFramework {

/**
 * @brief Base layout class.
 *
 * Handles positioning and sizing of child widgets.
 */
class Layout {
public:
    Layout();
    virtual ~Layout();

    // Disable copy
    Layout(const Layout&) = delete;
    Layout& operator=(const Layout&) = delete;

    /**
     * @brief Adds a widget to the layout.
     */
    virtual void addWidget(Widget* widget);

    /**
     * @brief Removes a widget from the layout.
     */
    virtual void removeWidget(Widget* widget);

    /**
     * @brief Returns all widgets.
     */
    const std::vector<Widget*>& widgets() const;

    /**
     * @brief Sets spacing between widgets.
     */
    void setSpacing(int spacing);

    /**
     * @brief Returns spacing.
     */
    int spacing() const;

    /**
     * @brief Sets margins (left, top, right, bottom).
     */
    void setMargins(int left, int top, int right, int bottom);

    /**
     * @brief Applies layout to parent widget.
     */
    virtual void apply(Widget* parent) = 0;

protected:
    std::vector<Widget*> m_widgets;

    int m_spacing;

    int m_marginLeft;
    int m_marginTop;
    int m_marginRight;
    int m_marginBottom;
};

/**
 * @brief Vertical box layout.
 *
 * Stacks widgets top-to-bottom.
 */
class VBoxLayout : public Layout {
public:
    VBoxLayout();

    void apply(Widget* parent) override;
};

/**
 * @brief Horizontal box layout.
 *
 * Stacks widgets left-to-right.
 */
class HBoxLayout : public Layout {
public:
    HBoxLayout();

    void apply(Widget* parent) override;
};

} // namespace MyFramework
