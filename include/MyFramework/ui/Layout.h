#pragma once

#include <vector>
#include <memory>

#include <MyFramework/core/Object.h>
#include <MyFramework/ui/Widget.h>

namespace MyFramework {

/**
 * @brief Base layout class.
 *
 * Responsible for:
 * - Positioning widgets
 * - Managing spacing
 * - Handling resizing behavior
 */
class Layout : public Object {
public:
    explicit Layout(Object* parent = nullptr);
    virtual ~Layout() = default;

    /**
     * @brief Adds widget to layout.
     */
    virtual void addWidget(Widget* widget);

    /**
     * @brief Removes widget from layout.
     */
    virtual void removeWidget(Widget* widget);

    /**
     * @brief Clears layout.
     */
    virtual void clear();

    /**
     * @brief Performs layout calculation.
     *
     * Called when:
     * - window resizes
     * - widget added/removed
     */
    virtual void updateLayout(int width, int height) = 0;

    /**
     * @brief Sets spacing between widgets.
     */
    void setSpacing(int spacing);
    int spacing() const;

    /**
     * @brief Sets margins (left, top, right, bottom).
     */
    void setMargins(int left, int top, int right, int bottom);

protected:
    std::vector<Widget*> m_widgets;

    int m_spacing;

    int m_marginLeft;
    int m_marginTop;
    int m_marginRight;
    int m_marginBottom;
};

} // namespace MyFramework
