#pragma once

#include <string>
#include <memory>

namespace MyFramework {

class Widget;
class Layout;
struct Theme;

/**
 * @brief Represents a top-level application window.
 *
 * A Window can contain a central widget or layout,
 * supports theming, and interacts with the platform layer.
 */
class Window {
public:
    /**
     * @brief Creates a window with title and size.
     */
    Window(const std::string& title, int width, int height);

    /**
     * @brief Destructor.
     */
    ~Window();

    // Disable copy
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    // Allow move
    Window(Window&&) = default;
    Window& operator=(Window&&) = default;

    /**
     * @brief Shows the window.
     */
    void show();

    /**
     * @brief Hides the window.
     */
    void hide();

    /**
     * @brief Closes the window.
     */
    void close();

    /**
     * @brief Checks if window is visible.
     */
    bool isVisible() const;

    /**
     * @brief Sets window title.
     */
    void setTitle(const std::string& title);

    /**
     * @brief Returns window title.
     */
    const std::string& title() const;

    /**
     * @brief Sets window size.
     */
    void setSize(int width, int height);

    /**
     * @brief Gets window width.
     */
    int width() const;

    /**
     * @brief Gets window height.
     */
    int height() const;

    /**
     * @brief Sets window position.
     */
    void setPosition(int x, int y);

    /**
     * @brief Gets X position.
     */
    int x() const;

    /**
     * @brief Gets Y position.
     */
    int y() const;

    /**
     * @brief Sets central widget.
     */
    void setCentralWidget(Widget* widget);

    /**
     * @brief Gets central widget.
     */
    Widget* centralWidget() const;

    /**
     * @brief Sets layout for the window.
     */
    void setLayout(Layout* layout);

    /**
     * @brief Gets layout.
     */
    Layout* layout() const;

    /**
     * @brief Applies a theme to the window.
     */
    void applyTheme(const Theme& theme);

    /**
     * @brief Returns current theme.
     */
    const Theme& theme() const;

    /**
     * @brief Forces redraw of the window.
     */
    void update();

    /**
     * @brief Resizes and redraws layout.
     */
    void relayout();

private:
    void createNativeWindow();
    void destroyNativeWindow();
    void updateNative();

private:
    std::string m_title;

    int m_width;
    int m_height;

    int m_x;
    int m_y;

    bool m_visible;

    Widget* m_centralWidget;
    Layout* m_layout;

    Theme* m_theme;

    // Opaque pointer to platform-specific window (Win32, X11, Wayland, etc.)
    void* m_nativeHandle;
};

} // namespace MyFramework
