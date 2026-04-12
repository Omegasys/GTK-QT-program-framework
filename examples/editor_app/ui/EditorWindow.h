#pragma once

#include <memory>

class DockManager;

/*
 * EditorWindow
 * ------------------------------------------------------------
 * Root UI container for the editor.
 */

class EditorWindow {
public:
    EditorWindow();
    ~EditorWindow();

    void initialize();
    void update();
    void render();

private:
    std::unique_ptr<DockManager> m_dockManager;
};
