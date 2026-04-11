#pragma once

#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>

class ThemeCanvas;
class GradientEditor;
class ThemeTimelineView;

class ThemeEditorApp : public MyFramework::Application {
public:
    bool initialize();
    void run();
    void shutdown();

private:
    MyFramework::Window* window = nullptr;

    ThemeCanvas* canvas = nullptr;
    GradientEditor* gradientEditor = nullptr;
    ThemeTimelineView* timelineView = nullptr;
};
