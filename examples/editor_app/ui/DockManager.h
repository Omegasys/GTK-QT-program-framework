#pragma once

#include <vector>
#include <memory>

class Panel;

/*
 * DockManager
 * ------------------------------------------------------------
 * Manages layout and docking of panels.
 */

class DockManager {
public:
    DockManager();
    ~DockManager();

    void initialize();
    void update();
    void render();

    void addPanel(std::unique_ptr<Panel> panel);

private:
    std::vector<std::unique_ptr<Panel>> m_panels;
};
