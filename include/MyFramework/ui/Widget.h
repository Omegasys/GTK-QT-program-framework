#pragma once

#include <vector>
#include <string>

namespace MyFramework {

class Layout;
class Window;
struct Theme;

/**
 * @brief Base class for all UI elements.
 *
 * Provides positioning, parenting, rendering,
 * and event handling functionality.
 */
class Widget {
public:
    Widget();
    virtual ~Widget();

    // Disable copy
    Widget(const Widget&) = delete;
    Widget& operator=(const Widget&) = delete;

    // Allow move
    Widget(Widget&&) = default;
    Widget& operator=(Widget&&) = default;

    /**
     * @brief Shows the widget.
     */
    void show();

    /**
     * @brief Hides the widget.
     */
    void hide();

    /**
     * @brief Returns visibility state.
     */
    bool isVisible() const;

    /**
     * @brief Sets parent widget.
     */
    void setParent(Widget* parent);

    /**
     * @brief Gets parent widget.
     */
    Widget* parent() const;

    /**
     * @brief Adds a child widget.
     */
    void addChild(Widget* child);

    /**
     * @brief Removes a child widget.
     */
    void removeChild(Widget* child);

    /**
     * @brief Returns all children.
     */
    const std::vector<Widget*>& children() const;

    /**
     * @brief Sets widget position.
     */
    void setPosition(int x, int y);

    /**
     * @brief Sets widget size.
     */
    void setSize(int width, int height);

    /**
     * @brief Gets X position.
     */
    int x() const;

    /**
     * @brief Gets Y position.
     */
    int y() const;

    /**
     * @brief Gets width.
     */
    int width() const;

    /**
     * @brief Gets height.
     */
    int height() const;

    /**
     * @brief Requests a redraw.
     */
    void update();

    /**
     * @brief Sets layout for this widget.
     */
    void setLayout(Layout* layout);

    /**
     * @brief Gets layout.
     */
    Layout* layout() const;

    /**
     * @brief Applies a theme to this widget.
     */
    virtual void applyTheme(const Theme& theme);

    /**
     * @brief Returns owning window.
     */
    Window* window() const;

protected:
    /**
     * @brief Paint event (override in subclasses).
     */
    virtual void paint();

    /**
     * @brief Called when widget is resized.
     */
    virtual void onResize(int width, int height);

    /**
     * @brief Mouse press event.
     */
    virtual void onMousePress(int x, int y);

    /**
     * @brief Mouse release event.
     */
    virtual void onMouseRelease(int x, int y);

    /**
     * @brief Mouse move event.
     */
    virtual void onMouseMove(int x, int y);

    /**
     * @brief Key press event.
     */
    virtual void onKeyPress(int key);

    /**
     * @brief Key release event.
     */
    virtual void onKeyRelease(int key);

private:
    Widget* m_parent;
    std::vector<Widget*> m_children;

    Layout* m_layout;

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    bool m_visible;

    Theme* m_theme;
};

} // namespace MyFramework
