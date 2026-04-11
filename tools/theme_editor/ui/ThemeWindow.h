#pragma once

#include <MyFramework/ui/Window.h>

class ThemeCanvas;
class GradientEditor;
class ThemeTimelineView;

class ThemeWindow : public MyFramework::Window {
public:
    ThemeWindow(int w, int h);

    void initializeUI();
    void update();

private:
    ThemeCanvas* canvas = nullptr;
    GradientEditor* gradientEditor = nullptr;
    ThemeTimelineView* timelineView = nullptr;
};
