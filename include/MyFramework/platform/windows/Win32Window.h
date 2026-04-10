#pragma once

#include <MyFramework/platform/WindowImpl.h>

namespace MyFramework {

/**
 * @brief Windows Win32 API window implementation.
 */
class Win32Window : public WindowImpl {
public:
    Win32Window(int width, int height, const std::string& title);
    ~Win32Window() override;

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
    void* m_hwnd;   // HWND

    bool m_open;
    int m_width;
    int m_height;
};

} // namespace MyFramework
