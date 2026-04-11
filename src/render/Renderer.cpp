#include <MyFramework/render/Renderer.h>
#include <iostream>

namespace MyFramework {

Renderer::Renderer()
    : m_target(nullptr) {}

void Renderer::begin(Widget* root, RenderTarget* target) {
    m_target = target;
    m_commands.clear();
}

void Renderer::end() {
    flush();
}

void Renderer::clear(const Color& color) {
    // Placeholder (real backend clears framebuffer)
    std::cout << "[Renderer] Clear: "
              << color.r << "," << color.g << "," << color.b << "\n";
}

void Renderer::drawRect(float x, float y, float w, float h, const Color& color) {
    m_commands.push_back(DrawCommand::rect(x, y, w, h, color));
}

void Renderer::drawText(float x, float y, const std::string& text, const Color& color) {
    m_commands.push_back(DrawCommand::text(x, y, text, color));
}

void Renderer::flush() {
    // For now: debug output instead of real rendering
    for (const auto& cmd : m_commands) {
        switch (cmd.type) {
            case DrawCommand::Type::Rect:
                std::cout << "[DrawRect] "
                          << cmd.x << "," << cmd.y
                          << " size=" << cmd.width << "x" << cmd.height
                          << "\n";
                break;

            case DrawCommand::Type::Text:
                std::cout << "[DrawText] "
                          << cmd.text << " at "
                          << cmd.x << "," << cmd.y
                          << "\n";
                break;
        }
    }
}

} // namespace MyFramework
