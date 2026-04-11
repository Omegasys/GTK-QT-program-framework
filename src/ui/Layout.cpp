#include <MyFramework/ui/Layout.h>

namespace MyFramework {

Layout::Layout(Object* parent)
    : Object(parent),
      m_spacing(5),
      m_marginLeft(0),
      m_marginTop(0),
      m_marginRight(0),
      m_marginBottom(0) {}

void Layout::addWidget(Widget* widget) {
    if (!widget) return;
    m_widgets.push_back(widget);
}

void Layout::removeWidget(Widget* widget) {
    m_widgets.erase(
        std::remove(m_widgets.begin(), m_widgets.end(), widget),
        m_widgets.end()
    );
}

void Layout::clear() {
    m_widgets.clear();
}

void Layout::setSpacing(int spacing) {
    m_spacing = spacing;
}

int Layout::spacing() const {
    return m_spacing;
}

void Layout::setMargins(int l, int t, int r, int b) {
    m_marginLeft = l;
    m_marginTop = t;
    m_marginRight = r;
    m_marginBottom = b;
}

} // namespace MyFramework
