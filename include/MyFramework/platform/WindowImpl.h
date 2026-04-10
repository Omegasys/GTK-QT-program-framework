#pragma once

#include <string>

namespace MyFramework {

class Event;
class RenderTarget;

/**
 * @brief Native window abstraction.
 *
 * This is implemented per-platform:
 * - Windows → Win32 API
 * - Linux → X11 / Wayland
 * - macOS → Cocoa
 */
class WindowImpl {
public:
    virtual ~WindowImpl() = default;

    // =========================
    // Window lifecycle
    // =========================

    /**
     * @brief Shows the window.
     */
    virtual void show() = 0;

    /**
     * @brief Hides the window.
     */
    virtual void hide() = 0;

    /**
     * @brief Closes window.
     */
    virtual void close() = 0;

    /**
     * @brief Checks if window is open.
     */
    virtual bool isOpen() const = 0;

    // =========================
    // Size / position
    // =========================

    virtual void setSize(int width, int height) = 0;
    virtual void getSize(int& width, int& height) const = 0;

    virtual void setPosition(int x, int y) = 0;
    virtual void getPosition(int& x, int& y) const = 0;

    // =========================
    // Title
    // =========================

    virtual void setTitle(const std::string& title) = 0;

    // =========================
    // Rendering hook
    // =========================

    /**
     * @brief Returns render target linked to this window.
     */
    virtual RenderTarget* getRenderTarget() = 0;

    /**
     * @brief Swaps buffers / presents frame.
     */
    virtual void present() = 0;

    // =========================
    // Input polling
    // =========================

    /**
     * @brief Polls OS events and converts them to framework events.
     */
    virtual bool pollEvent(Event& event) = 0;
};

} // namespace MyFramework
