#include "ColorStopWidget.h"

using namespace MyFramework;

ColorStopWidget::ColorStopWidget(Window* parent)
    : Widget(parent) {}

void ColorStopWidget::setPosition(float t) {
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;
    position = t;
}

float ColorStopWidget::getPosition() const {
    return position;
}

void ColorStopWidget::setColor(const Color& c) {
    color = c;
}

Color ColorStopWidget::getColor() const {
    return color;
}

void ColorStopWidget::update() {
    // Placeholder interaction logic:
    // - detect mouse click
    // - start dragging
    // - update position based on cursor

    if (dragging) {
        // simulate drag update
        // position = mouseX / parentWidth;
    }
}
