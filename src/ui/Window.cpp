#include <MyFramework/ui/Window.h>
#include <MyFramework/platform/Platform.h>
#include <MyFramework/render/Renderer.h>

namespace MyFramework {

Window::Window(int width, int height, const std::string& title)
    : Widget(nullptr),
      m_impl(Platform::createWindow(width, height, title)),
      m_renderer(new Renderer()) {}

Window::~Window() {
    delete m_renderer;
    delete m_impl;
}

void Window::show() {
    if (m_impl) m_impl->show();
}

void Window::close() {
    if (m_impl) m_impl->close();
}

bool Window::isOpen() const {
    return m_impl && m_impl->isOpen();
}

void Window::renderFrame() {
    if (!m_impl) return;

    RenderTarget* target = m_impl->getRenderTarget();

    m_renderer->begin(this, target);
    m_renderer->clear({0, 0, 0, 1});

    render(*m_renderer); // render widget tree

    m_renderer->end();
    m_impl->present();
}

bool Window::pollEvent(Event& event) {
    return m_impl->pollEvent(event);
}

} // namespace MyFramework
