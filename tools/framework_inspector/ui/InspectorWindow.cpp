#include "InspectorWindow.h"

#include "../WidgetTreeView.h"
#include "../PropertyEditor.h"
#include "../EventMonitor.h"
#include "../RenderDebugOverlay.h"

#include "LayoutDebugger.h"

using namespace MyFramework;

InspectorWindow::InspectorWindow(int w, int h)
    : Window(w, h, "Framework Inspector") {
    initializeUI();
}

void InspectorWindow::initializeUI() {
    treeView = new WidgetTreeView(this);
    propertyEditor = new PropertyEditor(this);
    eventMonitor = new EventMonitor(this);
    overlay = new RenderDebugOverlay(this);
    layoutDebugger = new LayoutDebugger(this);
}

void InspectorWindow::update() {
    Window::renderFrame();

    treeView->update();
    propertyEditor->update();
    eventMonitor->update();
    overlay->update();
    layoutDebugger->update();
}
