#include "HierarchyPanel.h"
#include <iostream>

HierarchyPanel::HierarchyPanel()
    : Panel("Hierarchy") {}

void HierarchyPanel::update() {
    // Future: sync with scene graph
}

void HierarchyPanel::render() {
    std::cout << "[Hierarchy]\n";

    for (const auto& item : m_items) {
        std::cout << " - " << item << "\n";
    }
}

void HierarchyPanel::addItem(const std::string& name) {
    m_items.push_back(name);
}
