#pragma once

#include <memory>

class WidgetTreeView;
class PropertyEditor;
class EventMonitor;
class RenderOverlay;

class InspectorApp {
public:
    InspectorApp();
    ~InspectorApp();

    void run();

private:
    void update();
    void render();

private:
    bool running = true;

    std::unique_ptr<WidgetTreeView> treeView;
    std::unique_ptr<PropertyEditor> propertyEditor;
    std::unique_ptr<EventMonitor> eventMonitor;
    std::unique_ptr<RenderOverlay> overlay;
};
