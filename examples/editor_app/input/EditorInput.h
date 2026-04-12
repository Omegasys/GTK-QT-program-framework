#pragma once

namespace gqf {

/// High-level editor shortcuts and navigation controls
class EditorInput {
public:
    void onKeyPress(int keycode, bool ctrl, bool shift, bool alt);
    void onKeyRelease(int keycode);

    void onMouseMove(double x, double y);
    void onMouseButton(int button, bool pressed, double x, double y);
    void onScroll(double dx, double dy);

private:
    bool m_spaceHeld = false;
};

} // namespace gqf
