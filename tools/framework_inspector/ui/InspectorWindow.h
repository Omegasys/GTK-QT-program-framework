#pragma once

#include <MyFramework/ui/Window.h>

class WidgetTreeView;
class PropertyEditor;
class EventMonitor;
class RenderDebugOverlay;
class LayoutDebugger;

class InspectorWindow : public MyFramework::Window {
public:
    InspectorWindow(int w, int h);

    void initializeUI();
    void update();

private:
    WidgetTreeView* treeView = nullptr;
    PropertyEditor* propertyEditor = nullptr;
    EventMonitor* eventMonitor = nullptr;
    RenderDebugOverlay* overlay = nullptr;
    LayoutDebugger* layoutDebugger = nullptr;
};
