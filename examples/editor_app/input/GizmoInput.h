#pragma once

namespace gqf {

/// Handles transform gizmos (move / rotate / scale)
class GizmoInput {
public:
    void onKeyPress(int keycode, bool ctrl, bool shift, bool alt);
    void onKeyRelease(int keycode);

    void onMouseMove(double x, double y);
    void onMouseButton(int button, bool pressed, double x, double y);
    void onScroll(double dx, double dy);

private:
    enum class Mode {
        None,
        Move,
        Rotate,
        Scale
    };

    Mode m_mode = Mode::None;
    bool m_dragging = false;
};

} // namespace gqf
