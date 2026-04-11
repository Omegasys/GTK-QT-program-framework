#include <MyFramework/ui/Label.h>
#include <MyFramework/render/Renderer.h>

namespace MyFramework {

Label::Label(Object* parent)
    : Widget(parent),
      m_color(Color::Black()),
      m_alignment(Alignment::Left),
      m_fontSize(14) {}

void Label::setText(const std::string& text) {
    m_text = text;
}

const std::string& Label::text() const {
    return m_text;
}

void Label::setColor(const Color& color) {
    m_color = color;
}

const Color& Label::color() const {
    return m_color;
}

void Label::setAlignment(Alignment a) {
    m_alignment = a;
}

Label::Alignment Label::alignment() const {
    return m_alignment;
}

void Label::setFontSize(int size) {
    m_fontSize = size;
}

int Label::fontSize() const {
    return m_fontSize;
}

void Label::render(Renderer& renderer) {
    if (!isVisible()) return;

    float tx = x();

    if (m_alignment == Alignment::Center)
        tx += width() / 2;
    else if (m_alignment == Alignment::Right)
        tx += width();

    renderer.drawText(tx, y(), m_text, m_color);
}

} // namespace MyFramework
