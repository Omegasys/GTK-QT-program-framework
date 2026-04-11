#include "ThemeEditorApp.h"

#include "ThemeCanvas.h"
#include "GradientEditor.h"
#include "ThemeTimelineView.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

bool ThemeEditorApp::initialize() {
    if (!Application::initialize())
        return false;

    window = new Window(1100, 750, "Theme Editor");
    window->show();

    canvas = new ThemeCanvas(window);
    gradientEditor = new GradientEditor(window);
    timelineView = new ThemeTimelineView(window);

    Logger::info("Theme Editor initialized");

    return true;
}

void ThemeEditorApp::run() {
    while (window->isOpen()) {
        Event e;
        while (window->pollEvent(e)) {
            window->handleEvent(e);
        }

        canvas->update();
        gradientEditor->update();
        timelineView->update();

        window->renderFrame();
    }
}

void ThemeEditorApp::shutdown() {
    delete canvas;
    delete gradientEditor;
    delete timelineView;
    delete window;

    Application::shutdown();
}
