#pragma once

#include <MyFramework/platform/WindowImpl.h>

namespace MyFramework {

/**
 * @brief Linux X11 window implementation.
 *
 * Uses Xlib / XCB backend.
 */
class X11Window : public WindowImpl {
public:
    X11Window(int width, int height, const std::string& title);
    ~X11Window() override;

    void show() override;
    void hide() override;
    void close() override;
    bool isOpen() const override;

    void setSize(int width, int height) override;
    void getSize(int& width, int& height) const override;

    void setPosition(int x, int y) override;
    void getPosition(int& x, int& y) const override;

    void setTitle(const std::string& title) override;

    RenderTarget* getRenderTarget() override;
    void present() override;

    bool pollEvent(Event& event) override;

private:
    void* m_display;   // X11 Display*
    unsigned long m_window;

    bool m_open;
    int m_width;
    int m_height;
};

} // namespace MyFramework
