#include "GradientEditor.h"

using namespace MyFramework;

GradientEditor::GradientEditor(Window* parent)
    : Widget(parent) {}

void GradientEditor::update() {
    // Placeholder: gradient rendering logic
}

void GradientEditor::addStop(float position, const Color& color) {
    stops.push_back({position, color});
}
