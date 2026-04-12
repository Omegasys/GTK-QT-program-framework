#include "DockManager.h"
#include "Panel.h"
#include "Viewport.h"

#include <iostream>

DockManager::DockManager() {
    std::cout << "[DockManager] Created\n";
}

DockManager::~DockManager() {
    std::cout << "[DockManager] Destroyed\n";
}

void DockManager::initialize() {
    std::cout << "[DockManager] Initializing panels\n";

    // Default panels
    addPanel(std::make_unique<Viewport>());
}

void DockManager::update() {
    for (auto& panel : m_panels) {
        panel->update();
    }
}

void DockManager::render() {
    for (auto& panel : m_panels) {
        panel->render();
    }
}

void DockManager::addPanel(std::unique_ptr<Panel> panel) {
    m_panels.push_back(std::move(panel));
}
