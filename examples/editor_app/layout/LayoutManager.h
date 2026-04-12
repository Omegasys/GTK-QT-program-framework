#pragma once

#include <memory>
#include <string>

class Workspace;
class DockLayout;

/*
 * LayoutManager
 * ------------------------------------------------------------
 * Controls layout switching, saving, and loading.
 */

class LayoutManager {
public:
    LayoutManager();

    void initialize();

    void loadLayout(const std::string& path);
    void saveLayout(const std::string& path);

    void setActiveWorkspace(const std::string& name);

private:
    std::unique_ptr<Workspace> m_workspace;
    std::unique_ptr<DockLayout> m_dockLayout;
};
