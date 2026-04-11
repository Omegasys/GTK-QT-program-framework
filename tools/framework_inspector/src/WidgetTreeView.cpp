#include "WidgetTreeView.h"

using namespace MyFramework;

WidgetTreeView::WidgetTreeView(Window* parent)
    : Widget(parent) {}

void WidgetTreeView::refreshTree() {
    // Placeholder: would query framework widget hierarchy
    widgetNames = {
        "RootWindow",
        "  Button",
        "  Label",
        "  Panel",
        "    SubWidget"
    };
}

void WidgetTreeView::update() {
    refreshTree();

    // Render tree view (placeholder)
}
