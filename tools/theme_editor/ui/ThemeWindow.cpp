#include "ThemeWindow.h"

#include "../ThemeCanvas.h"
#include "../GradientEditor.h"
#include "../ThemeTimelineView.h"

using namespace MyFramework;

ThemeWindow::ThemeWindow(int w, int h)
    : Window(w, h, "Theme Editor") {
    initializeUI();
}

void ThemeWindow::initializeUI() {
    canvas = new ThemeCanvas(this);
    gradientEditor = new GradientEditor(this);
    timelineView = new ThemeTimelineView(this);
}

void ThemeWindow::update() {
    Window::renderFrame();

    canvas->update();
    gradientEditor->update();
    timelineView->update();
}
