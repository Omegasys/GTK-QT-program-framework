#pragma once

#include <memory>

namespace gqf {

class EditorInput;
class GizmoInput;

/// Central input dispatcher that will later receive events from GTK/Qt adapters.
class InputRouter {
public:
    InputRouter();
    ~InputRouter();

    void setEditorInput(const std::shared_ptr<EditorInput>& editorInput);
    void setGizmoInput(const std::shared_ptr<GizmoInput>& gizmoInput);

    void clearEditorInput();
    void clearGizmoInput();

    // Unified event API (GTK / Qt adapters will call these)
    void keyPress(int keycode, bool ctrl, bool shift, bool alt);
    void keyRelease(int keycode);

    void mouseMove(double x, double y);
    void mouseButton(int button, bool pressed, double x, double y);
    void scroll(double dx, double dy);

private:
    std::shared_ptr<EditorInput> m_editorInput;
    std::shared_ptr<GizmoInput>  m_gizmoInput;
};

} // namespace gqf
