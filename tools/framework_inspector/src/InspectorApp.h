#pragma once

#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>

class WidgetTreeView;
class PropertyEditor;
class EventMonitor;
class RenderDebugOverlay;

class InspectorApp : public MyFramework::Application {
public:
    bool initialize();
    void run();
    void shutdown();

private:
    MyFramework::Window* window = nullptr;

    WidgetTreeView* treeView = nullptr;
    PropertyEditor* propertyEditor = nullptr;
    EventMonitor* eventMonitor = nullptr;
    RenderDebugOverlay* overlay = nullptr;
};
