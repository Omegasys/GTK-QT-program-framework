#include "InspectorPanel.h"
#include <iostream>

InspectorPanel::InspectorPanel()
    : Panel("Inspector") {}

void InspectorPanel::update() {
    // Future: sync with selection system
}

void InspectorPanel::render() {
    std::cout << "[Inspector] Selected: "
              << (m_selectedObject.empty() ? "None" : m_selectedObject)
              << "\n";
}

void InspectorPanel::setSelected(const std::string& objectName) {
    m_selectedObject = objectName;
}
