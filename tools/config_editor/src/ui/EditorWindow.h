#pragma once

#include <MyFramework/ui/Window.h>

class ConfigView;
class LivePreviewPanel;
class TimeFrameEditor;
class ThemeSlotEditor;

class EditorWindow : public MyFramework::Window {
public:
    EditorWindow(int w, int h);

    void initializeUI();
    void update();

private:
    ConfigView* configView = nullptr;
    LivePreviewPanel* previewPanel = nullptr;

    TimeFrameEditor* timeframeEditor = nullptr;
    ThemeSlotEditor* themeSlotEditor = nullptr;
};
