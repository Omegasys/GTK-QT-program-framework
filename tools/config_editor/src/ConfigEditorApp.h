#pragma once

#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>

class ConfigView;
class LivePreviewPanel;

class ConfigEditorApp : public MyFramework::Application {
public:
    bool initialize();
    void run();
    void shutdown();

private:
    MyFramework::Window* window = nullptr;

    ConfigView* view = nullptr;
    LivePreviewPanel* preview = nullptr;

    std::string currentConfigPath = "app.config";
};
