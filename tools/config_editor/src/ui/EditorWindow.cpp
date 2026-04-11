#include "EditorWindow.h"

#include "TimeFrameEditor.h"
#include "ThemeSlotEditor.h"

#include "../ConfigView.h"
#include "../LivePreviewPanel.h"

using namespace MyFramework;

EditorWindow::EditorWindow(int w, int h)
    : Window(w, h, "Config Editor UI") {
    initializeUI();
}

void EditorWindow::initializeUI() {
    configView = new ConfigView(this);
    previewPanel = new LivePreviewPanel(this);

    timeframeEditor = new TimeFrameEditor(this);
    themeSlotEditor = new ThemeSlotEditor(this);
}

void EditorWindow::update() {
    Window::renderFrame();

    configView->update();
    previewPanel->update(configView->getCurrentConfig());

    timeframeEditor->update();
    themeSlotEditor->update();
}
