#include "EditorWindow.h"
#include "DockManager.h"

#include <iostream>

EditorWindow::EditorWindow() {
    std::cout << "[EditorWindow] Created\n";
}

EditorWindow::~EditorWindow() {
    std::cout << "[EditorWindow] Destroyed\n";
}

void EditorWindow::initialize() {
    m_dockManager = std::make_unique<DockManager>();
    m_dockManager->initialize();
}

void EditorWindow::update() {
    m_dockManager->update();
}

void EditorWindow::render() {
    std::cout << "[EditorWindow] Rendering\n";
    m_dockManager->render();
}
