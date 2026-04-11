#include "ColorPicker.h"

#include <MyFramework/utils/Color.h>

using namespace MyFramework;

ColorPicker::ColorPicker(Window* parent)
    : Widget(parent) {}

void ColorPicker::setColor(const Color& c) {
    color = c;
}

Color ColorPicker::getColor() const {
    return color;
}

void ColorPicker::update() {
    // Placeholder for GUI interaction logic
    // (mouse drag, sliders, hex input, etc.)
}
