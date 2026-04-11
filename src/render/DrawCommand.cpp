#include <MyFramework/render/DrawCommand.h>

namespace MyFramework {

DrawCommand::DrawCommand(Type t)
    : type(t),
      x(0), y(0), width(0), height(0) {}

DrawCommand DrawCommand::rect(float x, float y, float w, float h, const Color& c) {
    DrawCommand cmd(Type::Rect);
    cmd.x = x;
    cmd.y = y;
    cmd.width = w;
    cmd.height = h;
    cmd.color = c;
    return cmd;
}

DrawCommand DrawCommand::text(float x, float y, const std::string& str, const Color& c) {
    DrawCommand cmd(Type::Text);
    cmd.x = x;
    cmd.y = y;
    cmd.text = str;
    cmd.color = c;
    return cmd;
}

} // namespace MyFramework
