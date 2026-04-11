#include <MyFramework/render/DrawCommand.h>
#include <iostream>

using namespace MyFramework;

void run_draw_command_tests() {
    std::cout << "[TEST] DrawCommand\n";

    auto rect = DrawCommand::rect(0, 0, 100, 100, Color::White());
    auto text = DrawCommand::text(10, 10, "Hello", Color::Black());

    if (rect.type == DrawCommand::Type::Rect &&
        text.type == DrawCommand::Type::Text)
        std::cout << "  ✔ DrawCommand types correct\n";
    else
        std::cout << "  ✖ DrawCommand types incorrect\n";
}
