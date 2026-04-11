#include "ConfigEditorApp.h"
#include "ConfigView.h"
#include "LivePreviewPanel.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

bool ConfigEditorApp::initialize() {
    if (!Application::initialize())
        return false;

    window = new Window(1000, 700, "Config Editor Tool");
    window->show();

    view = new ConfigView(window);
    preview = new LivePreviewPanel(window);

    Logger::info("Config Editor initialized");

    return true;
}

void ConfigEditorApp::run() {
    while (window->isOpen()) {
        Event e;
        while (window->pollEvent(e)) {
            window->handleEvent(e);
        }

        view->update();
        preview->update(view->getCurrentConfig());

        window->renderFrame();
    }
}

void ConfigEditorApp::shutdown() {
    delete view;
    delete preview;
    delete window;

    Application::shutdown();
}
