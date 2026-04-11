#include "ThemeCanvas.h"

using namespace MyFramework;

ThemeCanvas::ThemeCanvas(Window* parent)
    : Widget(parent) {}

void ThemeCanvas::update() {
    // Placeholder: would render live theme preview
}

void ThemeCanvas::setPrimaryColor(const Color& color) {
    primary = color;
}

void ThemeCanvas::setSecondaryColor(const Color& color) {
    secondary = color;
}
