#include "EditorInput.h"
#include <iostream>

namespace gqf {

void EditorInput::onKeyPress(int keycode, bool ctrl, bool shift, bool alt) {
    if (ctrl && keycode == 'Z')
        std::cout << "[Editor] Undo\n";

    if (ctrl && keycode == 'Y')
        std::cout << "[Editor] Redo\n";

    if (keycode == ' ')
        m_spaceHeld = true;
}

void EditorInput::onKeyRelease(int keycode) {
    if (keycode == ' ')
        m_spaceHeld = false;
}

void EditorInput::onMouseMove(double x, double y) {
    if (m_spaceHeld)
        std::cout << "[Editor] Panning: " << x << ", " << y << "\n";
}

void EditorInput::onMouseButton(int button, bool pressed, double x, double y) {
    if (pressed && button == 1)
        std::cout << "[Editor] Select at: " << x << ", " << y << "\n";
}

void EditorInput::onScroll(double dx, double dy) {
    std::cout << "[Editor] Zoom: " << dy << "\n";
}

} // namespace gqf
