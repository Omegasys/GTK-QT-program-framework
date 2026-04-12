#pragma once

#include "Panel.h"
#include <vector>
#include <string>

/*
 * HierarchyPanel
 * ------------------------------------------------------------
 * Displays scene object tree.
 */

class HierarchyPanel : public Panel {
public:
    HierarchyPanel();

    void update() override;
    void render() override;

    void addItem(const std::string& name);

private:
    std::vector<std::string> m_items;
};
