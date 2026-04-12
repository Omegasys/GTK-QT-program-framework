#include "GizmoInput.h"
#include <iostream>

namespace gqf {

void GizmoInput::onKeyPress(int keycode, bool ctrl, bool shift, bool alt) {
    if (keycode == 'W') {
        m_mode = Mode::Move;
        std::cout << "[Gizmo] Move mode\n";
    }

    if (keycode == 'E') {
        m_mode = Mode::Rotate;
        std::cout << "[Gizmo] Rotate mode\n";
    }

    if (keycode == 'R') {
        m_mode = Mode::Scale;
        std::cout << "[Gizmo] Scale mode\n";
    }
}

void GizmoInput::onKeyRelease(int keycode) {}

void GizmoInput::onMouseMove(double x, double y) {
    if (m_dragging)
        std::cout << "[Gizmo] Dragging: " << x << ", " << y << "\n";
}

void GizmoInput::onMouseButton(int button, bool pressed, double x, double y) {
    if (button == 1) {
        m_dragging = pressed;
        std::cout << "[Gizmo] " << (pressed ? "Start" : "Stop")
                  << " drag at: " << x << ", " << y << "\n";
    }
}

void GizmoInput::onScroll(double dx, double dy) {
    std::cout << "[Gizmo] Scroll adjust: " << dy << "\n";
}

} // namespace gqf
