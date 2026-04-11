#include <MyFramework/ui/Widget.h>
#include <MyFramework/ui/Layout.h>
#include <MyFramework/effects/EffectStack.h>

namespace MyFramework {

Widget::Widget(Object* parent)
    : Object(parent),
      m_x(0), m_y(0), m_width(0), m_height(0),
      m_visible(true), m_enabled(true),
      m_layout(nullptr),
      m_effectStack(nullptr),
      m_needsRedraw(true) {}

Widget::~Widget() {}

void Widget::setPosition(float x, float y) {
    m_x = x;
    m_y = y;
}

void Widget::setSize(float w, float h) {
    m_width = w;
    m_height = h;
}

float Widget::x() const { return m_x; }
float Widget::y() const { return m_y; }
float Widget::width() const { return m_width; }
float Widget::height() const { return m_height; }

void Widget::setVisible(bool v) { m_visible = v; }
bool Widget::isVisible() const { return m_visible; }

void Widget::setEnabled(bool e) { m_enabled = e; }
bool Widget::isEnabled() const { return m_enabled; }

void Widget::render(Renderer& renderer) {
    if (!m_visible) return;

    if (m_effectStack)
        m_effectStack->apply();

    paint(renderer);

    for (auto child : children()) {
        Widget* w = dynamic_cast<Widget*>(child);
        if (w) w->render(renderer);
    }
}

void Widget::paint(Renderer&) {
    // Base widget does nothing
}

bool Widget::handleEvent(Event& event) {
    if (!m_enabled) return false;

    switch (event.type()) {
        case EventType::MouseMove: return onMouseMove(event);
        case EventType::MousePress: return onMousePress(event);
        case EventType::MouseRelease: return onMouseRelease(event);
        case EventType::KeyPress: return onKeyPress(event);
        case EventType::KeyRelease: return onKeyRelease(event);
        default: break;
    }

    return false;
}

bool Widget::onMouseMove(Event&) { return false; }
bool Widget::onMousePress(Event&) { return false; }
bool Widget::onMouseRelease(Event&) { return false; }
bool Widget::onKeyPress(Event&) { return false; }
bool Widget::onKeyRelease(Event&) { return false; }

void Widget::setLayout(Layout* layout) {
    m_layout = layout;
}

Layout* Widget::layout() const {
    return m_layout;
}

void Widget::updateLayout() {
    if (m_layout)
        m_layout->updateLayout((int)m_width, (int)m_height);
}

void Widget::setEffectStack(EffectStack* stack) {
    m_effectStack = stack;
}

EffectStack* Widget::effectStack() const {
    return m_effectStack;
}

void Widget::addChild(Widget* child) {
    Object::addChild(child);
}

void Widget::removeChild(Widget* child) {
    Object::removeChild(child);
}

} // namespace MyFramework
