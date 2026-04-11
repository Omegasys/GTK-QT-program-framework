#include <MyFramework/render/RenderTarget.h>

namespace MyFramework {

RenderTarget::RenderTarget(int w, int h)
    : m_width(w), m_height(h) {}

int RenderTarget::width() const {
    return m_width;
}

int RenderTarget::height() const {
    return m_height;
}

void RenderTarget::resize(int w, int h) {
    m_width = w;
    m_height = h;
}

} // namespace MyFramework
