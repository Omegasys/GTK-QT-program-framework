#pragma once

#include <memory>
#include <string>

class EditorContext;
class EditorState;

/*
 * EditorApplication
 * ------------------------------------------------------------
 * Main entry point for the editor runtime.
 */

class EditorApplication {
public:
    EditorApplication();
    ~EditorApplication();

    bool initialize(const std::string& configPath);
    void run();
    void shutdown();

private:
    void update();
    void render();

private:
    bool m_running = true;

    std::unique_ptr<EditorContext> m_context;
    std::unique_ptr<EditorState> m_state;
};
