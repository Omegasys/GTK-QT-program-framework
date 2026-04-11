#include "InspectorApp.h"

#include "WidgetTreeView.h"
#include "PropertyEditor.h"
#include "EventMonitor.h"
#include "RenderDebugOverlay.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

bool InspectorApp::initialize() {
    if (!Application::initialize())
        return false;

    window = new Window(1200, 800, "Framework Inspector");
    window->show();

    treeView = new WidgetTreeView(window);
    propertyEditor = new PropertyEditor(window);
    eventMonitor = new EventMonitor(window);
    overlay = new RenderDebugOverlay(window);

    Logger::info("Framework Inspector initialized");

    return true;
}

void InspectorApp::run() {
    while (window->isOpen()) {
        Event e;
        while (window->pollEvent(e)) {
            window->handleEvent(e);
            eventMonitor->capture(e);
        }

        treeView->update();
        propertyEditor->update();
        eventMonitor->update();
        overlay->update();

        window->renderFrame();
    }
}

void InspectorApp::shutdown() {
    delete treeView;
    delete propertyEditor;
    delete eventMonitor;
    delete overlay;
    delete window;

    Application::shutdown();
}
