#include "InspectorApp.h"

#include "WidgetTreeView.cpp"
#include "PropertyEditor.cpp"
#include "EventMonitor.cpp"
#include "RenderOverlay.cpp"

#include <iostream>

InspectorApp::InspectorApp() {
    treeView = std::make_unique<WidgetTreeView>();
    propertyEditor = std::make_unique<PropertyEditor>();
    eventMonitor = std::make_unique<EventMonitor>();
    overlay = std::make_unique<RenderOverlay>();

    std::cout << "[Inspector] Initialized\n";
}

InspectorApp::~InspectorApp() {
    std::cout << "[Inspector] Shutdown\n";
}

void InspectorApp::run() {
    while (running) {
        update();
        render();
    }
}

void InspectorApp::update() {
    eventMonitor->poll();
    treeView->refresh();
    propertyEditor->update();
}

void InspectorApp::render() {
    overlay->draw();
    treeView->draw();
    propertyEditor->draw();
    eventMonitor->draw();
}
