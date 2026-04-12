#include "InputRouter.h"
#include "EditorInput.h"
#include "GizmoInput.h"

namespace gqf {

InputRouter::InputRouter() = default;
InputRouter::~InputRouter() = default;

void InputRouter::setEditorInput(const std::shared_ptr<EditorInput>& editorInput) {
    m_editorInput = editorInput;
}

void InputRouter::setGizmoInput(const std::shared_ptr<GizmoInput>& gizmoInput) {
    m_gizmoInput = gizmoInput;
}

void InputRouter::clearEditorInput() {
    m_editorInput.reset();
}

void InputRouter::clearGizmoInput() {
    m_gizmoInput.reset();
}

void InputRouter::keyPress(int keycode, bool ctrl, bool shift, bool alt) {
    if (m_editorInput) m_editorInput->onKeyPress(keycode, ctrl, shift, alt);
    if (m_gizmoInput)  m_gizmoInput->onKeyPress(keycode, ctrl, shift, alt);
}

void InputRouter::keyRelease(int keycode) {
    if (m_editorInput) m_editorInput->onKeyRelease(keycode);
    if (m_gizmoInput)  m_gizmoInput->onKeyRelease(keycode);
}

void InputRouter::mouseMove(double x, double y) {
    if (m_gizmoInput)  m_gizmoInput->onMouseMove(x, y);
    if (m_editorInput) m_editorInput->onMouseMove(x, y);
}

void InputRouter::mouseButton(int button, bool pressed, double x, double y) {
    if (m_gizmoInput)  m_gizmoInput->onMouseButton(button, pressed, x, y);
    if (m_editorInput) m_editorInput->onMouseButton(button, pressed, x, y);
}

void InputRouter::scroll(double dx, double dy) {
    if (m_editorInput) m_editorInput->onScroll(dx, dy);
    if (m_gizmoInput)  m_gizmoInput->onScroll(dx, dy);
}

} // namespace gqf
